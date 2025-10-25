#include "SecurityCamera.h"
using namespace std;

// base class and specific device attributes
SecurityCamera::SecurityCamera(int id, const string& name, const string& manufacturer, const string& quality, const string& power)
    : SmartDevice(id, name, manufacturer), cameraQuality(quality), power(power) {}

// interaction events for the security camera.
void SecurityCamera::InteractionEvent() 
{
    if (!GetStatus()) {
        cout << "Device is inactive. Please activate it first." << endl;
        return;
    }
    cout << "Now viewing camera: " << name << endl;
}

// camera information along with basic device info.
void SecurityCamera::ViewInfo() const 
{
    SmartDevice::ViewInfo();
    cout << "Camera Quality: " << cameraQuality 
         << "\nPower Source: " << power << endl;
}
