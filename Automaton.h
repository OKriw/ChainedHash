//
// Created by Olga on 14/10/2020.
//

#ifndef HASHMAP_AUTOMATON_H
#define HASHMAP_AUTOMATON_H
#include <iostream>
#include <vector>
#include <string>

class NAutomaton {
private:
    uint64_t terminals = 0;
    uint16_t alphabet_size, size;
    std::vector<std::vector<uint64_t>> transitions;
public:
    void addTermState(uint16_t state) {
        terminals |= (1ull << state);
    }
    void addTrans(uint16_t from, uint16_t to, char c) {
        transitions[from][c - 'a'] |= (1ull << to);
    }

    NAutomaton() = delete;
    NAutomaton(uint16_t alphSize, uint16_t n_states);
    bool isOk(std::string& s);
};

NAutomaton::NAutomaton(uint16_t alphSize, uint16_t size){
        this->alphabet_size = alphSize;
        this->size = size;
        transitions.resize(size);
        for (auto col: transitions) {
            col.resize(alphSize, (uint16_t)0);
        }
 };

bool NAutomaton::isOk(std::string& s){
        uint64_t current_state = 1;
        for (char c : s) {
            uint64_t tmp = 0;
            for (int16_t mb_state = 0; mb_state < size; ++mb_state) {
                if (current_state & (1ull<<mb_state)) {
                    tmp |= transitions[mb_state][c - 'a'];
                }
            }
            current_state = tmp;
            if (current_state == 0) {
                return false;
            }
        }
        return (terminals & current_state);
}
#endif //HASHMAP_AUTOMATON_H
