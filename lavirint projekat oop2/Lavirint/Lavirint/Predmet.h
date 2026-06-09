#pragma once
#ifndef PREDMET_H
#define PREDMET_H

class Predmet {
protected:
    int trajanje;
    bool aktivan;
public:
    Predmet(int trajanje, bool aktivan);
    virtual void aktivirajEfekat(int trenutniPotez) = 0;
    int getTrajanje();
    bool getAktivan();
    void setTrajanje(int trajanje);
    void setAktivan(bool status);
    Predmet();

};


#endif
