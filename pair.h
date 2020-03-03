#ifndef PAIR_H
#define PAIR_H
#include <iostream>
#include "../../../Documents/CS8(assignment)/B_PLUS_TREE/arrayfunctions.h"
using namespace std;

template<typename K,typename V>
struct Pair{
    K key;
    V value;
    Pair(const K& k=K(), const V& v=V())
    {
        key = k;
        value = v;
    }

    friend ostream& operator <<(ostream& outs, const Pair<K, V>& print_me)
    {
        outs<<"[K:] "<<print_me.key<<"[V:] "<<print_me.value;
        return outs;
    }
    friend bool operator !=(const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        return lhs.key != rhs.key;
    }
    friend bool operator ==(const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        return lhs.key == rhs.key;
    }
    friend bool operator <=(const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        return lhs.key <= rhs.key;
    }
    friend bool operator >=(const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        return lhs.key >= rhs.key;
    }
    friend bool operator < (const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        return lhs.key < rhs.key;
    }
    friend bool operator > (const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        return lhs.key > rhs.key;
    }
    friend Pair<K, V> operator + (const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        return Pair<K,V>(lhs.key,lhs.value + rhs.value);
    }
    friend Pair<K, V> operator += (const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        return Pair<K,V>(lhs.key,lhs.value + rhs.value);
    }

};


#endif // PAIR_H
