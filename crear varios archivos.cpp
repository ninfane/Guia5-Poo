#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
using namespace std;

int main() {
	
	vector<int> v(20);
	for(int i=0;i<20;i++) { 
		v[i] = rand()%16;
	}
	
	cout << "Mi vector: " << endl;
	for(int i=0;i<20;i++) { 
		cout << v[i] << " ";
	}
	cout << endl;
	
	int inicio = 0;
	int fin = 5;
	for(int i=0;i<3;i++) { 
		stringstream ss;
		ss << "archivo" << i+1 << ".txt";
		ofstream archi(ss.str());
		for(int j=inicio;j<fin;j++) { 
			archi << v[j] << endl;
		}
		inicio += 5; fin += 5;
		archi.close();
	}
	
	return 0;
}

