#pragma once

#include "includes.h"

typedef int graphicsint; //change to something in your graphics library for efficiency if you need

class VirtualTurtle {
private:
    float x_ = 0;
    float y_ = 0;
    unsigned char r_ = 0;
    unsigned char g_ = 0;
    unsigned char b_ = 0;
    float angle_ = 0; //facing right, like the unit circle
    bool pendown_ = true;
    void (*color_)(unsigned char, unsigned char, unsigned char);
    void (*pixel_)(graphicsint, graphicsint);
public:
    void setColorFunc(void (*func)(unsigned char, unsigned char, unsigned char)) {
        color_ = func; 
    }
    void setPixelFunc(void (*func)(graphicsint, graphicsint)) {
        pixel_ = func;
    }
    void forward(float length);
    void left(float angle);
    void right(float angle);
    void tp(float x, float y);
    void move(float x, float y);
    void penup() {
        pendown_ = false; 
    }
    void pendown() {
        pendown_ = true; 
    }
    void pencolor(unsigned char r, unsigned char g, unsigned char b) {
        r_ = r; g_ = g; b_ = b; 
    }
    graphicsint getx() {
        return x_;
    }
    graphicsint gety() {
        return y_;
    }
};