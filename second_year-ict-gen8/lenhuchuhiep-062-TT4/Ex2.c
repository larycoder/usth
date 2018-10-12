#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//create stack
//define node

typedef struct node{
  int data;
  struct node *next;
}node;

//global pointer worked as pop pointer of stack

struct node *head=NULL;

//push data into stack

void push(int data){
  struct node *new=(struct node *)malloc(sizeof(struct node));//create dynamic memory for element
  new->data=data;//push user's data to node
  new->next=head;//point node new to older node
  head=new;//point head to new node
}

//pop up data from stack and delete top node

int pop(void){
  struct node *pop=head;//take 1 pointer to top node
  head=head->next;//move head to second node
  int data=pop->data;//push out data from top node
  free(pop);//delete top node
  return data;//return data of top node
}

//recursive function to calculate the sum of all data in stack

int sum(void){
  //base of recursive function: this is last node of stack
  if(head->next==NULL){
    int data=pop();//take out data of last node
    printf("%d\n",data);//print out console last node value
    return data;//return value of last node
  }
  else{
    int data=pop();//take out data of top node
    //if node last node, use recursive funtion to count node
    printf("%d ",data);//print out value of top node
    return data+sum();//plus value of top node with another node value through recursive
  }
}

//function to put in data from console

int input(void){
  int c,sum=0;
    //after user type enter, begin read console until reach of another enter
    while((c=getchar())!='\n'){
      sum*=10;//increase value of sum to 10
      if((c-'0')>9)//check if value read from cosole is number or letter
        return 1;//if value read from console is letter then return 1
      sum+=c-'0';//if value read from console is number then add it to sum
    }//while brance
    push(sum);//after read value from console if it dont have any letter then return number user type in
    return 0;//return 0 if value from console is number
}

//function asking user type elements of list

void ask(void){
  int count=0,end=0;
  getchar();//remove first enter of user for reading value that user type in console
  printf("enter elements of list or type \"f\" to finish list: \n");//user type number for list or letter to finish list
  while(end==0){
    count++;
    printf("elements[%d]= ",count);
    end=input();//var to check:0 mean user type number and 1 mean user type letter
  }//while brance
    printf("sum=%d\n",sum());//print out sum of all number in list
}

//function to take randomly number
//copy right from Pro.Doan_Nhat_Quang

int random_number(int size){
  srand(time(NULL));
  int iSecret=rand()%size+1;
  return iSecret;
}

//function to push randomly number to stack

void push_randomly_number(int scale){
  //check if the list already has node or not
  if(head==NULL)
    push(random_number(scale));//if there is not exit any node then make node with random value
  else{
    //case list already exited at least 1 node
    int diff=random_number(scale);
    //check if new value is equale to after node value or not: make sure it not
    while(diff==head->data){
      diff=random_number(scale);
    }//while brance
    push(random_number(scale));//push new value to list
  }//else brance
}

//function to ask user for randomly list

void random_function(void){
  int size=0,count=0,scale=0;
  printf("the length of list is: ");//user type in lenth of list
  scanf("%d",&size);
  printf("the scale of randomly number is: ");//user type in scale for randomly number run
  scanf("%d",&scale);
  for(count=0;count<size;count++){
    push_randomly_number(scale);//push random number to stack
  }
  printf("sum=%d\n",sum());//print out sum of all values in list
}

//optional function for user chose

void option(void){
  int option;
  printf("there are 2 optional for you:\n");
  printf("1.Take randomly number to list\n");
  printf("2.Create your own list\n");
  printf("your option is: ");
  scanf("%d",&option);
  if(option==1)
    random_function();//create random list
  else
    ask();//user type in number in here
}

//run program

int main(){
  option();
  return 0;
}
