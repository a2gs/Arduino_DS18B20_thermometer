#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setup(void)
{
	sensors.begin();  // Start up the library
	Serial.begin(9600);
}

void loop(void)
{ 
	sensors.requestTemperatures(); 

	Serial.print("Temperature: ");
	Serial.print(sensors.getTempCByIndex(0));
	Serial.println("C");

	delay(200);
}