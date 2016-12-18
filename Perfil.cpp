#include "Perfil.h"

Perfil::Perfil(char i) {
	this->id = i;
	this->forca = 10;
	this->custo = 0;
}

Perfil::Perfil(Perfil & p){
	this->id = p.id;
	this->forca = p.forca;
	this->custo = p.custo;
	for (int i = 0; i < caracteristicas.size(); i++){
		caracteristicas.push_back(p.caracteristicas[i]->clone());
	}
}

bool Perfil::addCarateristica(Caracteristica *c){
	if (c == nullptr)
		return false;

	this->setForca(c->getForca());
	this->setCusto(c->getCusto());
	caracteristicas.push_back(c);
	nomesCar.push_back(c->getNome());

	return true;
}
void Perfil::subCarateristica(int i) {
	// verificar se foi bem sucedido
	this->forca += caracteristicas[i]->getForca();
	this->custo -= caracteristicas[i]->getCusto();
	this->caracteristicas.erase(caracteristicas.begin() + i);
	this->nomesCar.erase(nomesCar.begin() + i);
}

void Perfil::perfilMenu(string nome) {
	
}
char Perfil::getID()
{
	return this->id;
}

int Perfil::getForca()
{
	return this->forca;
}

vector<string> Perfil::getCar()
{
	return vector<string>(this->nomesCar);
}

void Perfil::infoPerfil() const{
	ostringstream  os;
	os.str("");
	os << "Perfil: " << this->id << endl;
	cout << os.str();
	if (!caracteristicas.empty()) {
		for (int i = 0; i < caracteristicas.size(); i++) {
			caracteristicas[i]->infoCaracteristica(os);
			cout << os.str() << endl;
		}
	}
}



Caracteristica::Caracteristica(string _nome, int _id,int _custo, int _forca) 
	: nome(_nome),id(_id), custo(_custo),forca(_forca) { }

int Caracteristica::getForca()
{
	return this->forca;
}

int Caracteristica::getCusto()
{
	return this->custo;
}

void Perfil::setForca(int _f){
	this->forca -= _f;
}

int Perfil::getCusto()
{
	return this->custo;
}

void Perfil::setCusto(int _c)
{
	this->custo += _c;
}

string Caracteristica::getNome()
{
	return string(nome);
}

void Caracteristica::infoCaracteristica(ostringstream &os){
	os.str("");
	os << "Nome: " << nome << endl;
	os << "Custo: " << custo << endl;
	os << "Forca:" << forca << endl;
	cout << os.str();
}

Caracteristica * Caracteristica::clone()
{
	return new Caracteristica(*this);
}

Bandeira::Bandeira(int cust,int forc) : Caracteristica("Bandeira",1,cust,forc){
}
void Bandeira::infoCaracteristica(ostringstream & os)
{
	os.str("");
	os << "Nome: " << nome << endl;
	os << "Custo: " << custo << endl;
	os << "Forca:" << forca << endl;
}
Bandeira * Bandeira::clone()
{
	return new Bandeira(*this);
}
Superior::Superior(int cust, int forc, int upSaude) : Caracteristica("Superior",2,cust, forc) {
	this->up_saude = upSaude;
}
void Superior::infoCaracteristica(ostringstream & os){
	os.str("");
	os << "Nome: " << nome << endl;
	os << "Custo: " << custo << endl;
	os << "Forca:" << forca << endl;
}
Superior * Superior::clone()
{
	return new Superior(*this);
}
int Superior::getSau(){
	return this->up_saude;
}
PeleDura::PeleDura(int cust, int forc, int _upDef) : Caracteristica("Pele Dura",3,cust, forc){
	this->upDef = _upDef;
}

Armadura::Armadura(int cust, int forc, int _upDef) : Caracteristica("Armadura",4,cust, forc){
	this->upDef = _upDef;
}
