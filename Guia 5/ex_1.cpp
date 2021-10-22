#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	
	ifstream ain("palabras.txt");
	if(!ain.is_open()){
		cout << "Error";
		return 1; 
	}
	
	//leo cada palabra del archivo de texto y lo llevo
	//a mi vector
	vector<string> v;
	string x;
	int contador = 0;
	while(ain >> x) {
		v.push_back(x);
		contador++;
	}
	
	cout << "Cantidad de palabras: " << contador << endl;
	
	//ordenar alfabeticamente el vector
	sort(v.begin(),v.end());
	
	//cierro el archivo
	ain.close();
	
	//escribo mi vector ordenado en el archivo 
	ofstream aout("palabras.txt", ios::trunc);
	for(size_t i=0;i<v.size();i++) { 
		aout << v[i] << endl;
	}
	//no es necesario aclarar el close en este caso
	aout.close();
	
	return 0;
}

