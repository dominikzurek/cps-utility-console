/*
 * CPS Utility Console - Main Entry Point
 * Author: Dominik Żurek
 */

#include "../include/menu.hpp"
#include <iostream>

int main() {
    while (true) {
        cps::displayMenu();
        std::cout << "\nSelect option: ";
        std::string choice;
        std::getline(std::cin, choice);
        if (!cps::handleChoice(choice)) break;
    }
    return 0;
}