// load game info
#include<stdio.h>
#include"myStructs.c"

struct Game** loadGame(FILE *file,int nOfGames){
    struct Game** allGames;
    // int* games[nOfGames];
    char c=1;
    int ncounter=0;
    for(int i= 0;i<=nOfGames;i++){
        while(c!=109){

            if (c==13){

            }
            
        }
    }

return &allGames;
}
int matchCounter(FILE *file){
    rewind(file);
  int count =0;
  char c=getc(file);

   while ( c != EOF ) 
            { 
              // c == m
              if(c==109){
                printf("Found match");
                count++;
              }
              c=getc(file);
            } 
  rewind(file);
  return count;
}