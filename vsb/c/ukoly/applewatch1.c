#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned char byte;

typedef struct {
    byte id_length;
    byte color_map_type;
    byte image_type;
    byte color_map[5];
    byte x_origin[2];
    byte y_origin[2];
    unsigned short width;
    unsigned short height;
    byte depth;
    byte descriptor;
} TGAHeader;

typedef struct {
    byte blue;
    byte green;
    byte red;
} Pixel;

// void watch_draw_time(TGAImage *self, const int hours, const int minutes);

// void watch_draw_time_color(
//     TGAImage *self,
//     const int hours,
//     const int minutes,
//     const RGBA *fg_color,
//     const RGBA *bg_color);

int main()
{
    FILE* out = fopen("test.tga", "wb");
    assert(out);

    TGAHeader header = {};
    header.image_type = 2;
    header.depth = 24;
    header.width = 368;
    header.height = 448;
    assert(fwrite(&header, sizeof(TGAHeader), 1, out) == 1);

    Pixel array[448][368];
    Pixel white;
    white.blue=255;
    white.red=255;
    white.green=255;
    for (int r = 0; r < 448; r++)
        for (int c = 0; c < 368; c++){

            assert(fwrite(&array[r][c]= white, sizeof(Pixel), 1, out) == 1);
            // array[r][c] = white;
            // fwrite(array,sizeof(Pixel),header.width*header.height,out);
            // printf("%c : ", array[r][c]);
        }
        // fwrite(array,out);
    fclose(out);




    return 0;
}