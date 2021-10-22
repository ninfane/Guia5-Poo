#include <iostream>
#include <cctype>
using namespace std;

//tomo una frase y la reescribo con la primera letra
//en mayuscula y el resto en minuscula
string corregir(string str){
	if(!str.empty()){
		str[0] = toupper(str[0]);
		for(size_t i=1;i<str.size();i++) { 
			str[i] = tolower(str[i]);
		}
	}
	return str;
}

int main() {
	
	string s1 = "mi frase a corregir";
	string s2 = corregir(s1);
	cout << s2 << endl;
	
	return 0;
}

