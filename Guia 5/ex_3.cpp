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
	
	int inicio = 0; int fin = 5;
	for(int i=0;i<comisiones;i++) { 
		stringstream ss;
		ss << "comision" << i+1 << ".txt";
		ofstream archi2(ss.str(),ios::trunc);
		for(int j=inicio;j<fin;j++) { 
			archi2 << v[j] << endl;
		}
		inicio +=5; fin+=5;
		archi2.close();
	}
	
	return 0;
}

