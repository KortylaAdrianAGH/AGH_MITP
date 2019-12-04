#include "point.h"
#include<math.h>
float obwod(struct POINT a, struct POINT b,struct POINT c){
    float obwod2,ab,bc,ca;
    ab=sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
    bc=sqrt((c.x-b.x)*(c.x-b.x)+(c.y-b.y)*(c.y-b.y));
    ca=sqrt((a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y));
    obwod2=ab+bc+ca;
    return obwod2;
}