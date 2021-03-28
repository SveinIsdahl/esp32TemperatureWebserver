#include "main.h"

const char *ssid = "ESP-32";


void mainTask(void *param)
{
    while (1)
    {
        /*
        digitalWrite(outPin, LOW);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        digitalWrite(33, HIGH);
        */
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void setup()
{
    Serial.begin(9600);
    xTaskCreatePinnedToCore(wifiTask, "wifiTask", 50240, &ssid, 3, NULL, 0);
    xTaskCreatePinnedToCore(mainTask, "mainTask", 2024, NULL, 1, NULL, 1);
    pinMode(outPin, OUTPUT);
    pinMode(tempPin, INPUT);
}

void loop()
{
}
