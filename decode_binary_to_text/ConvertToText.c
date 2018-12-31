#include <stdio.h>
#include <string.h>

FILE *fp;               //binary file
FILE *ftxt;             //text file

unsigned char bit[8];

unsigned char word;     //personal

void Initialize(const char *name){                            //open binary file to read
    fp=fopen(name,"r");

    char nameText[strlen(name)+strlen(".txt")];        //build name of out put 
    strcpy(nameText,name);                                       //file and create file
    strcat(nameText,".txt");
    ftxt=fopen(nameText,"w");
}

unsigned char readByte(void){                                 //take byte on file and return 
    unsigned char read[1];
    fread(read,1,1,fp);
    return read[0];
}

void BytetoBit(unsigned char byte){                         //convert byte to bit
    word=byte;                                                              //personnal
    unsigned char mask=1;
    for(int i=0;i<8;i++){
        bit[7-i]=(byte>>i)&mask;
    }
}

int main(){
    const char name[100];
    printf("#Type full path of file here [<= 100 character]:\n");
    scanf("%s",name);

    Initialize(name);

    if(!fp){
        printf("error can not open file !\n");
        return -1;
    }

    while(!feof(fp)){
        BytetoBit(readByte());
        for(int i=0;i<8;i++){
            fprintf(ftxt,"%d",bit[i]);
        }
        fprintf(ftxt,"::");

        printf("%c",word);                    //personnal
    }
    printf("successed");
    fclose(fp);
    fclose(ftxt);
    return 0;
}