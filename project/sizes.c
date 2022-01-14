#include<stdio.h>

typedef struct game{
  unsigned int id;
  char blu[20];
  char red[20];
  // char starts
  char playersStatsBlu[40];
  char playersStatsRed[40];
}Game;

int main(){
    Game game;

    char i = 'd';
    char *aray = "nitec";
    // char *p = &i;
    unsigned int u = 1;
    int* x[] = {1,3,5};
    int A[] = {1,3,5};
    int* p = &x;
    // *p = 6;
    int** q = &p;
    int* z = A;
    // *game.blu = {"n","i","c","e"};
    printf("game sizeof: %c",*game.blu);
    printf("z: %d",*(A+1));
//     int*** z = &q;
//     printf("&q: %d\n",&q);
//     // printf("*x: %d\n",*x);
//     printf("z: %d\n",z);
//     printf("*z: %d\n",***z);
//     printf("&z: %d\n",&z);
// printf("%lu\n",sizeof(i));
// printf("ad i: %lu\n",&i);
// printf("*p: %lu\n",p);
// printf("sizeof p: %d\n",sizeof(p));
// printf("i: %c\n",i);
printf("pointer *p: %lu\n",*p);
printf("pointer p: %lu\n",p);
// printf("x[1]%d\n",*x[1]);
printf("array[1]%c\n",aray[1+1]);
// printf("x[1]%i\n",x[1]);
printf("*x%d\n",(*x+1));
printf("sizeof x: %d\n",sizeof(x));
// printf("pointer p+1: %lu\n",p+1);
for(int i= 0;i<=200;i++){
    printf("%d %c\n",i,i);
}
return 0;
}


