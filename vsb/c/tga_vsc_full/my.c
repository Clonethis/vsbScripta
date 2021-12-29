#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"


int to_1d( const int row, const int col, const int cols ) {
    return col + row * cols;
}


typedef unsigned char byte;

typedef struct TGAHeader_ TGAHeader;

struct TGAHeader_ {
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
};

int tgaheader_width( const TGAHeader * self ) {
    int width = 0;

    memcpy( &width, self->width, 2 );

    return width;
}

int tgaheader_height( const TGAHeader * self ) {
    int height = 0;

    memcpy( &height, self->height, 2 );

    return height;

}

int tgaheader_channels( const TGAHeader * self ) {
    return self->depth / 8;
}
typedef struct TGA_ TGA;

struct TGA_ {
    TGAHeader header;
    byte * data;
};


TGA * tga_new( const int width, const int height, const int init_brightness ) {
    TGA * tga = (TGA *)malloc( sizeof( TGA) );
    ALLOCTEST( tga );

    memset( &tga->header, 0, sizeof( TGAHeader ) );

    tga->header.image_type = 3;
    tga->header.depth = 8;
    tga->header.descriptor = 1 << 5;

    memcpy( &tga->header.width, &width, 2 );
    memcpy( &tga->header.height, &height, 2 );

    tga->data = (byte *)malloc( width * height * sizeof( byte ) );
    memset( tga->data, init_brightness, width * height * sizeof( byte ) );

    return tga;
}

void tga_free( TGA ** self ) {
    free( (*self)->data );
    (*self)->data = NULL;
    free( (*self) );
    *self = NULL;
}

int tga_width( const TGA * self ) {
    return tgaheader_width( &self->header );
}

int tga_height( const TGA * self ) {
    return tgaheader_height( &self->header );
}

int tga_channels( const TGA * self ) {
    return tgaheader_channels( &self->header );
}

void tga_set_pixel( TGA * self, const int x, const int y, const byte b ) {
 self->data[ to_1d( y, x, tga_width( self ) ) ] = b;
}

void tga_write( const TGA * self, const char * filename ) {
    FILE * f = fopen( filename, "wb" );
    assert( f );

    fwrite( &self->header, sizeof( TGAHeader ), 1, f );

    int res = fwrite( self->data, sizeof( byte ), tga_width( self ) * tga_height( self ) * tga_channels( self ), f );
    assert( res == tga_width( self ) * tga_height( self ) * tga_channels( self ) );
    fclose( f );

}

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
    int color;
} Rect;

