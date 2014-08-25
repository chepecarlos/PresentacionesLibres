#include <SPI.h>
#include "WiFly.h"

WiFlyServer server(80);

void setup() {
  WiFly.begin();
  Serial.begin(9600);
  Serial.print("IP: ");
  Serial.println(WiFly.ip());
  server.begin();

}

void loop() {
  if(server.available()){
    Serial.println("OK");
  }

}
