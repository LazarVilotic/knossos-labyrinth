#include "ObradaDatoteka.h"
#include <ctime>
#include <iomanip>
#include <cstdlib>


ObradaDatoteka::ObradaDatoteka(const std::string& putanjaDatoteke) : putanjaDatoteke(putanjaDatoteke) {}

//salje se poruka kao parametar da se zna ko je pobedio ili da li je korisnik prekinuo igru
// otvara se fajl, upisuje vreme pa poruka i zatvara se datoteka
void ObradaDatoteka::upisiRezultat(const std::string& rezultat) {
    std::ofstream datoteka(putanjaDatoteke, std::ios::app);
    if (!datoteka) { //proverava se da li se datoteka otvorila
        std::cerr << "Greška: Ne mogu da otvorim datoteku " << putanjaDatoteke << std::endl;
        return;
    }

    std::time_t trenutnoVreme = std::time(nullptr);
    std::tm lokalnoVreme;
    localtime_s(&lokalnoVreme, &trenutnoVreme);

    datoteka << "Datum i vreme: " << std::put_time(&lokalnoVreme, "%Y-%m-%d %H:%M:%S") << std::endl;
    datoteka << "Rezultat igre: " << rezultat << std::endl;
    datoteka.close();
}

//uzima dinamicku matricu, broj redova i broj kolona, otvara se fajl i samo prolazi kroz matricu i njeni elementi se upisuju
void ObradaDatoteka::upisiMatricu(char** matrica, int redovi, int kolone) {
    std::ofstream datoteka(putanjaDatoteke, std::ios::app);
    if (!datoteka) { //proverava se da li se datoteka otvorila
        std::cerr << "Greška: Ne mogu da otvorim datoteku " << putanjaDatoteke << std::endl;
        return;
    }
    datoteka << "Matrica lavirinta:" << std::endl;
    for (int i = 0; i < redovi; ++i) {
        for (int j = 0; j < kolone; ++j) {
            datoteka << matrica[i][j] << ' ';
        }
        datoteka << std::endl;
    }
    datoteka.close();
    std::exit(0);
}

