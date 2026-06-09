#include "Lavirint.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <queue>
#include <chrono>


Lavirint::Lavirint(int redovi, int kolone, int brojPredmeta) : redovi(redovi), kolone(kolone), brojPredmeta(brojPredmeta) {
	if (redovi <= 15 || kolone <= 15 || brojPredmeta < 3) {
		throw std::invalid_argument("Dimenzije moraju biti veće od 15, a broj predmeta veći od 3.");
	}
	napraviPraznuMatricu();
}

Lavirint::~Lavirint() {
	isprazniMatricu();
}

// od prazne matrice, koristi metode da stvori sve objekte dok ne dobije validnu matricu (gde robot mozr doci do izlaza i minotaur nije zarobljen)
void Lavirint::generisiMatricu() {
	//pocetak merenja vremena
	auto pocetak = std::chrono::high_resolution_clock::now();
	while (true) {

		resetujMatricu();

		napraviSpoljasnjeZidove();
		napraviUnutrasnjeZidove();
		postaviUlazIzlaz();
		postaviMinotaura();
		postaviPredmete();

		bool validan = validanLavirint();
		if (validan == true) {
			break;
		}

		

	}
	// Kraj merenja vremena
	auto kraj = std::chrono::high_resolution_clock::now();

	// Izračunaj trajanje u milisekundama
	auto trajanje = std::chrono::duration_cast<std::chrono::milliseconds>(kraj - pocetak).count();

	// Prikaz vremena generisanja lavirinta
	std::cout << "Vreme potrebno za generisanje lavirinta: " << trajanje << " ms" << std::endl;
}

//stavlja sve elemente matrice na . koristi se u generaciji iznad
void Lavirint::resetujMatricu() {
	for (int i = 0; i < redovi; i++) {
		for (int j = 0; j < kolone; j++) {
			matrica[i][j] = '.';  
		}
	}
}

//pravi prvobitnu matricu kroz dve for petlje i sve elemente postavlja na .
void Lavirint::napraviPraznuMatricu() {
	matrica = new char* [redovi];

	for (int i =0 ; i < redovi;i++){
		matrica[i] = new char[kolone];
		for(int j=0;j<kolone;j++){
			matrica[i][j] = '.';
		}
	 }

}

void Lavirint::isprazniMatricu() {
	for (int i = 0;i < redovi;i++) {
		delete[] matrica[i];
	}
	delete[] matrica;
}
//stavlja zidove po obodima matrice
void Lavirint::napraviSpoljasnjeZidove() {
	for (int i = 0; i < redovi; ++i) {
		for (int j = 0; j < kolone; ++j) {
			if (i == 0 || i == redovi - 1 || j == 0 || j == kolone - 1) {
				matrica[i][j] = '#';
			}
		}
	}
}

//broj zidova je redovi+kolone i to puta dva, dalje se stavljaju na nasumicna mesta gde su .
void Lavirint::napraviUnutrasnjeZidove() {
	int brojZidova = 2 * (redovi + kolone); 
	while (brojZidova > 0) {
		int x = rand() % (redovi - 2) + 1;
		int y = rand() % (kolone - 2) + 1;
		if (matrica[x][y] == '.') {
			matrica[x][y] = '#';
			brojZidova--;
		}
	}
}

//nasumicno stavlja ulaz u prvi red, a izlaz u poslednji red
void Lavirint::postaviUlazIzlaz() {

	int ulazKolona = rand() % (kolone - 2) + 1;

	matrica[0][ulazKolona] = 'U';
	matrica[1][ulazKolona] = 'R';

	int izlazKolona = rand() % (kolone - 2) + 1;
	matrica[redovi - 1][izlazKolona] = 'I';
}

//isti princip kao kod unutrasnjih zidova, nasummicno se stavljaju na mesto gde je .
void Lavirint::postaviPredmete() {
	int brojPostavljenih = 0;
	while (brojPostavljenih < brojPredmeta) {
		int x = rand() % (redovi - 2) + 1;
		int y = rand() % (kolone - 2) + 1;
		if (matrica[x][y] == '.') {
			matrica[x][y] = 'P';
			brojPostavljenih++;
		}
	}
}
char** Lavirint::dohvatiMatricu() {
	return matrica;
}

void Lavirint::ispisiMatricu(){
	for (int i = 0; i < redovi; ++i) {
		for (int j = 0; j < kolone; ++j) {
			std::cout << matrica[i][j] << ' ';
		}
		std::cout << std::endl;
	}

}

// stavlja minotaura na tacku tako da ima prolaz pored njega i da ne bude u prva tri reda
void Lavirint::postaviMinotaura() {
	while (true) {
		int x = rand() % (redovi - 2) + 1;
		int y = rand() % (kolone - 2) + 1;
		if (matrica[x][y] == '.' && imaProlazPored(x, y) && x>2) {
			matrica[x][y] = 'M';
			break;
		}
	}
}

int Lavirint::xMinotaura() {
	for (int i = 0;i < redovi;i++) {
		for (int j = 0;j < kolone;j++) {
			if (matrica[i][j] == 'M')
				return i;
		}
	}
}

