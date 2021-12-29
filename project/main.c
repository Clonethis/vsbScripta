#include <stdio.h>
#include <stdlib.h>

int main(char *argv)
{
    FILE *fptr;
    fptr = fopen("f1.txt", "r");
    fprintf(fptr);
    fclose(fptr);
}