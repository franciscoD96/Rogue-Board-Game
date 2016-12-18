#pragma once

#include "Perfil.h"

#include <sstream>
#include <iostream>
#include <vector>

#ifndef SER_H
#define SER_H



using namespace std;

class Ser {
private:
	Perfil * perf;
	char id_col;
	char id;
	static char aux;
	int forca;
	int saude;
	int custo;
	int posicao;
	int velocidade;

public:
    Ser(Perfil * p);
	int getSaude();
	void setSaude(int saude);
	int getCusto();
	void setCusto(int custo);
	int getForca();
	void setForca(int forca);
	void setPosicao(int pos);
	int moveSer(int velocidade, int col);
	void mostraSerInfo(ostringstream & os) const;
	int getVelocidade();
	char getID();
};

#endif
