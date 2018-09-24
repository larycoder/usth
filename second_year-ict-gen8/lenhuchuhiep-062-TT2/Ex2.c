#include<stdio.h>
#include<stdlib.h>

//define new name of type

typedef long long int lli;

//define node of term

typedef struct node{
  int constant;//constant of term in polynomial function
  int degree;//degree of term in polynomial function
  struct node *next;//pointer point to next term
}node;

//define head of list of polynomial function

typedef struct head{
  int size;
  struct node *head;
}head;

//function init list of polynomial function

head *init_head(void){
  head *head=(struct head *)malloc(sizeof(head));
  head->size=0;
  head->head=NULL;
  return head;
}

//function delete dynamic memory of list

void free_list(head *head){
  for(int i=0;i<head->size;i++){
    node *delete=head->head;//add delete pointer to node want to delete
    head->head=head->head->next;//shift head to next node
    free(delete);//delete node
  }
  free(head);//delete head of node
}

//function to make new term

void mkterm(head *head,int constant,int degree){
  node *term=(node *)malloc(sizeof(node));//create new term
  term->next=head->head;//point next of new node to old node
  head->head=term;//point head of list to new node
  head->size++;//increase length of list
  term->constant=constant;//put constant of term to node constant
  term->degree=degree;//put degree of term to node degree
}

/*function to check if this degree of term was exit or not
  add 2 constant have same term degree if exit
  and make new term if this degree does not exit
*/

void check_term(head *head,int constant,int degree){
  int test=0;//function to confirm that term has same degree of user info exit or not
  node *check=head->head;//point check pointer to node
  for(int i=0;i<head->size;i++){
    if(check->degree==degree){
      check->constant+=constant;//add constant
      test=1;
      break;//break loop if find out term has same degree
    }
    check=check->next;//shift to next node
  }
  if(test==0) mkterm(head,constant,degree);//create new term
}

//function to ask user info of new term

void add_term(head *head){
  int constant;
  int degree;
  printf("Degree of your term: ");//user info for term degree
  scanf("%d",&degree);
  printf("Constant of your term: ");//user info for term constant
  scanf("%d",&constant);
  check_term(head,constant,degree);//check if term have same degree was exit or not
}

//function to delete term

void delete_term(head *head,int degree){
  //case term that head point to needing to delete
  if(head->head->degree==degree){
    node *delete=head->head;//pointer delete point to node needed delete
    head->head=head->head->next;//head point to next node of deleted node
    head->size--;//decrease length of list
    free(delete);//free memory of delete node
  }
  //case term that not pointed by head needing to delete
  else{
    node *delete=head->head;//create pointer to delete term
    for(int i=0;i<((head->size)-1);i++){
      if(delete->next->degree==degree){
        node *die=delete->next;//pointer die point to node needed to delete
        delete->next=delete->next->next;//new linked of previous and next node of deleted node
        free(die);//free memory of deleted node
        head->size--;//decrease length of list
        break;//end loop
      }
      delete=delete->next;//shift delete pointer to next node
    }
  }
}

//function to remove term in polynomial function

void remove_term(head *head){
  int degree;//var to save user info of degree term want to remove
  printf("term of degree you want to remove: ");//user put info of degree
  scanf("%d",&degree);
  delete_term(head,degree);//delete term that user input
}

//function to compute x power

long long int degree_compute(int degree,int x){
  lli final=(lli)x;//var store all multiply of x following its degree
  //case degree is 0
  if(degree==0) x=1;
  //case degree is defferent form 0
  else{
    for(int i=1;i<degree;i++){
      final*=final;//compute x power
    }
  }
  return final;
}

//function to compute polynomial function

long long int compute(head *head,int x){
  long long int sum=0;//var store total calculate of polynomial function
  node *check=head->head;//pointer check will move throught all term to take info
  for(int i=0;i<(head->size);i++){
    sum+=(lli)(check->constant)*degree_compute(check->degree,x);//calculate polynomial function
    check=check->next;//shift to next term
  }
  return sum;
}

//function to calculate polynomial function

void calculate_function(head *head){
  int x;//var store value of variable user want to compute
  printf("putting value of x: ");//input x info
  scanf("%d",&x);
  printf("result = %lld\n",compute(head,x));//compute engine and return result
}

//function to sort term following degree by using bubble sort technique

void sort_term(head *head){
  int exchange;//var to change 2 term
  int state=0;//var to count in bubble sort
  //loop to sort term following degree
  while(state!=((head->size)-1)){
    node *change=head->head;//pointer point to node
    state=0;//default state to 0
    for(int i=0;i<(head->size-1);i++){
      if((change->degree)>(change->next->degree)){
        //change degree of 2 term
        exchange=change->degree;
        change->degree=change->next->degree;
        change->next->degree=exchange;
        //change constant of 2 term
        exchange=change->constant;
        change->constant=change->next->constant;
        change->next->constant=exchange;
      }//if brance
      else state++;
      change=change->next;//shift pointer to next node
    }//for brance
  }//while brance
}

//function to display polynomial function

void display_function(head *head){
  printf("the polynomial function is: \nf(x)=");
  sort_term(head);//sort term in polynomial function following
  node *change=head->head;//pointer point to node
  for(int i=0;i<(head->size-1);i++){
    printf("%d*x^%d+",change->constant,change->degree);//print polynomial function
    change=change->next;//shift pointer to next node
  }
  printf("%d*x^%d\n",change->constant,change->degree);//print out final term
}

//function ask user for their option

void ask(head *head){
  int option;//var save user option
  printf("this is program to manage polynomial function of integer number\n");//introduce program
  printf("- Put 1 if you want to add term\n");//option for user
  printf("- Put 2 if you want to remove term\n");//option for user
  printf("- Put 3 if you want to calculate function\n");//option for user
  printf("- Put 4 if you want to display function\n");//option for user
  printf("your chose: ");//input user option
  scanf("%d",&option);
  if(option==1) add_term(head);//add term
  else if(option==2) remove_term(head);//remove term
  else if(option==3) calculate_function(head);//calculate function
  else if(option==4) display_function(head);//display function
  else printf("error option, please enter number in option\n");//warnning user
}

//begin program

int main(){
  int end;//var to end program
  struct head *head=init_head();//create term of polynomial function
  do{
    end=0;
    ask(head);
    printf("Do you want to continue program ?\n0 is yes and 1 is no: ");
    scanf("%d",&end);
  }while(end==0);
  free_list(head);
  return 0;
}
