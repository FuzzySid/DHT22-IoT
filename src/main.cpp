#include "DHT.h" //included the DHT file

//#define DHTPIN 4 or whatever pin you're using
#define DHTPIN 4 // IMPORTANT D2 ON NODE MCU IS GPIO 


//#define DHTTYPE DHT22
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);    //instance of DHT

void setup() {
    Serial.begin(115200); //Baud Rate
    dht.begin();
}

void loop() {
    delay(2000);
    float humidity = dht.readHumidity(); //Read Humidity values and store it in a variable
    float temp = dht.readTemperature(); //Read Temperatre value in Celcius and store it in a variable
    float temperature = dht.readTemperature(true); //true if temperature value is in farenheit
    
    if( isnan(humidity)| isnan(temp)| isnan(temperature))   //Check if the variables are storing the values
    {
        Serial.println("Failed to read values from the sensor");
        return;
    }

    //compute heat index in farenheit
    float hif = dht.computeHeatIndex(temperature,humidity);

    //compute heat index in celcius
    float hic = dht.computeHeatIndex(temp, humidity, false);

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %t");
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print(" *C ");
    Serial.print(temperature);
    Serial.print(" *F\t");
    Serial.print("Heat index: ");
    Serial.print(hic);
    Serial.print(" *C ");
    Serial.print(hif);
    Serial.println(" *F");


}