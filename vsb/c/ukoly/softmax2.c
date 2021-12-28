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
float *softmax(const float *array, const int len)
{
    printf("array: %f", &array);
    printf("array: %f", *array);
    printf("array: %f", array);
    printf("len : %d", len);
    float *softmaxArray = (float *)malloc(len);
    float sum = 0, result, e_zi;
    for (int i = 0; i < len / 10 / sizeof(float); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // printf("array char: %lf\n",*(array +j+i*10));
            // printf("power funct; %f\n",pow(M_E,*(array+i*10 +j)));
            sum += pow(M_E, *(array + i * 10 + j));
        }
        for (int k = 0; k < 10; k++)
        {
            result = 0;
            result = (pow(M_E, *(array + i * 10 + k))) / sum;
            *(softmaxArray + i * 10 + k) = result;
        }
    }

    printf("sum: %f\n", &sum);
    // free(softmaxArray);
    return softmaxArray;
}

// int argmax( const float * array, const int len ){

//     return
// };
int main()
{
    float *p;
    int cols = 10, rows;
    scanf("%d", &rows);
    // tip https://tutorialspoint.dev/language/c/dynamically-allocate-2d-array-c
    // p = (float*) malloc(sizeof(float)*cols*rows);
    // float (*A)[cols] = malloc(sizeof(float[rows][cols]));

    float *floatArray = (float *)malloc(rows * cols * sizeof(float));
    float value;

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {
            scanf("%f", &value);
            *(floatArray + i * rows + j) = value;
        }
    }

    // printf("type of floatArray,%d",floatArray);
    // printf("&floatarray %f",*(floatArray+x*r + y));

    float *softmaxCalculated = softmax(floatArray, rows * cols * sizeof(float));

    // float *argmaxCalculated = argmax(softmaxCalculated,rows*cols*sizeof(float));
    printf("pointer p: %d\n", &p);

    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            // printf("print elements [%d][%d], value: %f\n",x,y,floatArray[x][y]);
            printf("*floatarray %lf\n", *(floatArray + x * rows + y));
        }
    }
    // malloc(x);
    // int *pole = (int*) malloc(rows*sizeof(int));
    printf("softmaxCalc: %f \n", (softmaxCalculated + 1 * rows));
    printf("softmaxCalc&:%f\n", &softmaxCalculated + 6);
    printf("softmaxCalc*:%f\n", *softmaxCalculated);
    free(softmaxCalculated);
    free(floatArray);
}
