#include <iostream>
 #include <fstream>
 #include <string>
 #include <vector>
 #include <cstdlib>
 #include <ctime>
 #include <iomanip>
 #include <algorithm>
 #include "data.h"
#include "functions.h"
#include <list>

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    char dataChoice;
    std::cout << "Norite duomenis ivesti ranka (R), nuskaityti is failo (F), ar sugeneruoti atsitiktinius duomenis (G)? ";
    std::cin >> dataChoice;

    if (dataChoice == 'R' || dataChoice == 'r') {
        std::vector<Studentas> studentai;
        loadDataFromManualInput(studentai);
        GalutinisBalas(studentai);
        displayTable(studentai);
        
        
    } else if (dataChoice == 'F' || dataChoice == 'f') {
        std::vector<Studentas> studentai;
        std::vector<Studentas> nuskriaustukai;
        std::vector<Studentas> kietiakai;
        std::string filename;
        std::cout << "Iveskite failo pavadinima: ";
        std::cin >> filename;
        try {
            processStudentDataAndWriteToFile(filename);
            loadData(studentai, filename);
            GalutinisBalas(studentai);
            displayTable(studentai);
            
            
        } catch (const std::ifstream::failure& e) {
            std::cerr << "Error: Nepavyko atidaryti failo." << std::endl;
            return 1;
        }
    } else if (dataChoice == 'G' || dataChoice == 'g') {
         {
            std::vector<int> recordSizes = {1000, 10000, 100000, 1000000, 10000000};
            int repetitions = 5;

            for (int size : recordSizes) {
                std::string filename = "studentai_" + std::to_string(size) + ".txt";

                generateAndWriteStudentRecords(filename, size);
                processStudentData(filename, size, repetitions);
            }
        
        } 
    }

    return 0;
}



