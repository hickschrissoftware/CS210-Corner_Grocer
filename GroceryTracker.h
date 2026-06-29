/*
 * Student: Chris Hicks
 * Course: CS-210
 * Date: 6/20/2026
 * Description: Class declaration for tracking grocery item frequencies
 */
 
#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H
#include <string>
#include <map>

class GroceryTracker {

private:
    // Map to store the item name as the key and its frequency as the value
    std::map<std::string, int> itemFrequencies;

public:
    // Core data processing methods
    void processInputFile(const std::string& filename);
    void createBackupFile(const std::string& filename);

    // Menu option methods
    void searchItemFrequency(const std::string& item);
    void printAllFrequencies();
    void printHistogram();
 };

 #endif