#include <iostream>
#include <fstream> 
#include <iomanip> 
#include "D:\Proga\Function\Functions.h"
#include "Date.h"

Date::Date() {
    day = 1;
    month = 1;
    year = 1990;
}

void Date::Input() {
    std::cout << "Year :\t";
    
    while (!(std::cin>>year) || std::cin.get() != '\n' || year <= 0) {
        setConsoleColor(black, red);
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Error! Please enter the correct data" << std::endl;
        setConsoleColor(black, white);
    }

    std::cout << "Month :\t";
    while (!(std::cin >> month) || std::cin.get() != '\n' || month <= 0 || month > 12) {
        setConsoleColor(black, red);
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Error! Please enter the correct data" << std::endl;
        setConsoleColor(black, white);
    }

    int fy = 0;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                fy = 1;
            else
                fy = 0;
        }
        else
            fy = 1;
    }
    else
        fy = 0;

    int fm = 0;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        fm = 1;
    if (month == 2)
        fm = 2;

    std::cout << "Day :\t";
    while (!(std::cin >> day) || std::cin.get() != '\n' || day <= 0 || (fm == 0 && day > 31) || (fm == 1 && day > 30) || (fy == 1 && fm == 2 && day > 29) || (fy == 0 && fm == 2 && day > 28)) {
        setConsoleColor(black, red);
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Error! Please enter the correct data" << std::endl;
        setConsoleColor(black, white);
    }
}

void Date::ReadFile(std::ifstream& fin) {
    fin >> day >> month >> year;
}

void Date::SaveFile(std::ofstream& fout) {
    fout << day << " " << month << " " << year << "\n";
}

void Date::Output() {
    std::cout << std::setw(12) << day << "." << std::setw(2) << month << "." << std::setw(5) << year << "|\n";
}