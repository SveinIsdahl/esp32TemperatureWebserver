#include "main.h"

double analogReadToDegrees(int reading)
{
    //analogRead (0-4095) til spenning
    double u = reading * 0.0008 + 0.1372;

    //Fra spenning til grader
    double deg = -38.52499*u + 114.41527;
    

    return (deg);
}