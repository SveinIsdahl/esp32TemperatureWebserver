#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <math.h>

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"

#include "html.h"

#define outPin 33
#define tempPin 35

void wifiTask(void *ssidPointer);
double analogReadToDegrees(int reading);

extern int globalTargetTemp;
