#include <stdio.h>
#include<stdlib.h>
void arr_zero(int * arr, const int len){
    for(int i = 0 ; i<len;i++){
        *(arr+i)=0;
    }
}
int * arr_alloc(const int len){
    int * arr = NULL;
    arr = (int *)malloc(len*sizeof(arr[0]));
if(!arr){
        fprintf(stderr,"Out of memory!\n");
        exit(-1);
    }
    // how much elements * bytes -> also typecasting pointer to integer... what?? something like overtyping stuff
}
int string_len(const char * str)
{

    int len =0;
    while( *(str + len)!= '\0'){
        len ++;
    }
    return len;
}
int main(){
    // delka arraye
    const int len=4;
    char str [80]='UPL';
    printf("%s len = %d",str,string_len(str));
    
    return 0;
}
