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
	
	ain.close();
	
	ofstream aout("palabras.txt", ios::trunc);
	for(size_t i=0;i<v.size();i++) { 
		aout << v[i] << endl;
	}
	
	return 0;
}

