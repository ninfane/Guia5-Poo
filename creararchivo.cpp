#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	ofstream archi("nuevoar.txt");
	if(!archi.is_open()){
		cout << "error";
		return 1;
	}
	
	archi.close();
	
	return 0;
}

