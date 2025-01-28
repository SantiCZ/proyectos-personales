#include <iostream>
#include <map>
#include <string>

using namespace std;
class ButtonSimulator {
private:
    map<int, string> buttonMap;
public:
    ButtonSimulator() {
        // Inicializar la botonera con algunos botones y sus funciones
        buttonMap[1] = "Button 1 pressed";
        buttonMap[2] = "Button 2 pressed";
        buttonMap[3] = "Button 3 pressed";
        buttonMap[4] = "Button 4 pressed";
    }
    void simulateButtonPress(int buttonNumber) {
        if (buttonMap.find(buttonNumber) != buttonMap.end()) {
            cout << buttonMap[buttonNumber] << endl;
        }
        else {
            cout << "Button " << buttonNumber << " does not exist" << endl;
        }
    }
    void addButton(int buttonNumber, const string& action) {
        buttonMap[buttonNumber] = action;
        cout << "Button " << buttonNumber << " added with action: " << action << endl;
    }
    void removeButton(int buttonNumber) {
        if (buttonMap.erase(buttonNumber)) {
            cout << "Button " << buttonNumber << " removed" << endl;
        }
        else {
            cout << "Button " << buttonNumber << " does not exist" << endl;
        }
    }
};
int main() {
    ButtonSimulator simulator;
    int choice, buttonNumber;
    string action;

    while (true) {
        cout << "1. Simulate button press\n2. Add button\n3. Remove button\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter button number to simulate press: ";
            cin >> buttonNumber;
            simulator.simulateButtonPress(buttonNumber);
            break;
        case 2:
            cout << "Enter button number to add: ";
            cin >> buttonNumber;
            cin.ignore();
            cout << "Enter action for the button: ";
            getline(cin, action);
            simulator.addButton(buttonNumber, action);
            break;
        case 3:
            cout << "Enter button number to remove: ";
            cin >> buttonNumber;
            simulator.removeButton(buttonNumber);
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
//este codigo no ha sido probado con un prototipo electronico, aclaracion importante
