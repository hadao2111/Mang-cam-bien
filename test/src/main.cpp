#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    Serial.begin(9600);
    Serial.println(F("DHT11 test!"));

    dht.begin();
}

void loop()
{
    delay(2000);
    // Doc do am
    float h = dht.readHumidity();
    // Doc nhiet do duoi do C
    float t = dht.readTemperature();
    // Doc nhiet do duoi do F
    float f = dht.readTemperature(true);

    // Kiem tra xem co doc duoc khong
    if (isnan(h) || isnan(t) || isnan(f))
    {
        Serial.println(F("Không đọc được dữ liệu từ DHT11!"));
        return;
    }

    // Chi so nhiet theo do F
    float hif = dht.computeHeatIndex(f, h);
    // Chi so nhiet theo do C
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.print(F("Độ ẩm: "));
    Serial.print(h);
    Serial.print(F("%  Nhiệt độ: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  Chỉ số nhiệt: "));
    Serial.print(hic);
    Serial.print(F("°C "));
    Serial.print(hif);
    Serial.println(F("°F"));
}