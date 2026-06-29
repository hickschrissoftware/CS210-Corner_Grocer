/*
 * Student: Chris Hicks
 * Course: CS-210
 * Date: 6/20/2026
 * Description: Implementation of the GroceryTracker class methods
 */

#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

// Reads the input text file and populates the itemFrequencies map
void GroceryTracker::processInputFile(const std::string& filename) {
    std::ifstream inFS;
    std::string item;

    inFS.open(filename);

    // Error handling for missing file
    if (!inFS.is_open()) {
        std::cout << "Error: Could not open file: " << filename << std::endl;
        return;
    }

    // Read word by word until end of file
    while (inFS >> item) {
        // Increment new key from default value of 0
        itemFrequencies[item]++;
    }

    inFS.close();
}

// Writes the accumulated data to backup .dat file
void GroceryTracker::createBackupFile(const std::string& filename) {
    std::ofstream outFS;

    outFS.open(filename);

    // Error handling to write permissions
    if (!outFS.is_open()) {
        std::cout << "Error: Could not create backup file: " << filename << std::endl;
        return;
    }

    // Iterate through the map and write out each key-value pair
    for (const auto& pair : itemFrequencies) {
        outFS << pair.first << " " << pair.second << std::endl;
    }

    outFS.close();
}

// Outputs the frequency of a specific user-requested item
void GroceryTracker::searchItemFrequency(const std::string& item) {
    // .find() returns an iterator to the item or .end() if not found
    auto it = itemFrequencies.find(item);

    // Determine verb in output based on if item is singular or plural
    std::string verb = (item.back() == 's' || item.back() == 'S') ? "were" : "was";

    if (it != itemFrequencies.end()) {
        // Determine if item was purchased once or multiple times
        std::string time_s = (it->second == 1) ? "time" : "times";

        std::cout << "\n--> " << it->first << " " << verb << " purchased " << it->second << " " << time_s << "." << std::endl;
    } else {
        std::cout << "\n--> Notice: '" << item << "' " << verb << " not found in the daily records." << std::endl;
    }
}

// Prints standard frequeny list of all items
void GroceryTracker::printAllFrequencies() {
    std::cout << "\n=== DAILY INVENTORY TOTALS ===" << std::endl;
    for (const auto& pair : itemFrequencies) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << "==============================" << std::endl;
}

// Prints a histogram representation of all item frequencies
void GroceryTracker::printHistogram() {
    std::cout << "\n=== INVENTORY HISTOGRAM ===" << std::endl;
    for (const auto& pair : itemFrequencies) {
        // Formats asterisks
        std::cout << std::left << std::setw(15) << pair.first << " " << std::string(pair.second, '*') << std::endl;
    }

    std::cout << "==============================" << std::endl;
}