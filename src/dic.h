#include "trie.h"

using namespace std;
using namespace structures;

int nextPos = 0;

NoTrie* parseDict(std::string filename) {
	
	NoTrie* root = init();
	string line;
	ifstream file(filename);
	if (file.is_open()) 
	{
		while(getline(file, line))
		{	
			int i;
			string word;
			if (line[0] != '[')
			{
				nextPos += line.length() +1;
				continue;
			}
			for (i = 1; i < line.length(); i++)
			{
				if(line[i] == ']')
					break;
				
				word += line[i];
			}
			
			word[i] = '\0';
			insert(root, word, nextPos, line.length());
			nextPos += line.length() + 1;
		}
		file.close();
	} else {
		printf("nao abriu arquivo\n");
	
	
	}
    // confia

    return root;
}
