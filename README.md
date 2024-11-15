Assignment 3A Solutions - Object Oriented Programming Design (IIIT Delhi)
This repository contains the solutions for Assignment 3A of the Object Oriented Programming Design course at IIIT Delhi.

Overview
In this assignment, I created a library for Railway Systems using object-oriented programming principles. The library models the following entities:

Station
Lines
Platforms
Functionalities
Station, Line, Platform, and Train Management:

Users can enter details about stations, lines, platforms, and trains.
Trains are scheduled with timing constraints to prevent overlapping on the same platform.
Test Library:

The library.h contains all the functionalities needed for this system.
The test.cpp file includes test cases to verify both correct and incorrect functionality of the library.
Menu-Driven Program:

The main.cpp file implements a menu-driven program that allows the user to interact with the Railway System.
Build System:

A Makefile is provided to streamline the build process.
Separate executables are created for the main program (main.cpp) and testing program (test.cpp), both in debug and optimized modes.
File Structure
library.h: Contains the implementation of all functionalities for the Railway System.
main.cpp: Implements the menu-driven interface for user interaction.
test.cpp: Contains test cases to validate the library's functionality.
Makefile: Automates the build process, creating executables for both debug and optimized versions.
How to Run
Step 1: Build Executables
To compile the project and generate executables:

bash
Copy code
mingw32-make
This command will create the following executables:

Debug Versions:
main_debug.exe
test_debug.exe
Optimized Versions:
main_optimized.exe
test_optimized.exe
Step 2: Run Executables
Run the desired executable by entering the following command:

bash
Copy code
./<executable-name>
For example:

bash
Copy code
./main_debug.exe
Step 3: Clean Build Files
To remove all generated files and clean the directory:

bash
Copy code
mingw32-make clean
Example Commands
bash
Copy code
mingw32-make            # Build all executables
./main_debug.exe        # Run the main program in debug mode
./test_optimized.exe    # Run the test program in optimized mode
mingw32-make clean      # Clean the build files
Features
Timing Constraints: Prevent overlapping train schedules on the same platform.
Debugging: Debug mode executables include additional error-checking and logging for development.
Optimized Builds: Optimized executables improve runtime performance for production use

Taken Help from LLM wherever its required.