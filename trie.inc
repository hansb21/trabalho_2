
struct NoTrie* init() 
{
	auto Nnode = new NoTrie;

	Nnode->size = Nnode->pos = 0;
	
	for (int i = 0; i < 26; i++)
		Nnode->filhos[i] = NULL;
	
	return Nnode;
}


