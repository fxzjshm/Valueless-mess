// package io.github.fxzjshm.hanzi.process;

import static java.lang.System.in;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.util.regex.*;

public class HanziProcess2{
// http://www.360doc.cn/article/3328689_345160678.html
public static Scanner sc=new Scanner(in);

public static void main(String args[])throws Exception{
    File file = new File("/tmp/HanziProcess2.txt");
    PrintStream printStream = new PrintStream(file);
    System.setOut(printStream);
    String s,s2,ss1[],ss2[];
    // Pattern pattern=Pattern.compile(".*（.*）.*");
    while(true){
        /*String[] ss=s.split("[.]{2,4}（[.]{1,27}）[.]*");
        out.println(ss.length);
        for(String si:ss){
            out.println(si);
        }*/

        // P1
        /*s=sc.nextLine();
        ss1=s.split("（",2),ss2=ss1[1].split("）",2);
        out.println(ss1[0]+","+ss2[0]+","+ss2[1]);*/

        //P2-5
        /*s=sc.next();
        out.print(s+",");
        s=sc.nextLine();
        ss1=s.split("：|:",2);
        out.println(ss1[0]+","+ss1[1]);*/

        //P6,8,11
        /*boolean f=true;
        s=sc.nextLine();
        ss1=s.split("：|:",2);
        for(int i=0;i<ss1[0].length();i++){
            if(f&&i!=0&&isChinese(ss1[0].charAt(i-1))&&(!isChinese(ss1[0].charAt(i)))){
                f=true;
                out.print(",");
            }
            out.print(ss1[0].charAt(i));
        }
        out.println(","+ss1[1]);*/

        //P7 Format edited
        /*s=sc.next();
        StringBuilder sb=new StringBuilder();
        sb.append(s).append(",");;
        for(int i=1;i<=s.length();i++){
            sb.append(sc.next()).append(" ");
        }
        sb.append(",").append(sc.nextLine());
        out.println(sb);*/

        //P9 edited
        /*s=sc.next();
        StringBuilder sb=new StringBuilder();
        sb.append(s).append(",");;
        for(int i=1;i<s.length();i++){
            sb.append(sc.next());
            if(i!=s.length()-1)sb.append(" ");
        }
        ss1=sc.nextLine().split("：|:",2);
        sb.append(ss1[0]).append(",").append(ss1[1]);
        out.println(sb);*/

        //P10,12
        boolean f=true;
        s=sc.nextLine();
        s=s.replace("、","");
        ss1=s.split("：|:",2);
        int i=0;
        for(;i<ss1[0].length();i++){
            if(i!=0&&(!isChinese(ss1[0].charAt(i-1)))&&(isChinese(ss1[0].charAt(i)))){
                break;
            }
        }
        for(;i<ss1[0].length();i++){
            if(f&&i!=0&&isChinese(ss1[0].charAt(i-1))&&(!isChinese(ss1[0].charAt(i)))){
                f=true;
                out.print(",");
            }
            out.print(ss1[0].charAt(i));
        }
        out.println(","+ss1[1]);
    }
}
    private static final boolean isChinese(char c) {
    Character.UnicodeBlock ub = Character.UnicodeBlock.of(c);
    if (ub == Character.UnicodeBlock.CJK_UNIFIED_IDEOGRAPHS
            || ub == Character.UnicodeBlock.CJK_COMPATIBILITY_IDEOGRAPHS
            || ub == Character.UnicodeBlock.CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A
            || ub == Character.UnicodeBlock.GENERAL_PUNCTUATION
            || ub == Character.UnicodeBlock.CJK_SYMBOLS_AND_PUNCTUATION
            || ub == Character.UnicodeBlock.HALFWIDTH_AND_FULLWIDTH_FORMS) {
        return true;
    }
    return false;
}

}
