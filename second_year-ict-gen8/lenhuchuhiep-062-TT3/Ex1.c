#include <stdio.h>
#include <stdlib.h>

//define letter of 1 string

typedef struct letter{
  int data;//var store character of string
  struct letter *next;//pointer to point to next character
}letter;

//define top of string

typedef struct name{
  int size;//length of string
  struct letter *next;//pointer point to first letter
}name;

//function to init string

struct name *init_string(void){
  struct name *string=(struct name*)malloc(sizeof(struct name));//create memory of top of string
  string->size=0;//length of string is 0
  string->next=NULL;//point first letter to null
  return string;
}

//function to create 1 letter in string

void mk_letter(struct name *top,char data){
  struct letter *letter=(struct letter*)malloc(sizeof(struct letter));//create memory of 1 letter
  letter->data=data;//push data to letter memory
  letter->next=top->next;//connect letter to older letter
  top->next=letter;//top of string point to new letter
  top->size++;//increase length of string
}

//function to input letter to string

void input(struct name *top){
  printf("put name of you: ");//take name of user
  int data;//value to store letter from console
  while((data=getchar())!=10){
    mk_letter(top,data);
  }//while brance
}

//function to push out console

int pop(struct name *top){
  struct letter *push=top->next;
  top->size--;//decrease length of string
  top->next=top->next->next;//shift pointer to next letter
  int data=push->data;//take letter form list
  free(push);//free memory of letter after using
  return data;
}

//function to output reverse name

void output(struct name *top){
  printf("your reverse name is: ");//out put reverse name
  while(top->size>0){
    printf("%c",pop(top));
  }
  printf("\n");
}

//function to user input string and return reverse string

void name_reverse(struct name *string){
  input(string);//take name from console
  output(string);//put out result
}

//begin program

int main(){
  int end;//var to end ptogram
  struct name *string;//create 1 string
  string=init_string();//begin string
  printf("program to reverse string\n");
  do{
    name_reverse(string);//to user input string and return reverse string
    printf("type 1 to continue program and 0 to end program: ");
    scanf("%d",&end);
    getchar()
  }while(end==1);
  free(string);
  return 0;
}
