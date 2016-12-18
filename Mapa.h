#pragma once

#include "Identificador_Mapa.h"


#include <sstream>
#include <iostream>
#include <vector>

#ifndef MAPA_H
#define MAPA_H

using namespace std;

class Mapa {
private:
	//LINHAS SAO Y E COLUNAS SAO X
	int lin , col;
	int tamanho;
	vector <Identificador_Mapa *> mapa;
public:
	Mapa(int linhas, int colunas);

	//gets e set
	int getLin();
	int getCol();
	int getTamanho();
	vector<Identificador_Mapa*> getCelula();
	void setLin(int lin);
	void setCol(int col);
	void SetMapaSer(int _x, int _y, Ser *s);
	void SetMapaEdificio(int _x, int _y, Edificio * e);
	void CarregaMapa();
	void preencheMapa();
	int PosCoord_X(int pos);
	int PosCoord_Y(int pos);
	int CoordPos(int _x,int _y);
	void InfoMapa();
	vector<Identificador_Mapa*> retornaVectorIdMapa();
	bool mudaPosicao(Ser *s, int new_position);
};

#endif