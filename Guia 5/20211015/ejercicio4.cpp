#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct clave{
	string campo,valor;
};

class ConfigFile{
	vector<clave> v;
	string archivo;
public:
	ConfigFile(string x);
	string VerValor(string ca);
	void ModificaValor(string ca, string nuevov);
	void ActualizarArchivo();
	clave VerClave(int x){return v[x];}
	int CantClaves(){return v.size();}
};

ConfigFile::ConfigFile(string x):archivo(x){
	ifstream archi(archivo);
	string linea;
	clave aux;
	while(getline(archi,linea)){
		if (linea[0] != '#'){       //  materia=Programacion Orientada a Objetos
			aux.campo=linea.substr(0,linea.find("="));
			aux.valor=linea.substr(linea.find("=")+1);
			v.push_back(aux);
		}
	}
	archi.close();
}

string ConfigFile::VerValor(string ca){
	for(size_t i=0;i<v.size();i++) {
		//if(v[i].campo == ca)        //si queremos que sea exactamente igual al campo la busqueda
		if(v[i].campo.find(ca)!= string::npos)   //si quiero que busque una parte
			return v[i].valor;
	}
	return "";
}

void ConfigFile::ModificaValor(string ca, string nuevov){
	for(size_t i=0;i<v.size();i++) {
	//if(v[i].campo == ca)        //si queremos que sea exactamente igual al campo la busqueda
		if(v[i].campo.find(ca)!= string::npos)   //si quiero que busque una parte
			v[i].valor=nuevov;
	}
}

void ConfigFile::ActualizarArchivo(){
	ofstream archi(archivo,ios::trunc);
	for(clave a: v)
		archi<<a.campo<<"="<<a.valor<<endl;
	archi.close();
}
	
int main(int argc, char *argv[]) {
	ConfigFile CF("configuracion.txt");
	for(int i=0;i<CF.CantClaves();i++) { 
		clave aux=CF.VerClave(i);
		cout<<aux.campo<<" = "<<aux.valor <<endl;
	}
	
	cout<<endl<<CF.VerValor("unive")<<endl;
	
	CF.ModificaValor("mate","Fundamentos de Programacion");
	CF.ModificaValor("nro_","15");
	
	cout<<endl<<endl;
	
	for(int i=0;i<CF.CantClaves();i++) { 
		clave aux=CF.VerClave(i);
		cout<<aux.campo<<" = "<<aux.valor <<endl;
	}
	
	CF.ActualizarArchivo();
	
	
	return 0;
}

