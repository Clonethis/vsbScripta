#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void printArray(int *array,int length){
    for(int i = 0; i<=length;i++){
        printf("Value %d : %d\n",i,*(array+i));
    }
}
void printArrayC(char **array,int length,int elementLength){
    for(int i = 0; i<=length;i++){
        for(int x = 0;x <= elementLength;x++){

        printf("Value %d : %c\n",i,array[i][x]);
        }
    }
}
int numberOfRows(FILE *file){
int count = 0;
  for(char c=getc(file);c!=EOF;c=getc(file)){
  if( c == '\n'){
    count++;
    // printf("newline");
  }}
  rewind(file);
//   printf("count %d\n",count);
  return count;
}
int numberOfGames(FILE *file){
  rewind(file);
  int count =0;
  char c=getc(file);

   while ( c != EOF ) 
            { 
              // c == m
              if(c==109){
                printf("New match");
                count++;
              }
              c=getc(file);
            } 
  rewind(file);
  return count;

}

//  }
int populatePlayersNames(char** playerNames[],int length,FILE *file,int name_size){
char  c = 0;
int playerNum = 0,countName = 0;
        while(c!=EOF){
        if(c==44){

        while(c!='\n' && c>=35 && c<=122){
          playerNames[playerNum][countName]=c;
          c=getc(file);
          countName++;
          printf("%c",c);
        }
        countName= 0;
        }
        }
        rewind(file);
        return 0;
  
}
int populatePlayersId(int* playerIds,int length,FILE *file){
  int countID =0,playerNum=0;
  char c='\n',id[20];
  rewind(file);
  assert(playerIds);
  
//   char c=1;99
  while(c!=EOF){
    // 48->56 nums; 59 = ";" 44=","
    // c=getc(file);
    if(c==10){
      c = getc(file);
      while(c!=44){
        id[countID] = c;
        countID++;
        // printf("%c",id[countID]);
        c = getc(file);
      }
      }
      if(playerNum==length+1){
          break;
          return 1;
      }
      playerIds[playerNum] = atoi(id);
      printf("Nice players %d\n",playerIds[playerNum]);
      for(int i= 0;i<20;i++){
          id[i]=0;
      }
      countID = 0;

      playerNum++;
    }
    c=getc(file);

  
//   rewind(file);
return 0;
}

int main(int agc,char **argv)
{  

    FILE *fplayer,*fgames;
    char before = -2;

    fplayer = fopen(argv[1], "r");
    fgames = fopen(argv[2], "r");
    if(fplayer==NULL || fgames==NULL){
        printf("couldn't open file");
        return 1;
    }
    int num = numberOfRows(fgames);
    int players = numberOfRows(fplayer);

    // int* playerIds = (int*)calloc(players,sizeof(int));
    int name_size = 20;
    int* playerIds[players];
    char** playerNames[players][name_size];
    //   not working due to unknown bug
    // printf("playerIDS %d",);
    populatePlayersId(playerIds,players,fplayer);
    populatePlayersNames(playerNames,players,fplayer,name_size);

    printArray(playerIds,players);
    printArrayC(&playerNames,players,20);
    // TODO
    // populateGames()

    // calc Elo
    // paint on svg
    
    // free(playerIds);
}


