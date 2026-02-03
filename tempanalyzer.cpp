#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream inputFile("temperatures.txt");
    double temp;
    double sum = 0.0;
    int count = 0;

    // Check if file opened successfully
    if (!inputFile) {
        std::cerr << "Error: Could not open temperatures.txt" << std::endl;
        return 1;
    }

    // Read numbers from file
    while (inputFile >> temp) {
        sum += temp;
        count++;
    }
    inputFile.close();

    // Calculate and display results
    if (count > 0) {
        double average = sum / count;
        std::cout << "Number of days recorded: " << count << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "Average temperature: " << average << std::endl;
    } else {
        std::cout << "No data found in file." << std::endl;
    }

    return 0;
}
