from utils.parser import *
from utils.network import *

req = read_request();
args = read_args();
req = [x.strip() for x in req]
args = [x.strip() for x in args]
print("request:\n",req, args, sep='\narguments:\n');

response = ("undefined", -1);
if(req[0] == "network_py"):
    response = network_core(req[1], args);
elif(req[0] == "cache_py"):
    response = "";

send_answer(response);