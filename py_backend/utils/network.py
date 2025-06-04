import datetime
import random

from utils.logger import log
import json
import requests
from dotenv import load_dotenv
import os

load_dotenv('utils/apikey.env')

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
    "binancecoin",
    "bitcoin",
    "ethereum",
    "near",
    "ripple",
    "tether"
]

symbols = ",".join(currencies)

### ^^^ INIT VARIABLES ^^^ ###

def get_cash_rate_request_args():
    api_key = os.getenv("FIXER_API_KEY")
    if not api_key:
        log("API key for cash_rate request not found")
        raise RuntimeError("API key for cash_rate request not found FIXER_API_KEY.")

    return {
        "access_key": api_key,
        "base": "EUR",  # only euro for free version
        "symbols": ",".join(currencies)
    }

def update_rates():
    cash_url = "https://data.fixer.io/api/latest"
    params = get_cash_rate_request_args()
    response = requests.get(cash_url, params)
    if response.ok:
        data = response.json()
        try:
            with open("./cash_rates.json", "w", encoding="utf-8") as f:
                json.dump(data, f, indent=4, ensure_ascii=False)
        except OSError as e:
            log(e)
            return exitcodes[-1]  # fatal_err
        return exitcodes[0]
    else:
        return exitcodes[1]

def is_valid_response():
    mod_time = os.path.getmtime("./cash_rates.json")
    mod_date = datetime.datetime.fromtimestamp(mod_time).date()
    today = datetime.datetime.today().date()
    return mod_date == today

# -----v-v-v- CONVERTER -v-v-v-----
def get_rates(depth: int):
    try:
        with open("./cash_rates.json", "r", encoding="utf-8") as f:
            data = json.load(f)
    except OSError as e:
        log(e)
        return exitcodes[1], {}
    if is_valid_response():
        return exitcodes[0], data.get("rates")
    elif depth == 0:
        updated = update_rates()
        if updated != exitcodes[0]:
            return exitcodes[6], {}
        return get_rates(depth + 1)
    return exitcodes[6], {}

def convert(args, rates):
    temp_cur = args[2]
    target_cur = args[3]
    amount = float(args[4])
    temp_rate = rates[temp_cur]
    target_rate = rates[target_cur]
    aspect = target_rate / temp_rate
    target_amount = amount * aspect
    return target_amount

# -----^-^-^- CONVERTER / NEWS | CRYPTO -v-v-v-----

def is_valid_crypto_response(data):
    mod_time = os.path.getmtime("./crypto_rates.json")
    mod_date = datetime.datetime.fromtimestamp(mod_time).date()
    if mod_date != datetime.datetime.today().date():
        return False

    required_currencies = ["usd", "eur"]
    for cur in crypto_ids:
        if cur not in data:
            return False
        for currency in required_currencies:
            if currency not in data[cur]:
                return False
    return True

def get_crypto_rates_request_args():
    return {
        "ids": ",".join(crypto_ids),
        "vs_currencies": "usd,eur"
    }

def update_crypto_rates():
    crypto_url = "https://api.coingecko.com/api/v3/simple/price"
    params = get_crypto_rates_request_args()
    response = requests.get(crypto_url, params)
    if response.ok:
        data = response.json()
        try:
            with open("./crypto_rates.json", "w", encoding="utf-8") as f:
                json.dump(data, f, indent=4, ensure_ascii=False)
        except OSError as e:
            log(e)
            return exitcodes[-1]  # fatal_err
        return exitcodes[0]
    else:
        print(response.json()["error"])
        return exitcodes[1]

def get_crypto_rates(depth: int):
    try:
        with open("crypto_rates.json", "r", encoding="utf-8") as f:
            data = json.load(f)
    except Exception as e:
        log(e)
        return exitcodes[1], {}
    if is_valid_crypto_response(data):
        flat_rates = {}
        for coin, prices in data.items():
            for currency, value in prices.items():
                flat_rates[f"{coin}_{currency}"] = value
        return exitcodes[0], flat_rates
    elif depth == 0:
        update_crypto_rates()
        return get_crypto_rates(depth + 1)
    else:
        return exitcodes[6], {}

def get_crypro_news_request_args():
    api_key = os.getenv("FINNHUB_API_KEY")
    if not api_key:
        log("API key for crypto_news request not found")
        raise RuntimeError("API key for cash_rate request not found FINNHUB_API_KEY.")

    return {
        "category": "general",
        "token": api_key
    }

def update_crypto_news():
    base_url = "https://finnhub.io/api/v1/news"
    params = get_crypro_news_request_args()

    response = requests.get(base_url, params=params)
    if response.ok:
        data = response.json()
        try:
            with open("./crypto_news.json", "w", encoding="utf-8") as f:
                json.dump(data, f, indent=4, ensure_ascii=False)
        except OSError as e:
            log(e)
            return exitcodes[-1]  # fatal_err
        return exitcodes[0]
    else:
        print(response.json()["error"])
        return exitcodes[1]

def is_valid_crypto_news_response():
    mod_time = os.path.getmtime("./crypto_news.json")
    mod_date = datetime.datetime.fromtimestamp(mod_time).date()
    today = datetime.datetime.today().date()
    return mod_date == today

def get_crypto_news(depth: int):
    try:
        with open("./crypto_news.json", "r", encoding="utf-8") as f:
            data = json.load(f)
    except Exception as e:
        log(e)
        return exitcodes[1], []

    if is_valid_crypto_news_response():
        news = []

        if isinstance(data, dict):
            items = list(data.values())
        elif isinstance(data, list):
            items = data
        else:
            log("Invalid data format in crypto_news.json")
            return exitcodes[2], []

        valid_items = [item for item in items if isinstance(item, dict) and "summary" in item]

        selected_items = random.sample(valid_items, min(len(valid_items), 10))

        news = [item["summary"] for item in selected_items]

        return exitcodes[0], news

    elif depth == 0:
        update_crypto_news()
        return get_crypto_news(depth + 1)
    else:
        return exitcodes[6], []


# -----^-^-^- NEWS | CRYPTO / -v-v-v-----

def network_core(command: str, args):
    answer = "undefined"
    if command == "convert":
        res, rates = get_rates(0)
        if res != exitcodes[0]:
            return res, tuple([])
        else:
            amount = convert(args, rates)
            return exitcodes[0], tuple([amount])
    elif command == "update_crypto_rates":
        res, rates = get_crypto_rates(0)
        if res != exitcodes[0]:
            return res, tuple([])
        else:
            return exitcodes[0], tuple(rates.values())
    elif command == "update_crypto_news":
        res, news = get_crypto_news(0)
        if res != exitcodes[0]:
            return res, tuple([])
        else:
            return exitcodes[0], tuple(news)
    return answer, tuple([8])
