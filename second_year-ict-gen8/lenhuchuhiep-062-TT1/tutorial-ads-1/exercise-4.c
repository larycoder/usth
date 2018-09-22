#include<stdio.h>
typedef struct point{
  float x,y;
}point;
int fall(point,point,point);
int main(){
  int repeat=0;
  point a,b;
  do{
    //user enter 2 vectors and program check if it can satisfy condition of exercise or not
    repeat=0;
    printf("we have 2 vectors, please note direction for them\n");
    printf("vector a has :\nx=");
    scanf("%f",&a.x);
    printf("y=");
    scanf("%f",&a.y);
    printf("vector b has :\nx=");
    scanf("%f",&b.x);
    printf("y=");
    scanf("%f",&b.y);
    if((a.x-b.x)==0||(a.y-b.y)==0){
      printf("error please try again\n\n");
      repeat==1;
    }
  }while(repeat==1);
  //compute area of rectangle
  float area=0;
  area=(a.x-b.x)*(a.y-b.y);
  if(area<0) area*=-1;
  printf("the area of rectangle is %.3f\n",area);
  //user chose 1 another vector
  point c;
  printf("vector c has :\nx=");
  scanf("%f",&c.x);
  printf("y=");
  scanf("%f",&c.y);
  printf("the point c fall within a rectangle is %d\n",fall(a,b,c));
  return 0;
}
//function check if the new vectors satisfy exercise condition or not
int fall(point a,point b,point c){
  int test=0;
  if((a.x>c.x>b.x)||(b.x>c.x>a.x)) test++;
  if((a.y>c.y>b.y)||(b.y>c.y>a.y)) test++;
  if(test==2) return 1;
  return 0;
}
