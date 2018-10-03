#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define node

typedef struct node{
  char name[100];
  int id;
  struct node *next;
}node;

//define head

typedef struct head{
  int size;
  struct node *next;
  struct node *pre;
}head;

//init queue

struct head *init(void){
  struct head *ptr=(struct head*)malloc(sizeof(struct head));
  ptr->size=0;
  ptr->next=NULL;
  ptr->pre=NULL;
  return ptr;
}

//free memory of queue

void free_queue(struct head *ptr){
  while(ptr->size>0){
    struct node *delete=ptr->next;
    ptr->next=ptr->next->next;
    ptr->size--;
    free(delete);
  }
  free(ptr);
}

//check if the queue is empty or not

int is_empty(struct head *ptr){
  if(ptr->size==0) return 1;
  return 0;
}

//add a new iteam at the back of the queue

void enqueue(struct head *ptr,char *string,int id){
  if(is_empty(ptr)){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    strcpy(new->name,string);
    new->id=id;
    new->next=ptr->next;
    ptr->next=new;//tail pointer
    ptr->pre=new;//head pointer
    ptr->size++;
  }
  else{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    strcpy(new->name,string);
    new->id=id;
    new->next=ptr->next;
    ptr->next=new;
    ptr->size++;
  }
}

//remove the front iteam of the enqueue

void dequeue(struct head *ptr){
  struct node *delete=ptr->pre;
  ptr->size--;
  ptr->pre=ptr->next;
  int i;
  for(i=0;i<(ptr->size-1);i++){
    ptr->pre=ptr->pre->next;
  }
  free(delete);
}

//function return the size of the dequeue

int length(struct head *ptr){
  return ptr->size;
}

//function resize length of queues

void resize(struct head *ptr,int number){
  while(ptr->size>number){
    dequeue(ptr);
  }
}

//function to display waiting row

void display(struct head *ptr){
  struct node *change=ptr->next;
  int i;
  for(i=0;i<(ptr->size);i++){
    printf("passenger[%d]_name:%s(id:%d)\n",(ptr->size-i),change->name,change->id);
    change=change->next;
  }
}

//function demand user book ticket of train

int book(struct head *ptr,int number){
  char name[100];
  int id,end;
  printf("Do you want to go in this train [y/n]: ");
  getchar();
  end=getchar();
  if(end=='n') return 0;
  printf("Register your ticket:\n");
  printf("Your last name: ");
  scanf("%s",name);
  printf("Your id that you see on table: ");
  scanf("%d",&id);
  enqueue(ptr,name,id);
  resize(ptr,number);
  printf("\nThis train has %d passenger that is: \n",length(ptr));
  display(ptr);
  return 1;
}

//begin program

int main(){
  struct head *ptr=init();
  int number,end;
  printf("Exercise 4:\nthe number of passengers can be in row: ");
  scanf("%d",&number);
  do{
    end=book(ptr,number);
  }while(end==1);
  free_queue(ptr);
  return 0;
}
