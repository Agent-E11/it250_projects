// --- Requirements ---
// Use 3rd party integrations such that:
// 1. Device effects 3rd party
// 2. 3rd party effects device
//
// --- My plan ---
// Requirement 1:
// Have a button, that when pressed, will log the current time to a Google spreadsheet
// - Resource: https://docs.particle.io/integrations/community-integrations/publish-to-google-sheets/
// - Resource: https://community.particle.io/t/pushing-data-to-google-sheets-new-thread/60138
//
// Requirement 2:
// When someone opens the Google sheet, play a tone
// - Resource: https://community.particle.io/t/webhooks-tutorial-get-your-unread-gmail-count/10565/2
// - Resource: https://script.google.com/home/projects/1Y2wUrpTTZAFV7UcSsCl9bKP0a_Kv6prmIXgZqQdSohKj3-95AUrqwoPM/edit?pli=1

#include "Particle.h"

SYSTEM_THREAD(ENABLED);

SerialLogHandler log_handler;

// How often to publish a value
const std::chrono::milliseconds publish_period = 500ms;

// The event name to publish with
const char *event_name = "it250_tpi";

const int button = D2;
const int buzzer = D4;

unsigned long last_publish;
int counter = 0;

void publish_test();

int sheet_opened(String);

void setup() {
    pinMode(button, INPUT);
    pinMode(buzzer, OUTPUT);
    Particle.function("sheet_opened", sheet_opened);
}

bool pressed = false;
void loop() {
    if (digitalRead(button)) {
        if (millis() - last_publish >= publish_period.count()) {
            publish_test();
            tone(buzzer, 1908, 100);
            last_publish = millis();
        }
    }
}

void publish_test() {
    char buf[128];

    snprintf(buf, sizeof(buf), "[%d]", ++counter);

    Particle.publish(event_name, buf, PRIVATE);
    Log.info("published: %s", buf);
}

int sheet_opened(String arg) {
    Particle.publish("it250_sheet_opened", "["+arg+"]", PRIVATE);
    tone(buzzer, 1908, 100);
    return 0;
}
