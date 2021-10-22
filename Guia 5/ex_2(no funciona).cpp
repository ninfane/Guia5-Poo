#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

struct Alumno {
	string name, condition;
	int n1, n2;
	float pro;
};

void modificar(vector<Alumno> v){
	float prom = 0.0;
	for(size_t i=0;i<v.size();i++) { 
		float aux  = 0.0;
		aux += v[i].n1;
		aux += v[i].n2;
		prom += aux/2;
		v[i].pro = prom;
	}
	for(size_t i=0;i<v.size();i++) { 
		if(v[i].pro>=8) v[i].condition = "promocional";
		else if (v[i].pro>=4) v[i].condition = "regular";
		else v[i].condition = "libre";
	}
}

int main() {
	
	vector<Alumno> v;
	
	ifstream ain("lista.txt");
	if(!ain.is_open()){
		cout << "Error";
		return 1;
	}
	
	Alumno aux;
	while(getline(ain,aux.name) and ain >> aux.n1 >> aux.n2){
		v.push_back(aux);
		ain.ignore();
	}
	
	for(size_t i=0;i<v.size();i++) { 
		cout << v[i].name << endl;
		cout << v[i].n1 << " " << v[i].n2 << endl;
	} 
	
	ain.close();
	
	ofstream aout("lista.txt",ios::trunc);
	for(size_t i=0;i<v.size();i++) { 
		aout << v[i].name << " " << v[i].pro << " " << v[i].condition << endl;
	}
	
	return 0;
}

