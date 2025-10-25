#include "SmartDevice.h"
using namespace std;

// constructor for the SmartDevice with the id, name, and manufacturer.
SmartDevice::SmartDevice(int id, const string & name, const string & manufacturer)
    : id(id)
    , name(name)
    , manufacturer(manufacturer)
    , status(false)
    , connectionStatus(true)
{
}

// used for cleanup
SmartDevice::~SmartDevice()
{ 
}

// Activates the device 
void SmartDevice::Activate()
{
    status = true;
    cout << name << " is now activated." << endl;
}

// Deactivates the device
void SmartDevice::Deactivate()
{
    status = false;
    cout << name << " is now deactivated." << endl;
}

// Displays device info
void SmartDevice::ViewInfo() const
{
    cout << "Device ID: " << id << "\nDevice Name: " << name 
         << "\nManufacturer: " << manufacturer 
         << "\nStatus: " << (status ? "Active" : "Inactive") 
         << "\nConnection Status: " << (connectionStatus ? "Connected" : "Disconnected") 
         << endl;
}

// shows the current connection status.
bool SmartDevice::CheckConnection() const
{
    return connectionStatus;
}

// interacts with the device's connection status.
void SmartDevice::ToggleConnection()
{
    connectionStatus = !connectionStatus;
}

// outputs whether the device is activated.
bool SmartDevice::GetStatus() const
{
    return status;
}

// outputs the device's ID.
int SmartDevice::GetId() const
{
    return id;
}
