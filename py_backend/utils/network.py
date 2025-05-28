from utils.logger import *
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

base_currency = "EUR";
symbols = ",".join(currencies);

cash_url = "http://data.fixer.io/api/latest";

### ^^^ INIT VARIABLES ^^^ ###

def get_params():
    api_key = os.getenv("FIXER_API_KEY")
    if not api_key:
        raise RuntimeError("API ключ не найден. Убедитесь, что .env загружен и переменная FIXER_API_KEY определена.")

    return {
        "access_key": api_key,
        "base": "EUR",  # only euro for free version
        "symbols": ",".join(currencies)
    }

def update_rates():
    response = requests.get(cash_url, params=get_params());
    if response.ok:
        data = response.json();
        try:
            with open("./cache.json", "w", encoding="utf-8") as f:
                json.dump(data, f, indent=4, ensure_ascii=False);
        except OSError as e:
            log(e);
            return exitcodes[-1]  # fatal_err
        return exitcodes[0];
    else:
        return exitcodes[1];

def is_valid_response(data):
    return data.get("rates") is not None;

# ----------- CONVERTER -----------
def get_rates():
    try:
        with open("cache.json", "r", encoding="utf-8") as f:
            data = json.load(f);
    except OSError as e:
        log(e);
        return (exitcodes[1], {});
    if is_valid_response(data):
        return (exitcodes[0], data.get("rates"));
    else:
        return (exitcodes[5], {});

def convert(args, rates):
    temp_cur = args[2];
    target_cur = args[3];
    amount = float(args[4]);
    temp_rate = rates[temp_cur];
    target_rate = rates[target_cur];
    aspect = target_rate / temp_rate;
    target_amount = amount * aspect;
    return target_amount;

def network_core(command : str, args):
    answer = "undefined";
    if(command == "convert"):
        res, rates = get_rates();
        if(res != exitcodes[0]):
            return (res, -1);
        else:
            amount = convert(args, rates);
            return (exitcodes[0], amount);
    return answer;