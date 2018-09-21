/*
 * Arduino Current Monitoring
 * with INA219 Module
 *
 * 
 * by Niyas Thalappil
 * 
 * www.youtube.com/c/NiyasThalappil
 * NiyazThalappil@gmail.com
 *
 */


#include <Wire.h>                                   // Include the Wire lib as we are using I2C
#include <INA219.h>                                 // We need the INA219 lib to use the sensor
#include <Adafruit_GFX.h>                           // grafix lib for the OLED
#include <Adafruit_SSD1306.h>                       // I2C OLED lib
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);               //OLED lib call
INA219 monitor;                                     //INA219 lib call


void setup()
{
 
   monitor.begin();                               
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);      
   display.display();                               
   display.clearDisplay();                         
}

void loop()
{

  display.setTextSize(1);                          
  display.setTextColor(WHITE);                    
  display.setCursor(0,0);                          

  display.print("shunt current: ");                
  display.setCursor(0,10);                          
  display.print(monitor.shuntCurrent() * 1000, 4);  
  display.setCursor(47,10);                         
  display.println(" mA");                           
  display.display();                              
  delay(1000);                                     
  display.clearDisplay();                           
}


