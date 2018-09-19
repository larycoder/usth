#include<stdio.h>
int main(){
  //i chose interger
  //enter number elements
  int sum=0,n;
  printf("enter number of array=");
  scanf("%d",&n);
  int array[n];
  //enter each elements
  printf("enter integer elements of array:\n");
  for(int i=0;i<n;i++){
    printf("array[%d]=",i+1);
    scanf("%d",&array[i]);
  }
  //return sum of al elements
  int*ptr=array;
  for(int i=0;i<n;i++) sum+=*(ptr+i);
  printf("sum of all elements in array=%d\n",sum);
  return 0;
}
