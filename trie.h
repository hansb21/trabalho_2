
#ifndef TRIE_STRUCT_H
#define TRIE_STRUCT_H

namespace structures {

	struct NoTrie {
		struct NoTrie* filhos[26];
		int size, pos;
	};

	struct NoTrie* initi();

#include "trie.inc"

} // namespace structures

#endif
