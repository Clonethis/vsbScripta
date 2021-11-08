#include <stdio.h>
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
//OR void print_sqr(int arr[], const int len)

    // could show to different value -> pointer interpreted as array, -> typical use... -> using array in 'functions' as pointer
 //OR  void print_sqr(int * arr, const int len)
//  len of array as pointer decrement by array len, -> it should return array
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
// could be written in number like '65' -> translates into ASCII
// todo learn dynamic allocated memory

    int arr[4]={0,1,2,3};
    // char c = 'A';
    // printf("%c\n",c);
    // checks sizes of array - only works for static array / DYNAMIC alloc, will throw errors
    printf("len arr : = %d \n", sizeof(arr)/sizeof(int));
    print_sqr(arr,4);
    int res=0;
    arr[2]=10;
    for (int i = 0 ; i<4;i++){
        // looking for addres of 'res' by '&'
        // sqr_void(i,&res);
        // printf("I: %d \t Sqrt: %d \n ",i, res);
        int res = sqr(arr[i]);
        printf("I: %d \t Sqrt: %d \n ",arr[i], res);
    }
    return 0;
}