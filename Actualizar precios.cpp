#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct precios {
	string producto;
	int precio;
};

int main() {
	
	ifstream archi("precios.txt");
	if(!archi.is_open()){
		cout << "Error";
		return 1;
	}
	
	vector<precios> v;
	precios aux;
	
	//me guardo la info en un vector
	while(getline(archi,aux.producto) and archi >> aux.precio){
		v.push_back(aux);
		archi.ignore();
	}
	
	archi.close();
	
	//le agrego 1000 pesos a cada producto
	ofstream archi2("precios.txt",ios::trunc);
	for(size_t i=0;i<v.size();i++) { 
		archi2 << v[i].producto << endl;
		int nuevo = v[i].precio + 1000;
		archi2 << nuevo << endl;
	}
	
	archi2.close();
	
	return 0;
}

