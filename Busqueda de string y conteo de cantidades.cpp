#include <iostream>
using namespace std;

int main() {
	
	string frase = "being the one is just like being in love"; 
	cout << frase << endl;
	
	string word;
	cout << "Ingrese palabra a buscar" << endl;
	cin >> word;
	
	//puedo agregar desde que posicion quiero que busque
	//aqui el 0. Si no pongo nada, es 0 por defecto 
	size_t p = frase.find(word);
	if(p==string::npos) cout << "No esta" << endl;
	else cout << "La palabra comienza en posicion " << p << endl;
	
	cout << "Ingrese segunda palabra" << endl;
	string word2; cin >> word2;
	size_t p2 = frase.find(word2);
	
	//si quiero buscar cuantas veces se repite debo usar un while
	//mientras no sea el valor especial npos, sumo al contador
	//y corro la posicion de p2 la cantidad de lugares que ocupa
	//la palabra/silaba, lo que sea 
	int cant = 0;
	while(p2!=string::npos){
		cant++;
		p2 = frase.find(word2,p2+word2.size());
	}
	
	cout << "La palabra esta " << cant << " veces" << endl; //da 2
	
	return 0;
}

