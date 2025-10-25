#ifndef SMARTLIGHT_H
#define SMARTLIGHT_H

#include "SmartDevice.h"
using namespace std;

class SmartLight : public SmartDevice 
{
private:
    int brightnessLevel;
    string colourType;

public:
    SmartLight(int id, const string& name, const string& manufacturer, int brightness = 50, const string& colour = "warm white");
    void InteractionEvent() override;
    void ViewInfo() const override;
};

#endif 
