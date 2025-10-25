#ifndef SMARTSPEAKER_H
#define SMARTSPEAKER_H

#include "SmartDevice.h"
using namespace std;

class SmartSpeaker : public SmartDevice 
{
private:
    int volumeLevel;

public:
    SmartSpeaker(int id, const string& name, const string& manufacturer, int volume = 50);
    void InteractionEvent() override;
    void ViewInfo() const override;
};

#endif 
