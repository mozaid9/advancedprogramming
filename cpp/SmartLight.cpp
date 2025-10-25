#include "SmartLight.h"
using namespace std;

SmartLight::SmartLight(int id, const string& name, const string& manufacturer, int brightness, const string& colour)
    : SmartDevice(id, name, manufacturer), brightnessLevel(brightness), colourType(colour) {}

void SmartLight::InteractionEvent() 
{
    if (!GetStatus()) {
        cout << "Device is inactive. Please activate it first." << endl;
        return;
    }
    cout << "Enter brightness level (0-100): ";
    cin >> brightnessLevel;
    if (colourType == "RGB") {
        cout << "Enter colour: ";
        cin >> colourType;
    }
}

void SmartLight::ViewInfo() const 
{
    SmartDevice::ViewInfo();
    cout << "Brightness Level: " << brightnessLevel 
         << "\nColour Type: " << colourType << endl;
}
