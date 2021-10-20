#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Alumno {
	string nombre;
	float n1, n2, n3;
};

int main() {
	
	ifstream archi("alumnos.txt");
	if(!archi.is_open()){
		cout << "Error";
		return 1;
	}
	
	vector<Alumno> v;
	
	Alumno a;
	while( getline(archi,a.nombre) && archi >> a.n1 >> a.n2 >> a.n3 ) {
		v.push_back(a);
		archi.ignore();
	}
	archi.close();
	
	ofstream archi2("alumnos.txt",ios::trunc);
	
	for(size_t i=0;i<v.size();i++) { 
		archi2 << v[i].nombre << endl;
		float prom = (v[i].n1+v[i].n2+v[i].n3)/3.0;
		archi2 << prom << endl;
	}
	
	return 0;
}

