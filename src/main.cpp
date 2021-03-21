#include "main.h"


const char *ssid = "ESP-32";


void mainTask(void* param) {
    while (1) {
        digitalWrite(2, HIGH);
        digitalWrite(33, LOW);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        digitalWrite(2, LOW);
        digitalWrite(33, HIGH);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void setup() {
    Serial.begin(9600);
    xTaskCreatePinnedToCore(wifiTask, "wifiTask", 30240, &ssid, 3, NULL, 0);
    xTaskCreatePinnedToCore(mainTask, "mainTask", 1024, NULL, 1, NULL, 1);
    pinMode(2, OUTPUT);
    pinMode(33, OUTPUT);

    // put your setup code here, to run once:
}

void loop() {
    // put your main code here, to run repeatedly:
}