#include<stdio.h>

//function to multiply 2 integer

int m_int(int a, int b){
  if(a<0){
    a*=-1;
    return -m_int(a,b);
  }
  else if(a>=0){
    if(a==0)
      return 0;
    else if(a==1)
      return b;
    return m_int(a-1,b)+b;
  }
}

//run program

int main(){
  int a=0,b=0;
  printf("this is program to multiply 2 integer numbers\n");
  printf("number 1: ");
  scanf("%d",&a);
  printf("number 2: ");
  scanf("%d",&b);
  printf("%d*%d=%d",a,b,m_int(a,b));
  return 0;
}
