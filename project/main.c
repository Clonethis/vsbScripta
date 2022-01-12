#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr, *fplayer;
    fptr = fopen("f1.txt", "r");
// ukazuje na zacatek file
    fplayer = fopen("users.txt","r");
    printf("addresa 1: f1 %d",fptr);
    char *game,*buffer,*players;
    game = malloc(sizeof(&fptr));
    players = malloc(sizeof(&fplayer));
    int i = 0;
    if(!fptr)return 1;
    
    printf("size of game: %lu",sizeof(&game));
    // TODO create load file fc;
    int player = 0;
    while(fgets(&buffer,sizeof(&fplayer),fplayer)!=NULL){
        players[player]= &buffer;
        player+=1;
        printf("player %c",players[player]);
    }
    printf("players : %s",players);
    
    printf("Read buffer %s\n",buffer);
    while(fgets(game,sizeof(&fptr),fptr)!=NULL){
        printf("%s%d",game,i);
        i++;
        if(i>=5000){
            return 1;
        }
    }
    printf("Game array content: %c",game[1]);
//       for(int x =m 0; x < 5; ++x) {
//      printf("%c\n", game[]);
//   }
    printf("size of game: %lu",sizeof(&game));
    // fprintf("");
        fclose(fplayer);
        fclose(fptr);
}


// int i;
// int** arr = malloc(sizeof(int*)*3);
// for(i=0;i<3;i++){
//     arr[i]=malloc(sizeof(int)*3);

// }
// arr[0][1];
// printf("%llu\n",sizeof(arr));
// fre(i=0;i<3;i++){
//     free(arr[i]);
//     arr[i]=NULL;
// }
// free(arr);
// arr = NULL;
// return 0;
