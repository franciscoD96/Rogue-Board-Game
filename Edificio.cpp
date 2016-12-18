#include "Edificio.h"
Edificio::Edificio(int custo, int saude, int def): custo(custo),saude(saude),defesa(def) {
	this->id = aux;
	aux++;
}


void Edificio::InfoEdificio(ostringstream  & os){
	
	os.str("");
	os << "ID Colonia: " << id_col << endl;
	os << "ID: " << id << endl;
	os << "Saude: " << saude << endl;
	os << "Defesa: " << defesa << endl;
}

char Castelo::getIdEdificio()
{
	return this->id;

}

void Castelo::SetIdentificaCol(char id)
{
	this->id_col = id;
}

void Castelo::setPosEdificio(int _pos)
{
	this->posicao= _pos;
}

int Castelo::getPosEdificio()
{
	return this->posicao;
}

bool Castelo::addSer(Ser * s)
{
	if (s == nullptr)
		return false;

	Ser* aux = s;
	aux->setPosicao(this->getPosEdificio());
	edSeres.push_back(aux);
	return true;
}

vector<Ser*> Castelo::retornaSeres()
{
	return this->edSeres;
}



char Edificio::aux = 'a';
Castelo::Castelo(int custo, int saude, int def) : Edificio(custo, saude, def) {
}



void Castelo::InfoEdificio(ostringstream  & os){
	
	os.str("");
	os << " ___EDIFICIO___" << endl;
	os << "|ID Colonia: " <<id_col<<" |" << endl;
	os << "|ID: "<< id  <<"         |" << endl;
	os << "|Saude: "<< saude <<"     |" << endl;
	os << "|Defesa: "<<defesa<<"    |" <<endl;
	os << "|______________|" << endl;
	if (!edSeres.empty()) {
		for (int i = 0; i < edSeres.size(); i++) {
				edSeres[i]->mostraSerInfo(os);
				cout << os.str() << endl;
			}
	}
}

Torre::Torre(int custo, int saude, int def, int atk) : Edificio(custo, saude, def), ataque(atk) {}

void Torre::InfoEdificio(ostringstream  & os){
	
	os.str("");
	os << "ID Colonia: " << id_col << endl;
	os << "ID: " << id << endl;
	os << "Saude: " << saude << endl;
	os << "Defesa: " << defesa << endl;
	os << "Ataque: " << ataque << endl;
	
}

Quinta::Quinta(int custo, int saude, int def, int prod) : Edificio(custo, saude, def),producao(prod){}

