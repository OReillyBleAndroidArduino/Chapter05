#include "CurieBle.h"

static const char* bluetoothDeviceName = "MyDevice"; 

BLEPeripheral blePeripheral; 

// Central connected.  Print MAC address
void onCentralConnected(BLECentral& central) {
  Serial.print("Central connected: ");
  Serial.println(central.address());
}

// Central disconnected
void onCentralDisconnected(BLECentral& central) {
  Serial.print("Central disconnected: ");
  Serial.println(central.address());  
}

void setup() {
  blePeripheral.setLocalName(bluetoothDeviceName); 

  // attach callback when Central connects
  blePeripheral.setEventHandler(
    BLEConnected,
    onCentralConnected
  );
  // attach callback when Central disconnects
  blePeripheral.setEventHandler(
    BLEDisconnected,
    onCentralDisconnected
  );
  
  blePeripheral.begin(); 
}

void loop() {}

