#include "SmartHomeManager.h"
#include "SecurityCamera.h"
#include "Thermostat.h"
#include "SmartSpeaker.h"
#include "SmartLight.h"
#include <iostream>
#include <limits>
using namespace std;

//function to get a valid integer.
int getValidatedInt(const string & prompt)
{
    int value;
    cout << prompt;
    while (!(cin >> value))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer: ";
    }
    return value;
}

// constructor.
SmartHomeManager::SmartHomeManager()
{
}

// Destructor 
SmartHomeManager::~SmartHomeManager()
{
    CleanUp();
}

// Main loop that displays the menu and handles user input.
void SmartHomeManager::Run()
{
    int choice;
    bool exit = false;
    while (!exit)
    {
        cout << "\nSmart Home Automation Manager Menu" << endl;
        cout << "1. Create Room" << endl;
        cout << "2. Delete Room" << endl;
        cout << "3. List Rooms" << endl;
        cout << "4. Add Device to Room" << endl;
        cout << "5. Remove Device from Room" << endl;
        cout << "6. List Devices in Room" << endl;
        cout << "7. Activate/Deactivate All Devices in Room" << endl;
        cout << "8. Control Individual Device in Room" << endl;
        cout << "9. Exit" << endl;
        choice = getValidatedInt("Enter choice: ");
        
        switch (choice)
        {
            case 1:
                CreateRoom();
                break;
            case 2:
                DeleteRoom();
                break;
            case 3:
                ListRooms();
                break;
            case 4:
                AddDeviceToRoom();
                break;
            case 5:
                RemoveDeviceFromRoom();
                break;
            case 6:
                ListDevicesInRoom();
                break;
            case 7:
                ActivateDeactivateAllInRoom();
                break;
            case 8:
                ControlDeviceInRoom();
                break;
            case 9:
                exit = true;
                break;
            default:
                cout << "Invalid option, try again." << endl;
                break;
        }
    }
}

// prompts the user for a room name and creates a new room.
void SmartHomeManager::CreateRoom()
{
    string roomName;
    cout << "Enter room name: ";
    cin >> roomName;
    Room * newRoom = new Room(roomName);
    rooms.push_back(newRoom);
    cout << "Room " << roomName << " created." << endl;
}

// delete a room if user selects
void SmartHomeManager::DeleteRoom()
{
    if (rooms.empty())
    {
        cout << "No rooms to delete." << endl;
        return;
    }
    int index = getValidatedInt("Enter room number to delete: ");
    if (index < 1 || index > static_cast<int>(rooms.size()))
    {
        cout << "Invalid room number." << endl;
        return;
    }
    delete rooms[index - 1];
    rooms.erase(rooms.begin() + index - 1);
    cout << "Room deleted." << endl;
}

// Lists all available rooms.
void SmartHomeManager::ListRooms() const
{
    if (rooms.empty())
    {
        cout << "No rooms available." << endl;
        return;
    }
    cout << "Rooms:" << endl;
    for (size_t i = 0; i < rooms.size(); i++)
    {
        cout << i + 1 << ". " << rooms[i]->GetName() << endl;
    }
}

