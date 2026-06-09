#include "MaglaRata.h"
#include "Predmet.h"


MaglaRata::MaglaRata(int trajanje, bool aktivan) :Predmet(trajanje, aktivan) {}
MaglaRata::MaglaRata() : Predmet(0, false) {}

//nasledjenja funkcija iz nadklase Predmet za stavljanje aktivnosti na true (u igri) i trajanje na 3 poteza
void MaglaRata::aktivirajEfekat(int trenutniPotez) {
	aktivan = true;
	trajanje = trenutniPotez + 4;
}

void MaglaRata::setAktivan(bool aktivanNovo) {
	aktivan = aktivanNovo;
}

void MaglaRata::setTrajanje(int trajanjeNovo) {
	trajanje = trajanjeNovo;
}

bool MaglaRata::getAktivan() {
	return aktivan;
}


int MaglaRata::getTrajanje() {
	return trajanje;
}