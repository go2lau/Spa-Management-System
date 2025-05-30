#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "specialTreatment.h"

int main() {
    // Seed random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << "Welcome to our Spa!" << std::endl;

    // User input for duration
    float duration;
    std::cout << "Enter duration (in minutes): ";
    std::cin >> duration;

    // Generate random base price between 1000 and 1800
    float price = 1000.0f + static_cast<float>(std::rand() % 801);
    std::cout << "Base price: " << price << std::endl;

    // Clear input buffer before reading time
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string time;
    std::cout << "Enter time: ";
    std::getline(std::cin, time);

    // Construct SpecialTreatment; serviceName is fixed inside the class
    SpecialTreatment st("", duration, price, time);

    // Display basic info using overridden getInfo()
    std::cout << "\n=== Basic Treatment Info ===" << std::endl;
    std::cout << st.getInfo() << std::endl;

    // Apply returning-client discount if applicable
    char returningAnswer;
    std::cout << "Is this a returning client? (y/n): ";
    std::cin >> returningAnswer;
    if (returningAnswer == 'y' || returningAnswer == 'Y') {
        st.setPrice(price, true);
        std::cout << "\n=== Returning Client Info ===" << std::endl;
        std::cout << st.getInfo(true) << std::endl;
    }

    // Apply surcharge for sessions over 60 minutes if applicable
    char over60Answer;
    std::cout << "Apply over-60-minutes surcharge? (y/n): ";
    std::cin >> over60Answer;
    if (over60Answer == 'y' || over60Answer == 'Y') {
        st.setPrice(true, price);
        std::cout << "\n=== Over-60-Minutes Info ===" << std::endl;
        std::cout << st.getInfo(true) << std::endl;
    }

    return 0;
}
