#pragma once
#ifndef LAVIRINT_H
#define LAVIRINT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Lavirint {

private:
	int redovi, kolone, brojPredmeta;
	char** matrica;

public:
	Lavirint(int redovi, int kolone, int broj_predmeta);
	~Lavirint();
	void napraviPraznuMatricu();
	void isprazniMatricu();
	void napraviSpoljasnjeZidove();
	void napraviUnutrasnjeZidove();
	void postaviUlazIzlaz();
	void postaviPredmete();
	void postaviMinotaura();
	void generisiMatricu();
	void ispisiMatricu();
	char** dohvatiMatricu();
	int xMinotaura();
	int yMinotaura();
	int xRobota();
	int yRobota();
	bool imaProlazPored(int x, int y);
	bool validanLavirint() const;
	void resetujMatricu();
	char vrednostNaPoziciji(int x, int y) const;
	void postaviVrednost(int x, int y, char znak);
	int getRed();
	int getKolona();
	void ispisSaMaglomRata();

};

#endif