int Lavirint::yMinotaura() {
	for (int i = 0;i < redovi;i++) {
		for (int j = 0;j < kolone;j++) {
			if (matrica[i][j] == 'M')
				return j;
		}
	}
}

int Lavirint::xRobota() {
	for (int i = 0;i < redovi;i++) {
		for (int j = 0;j < kolone;j++) {
			if (matrica[i][j] == 'R')
				return i;
		}
	}
}

int Lavirint::yRobota() {
	for (int i = 0;i < redovi;i++) {
		for (int j = 0;j < kolone;j++) {
			if (matrica[i][j] == 'R')
				return j;
		}
	}
}

//proverava da li su polja oko minotaura (gore, dole, levo, desno) . ako jesu ima prolaz pored
bool Lavirint::imaProlazPored(int x, int y) {
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < redovi && ny >= 0 && ny < kolone && matrica[nx][ny] == '.') {
			return true; 
		}
	}
	return false; 
}

// koriscenjem bfs pretrage proveravamo da li je matrica validna, to jest, da li robot ima put do izlazi, kao i minotaur
bool Lavirint::validanLavirint() const {
	// Koraci kretanja: gore, dole, levo, desno
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	// Dinamicka alokacija matrice "poseceno"
	bool** poseceno = new bool* [redovi];
	for (int i = 0; i < redovi; i++) {
		poseceno[i] = new bool[kolone]();
	}

	// Pronadji robota, Minotaura i izlaz
	int xRobot = -1, yRobot = -1, xMinotaur = -1, yMinotaur = -1, xIzlaza = -1, yIzlaza = -1;
	for (int i = 0; i < redovi; i++) {
		for (int j = 0; j < kolone; j++) {
			if (matrica[i][j] == 'R') {
				xRobot = i;
				yRobot = j;
			}
			if (matrica[i][j] == 'M') {
				xMinotaur = i;
				yMinotaur = j;
			}
			if (matrica[i][j] == 'I') {
				xIzlaza = i;
				yIzlaza = j;
			}
		}
	}

	if (xRobot == -1 || xIzlaza == -1) {
		std::cerr << "Greska: Robot ili izlaz nisu postavljeni." << std::endl;

		// Oslobadjanje memorije pre izlaza
		for (int i = 0; i < redovi; i++) {
			delete[] poseceno[i];
		}
		delete[] poseceno;

		return false;
	}

	// BFS inicijalizacija
	std::queue<std::pair<int, int>> red;
	red.push({ xRobot, yRobot });
	poseceno[xRobot][yRobot] = true;

	// BFS pretraga za robota
	while (!red.empty()) {
		int x = red.front().first;
		int y = red.front().second;
		red.pop();

		// Ako smo stigli do izlaza
		if (x == xIzlaza && y == yIzlaza) {
			// Oslobađanje memorije pre povratka
			for (int i = 0; i < redovi; i++) {
				delete[] poseceno[i];
			}
			delete[] poseceno;

			return true;
		}

		// Proveri sva susedna polja
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// Validacija granica i prolaznosti
			if (nx >= 0 && nx < redovi && ny >= 0 && ny < kolone && !poseceno[nx][ny]) {
				if (matrica[nx][ny] == '.' || matrica[nx][ny] == 'I') {
					poseceno[nx][ny] = true;
					red.push({ nx, ny });
				}
			}
		}
	}

	// Oslobadjanje memorije pre povratka
	for (int i = 0; i < redovi; i++) {
		delete[] poseceno[i];
	}
	delete[] poseceno;

	// Ako smo zavrsili BFS a nismo nasli izlaz, lavirint nije validan
	return false;
}

//vraca vrednost polja na poziciji (x , y)
char Lavirint::vrednostNaPoziciji(int x, int y) const {
	if (x >= 0 && x < redovi && y >= 0 && y < kolone) {
		return matrica[x][y];
	}
	else {
		throw std::out_of_range("Indeksi su van opsega matrice lavirinta.");
	}
}

//postavlja vrednost, ovde char znak, na zadate koordinate x i y
void Lavirint::postaviVrednost(int x, int y, char znak) {
	if (x >= 0 && x < redovi && y >= 0 && y < kolone) {
		matrica[x][y] = znak;
	}
	else {
		throw std::out_of_range("Indeksi su van opsega matrice lavirinta.");
	}
}

int Lavirint::getRed() {
	return redovi;
}

int Lavirint::getKolona() {
	return kolone;
}

void Lavirint::ispisSaMaglomRata() {
	int robotX = xRobota();  // Pozicija robota
	int robotY = yRobota();  // Pozicija robota

	// Definisanje granica 3x3 podmatrice oko robota
	int pocetnaX = robotX - 1;
	int pocetnaY = robotY - 1;

	// Ispisivanje podmatrice 3x3
	for (int i = pocetnaX; i < pocetnaX + 3; i++) {
		for (int j = pocetnaY; j < pocetnaY + 3; j++) {
			if (i >= 0 && i < redovi && j >= 0 && j < kolone) {
				// Ako je pozicija unutar matrice, ispisujemo vrednost
				std::cout << matrica[i][j];
			}
			else {
				// Ako je pozicija van matrice, ispisujemo '#'
				std::cout << "#";
			}
		}
		std::cout << std::endl;
	}
}

