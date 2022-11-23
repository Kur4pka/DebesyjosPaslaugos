#include <iostream>
#include "Composite.h"
#include "Leaf.h"

using namespace std;

int main() {

    auto *cluster = new Composite("CLUSTER");

    auto *user = new Leaf(vector<string>(), 0, 0);
    auto *mainServer = new Leaf(vector<string>{string("Basic"), string("Middle"), string("Max")}, 5000, 900);

    cluster->addComponent(mainServer);

int input = 1;

while(input != 0) {
    cout << " -----------------------" << endl;
    cout << "          MENU         " << endl;
    cout << " -----------------------" << endl;
    cout << "1. Cloud resource availability" << endl;
    cout << "2. Custom plan" << endl;
    cout << "3. Current user plan" << endl;
    cout << "0. Exit Program." << endl;

    cout << "Iveskite punkto nr: ";
    cin >> input;

    switch (input) {
        case 1:
            cluster->getInformation();
            cin.ignore(1);
            cout << "Press enter to continue:";
            cin.get();
            break;
            case 2: {

                    cout << "-----------------------" << endl;
                    cout << "      Choose ServerType" << endl;
                    cout << " -----------------------" << endl;
                    cout << "1. Basic" << endl;
                    cout << "2. Middle" << endl;
                    cout << "3. Max" << endl;
                    cout << "Iveskite punkto nr: ";
                    cin >> input;
                    user->assignServerType(input, mainServer);


                    cout << "-----------------------" << endl;
                    cout << "   Storage Capacity    " << endl;
                    cout << "-----------------------" << endl;
                    cout << "1. 10 TB" << endl;
                    cout << "2. 100 TB" << endl;
                    cout << "3. Custom" << endl;
                    cout << "Iveskite punkto nr: ";
                    cin >> input;
                    switch (input) {
                        case 1:
                            user->assignStorage(10, mainServer);
                            break;
                        case 2:
                            user->assignStorage(100, mainServer);
                            break;
                        case 3: {
                            cout << "Input desired storage capacity: ";
                            int size;
                            cin >> size;
                            while (cin.fail() || !mainServer->getStorageAvailability(size)) {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout << "Input is not a number or not enough capacity available" << endl;
                                cout << "input number: ";
                                cin >> size;
                            }
                            user->assignStorage(size, mainServer);
                            break;
                        }
                        default: break;
                    }
                    cout << "-----------------------" << endl;
                    cout << "    Database Capacity   " << endl;
                    cout << " -----------------------" << endl;
                    cout << "1. 5 TB" << endl;
                    cout << "2. 15 TB" << endl;
                    cout << "3. Custom" << endl;
                    cout << "Iveskite punkto nr: ";
                    cin >> input;
                    switch (input) {
                        case 1:
                            user->assignDatabase(5, mainServer);
                            break;
                        case 2:
                            user->assignDatabase(15, mainServer);
                            break;
                        case 3: {
                            cout << "Input desired storage capacity: ";
                            int size;
                            cin >> size;
                            while (cin.fail() || !mainServer->getDataAvailability(size)) {
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                                cout << "Input is not a number or not enough capacity available" << endl;
                                cout << "input number: ";
                                cin >> size;
                            }
                            user->assignDatabase(size, mainServer);
                            break;
                        }
                        default: break;
                }
            }
        case 3:
            cout << "-----------------------" << endl;
            if(user->getCapacity() != 0) {
                cout << "     Current plan      " << endl;
            cout << " -----------------------" << endl;
            user->getInformation();
            cout << "-----------------------" << endl;
            cout << "1. Cancel plan" << endl;
            cout << "2. Back" << endl;
            cout << "Iveskite punkto nr: ";
            cin >> input;
                if(input == 1) {
                    user->clearUserPlan(mainServer);
                }

            }else {
                cout << "    No Active plans" << endl;
                cin.ignore(1);
                cout << "Press enter to continue:";
                cin.get();
            }
            break;
        default:
            cout << "Tokio pasirinkimo nera " << input << endl;
    }
}



    return 0;
}

