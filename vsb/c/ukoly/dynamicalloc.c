#include <stdio.h>   
#include <stdlib.h> 

int main(){
    int number,thing;
    scanf("%d",&number);
    int *allocated =malloc(number*sizeof(int));
    for (int i =0;i<number;i++){
        scanf("%d",&thing);
        allocated[i]=thing;

    }
    for (int i=0;i<number;i++){
     if(allocated[i]%2==0){
        printf("%d even\n",allocated[i]);
     }else{

        printf("%d odd\n",allocated[i]);
     }
    }
    
    free(allocated);
}