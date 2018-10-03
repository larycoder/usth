#include<stdio.h>
int main(){
  //warnning
  printf("please enter the type after question mark, any other character not demand in question can cause bug.");
  //chose type
  printf("\nchose type you want float' or 'int' or 'char'? ");
  int c,i;
  while((i=getchar())!=10){
    if(i=='f') {
      c=1;
    }
    else if(i=='i'){
      c=0;
    }
    else if(i=='c'){
      c=2;
    }
  }
  //user enter 2 value
  //case of float and int
  if(c!=2){
    float add,add2;
    float*ptr=&add;
    printf("add value for add1=");
    scanf("%f",ptr);
    printf("add value for add2=");
    scanf("%f",(ptr=&add2));
    //compute and return result
    if(c==0) printf("add1=%d\nadd2=%d\nadd1+add2=%d\n",(int)add,(int)*(ptr),(int)(*ptr+add));
    else printf("add1=%f\nadd2=%f\nadd1+add2=%f\n",add,*(ptr),*ptr+add);
  }
  //special case of char character
  else{
    int add,add2;
    int*ptr=&add;
    printf("add value for add1=");
    while((i=getchar())!=10){
      *ptr=i;
    }
    ptr=&add2;
    printf("add value for add2=");
    while((i=getchar())!=10){
      *ptr=i;
    }
    printf("add1=%c\nadd2=%c\nadd1+add2=%c%c\n",add,*(ptr),add,*ptr);
  }
  return 0;
}
