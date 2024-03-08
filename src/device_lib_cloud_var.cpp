// Install libraries (For VSCode):
// Open command pallette
// >Particle: Install Library
// Type GROVE-ULTRASONIC-RANGER
// 
// Open command pallette
// >Particle: Install Library
// Type GROVE_4DIGIT_DISPLAY
//
// Tip: To search for libraries, go to the "Libraries" tab in the Web IDE
#include "application.h"

// #include "Grove_4Digit_Display.h"
// #define CLK D2 // pins definitions for TM1637 and can be changed to other ports
// #define DIO D3
// TM1637 tm1637(CLK, DIO);
// void setup()
// {
//     tm1637.init();
//     tm1637.set(BRIGHT_TYPICAL); // BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
//     tm1637.point(POINT_ON);
// }

// void loop()
// {
//     int8_t NumTab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; // 0~9,A,b,C,d,E,F
//     int8_t ListDisp[4];
//     unsigned char i = 0;
//     unsigned char count = 0;
//     delay(150);

//     while (1)
//     {
//         i = count;
//         count++;
//         if (count == sizeof(NumTab))
//             count = 0;
//         for (unsigned char BitSelect = 0; BitSelect < 4; BitSelect++)
//         {
//             ListDisp[BitSelect] = NumTab[i];
//             i++;
//             if (i == sizeof(NumTab))
//                 i = 0;
//         }
//         tm1637.display(0, ListDisp[0]);
//         tm1637.display(1, ListDisp[1]);
//         tm1637.display(2, ListDisp[2]);
//         tm1637.display(3, ListDisp[3]);
//         delay(1000);
//     }
// }

void setup() {

}

#define LED D7
void loop() {
    tone(D2, 2000, 0.0);

    digitalWrite(LED, 0);
    delay(1000);
    digitalWrite(LED, 1);
    delay(1000);
}
