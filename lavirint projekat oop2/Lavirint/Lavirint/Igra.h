#pragma once
#ifndef IGRA_H
#define IGRA_H
#include "Lavirint.h"
#include "Stit.h"
#include "Mac.h"
#include "MaglaRata.h"
#include "Cekic.h"
#include "Predmet.h"

class Igra {

private:
	int potez;
	MaglaRata MaglaRata;
	Mac Mac;
	Stit Stit;
	Cekic Cekic;

public:
	void potezRobota(Lavirint& lavirint);
	void potezMinotaur(Lavirint& lavirint);
	Igra();
	void postaviNasumicniPredmet();
	int getPotez();
	void proveriTrajanjePredmeta();
	void setPotez(int broj);
};

#endif