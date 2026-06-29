/*
 * Student: Chris Hicks
 * Course: CS-210
 * Date: 6/20/2026
 * Description: Handles the main menu display and user input validation
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "GroceryTracker.h"

using namespace std;

void displayMenu() {
    cout << "\nCorner Grocer - Main Menu" << endl;
    cout << "1. Search for an item's quantity" << endl;
    cout << "2. Print all items and quantities" << endl;
    cout << "3. Print all items and quantities in histogram format" << endl;
    cout << "4. Exit program" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    GroceryTracker tracker;

    // Data processing and backup file creation without user interaction
    tracker.processInputFile("CS210_Project_Three_Input_File.txt");
    tracker.createBackupFile("frequency.dat");

    bool running = true;
    string userInput;
    int choice;

    while (running) {
        displayMenu();

        // Read the entire line of input as a string
        getline(cin, userInput);

        try {    
            // Attempt to parse string into an integer
            choice = stoi(userInput);

            switch (choice) {
                case 1: {
                    string itemSearch;
                    cout << "Enter the item name to search for: ";
                    getline(cin, itemSearch);

                    // Ensure case insensitivity
                    if (!itemSearch.empty()) {
                        itemSearch[0] = toupper(itemSearch[0]);
                    }

                    tracker.searchItemFrequency(itemSearch);
                    break;
                }
                case 2:
                    tracker.printAllFrequencies();
                    break;
                case 3:
                    tracker.printHistogram();
                    break;
                case 4:
                    cout << "\nExiting program. Backup data has been saved to frequency.dat. Goodbye!" << endl;
                    running = false;
                    break;
                default:
                    cout << "\nInvalid selection. Please enter a numerical value of 1, 2, 3 or 4." << endl;
                    break;
            }
        }

        // Catch the exception thrown if user inputs letters or symbols
        catch (const invalid_argument& e) {
            cout << "\nInvalid input type. Please enter a numerical value of 1, 2, 3 or 4." << endl;
        }
        // Catch the exception thrown if user inputs a numerical value that is out of range of 1 through 4
        catch (const out_of_range& e) {
            cout << "\nInput value is out of range. Please enter a numerical value of 1, 2, 3 or 4." << endl;
        }
    }

    return 0;
}