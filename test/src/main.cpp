#include <Arduino.h>  
#include <DHT.h>  

#define DHTPIN 4          
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);  

void setup() {  
    Serial.begin(9600);   
    dht.begin();            
}  

void loop() {  
    delay(2000); 

    float temperature = dht.readTemperature();  
    if (isnan(temperature)) {  
        Serial.println("Lỗi đọc nhiệt độ!");  
        return;  
    }  

    float humidity = dht.readHumidity();  
    if (isnan(humidity)) {  
        Serial.println("Lỗi!");  
        return;  
    }  
    Serial.print("Nhiệt độ: ");  
    Serial.print(temperature);  
    Serial.print(" °C, Độ ẩm: ");  
    Serial.print(humidity);  
    Serial.println(" %");  

}