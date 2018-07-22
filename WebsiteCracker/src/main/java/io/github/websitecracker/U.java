package io.github.websitecracker;
import java.util.Random;

public abstract class U {
    static Random r = new Random();

    public static String gP() {
        r.setSeed(System.nanoTime() + r.nextLong());
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= r.nextInt(10) + 8; i++) {
            sb.append((char) ('a' + r.nextInt(26)));
        }
        // System.out.println(sb.toString());
        return sb.toString();
    }

    public static String gU() {
        r.setSeed(System.nanoTime() + r.nextLong());
        StringBuilder sb = new StringBuilder();
        sb.append(r.nextInt(99900000) + 100000);
        // System.out.println(sb.toString());
        return sb.toString();
    }
}
