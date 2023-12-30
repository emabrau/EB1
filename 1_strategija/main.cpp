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
    char containerChoice;
    std::cout << "Norite duomenis ivesti ranka (R), nuskaityti is failo (F), ar sugeneruoti atsitiktinius duomenis (G)? ";
    std::cin >> dataChoice;

    if (dataChoice == 'R' || dataChoice == 'r') {
        std::vector<Studentas> studentai;
        loadDataFromManualInput(studentai);
        GalutinisBalas(studentai);
        displayTable(studentai);
    } else if (dataChoice == 'F' || dataChoice == 'f') {
        std::vector<Studentas> studentai;
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
        std::cout << "Pasirinkite duomenu struktura (V - Vektorius, L - Listas): ";
        std::cin >> containerChoice;

        if (containerChoice == 'V' || containerChoice == 'v') {
            std::vector<int> recordSizes = {1000, 10000, 100000, 1000000, 10000000};
            int repetitions = 5;

            for (int size : recordSizes) {
                std::string filename = "studentai_" + std::to_string(size) + ".txt";

                generateAndWriteStudentRecordsV(filename, size);
                processStudentDataV(filename, size, repetitions);
            }
        } else if (containerChoice == 'L' || containerChoice == 'l') {
            std::list<int> recordSizes = {1000, 10000, 100000, 1000000, 10000000};
            int repetitions = 5;

            for (int size : recordSizes) {
                std::string filename = "studentai_" + std::to_string(size) + ".txt";

                generateAndWriteStudentRecordsL(filename, size);
                processStudentDataL(filename, size, repetitions);
            }
        } else {
            std::cout << "Netinkamas pasirinkimas. Prasome pairinkti 'V' arba 'L'." << std::endl;
            return 1;
        }
    } else {
        std::cout << "Netinkamas pasirinkimas. Prasome pairinkti 'V', 'L' arba 'G'." << std::endl;
        return 1;
    }

    return 0;
}

