#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"
using namespace std;

class Thermostat : public SmartDevice 
{
private:
    int targetTemperature;

public:
    Thermostat(int id, const string& name, const string& manufacturer, int temp = 20);
    void InteractionEvent() override;
    void ViewInfo() const override;
};

#endif 
