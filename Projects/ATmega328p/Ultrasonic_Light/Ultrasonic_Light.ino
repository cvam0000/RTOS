#include <Arduino_FreeRTOS.h>

const int trigPin = 9;
const int echoPin = 10;

void TaskBlink( void *pvParameters );

int green = 13;
int red = 12;

long duration;
int distance;


void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  while (!Serial) {
    ;
  }

  xTaskCreate(
    TaskBlink
    ,  (const portCHAR *)"Blink"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );

}




void loop() {


}


void TaskBlink(void *pvParameters) {
  while (1) {
    digitalWrite(trigPin, LOW);
    vTaskDelay( 2 / portTICK_PERIOD_MS );
    digitalWrite(trigPin, HIGH);
    vTaskDelay( 10 / portTICK_PERIOD_MS );
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
//    Serial.print("Distance: ");
//    Serial.println(distance);

    if (distance < 10) {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
    } else {
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
    }
  }
}

