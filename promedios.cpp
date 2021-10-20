#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	ofstream archi("notas.txt", ios::trunc);
	if(!archi.is_open()){
		cout << "Error";
		return 1;
	}
	
	cout << "Ingrese cantidad de examenes" << endl;
	int e; cin >> e;
	for(int i=0;i<e;i++) { 
		cout << "Ingrese nota" << endl;
		int n; cin >> n;
		archi << n << " ";
	}
	
	archi.close();
	
	return 0;
}

