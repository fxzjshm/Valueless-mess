#!/usr/bin/env python
# reference: https://zhuanlan.zhihu.com/p/28810019
import requests, random

url = "http://tygpouenk.vonharngermanshepherds.com/xyz/index1.html"

header = {
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:100.0) Gecko/20100101 Firefox/100.0",
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/jxl,image/webp,*/*;q=0.8",
    "Accept-Language": "zh,en-US;q=0.7,en;q=0.3",
    "Content-Type": "application/x-www-form-urlencoded",
    "Referrer": "http://tygpouenk.vonharngermanshepherds.com/wdtx/aqqdoc.html?ud=cHA4",
}

'''
await fetch("http://tygpouenk.vonharngermanshepherds.com/xyz/index1.html", {
    "credentials": "include",
    "headers": {
        "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:100.0) Gecko/20100101 Firefox/100.0",
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/jxl,image/webp,*/*;q=0.8",
        "Accept-Language": "zh,en-US;q=0.7,en;q=0.3",
        "Content-Type": "application/x-www-form-urlencoded",
        "Upgrade-Insecure-Requests": "1"
    },
    "referrer": "http://tygpouenk.vonharngermanshepherds.com/wdtx/aqqdoc.html?ud=cHA4",
    "body": "ud=cHA4&u=279450091&p=asdfghjklkjhgfds&page=&iaa=1",
    "method": "POST",
    "mode": "cors"
});
'''

def request(u,p):
    data = {
        'ud' : 'cHA4',
        'u' : u,
        'p' : p,
        'page' : '',
        'iaa' : 1
    }
    r = requests.post(url, data, headers=header)
    print("" + str(r.request.body) + str(r))

while True:
    n = str(random.randint(100000000,10000000000))
    p = "".join(random.sample('1234567890abcdefghijklmnopqrstuvwxyz!@#$%', random.randint(9, 15)))
    request(n, p)
