#include "Configuracao.h"
#include "Colonia.h"
#include "Mapa.h"
#include "Identificador_Mapa.h"
#include "Perfil.h"


using namespace std;

Configuracao::Configuracao() {
	caracteristicas.push_back("Bandeira");
	caracteristicas.push_back("Superior");
	caracteristicas.push_back("Pele dura");
	caracteristicas.push_back("Armadura");
	caracteristicas.push_back("Faca");
	caracteristicas.push_back("Espada");
	caracteristicas.push_back("Agressão");
	caracteristicas.push_back("Ecológico");
	caracteristicas.push_back("HeatSeeker");
	caracteristicas.push_back("BuildSeeker");
	caracteristicas.push_back("Walker");
	caracteristicas.push_back("Remedio");
	caracteristicas.push_back("SecondChance");
	caracteristicas.push_back("Aluno");

	dimLin = 0;
	dimCol = 0;
	moedas = 150;
	opon = 1;
	this->dimT = false;
	this->inicioT = false;
	this->oponT = false;
	this->comInv = false; // comando invalido
}

void Configuracao::processaComando(string primeira, string segunda, string terceira, string quarta) {
	this->comInv = false;
	if (primeira == "dim" && dimT == false) {
		dimT = true;
		Configuracao::setDim(stoi(segunda), stoi(terceira));
	}
	else
		if (primeira == "moedas") {
			Configuracao::setMoedas(stoi(segunda));
		}
		else
			if (primeira == "oponentes" && dimT == true) {
				oponT = true;
				Configuracao::setOponentes(stoi(segunda));
			}
			else
				if (primeira == "castelo" && oponT == true)
					Configuracao::setPosCastelo(segunda, stoi(terceira), stoi(quarta));
				else
					if (primeira == "inicio")
						Configuracao::setInicio();
					else 
						if (primeira == "mkperfil")
							Configuracao::mkperfil(segunda);
						else 
							if (primeira == "addperfil")
								Configuracao::addperfil(segunda, terceira);
							else
								if (primeira == "subperfil")
									Configuracao::subperfil(segunda, terceira);
								else 
									if (primeira == "rmperfil")
										Configuracao::rmperfil(segunda);
									else {
							this->comInv = true;
						}
}
void Configuracao::loadFile(string fich) {
	ifstream infile(fich); if (!infile) { this->comInv = true; return; }

	string line;
	while (infile.good()) {
		getline(infile, line);
		istringstream iss(line);
		string primeira, segunda, terceira, quarta;
		iss >> primeira >> segunda >> terceira >> quarta;
		Configuracao::processaComando(primeira, segunda, terceira, quarta);
	}
	infile.close();

}
void Configuracao::setInicio() {
	this->inicioT = true;
}
void Configuracao::mkperfil(string segunda){
	const char *letra = segunda.c_str();

	for (int i = 0; i < perfis.size();i++) // valida de há um igual
		if (perfis[i]->getID() == *letra) {
			this->comInv = true;
			return;
		}

	Perfil *p1 = new Perfil(*letra);
	perfis.push_back(p1);
}
void Configuracao::addperfil(string segunda, string terceira)
{
	const char *letra = segunda.c_str();
	int i=0;
	while (perfis[i]->getID() != *letra){
		i++;
		// validar se o perfil inserido existe
	}

	int _case = 0;
	for (int j = 0; j < caracteristicas.size(); j++) {
		if (caracteristicas[j] == terceira)
			break;
		_case++;
	}
	if (perfis[i]->getForca() <= 0)
		this->comInv = true;
	else {
		switch (_case) {
		case (0):
			perfis[i]->addCarateristica(new Bandeira(1, 1));
		default:
			break;
		}
	}
	

	//perfis[i]->addCarateristica(new Superior(3,2,1));
}
void Configuracao::subperfil(string segunda, string terceira)
{

	const char *letra = segunda.c_str();

	int i = 0;
	while (perfis[i]->getID() != *letra) {
		i++;
		// validar se o perfil inserido existe
	}

	int j;
	vector<string> car = perfis[i]->getCar();
	for (j = 0; car[j] != terceira; j++) {
		if (car[j] == terceira)
			break;
	}
	
	perfis[i]->subCarateristica(j);

}
void Configuracao::rmperfil(string segunda)
{
	const char *letra = segunda.c_str();
	int i = 0;
	while (perfis[i]->getID() != *letra) {
		i++;
		// validar se o perfil inserido existe
	}
	perfis.erase(perfis.begin() + i);
	//perfis[i].erase(perfis.size() + i);

}
vector<string> Configuracao::getCar(int i)
{
	return vector<string>(perfis[i]->getCar());
}
int Configuracao::getTamanho(int _x , int _y){

	return _x*_y;
}
void Configuracao::setDim(int lin, int col) {
	this->dimLin = lin;
	this->dimCol = col;
	this->tamanho = lin*col;
}
int Configuracao::getDimLin(){
	return this->dimLin;
}
int Configuracao::getDimCol(){
	return this->dimCol;
}
void Configuracao::setMoedas(int n) {
	this->moedas = n;
}
int Configuracao::getMoedas(){
	return this->moedas;
}
Perfil * Configuracao::getPerfil(int i) {

	return (this->perfis[i]);
}
int Configuracao::getTamanhoVectorPerfil() {
	return this->perfis.size();
}

/*void Configuracao::posiciona_castelos(int n) {
	srand(time(0));
	int pos;
	for (int i = 0; i < n; i++) {
		pos = rand() % this->tamanho;
		Pos_castelo.push_back(pos);
	}
}*/
void Configuracao::setOponentes(int op){
	for (int i = 0; i < (op+1); i++) {
		Cast_X.push_back(rand() % this->dimCol);
		Cast_Y.push_back(rand() % this->dimLin);
	}
	this->opon = op + 1;
}
int Configuracao::getOponentes()
{
	return this->opon;
}
void Configuracao::setPosCastelo(string colonia, int x, int y) {
	
	int i = (int)colonia.at(0), teste = i;
	if ((teste - 90) < 0) // 90 poder ser um nr qq entre os char maiusculos e minusculos
		i = i - 65;
	else
		i = i - 97;
	
	if (this->opon > i) {
		Cast_X[i] = x;
		Cast_Y[i] = y;
	}
		

	//return this->Pos_castelo[i] = this->getTamanho(x, y);
}

/*int Configuracao::getPosInVector(int positionVetor){
	return this->Pos_castelo[positionVetor];
}*/


bool Configuracao::getInicio() { 
	return inicioT; 
}

bool Configuracao::getcomInv() {
	return comInv;
}

bool Configuracao::getdimT(){
	return dimT;
}

bool Configuracao::getmoedasT(){
	return moedasT;
}

bool Configuracao::getoponT(){
	return oponT;
}

int Configuracao::gettamvetor() {
	return perfis.size();
}

char Configuracao::getcharperf(int i)
{
	return perfis[i]->getID();
}
int Configuracao::getForcaPerf(int i) {
	return perfis[i]->getForca();
}
int Configuracao::getCustoPerf(int i)
{
	return perfis[i]->getCusto();
}
int Configuracao::getCoordX(int i)
{
	if (Cast_X.empty())
		return 0;
	else
		return Cast_X[i];
}

int Configuracao::getCoordY(int i){
	if (Cast_Y.empty())
		return 0;
	else
		return Cast_Y[i];
}
void Configuracao::Castelos_menu(int _i){
	cout <<"X "<< Cast_X[_i]<<" , "<<"Y " << Cast_Y[_i];
}

