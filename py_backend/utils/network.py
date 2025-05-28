import datetime

from utils.logger import log
import json
import requests
from dotenv import load_dotenv
import os

load_dotenv('utils/apikey.env');

### vvv INIT VARIABLES vvv ###

exitcodes = {
    0:  "success",
    1:  "network_err",
    2:  "protocol_err",
    3:  "response_err",
    4:  "openfile_err",
    5:  "ready_to_read",
    6:  "parse_err",
    7:  "run_err",
    8:  "undefined",
   -1:  "fatal_err"
}

currencies = [
    "USD", "EUR", "GBP", "JPY", "CNY", "CHF",
    "AUD", "CAD", "NZD", "SEK", "NOK", "DKK",
    "RUB", "PLN", "CZK", "HUF", "TRY", "INR",
    "BRL", "ZAR", "MXN", "SGD", "HKD", "KRW",
    "THB", "MYR", "IDR", "VND", "AED", "SAR",
    "EGP"
]

crypto_ids = [
    "bitcoin",
    "ethereum",
    "tether",
    "near",
    "binancecoin",
    "ripple"
]

base_currency = "EUR";
symbols = ",".join(currencies);

cash_url = "https://data.fixer.io/api/latest";
crypto_url = "https://api.coingecko.com/api/v3/simple/price";

### ^^^ INIT VARIABLES ^^^ ###

def get_cash_rate_request_args():
    api_key = os.getenv("FIXER_API_KEY")
    if not api_key:
        log("API key for cash_rate request not found");
        raise RuntimeError("API key for cash_rate request not found FIXER_API_KEY.");

    return {
        "access_key": api_key,
        "base": "EUR",  # only euro for free version
        "symbols": ",".join(currencies)
    }

def update_rates():
    response = requests.get(cash_url, params=get_cash_rate_request_args());
    if response.ok:
        data = response.json();
        try:
            with open("./cash_rates.json", "w", encoding="utf-8") as f:
                json.dump(data, f, indent=4, ensure_ascii=False);
        except OSError as e:
            log(e);
            return exitcodes[-1]  # fatal_err
        return exitcodes[0];
    else:
        return exitcodes[1];

def is_valid_response(data):
    try:
        date_from_data = datetime.datetime.strptime(data.get("date", ""), "%Y-%m-%d").date()
        return data.get("rates") is not None and date_from_data == datetime.date.today()
    except (ValueError, TypeError):
        return False

# -----v-v-v- CONVERTER -v-v-v-----
def get_rates(depth : int):
    try:
        with open("cash_rates.json", "r", encoding="utf-8") as f:
            data = json.load(f);
    except OSError as e:
        log(e);
        return (exitcodes[1], {});
    if is_valid_response(data):
        return (exitcodes[0], data.get("rates"));
    elif(depth > 0):
        update_rates();
        return get_rates(depth + 1);

def convert(args, rates):
    temp_cur = args[2];
    target_cur = args[3];
    amount = float(args[4]);
    temp_rate = rates[temp_cur];
    target_rate = rates[target_cur];
    aspect = target_rate / temp_rate;
    target_amount = amount * aspect;
    return target_amount;

# -----^-^-^- CONVERTER / NEWS | CRYPTO -v-v-v-----

def is_valid_crypto_response(data):
    mod_time = os.path.getmtime("./crypto_rates.json");
    mod_date = datetime.datetime.fromtimestamp(mod_time).date();
    if(mod_date != datetime.datetime.today().date()):
        return False;

    required_currencies = ["usd", "eur"];
    for cur in crypto_ids:
        if cur not in data:
            return False
        for currency in required_currencies:
            if currency not in data[cur]:
                return False
    return True;

def get_crypto_rates_request_args():
    return {
    "ids": ",".join(crypto_ids),
    "vs_currencies": "usd,eur"
}

def update_crypto_rates():
    response = requests.get(crypto_url, params=get_crypto_rates_request_args());
    if response.ok:
        data = response.json();
        try:
            with open("./crypto_rates.json", "w", encoding="utf-8") as f:
                json.dump(data, f, indent=4, ensure_ascii=False);
        except OSError as e:
            log(e);
            return exitcodes[-1]  # fatal_err
        return exitcodes[0];
    else:
        print(response.json()["error"]);
        return exitcodes[1];

def get_crypto_rates(depth : int):
    try:
        with open("crypto_rates.json", "r", encoding="utf-8") as f:
            data = json.load(f);
    except Exception as e:
        log(e);
        return (exitcodes[1], {});
    if is_valid_crypto_response(data):
        flat_rates = {}
        for coin, prices in data.items():
            for currency, value in prices.items():
                flat_rates[f"{coin}_{currency}"] = value
        return (exitcodes[0], flat_rates)
    elif(depth == 0):
        update_crypto_rates();
        return get_crypto_rates(depth + 1);
    else:
        return (exitcodes[6], {});

# -----^-^-^- NEWS | CRYPTO / -v-v-v-----

def network_core(command : str, args):
    answer = "undefined";
    if(command == "convert"):
        res, rates = get_rates(0);
        if(res != exitcodes[0]):
            return (res, tuple(-1));
        else:
            amount = convert(args, rates);
            return (exitcodes[0], tuple([amount]));
    elif(command == "update_crypto_rates"):
        res, rates = get_crypto_rates(0);
        if (res != exitcodes[0]):
            return (res, tuple(-1));
        else:
            return (exitcodes[0], tuple(rates.values()));
    return (answer, tuple([8]));