package io.github.fxzjshm.websitecracker;
public class C {

    public static void main(String[] args) throws Exception {
        // Case 5
        new ApacheHTTPClientWrapper("http://www.savhot.com/data/uploadtmp/20130526/auth.php",
                "MQQBrowser/26 Mozilla/5.0 (Linux; U; Android 2.3.7; zh-cn; MB200 Build/GRJ22; CyanogenMod-7) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0 Mobile Safari/533.1",
                "u", "p").start();
    }

}
