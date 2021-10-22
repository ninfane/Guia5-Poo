#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	
	ifstream ain("inscriptos.txt");
	if(!ain.is_open()){
		cout << "Error";
		return 1;
	}
	
	vector<string> v;
	string x;
	while(getline(ain,x)){
		v.push_back(x);
		ain.ignore();
	}
	int cant = v.size();
	float comisiones = cant/5.0;
	cout << "Cantidad de comisiones: " << comisiones << endl;
	
	ain.close();
	
	for(int i=0;i<comisiones;i++) { 
		int aux = 1;
		stringstream ss;
		ss << "comision" << aux << ".txt";
		ofstream archi2(ss.str(),ios::trunc);
		for(int j=0;j<5;j++) { 
			archi2 << v[j] << endl;
		}
		aux++;
		archi2.close();
	}
	
	return 0;
}

