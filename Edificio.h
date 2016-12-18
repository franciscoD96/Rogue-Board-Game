#pragma once

#include "Ser.h"

#include <vector>

#ifndef EDIFICIO_H
#define EDIFICIO_H

using namespace std;

class Edificio {
	static char aux;
protected:
	char id_col;
	char id;
	int custo;
	int saude;
	int defesa;
	int posicao;
public:
	Edificio(int custo, int saude, int def);
	virtual void InfoEdificio(ostringstream  & os);
	virtual char getIdEdificio() = 0;
	virtual void SetIdentificaCol(char id) = 0;
	virtual void setPosEdificio(int _pos) = 0;
	virtual int getPosEdificio() = 0;
	virtual bool addSer(Ser *s) = 0;
	virtual vector<Ser*> retornaSeres() = 0;
};

class Castelo : public Edificio {
	vector <Ser *> edSeres;
public:
	Castelo(int custo, int saude, int def);
	virtual void InfoEdificio(ostringstream  & os);
	virtual char getIdEdificio();
	virtual void SetIdentificaCol(char id);
	virtual void setPosEdificio(int _pos);
	virtual int getPosEdificio();
	virtual bool addSer(Ser *s);
	virtual vector<Ser*> retornaSeres();

};

class Torre : public Edificio {
	int ataque;
public:
	Torre(int custo, int saude, int def,int atk);
	virtual void InfoEdificio(ostringstream  & os);
};

class Quinta : public Edificio {
	int producao;
public:
	Quinta(int custo, int saude, int def, int prod);
};
#endif