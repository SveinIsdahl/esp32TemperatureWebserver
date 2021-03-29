#include "main.h"

double analogReadToDegrees(int reading)
{
    //analogRead (0-4095) til spenning
    double u = reading * 0.0008 + 0.1372;

    //Fra spenning til grader
    //Ukjent termistor, steinharts formel gave dårlige resultater
    //Brukte heller lineær regresjon mellom 37 og 65 grader med ca 30 målinger og fant funksjon
    double deg = -38.52499*u + 114.41527;
    

    return (deg);
}