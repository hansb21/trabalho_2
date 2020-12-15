
#include <fstream>
#include <iostream>
#include <string>

#include "trie.h"
#include "dic.h"

/**
 * @brief Printa a resposta correspondente ao nó e à palavra buscada.
 * 
 * @param NoTrie nó correspondente a palavra buscada
*  @param string palavra buscada
 */
void outputResults(structures::NoTrie* node, std::string word) {
    int sufixes = structures::countSufixes(node);
    int pos = node->pos;
    int size = node->size;

    if (sufixes == 0) {
        std::cout << word << " is not prefix" << std::endl;
    } else {
        std::cout << word << " is prefix of " << sufixes << " words" << std::endl;
    }

    if (size > 0) {
        std::cout << word << " is at (" << pos << " " << size << ")" << std::endl;
    }
}

/**
 * @brief Executa o programa, e lê as entradas.
 * 
 * @return 0 se o programa funcionar;
 * @return 1 se não foi possível abrir o arquivo;
 */
int main() {
    
    using namespace std;
    using namespace structures;

    string filename;
    string word;

    cin >> filename;  // entrada
    NoTrie* root = parseDict(filename);

    // leitura das palavras até encontrar "0"
    while (true) {
        cin >> word;
        if (word.compare("0") == 0) break;

        NoTrie* node = find(root, word);
        outputResults(node, word);
    }

    return 0;
}

