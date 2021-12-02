#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdbool.h>


    typedef struct{
        float x;
        float y;
    }Point2;

    typedef struct{
        Point2 center;
        float radius;

    }Circle;
// float circle_perimeter( struct Circle * self ){
//     return M_PI*2*(self.radius);
// };

bool circle_contains_circle ( Circle * self, Circle * other){
    // printf("%f",self);
    Point2 center1 = self ->center;
    Point2 center2 = other->center;
    // printf("%f\n",center1.x);
    float distance = sqrt(pow(center2.x-center1.x,2)+pow(center2.y-center1.y,2));
    if(self->radius < other->radius || distance + other->radius >= self->radius){
        return false;
    }else {
        return true;
    }
    // if ()
};
int main(){
    float myPerimeter;
    // float *x1,*x2,*y1,*y2,*radius1,*radius2;
    float x1,x2,y1,y2,radius1,radius2;
    // Circle circle, secondCircle;
    scanf("%f%f%f",&x1,&y1,&radius1);
   
    // Circle circle = {  .radius= *radius1, .center={.x=*x1,.y=*y1}  };
     Circle circle={  .radius= radius1, .center={.x=x1,.y=y1}  };
    scanf("%f%f%f",&x2,&y2,&radius2);
    // Circle secondCircle = {  .radius= *radius2, .center={.x=*x2,.y=*y2}  };
    Circle secondCircle = {  .radius= radius2, .center={.x=x2,.y=y2}  };
// printf("%f\n",circle.radius);
    circle_contains_circle(&circle,&secondCircle)?printf("True\n"):printf("False\n");
    // printf("Circle radius: %f\n",&circle.radius);
    // printf("pointer to circle: %f",circle.radius);
    // myPerimeter = circle_perimeter(circle);
    // printf("%.2f\n",myPerimeter);
 
}