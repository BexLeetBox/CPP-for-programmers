#include <iostream>
#include <fstream>



void read_temperatures(double temperatures[], int length);

void read_temperatures(double temperatures[], int length) {
    const char filename[] = "../tempFile.dat"; // If running from TempB/build

    std::ifstream file;
    file.open(filename);

    if (!file) {
        std::cout << "Error opening file" << std::endl;
        exit(EXIT_FAILURE); // Exits program
    }

    std::cout << "Temperatures read from file: " << std::endl;
    /**while (file >> number) {
            temperatures[i] = number;
            std::cout << temperatures[i] << std::endl;
            i++;
        }
        */
    for (int i = 0; i < length; i++) {

        if (!(file >> temperatures[i])) {
            std::cout << "Error reading temperature " << i + 1 << std::endl;
            break;
        }
        std::cout << "Temperature " << i + 1 << ": " << temperatures[i] << std::endl;
    }
    }


int main() {
    double temperatures[5];
    const int length = 5;
    read_temperatures(temperatures, length);

    int under10 = 0, between10And20 = 0, over20 = 0;

    for (double temperature : temperatures) {

        if (temperature < 10.0) {
            under10++;
        } else if (temperature >= 10.0 && temperature <= 20.0) {
            between10And20++;
        } else {
            over20++;
        }
    }

    std::cout << "Antall under 10 er " << under10 << std::endl;
    std::cout << "Antall mellom 10 og 20 er " << between10And20 << std::endl;
    std::cout << "Antall over 20 er " << over20 << std::endl;

    return 0;
}
