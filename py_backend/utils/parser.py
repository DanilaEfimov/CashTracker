import requests
import json
from utils.logger import log
from utils.network import * #exitcodes, currencies, base_currency, symbols, cash_url, params

### main parser api function
# for reading requests from Qt front
def read_request():
    try:
        with open("../buffer/buffer.txt", "r", encoding="utf-8") as f:
            req = f.readlines();
            return req;
    except OSError as e:
        log(e);
        return exitcodes[4];

def read_args():
    try:
        with open("../buffer/args.txt", "r", encoding="utf-8") as f:
            req = f.readlines();
            return req;
    except OSError as e:
        log(e);
        return exitcodes[4];

def send_answer(response):
    try:
        if(response[0] != "success"):
            log("something went wrong. answer : " + str(response));
        with open("../buffer/response.txt", "w", encoding="utf-8") as f:
            f.write(str(response[0]) + "\n");   # exit status (success)
            for item in response[1]:
                f.write(f"{item}\n");
            return exitcodes[0];
    except OSError as e:
        log(e);
        return exitcodes[4];