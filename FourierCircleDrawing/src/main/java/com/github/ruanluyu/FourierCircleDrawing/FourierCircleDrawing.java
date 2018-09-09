package com.github.ruanluyu.FourierCircleDrawing;

import processing.core.PApplet;
import processing.core.PGraphics;
import processing.core.PVector;

public class FourierCircleDrawing extends PApplet {
    // String[] lines;
    float datas[][] = null;
    float rp[][] = null;
    int maxCircle = -1;// Max num off circle,unlimited when it is -1
    float rotationSpeed = 0.003f;// Speed of rotation

    @Override
    public void setup() {

        String[] lines = loadStrings("FourierMath/datas.txt");
        datas = new float[lines.length][2];
        rp = new float[lines.length][2];
        for (int i = 0; i < lines.length; i++) {
            String cache[] = split(lines[i], ",");
            if (cache.length < 2) {
                break;
            }
            datas[i][0] = Float.parseFloat(cache[0].replace("[", ""));
            datas[i][1] = Float.parseFloat(cache[1].replace("]", ""));
            rp[i][0] = sqrt(datas[i][0] * datas[i][0] + datas[i][1] * datas[i][1]);
            rp[i][1] = atan2(datas[i][1], datas[i][0]);
        }
        spot = createGraphics(width, height);
        coord = createGraphics(width, height);
        coord.beginDraw();
        coord.stroke(0, 15, 25, 100);
        coord.line(0, coord.height / 2f, coord.width, coord.height / 2f);
        coord.line(coord.width / 2f, 0, coord.width / 2f, coord.height);
        coord.endDraw();
    }

    PVector size = new PVector(1, 1); // pixel/unit
    PGraphics spot = null;
    PGraphics coord = null;
    PVector lastPos = new PVector();
    float t = -0f;// init t.If you want program to start drawing at beginning,set this to 0.
    int reversey = 1;

    @Override
    public void draw() {
        background(255);
        t += rotationSpeed;
        image(coord, 0, 0);
        PVector center = new PVector();
        PVector pointer = new PVector();
        noFill();
        stroke(255);
        int num = (maxCircle > 0) ? min(maxCircle, datas.length) : datas.length;
        for (int i = 0; i < num; i++) {
            int m = 0;
            if (i > 0)
                m = ((i + 1) / 2) * ((i % 2 == 0) ? -1 : 1);
            float r = rp[i][0];
            stroke(175);
            ellipse(center.x * size.x + width / 2f, reversey * center.y * size.y + height / 2f, r * size.x * 2f,
                    r * size.y * 2f);
            float theta = reversey * t * m + rp[i][1];
            pointer.add(new PVector(r * cos(theta), r * sin(theta)));
            if (m == 0)
                pointer.set(datas[0][0], datas[0][1]);
            stroke(100);
            line(center.x * size.x + width / 2f, reversey * center.y * size.y + height / 2f,
                    pointer.x * size.x + width / 2f, reversey * pointer.y * size.y + height / 2f);
            center.set(pointer);
        }
        stroke(10, 255, 10);
        fill(100, 124, 255, 150);
        ellipse(pointer.x * size.x + width / 2f, reversey * pointer.y * size.y + height / 2f, 8, 8);
        if (t >= 0) {
            spot.beginDraw();
            spot.noStroke();
            // spot.stroke(0, 155, 255);
            // spot.strokeWeight(3);
            spot.fill(0, 155, 255);
            spot.translate(spot.width / 2f, spot.height / 2f);
            // spot.line(lastPos.x*size.x,lastPos.y*size.y,pointer.x*size.x,pointer.y*size.y);
            spot.ellipse(pointer.x * size.x, reversey * pointer.y * size.y, 5, 5);
            spot.endDraw();
            image(spot, 0, 0);
        }
        lastPos.set(pointer);
        // noLoop();
    }

    @Override
    public void settings() {
        size(1920, 1080);
    }

