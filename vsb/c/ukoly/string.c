#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
    char text[100];
    int iterator=0;
    int ch;
while ( (ch = getchar()) != '\n') {
    if(ch>=65&&ch<=90){
        text[iterator]=ch;
        ++iterator;
    }else if(ch>=97&&ch<=122){
        text[iterator]=ch;
        ++iterator;
    }else{
        continue;
    }
}

    for (int i = 0; i<=strlen(text);i++){
        if(text[i]!=37){
           fprintf(stdout,"%c",text[i]);

        }
    }
    fprintf(stdout,"\n");

}