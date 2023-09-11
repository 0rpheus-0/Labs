#include <iostream>
#include <string>
#include <fstream> 
#include "D:\Proga\Function\Functions.h"
#include "Date.h"
#include "List.h"
#include "Person.h"


int main()
{
    List hospital;
    bool repead = true;
    while (repead) {
        setConsoleColor(black, green);
        std::cout << "1) Add to the beginning 2) Add to the end\n3) Search by name 4) Change by name\n5) Delete from the beginning 6) Delete from the end\n7) Delete by name 8) Read the file accordingly\n9) Save to a file 10) View the list\n11)Exit\n";
        setConsoleColor(black, white);

        int change;
        while (!(std::cin >> change) || std::cin.get() != '\n' || change <= 0 || change > 11) {
            setConsoleColor(black, red);
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Error! Please enter the correct data" << std::endl;
            setConsoleColor(black, white);
        }

        switch (change) {
        case 1: {
            Person temp;
            temp.Input();
            hospital.InsertFront(temp);
            break;
        }
        case 2: {
            Person temp;
            temp.Input();
            hospital.InsertBack(temp);
            break;
        }
        case 3: {
            std::cout << "Enter name :\t";
            std::string key;
            std::getline(std::cin, key, '\n');
            hospital.FindByKey(key);
            break;
        }
        case 4: {
            std::cout << "Enter name :\t";
            std::string key;
            std::getline(std::cin, key, '\n');
            hospital.ChangeByKey(key);
            break;
        }
        case 5:
            hospital.RemovFromFront();
            break;
        case 6:
            hospital.RemovFromBack();
            break;
        case 7: {
            std::cout << "Enter name :\t";
            std::string key;
            std::getline(std::cin, key, '\n');
            hospital.RemovByKey(key);
            break;
        }
        case 8:
            hospital.ReadFile();
            break;
        case 9:
            hospital.SaveFile();
            break;
        case 10:
            hospital.Print();
            break;
        case 11:
            repead = false;
            break;
        }
    }
}


