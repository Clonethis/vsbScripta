// zapis do file
#include <stdio.h>
#include <assert.h>

int main() {
    int pole[5] = { 1, 2, 3, 4, 5 };

    // otevření souboru
    FILE* soubor = fopen("soubor", "wb");
    assert(soubor);

    // binární zápis do souboru
    int zapsano = fwrite(pole, sizeof(int), 5, soubor);
    assert(zapsano == 5);

    // zavření souboru
    fclose(soubor);    

    return 0;
}
