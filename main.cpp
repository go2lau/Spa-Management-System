#include <iostream>
#include <string>
#include <limits>
#include "specialTreatment.h"

int main() {
    std::cout << "Welcome to the Special Treatment Scheduler" << std::endl;

    // User inputs for duration, base price, and time
    float duration;
    std::cout << "Enter duration (in minutes): ";
    std::cin >> duration;

    float price;
    std::cout << "Enter base price: ";
    std::cin >> price;

    // Clear input buffer before reading a line
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string time;
    std::cout << "Enter time (e.g., 14:00): ";
    std::getline(std::cin, time);

    // Construct SpecialTreatment; serviceName is fixed inside the class
    SpecialTreatment st("", duration, price, time);

    // Display basic info using overridden getInfo()
    std::cout << "\n=== Basic Treatment Info ===" << std::endl;
    std::cout << st.getInfo(false) << std::endl;

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
