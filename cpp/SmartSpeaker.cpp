#include "SmartSpeaker.h"
using namespace std;

SmartSpeaker::SmartSpeaker(int id, const string& name, const string& manufacturer, int volume)
    : SmartDevice(id, name, manufacturer), volumeLevel(volume) {}

void SmartSpeaker::InteractionEvent() 
{
    if (!GetStatus()) {
        cout << "Device is inactive. Please activate it first." << endl;
        return;
    }
    cout << "Enter volume level (0-100): ";
    cin >> volumeLevel;
}

void SmartSpeaker::ViewInfo() const 
{
    SmartDevice::ViewInfo();
    cout << "Volume Level: " << volumeLevel << endl;
}