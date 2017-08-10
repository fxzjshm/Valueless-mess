import httplib
import time

h = httplib.HTTPConnection('zk.ntzk.com')
while (1>0):
    h.request("GET","/webUI/zytb/tbzy.aspx")
    r = h.getresponse().status
    if 200 <= r <= 299:
        i = 10
        while (i > 0):
	        print "Service avaliable !!!"
    h.close()
    time.sleep(5)