
#include "Stit.h"
#include "Predmet.h"
Stit::Stit(int trajanje, bool aktivan) :Predmet(trajanje, aktivan) {}

//nasledjenja funkcija iz nadklase Predmet za stavljanje aktivnosti na true (u igri) i trajanje na 3 poteza
void Stit::aktivirajEfekat(int trenutniPotez) {
	aktivan = true;
	trajanje = trenutniPotez + 4;
}
Stit::Stit() : Predmet(0, false) {}

void Stit::setAktivan(bool aktivanNovo) {
	aktivan = aktivanNovo;
}

void Stit::setTrajanje(int trajanjeNovo) {
	trajanje = trajanjeNovo;
}

bool Stit::getAktivan() {
	return aktivan;
}


int Stit::getTrajanje() {
	return trajanje;
}