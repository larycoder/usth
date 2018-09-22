#include <stdio.h>
typedef long int li;
int chISBN(li a);
int main(){
  //announced
  printf("this is program to check if ISBN is true or not\nplease enter 9 digit  of following International Standard Book Numbers to check");
  //calculate and return final ISBN
  printf("\nthis is test:\nISBN:408858734-?\n");
  li final=408858734;
  printf("ISBN:%ld-%d\n",final,chISBN(final));
  printf("this is another test:\nISBN:408872271-?\n");
  final=408872271;
  printf("ISBN:%ld-%d\n",final,chISBN(final));
  printf("now please enter your 9 ISBN\nISBN:");
  scanf("%ld",&final);
  printf("ISBN:%ld-%d\n",final,chISBN(final));
  return 0;
}
//function create ISBN digit checking
int chISBN(li a){
  int j=9;
  int sum=0;
  while(j>0){
    sum+=a%10*j;
    a/=10;
    j--;
  }
  sum%=11;
  return sum;
}
