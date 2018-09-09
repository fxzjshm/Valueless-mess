// package com.github.fxzjshm.test;

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
    private float rotationSpeed = 1;

    @Override
    public void draw() {
        background(255);
        t += rotationSpeed;
        image(coord, 0, 0);
        PVector center = new PVector();
        PVector pointer = new PVector();
        noFill();
        stroke(255);
        pointer.x = x(t);
        pointer.y = y(t);

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

    native float x(float t);
    native float y(float t);

    @Override
    public void settings() {
        size(1920, 1080);
    }

    public static void main(String[] args) {
        System.loadLibrary("test.so");
        PApplet.main("com.github.fxzjshm.test.Draw");
    }

}
