#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>





// https://www.tutorialspoint.com/cprogramming/c_pointers.htm
// advanced pointers : https://www.guru99.com/c-pointers.html
int* playerLoad(FILE *file){
 int *array = malloc(sizeof(file));
  // include loading data
  return array;
}
// redWin -> if yes 1, else 0;
int eloCALC (int* usersELO,int whichToCalc,int redWin){
  // mean rating for teams
  int i=0,ra,rb;
  while(i<5){
    if(i<2){
      // rating of user
      ra = ra + usersELO[i];
    }else{
      rb = rb + usersELO[i];
    }
    i++;
  }
  ra= ra/3;
  rb= rb/3;
  int ea,k,sa,newrating;
  ea = 1 / (1 + 10^((rb - ra) / 400));  // znak `^` značí mocninu.
  k = 30;
  if (redWin == 1){
    newrating = ra + k * (sa - ea);
  }
  return newrating;
}


struct Player{
  int id;
  char name[20];
  int elo;
  char teamPlays;
  int gamesPlayed;


};
typedef struct game{
  unsigned int id;
  char blu[20];
  char red[20];
  // char starts
  char playersStatsBlu[40];
  char playersStatsRed[40];
}Game;

int numberOfRows(FILE *file){
int count = 0;
  for(char c=getc(file);c!=EOF;c=getc(file)){
  if( c == '\n'){
    count++;
  }}
  rewind(file);
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
int calcLineLength(FILE *file){
  char c;
  int count = 0;
  while(c!='\n'){
    c=getc(file);
    count++;
  }
  // returns at the start of line
  fseek(file,sizeof(char),count);
  return count;
}
Game* loadGames(FILE *file,int length){

// loading lines instead of chars
Game games[length];
  char buffer[200];
  int row=0,col = 0,id=0;
  Game *ptr_G = &games[id];

  while (fgets(buffer, 200, file)) {
    ptr_G = &games[id];  
    col = 0;
    row++;
    if(row%6==0){
      continue;
      id++;
    }
     char* value = strtok(buffer, ",");
      while (value) {
        if((row-1)%6 ==0){
// load red id's
printf("Irun");
         strcpy(ptr_G->red,*value);
        }
        if((row-2)%6 ==0){
// stats for red
        }
        if((row-3)%6 == 0){
// load blu id's
// when loaded check if blue same as red
        }
        if((row-4)%6 == 0){
// stats for blu

        }
        if((row-5)%6 == 0){
// who won
        }
        value = strtok(NULL,",");
        row ++;

                
            }
  
            printf("\n");
            
return &games;
}}
// struct playerCreator( Player players,id,name,){

//  }
void populatePlayersId(int* playerIds,int len,FILE *file){
  rewind(file);
  printf("players ids %d",*(playerIds));
  char c;
  char id[10];
  int count = 0, playerNum = 0;
  while(c!=EOF){
    // 48->56 nums; 59 = ";" 44=","
    c=getc(file);
    printf("%c",c);
    if(c=='\n'){
      c = getc(file);
      while(c!=44){
        id[count] = c;
        count++;
        // printf("ints: %c",c);
        c = getc(file);
      }
      // printf("id %d\n",atoi(id));
      playerIds[playerNum] = atoi(id);
      id[0]=0;
      count = 0;
      playerNum++;
    }
  }
  rewind(file);
}

int main(int agc,char **argv)
{  
  
  FILE *fplayer,*fgames;
  char c,before = -2;
  char *id;
  // id = malloc(siqzeof(char)*8);
  // struct Player player;
  // int* players;
  // int user =-1,charCount=0;
  // size_t count=0,nmOfLines=0;
  fplayer = fopen(argv[1], "r");
  fgames = fopen(argv[2], "r");
  if(fplayer==NULL || fgames==NULL){
    printf("couldn't open file");
    return 1;
  }
  int num = numberOfRows(fgames);
  int players = numberOfRows(fplayer);
  
  int* playerIds = (int *)malloc(players*sizeof(int));
  printf("players ids main %d\n",playerIds);
  printf("players & ids main %d\n",&playerIds);
  printf("players * ids main %d\n",*playerIds);
  populatePlayersId(&playerIds,players,fplayer);
  // for(int i = 0; i<= players;i++){
  //   // printf("player ids: %d",playerIds[i]);
  // }
  // struct Game Games[games];
  // Game *games = loadGames(fgames,num);
  // FILE *out = fopen("output.txt","w");
  // fwrite(&games,sizeof(Game),3,out);
  // fclose(out);
  // struct Player Players[players];

  
  // int fplayrerLen = fseek(fplayer, 0L, SEEK_END);
  // int sz = ftell(fplayer);
  // printf("fplayer %d , f sz %d\n",fplayrerLen,sz);
  // rewind(fplayer);
  // printf("sizeof int %lu",sizeof(int));
  // printf("game matches: %lu",games);
  // int players=malloc(sizeof(fplayer)*4);
  // int players[sizeof(fplayer)];
  // printf("players length %d\n",sizeof(players));
  // assert(id);
  // assert(fplayer);
  // assert(fgames);
  // load chars
  
  // 44 = ',' 59= ";"
// allocating size for players
  

//   struct Player **Players = malloc(sizeof( player)*nmOfLines);
//   rewind(fplayer);
  
//   for(char c=getc(fplayer);c!=EOF;c=getc(fplayer)){

//   // TODO not finished loading of data
//   // missing inputing to array, just ints
//   // https://stackoverflow.com/questions/10204471/convert-char-array-to-a-int-number-in-c
//   if(c!=-2 || c != 10 || c!= 13 || c !=44){
//       Players[user][2].name[charCount]=c;
//       charCount++;
//   }
//   if (before==-2 || before==10){
//     count=0;
//     while(c!=44){
//       printf("Num: %c\n",c);
//       id[count] = c;
//       c=getc(fplayer);
//       // players[]=
//       count++;
//     }
//   id[count]=0;
    
//     Players[user]->id = strtol(id,0,10);

//     // Vynulovat id
//     for(int i =0; i<=7;i++){
//       id[i]=0;
//     }

//     user++;
//     charCount =0;
//   }
//     // printf("%c",c);
//     before = c;
//   }


// // free(players);
// return 0;

}


