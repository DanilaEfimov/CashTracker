import datetime

def log(what):
    now = datetime.datetime.now()
    formatted = now.strftime(" : %Y-%m-%d %H:%M:%S")
    with open("../logs/backend.log", "a", encoding="utf-8") as f:
        f.write(str(what) + str(formatted) + "\n");