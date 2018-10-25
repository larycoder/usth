/**
*EXERCISE PUBLIC LICENSE
*version 1, 12 octorber 2018
*
*Author: Le Nhu Chu Hiep
*Copyright(C) 2018 USTH_ADS_TT[https://github.com/larycoder/usth/tree/master/second_year-ict-gen8]
*
*This program is free software: you can redistribute it and/or modify it.
*But if you want to use it for your ADS exercise submitting to Pro.Quang in USTH
* please make sure your exercise and this code are different at least 10% words not counting blank
*/

#include <stdio.h>
#include <time.h>

//user make array by themselve
//complexity O[n]

void user_array(int *arr,int size){
  printf("welcome to program, now put in values of array:\n");
  int i=0;
  for(i=0;i<size;i++){
    printf("value[%d]= ",i+1);
    scanf("%d",&arr[i]);
  }
}

//function creating radomly number -- following pro.Doan Nhat Quang code
//complexity O[1]

int random_number(void){
  int iSecret=rand()%99+1;
  return iSecret;
}

//machine make array following size of user
//complexity O[n]

void machine_array(int *arr,int size){
  printf("please wait a minutes, it may take few minutes to process\n");
  int i=0;
  srand ( time(NULL) );
  for(i=0;i<size;i++){
    arr[i]=random_number();
  }
}

//display values in array
//complexity O[n]

void display(int *arr, int size){
  int i;
  for(i=0;i<size;i++){
    printf("value[%d]= %d\n",i+1,arr[i]);
  }
}

//sorting array following bubble sort technique and recusive technique
//complexity O[n2]

void sort(int *arr, int size,int dir,int init){
  int i=0;
  int swap=0;
  // 1 loop is 1 running cursol for check array value following direction is instruted
  for(i=0;i<size-1;i++){
    if((arr[init+dir]-arr[init])*dir<0){
      arr[init]+=arr[init+dir];
      arr[init+dir]=arr[init]-arr[init+dir];
      arr[init]=arr[init]-arr[init+dir];
      swap=1;
    }
    init+=dir;//move init up to next position depend on direction
  }
  init-=dir;
  if(swap==0)//check after 1 loop, if there is no swap value then array is sorted, stop sorting
    return;
  sort(arr,size-1,-dir,init);//sort in smaller part of array and inverse direction of running cursol check
}

//option for user
//complexity O[n2]

void option(void){
  printf("Hi! this is sorting program following bubble sort\n");
  printf("now try to create 1  int array:\n");
  printf("How many elements in your array: ");
  int size;
  scanf("%d",&size);
  int arr[size];
  printf("1.Try your own array\n");
  printf("2.Machine create it for you\n");
  printf("your choise: ");
  int option;
  scanf("%d",&option);
  if(option==1)
    user_array(arr,size);
  if(option==2)
    machine_array(arr,size);
  else{
    printf("error input");
    return;
  }
  printf("your array is: \n");
  display(arr,size);
  clock_t begin=clock();
  sort(arr,size,1,0);
  clock_t end=clock();
  printf("time run bubble sort is %lfs\n",(double)(end-begin)/CLOCKS_PER_SEC);
  printf("sorted array is: \n");
  display(arr,size);
}

//begin running program in here
//complexity O[n]

int main(){
  option();
  printf("complexity of algorithm is \n");
  printf("best:    O[n]\n");
  printf("worst:   O[n*n]\n");
  printf("average: O[n*n]\n");
  return 0;
}