// Adds a device to a selected room.
void SmartHomeManager::AddDeviceToRoom()
{
    if (rooms.empty())
    {
        cout << "No rooms available. Create a room first." << endl;
        return;
    }
    ListRooms();
    int roomIndex = getValidatedInt("Enter room number to add device: ");
    if (roomIndex < 1 || roomIndex > static_cast<int>(rooms.size()))
    {
        cout << "Invalid room number." << endl;
        return;
    }
    Room * room = rooms[roomIndex - 1];
    
    int deviceType = getValidatedInt("Select device type to add:\n1. Security Camera\n2. Thermostat\n3. Smart Speaker\n4. Smart Light\nEnter choice: ");
    
    string name, manufacturer;
    cout << "Enter device name: ";
    cin >> name;
    cout << "Enter manufacturer: ";
    cin >> manufacturer;
    
    // get device ID by increasing in +1 each time a new device is added
    int deviceId = room->GetDevices().size() + 1;
    
    switch (deviceType)
    {
        case 1:
        {
            string quality, power;
            cout << "Enter camera quality (e.g., 1080p): ";
            cin >> quality;
            cout << "Enter power source (e.g., battery): ";
            cin >> power;
            room->AddDevice(new SecurityCamera(deviceId, name, manufacturer, quality, power));
            break;
        }
        case 2:
        {
            int temp = getValidatedInt("Enter target temperature: ");
            room->AddDevice(new Thermostat(deviceId, name, manufacturer, temp));
            break;
        }
        case 3:
        {
            int volume = getValidatedInt("Enter volume level (0-100): ");
            room->AddDevice(new SmartSpeaker(deviceId, name, manufacturer, volume));
            break;
        }
        case 4:
        {
            int brightness = getValidatedInt("Enter brightness level (0-100): ");
            string colour;
            cout << "Enter colour type: ";
            cin >> colour;
            room->AddDevice(new SmartLight(deviceId, name, manufacturer, brightness, colour));
            break;
        }
        default:
            cout << "Invalid device type." << endl;
            break;
    }
    cout << "Device added to room " << room->GetName() << "." << endl;
}

// Removes a device from a selected room.
void SmartHomeManager::RemoveDeviceFromRoom()
{
    if (rooms.empty())
    {
        cout << "No rooms available." << endl;
        return;
    }
    ListRooms();
    int roomIndex = getValidatedInt("Enter room number to remove device from: ");
    if (roomIndex < 1 || roomIndex > static_cast<int>(rooms.size()))
    {
        cout << "Invalid room number." << endl;
        return;
    }
    Room * room = rooms[roomIndex - 1];
    room->ListDevices();
    int deviceIndex = getValidatedInt("Enter device number to remove: ");
    room->RemoveDevice(deviceIndex - 1);
    cout << "Device removed from room " << room->GetName() << "." << endl;
}

// Lists devices in a selected room.
void SmartHomeManager::ListDevicesInRoom() const
{
    if (rooms.empty())
    {
        cout << "No rooms available." << endl;
        return;
    }
    ListRooms();
    int roomIndex = getValidatedInt("Enter room number to list devices: ");
    if (roomIndex < 1 || roomIndex > static_cast<int>(rooms.size()))
    {
        cout << "Invalid room number." << endl;
        return;
    }
    rooms[roomIndex - 1]->ListDevices();
}

// Activates or deactivates all devices in a selected room.
void SmartHomeManager::ActivateDeactivateAllInRoom()
{
    if (rooms.empty())
    {
        cout << "No rooms available." << endl;
        return;
    }
    ListRooms();
    int roomIndex = getValidatedInt("Enter room number: ");
    if (roomIndex < 1 || roomIndex > static_cast<int>(rooms.size()))
    {
        cout << "Invalid room number." << endl;
        return;
    }
    Room * room = rooms[roomIndex - 1];
    int action = getValidatedInt("1. Activate all devices\n2. Deactivate all devices\nSelect an action: ");
    if (action == 1)
    {
        room->ActivateAllDevices();
    }
    else if (action == 2)
    {
        room->DeactivateAllDevices();
    }
    else
    {
        cout << "Invalid action." << endl;
    }
}

// Controls a specific device in a selected room.
void SmartHomeManager::ControlDeviceInRoom()
{
    if (rooms.empty())
    {
        cout << "No rooms available." << endl;
        return;
    }
    ListRooms();
    int roomIndex = getValidatedInt("Enter room number: ");
    if (roomIndex < 1 || roomIndex > static_cast<int>(rooms.size()))
    {
        cout << "Invalid room number." << endl;
        return;
    }
    Room * room = rooms[roomIndex - 1];
    room->ListDevices();
    int deviceIndex = getValidatedInt("Enter device number to control: ");
    if (deviceIndex < 1 || deviceIndex > static_cast<int>(room->GetDevices().size()))
    {
        cout << "Invalid device number." << endl;
        return;
    }
    room->GetDevices()[deviceIndex - 1]->InteractionEvent();
}

// Deletes all allocated rooms.
void SmartHomeManager::CleanUp()
{
    for (auto room : rooms)
    {
        delete room;
    }
    rooms.clear();
}
