#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	ifstream archi("notas.txt");
	
	int x;
	int notas = 0;
	float suma = 0;
	while(archi>>x){
		suma += x;
		notas++;
	}
	
	cout << "Promedio: " << suma/notas << endl;
	
	return 0;
}

