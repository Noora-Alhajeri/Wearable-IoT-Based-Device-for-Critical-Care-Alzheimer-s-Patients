#include "Adafruit_MLX90614.h"

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);

  Serial.println("Adafruit MLX90614 test");

  mlx.begin();
}

void loop() {
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
  String ambient_tempc = String(mlx.readAmbientTempC());
  Particle.publish("Ambient Temp Grad Celsius", ambient_tempc, PRIVATE); // publish to cloud
  
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  String object_tempc = String(mlx.readObjectTempC());
  Particle.publish("Object Temp Grad Celsius", object_tempc, PRIVATE); // publish to cloud
  
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

  Serial.println();
  
  delay(500);
}
