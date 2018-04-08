// package io.github.fxzjshm.hanzi.process;

import static java.lang.System.in;
import static java.lang.System.out;
import java.util.*;
import java.io.*;

public class HanziProcess{
// http://www.360doc.cn/article/3328689_345160678.html
public static Scanner sc=new Scanner(in);
public static void checkAndPrint(char si){
        /*if(si==','){
            out.print("，");
        }else */if(si=='\"'){
            out.print("\"\"");
        }else out.print(si);
}
public static void readAndPrint(){
    String s=sc.nextLine();
    StringBuilder sb=new StringBuilder("");
    int ind=s.indexOf("（");
    // out.println(s.indexOf('（'));
    if(ind<=2&&ind>=0){
        sb.append(s);
        ind=s.indexOf("（");
        sb.replace(ind,ind+1,",");
        ind=s.indexOf("）");
        sb.replace(ind,ind+1,",");
    }else{
        sb.append(",").append(s);
        ind=s.indexOf("：");
        if(ind==-1)ind=s.indexOf(":");
        sb.replace(ind+1,ind+2,",");
    }
    out.println(sb.toString());
}
public static void main(String args[])throws Exception{
File file = new File("/tmp/HanziProcess.txt");
PrintStream printStream = new PrintStream(file);
System.setOut(printStream);
    String w1;
    while(true){
        w1=sc.next();
        out.print(w1);
        readAndPrint();
    }
}

}
