#include <Wire.h>
#include <math.h>

float k1=.5;
float k2=55;
float k3=.00001;

int milliOld;
int milliNew;
float dt;

float yawTarget=0;
float yawActual;
float yawError=0;
float yawErrorOld;
float yawErrorChange;
float yawErrorSlope=0;
float yawErrorArea=0;

void setup() {
Serial.begin(115200);
delay(1000);
milliNew=millis();
}

void loop() {
 
}
float PID_CONTROL(float yawActual, float yawTarget)
{
milliOld=milliNew;
milliNew=millis();
dt=(milliNew-milliOld)/1000.0;
yawErrorOld=yawError;
yawError=yawTarget-yawActual;
yawErrorChange=yawError-yawErrorOld;
yawErrorSlope=yawErrorChange/dt;
yawErrorArea=yawErrorArea+yawError*dt;

correction=k1*yawError+k2*yawErrorSlope+k3*yawErrorArea;

return correction;
}
