#include "Thermostat.h"
using namespace std;

Thermostat::Thermostat(int id, const string& name, const string& manufacturer, int temp)
    : SmartDevice(id, name, manufacturer), targetTemperature(temp) {}

void Thermostat::InteractionEvent() 
{
    if (!GetStatus()) {
        cout << "Device is inactive. Please activate it first." << endl;
        return;
    }
    cout << "Enter target temperature: ";
    cin >> targetTemperature;
}

void Thermostat::ViewInfo() const 
{
    SmartDevice::ViewInfo();
    cout << "Target Temperature: " << targetTemperature << " degrees" << endl;
}
