// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "a9088adb-74f3-4b5a-8f09-975f66b2a3ae";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onMsgChange();
void onPotChange();
void onHumidityChange();
void onEveningTimerChange();
void onTimerChange();
void onFanChange();
void onLedChange();

String msg;
CloudTemperatureSensor temperature;
int pot;
CloudRelativeHumidity humidity;
CloudSchedule eveningTimer;
CloudSchedule timer;
bool fan;
bool led;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(msg, READWRITE, ON_CHANGE, onMsgChange);
  ArduinoCloud.addProperty(temperature, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(pot, READWRITE, ON_CHANGE, onPotChange, 1);
  ArduinoCloud.addProperty(humidity, READWRITE, ON_CHANGE, onHumidityChange);
  ArduinoCloud.addProperty(eveningTimer, READWRITE, ON_CHANGE, onEveningTimerChange);
  ArduinoCloud.addProperty(timer, READWRITE, ON_CHANGE, onTimerChange);
  ArduinoCloud.addProperty(fan, READWRITE, ON_CHANGE, onFanChange);
  ArduinoCloud.addProperty(led, READWRITE, ON_CHANGE, onLedChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);