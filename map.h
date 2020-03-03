#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "pair.h"
#include "../../../Documents/CS8(assignment)/B_PLUS_TREE/b_plus_tree.h"
#include <cassert>
#include <string>
#include "../../../Documents/CS8(assignment)/Cs8FinalProject/constant.h"
using namespace std;

template<typename K, typename V>
class Map
{
public:
    typedef BPlusTree<Pair<K, V> > map_base;
    class Iterator{
    public:
        friend class Map;
        Iterator(){}
        Iterator(typename map_base::Iterator it)
        {
            _it = it;
        }
        Iterator operator ++(int unused) //it++
        {
            Iterator add = _it;
            _it++;
            return add;
        }
        Iterator operator ++() //++it
        {
            return ++_it;
        }
        Pair<K, V>& operator *()
        {
            return *_it;

//            return Pair<K,V> ((*_it).key,(*_it).value);
        }
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs)
        {
            return (lhs._it==rhs._it);
        }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs)
        {
            return (lhs._it!=rhs._it);
        }
    private:
        typename map_base::Iterator _it;

    };

    Map(){}
    //  Iterators
    Iterator begin()
    {
        return map.begin();
    }
    Iterator end()
    {
        return Iterator(NULL);
    }

    //  Capacity
    int size() const
    {
        return map.size();
    }
    bool empty() const
    {
        return map.empty();
    }

    //  Element Access
    V& operator[](const K& key)
    {
        const bool debug = false;
        if(debug) cout<<"in operator [] key: "<<key<<endl;
        return map.get(Pair<K,V> (key)).value;
    }

    V& at(const K& key);

    const V& at(const K& key) const;


    //  Modifiers
    void insert(const K& k, const V& v)
    {
        bool debug = false;
        if(debug) cout<<"in insert map"<<endl;
        map.insert(Pair<K,V> (k,v));
        if(debug) cout<<"end of insert map"<<endl;
    }
    void erase(const K& key)
    {
        map.remove(key);
    }
    void clear()
    {
        map.clear_tree();
    }
    V get(const K& key)
    {
        return map.get(Pair<K,V> (key)).value;
    }

    //  Operations:
    Iterator find(const K& key)
    {
        return Iterator(map.find(Pair<K,V>(key)));
    }

    bool contains(const Pair<K, V>& target)
    {
        return map.contains(target);
    }
    bool contains(const Pair<K, V>& target) const
    {
        return map.contains(target);
    }
    int count(const K& key)
    {
        return (*map.find(Pair<K,V> (key)));
    }

    // I have not writtent hese yet, but we will need them:
    //    int count(const K& key);
    //    lower_bound
    //    upper_bound
    //    equal_range:
    Iterator upper_bound(const K&key)
    {
        Iterator it = begin();
        while((*it).key>=key)
        {
            ++it;

        }
        return ++key;

    }

    Iterator lower_bound(const K&key)
    {
        Iterator it;
        if(map.contains(key))
            return map.find(key);
        else
            return ++map.find(key);
    }


    bool is_valid()
    {
        return map.is_valid();
    }
    friend bool operator ==(Map<K,V> lhs, string rhs)
    {
        return lhs[COMMAND_str] == rhs;
    }
    friend ostream& operator<<(ostream& outs, const Map<K, V>& print_me)
    {
        outs<<print_me.map<<endl;
        return outs;
    }
private:
    int key_count;
    BPlusTree<Pair<K, V> > map;
};

#endif // MAP_H
