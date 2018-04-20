#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include "Touchberry.h"
#include "Thumper_REST_Request.h"

using namespace touchberry;
using namespace thumper_rest_request;

int main(void) {
    int intensity = 120;
    int R = 10;
    int G = 200;
    int B = 10;
    Touchberry touchberry;
    Thumper_REST_Request thumper;

    thumper.set_rgb_color_leds(30,200,20);

    for(int i = 0;i<5;i++){
          touchberry.set_led_color(R,G,B);
         }
        while(true){
        std::cout<<touchberry.read_buttons()<<std::endl;
        if(touchberry.read_buttons()=="X"){
          if(intensity > 245){
            intensity = 10;
          }else{
            intensity = intensity + 10;
          }
        usleep(500000);
        }
        if(touchberry.read_buttons()=="B"){
          if(intensity < 10){
            intensity = 250;
          }else{
            intensity = intensity - 10;
          }
        usleep(500000);
        }
        if(touchberry.read_buttons()=="left"){
          thumper.set_motor_drive(-100,100);
          if(R > 245){
            R = 10;
          }else{
            R = R + 10;
          }
        usleep(500000);
        }
        if(touchberry.read_buttons()=="up"){
          thumper.set_motor_drive(200,200);
          if(G > 245){
            G = 10;
          }else{
            G = G + 10;
          }
        usleep(500000);
        }
        if(touchberry.read_buttons()=="right"){
          thumper.set_motor_drive(100,-100);
          if(B > 245){
            B = 10;
          }else{
            B = B + 10;
          }
        usleep(500000);
        }
        if(touchberry.read_buttons()=="down"){
          thumper.set_motor_drive(-200,-200);
          usleep(500000);
        }
        if(touchberry.read_buttons()=="A"){
          touchberry.set_led_color(R,G,B);
          usleep(500000);
        }
        touchberry.set_led_intensity(intensity);
    }
  return 0;
}
