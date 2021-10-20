#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
	
	//abro el archivo 
	ofstream archi("numeros.txt", ios::app);
	if(!archi.is_open()){
		cout << "No se pudo abrir el archivo";
		return 1;
	}
	
	//uso el nombre del archivo en lugar de cout 
	//y de esta forma estoy escribiendo 
	for(int i=0;i<10;i++) { 
		archi << rand()%100 << " ";
	}
	archi << endl;
	
	archi.close();
	//esto lo hice para probar nomas, no es necesario
	if(archi.is_open()){
		cout << "El archivo no se cerro";
		return 1;
	}
	
	return 0;
}

