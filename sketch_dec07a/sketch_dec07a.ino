
// Pin Variables
int ledOut = 8;
int tempIn = 0;
int lightIn = 1;

// Control Variables
float minMoist = 0.5;
float mintemp = 30.0;
float minHumidity = 0.6;
float lightsOnTime = "HH:MM:SS";


void checkLux(){
	// get lux value (depends on used resistance)
	float lightval = analogRead(lightIn);
	Serial.print(lightval); Serial.println(" Lux");
}

void activatePump(bool b){
	if(b){
		// turn pump on
	}

	else{
		// turn pump off
	}

}

void checkHumidity(){

	float humidty;
	if(humidity<minHumidity){
		Serial.print("Humidity is low");
	}
	// Implement
}

void checkMoist(){

	int moist; // = sensor.getMoist()
	if (moist < minMoist){
		activatePump(true);
	}
	else{
		activatePump(false);
	}
}

void checkTemp(){

	//getting the voltage reading from the temperature sensor
	int reading = analogRead(tempIn);

	// converting that reading to voltage, for 3.3v arduino use 3.3
	// also more accurate conversion than using 5v
	float voltage = reading * 5.0;
	voltage /= 1024.0;

	// print out the voltage
	Serial.print(voltage); Serial.println(" volts");

	// now print out the temperature
	float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
	//to degrees ((voltage - 500mV) times 100)
	Serial.print(temperatureC); Serial.println(" degrees C");

	// now convert to Fahrenheit
	//float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
	//Serial.print(temperatureF); Serial.println(" degrees F");
}

void setup(){
	Serial.begin(9600);
	pinMode(tempIn, INPUT);
	pinMode(ledOut, OUTPUT);
	pinMode(lightIn, INPUT);
}

void loop(){

	// Blink led
	digitalWrite(ledOut, HIGH);
	delay(1000);
	digitalWrite(ledOut, LOW);
	delay(1000);

	checkTemp();
	checkLux();

	//checkMoist();
	//checkHumidity();


}
