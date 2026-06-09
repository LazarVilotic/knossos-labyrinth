#include "Predmet.h"
#include "Igra.h" 


Predmet::Predmet(int trajanje, bool aktivan) : trajanje(trajanje), aktivan(aktivan) {}


Predmet::Predmet() : trajanje(0), aktivan(false) {}


void Predmet::setAktivan(bool aktivanNovo) {
    aktivan = aktivanNovo;
}

void Predmet::setTrajanje(int trajanjeNovo) {
    trajanje = trajanjeNovo;
}

bool Predmet::getAktivan() {
    return aktivan;
}

int Predmet::getTrajanje() {
    return trajanje;
}

// aktivirajEfekat nije implementirana jer je virtuelna funkcija koja se implementira u klasama naslednicama