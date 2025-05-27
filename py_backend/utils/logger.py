from utils.cache import exitcodes
from datetime import datetime

def log(what):
    with open("../logs/backend.log", "a", encoding="utf-8") as f:
        f.write(what + str(datetime.now()) + '\n');