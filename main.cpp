#include <iostream>
#include "HashClosedAdr.h"
#include "Automaton.h"
#include <chrono>
#include <random>
#include <vector>

int myhash(int key) {
    return key%32;
}

int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}
int main() {
    HashChained<int> hash_table(32, &myhash);
    std::vector<int> keys;
    for (int i = 0; i < 32; i++) {
        int op = rand_uns(2, 3);
        if (op == 2) {
            int key = rand_uns(1, 799);
            keys.push_back(key);
            hash_table.insert(key, rand_uns(-100, 100));
        }
        if (op == 3) {
            hash_table.remove(rand_uns(0, keys.size()));
        }

    }
    //hash_table.print();
    std::cout << "Hello, World!" << std::endl;
    std::cout <<1ull<<std::endl;
    std::cout <<1ull<<std::endl;
    //Automaton
    uint16_t alphabet_size = 0, states = 0;
    std::cin >> alphabet_size >> states;
    NAutomaton aut(alphabet_size, states);

    int n; //<- states
    std::cin >> n;
    uint16_t from, to;
    char c;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> from >> to >> c;
        aut.addTrans(from, to, c);
    }


    for (size_t i = 0; i < n; ++i) {
        std::cin >> from;
        aut.addTermState(from);
    }
    return 0;
}
