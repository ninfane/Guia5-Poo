#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Materia {
	string camp, content;
};

class ConfigFile{
private:
	vector<Materia> v;
	string archivo;
public:
	ConfigFile(string name);
	string VerContenido(string campo);
	void ModContenido(string campo, string nuevo);
	void GuardarArchivo();
};

ConfigFile::ConfigFile(string name): archivo(name){
	ifstream archi(archivo);
	if(!archi.is_open()){
		cout << "Error";
	}
	string linea;
	Materia aux;
	while(getline(archi,linea)){
		if(linea[0]!='#'){
			aux.camp = linea.substr(0,linea.find("="));
			aux.content = linea.substr(linea.find("="+1));
			v.push_back(aux);
		}
	}
	archi.close();
}
string ConfigFile::VerContenido(string campo){
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].camp == campo){
			return v[i].content;
		}
	}
	return " ";
}

void ConfigFile::ModContenido(string campo, string nuevo){
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].camp == campo){
			v[i].content = nuevo;
		}
	}
}
void ConfigFile::GuardarArchivo(){
	ofstream archi(archivo);
	for(size_t i=0;i<v.size();i++) { 
		archi << v[i].camp + "=" + v[i].content << endl;
	}
}

int main() {
	
	cout << "Ingrese nombre del archivo" << endl;
	string name; getline(cin,name);
	ConfigFile file(name);
	
	//funciona
	string m = file.VerContenido("materia");
	cout << m << endl;
	
	//funciona
	file.ModContenido("materia","Fundamentos de programacion");
	
	//funciona
	file.GuardarArchivo();
	
	return 0;
}

