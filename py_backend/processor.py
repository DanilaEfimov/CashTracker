from utils.parser import *
from utils.network import *

# by ipc request contains: util name + function name

def main():
    req = read_request()
    args = read_args()

    req = [x.strip() for x in req]
    args = [x.strip() for x in args]

    print("request:", req, "\narguments:", args)

    response = ("undefined", -1)

    if req[0] == "network_py":
        response = network_core(req[1], args)
    elif req[0] == "parser_py":
        response = parser_core(req[1], args)
    elif req[0] == "cache_py":
        response = ("", 0)

    exitcode = send_answer(response)
    print(exitcode)

if __name__ == "__main__":
    main()
