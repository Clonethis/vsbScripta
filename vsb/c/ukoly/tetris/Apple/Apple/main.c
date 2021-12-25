#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
typedef unsigned char byte;
typedef struct {
    byte id_length;
    byte color_map_type;
    byte image_type;
    byte color_map[5];
    byte x_origin[2];
    byte y_origin[2];
    byte width[2];
    byte height[2];
    byte depth;
    byte descriptor;
} TGAHeader;
typedef struct {
    byte blue;
    byte green;
    byte red;
} Pixel;

Pixel* load_pixels(TGAHeader header, FILE* file) {
    int width = 0;
    int height = 0;
    
    memcpy(&width, header.width, 2);
    memcpy(&height, header.height, 2);

    Pixel* pixels = (Pixel*) malloc(sizeof(Pixel) * width * height);
    assert(fread(pixels, sizeof(Pixel) * width * height, 1, file) == 1);
    return pixels;
}
int main(){
    FILE* file = fopen("./nice.tga", "rb");
    if (file==NULL){
        
        printf("Some bullshit");
        return 1 ;
    }
//    assert(file);
    Pixel *pixels;

    TGAHeader header ={};
    // assert(fread(header, sizeof(TGAHeader), 1, file) == 1);

    int width = 0;
    int height = 0;
    pixels = load_pixels(header,file);
    printf("Image type: %d, pixel depth: %d\n", header.image_type, header.depth);

    memcpy(&width, header.width, 2);
    memcpy(&height, header.height, 2);
}
