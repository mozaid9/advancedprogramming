#include "Room.h"   
using namespace std;

// Constructor
Room::Room(const string & roomName)
    : name(roomName)  
{
}

// cleans up memory
Room::~Room()
{
    for (SmartDevice * device : devices)
    {
        delete device;
    }
    // Clean up avoiding memory leak
    devices.clear();
}

// the name of the room.
string Room::GetName() const
{
    return name;
}

// Adds a new SmartDevice
void Room::AddDevice(SmartDevice * device)
{
    devices.push_back(device);
}

// used to removde devices in room
void Room::RemoveDevice(int deviceIndex)
{
    if (deviceIndex < 0 || deviceIndex >= devices.size())
    {
        cout << "Invalid device index." << endl;
        return;
    }
    // Delete the device to free memory
    delete devices[deviceIndex];
    devices.erase(devices.begin() + deviceIndex);
}

// lists the devices in room
void Room::ListDevices() const
{
    if (devices.empty())
    {
        cout << "No devices in room " << name << endl;
        return;
    }
    cout << "Devices in room " << name << ":" << endl;
    for (size_t i = 0; i < devices.size(); i++)
    {
        cout << i + 1 << ". ";  // Display the device number
        devices[i]->ViewInfo(); 
        cout << endl;
    }
}

void Room::ActivateAllDevices()
{
    for (SmartDevice * device : devices)
    {
        device->Activate(); 
    }
    cout << "All devices in room " << name << " activated." << endl;
}

void Room::DeactivateAllDevices()
{
    for (SmartDevice * device : devices)
    {
        device->Deactivate(); 
    }
    cout << "All devices in room " << name << " deactivated." << endl;
}

vector<SmartDevice*> & Room::GetDevices()
{
    return devices;
}
