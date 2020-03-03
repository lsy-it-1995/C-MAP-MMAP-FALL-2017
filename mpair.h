#ifndef MPAIR_H
#define MPAIR_H
#include <iostream>
#include <vector>
using namespace std;

template<typename K, typename V>
struct MPair{
    K key;
    vector<V> value_list;

    //--------------------------------------------------------------------------------
    /*  MPair CTORs:
     *  must have these CTORs:
     *  - default CTOR / CTOR with a key and no value: this will create an empty vector
     *  - CTOR with a key AND a value: pushes the value into the value_list
     *  _ CTOR with a key and a vector of values (to replace value_list)
     */
    //--------------------------------------------------------------------------------

    MPair(const K& k=K())
    {
        key = k;
    }
    MPair(const K& k, const V& v)
    {
        key = k;
        value_list.push_back(v);
    }
    MPair(const K& k, const vector<V>& vlist)
    {
        key = k;
        for(int i = 0 ; i <vlist.size();i++)
        {
            value_list.push_back(vlist[i]);
        }
    }

    //--------------------------------------------------------------------------------

    friend ostream& operator <<(ostream& outs, const MPair<K, V>& print_me)
    {
        bool debug = false;
        if(debug) cout<<"in mpair.h operator<<"<<endl;
        if(debug) cout<<"print me valuelist size"<<print_me.value_list.size()<<endl;

        outs<<"["<<print_me.key<<"]->";
        for(size_t i = 0; i < print_me.value_list.size();i++)
        {
            outs<<print_me.value_list[i];
        }

        return outs;
    }
    friend bool operator !=(const MPair<K, V>& lhs, const MPair<K, V>& rhs)
    {
        return lhs.key != rhs.key;
    }
    friend bool operator ==(const MPair<K, V>& lhs, const MPair<K, V>& rhs)
    {
        return lhs.key == rhs.key;
    }

    friend bool operator <= (const MPair<K, V>& lhs, const MPair<K, V>& rhs)
    {
        return lhs.key<= rhs.key;
    }
    friend bool operator >= (const MPair<K, V>& lhs, const MPair<K, V>& rhs)
    {
        return lhs.key >= rhs.key;
    }
    friend bool operator < (const MPair<K, V>& lhs, const MPair<K, V>& rhs)
    {
        return lhs.key< rhs.key;
    }
    friend bool operator > (const MPair<K, V>& lhs, const MPair<K, V>& rhs)
    {
        return lhs.key > rhs.key;
    }

//    friend string& operator += (string& lhs, const V& rhs)
//    {
//        lhs = lhs.push_back(rhs);
//        return lhs;
//    }
//    friend vector<V>& operator += (vector<V>& lhs, const V& rhs)
//    {
//        lhs = lhs.push_back(rhs);
//        return lhs;
//    }
    MPair<K, V>& operator += (const MPair<K, V>& rhs)
    {
        key = rhs.key;

        for(size_t i = 0; i <rhs.value_list.size();i++)
        {
            value_list.push_back(rhs.value_list[i]);
        }
        return *this;
    }
    friend MPair<K, V> operator + (const MPair<K, V>& lhs, const MPair<K, V>& rhs)
    {
        MPair<K,V> temp;
        temp.key = lhs.key;
        temp.value_list = lhs.value_list;
        for(size_t i = 0; i<rhs.value_list.size();i++)
        {
            temp.value_list.push_back(rhs.value_list[i]);
        }
        return temp;
    }
};
#endif // MPAIR_H
