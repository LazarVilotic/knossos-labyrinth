
#include "Mac.h"
#include "Predmet.h"

Mac::Mac(int trajanje, bool aktivan) :Predmet(trajanje, aktivan) {}

//nasledjenja funkcija iz nadklase Predmet za stavljanje aktivnosti na true (u igri) i trajanje na 3 poteza
void Mac::aktivirajEfekat(int trenutniPotez) {
	aktivan = true;
	trajanje = trenutniPotez + 4;
}
Mac::Mac() : Predmet(0, false) {}

void Mac::setAktivan(bool aktivanNovo) {
	aktivan = aktivanNovo;
}

void Mac::setTrajanje(int trajanjeNovo) {
	trajanje = trajanjeNovo;
}

bool Mac::getAktivan() {
	return aktivan;
}


int Mac::getTrajanje() {
	return trajanje;
}
