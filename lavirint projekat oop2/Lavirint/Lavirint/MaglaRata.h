#pragma once
#ifndef MAGLA_RATA_H
#define MAGLA_RATA_H
#include "Predmet.h"

class MaglaRata : public Predmet {

public:
	MaglaRata(int trajanje, bool aktivan);
	MaglaRata();
	void aktivirajEfekat(int trenutniPotez) override;
	int getTrajanje();
	bool getAktivan();
	void setTrajanje(int trajanje);
	void setAktivan(bool status);
	
};


#endif
