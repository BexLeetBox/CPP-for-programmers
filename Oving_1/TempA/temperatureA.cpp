#include <iostream>

int main() {
    const int numTemperatures = 5;
    int under10 = 0, between10And20 = 0, over20 = 0;

    std::cout << "Du skal skrive inn " << numTemperatures << " temperaturer." << std::endl;
    double temperature;
    for (int i = 0; i < numTemperatures; ++i) {

        std::cout << "Temperatur nr " << i + 1 << ": ";
        std::cin >> temperature;

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
