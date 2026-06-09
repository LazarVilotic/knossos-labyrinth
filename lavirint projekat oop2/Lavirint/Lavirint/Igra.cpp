#include "Lavirint.h"
#include "Igra.h"
#include <iostream>
#include <cstdlib>  // Za rand() i srand()
#include <ctime>    // Za time()

#include "Stit.h"
#include "Mac.h"
#include "MaglaRata.h"
#include "Cekic.h"
#include "Predmet.h"
#include "ObradaDatoteka.h"


Igra::Igra(){}

// proverava da li je trajanje == potez za sve efekte predmeta, jer se u aktivaciji uzme trenutni potez i doda mu se 4 da traje 3 poteza
void Igra::proveriTrajanjePredmeta() {

    if (MaglaRata.getTrajanje() == potez) {
        MaglaRata.setAktivan(false);
    }

    if (Mac.getTrajanje() == potez) {
        Mac.setAktivan(false);
    }

    if (Cekic.getTrajanje() == potez) {
        Cekic.setAktivan(false);
    }

    if (Stit.getTrajanje() == potez) {
        Stit.setAktivan(false);
    }
}
//ova metoda je dugacka pa cu je redom kroz kod objasniti
void Igra::potezRobota(Lavirint& lavirint) {
    ObradaDatoteka upisiUFajl("C:\\Users\\Korisnik\\Desktop\\a.txt");
    std::cout << "Odaberite gde hocete da se pomerite: " << std::endl;
    std::cout << "W za gore, A za levo, S za dole, D za desno ili Q za zavrsetak igre: " << std::endl;
    char upis;

    proveriTrajanjePredmeta(); //prvo se proveri trajanje efekata predmeta od gore
    while (true) {
        
        if (MaglaRata.getAktivan() == true) { //ako je magla rata aktivna idi ispis za maglu rata, u suprotnom ide normalan ispis
            lavirint.ispisSaMaglomRata();
        }
        else{
            lavirint.ispisiMatricu();
        }

        std::cin >> upis;

        // proverite da li je korisnik uneo vise od jednog karaktera
        if (std::cin.peek() != '\n') {
            std::cout << "Nevalidan unos! Molimo unesite samo jedan karakter." << std::endl;
            // ocistite ulazni bafer da biste sprecili ponovni unos.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // pretvori unos u velika slova ako je potrebno
        upis = toupper(upis);

        int x = lavirint.xRobota();
        int y = lavirint.yRobota();

        // Koordinate nove pozicije
        int noviX = x, noviY = y;

        if (upis == 'W') { //provera unosa
            noviX = x - 1;
        }
        else if (upis == 'A') {
            noviY = y - 1;
        }
        else if (upis == 'S') {
            noviX = x + 1;
        }
        else if (upis == 'D') {
            noviY = y + 1;
        }
        else if (upis == 'Q') {
            std::cout << "Korisnik je prekinuo igru.";
            upisiUFajl.upisiRezultat("Korisnik je prekinuo igru.");
            upisiUFajl.upisiMatricu(lavirint.dohvatiMatricu(), lavirint.getRed(), lavirint.getKolona());
            
        }
        else {
            std::cout << "Nevalidan unos!" << std::endl;
            continue;
        }

        // ako je unos validan prvo se proverava da li je korisnik na izlazu, ako jeste igra se zavrsava
        if (lavirint.vrednostNaPoziciji(noviX, noviY) == 'I') { 
            std::cout << "Robot je uspesno izasao iz lavirinta.";
            upisiUFajl.upisiRezultat("Robot je uspesno izasao iz lavirinta.");
            upisiUFajl.upisiMatricu(lavirint.dohvatiMatricu(), lavirint.getRed(), lavirint.getKolona());
        }

        //onda se proverava da li je korisnik stao na predmet, ako jeste, ide funkcija koja nasumicno daje jedan od efekata 
        if (lavirint.vrednostNaPoziciji(noviX, noviY) == 'P') {
            postaviNasumicniPredmet();
        }

        //onda ako je mac aktivan u proveru uslova za pomeranje se dodaje i minotaur kog dole u pomeranju bez aktivnih efekata nece biti
        // proverava se da korisnik ne izlazi van opsega (zbog cekica) i da li staje na dozvoljena polja
        if (Mac.getAktivan() == true) {
            if (noviX >= 0 && noviX < lavirint.getRed() &&
                noviY >= 0 && noviY < lavirint.getKolona() &&
                (lavirint.vrednostNaPoziciji(noviX, noviY) == '.' ||
                    lavirint.vrednostNaPoziciji(noviX, noviY) == 'P' || lavirint.vrednostNaPoziciji(noviX,noviY)== 'M')) {

                // Pomeranje robota
                lavirint.postaviVrednost(noviX, noviY, 'R');
                lavirint.postaviVrednost(x, y, '.');
                break;
            }
            else {
                std::cout << "Nevalidan potez!" << std::endl;
            }
        }
        //kod cekcia je umesto minotaura zid dodat kao mesto na koje moze da se robot pomeri
        if (Cekic.getAktivan() == true) {
            if (noviX >= 0 && noviX < lavirint.getRed() &&
                noviY >= 0 && noviY < lavirint.getKolona() &&
                (lavirint.vrednostNaPoziciji(noviX, noviY) == '.' ||
                    lavirint.vrednostNaPoziciji(noviX, noviY) == 'P' || lavirint.vrednostNaPoziciji(noviX, noviY) == '#')) {

                // Pomeranje robota
                lavirint.postaviVrednost(noviX, noviY, 'R');
                lavirint.postaviVrednost(x, y, '.');
                break;
            }
            else {
                std::cout << "Nevalidan potez!" << std::endl;
            }
        }
        // Provera granica i validnosti poteza bez ikakvih efekata
        if (noviX >= 0 && noviX < lavirint.getRed() &&
            noviY >= 0 && noviY < lavirint.getKolona() &&
            (lavirint.vrednostNaPoziciji(noviX, noviY) == '.' ||
                lavirint.vrednostNaPoziciji(noviX, noviY) == 'P')) {

            // Pomeranje robota
            lavirint.postaviVrednost(noviX, noviY, 'R');
            lavirint.postaviVrednost(x, y, '.');
            break;
        }
        else {
            std::cout << "Nevalidan potez!" << std::endl;
        }
    }
}

void Igra::potezMinotaur(Lavirint& lavirint) {
    ObradaDatoteka upisiUFajl("C:\\Users\\Korisnik\\Desktop\\a.txt");
    int xMinotaura = lavirint.xMinotaura();
    int yMinotaura = lavirint.yMinotaura();
    int xRobota = lavirint.xRobota();
    int yRobota = lavirint.yRobota();

    // Koraci za pomeranje (gore, dole, levo, desno)
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    // Proveri da li je Robot pored Minotaura
    for (int i = 0; i < 4; i++) {
        int nx = xMinotaura + dx[i];
        int ny = yMinotaura + dy[i];
        if (nx == xRobota && ny == yRobota && Stit.getAktivan() == false) {
            // Minotaur ide ka Robotu ako su jedan do drugog i ako stit nije aktivan
            lavirint.postaviVrednost(nx, ny, 'M');
            lavirint.postaviVrednost(xMinotaura, yMinotaura, '.');
            std::cout << "Minotaur je unistio robota.";
            upisiUFajl.upisiRezultat("Minotaur je unistio robota.");
            upisiUFajl.upisiMatricu(lavirint.dohvatiMatricu(), lavirint.getRed(), lavirint.getKolona());
        }
        //ako je pored i stit je aktivan minotaur ide na nasumicno polje, ali bez polja na kom je robot
        else if (nx == xRobota && ny == yRobota && Stit.getAktivan() == true) { 
            while (true) {
                int randomIndex = rand() % 4; // Nasumični indeks za kretanje
                int noviX = xMinotaura + dx[randomIndex];
                int noviY = yMinotaura + dy[randomIndex];

                // Proveri granice i validnost poteza
                if (noviX >= 0 && noviX < lavirint.getRed() && 
                    noviY >= 0 && noviY < lavirint.getKolona() && 
                    (lavirint.vrednostNaPoziciji(noviX, noviY) == '.' ||
                        lavirint.vrednostNaPoziciji(noviX, noviY) == 'P')) {
                    if(noviX != xRobota&& noviY!=yRobota){                    // Minotaur se pomera
                        lavirint.postaviVrednost(noviX, noviY, 'M');
                        lavirint.postaviVrednost(xMinotaura, yMinotaura, '.');
                        potez++;
                        break;
                    }

                }
            }

        }
    }

    // Ako Robot nije pored i nema stit, nasumično se pomera
    while (true) {
        int randomIndex = rand() % 4; // Nasumični indeks za kretanje
        int noviX = xMinotaura + dx[randomIndex];
        int noviY = yMinotaura + dy[randomIndex];

        // Proveri granice i validnost poteza
        if (noviX >= 0 && noviX < lavirint.getRed() &&
            noviY >= 0 && noviY < lavirint.getKolona() &&
            (lavirint.vrednostNaPoziciji(noviX, noviY) == '.' ||
                lavirint.vrednostNaPoziciji(noviX, noviY) == 'P')) {

            // Minotaur se pomera
            lavirint.postaviVrednost(noviX, noviY, 'M');
            lavirint.postaviVrednost(xMinotaura, yMinotaura, '.');
            potez++;
            break;
        }
    }
}



void Igra::postaviNasumicniPredmet(){        // Postavljamo generator slučajnih brojeva
    srand(time(0));  // Inicijalizacija generatora na osnovu trenutnog vremena

    // Nasumično odabrati jedan broj između 0 i 3
    int random = rand() % 4;

    // Na osnovu broja postaviti odgovarajući boolean na true
    switch (random) {
    case 0:
        MaglaRata.aktivirajEfekat(getPotez());
        std::cout << "Predmet je magla rata!" << std::endl;
        break;
    case 1:
        Mac.aktivirajEfekat(getPotez());
        std::cout << "Predmet je mac!" << std::endl;
        break;
    case 2:
        Stit.aktivirajEfekat(getPotez());
        std::cout << "Predmet je stit!" << std::endl;
        break;
    case 3:
        Cekic.aktivirajEfekat(getPotez());
        std::cout << "Predmet je cekic!" << std::endl;
        break;
    }
}

int Igra::getPotez() {
    return potez;
}

void Igra::setPotez(int broj) {
    potez = broj;
}