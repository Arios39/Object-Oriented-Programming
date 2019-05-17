//
//  Rect.h
//  Lab02
//
//  Created by Andres Rios on 2/21/19.
//  Copyright © 2019 Andres Rios. All rights reserved.
//

#ifndef Rect_h
#define Rect_h
enum Shape {none, circle, cross};

#include <stdio.h>

struct rectangle {
    float x;
    float y;
    float w;
    float h;

    bool occupied;
    Shape shape;
    
    rectangle();
    rectangle(float x,float y, float w, float h);
    
    bool contains(float mx, float my);
    
    void draw();
    
};















#endif /* Rect_h */
