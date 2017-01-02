#!/usr/bin/python3
import sys
import os
import time
import re
import socket
try:
    import httplib2
except ImportError as ie:
    print('Please install httplib.', file=sys.stderr)
    sys.exit(1)
# from httplib2 import HTTPConnection
try:
    import argparse
except ImportError as ie:
    print('Please install argparse.', file=sys.stderr)
    sys.exit(1)


# '''descripition='A tool to watch whether domain ip is changed. If it is, do something(--exec)' '''
parser=argparse.ArgumentParser()
parser.add_argument('domain', help='Which domain you want to watch for.')
parser.add_argument('exec', help='Tell what to exec when ips are different. (May need \' \' (quotes))', type=str)
parser.add_argument('-t', '--time', help='Delta time (second) between checking domain ip, default 60.', type=int)
args = parser.parse_args()
# print(args.domain)
# print(args.exec)
# print(args.time)

def getMyIP():
    # response = get('1212.ip138.com/ic.asp', 80)
    h = httplib2.Http(".cache")
    resp, content = h.request("http://1212.ip138.com/ic.asp", "GET")
    content=str(content, encoding='GBK')
    # print(content)
    start = content.index('[')
    end = content.index(']')
    ip = content[start + 1 : end]
    return ip

# def main():
print('Initializing...')
realIP=getMyIP()
print('Local IP is: '+realIP)
domainIP=socket.gethostbyname(args.domain)
print('IP of domain '+args.domain+' is '+domainIP)
sleepTime=args.time
if(sleepTime is None):
    sleepTime=60
# print(time)
print('Running exec script first...')
returnValue=(os.system(args.exec)) >> 8
# print(os.system(exec))
if returnValue==0:
    print('Done.')
else:
    print('WARNING: exec script returned non-zero value'+returnValue)

print('Now watching the domain...')

while(True):
    if realIP == domainIP :
        time.sleep(sleepTime)
    else:
        realIP=getMyIP()
        print('Local IP is: '+realIP)
        domainIP=socket.gethostbyname(args.domain)
        print('IP of domain '+args.domain+' is '+domainIP)
        if realIP == domainIP :
            pass
        else:
            print(os.system(args.exec) >> 8)
            print('Executed script.')
            # print('I\'m too tired, let me sleep a while...')
            # time.sleep(sleepTime)
