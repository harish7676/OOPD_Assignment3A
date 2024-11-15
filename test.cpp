#include <iostream>
#include <string>
#include "library.h"

using namespace std;

void testCorrectInput() {
    cout << "### Correct Input Test ###\n";
    
    try {
        // Create station with integer ID
        Station<int> station1(101, "Central Station");
        station1.addLine("Red Line");
        station1.addLine("Blue Line");
        station1.display();

        // Create station with string ID
        Station<string> station2("S1001", "Park Station");
        station2.addLine("Green Line");
        station2.addLine("Yellow Line");
        station2.display();

        // Add platforms and train schedules
        Platform platform1(1);
        platform1.addTrain("Red Line", Time(10, 30), true);
        platform1.addTrain("Red Line", Time(12, 45), false);
        platform1.display();

        Platform platform2(2);
        platform2.addTrain("Green Line", Time(9, 00), true);
        platform2.addTrain("Green Line", Time(10, 15), false);
        platform2.display();
        
        // Add the platforms to the line
        Line line1("Red Line");
        line1.addPlatform(platform1);
        line1.addPlatform(platform2);
        line1.display();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void testIncorrectInput() {
    cout << "### Incorrect Input Test ###\n";
    
    try {
        // Invalid Station ID type (string with number)
        Station<int> invalidStation1(-1, "Invalid Station");
        invalidStation1.addLine("Blue Line");
        
        // Invalid time (e.g., time outside valid range)
        Time invalidTime(25, 61);  // Invalid hour and minute
    } catch (const exception& e) {
        cerr << "Expected Error: " << e.what() << endl;
    }

    try {
        // Try to add a train with an invalid time difference (less than 10 minutes)
        Platform platform(1);
        platform.addTrain("Red Line", Time(10, 30), true);
        platform.addTrain("Red Line", Time(10, 35), false);  // Invalid due to less than 10 minutes between trains
    } catch (const exception& e) {
        cerr << "Expected Error: " << e.what() << endl;
    }

    try {
        // Try to add a train with an invalid time difference (less than 30 minutes)
        Platform platform(2);
        platform.addTrain("Green Line", Time(12, 00), true);
        platform.addTrain("Green Line", Time(12, 25), true);  // Invalid due to less than 30 minutes between stoppage trains
    } catch (const exception& e) {
        cerr << "Expected Error: " << e.what() << endl;
    }
}

int main() {
    cout << "Indian Railways Scheduling System - Test Program.\n";
    
    // Test correct inputs
    testCorrectInput();

    // Test incorrect inputs and ensure proper error handling
    testIncorrectInput();

    return 0;
}
