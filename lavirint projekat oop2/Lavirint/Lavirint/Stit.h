#pragma once
#ifndef STIT_H
#define STIT_H
#include "Predmet.h"

class Stit : public Predmet {

public:
	Stit(int trajanje, bool aktivan);
	Stit();
	void aktivirajEfekat(int trenutniPotez) override;
	int getTrajanje();
	bool getAktivan();
	void setTrajanje(int trajanje);
	void setAktivan(bool status);

};

#endif
