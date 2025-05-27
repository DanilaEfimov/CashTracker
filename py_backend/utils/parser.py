import requests
import json
from utils.logger import log
from utils.cache import * #exitcodes, currencies, base_currency, symbols, cash_url, params

### main parser api function
# for reading requests from Qt front
def read_request():
    try:
        with open("../buffer/buffer.txt", "r", encoding="utf-8") as f:
            req = f.readlines();
            return req;
    except OSError as e:
        log(e);
        return exitcodes[-1];


def get_rates():
    response = requests.get(cash_url, params=get_params());
    if response.status_code == 200:
        data = response.json();
        try:
            with open("./cache.json", "w", encoding="utf-8") as f:
                json.dump(data, f, indent=4, ensure_ascii=False);
                print(data);
        except OSError as e:
            log(e);
            return exitcodes[-1]  # например, fatal_err
        return exitcodes[0];
    else:
        return exitcodes[1];