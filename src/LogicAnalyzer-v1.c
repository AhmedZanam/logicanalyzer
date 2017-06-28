#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#include <sys/time.h>
#include <stdlib.h>

/*
#define CHANNEL1 1
#define CHANNEL2 2
#define CHANNEL3 3
#define CHANNEL4 4
#define CHANNEL5 5
#define CHANNEL5 6
#define CHANNEL5 7
#define CHANNEL5 8
*/
#define INPUT_GPIO 4
//#define CYCLES 1000

int main()
{
    int bits[1000];
    wiringPiSetupGpio();
    
    pinMode(INPUT_GPIO, INPUT);//
    while(1)
    {
        //for(int i = 0; i < sizeof(bits); i++)
        //{
            //bits[i] = digitalRead(pin);
        //}
        //delay(200);
        printf("%d", digitalRead(INPUT_GPIO));
        
    }
    return EXIT_SUCCESS;
}

