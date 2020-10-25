package io.github.fxzjshm.websitecracker;

import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;

import java.io.IOException;
import java.net.MalformedURLException;

public class Case7 extends ApacheHTTPClientWrapper {

    public Case7(String target, String userAgent, String usernameField, String passwordField) throws MalformedURLException {
        super(target, userAgent, usernameField, passwordField);
    }

    public static void main(String[] args) throws MalformedURLException {

//        Case7 wrapper = new Case7("http://cdn.tldcnm.com/dnf.php", "Mozilla/5.0 (Linux; Android 7.1.2; MI 5C Build/N2G47J; wv) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/66.0.3359.126 MQQBrowser/6.2 TBS/045114 Mobile Safari/537.36 V1_AND_SQ_8.2.7_1334_YYB_D PA QQ/8.2.7.4410 NetType/WIFI WebP/0.3.0 Pixel/1080 StatusBarHeight/72 SimpleUISwitch/1", "", "");
        Case7 wrapper = new Case7("http://cdn.tldcnm.com/dnf.php", "Mozilla/5.0 (Linux; Android 7.1.2; Mobile; rv:73.0) Gecko/73.0  Firefox/73.0", "", "");
        for (String s : args) {
            try {
                wrapper.addThread(Integer.valueOf(s));
            } catch (NumberFormatException ignored) {
            }
        }
        wrapper.start();
    }

    @Override
    public void start() {
        Runnable r = () -> {
            while (true) {
                HttpGet get;
                HttpResponse response;
                try {
                    //get = new HttpGet("http://cdn.tldcnm.com/");

                    //get.addHeader("Accept", "*/*");
                    //get.addHeader("Connection", "Keep-Alive");
                    //get.addHeader("User-Agent", ua);

                    //response = httpClient.execute(get, context);

                    get = new HttpGet("https://cdn.tldcnm.com/dnf.php?u=" + U.gU() + "&p=" + U.gP());

                    get.addHeader("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,image/sharpp,image/apng,image/tpg,*/*;q=0.8");
                    get.addHeader("Connection", "Keep-Alive");
                    get.addHeader("User-Agent", ua);
                    get.addHeader("Referer", "http://cdn.tldcnm.com/");
                    get.addHeader("Host", "cdn.tldcnm.com");

                    response = httpClient.execute(get, context);
                    System.out.println(System.currentTimeMillis() + " : " + response.getStatusLine().getStatusCode());
                    get.releaseConnection();
                } catch (IOException e) {
                    // e.printStackTrace();
                }
                try {
                    Thread.sleep(666 + U.r.nextInt(233));
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    // e.printStackTrace();
                }
            }
        };
        start(r);
    }
}
