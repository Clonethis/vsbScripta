#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    fptr = fopen("matchData.txt", "r");
    char *game;
    game = malloc(sizeof(&fptr));
    int i = 0;
    if(!fptr)return 1;
    
    // printf("size of game: %lu",sizeof(&game));
    // TODO create load file fc;
    // while(fgets(game,sizeof(&fptr),fptr)!=NULL){
    //     printf("%s%d",game,i);
    //     i++;
    //     if(i>=5000){
    //         return 1;
    //     }
    // }
    printf("Game array content: %c",game[1]);
//       for(int x = 0; x < 5; ++x) {
//      printf("%c\n", game[]);
//   }
    printf("size of game: %lu",sizeof(&game));
    // fprintf("");
        fclose(fptr);
}