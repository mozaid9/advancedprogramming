#ifndef SMARTHOMEMANAGER_H
#define SMARTHOMEMANAGER_H

#include <vector>
#include <string>
#include "Room.h"
using namespace std;

// manages rooms and devices in the smart home system.
class SmartHomeManager 
{
private:
    vector<Room*> rooms;  // List of room pointers

public:
    SmartHomeManager();
    ~SmartHomeManager();

    void Run(); // Runs the main smarthomemanager loop

private:
    void CreateRoom();
    void DeleteRoom();
    void ListRooms() const;
    void AddDeviceToRoom();
    void RemoveDeviceFromRoom();
    void ListDevicesInRoom() const;
    void ActivateDeactivateAllInRoom();
    void ControlDeviceInRoom();
    void CleanUp(); 
};

#endif
