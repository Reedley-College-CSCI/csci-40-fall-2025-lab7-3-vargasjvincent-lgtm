#include <iostream>
#include <fstream>
using namespace std;

// Vincent Vargas
// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.
struct TemperatureRecord { int day; int temperature; };

// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord array[], int size); // TODO: Fix the parameters
void printTemperatures(const int MAX_DAYS , TemperatureRecord records[]);
//TemperatureRecord findMin(const ???);
//TemperatureRecord findMax(const ???);
double findAverage(const int MAX_DAYS, TemperatureRecord records[]);

int main() {
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TemperatureRecord records[MAX_DAYS];
    int size = 0;  // Actual number of records read

    // TODO: Step 3 - Call readTemperatures() to load data from file
    readTemperatures(records, MAX_DAYS);
    
    // TODO: Step 4 - Print the temperatures
    printTemperatures(MAX_DAYS, records);
    // TODO: Step 5 - Compute and display min, max, and average temperature
    
    cout << "The average is: " << findAverage(MAX_DAYS, records);
    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
void readTemperatures(TemperatureRecord array[], int size) {
    int count = 0;
    ifstream inFile("temps.txt");
    if (!inFile) {
        cout << "Error: Could not open file" << endl;
      
    }
        while (count < size && inFile) {
            inFile >> array[count].day; 
            inFile >> array[count].temperature;
            count++;
        }
    inFile.close();
}

// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
void printTemperatures(const int MAX_DAYS, TemperatureRecord records[]) {
    cout << "Day  Temp" << endl;
    for (int i = 0; i < MAX_DAYS; i++) 
    {
        cout << records[i].day << "   " << records[i].temperature << endl;
    }
}

// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature

// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature

// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
double findAverage(const int MAX_DAYS, TemperatureRecord records[]) {
    double sum = 0.0;
    for (int i = 0; i < MAX_DAYS; i++) {
        sum = sum + records[i].temperature;
    }
    return sum / MAX_DAYS;
}

