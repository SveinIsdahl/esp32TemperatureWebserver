#include "main.h"

double analogReadToDegrees(int reading)
{
    //analogRead (0-4095) til spenning
    double u = reading * 0.0008 + 0.1372;

    //Fra spenning til motstand i thermistor (kiloohm)
    //3.93k = konstant motstand
    //3.3 = votlage spenning over konstantmotstand + thermistor
    double res = (u * 3.93) / (3.3 - u);
    Serial.println(u);
    Serial.println(res);
    //Unkjent thermistor så funksjon for å finne grader er fra eksprimentell data
    //ble utført ved regresjon med verdier rundt 50 grader, derfor bare nøyaktig rundt 50 grader
    //Prøvde også å bruke steinharts formel, men resulttene ble dårligere enn de jeg fant selv
    //Skal bare brukes mellom 40 og 60 grader, ikke viktig med nøyaktighet ved andre områder
    double deg = 93.0664 * pow(0.85895, res);

    return (deg);
}