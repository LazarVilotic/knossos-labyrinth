
#include "Cekic.h"
#include "Predmet.h"

Cekic::Cekic(int trajanje, bool aktivan):Predmet(trajanje, aktivan){}

//nasledjenja funkcija iz nadklase Predmet za stavljanje aktivnosti na true (u igri) i trajanje na 3 poteza
void Cekic::aktivirajEfekat(int trenutniPotez) { 
	aktivan = true;
	trajanje = trenutniPotez + 4;
}
Cekic::Cekic() : Predmet(0, false) {}

void Cekic::setAktivan(bool aktivanNovo) {
	aktivan = aktivanNovo;
}

void Cekic::setTrajanje(int trajanjeNovo) {
	trajanje = trajanjeNovo;
}

bool Cekic::getAktivan() {
	return aktivan;
}


int Cekic::getTrajanje() {
	return trajanje;
}