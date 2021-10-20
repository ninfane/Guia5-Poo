#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	ifstream archi("numeros.txt");
	if(!archi.is_open()){
		cout << "Error";
		return 1;
	}
	
	int x;
	while(archi>>x){
		cout << x << " ";
	}
	cout << endl;
	
	return 0;
}

