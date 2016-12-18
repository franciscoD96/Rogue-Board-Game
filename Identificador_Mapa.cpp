#include "Identificador_Mapa.h"
#include "Consola.h"

Identificador_Mapa::Identificador_Mapa(int linhas,int colunas){
	this->posicao = contador;
	contador++;
	this->ser_pos = nullptr;
	this->edificio_pos = nullptr;
}

int Identificador_Mapa::contador = 0;

void Identificador_Mapa::set_Pos(int pos) {
	this->posicao = pos;
}

int Identificador_Mapa::getPos()
{
	return this->posicao;
}

bool Identificador_Mapa::addSer(Ser * s) {
	if (s == nullptr || edificio_pos != nullptr)
		return false;
	Ser *aux = s;
	this->ser_pos = aux;
	return true;
}
bool Identificador_Mapa::addEdificio(Edificio * e)
{
	if (e == nullptr || ser_pos != NULL)
		return false;
	Edificio *aux = e;
	this->edificio_pos = aux;
	return true;
}

void Identificador_Mapa::infoCelula(ostringstream & os){
	os.str("");
	if (ser_pos == nullptr && edificio_pos != nullptr)
		edificio_pos->InfoEdificio(os);
	if (edificio_pos != nullptr && ser_pos == nullptr)
		os << "Edificio: (ID - " << edificio_pos << ") ";
	if (edificio_pos == nullptr && ser_pos == nullptr)
		os << "Posicao: " << posicao << " vazia "<< endl;
	else
		os << "Posicao: " << posicao << endl;
}

Ser * Identificador_Mapa::getSer()
{
	return this->ser_pos;
}

bool Identificador_Mapa::verificaSer()
{
	if (ser_pos != nullptr)
		return false;
	else
		return true;
}

void Identificador_Mapa::setSer(Ser *s)
{
	this->ser_pos = s;
}

void Identificador_Mapa::imprime(int x, int y)
{

	Consola::gotoxy(9 + (x * 4), 5 + (y * 2));



	if (ser_pos == nullptr && edificio_pos != nullptr)
		cout << " E";
	else
		if (ser_pos != nullptr && edificio_pos == nullptr)
			cout << " S";//cout << ser_pos;
		else
			if (ser_pos == nullptr && edificio_pos == nullptr)
				cout << " .";

}