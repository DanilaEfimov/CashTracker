import requests
import json
from utils.logger import log
from utils.network import *
import pandas as pd

### main parser api function
# for reading requests from Qt front
def read_request():
    try:
        with open("../buffer/buffer.txt", "r", encoding="utf-8") as f:
            req = f.readlines()
            return req
    except OSError as e:
        log(e)
        return exitcodes[4]

def read_args():
    try:
        with open("../buffer/args.txt", "r", encoding="utf-8") as f:
            req = f.readlines()
            return req
    except OSError as e:
        log(e)
        return exitcodes[4]

def send_answer(response):
    try:
        if response[0] != "success":
            log("something went wrong. answer : " + str(response))
        with open("../buffer/response.txt", "w", encoding="utf-8") as f:
            f.write(str(response[0]) + "\n")   # exit status (success)
            if isinstance(response[1], (list, tuple)):
                for item in response[1]:
                    f.write(f"{item}\n")
            else:
                f.write(str(response[1]) + "\n")
            return exitcodes[0]
    except OSError as e:
        log(e)
        return exitcodes[4]

def append_answer(lines):
    try:
        with open("../buffer/response.txt", "a", encoding="utf-8") as f:
            for line in lines:
                f.write(line + "\n")
        return exitcodes[0]
    except OSError as e:
        log(e)
        return exitcodes[4]

def parse_dynamic_args(args):
    args = [line.strip() for line in args if line.strip()]

    signature = args[0].split(',')
    counts = list(map(int, args[1].split(',')))

    data_start = 2
    current_index = data_start

    results = {
        'text': [],
        'int': [],
        'real': []
    }

    for i, typename in enumerate(signature):
        count = counts[i]
        values = args[current_index: current_index + count]

        if typename == 'text':
            results['text'].extend(values)
        elif typename == 'int':
            results['int'].extend(map(int, values))
        elif typename == 'real':
            results['real'].extend(map(float, values))
        else:
            log(f"Unknown type in signature: {typename}")

        current_index += count

    return results['text'], results['int'], results['real']


def save_as_json(args):
    strs, ints, reals = parse_dynamic_args(args)

    counts = [len(strs), len(ints), len(reals)]

    try:
        count_cryptos = ints[0]  # 6
        path = strs[-1]  # path
        formats = strs[-2]  # 'json'

        fiat_currencies = strs[0:2]  # ['USD', 'EUR']
        crypto_names = strs[2:2 + count_cryptos]  # ['Bitcoin', ...]

        usd_values = reals[0::2]
        eur_values = reals[1::2]

        result = {}

        for i in range(count_cryptos):
            crypto = crypto_names[i].lower()
            result[crypto] = {
                "usd": usd_values[i],
                "eur": eur_values[i]
            }

        with open(path + "/rates.json", "w", encoding="utf-8") as f:
            json.dump(result, f, indent=4, ensure_ascii=False)

        return exitcodes[0], tuple([])

    except Exception as e:
        log(f"Error in save_as_json: {e}")
        return exitcodes[6], tuple([])



def save_as_csv(args):
    strs, ints, reals = parse_dynamic_args(args)

    try:
        count_cryptos = ints[0]
        path = strs[-1]          # path
        formats = strs[-2]       # 'csv' or 'json'

        fiat_currencies = strs[0:2]                      # ['USD', 'EUR']
        crypto_names = strs[2:2 + count_cryptos]         # ['Bitcoin', ...]

        usd_values = reals[0::2]
        eur_values = reals[1::2]

        data = {
            "crypto": [name.lower() for name in crypto_names],
            "usd": usd_values[:count_cryptos],
            "eur": eur_values[:count_cryptos]
        }

        df = pd.DataFrame(data)
        df.to_csv(path + "/rates.csv", index=False, sep=';')
        # separator relative country (Russian -> ';')

        return exitcodes[0], tuple([])

    except Exception as e:
        log(f"Error in save_as_csv: {e}")
        return exitcodes[6], tuple([])


# =========== vvv PARSER_CORE vvv =============

def parser_core(command: str, args):
    answer = "undefined"
    if command == "save_as_json":
        res, vals = save_as_json(args)
        return res, vals
    elif command == "save_as_csv":
        res, vals = save_as_csv(args)
        return res, vals
    return answer, exitcodes[8]
