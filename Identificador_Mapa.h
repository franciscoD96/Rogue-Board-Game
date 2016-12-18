#pragma once

#include "Ser.h"
#include "Edificio.h"

#include <sstream>
#include <iostream>
#include <string>

#ifndef IDENTIFICADOR_MAPA_H
#define IDENTIFICADOR_MAPA_H

using namespace std;

class Identificador_Mapa {
	int posicao;
	static int contador;
	Ser * ser_pos;
	Edificio * edificio_pos;
public:
	Identificador_Mapa(int linhas, int colunas);
	void set_Pos(int pos);
	int getPos();
	bool addSer(Ser * s);
	bool addEdificio(Edificio * e);
	void infoCelula(ostringstream &os);
	Ser* getSer();
	bool verificaSer();
	void setSer(Ser *s);
	void imprime(int x, int y);

};
#endif
