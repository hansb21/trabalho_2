#include <iostream>

struct NoTrie* init() 
{
	auto Nnode = new NoTrie;

	Nnode->size = 0;
       	Nnode->pos = 0;
	
	for (int i = 0; i < 26; i++)
		Nnode->filhos[i] = NULL;
	
	return Nnode;
}

void insert(struct NoTrie* root, std::string key, unsigned long pos, unsigned long size)
{
	auto aux = root;
	
	for (auto i = 0u; i < key.length(); i++)
	{
		int idx = key[i] - 'a';
		if (!aux->filhos[idx])
			aux->filhos[idx] = init();
		
		aux = aux->filhos[idx];
	}

	aux->pos = pos;
	aux->size = size;
}


//! retorna o Nó do último caracter de uma string ou a própria raiz
NoTrie* find(struct NoTrie* root, std::string key) 
{
	auto aux = root;

	for (auto i = 0u; i < key.length(); i++) {
		int idx = key[i] - 'a';
		
		if (!aux->filhos[idx]) {
			// caso a string não esteja na árvore
			return init();
		}
		aux = aux->filhos[idx];
	}
	return aux;
}

int countSufixes(struct NoTrie* root) {
	int sufixes = 0;

	if (root->size > 0) {
		sufixes++;
	}

	for (int i = 0; i < 26; i++) {
		if (root->filhos[i]){
			sufixes += countSufixes(root->filhos[i]);
		}
	}
	return sufixes;
}
