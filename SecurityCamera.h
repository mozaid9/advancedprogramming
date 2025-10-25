#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include "SmartDevice.h"
using namespace std;

class SecurityCamera : public SmartDevice 
{
private:
    string cameraQuality; 
    string power;        
public:
    // initialises a SecurityCamera object with the device attributes
    SecurityCamera(int id, const string& name, const string& manufacturer, const string& quality, const string& power);
    
    // interaction event where user request to view the camera feed.
    void InteractionEvent() override;
    
    // information about the security camera.
    void ViewInfo() const override;
};

#endif