    public static void main(String[] args) {
        try {
            // FourierMath$py.main(args);
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        /*
        Properties props = new Properties();
        props.put("python.import.site", "false");
        Properties preprops = System.getProperties();
        PythonInterpreter.initialize(preprops, props, new String[0]);
        PythonInterpreter interpreter = new PythonInterpreter();
        interpreter.exec("" + "# -*- coding: utf-8 -*-\r\n" +
                "# from __future__ import *\r\n" +
                "from __future__ import division\r\n" +
                "\r\n" +
                "import math\r\n" +
                "import cmath\r\n" +
                "import re\r\n" +
                "import time\r\n" +
                "import multiprocessing\r\n" +
                "\r\n" +
                "'''\r\n" +
                "作者：中梓星音\r\n" +
                "简介：\r\n" +
                "    这是一个导入并解析svg曲线信息，并计算其在各转速轮下的轨道初始参数的程序。\r\n" +
                "程序：\r\n" +
                "    1.读取svg原始信息，解析，并放入points列表中（二维坐标点列->复数列）\r\n" +
                "    2.用points列表计算轨道初始参数（复数列）\r\n" +
                "    3.输出轨道初始参数（复数列->二维坐标点列）\r\n" +
                "'''\r\n" +
                "\r\n" +
                "def bezier(t,a,b,c,d):#贝塞尔函数（估测长度用）\r\n" +
                "    return (-a+3*b-3*c+d)*t*t*t+3*(a-2*b+c)*t*t+3*(-a+b)*t+a\r\n" +
                "\r\n" +
                "def linear(x,a,b,c,d):#映射函数\r\n" +
                "    return (x-a)/(b-a)*(d-c)+c\r\n" +
                "'''\r\n" +
                "def equation(bt,t,m,bV):#主要计算函数——（废弃）\r\n" +
                "    return bezier(bt,bV[0],bV[1],bV[2],bV[3])*cmath.exp(-m*1j*t)\r\n" +
                "'''\r\n" +
                "oneOver2PI = 1/(math.pi*2)#常量\r\n" +
                "\r\n" +
                "def prSolve(m,cs,ce,n):#主要计算函数1-解析解\r\n" +
                "    if m == 0 :\r\n" +
                "        return (ce-cs)*oneOver2PI/(n+1)\r\n" +
                "    if n==0 :\r\n" +
                "        return 1j*oneOver2PI/m*(cmath.exp(-m*1j*ce)-cmath.exp(-m*1j*cs))\r\n" +
                "    elif n>0 :\r\n" +
                "        return 1j*oneOver2PI/m*cmath.exp(-m*1j*ce)-n*1j/((ce-cs)*m)*prSolve(m,cs,ce,n-1)\r\n" +
                "    else : \r\n" +
                "        return 0\r\n" +
                "\r\n" +
                "def numSolve(m,cs,ce,pts):#主要计算函数2-贝塞尔曲线方程代入\r\n" +
                "    return (-pts[0]+3*pts[1]-3*pts[2]+pts[3])*prSolve(m,cs,ce,3)+3*(pts[0]-2*pts[1]+pts[2])*prSolve(m,cs,ce,2)+3*(-pts[0]+pts[1])*prSolve(m,cs,ce,1)+pts[0]*prSolve(m,cs,ce,0)\r\n" +
                "\r\n" +
                "\r\n" +
                "def cpToList(cp):\r\n" +
                "    return [cp.real,cp.imag]\r\n" +
                "start = 0\r\n" +
                "end = 1000#圆圈数量\r\n" +
                "prjNum = end-start+1\r\n" +
                "prjCur = None\r\n" +
                "points = []#贝塞尔采集点\r\n" +
                "out = []#输出用坐标容器\r\n" +
                "center = [500,500]#中心点位置\r\n" +
                "curWeight = []#各段曲线的时间权重容器\r\n" +
                "trDatas = []#临时容器\r\n" +
                "sharedPoints = None\r\n" +
                "\r\n" +
                "def initParam(pts,cw,pjc):\r\n" +
                "    global points,curWeight,prjCur\r\n" +
                "    points = pts\r\n" +
                "    curWeight = cw\r\n" +
                "    prjCur = pjc\r\n" +
                "\r\n" +
                "def mainCalculation(s):\r\n" +
                "    global points,curWeight,prjCur\r\n" +
                "    m = 0\r\n" +
                "    if s>0: \r\n" +
                "        m = ((s+1)//2)*(-1 if (s%2 == 0) else 1)\r\n" +
                "    #print(\"Now working on orbit {0},m = {1}\".format(s,m))\r\n" +
                "    sum = 0j\r\n" +
                "    for i in range(len(points)):\r\n" +
                "        cs = linear(curWeight[i],0,1,0,math.pi*2)\r\n" +
                "        ce = linear(curWeight[i+1],0,1,0,math.pi*2)\r\n" +
                "        sum += numSolve(m,cs,ce,points[i])\r\n" +
                "    with prjCur.get_lock():\r\n" +
                "        prjCur.value += 1\r\n" +
                "    return cpToList(sum)\r\n" +
                "\r\n" +
                "\r\n" +
                "if __name__ == '__main__':\r\n" +
                "    with open('rawvertexes.txt', 'r') as f:#读取并解析SVG信息\r\n" +
                "        rawdata = f.readlines()\r\n" +
                "        curve = re.sub(r'\\s','',\"\".join(rawdata))\r\n" +
                "        cells = re.findall(r'\\w[\\d\\,\\-\\.]+',curve)\r\n" +
                "        for cell in cells:\r\n" +
                "            trcdata = []\r\n" +
                "            formatString = re.sub(r'-',',-',cell)\r\n" +
                "            trcdata.append(re.match(r'[A-Za-z]',formatString).group(0))\r\n" +
                "            rawvers = re.sub(r'[A-Za-z]\\,?','',formatString).split(',')\r\n" +
                "            for st in range(len(rawvers)):\r\n" +
                "                rawvers[st] = float(rawvers[st])\r\n" +
                "            vergroup = []\r\n" +
                "            vercurgrp = []\r\n" +
                "            for st in range(len(rawvers)):\r\n" +
                "                vercurgrp.append(rawvers[st])\r\n" +
                "                if len(vercurgrp)>=2:\r\n" +
                "                    vergroup.append(vercurgrp[0]+vercurgrp[1]*1j)\r\n" +
                "                    vercurgrp[:] = []\r\n" +
                "            if len(vercurgrp)>0:\r\n" +
                "                if re.match(r'v',trcdata[0],re.I):\r\n" +
                "                    vergroup.append(0+vercurgrp[0]*1j)\r\n" +
                "                elif re.match(r'h',trcdata[0],re.I):\r\n" +
                "                    vergroup.append(vercurgrp[0]+0j)\r\n" +
                "            trcdata.append(vergroup)\r\n" +
                "            trDatas.append(trcdata)\r\n" +
                "        print('Vertexes data have been read.')\r\n" +
                "\r\n" +
                "    for i in range(1,len(trDatas)):#解析SVG信息\r\n" +
                "        if re.match(r'[a-z]',trDatas[i][0]):\r\n" +
                "            for j in range(len(trDatas[i][1])):\r\n" +
                "                trDatas[i][1][j]+=trDatas[i-1][1][-1]\r\n" +
                "    for i in range(len(trDatas)):#解析SVG信息\r\n" +
                "        flag = trDatas[i][0]\r\n" +
                "        if re.match(r'm',flag,re.I):continue\r\n" +
                "        trDatas[i][1].insert(0,trDatas[i-1][1][-1])\r\n" +
                "        if re.match(r's',flag,re.I):\r\n" +
                "            trDatas[i][1].insert(1,2*trDatas[i-1][1][-1]-trDatas[i-1][1][-2])\r\n" +
                "        if re.match(r'[lvh]',flag,re.I):\r\n" +
                "            trDatas[i][1].insert(1,trDatas[i][1][0]/3+trDatas[i][1][-1]*2/3)\r\n" +
                "            trDatas[i][1].insert(1,trDatas[i][1][0]*2/3+trDatas[i][1][-1]/3)\r\n" +
                "\r\n" +
                "    for i in range(len(trDatas)):#解析SVG信息\r\n" +
                "        flag = trDatas[i][0]\r\n" +
                "        if re.match(r'm',flag,re.I):continue\r\n" +
                "        points.append(trDatas[i][1])\r\n" +
                "    for i in range(len(points)):#将中心点归零\r\n" +
                "        for j in range(len(points[i])):\r\n" +
                "            points[i][j] -= center[0]+1j*center[1]\r\n" +
                "\r\n" +
                "    print(\"Weight process start.\")#计算时间权重\r\n" +
                "    wsum = 0\r\n" +
                "    for curve in points:#Calculate weight\r\n" +
                "        wst = 10 #steps\r\n" +
                "        sum = 0\r\n" +
                "        for i in range(1,wst):\r\n" +
                "            sum+=abs(bezier(linear(i,0,wst,0,1),curve[0],curve[1],curve[2],curve[3])-\r\n" +
                "            bezier(linear(i-1,0,wst,0,1),curve[0],curve[1],curve[2],curve[3]))\r\n" +
                "        curWeight.append(sum)\r\n" +
                "        wsum+=sum\r\n" +
                "    for i in range(len(curWeight)):\r\n" +
                "        curWeight[i] /= wsum\r\n" +
                "    for i in range(1,len(curWeight)):\r\n" +
                "        curWeight[i] += curWeight[i-1]\r\n" +
                "    curWeight.insert(0,0)\r\n" +
                "    curWeight[-1] = 1\r\n" +
                "    print(\"Weight process finished.\")\r\n" +
                "    #print(points)\r\n" +
                "    out = []\r\n" +
                "    print(\"Initializing...\")\r\n" +
                "    multiprocessing.freeze_support()#并行计算开始\r\n" +
                "    prjCur = multiprocessing.Value('i',0)\r\n" +
                "    pool = multiprocessing.Pool(initializer = initParam,initargs = (points,curWeight,prjCur))\r\n" +
                "    print(\"Initializing finished.\")\r\n" +
                "    print(\"Main calculation start.\")\r\n" +
                "    out = pool.map_async(mainCalculation, range(start,end+1))\r\n" +
                "    division = 50\r\n" +
                "    while True :\r\n" +
                "        percentage = prjCur.value/prjNum\r\n" +
                "        nump = round(percentage*division)\r\n" +
                "        # print(\"[{}{}] {:.0%}\".format(\"=\"*nump,\" \"*(division-nump),percentage),end = '\\r',flush = True)\r\n" +
                "        print(\"[{}{}] {:.0%}\".format(\"=\"*int(nump),\" \"*int(division-nump),percentage))\r\n" +
                "        if prjCur.value>=prjNum : \r\n" +
                "            print()\r\n" +
                "            break\r\n" +
                "        time.sleep(0.1)\r\n" +
                "    pool.close()\r\n" +
                "    pool.join()\r\n" +
                "    out.wait()\r\n" +
                "    out = out.get()\r\n" +
                "    print(\"Main calculation finished.\")\r\n" +
                "    with open(\"datas.txt\", \"w\") as File:#把结果写入硬盘\r\n" +
                "        for dc in out:\r\n" +
                "            File.write(\"{0}\".format(dc))\r\n" +
                "            File.write(\"\\n\")\r\n" +
                "    print(\"Data saved.\\n\\nWork finished.\\n\")#完成提示\r\n" +
                "\r\n" +
                "");//*/
        PApplet.main("com.github.ruanluyu.FourierCircleDrawing.FourierCircleDrawing");
    }
}
