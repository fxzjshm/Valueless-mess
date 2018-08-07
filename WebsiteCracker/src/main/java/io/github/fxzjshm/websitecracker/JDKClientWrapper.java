package io.github.fxzjshm.websitecracker;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.SynchronousQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class JDKClientWrapper extends ClientWrapper {

    public JDKClientWrapper(String target, String userAgent, String usernameField, String passwordField)
            throws MalformedURLException {
        super(target, userAgent, usernameField, passwordField);
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
            /*
             * while (cnt != 0) { Thread.sleep(500); cnt--; }
             */
            // Thread.sleep(5000);

        }
    }

    public static class R implements Runnable {
        final JDKClientWrapper w;

        public R(JDKClientWrapper w) {
            this.w = w;
        }

        @Override
        public void run() {
            while (true) {
                try {
                    URL t = new URL(w.t);
                    PrintWriter out = null;
                    BufferedReader in = null;
                    HttpURLConnection conn = (HttpURLConnection) t.openConnection();
                    conn.setRequestMethod("POST");
                    conn.setRequestProperty("Accept", "*/*");
                    conn.setRequestProperty("Connection", "close");
                    conn.setRequestProperty("User-Agent", w.ua);
                    conn.setRequestProperty("Cookie", "userid=0");
                    // conn.setRequestProperty("Referer",
                    // "http://www.savhot.com/data/uploadtmp/20130526/");
                    conn.setDoOutput(true);
                    conn.setDoInput(true);
                    // conn.setInstanceFollowRedirects(false);
                    out = new PrintWriter(conn.getOutputStream());
                    try {
                        // while (true) {
                        out.print("ip=&" + w.unf + "=" + U.gU() + "&" + w.pwf + "=" + U.gP());
                        out.flush();
                        // conn.connect();

                        String result = "";
                        in = new BufferedReader(new InputStreamReader(conn.getInputStream()));
                        String line;
                        while ((line = in.readLine()) != null) {
                            result += line;
                        }
                        System.out.println(result);
                        // FileOutputStream fos = new FileOutputStream(new File("wtf.jpg"));
                        // fos.write(result.getBytes());
                        // fos.close();

                        // String location = conn.getHeaderField("Location");
                        // System.out.println(location);
                        Thread.sleep(66 + U.r.nextInt(233));
                        // e.printStackTrace();
                        // cnt++;
                        // if (cnt >= 10) {
                        // cnt-=10;
                        // try {
                        // Thread.sleep(500);
                        // } catch (Exception e) {
                        // }
                        // }
                        // }
                    } catch (Exception e) {
                    }
                    conn.disconnect();
                    in.close();
                    out.close();
                } catch (Exception e) {
                }
            }
        }
    }
}