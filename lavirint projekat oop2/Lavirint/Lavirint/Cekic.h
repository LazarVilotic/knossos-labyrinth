#pragma once
#ifndef CEKIC_H
#define CEKIC_H
#include "Predmet.h"

class Cekic : public Predmet {

public:
	Cekic(int trajanje, bool aktivan);
	void aktivirajEfekat(int trenutniPotez) override;
	Cekic();
	int getTrajanje();
	bool getAktivan();
	void setTrajanje(int trajanje);
	void setAktivan(bool status);
};


#endif
