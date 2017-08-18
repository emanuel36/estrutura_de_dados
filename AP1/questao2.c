#include <stdio.h>
#include <math.h>

typedef struct position Position;

struct position{
  int* x;
  int* y;
};

float iDistance(Position* p){
  float dis = pow((4 - (*(p->x))), 2) + pow((3 - *(p->y)), 2);
  return sqrt(dis);
}

int main(){
  int X, Y;
  Position pontos;
    
  scanf("%d", &X);
  scanf("%d", &Y);
  
  pontos.x = &X;
  pontos.y = &Y;
 
  printf("%f", iDistance(&pontos));

  return 0;
}