void draw_rect( TGA * tga, const Rect * r ) {
    int color = r->color;
    for ( int y = r->y1; y < r->y2; y++ ) {
        for ( int x = r->x1; x < r->x2; x++ ) {
            tga_set_pixel( tga, x, y, color );
        }
    }
}
void draw_number(Rect obdelnik, int number,int backgroundColor,int smallTextWidth, int largeTextWidth,TGA * tga){
    // pamatovat ze zmenit i tady
    // 
    int numberColor = 205;
obdelnik.color = backgroundColor;

    switch (number){
        case 0: 
            // obdelnik.color= backgroundColor;
            obdelnik.x1=obdelnik.x1+smallTextWidth;
            obdelnik.x2=obdelnik.x2-smallTextWidth;
            obdelnik.y1=obdelnik.y1+smallTextWidth;
            obdelnik.y2=obdelnik.y2-smallTextWidth;
            draw_rect(tga,&obdelnik);
            break;
        case 1:
            // obdelnik.color= backgroundColor;
            // obdelnik.x1=obdelnik.x1;
            obdelnik.x2=obdelnik.x2-smallTextWidth;
            // obdelnik.y1=obdelnik.y1-smallTextWidth;
            // obdelnik.y2=obdelnik.y2+smallTextWidth;
            draw_rect(tga,&obdelnik);
            break;

        case 2:
            obdelnik.x2 = obdelnik.x2-smallTextWidth;
            obdelnik.y1 = obdelnik.y1+smallTextWidth;
            obdelnik.y2 = obdelnik.y1 + largeTextWidth;
            draw_rect(tga,&obdelnik);

            obdelnik.x1 =obdelnik.x1+smallTextWidth;
            obdelnik.x2 = obdelnik.x2 +smallTextWidth;
            obdelnik.y1 = obdelnik.y1 + largeTextWidth+35;
            obdelnik.y2 = obdelnik.y2 + largeTextWidth+35;
            draw_rect(tga,&obdelnik);
            break;

        case 3:
            obdelnik.x2 = obdelnik.x2 - smallTextWidth;
            obdelnik.y1 = obdelnik.y1 + smallTextWidth;
            obdelnik.y2 = obdelnik.y1 + largeTextWidth;
            draw_rect(tga,&obdelnik);
            obdelnik.y1 = obdelnik.y1 + largeTextWidth+35;
            obdelnik.y2 = obdelnik.y2 + largeTextWidth+35;
            draw_rect(tga,&obdelnik);
            break;

        case 4:
            obdelnik.x1 = obdelnik.x1 + smallTextWidth;
            obdelnik.x2 = obdelnik.x2 -smallTextWidth;
            obdelnik.y2 = obdelnik.y1+ largeTextWidth+smallTextWidth;
            draw_rect(tga,&obdelnik);
            obdelnik.x1 = obdelnik.x1 - smallTextWidth;
            obdelnik.y1 = obdelnik.y1 + largeTextWidth+35+smallTextWidth;
            obdelnik.y2 = obdelnik.y2 + largeTextWidth+35+smallTextWidth;
            draw_rect(tga,&obdelnik);
            break;
        case 5:
            obdelnik.x1 = obdelnik.x1+smallTextWidth;
            obdelnik.y1 = obdelnik.y1+smallTextWidth;
            obdelnik.y2 = obdelnik.y1 + largeTextWidth;
            draw_rect(tga,&obdelnik);
            obdelnik.x1 =obdelnik.x1-smallTextWidth;
            obdelnik.x2 = obdelnik.x2 -smallTextWidth;
            obdelnik.y1 = obdelnik.y1 + largeTextWidth+35;
            obdelnik.y2 = obdelnik.y2 + largeTextWidth+35;
            draw_rect(tga,&obdelnik);
            break;
        case 6:
            obdelnik.x1 = obdelnik.x1 + smallTextWidth;
            obdelnik.y1 = obdelnik.y1+ smallTextWidth;
            obdelnik.y2 = obdelnik.y1 + largeTextWidth;
            draw_rect(tga,&obdelnik);
            obdelnik.y1 = obdelnik.y1 + largeTextWidth +35;
            obdelnik.y2 = obdelnik.y1 + largeTextWidth;
            obdelnik.x2 = obdelnik.x2 - smallTextWidth;
            // obdelnik.color = 130;
            // obdelnik.x1 = obdelnik.x1;
            // obdelnik.x2 = obdelnik.x2 - smallTextWidth;
            // obdelnik.y1 = obdelnik.y1 +35;
            // obdelnik.y2 + obdelnik.y1+ largeTextWidth;
            draw_rect(tga,&obdelnik);
            break;
        case 7:
         obdelnik.x2=obdelnik.x2-smallTextWidth;
         obdelnik.y1 = obdelnik.y1 +smallTextWidth;
         draw_rect(tga,&obdelnik);
        break;

        // notdone
        case 8:
        obdelnik.color = numberColor;
        // same as 0
        obdelnik.color= backgroundColor;
        obdelnik.x1=obdelnik.x1+smallTextWidth;
        obdelnik.x2=obdelnik.x2-smallTextWidth;
        obdelnik.y1=obdelnik.y1+smallTextWidth;
        obdelnik.y2=obdelnik.y1+largeTextWidth;
        draw_rect(tga,&obdelnik);
        obdelnik.y1= obdelnik.y1 + largeTextWidth+35;
        obdelnik.y2 = obdelnik.y1 + largeTextWidth;
        draw_rect(tga,&obdelnik);
        // obdelnik.color=numberColor;
        // obdelnik.y1 = obdelnik.y1+80;
        // obdelnik.y2 = obdelnik.y2-80;
        // draw_rect(tga,&obdelnik);
        // obdelnik.x1 = obdelnik.x1/2+smallTextWidth/2;
        // obdelnik.x2 = obdelnik.x2/2 +smallTextWidth/2;
        // obdelnik.y1 = (obdelnik.y1/2)-(smallTextWidth/2);
        // obdelnik.y2 = (obdelnik.y2/2) + (smallTextWidth/2);
        // draw_rect(tga,&obdelnik);
        break;

        // DONE
        case 9 :
        obdelnik.color=backgroundColor;
        obdelnik.x1 = obdelnik.x1+smallTextWidth;
        obdelnik.x2 = obdelnik.x2-smallTextWidth;
        obdelnik.y1 = obdelnik.y1+smallTextWidth;
        obdelnik.y2 = obdelnik.y1+largeTextWidth;

        // printf()
        draw_rect(tga,&obdelnik);
        obdelnik.color = backgroundColor;
        obdelnik.x1 = obdelnik.x1-smallTextWidth;
        obdelnik.y1 = obdelnik.y1+largeTextWidth*2-15;
        obdelnik.y2 = obdelnik.y2+largeTextWidth*2-15;
        draw_rect(tga,&obdelnik);
        break;
    }
}
void watch_draw_time(TGA *tga, int hours, int minutes){
     int width = 368;
    int height = 448;
    int rectWidth = width/2;
    int rectHeight = height/2;
    int padding = 15;
    int numberColor = 255;
    int backgroundColor = 0;
    int borderColor = 150;
    int smallTextWidth = 30;
    int largeTextWidth = 50;

     Rect background ={0,0,width,height,0};
        draw_rect(tga,&background);

        Rect lTop = {0+padding,0+padding,rectWidth-15,rectHeight-15,numberColor};
        Rect rTop = {rectWidth+padding,0+padding,width-padding,rectHeight-padding,numberColor};
        Rect lBottom = {padding,height/2+padding,rectWidth-padding,height-padding,numberColor};
        Rect rBottom = {width/2+padding,height/2+padding,width-padding,height-padding,numberColor};
        draw_rect(tga,&lTop);
        draw_rect(tga,&rTop);
        draw_rect(tga,&lBottom);
        draw_rect(tga,&rBottom);
        // checkTime(argv);
        // assert(rTop.x2 -rTop.x1 = rectWidth-2*padding?draw_rect(tga,&rTop));

        // draw_rect(tga,&lTop);
        // draw_rect(tga,&rTop);
        // r.color = backgroundColor;
        // r.x1= r.x1+largeTextWidth;
        // r.x2=r.x2-largeTextWidth;
        // r.y1= r.y1+largeTextWidth;
        // r.y2= r.y2-largeTextWidth;
        // draw_rect(tga,&r);
        if (hours<=24 && minutes<60&& hours>=0 && minutes>=0){        
            // int hour = ;
            draw_number(lTop,hours/10,backgroundColor,smallTextWidth,largeTextWidth,tga);
            draw_number(rTop,hours%10,backgroundColor,smallTextWidth,largeTextWidth,tga);
            draw_number(lBottom,minutes/10,backgroundColor,smallTextWidth,largeTextWidth,tga);
            draw_number(rBottom,minutes%10,backgroundColor,smallTextWidth,largeTextWidth,tga);
 
        }else{
            printf("zkus dat cislo v normalnim casovem rozmezi");
        }
        
}

int main(int argc, char *argv[]) {
    
    int hours = atoi(argv[1]);
    int minutes = atoi(argv[2]);

    TGA * tga = tga_new( 368, 448, 20 );

    watch_draw_time(tga,hours,minutes);
    tga_write( tga, "aw.tga" );
    tga_free( &tga );

    return 0;
}
