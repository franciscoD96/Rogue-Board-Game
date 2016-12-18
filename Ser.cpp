#include "Ser.h"

Ser::Ser(Perfil * p) : perf(p){
	this->id = aux;
	aux++;
	this->forca = 10;
	this->saude = 10;
	this->custo = 0; // deixar apenas o custo no perfil ?
	this->velocidade = 1;
}

char Ser::aux = 'a';
int Ser::getSaude()
{
	return this->saude;
}

void Ser::setSaude(int saude){
	this->saude += saude;
}

int Ser::getCusto()
{
	return this->custo;
}

void Ser::setCusto(int custo){
	this->custo += custo;
}

int Ser::getForca()
{
	return this->forca;
}

void Ser::setForca(int forca){
	this->forca -= forca;
}

void Ser::setPosicao(int pos){
	this->posicao = pos;
}

void Ser::mostraSerInfo(ostringstream & os) const{
	os.str("");
	os << "ID(" <<id <<") -";
	os << " Stats:(Forca : " << forca << " | Saude : " << saude << " )" <<endl;
	cout << os.str();
	perf->infoPerfil();
}
int Ser::getVelocidade()
{
	return this->velocidade;
}
char Ser::getID()
{
	return this->id;
}
int Ser::moveSer(int velocidade, int col) {
	for (int i = 0; i < velocidade; i++) {
		int new_pos = rand() % 8;
		switch (new_pos) {
		case 1: //CIMA
			return this->posicao -= col;
		case 2: // CIMA DIREITA
			return this->posicao -= (col + 1);
		case 3: // DIREITA
			return this->posicao += 1;
		case 4: // BAIXO DIREITA
			return this->posicao += (col + 1);
		case 5: // BAIXO
			return this->posicao += col;
		case 6: // BAIXO ESQUERDA
			return this->posicao += (col - 1);
		case 7: // ESQUERDA
			return this->posicao -= 1;
		case 8: // VIMA ESQUERDA
			return this->posicao -= (col + 1);
		default:
			break;
		}
	}
}