
#ifndef TRIE_STRUCT_H
#define TRIE_STRUCT_H

namespace structures {

	struct NoTrie {
		struct NoTrie* filhos[26];
		unsigned long size, pos;
	};

	struct NoTrie* initi();

	void insert(struct NoTrie* root, std::string key, unsigned long pos, unsigned long size);
	
	std::pair<int, int> find(struct NoTrie*, std::string word);

#include "trie.inc"

} // namespace structures

#endif
