#include <LiquidCrystal.h>
#include <dht_nonblocking.h>
#include <math.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11

const int water_pin = A4;
const int light_pin = A3;
const int therm_pin = A2;

const int buzzer_pin = 5;
const int led_pin = 2;
const int dht11_pin = 3;
const int button_pin = 4;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DHT_nonblocking dht_sensor(dht11_pin, DHT_SENSOR_TYPE);

int minim_water = 30;
bool water = false;
int waterValue = 0;

float humidityValue = 0;

unsigned long timerHum = 0;
unsigned long timerWater = 0;
unsigned long timerLCD = 0;

const unsigned long intervalHum = 2000;
const unsigned long intervalWater = 100;
const unsigned long intervalLCD = 500;

int nr_page = 0;
int last_state = HIGH;

int read_light()
{
    return analogRead(light_pin);
}

float read_temperature()
{
    int raw = analogRead(therm_pin);
    if(raw == 0) raw = 1;

    float resistance = 10000.0 * (1023.0 / raw - 1.0);

    const float BETA = 3950.0;
    const float T0 = 298.15;

    float tempK = 1.0 / (1.0 / T0 + (1.0 / BETA) * log(resistance / 10000.0));

    return tempK - 273.15;
}

void update_humidity()
{
    unsigned long now = millis();

    if(now - timerHum >= intervalHum)
    {
        timerHum = now;

        float t, h;

        if(dht_sensor.measure(&t, &h))
        {
            humidityValue = h;
        }
        else
        {
            Serial.println("DHT FAIL");
        }
    }
}

int water_level()
{
    unsigned long now = millis();

    if(now - timerWater >= intervalWater)
    {
        timerWater = now;

        waterValue = analogRead(water_pin);

        if(waterValue > minim_water)
        {
            digitalWrite(led_pin, HIGH);
            tone(buzzer_pin, 2000);
            water = true;
        }
        else
        {
            digitalWrite(led_pin, LOW);
            noTone(buzzer_pin);
            water = false;
        }
    }

    return waterValue;
}

void read_button()
{
    static unsigned long lastPress = 0;
    unsigned long now = millis();

    int state = digitalRead(button_pin);

    if(state == LOW && last_state == HIGH && now - lastPress > 200)
    {
        nr_page++;
        if(nr_page > 2) nr_page = 0;

        lastPress = now;
    }

    last_state = state;
}

void writeLCD()
{
    unsigned long now = millis();

    if(now - timerLCD < intervalLCD)
        return;

    timerLCD = now;

    if(water)
    {
        lcd.setCursor(0, 0);
        lcd.print("WATER ALERT!   ");

        lcd.setCursor(0, 1);
        lcd.print(waterValue);
        lcd.print("      ");

        return;
    }

    if(nr_page == 0)
    {
        lcd.setCursor(0, 0);
        lcd.print("Temp:          ");

        lcd.setCursor(0, 1);
        lcd.print(read_temperature());
        lcd.print(" C     ");
    }
    else if(nr_page == 1)
    {
        lcd.setCursor(0, 0);
        lcd.print("Humidity:      ");

        lcd.setCursor(0, 1);
        lcd.print(humidityValue);
        lcd.print(" %     ");
    }
    else if(nr_page == 2)
    {
        lcd.setCursor(0, 0);
        lcd.print("Light:         ");

        lcd.setCursor(0, 1);
        lcd.print(read_light());
        lcd.print("      ");
    }
}

void setup()
{
    pinMode(led_pin, OUTPUT);
    pinMode(button_pin, INPUT_PULLUP);
    pinMode(buzzer_pin, OUTPUT);

    Serial.begin(9600);
    lcd.begin(16, 2);
}

void loop()
{
    read_button();
    water_level();
    update_humidity();
    writeLCD();
}