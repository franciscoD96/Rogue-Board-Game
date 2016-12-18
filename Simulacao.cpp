#include "Simulacao.h"

#include <string>
#include <vector>


Simulacao::Simulacao(Mapa *mapa, vector<Colonia *> col):colonias(col) {
	this->m = mapa;
	this->foco[0] = 1;
	this->foco[1] = 1;
	this->nextT = false;
	this->comInv = false;
}


void Simulacao::processaComando(string primeira, string segunda, string terceira) {
	this->comInv = false;

	if (primeira == "next") {
		this->nextT = true;
		return;
	} else
		if (primeira == "foco") {
			this->foco[0] = stoi(segunda);
			this->foco[1] = stoi(terceira);
		} else
			if (primeira == "ser") {
				const int nr = stoi(segunda);
				const char *perfil = terceira.c_str();
				incubadora(nr, *perfil);
			}

}

void Simulacao::incubadora(int nr,char perfil){
	for (int i = 0; i < nr; i++) {
		colonias[0]->BuildSer(perfil);
	}
}

void Simulacao::movimentodeSeres() {
	for (int i = 0; i < colonias.size(); i++) {
		Edificio *aux = colonias[i]->getCast();
		vector<Ser*> Saux = aux->retornaSeres();
		for (int j = 0; j < Saux.size(); j++) {
			int new_pos = Saux[j]->moveSer(Saux[j]->getVelocidade(), m->getCol());
			m->mudaPosicao(Saux[j], new_pos);
		}
	}
}