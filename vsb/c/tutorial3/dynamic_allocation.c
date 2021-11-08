// We have stack 
//  - main 
// -- inside -> x, arr[0],arr[1]
//  stack should have by default 32 MB -> on Windows 8MB
//  trvalejsi data ukladat na 'heap' -> typicky jsou to pole 
//  'process' <- operacni system tomu prirazuje pamet
//  'heap' -> neni presne recenej, =~ 2MB+ -> muzeme alokovat dukud -> nam nedojde fyzicka pamet| 'virtualni pamet'
//  pri prekroceni alokovane pameti-> Core dump->vse co v procesu je a je v pameti, se hazela do filu -> Sick segmentation fault 
//  page: 4kB 
// Trial: zkusit obnovit mrtvy proces zkrze debugger 
//  debugging -> DTrace
// malloc.h vraci pointer na void -> musime udelat typecasting 
//  if created with -> -g -fsanitize=adress ->error  leakSanitizer -> 
// 
// functional calling of malloc -> with lib c -> we can in run-time that: 'malloc'-from lib.c could lead to some 'interceptor_malloc' -> now it behaves diferrently -> malloc typically returns 0 bytes of memory -> in this class
// -reaction on not having enought memory for program
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
int main(){
    // delka arraye
    const int len=4;
    // tento pointer nikam neukazuje
    // when we have allocated memory - 'ask' -> if there is enough memory
    
    int * arr = arr_alloc(len);
    
    // in free putting only pointer 
    
    free (arr);
    
    // best practice
    arr = NULL;
    
    return 0;
}
