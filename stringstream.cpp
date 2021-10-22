#include <iostream>
#include <sstream>
using namespace std;

int main() {
	
	stringstream ss;
	int aux = 10;
	ss << "Toxi taxi " << aux << ".txt";
	cout << ss.str();
	
	return 0;
}

