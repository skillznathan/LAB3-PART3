#include <iostream>
#include <fstream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    std::ifstream inputFile;
    inputFile.open("temperatures.txt");

    // Check if the file opened successfully
    if (!inputFile) {
        std::cerr << "Error opening the file: temperatures.txt" << std::endl;
        return 1; // Exit with an error code
    }

    double currentTemp;
    double sumOfTemps = 0.0;
    int countOfDays = 0;

    // Read numbers from the file using a while loop
    while (inputFile >> currentTemp) {
        sumOfTemps += currentTemp; // Add the current temperature to the sum
        countOfDays++;             // Increment the count of days
    }

    // Close the file
    inputFile.close();

    // Check if any data was read to prevent division by zero
    if (countOfDays > 0) {
        double averageTemp = sumOfTemps / countOfDays;

        // Display results formatted to one decimal place
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "Number of days recorded: " << countOfDays << std::endl;
        std::cout << "Average temperature: " << averageTemp << " degrees" << std::endl;
    } else {
        std::cout << "No temperature data found in the file." << std::endl;
    }

    return 0;
}
