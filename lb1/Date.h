#pragma once

class Date {
        int day;
        int month;
        int year;
public:
    Date();

    void Input();
    void ReadFile(std::ifstream& fin);
    void SaveFile(std::ofstream& fout);
    void Output();
};

