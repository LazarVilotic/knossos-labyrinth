#include "Lavirint.h"
#include "Igra.h"
#include <iostream>
#include "Predmet.h"
#include <filesystem>
#include <fstream>
#include <string>

int main() {
    int redovi, kolone, brojPredmeta;


    std::string filePath = "C:\\Users\\Korisnik\\Desktop\\a.txt";
    std::ifstream inputFile(filePath);

    // Provera da li je fajl uspešno otvoren
    if (!inputFile.is_open()) {
        std::cerr << "Greška prilikom otvaranja fajla: " << filePath << std::endl;
        return 1;
    }
    // Unos dimenzija i broja predmeta sa tastature
    std::cout << "Unesite broj redova (min 15): ";
    std::cin >> redovi;

    std::cout << "Unesite broj kolona (min 15): ";
    std::cin >> kolone;

    std::cout << "Unesite broj predmeta (min 3): ";
    std::cin >> brojPredmeta;

    // Provera validnosti unosa
    if (redovi <= 15 || kolone <= 15 || brojPredmeta < 3) {
        std::cerr << "Greska: Dimenzije moraju biti vece od 15, a broj predmeta veci od 3." << std::endl;
        return 1;
    }

    //try block u kom se pravi lavirint, igra, stavlja se potez na 1, i u while petlji idu metode igre, gde se smenjuju potez robota i minotaura
    //dok ne dodje do kraja igre, koji je obezbedjen u klasi ObradaDatoteka
    try {
        std::srand(std::time(0));
        Lavirint lavirint(redovi, kolone, brojPredmeta);
        lavirint.generisiMatricu();
        Igra igra;
        igra.setPotez(1);
        while (true) {
            igra.potezRobota(lavirint);
            igra.potezMinotaur(lavirint);

        }
    }
    catch (const std::exception& e) { //provera da li je greska uhvacena
        std::cerr << "Greska: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

