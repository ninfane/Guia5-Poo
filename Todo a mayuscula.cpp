#include <iostream>
#include <cctype>
using namespace std;

string a_mayusc(string str){
	if(!str.empty()){	
		for(size_t i=0;i<str.size();i++) { 
			str[i] = toupper(str[i]);
		}
	}
	return str;
}

int main() {
	
	string s1 = "llevar a MayusCula";
	string s2 = a_mayusc(s1);
	cout << s2 << endl;
	
	return 0;
}

