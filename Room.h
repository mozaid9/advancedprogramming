#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <string>
#include "SmartDevice.h"
using namespace std;

class Room 
{
private:
    string name;                     // The name of the room.
    vector<SmartDevice*> devices;    // smart devices in room

public:
    Room(const string & roomName);
    ~Room();

    string GetName() const;
    void AddDevice(SmartDevice * device);
    void RemoveDevice(int deviceIndex);
    void ListDevices() const;
    void ActivateAllDevices();
    void DeactivateAllDevices();
    vector<SmartDevice*> & GetDevices();
};

#endif
