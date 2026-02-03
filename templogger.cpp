#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 1. Declare an ofstream object to handle file writing.
    // 'temperatures.txt' will be created if it doesn't exist,
    // and this program will overwrite its content each time it runs.
    std::ofstream outputFile("temperatures.txt");

    // Check if the file opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open temperatures.txt for writing." << std::endl;
        return 1; // Return an error code
    }

    int numDays;
    std::cout << "How many days of temperatures would you like to record? ";

    // 2. Ask the user how many days of temperatures they would like to record.
    if (!(std::cin >> numDays) || numDays <= 0) {
        std::cerr << "Error: Invalid input. Please enter a positive number." << std::endl;
        outputFile.close();
        return 1;
    }

    double temperature;

    // 3. Use a for loop that runs for that many days.
    for (int i = 1; i <= numDays; ++i) {
        // 4. Inside the loop, prompt the user for the high temperature for each day
        std::cout << "Enter the high temperature for day " << i << ": ";
        if (!(std::cin >> temperature)) {
            std::cerr << "Error: Invalid temperature input. Exiting." << std::endl;
            // Close the file and return an error if input fails
            outputFile.close();
            return 1;
        }

        // 5. Write each temperature to the file, each on a new line.
        outputFile << temperature << std::endl;
    }

    // Close the file stream when done
    outputFile.close();

    std::cout << "\nSuccessfully logged " << numDays << " temperatures to temperatures.txt" << std::endl;

    return 0; // Return 0 to indicate success
}
