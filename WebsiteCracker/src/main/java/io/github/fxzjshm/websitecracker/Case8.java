package io.github.fxzjshm.websitecracker;

import java.net.MalformedURLException;

public class Case8 {
    public static void main(String[] args) throws MalformedURLException {
        // http://45.207.28.97/v%5Eys/v%5E4/2019.php
        // curl 'http://45.207.28.97/v%5Eys/v%5E4/2019.php' \
        // -H 'User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:81.0) Gecko/20100101 Firefox/81.0' \
        // -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8' \
        // -H 'Accept-Language: zh,en-US;q=0.7,en;q=0.3' \
        // --compressed \
        // -H 'Content-Type: application/x-www-form-urlencoded' \
        // -H 'Origin: http://45.207.28.97' \
        // -H 'DNT: 1' \
        // -H 'Connection: keep-alive' \
        // -H 'Referer: http://45.207.28.97/v%5Eys/v%5E4/qt.php' \
        // -H 'Cookie: PHPSESSID=ejen277i0q5f4nfpvo22ohu9d7' \
        // -H 'Upgrade-Insecure-Requests: 1' \
        // -H 'Pragma: no-cache' \
        // -H 'Cache-Control: no-cache' \
        // --data-raw 'user=3654568987&pass=bhjvkvg3564&submit='
        new ApacheHTTPClientWrapper("http://45.207.28.97/v%5Eys/v%5E4/2019.php",
                "Mozilla/5.0 (Linux; Android 10; M2006J10C) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.117 Mobile Safari/537.36",
                "user", "pass").start();
    }
}
