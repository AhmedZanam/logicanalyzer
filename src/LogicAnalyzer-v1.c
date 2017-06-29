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


static volatile int globalCounter;
static volatile int counter;

void myInterrupt (void) {
    ++globalCounter;
}

int main(int argc, char *argv[])
{
    int data[410];
    wiringPiSetupGpio();
    int ret = 0;
    //int counter = 0;
    pinMode(INPUT_GPIO, INPUT);
    
    wiringPiISR (INPUT_GPIO, INT_EDGE_BOTH, &myInterrupt);
    while(1){
        ret = waitForInterrupt (INPUT_GPIO, 20000);
        
        if(ret > 0){
            ++counter;
            data[counter] = digitalRead(INPUT_GPIO);
            //printf("ret: %d counter: %d globalCounter: %d Bit: %d\n", ret, counter, globalCounter, digitalRead(INPUT_GPIO));
            if(counter == 410)
            {
                for(int i = 0; i < 410; ++i){
                    printf("%d", data[i]);
                }
                break;
            }
        }
        
    }
    
/*
    while(ret == 0)
    {
        printf("Counter: %5d Bit: %d\n", globalCounter,digitalRead(INPUT_GPIO));
        //for(int i = 0; i < sizeof(bits); i++)
        //{
            //bits[i] = digitalRead(pin);
        //}
        //delay(200); 
    }
*/
    return EXIT_SUCCESS;
}

