def cache_data(data):
    with open("./cache.json", "a", encoding="utf-8") as f:
        f.write(data);