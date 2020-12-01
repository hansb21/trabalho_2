#include <fstream>
#include <iostream>
#include <string>

#include "trie.h"

int main() {
	
	using namespace std;
	using namespace structures;
	
	string word;
	NoTrie* root = init();
	cin >> word;
	cout << "inicializou" << endl;
	insert(root, word, 0, 3);
	cout << "inseriu" << endl;
	return (0);
}
