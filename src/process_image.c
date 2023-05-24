#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    return im.data[c*im.w*im.h + y*im.w + x];
}

void set_pixel(image im, int x, int y, int c, float v)
{
    // TODO Fill this in
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    for (int i = 0 ; i < im.c ; i++){
        for ( int j = 0 ; j < im.h ; j++){
            for ( int k = 0 ; k < im.w ; k++){
                set_pixel( copy , k , j , i , get_pixel( im , k , j , i));
            }
        }
    }

    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    for ( int i = 0 ; i < im.h ; i++){
        for ( int j = 0 ; j < im.w ; j++){
            set_pixel( gray , j , i , 0 ) = get_pixel( im , j , i , 0)*0.299 + get_pixel( im , j , i , 1)*0.587 + get_pixel( im , j , i , 2)*0.114 ;  ;
        }
    }
    return gray;
}

void shift_image(image im, int c, float v)
{
    for ( int i = 0 ; i < im.h ; i++){
        for ( int j = 0 ; j < im.w ; j++){
            set_pixel( im , j , i , c , get_pixel( im , j , i , c) + v) ;
        }
    }
}

void clamp_image(image im)
{
    for ( int i  = 0 ; i < im.c ; i++){
        for( int j = 0 ; j < im.h ; j++){
            for ( int k = 0 ; k < im.w ; k++){
                if (get_pixel( im , k , j , i) > 1) {
                    set_pixel( im , k , j , i , 1) ;
                }
                else if ( get_pixel( im , k , j , i) < 0 ) {
                    set_pixel( im , k , j , i , 0 ) ;   
                }
            }
        }
    }

    save_image( im , "fixed" ) ;
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
