#include "Mapa.h"

Mapa::Mapa(int linhas,int colunas): lin(linhas),col(colunas) {
	this->tamanho = linhas * colunas;
}

int Mapa::getLin()
{
	return this->lin;
}
int Mapa::getCol()
{
	return this->col;
}
int Mapa::getTamanho()
{
	return this->tamanho;
}
vector<Identificador_Mapa*> Mapa::getCelula()
{
	return this->mapa;
}
void Mapa::setLin(int lin){
	this->lin = lin;
}
void Mapa::setCol(int lin) {
	this->col = col;
}

int Mapa::CoordPos(int _x, int _y){
	if (_x == 0)
		return (_y*this->col);
	else
		if (_y == 0)
			return _x;
		else
			return (_y*this->col) + _x;

}

void Mapa::InfoMapa(){
	ostringstream os;
	for (int i = 0; i < mapa.size(); i++) {
		mapa[i]->infoCelula(os);
		cout << os.str();
	}
}

vector<Identificador_Mapa*> Mapa::retornaVectorIdMapa()
{
	return this->mapa;
}

bool Mapa::mudaPosicao(Ser * s, int new_position)
{
	vector<Identificador_Mapa*> Vaux = this->mapa;
	for (int i = 0; i < Vaux.size(); i++) {
		Ser *Saux = Vaux[i]->getSer();
		if (Saux->getID() == s->getID() && Saux == NULL) {
			Vaux[i]->setSer(nullptr);
			if (Vaux[new_position]->getSer() == nullptr)
				Vaux[new_position]->addSer(s);
			else {
				Vaux[i]->setSer(Saux);
				return false;
			}
				
		}
	}

	return true;
}


void Mapa::preencheMapa()
{
	int cont = 0;
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < 20; j++) {
			mapa[cont]->imprime(i, j);
			cont++;
		}
	/*
		int x = 0, y = 0 ;
		for (int i = this->PosCoord_X(x); i < 40; i++) {
			for (int j = this->PosCoord_Y(y); j < 20; j++) {
				mapa[i]->imprime(x, y);
				x++;
			}
			y++;
		}


		//for (int i = 0;i < mapa.size();i++) {
		//	x = this->PosCoord_X(i);
		//	y = this->PosCoord_Y(i);

		//}
	}*/
}

int Mapa::PosCoord_X(int pos){
	int x = 0, total = 0;
	while(total != pos){
		if (x == (this->col-1)) {
			total++;
			x = 0;
		}
		x++;
		total++;
	}
	return x;
}

int Mapa::PosCoord_Y(int pos)
{
	int y = 0, total_y = 0,total = 0;
	while(total != pos) 
	{
		total_y++;
		total++;
		if (total_y == (this->col - 1) ){
			total++;
			total_y = 0;
			y++;
		}
		
	}
	return y;
}


void Mapa::SetMapaSer(int _x, int _y,Ser *s){
	int real_pos = this->CoordPos(_x, _y);
	this->mapa[real_pos]->addSer(s);

}
void Mapa::SetMapaEdificio(int _x, int _y, Edificio * e){
	int real_pos = this->CoordPos(_x, _y);
	this->mapa[real_pos]->addEdificio(e);
}
void Mapa::CarregaMapa(){
	for (int i = 0; i < tamanho; i++){
		mapa.push_back(new Identificador_Mapa(this->lin, this->col));
	}
}


/*void Mapa::MostraVetorInfos() const{
	int space = 1;
	for (int i = 0; i < tamanho; i++) {
		cout << " " << mapa[i];
		if (this->col == space){
			space = 0;
			cout << endl;
		}
		space++;
	}
}*/





