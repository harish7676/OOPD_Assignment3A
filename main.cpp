#include <iostream>
#include <string>
#include "library.h"

using namespace std;

void userInputTest() {
    try {
        // Create stations
        cout << "Enter the type of Station ID (1 for integer, 2 for string): ";
        int idType;
        cin >> idType;

        if (idType == 1) {
            int stationID;
            cout << "Enter Station ID (integer): ";
            cin >> stationID;
            string stationName;
            cout << "Enter Station Name: ";
            cin.ignore();
            getline(cin, stationName);

            Station<int> station(stationID, stationName);

            int numLines;
            cout << "Enter number of lines: ";
            cin >> numLines;
            for (int i = 0; i < numLines; ++i) {
                string lineName;
                cout << "Enter Line " << i + 1 << " Name: ";
                cin >> lineName;
                station.addLine(lineName);
            }

            station.display();
        } else if (idType == 2) {
            string stationID;
            cout << "Enter Station ID (string): ";
            cin >> stationID;
            string stationName;
            cout << "Enter Station Name: ";
            cin.ignore();
            getline(cin, stationName);

            Station<string> station(stationID, stationName);

            int numLines;
            cout << "Enter number of lines: ";
            cin >> numLines;
            for (int i = 0; i < numLines; ++i) {
                string lineName;
                cout << "Enter Line " << i + 1 << " Name: ";
                cin >> lineName;
                station.addLine(lineName);
            }

            station.display();
        } else {
            throw invalid_argument("Invalid Station ID type.");
        }

        // Create platforms
        int numPlatforms;
        cout << "Enter number of platforms: ";
        cin >> numPlatforms;

        vector<Platform> platforms;
        for (int i = 0; i < numPlatforms; ++i) {
            platforms.emplace_back(i + 1);
        }

        // Add trains to platforms
        while (true) {
            cout << "Enter Platform Number (or -1 to exit): ";
            int platformNum;
            cin >> platformNum;
            if (platformNum == -1) break;

            if (platformNum < 1 || platformNum > numPlatforms) {
                cerr << "Invalid Platform Number. Try again.\n";
                continue;
            }

            cout << "Enter Line Name: ";
            string lineName;
            cin >> lineName;

            cout << "Enter Train Time (HH MM): ";
            int hour, minute;
            cin >> hour >> minute;

            cout << "Is the train stoppage or through (1 for stoppage, 0 for through)? ";
            bool isStoppage;
            cin >> isStoppage;

            try {
                platforms[platformNum - 1].addTrain(lineName, Time(hour, minute), isStoppage);
                cout << "Train successfully scheduled.\n";
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }

        // Display platform schedules
        for (const auto& platform : platforms) {
            platform.display();
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int main() {
    cout << "Indian Railways Scheduling System.\n";
    userInputTest();
    return 0;
}