#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Co naprogramovat

// Výsledný program bude postupovat následovně:

//    todo Načte z stdin číslo, které udává počet vektorů, které se bude následně zpracovávat. Každý vektor má dimenzi 10 (10 prvků ve vektoru). K dispozici je text o vstupu a výstupu. Stačí je pak načítat pomocí funkce scanf. Jednotlivé elementy načítejte pomocí cyklu.
//    todo Načtěte každý vektor do dynamicky alokovaného pole.
//     todo Toto pole pošlete do funkce softmax.
//     todo Výslední pole z funkce softmax spošlete do funkce argmax.
//     todo Výsledek funkce argmarowszapište na standardní výstup (stdout). Za něj pak zapište výsledek z funkce softmax. Každý výsledek bude na samostatném řádku a jednotlivá čísla budou oddělena mezerou. Desetinná čísla zapište s přesností na 4 desetinná čísla.

// Příklad výstupu pro náš demonstrační vstup (plný příklad naleznete v záložce Tests):
// todo implementation of 'softmax' function
float* softmax( const float* array, const int len ){
    printf("array: %f",&array);
    printf("len : %d",len);
    float *p;
return p;
}
// // todo argmax
// int argmax( const float * array, const int len );
int main() {
    float *p;   
    int cols=10,rows;
    scanf("%d",&rows);

    // p = (float*) malloc(sizeof(float)*cols*rows);
    // float (*A)[cols] = malloc(sizeof(float[rows][cols]));
    float *floatArray = (int*)malloc(rows*sizeof(int));
    p = floatArray;

    for(int i =0;i<rows;i++){
        floatArray[i]=(float*)malloc(cols*sizeof(float)) ;
        for(int j = 0; j<cols;j++){
            scanf("%f",&floatArray[i][j]);
        }
    }
    
    // printf("type of floatArray,%d",floatArray);
    printf("&floatarray %lf",floatArray[1][2]);
    printf("*floatarray %lf",floatArray[1][2]);
    p =softmax(p, cols*rows*sizeof(float));
    printf("pointer p: %d\n",p);
    
    for(int x =0;x<rows;x++){
        for(int y = 0; y<cols;y++){
            printf("print elements [%d][%d], value: %f\n",x,y,floatArray[x][y]);
        }
    }
    // malloc(x);
    // int *pole = (int*) malloc(rows*sizeof(int));
    
    free(floatArray);
    
}
