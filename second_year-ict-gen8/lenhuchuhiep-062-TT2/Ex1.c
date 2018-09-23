#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define car info

typedef struct node{
  int nu_pas;//number of passengers
  char name_car[10];//name of new car
  struct node *next;//pointer to next node
}node;

//define head of the train

typedef struct head{
  int size;
  struct node *head;
}head;

//you should init train

struct head *init_train(void){
  struct head *head=(struct head *)malloc(sizeof(struct head));//define 1 train head
  head->size=0;//first length is 0
  head->head=NULL;//when init there is no car in train
  return head;//push head train info to main
}

//now creat car for train

void mkcar(head *head,int nu_pas,char *name_car){
  struct node *car=(node *)malloc(sizeof(struct node));//init 1 memory for 1 car
  car->next=head->head;//push address of head to car
  head->head=car;//push address of this car to head train
  head->size++;//count length of train
  car->nu_pas=nu_pas;//push number of passengers
  strcpy(car->name_car,name_car);//add name to new car
}

//function to add new car

void add_car(head *head){
  int nu_pas;
  char name_car[10];
  printf("name of the car[max is 10 character with no space]=");//name info of new car
  scanf("%s",name_car);
  printf("number of passengers are: ");//number of passengers info
  scanf("%d",&nu_pas);
  if(nu_pas==0){
    ;//if there is no passengers then dont creat this car
  }
  else mkcar(head,nu_pas,name_car);//create new car with info of user
}

//display all train info

void display(head *head){
  node *read=head->head;//read info from final car to first
  printf("train has %d size\n",head->size);//print length of train
  for(int i=0;i<head->size;i++){
    printf("name of car is: %s\n",read->name_car);//print out name of car
    printf("number of passengers of car \"%s\" is: %d\n",read->name_car,read->nu_pas);//print out number of passengers
    read=read->next;//read info of next
  }
}

//ask user to input info for new car

void ask(head *head){
  int answer;
  printf("do you want to add new car or display info of car ? \n");//option for user chose
  printf("add 1 if add new car and 2 if display info ? ");
  scanf("%d",&answer);//input user answer
  if(answer==1) add_car(head);//add new car to train
  else if(answer==2) display(head);//display all info of train
}

//function to free all dynamic memory

void free_train(head *head){
  for(int i=0;i<head->size;i++){
    node *delete=head->head;//add delete pointer to node want to delete
    head->head=head->head->next;//shift head to next node
    free(delete);//delete node
  }
  free(head);//delete head of node
}

//begin program

int main(){
  head *head=init_train();//init 1 head
  int next=0;
  do{
    ask(head);//ask user for putting info
    printf("\nwhat next ? 1 is add or display train info, 0 will end program: ");//var to ask if user want to continuous program or not
    scanf("%d",&next);
  }while(next!=0);
  free_train(head);//free dynamic memory that declare in process
  return 0;
}
