package com.github.fxzjshm.test;

import java.io.File;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

import processing.core.PApplet;
import processing.core.PGraphics;
import processing.core.PVector;

public class Draw extends PApplet {

    @Override
    public void setup() {
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
    private float rotationSpeed = 0.05f;

    // final Object lock1 = new Object(), lock2 = new Object();

    ExecutorService e = Executors.newFixedThreadPool(3);

    @Override
    public void draw() {
        background(255);
        t += rotationSpeed;
        // System.out.println(t);
        image(coord, 0, 0);
        // PVector center = new PVector();
        PVector pointer = new PVector();
        noFill();
        stroke(255);

        Future<Double> fx = e.submit(new Callable<Double>() {
            @Override
            public Double call() throws Exception {
                double x = x(t);
                // System.out.println(x);
                return (x / 5);
            }
        });
        Future<Double> fy = e.submit(new Callable<Double>() {
            @Override
            public Double call() throws Exception {
                double y = y(t);
                // System.out.println(y);
                return (y / 5);
            }
        });
        // fx.isDone();fy.isDone();
        try {
            pointer.x = fx.get().floatValue() - 300;
            pointer.y = -fy.get().floatValue() - 400;
        } catch (InterruptedException | ExecutionException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        }

        // System.out.println(String.format("(%f,%f)", pointer.x, pointer.y));

        // synchronized (lock1) {
        // synchronized (lock2) {
        stroke(10, 255, 10);
        fill(100, 124, 255, 150);
        ellipse(pointer.x * size.x + width / 2f, reversey * pointer.y * size.y +
                height / 2f, 12, 12);
        if (t >= 0) {
            spot.beginDraw();
            spot.noStroke();
            // spot.stroke(0, 155, 255);
            // spot.strokeWeight(3);
            spot.fill(0, 155, 255);
            spot.translate(spot.width / 2f, spot.height / 2f);
            // spot.line(lastPos.x*size.x,lastPos.y*size.y,pointer.x*size.x,pointer.y*size.y);
            spot.ellipse(pointer.x * size.x, reversey * pointer.y * size.y, 3, 3);
            spot.endDraw();
            image(spot, 0, 0);
        }
        lastPos.set(pointer);
        text(new Double(Math.min(1, t / (128 * Math.PI))).toString(), 0, 0);
        // noLoop();
        // }
        // }
    }

    native double x(double t);

    native double y(double t);


    @Override
    public void settings() {
        size(1600, 900);
    }

    public static void main(String[] args) {
        String path = System.getProperty("java.library.path");
        System.out.println(new File(path + "\\test.dll").exists());
        /*
         * String[] files = new File(path).list(); for (String f : files)
         * System.out.println(f);//
         */

        System.loadLibrary("test");
        PApplet.main("com.github.fxzjshm.test.Draw");
    }

}
