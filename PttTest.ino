#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
bool mLastButtonState = true;
const int cPinNumber = 27;

void setup() {
  Serial.begin(115200); // Optional, to use the serial monitor to see the action
    
  SerialBT.register_callback(callback); // Optional for diagnostics, check status of the connection
  SerialBT.begin("K1100LT PTT"); //Bluetooth device name, make sure it contains 'PTT' to be automatically recognized by Zello
  Serial.println("The device started, now you can pair it with bluetooth!");
  
  pinMode(cPinNumber, INPUT_PULLUP); // Using pin 27, but can be any pin. Use internal pullup so connect button to ground
}

void loop() {
  bool newButtonState = digitalRead(cPinNumber);
  if (mLastButtonState != newButtonState)
  {
    if(newButtonState)
    {
      Serial.println("OFF");
      SerialBT.print("+PTTS=R");
    }
    else
    {
      Serial.println("ON");
      SerialBT.print("+PTTS=P");
    }
    mLastButtonState = newButtonState;
  }

  // Delay to reduce CPU load and conserve energy
  delay(10);
}

void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
  
  if (event == ESP_SPP_SRV_OPEN_EVT) {
 
    Serial.println("Client Connected has address:");
 
    for (int i = 0; i < 6; i++) {
 
      Serial.printf("%02X", param->srv_open.rem_bda[i]);
 
      if (i < 5) {
        Serial.print(":");
      }
 
    }
  }
  else if (event == ESP_SPP_SRV_STOP_EVT)
  {
    Serial.print("Serial server stopped");
  }


}
