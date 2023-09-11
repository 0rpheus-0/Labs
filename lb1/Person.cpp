#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> 
#include "D:\Proga\Function\Functions.h"
#include "Person.h"
#include "Date.h"

Person::Person() {
	name = "Mister X";
	post = "medical worker";
	salare = 300;
}

void Person::Input() {
	std::cout << "Enter name :\t";
	std::getline(std::cin, name, '\n');

	std::cout << "Enter date of birth :\n";
	dateOfBirth.Input();

	std::cout << "Enter post :\t";
	std::getline(std::cin, post, '\n');

	std::cout << "Enter salare :\t";
	while (!(std::cin >> salare) || std::cin.get() != '\n' || salare <= 0) {
		setConsoleColor(black, red);
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Error! Please enter the correct data" << std::endl;
		setConsoleColor(black, white);
	}
}

std::string Person::GetName() {
	return name;
}

void Person::Change() { 
	int change;
	std::cout << "Want to change?\n1)Name\n2)Date of birt\n3)Post\n4)Salare\n";
	while (!(std::cin >> change) || std::cin.get() != '\n' || change <= 0 || change > 4) {
		setConsoleColor(black, red);
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Error! Please enter the correct data" << std::endl;
		setConsoleColor(black, white);
	}

	switch (change)
	{
	case 1:
		std::cout << "Enter name :\t";
		std::getline(std::cin, name, '\n');
		break;
	case 2:
		std::cout << "Enter date of birth :\n";
		dateOfBirth.Input();
		break;
	case 3:
		std::cout << "Enter post :\t";
		std::getline(std::cin, post, '\n');
		break;
	case 4:
		std::cout << "Enter salare :\t";
		while (!(std::cin >> salare) || std::cin.get() != '\n' || salare <= 0) {
			setConsoleColor(black, red);
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Error! Please enter the correct data" << std::endl;
			setConsoleColor(black, white);
		}
		break;
	}
}

void Person::ReadFile(std::ifstream& fin) {
	char temp;
	fin >> temp;
	fin.seekg(-1, std::ios::cur);
	std::getline(fin, name, '\n');
	dateOfBirth.ReadFile(fin);
	fin >> temp;
	fin.seekg(-1, std::ios::cur);
	std::getline(fin, post, '\n');
	fin >> salare;
}

void Person::SaveFile(std::ofstream& fout){
	fout << name << "\n";
	dateOfBirth.SaveFile(fout);
	fout << post << "\n";
	fout << salare << "\n";
}

void Person::Print() {
	std::cout << "_______________________________________\n";
	std::cout << "|Name : " << std::setw(30) << name << "|\n";
	std::cout << "|Date of birth : ";
	dateOfBirth.Output();
	std::cout << "|Post : " << std::setw(30) << post << "|\n";
	std::cout << "|Salare : " << std::setw(27) << salare << "$|\n";
	std::cout << "|_____________________________________|\n";
}