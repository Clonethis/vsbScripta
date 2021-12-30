#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    fptr = fopen("f1.txt", "r");
    char *game;
    game = malloc(sizeof(&fptr));
    if(!fptr){
        return 1;
    }
    int i = 0;
    printf("size of game: %lu",sizeof(&game));
    while(fgets(game,sizeof(&fptr),fptr)!=NULL){
        printf("%s%d",game,i);
        i++;
        if(i>=5000){
            return 1;
        }
    }
    printf("Game array content: %c",game[1]);
//       for(int x = 0; x < 5; ++x) {
//      printf("%c\n", game[]);
//   }
    printf("size of game: %lu",sizeof(&game));
    // fprintf("");
        fclose(fptr);
}