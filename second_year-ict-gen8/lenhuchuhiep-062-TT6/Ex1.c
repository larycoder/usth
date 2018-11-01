/**
*EXERCISE PUBLIC LICENSE
*version 1, 12 octorber 2018
*
*Author: Le Nhu Chu Hiep
*Copyright(C) 2018 USTH_ADS_TT[https://github.com/larycoder/usth/tree/master/second_year-ict-gen8]
*
*This program is free software: you can redistribute it and/or modify it.
*But if you want to use it for your ADS exercise submitting to Pro.Quang in USTH
*Please make sure your exercise and this code are different at least 10% words not counting blank
*
*/

#include <stdio.h>
#include <stdlib.h>

//define ADT of binary tree

typedef struct node{
  int value;
  struct node *Lchild;
  struct node *Rchild;
}node;

//pointer point to root of tree

struct node *Root=NULL;

void show(int data,int tab);//function manage render of list in console
void display(struct node *tmp,int tab);//function to read tree then show it to console by function "show"
void free_tree(struct node *del);//funtion to free link list tree after finishing
int length_list(void);//function to count numbers of value in file "list_data.txt"
void sort(int *arr,int size);//function to sort list following bubble sort
struct node *build_tree(int *arr,int position,int length);//function to build tree in link list type
void push_data(void);//function to push value from file to stastic array before building link list tree
void announce(void);//function to announce for user way to modify data to tree

//running program

int main(){
  announce();
  display(Root,0);
  free_tree(Root);
  return 0;
}

//using list to arrange tree

void announce(void){
  printf("This program arranges a list as 1 binary tree, it uses data in Ex6_list.txt file\n");
  printf("(you can modify data of list in file \"list_data.txt\" with syntax: number+semicolon)\n");
  push_data();
}

//push value from file to stastic array before building link list tree

void push_data(void){
  int n=length_list();
  int arr[n];//make template stastic list to store value from file
  FILE *fp=fopen("list_data.txt","r");
  int count,number=0,i=0;
  //read file and push value to array
  while((count=fgetc(fp))!=EOF){
    int ch=(count-'0');
    if(count==';'){
      arr[i++]=number;
      number=0;
    }
    else if(ch<10&&ch>=0)
      number=number*10+ch;
  }
  //sorting this array
  sort(arr,i);
  //add expand value following request of exercise
  number=arr[i-1];
  while(i<n)
    arr[i++]=number;
  //build link list tree of list
  Root=build_tree(arr,0,n/2);
}

//count number of values in file

int length_list(void){
  //count true number value from text
  FILE *fp=fopen("list_data.txt","r");
  int count,length=0;
  while((count=fgetc(fp))!=EOF)
    if(count==';')
      length++;
  fclose(fp);
  //add expand space to stastic list for expand value following request of exercise
  for(count=1;count<length;count*=2)
    ;
  return count;
}

//using bubble sort to provide 1 sorted list

void sort(int *arr,int size){
  int swap=1;
  while(swap!=0){
    swap=0;
    int i;
    for(i=0;i<(size-1);i++)
      if(arr[i]>arr[i+1]){
        arr[i]+=arr[i+1];
        arr[i+1]=arr[i]-arr[i+1];
        arr[i]-=arr[i+1];
        swap=1;
      }
  }
}

//build linked list tree using recursive

struct node *build_tree(int *arr,int position,int length){
  //create and add value to internal node of main tree
  struct node *root=(struct node *)malloc(sizeof(struct node));
  root->value=arr[position+length-1];
  //build terminal node: base case
  if(length==1){
    root->Lchild=(struct node *)malloc(sizeof(struct node));
    root->Lchild->value=arr[position];
    root->Lchild->Lchild=root->Lchild->Rchild=NULL;
    root->Rchild=(struct node *)malloc(sizeof(struct node));
    root->Rchild->value=arr[position+1];
    root->Rchild->Lchild=root->Rchild->Rchild=NULL;
    return root;
  }
  //build subtree and add subtree to main tree
  struct node *Lchild=build_tree(arr,position,length/2);
  struct node *Rchild=build_tree(arr,position+length,length/2);
  root->Lchild=Lchild;
  root->Rchild=Rchild;
  return root;
}

//free binary tree after finishing process using recursive technique

 void free_tree(struct node *del){
   //base case: there is not any subtree then free node
   if(del->Lchild==NULL){
     free(del);
     return;
   }
   //case there is subtree: free each child of node then free node
   free_tree(del->Lchild);
   free_tree(del->Rchild);
   free(del);
 }

//diplay binary tree using recursive technique

void display(struct node *tmp,int tab){
  show(tmp->value,tab);//function to render node of main tree in console
  //base case: there is not any child then it is leaf -> dont show value of its child
  if(tmp->Lchild==NULL){
    return;
  }
  //display subtree of main tree node
  display(tmp->Rchild,tab+1);
  display(tmp->Lchild,tab+1);
}

//arrange the way number render in console: dont forcus too much to this algorithm

void show(int data,int tab){
  int i;
  for(i=0;i<tab;i++){
    if(i==tab-1){
      printf("|--");
      break;
    }
    printf("    ");
  }
  printf(">");
  printf("%d\n",data);
}
