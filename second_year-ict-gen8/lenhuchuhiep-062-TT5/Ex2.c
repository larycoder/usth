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

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//define node of list

typedef struct node{
  int data;
  struct node *next;
}node;

//add node to list

struct node*add(struct node *ptr,int data){
  struct node *new=(struct node*)malloc(sizeof(struct node));
  new->data=data;
  new->next=ptr;
  return new;
}

//delete all node of list after finishing program

void free_list(struct node *ptr){
  struct node*tmp=NULL;
  while(ptr!=NULL){
    tmp=ptr;
    ptr=ptr->next;
    free(tmp);
  }
}

//display list of values

void display(struct node*ptr){
  int i=1;
  while(ptr!=NULL){
    printf("value[%2d]= %d\n",i,ptr->data);
    ptr=ptr->next;
    i++;
  }
}

//take in data from console and check for finished condition of list

struct node*takein(struct node*ptr,int *state){
  int count,number=0;
  //take one value on console and check if all is number:
  //true then combine them to built up whole number
  while((count=getchar())!='\n'){
    if((count-'0')<10&&(count-'0')>-1)
      number=number*10+(count-'0');
    else{
      *state=0;
      return ptr;
    }
  }
  ptr=add(ptr,number);
  return ptr;
}

//user input their own value for list

struct node*user_array(struct node *ptr){
  int data,i=0,state=1;
  getchar();//remove buffer of before input that make sure next algorithm go right
  printf("please enter value, type any non-number for finishing your list\n");
  while(state==1){
    i++;
    printf("value[%d]= ",i);
    ptr=takein(ptr,&state);
  }
  return ptr;
}

//ramdom number and put it in list

struct node*machine_make(struct node*ptr,int size,int scale){
  srand(time(NULL));
  int i,data;
  for(i=0;i<size;i++){
    data=rand()%(size+1);
    ptr=add(ptr,data);
  }
  return ptr;
}

//machine chose randome of value for list

struct node*machine_array(struct node*ptr){
  printf("Chose length of list: ");
  int size;
  scanf("%d",&size);
  printf("Chose scale restricted interval of randomly number: ");
  int scale;
  scanf("%d",&scale);
  ptr=machine_make(ptr,size,scale);
  printf("machine list is: \n");
  display(ptr);
  return ptr;
}

//count length of linked list

int length_array(struct node*ptr){
  int count=0;
  while(ptr!=NULL){
    count++;
    ptr=ptr->next;
  }
  return count;
}

//add 1 reference to exactly 1 position of linked list and disconect that node with previous node
//attention: position of node much count from 0

struct node*push_reference(struct node*ptr,int position){
  int i;
  //run pointer to the position needed to add reference
  for(i=0;i<position;i++){
    //after reach of wanted position, disconect it with previous node
    if(i==(position-1)){
      struct node*tmp=ptr;
      ptr=ptr->next;
      tmp->next=NULL;
      return ptr;
    }
    //shift pointer to next node
    ptr=ptr->next;
  }
  return ptr;//return reference added to corrertly position
}

//insert 1 exit node to final of  1 list

struct node*insert(struct node*ptr,struct node*NODE){
  NODE->next=NULL;//make sure node not cause error
  //case dont have any node
  if(ptr==NULL)
    return NODE;
  //case have node then shift pointer to the end of list then add node in there
  struct node*tmp=ptr;
  while(tmp->next!=NULL){
    tmp=tmp->next;
  }
  tmp->next=NODE;
  return ptr;
}

//combine 2 part of array devided by merge sort

struct node*sort(struct node*L,struct node*R){
  struct node*ptr=NULL;
  struct node*tmp=NULL;
  //combine and sort 2 part of list following merge sort technique
  while(L!=NULL&&R!=NULL){
    if(L->data<R->data){
      tmp=L;
      L=L->next;
      ptr=insert(ptr,tmp);
    }
    else{
      tmp=R;
      R=R->next;
      ptr=insert(ptr,tmp);
    }
  }
  while(L!=NULL){
    tmp=L;
    L=L->next;
    ptr=insert(ptr,tmp);
  }
  while(R!=NULL){
    tmp=R;
    R=R->next;
    ptr=insert(ptr,tmp);
  }
  return ptr;
}

//sort array following merge sort

struct node*merge(struct node*ptr,int size){
  if(size==1)
    return ptr;//if number of value in list is 1 then return pointer point to that node
  //add pointer to midder value of list
  struct node *L=push_reference(ptr,0);
  struct node *R=push_reference(ptr,((size-1)/2)+1);
  //sort each part of list
  L=merge(L,size-size/2);
  R=merge(R,size/2);
  //combine 2 part of list to 1
  struct node*tmp=sort(L,R);
  return tmp;
}

//option for user

struct node*option(struct node *ptr){
  printf("this is program try to sort your data following merge sort technique\n");
  printf("you has 2 option:\n");
  printf("1.Try your own array\n");
  printf("2.Machine create it for you\n");
  printf("your option is: ");
  int option;
  scanf("%d",&option);
  if(option==1)
    ptr=user_array(ptr);
  else if(option==2)
    ptr=machine_array(ptr);
  else{
    printf("error\n");
    return ptr;
  }
  int size=length_array(ptr);
  ptr=merge(ptr,size);
  printf("list after sorting is: \n");
  display(ptr);
  return ptr;
}

//running program

int main(){
  struct node *head=NULL;
  head=option(head);
  free_list(head);
  return 0;
}
