#pragma once
#include <string>
#include "Date.h"


class Person {
	std::string name, post;
	Date dateOfBirth;
	int salare;
public:
	Person();

	void Input();
	std::string GetName();
	void Change();
	void ReadFile(std::ifstream& fin);
	void SaveFile(std::ofstream& fout);
	void Print();
};

