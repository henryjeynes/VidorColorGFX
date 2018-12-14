/*
  VidorColorGFX
  (C) 2018 Henry Jeynes
  
  This sketch basically just pukes colorful squares onto a screen.
  It's derived from VidorDrawLogo. RandomColor() and Color() are
  from Vidor_GFX.cpp.
  
  I tried setting the resolution to 1920x1080, but that didn't work.
  I also tried setting it lower with no luck. I don't even know if
  this is possible because of the abysmal documentation for the Vidor.
*/

#include "VidorGraphics.h"
#include "Vidor_GFX.h"

//these redefinitions don't work for me, let me know if they do for you
#ifdef VIDOR_WIDTH
#undef VIDOR_WIDTH
#define VIDOR_WIDTH 640
#endif

#ifdef VIDOR_HEIGHT
#undef VIDOR_HEIGHT
#define VIDOR_HEIGHT 360
#endif

Vidor_GFX  vdgfx;

void setup() {
  //move along, nothing to see here
}

void loop()
{
  /*
  *  Draw an Arduino logo
  */

  // Fill the screen with a white background
  vdgfx.fillRect(0,0,640,480,vdgfx.White());

  /**
  *  The library allows drawing some basic elements to the view, like circles, rectangles, lines
  */  

  vdgfx.fillCircle(225,225,100 ,vdgfx.lightBlue());
  vdgfx.fillCircle(415,225,100 ,vdgfx.lightBlue());
  vdgfx.fillCircle(225,225,90 ,vdgfx.White());
  vdgfx.fillCircle(415,225,90 ,vdgfx.White());
  vdgfx.fillRect(175,220,100,10 ,vdgfx.lightBlue());
  vdgfx.fillRect(365,220,100,10 ,vdgfx.lightBlue());
  vdgfx.fillRect(410,175,10,100 ,vdgfx.lightBlue());

  /**
  *  To draw a text we can use the classic functions like write() and print()
  *  Text size, color and position can be changed using the .text subclass
  */
  vdgfx.text.setCursor(150,375);
  vdgfx.text.setAlpha(255);
  vdgfx.text.setSize(3);
  vdgfx.text.setColor(vdgfx.lightBlue());
  vdgfx.println("ARDUINO");
  vdgfx.text.setCursor(480,145);
  vdgfx.text.setSize(1);
  vdgfx.println("TM");

  while (1) {
        vdgfx.fillRect(random(0, 640), random(0, 480), 10, 10, RandomColor());
        //delayMicroseconds(16667); //should limit to 60 FPS
  }
}

uint32_t RandomColor() {
  return Color(random(0, 255), random(0, 255), random(0, 255));
}

uint32_t Color(uint8_t r, uint8_t g, uint8_t b) {
  return ((((uint32_t)r) << 16) |
          (((uint32_t)g) <<  8) |
                     (b));
  //this is pure sorcery to me, I have no idea what's going on here
}