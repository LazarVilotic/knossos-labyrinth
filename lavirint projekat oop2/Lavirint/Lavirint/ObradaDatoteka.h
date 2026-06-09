#pragma once
#ifndef OBRADA_DATOTEKA_H
#define OBRADA_DATOTEKA_H

#include <string>
#include <fstream>
#include <iostream>

class ObradaDatoteka {
private:
    std::string putanjaDatoteke;

public:
    ObradaDatoteka(const std::string& putanjaDatoteke);
    void upisiRezultat(const std::string& rezultat);
    void upisiMatricu(char** matrica, int redovi, int kolone);

};

#endif 