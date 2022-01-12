#include <stdio.h>
#include <stdlib.h>
#include <assert.h>





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
  char* name;
  int* elo;
  char* teamPlays;
  int* gamesPlayed;


};
struct Game{
  unsigned int id;
  unsigned int blu[3];
  unsigned int red[3];
  // players stats
  unsigned int playersStatsBlu[9];
  unsigned int playersStatsRed[9];
};
int numberOfGames(FILE *file){
  rewind(file);
  int count =0;
  char c=getc(file);

   while ( c != EOF ) 
            { 
              // c == m
              if(c==109){
                printf("Iom running");
                count++;
              }
              c=getc(file);
            } 
  rewind(file);
  return count;

}
struct playerCreator( Player players,id,name,){

 }

int main(int agc,char **argv)
{  
  
  FILE *fplayer,*fgames;
  char c,before = -2;
  char *id;
  id = malloc(sizeof(char)*8);
  Player player;
  // int* players;
  int user =-1,charCount=0;
  size_t count=0,nmOfLines=0;
  fplayer = fopen(argv[1], "r");
  fgames = fopen(argv[2], "r");
  int fplayrerLen = fseek(fplayer, 0L, SEEK_END);
  int sz = ftell(fplayer);
  printf("fplayer %d , f sz %d\n",fplayrerLen,sz);
  rewind(fplayer);
  int games = numberOfGames(fgames);
  // printf("sizeof int %lu",sizeof(int));
  // printf("game matches: %lu",games);
  // int players=malloc(sizeof(fplayer)*4);
  // int players[sizeof(fplayer)];
  // printf("players length %d\n",sizeof(players));
  if(fplayer==NULL || fgames==NULL){
    printf("couldn't open file");
    return 1;
  }
  assert(id);
  // assert(fplayer);
  // assert(fgames);
  // load chars
  
  // 44 = ',' 59= ";"
// allocating size for players
  for(char c=getc(fplayer);c!=EOF;c=getc(fplayer)){
  if( c == '\n'){
    nmOfLines++;
  }}

  *Players = malloc(sizeof( player)*nmOfLines);
  rewind(fplayer);
  
  for(char c=getc(fplayer);c!=EOF;c=getc(fplayer)){

  // TODO not finished loading of data
  // missing inputing to array, just ints
  // https://stackoverflow.com/questions/10204471/convert-char-array-to-a-int-number-in-c
  if(c!=-2 || c != 10 || c!= 13 || c !=44){
      Players[user].name[charCount]=c;
      charCount++;
  }
  if (before==-2 || before==10){
    count=0;
    while(c!=44){
      printf("Num: %c\n",c);
      id[count] = c;
      c=getc(fplayer);
      // players[]=
      count++;
    }
  id[count]=0;
    
    Players[user].id = strtol(id,0,10);

    // Vynulovat id
    for(int i =0; i<=7;i++){
      id[i]=0;
    }

    user++;
    charCount =0;
  }
    // printf("%c",c);
    before = c;
  }


// free(players);
return 0;

}


