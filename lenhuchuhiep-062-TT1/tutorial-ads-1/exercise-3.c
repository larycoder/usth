#include<stdio.h>
#include<math.h>
//define struct
struct point{
  float x;
  float y;
};
int main(){
  //user enter 2 vectors
  printf("we have 2 vectors, please note direction for them\n");
  struct point a;
  printf("vector a has :\nx=");
  scanf("%f",&a.x);
  printf("y=");
  scanf("%f",&a.y);
  struct point b;
  printf("vector b has :\nx=");
  scanf("%f",&b.x);
  printf("y=");
  scanf("%f",&b.y);
  //computer Euclidean distance
  printf("Euclidean distance between two Points is %.3f\n",sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
  return 0;
}
