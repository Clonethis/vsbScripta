#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void printArray(int *array,int length){
    for(int i = 0; i<=length;i++){
        printf("Value %d : %d\n",i,*(array+i));
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
int populatePlayersId(int* playerIds,int length,FILE *file){
  int count =0,playerNum=0;
  char c='\n',id[20];
  rewind(file);
  printf("nice");
  printf("players[1] ids %d\n",playerIds[2]);
  printf("players ids %d\n",*(playerIds));
  printf("players ids+1 %d\n",*(playerIds+1));
  assert(playerIds);
  for(int i = 0; i<=10;i++){
      *(playerIds+i) = 0;
      printf("players ids+%d - %d\n",i,*(playerIds+i));

  }
//   char c=1;99
  while(c!=EOF){
    // 48->56 nums; 59 = ";" 44=","
    // c=getc(file);
    printf("%c",c);
    if(c==10){
        printf("run");
      c = getc(file);
      while(c!=44){
        id[count] = c;
        
        count++;
        printf("%c",id[count]);
        c = getc(file);
      }
      if(playerNum==length+1){
          break;
          return 1;
      }
      printf("id %d\n",atoi(id));
          printf("pnum %d\n",playerNum);
      playerIds[playerNum] = atoi(id);
      printf("Nice players %d\n",playerIds[playerNum]);
      for(int i= 0;i<20;i++){
          id[i]=0;
      }
      count = 0;
      playerNum++;
    }
    c=getc(file);

  }
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

    int* playerIds[players];
    char** playerNames[players][20];
    //   not working due to unknown bug
    // printf("playerIDS %d",);
    populatePlayersId(playerIds,players,fplayer);
    populatePlayerNames(playerNames,players,fplayer);
    printArray(playerIds,players);
    // TODO
    // populateGames()

    // calc Elo
    // paint on svg
    
    // free(playerIds);
}


