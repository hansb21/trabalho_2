
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
	
	for (int i = 0; i < key.length(); i++)
	{
		int idx = key[i] - 'a';
		if (!aux->filhos[idx])
			aux->filhos[idx] = init();

		aux = aux->filhos[idx];
	}

	aux->pos = pos;
	aux->size = size;
}