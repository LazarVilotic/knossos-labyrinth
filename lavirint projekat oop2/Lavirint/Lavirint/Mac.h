#pragma once
#ifndef MAC_H
#define MAC_H
#include "Predmet.h"


class Mac : public Predmet {

public:
	Mac(int trajanje, bool aktivan);
	Mac();
	void aktivirajEfekat(int trenutniPotez) override;
	int getTrajanje();
	bool getAktivan();
	void setTrajanje(int trajanje);
	void setAktivan(bool status);

};

#endif
