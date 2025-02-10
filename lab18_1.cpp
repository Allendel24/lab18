#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1, Rect R2){
    double i, j;
    
    if(min(R1.x + R1.w, R2.x + R2.w) < max(R1.x, R2.x)) i = 0;
    else if(R1.x < R2.x && R1.x + R1.w < R2.x + R2.w)
    i = R1.x + R1.w - R2.x;
    else if(R2.x < R1.x && R2.x + R2.w < R1.x + R1.w)
    i = R2.x + R2.w - R1.x;
    else i = min(R1.w, R2.w);
    
    if(max(R1.y - R1.h, R2.y - R2.h) > min(R1.y, R2.y)) j = 0;
    else if(R1.y > R2.y && R1.y - R1.h > R2.y - R2.h)
    j = R2.y - (R1.y - R1.h);
    else if(R2.y > R1.y && R2.y - R2.h > R1.y - R1.h)
    j = R1.y - (R2.y - R2.h);
    else j = min(R2.h, R2.h);
    
    return i*j;
}