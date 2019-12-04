#include"point.h"
float pole(struct POINT a, struct POINT b,struct POINT c){
    float p=0.5*(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    if (p>0){
        return p;
    }
    else {
        return -1*p;
    }
}