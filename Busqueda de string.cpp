#include <iostream>
using namespace std;

int main() {
	
	string frase = "being the one is just like being in love"; 
	
	string word;
	cout << "Ingrese palabra a buscar" << endl;
	cin >> word;
	
	//puedo agregar desde que posicion quiero que busque
	//aqui el 0. Si no pongo nada, es 0 por defecto 
	size_t p = frase.find(word);
	if(p==string::npos) cout << "No esta" << endl;
	else cout << "La palabra comienza en posicion " << p;
	
	return 0;
}

