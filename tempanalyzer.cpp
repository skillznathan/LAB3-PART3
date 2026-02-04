#include <iostream>
#include <fstream> // Required for file operations
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    std::ifstream inputFile("temperatures.txt"); // Open file for reading

    if (!inputFile.is_open()) {
        std::cerr << "Error opening temperatures.txt for reading!" << std::endl;
        return 1;
    }

    double temperature = 0.0;
    double sum = 0.0;
    int count = 0;

    // Read numbers from the file until the end of the file is reached
    while (inputFile >> temperature) {
        sum += temperature;
        count++;
    }

    inputFile.close(); // Close the file

    if (count == 0) {
        std::cout << "No temperatures were found in the file." << std::endl;
        return 0;
    }

    double average = sum / count;

    std::cout << "Temperatures analyzed for " << count << " days." << std::endl;
    // Format output to one decimal place
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "The average temperature was: " << average << std::endl;

    return 0;
}
