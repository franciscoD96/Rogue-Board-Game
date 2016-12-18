#pragma once

#include "Edificio.h"

#include <iostream>
#include <vector>

#ifndef COLONIA_H
#define COLONIA_H

using namespace std;

class Colonia {
private:
    char id;
	static char aux;
	int moedas;
    vector <Perfil *> perfis;
    vector <Ser *> seres;
    vector <Edificio *> edificos;
public:
    Colonia();
	bool AddPerfil(Perfil *p);
	//bool AddSer(Ser *s);
	bool AddEdificio(Edificio *e);
	bool BuildSer(char perfil);
	char getIDCol();
	//bool ConfirmaPagamentoSer();
	//bool ConfirmaPagamentoEdificios();
	int getMoedas();
	void setMoedas(int moedas);
	void infoColonia();
	int posPerfil(char perfil);
	Edificio * getCast();
	

};

#endif /* COLONIA_H */
