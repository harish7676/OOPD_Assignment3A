#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <cassert>

using namespace std;

// Helper structure for Time
struct Time {
    int hour;
    int minute;

    Time(int h, int m) {
        if (h < 0 || h > 23 || m < 0 || m > 59) 
            throw invalid_argument("Invalid time");
        hour = h;
        minute = m;
    }

    // Calculate the difference in minutes between two times
    int difference(const Time& other) const {
        return abs((hour * 60 + minute) - (other.hour * 60 + other.minute));
    }

    string toString() const {
        return to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
    }
};

// Template class for Station
template <typename T>
class Station {
    T stationID;
    string stationName;
    vector<string> lines;

public:
    Station(T id, const string& name) : stationID(id), stationName(name) {}

    void addLine(const string& line) {
        lines.push_back(line);
    }

    void display() const {
        cout << "Station ID: " << stationID << ", Name: " << stationName << ", Lines: ";
        for (const auto& line : lines)
            cout << line << " ";
        cout << endl;
    }

    T getID() const {
        return stationID;
    }
};

// Class for Platform
class Platform {
    int platformNumber;
    vector<pair<string, Time>> schedule; // Pair of line and time

public:
    Platform(int number) : platformNumber(number) {}

    void addTrain(const string& line, const Time& time, bool isStoppage) {
        for (const auto& entry : schedule) {
            int diff = entry.second.difference(time);
            if (entry.first == line && 
                ((isStoppage && diff < 30) || (!isStoppage && diff < 10))) {
                throw invalid_argument("Invalid train schedule: violates timing constraint.");
            }
        }
        schedule.emplace_back(line, time);
    }

    void display() const {
        cout << "Platform Number: " << platformNumber << "\nTrain Schedule:\n";
        for (const auto& entry : schedule) {
            cout << "  Line: " << entry.first << ", Time: " << entry.second.toString() << endl;
        }
    }
};

// Class for Line
class Line {
    string lineName;
    vector<Platform> platforms;

public:
    Line(const string& name) : lineName(name) {}

    void addPlatform(const Platform& platform) {
        platforms.push_back(platform);
    }

    void display() const {
        cout << "Line Name: " << lineName << endl;
        for (const auto& platform : platforms)
            platform.display();
    }
};