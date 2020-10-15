//
// Created by Olga on 14/10/2020.
//

#ifndef HASHMAP_HASHCLOSEDADR_H
#define HASHMAP_HASHCLOSEDADR_H
#include <list>
#include <vector>
#include <iostream>

template <class T>
class HashChained {
    int elements = 0, size = 0;
    std::vector<std::list<std::pair<int, int>>> table;
    std::function<int (const T&)> hash;
public:
    HashChained()= delete;
    HashChained(int size, const std::function<int(const T &)> &hash);
    void insert(int key, int val);
    void remove(int key);
    T search(int  key);
    void print();
};

template<class T>
HashChained<T>::HashChained(int size, const std::function<int(const T &)> &hash){
    this->size = size;
    this->hash = hash;
    table.resize(size);
}

template<class T>
void HashChained<T>::insert(int key, int val) {
    int idx = hash(key);
    for (auto it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it -> first == key) {
            it -> second = val;
            return;
        }
    }
    table[idx].push_back(std::pair<int, int>(key, val));
    elements++;
}
template<class T>
void HashChained<T>::remove(int key) {
    int idx = hash(key);
    for (auto it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it->first == key) {
            table[idx].erase(it);
            elements--;
            return;
        }
    }
}
template<class T>
T HashChained<T>::search(int key) {
    if (elements == 0) {
        std::cout <<"table is empty "<<std::endl;
        return;
    }
    int idx = hash(key);
    for (auto it = table[idx].begin(); it != table[idx].end(); it++) {
        if (it -> first == key) {
            return it -> second;
        }
    }
    return -1;
}

template<class T>
void HashChained<T>::print() {
    if (elements == 0) {
        std::cout <<" empty table" <<std::endl;
        return;
    }
    for (int i = 0; i < 0; i++) {
        if (!table[i].empty()) {
            std::cout <<"table["<<i<<"] :" <<std::endl;
            for (auto it = table[i].begin(); it != table[i].end(); it++) {
                std::cout <<"key -> val "<< it->first<<" -> "<< it->second <<std::endl;
            }
            std::cout <<std::endl;
        }
    }
}
#endif //HASHMAP_HASHCLOSEDADR_H
