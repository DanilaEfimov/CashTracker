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

def get_params():
    api_key = os.getenv("FIXER_API_KEY")
    if not api_key:
        raise RuntimeError("API ключ не найден. Убедитесь, что .env загружен и переменная FIXER_API_KEY определена.")

    return {
        "access_key": api_key,
        "base": "EUR",  # Только EUR на бесплатной версии
        "symbols": ",".join(currencies)
    }
### ^^^ INIT VARIABLES ^^^ ###