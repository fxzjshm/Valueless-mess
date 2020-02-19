package io.github.fxzjshm.websitecracker;
import java.util.Random;

public abstract class U {
    static Random r = new Random();

    public static String gP() {
        r.setSeed(System.nanoTime() + r.nextLong());
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= r.nextInt(10) + 8; i++) {
            sb.append((char) ('a' + r.nextInt(26)));
        }
        return sb.toString();
    }

    public static String gU() {
        r.setSeed(System.nanoTime() + r.nextLong());
        return String.valueOf(r.nextInt(99900000) + 100000);
    }
}
