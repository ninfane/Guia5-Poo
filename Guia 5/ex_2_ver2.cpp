#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Alumno {
	string name;
	float n1, n2;
};

struct Condition {
	string name, cond;
	float prom;
};

vector<Condition> modifica(const vector<Alumno> &v);

int main() {
	
	ifstream ain("lista2.txt");
	if(!ain.is_open()){
		cout << "Error";
		return 1;
	}
	
	vector<Alumno> v;
	Alumno aux;
	while(getline(ain,aux.name) and ain >> aux.n1 >> aux.n2){
		v.push_back(aux);
		ain.ignore();
	}
	/*Muestro para ver que este todo bien en el pasaje
	al vector
	for(size_t i=0;i<v.size();i++) { 
		cout << v[i].name << endl;
		cout << "Notas: " << v[i].n1 << " " << v[i].n2 << endl;
	}
	*/
	
	vector<Condition> c = modifica(v);
	/*muestro para chequear que funcione
	for(size_t i=0;i<c.size();i++) { 
		cout << c[i].name << endl;
		cout << c[i].prom << " " << c[i].cond << endl;
	}
	*/
	ain.close();
	
	ofstream aout("lista2.txt",ios::trunc);
	if(!aout.is_open()){
		cout << "error";
		return 1;
	}
	
	for(size_t i=0;i<c.size();i++) { 
		aout << c[i].name << " " << c[i].prom << " " <<
			c[i].cond << endl;
	}
	
	return 0;
}

vector<Condition> modifica(const vector<Alumno> &v){
	vector<Condition> c;
	
	for(size_t i=0;i<v.size();i++) { 
		Condition aux;
		aux.prom = (v[i].n1+v[i].n2)/2.0;
		aux.name = v[i].name;
		if(aux.prom>=40.0)	aux.cond = "regular";
		else if(aux.prom>=70.0) aux.cond = "promocional";
		else aux.cond = "libre";
		c.push_back(aux);
	}
	return c;
}
