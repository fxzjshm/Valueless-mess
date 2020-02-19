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

        Case7 wrapper = new Case7("http://cdn.tldcnm.com/dnf.php", "MQQBrowser/26 Mozilla/5.0 (Linux; U; Android 2.3.7; zh-cn; MB200 Build/GRJ22; CyanogenMod-7) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0 Mobile Safari/533.1", "", "");
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

                    get = new HttpGet("http://cdn.tldcnm.com/dnf.php?u=" + U.gU() + "&p=" + U.gP());

                    get.addHeader("Accept", "*/*");
                    get.addHeader("Connection", "Keep-Alive");
                    get.addHeader("User-Agent", ua);
                    get.addHeader("Referer", "http://cdn.tldcnm.com/");
                    get.addHeader("Host", "cdn.tldcnm.com");

                    response = httpClient.execute(get, context);
                    System.out.println(response.getStatusLine().getStatusCode());
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
