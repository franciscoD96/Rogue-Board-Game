#pragma once

#ifndef PERFIL_H
#define PERFIL_H
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Perfil;
class Caracteristica {
protected:
	int id;
	string nome;
	int custo;
	int forca;
public:
	Caracteristica(string _nome,int _id,int _custo, int _forca);
	int getForca();
	int getCusto();
	string getNome();
	virtual void infoCaracteristica(ostringstream & os);
	virtual Caracteristica *clone();

};



class Bandeira : public Caracteristica {
public:
	Bandeira(int cust,int forc);
	virtual void infoCaracteristica(ostringstream & os);
	virtual Bandeira *clone();
};
class Superior : public Caracteristica {
	int up_saude;
public:
	Superior(int cust, int forc, int _upSaude);
	virtual void infoCaracteristica(ostringstream & os);
	virtual Superior *clone();
	int getSau();
};
class PeleDura : public Caracteristica {
	int upDef;
public:
	PeleDura(int cust, int forc, int _upDef);

};
class Armadura : public Caracteristica {
	int upDef;
public:
	Armadura(int cust, int forc, int _upDef);

};

class Perfil {
private:
	char id;
	int forca;
	int custo;
	vector<Caracteristica *> caracteristicas;
	vector<string> nomesCar;

public:
	Perfil(char i);
	Perfil(Perfil & p);
	bool addCarateristica(Caracteristica * c);
	void subCarateristica(int i);
	void perfilMenu(string nome);
	char getID();
	int getForca();
	void setForca(int _f);
	int getCusto();
	void setCusto(int _c);
	vector<string> getCar();
	void infoPerfil() const;
};
#endif
