#include<stdio.h>
#include<stdlib.h>

//define node of list

typedef struct node{
  int data;
  struct node *next;
}node;

//global pointer point to 3 disks

struct node *SOURCE=NULL;//create tower source
struct node *TMP=NULL;//create tower tmp
struct node *TARGET=NULL;//create tower target

//free dynamic memory after finishing

void free_stack(struct node *ptr){
  struct node *del;
  while(ptr!=NULL){
    del=ptr;
    ptr=ptr->next;
    free(del);
  }
}

//push value to list

void push(struct node *ptr,int data){
  struct node *new=(struct node *)malloc(sizeof(struct node));//create node
  new->data=data;//push data to node
  new->next=ptr->next;//point new node to older node
  ptr->next=new;//point head to new node
}

//take out value from stack

int pop(struct node *ptr){
  struct node *tmp=ptr->next;//point temp to big node
  ptr->next=ptr->next->next;//move head to second node
  int data=tmp->data;//take our value of node
  free(tmp);//delete top node
  return data;//return value of top node
}

//function to display info of 3 tower in each step program soft disk

void display(void){
  struct node *ptr=SOURCE->next;//build pointer ptr to source tower
  printf("tower source: ");
  while(ptr!=NULL){
    printf("%d ",ptr->data);//show value of node of source tower
    ptr=ptr->next;//shift pointer to next node
  }
  printf("\n");
  ptr=TARGET->next;//build pointer ptr to target tower
  printf("tower target: ");
  while(ptr!=NULL){
    printf("%d ",ptr->data);//show value of node of target tower
    ptr=ptr->next;//shift pointer to next node
  }
  printf("\n");
  ptr=TMP->next;//build pointer ptr to tmp tower
  printf("tower tmp:    ");
  while(ptr!=NULL){
    printf("%d ",ptr->data);//show value of node of tmp tower
    ptr=ptr->next;//shift pointer to next node
  }
  printf("\n-------------------------------------\n");
}

//recursive function to move disk

void move(struct node *source,struct node *target,struct node *tmp,int count){
  if(count==1){
    push(target,pop(source));//base of recursive
    display();
  }
  else{
    move(source,tmp,target,count-1);//move n-1 disk to tmp
    push(target,pop(source));//move disk #n to target
    display();
    move(tmp,target,source,count-1);//move n-1 disk to target
  }
}

//create head of stack

struct node *begin(void){
  struct node *ptr=(struct node *)malloc(sizeof(struct node));
  ptr->data=0;
  ptr->next=NULL;
  return ptr;
}

//init first tower of disks

void init(struct node *ptr,int count){
  int i;
  for(i=0;i<count;i++){
    push(ptr,(count-i));
  }
}

//order user for number of disks and solving problem

void action(void){
  int count;//value store number of disks
  printf("this is program solving HaNoi tower probem\n");//user type number of disks for solving
  printf("number of disks you want to move is: ");
  scanf("%d",&count);
  SOURCE=begin();//create memory for source tower
  TARGET=begin();//create memory for target tower
  TMP=begin();//create memory for tmp tower
  init(SOURCE,count);//creating source of disks
  display();//show 3 tower before sort
  move(SOURCE,TARGET,TMP,count);//solving problem
  free_stack(SOURCE);
  free_stack(TARGET);
  free_stack(TMP);
}

//run program

int main(){
  action();
  return 0;
}
