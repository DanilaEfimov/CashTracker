def cache_data(data):
    with open("./cash_rates.json", "a", encoding="utf-8") as f:
        f.write(data);