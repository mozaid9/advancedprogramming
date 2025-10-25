#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <iostream>
#include <string>
using namespace std;

class SmartDevice 
{
protected:
    int id;
    string name;
    string manufacturer;
    bool status;             // false by default 
    bool connectionStatus;   // simulated connection status

public:
    SmartDevice(int id, const string & name, const string & manufacturer);
    virtual ~SmartDevice();

    void Activate();
    void Deactivate();

    // virtual function
    virtual void InteractionEvent() = 0;
    virtual void ViewInfo() const;

    bool CheckConnection() const;
    void ToggleConnection();
    bool GetStatus() const;

    //  for the device ID.
    int GetId() const;
};

#endif 