// -----------------------------------
// Example - 01: Singing A Song
// -----------------------------------
#include "application.h"

// name the pins
#define BUTTONPIN D2
#define BUZZERPIN D4

void play_music1() {
    int melody[] = {1908, 2551, 2551, 2273, 2551, 0, 2024, 1908};
    int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

    for (int i = 0; i < 8; i++) {
        int noteDuration = 1000 / noteDurations[i];
        tone(BUZZERPIN, melody[i], noteDuration);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(BUZZERPIN);
    }
}

void play_music2() {
    int melody[] = {1908, 2024, 0, 2551, 2273, 2551, 2551, 1908};
    int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

    for (int i = 0; i < 8; i++) {
        int noteDuration = 1000 / noteDurations[i];
        tone(BUZZERPIN, melody[i], noteDuration);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(BUZZERPIN);
    }
}

bool play_1 = true;

// This routine runs only once upon reset
void setup() {
    pinMode(BUTTONPIN, INPUT);
    pinMode(BUZZERPIN, OUTPUT);
}

// This routine loops forever
void loop() {
    if (digitalRead(BUTTONPIN) == 1) {
        if (play_1) {
            play_music1();
        }
        else {
            play_music2();
        }
        play_1 = !play_1;
    }
}
