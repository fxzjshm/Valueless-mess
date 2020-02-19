package io.github.fxzjshm.websitecracker;

import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.SynchronousQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public abstract class ClientWrapper {
    final String t, ua, unf, pwf;

    public ClientWrapper(String target, String userAgent, String usernameField, String passwordField) {
        t = target;
        ua = userAgent;
        unf = usernameField;
        pwf = passwordField;
    }

    public abstract void start();

    public void start(Runnable runnable){
        System.out.println("Initalized.");
        Scanner in = new Scanner(System.in);
        while (true) {
            int n = in.nextInt();
            System.out.println("+" + n);
            for (int i = 1; i <= n; i++) {
                ExecutorService cachedThreadPool = new ThreadPoolExecutor(0, Integer.MAX_VALUE, Long.MAX_VALUE,
                        TimeUnit.SECONDS, new SynchronousQueue<Runnable>());

                cachedThreadPool.execute(runnable);
                try {
                    Thread.sleep(666 + U.r.nextInt(233));
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    // e.printStackTrace();
                }
            }
        }
    }
}
