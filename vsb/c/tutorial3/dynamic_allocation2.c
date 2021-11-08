#include <stdio.h>
#include<stdlib.h>
int sqr(int a){
    int res = a*a;
    return res;
}
void sqr_void(int a, int *res){
    // to derefer need '*res'
    *res = a*a;
    // Todo learn pointy
    // zasobnik, fronta, call stack
}
void print_sqr(int arr[], const int len){
    printf("hack = %d \n",*(&arr-3));
    for (int i = 0 ; i<len;i++){
        int res = sqr(arr[i]);
        printf("%d %d \n",arr[i],res);
    }
}
void swap(int *a , int * b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(){
    // delka arraye
    const int len=4;
    // tento pointer nikam neukazuje
    int * arr = NULL;

    // how much elements * bytes -> also typecasting pointer to integer... what?? something like overtyping stuff
    arr = (int *)malloc(len*sizeof(arr[0]));
    int arr[2]={10};
    arr[2]=10;
    for (int i = 0 ; i<4;i++){

        int res = sqr(arr[i]);
        printf("I: %d \t Sqrt: %d \n ",arr[i], res);
    }
    return 0;
}
