#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//define stack

typedef struct node{
  int data;
  struct node *next;
}node;

//define head of stack

typedef struct head{
  int size;
  struct node *next;
}head;

//funtion init list

struct head *init(void){
  struct head *ptr=(struct head*)malloc(sizeof(struct head));
  ptr->next=NULL;
  ptr->size=0;
  return ptr;
}

//function to take randomly 2 number

int random_number(void){
  srand(time(NULL));
  int iSecret=rand()%9+1;
  return iSecret;
}

//function to push number to stack

void push(struct head *ptr,int data){
  struct node *new_ptr=(struct node *)malloc(sizeof(struct node));//make new node
  new_ptr->data=data;//push data to new node
  new_ptr->next=ptr->next;//pointer of new node point to previous node
  ptr->next=new_ptr;//pointer of head point to new node
  ptr->size++;
}

//function to pop up node

int pop(struct head *ptr){
  struct node *pop_ptr=ptr->next;
  ptr->next=ptr->next->next;
  ptr->size--;
  int data=pop_ptr->data;
  free(pop_ptr);
  return data;
}

//function to finish list

void finish(struct head *ptr){
  int data;
  while(ptr->size>0){
    data=pop(ptr);
  }
  free(ptr);
}

//funtion create stack of randomly number

void stack(struct head *ptr){
  while(ptr->size<2){
    if(ptr->next!=NULL){
      int i=random_number();
      while(i==ptr->next->data){
        i=random_number();
      }//while brance
      push(ptr,i);
    }//if brance
    else{
      push(ptr,random_number());
    }//else brance
  }//while brance
}

//function to check 2 number

int check(struct head *ptr,int c){
  int a=pop(ptr);
  int b=pop(ptr);
  printf("2 numbers is: %d and %d\n",a,b);
  push(ptr,b);
  stack(ptr);
  if(a==c||b==c){
    printf("wrong!\n");
    return 0;
  }
  else if(((a-c)*(a-c))<((a-b)*(a-b)))
    return 1;
  printf("wrong!\n");
  return 0;
}

//function ask user

void ask(struct head *ptr){
  stack(ptr);
  printf("this is the game:\n");
  printf("we have 2 random value\n");
  printf("you must guess 1 number that can be between them\n");
  printf("you can choose 2 times\n");
  printf("after 1 times chose, one number will change\n");
  printf("good luck\n");
  int i,end,number;
  for(i=0;i<2;i++){
    printf("your chose is: ");
    scanf("%d",&number);
    end=check(ptr,number);
    if(end==1)
      break;
  }
  if(end==0)
    printf("you lose");
  else
    printf("you win");
}

//function to run program

int main(){
  struct head *ptr=init();
  ask(ptr);
  finish(ptr);
  return 0;
}
