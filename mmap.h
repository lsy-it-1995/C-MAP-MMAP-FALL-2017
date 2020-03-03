#ifndef MMAP_H
#define MMAP_H
#include <iostream>
#include "../../../Documents/CS8(assignment)/B_PLUS_TREE/b_plus_tree.h"
#include "mpair.h"
#include "../../../Documents/CS8(assignment)/Cs8FinalProject/constant.h"

using namespace std;

template <typename K, typename V>
class MMap
{
public:
    typedef BPlusTree<MPair<K, V> > map_base;
    class Iterator{
    public:
        friend class MMap;
        Iterator(typename map_base::Iterator it=NULL)
        {
            _it = it;
        }
        Iterator operator ++(int unused) //it++;
        {
            Iterator hold = _it;
            _it ++;
            return hold;
        }
        Iterator operator ++()
        {
            _it++;
            return _it;
        }
        MPair<K, V> operator *()
        {
            return *_it;
//            return MPair<K,V> ((*_it).key,(*_it).value_list);
        }
        bool at (const Iterator &other)
        {
            return _it.at(other._it);
        }
        friend ostream& operator <<(ostream& outs, const Iterator& print_me)
        {
            Iterator final = print_me;
            final._it.print_Iterator();
            return outs;
        }
        bool is_null(){ return _it.is_null(); }
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs)
        {
            return lhs._it == rhs._it;
        }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs)
        {
            return (lhs._it != rhs._it);
        }
    private:
        typename map_base::Iterator _it;
    };

    MMap()
    {

    }

    //  Iterators
    Iterator begin()
    {
        return Iterator(mmap.begin());
    }
    Iterator end()
    {
        return Iterator(NULL);
    }

    //  Capacity
    int size() const
    {
        return mmap.size();
    }
    bool empty() const
    {
        return mmap.empty();
    }

    //  Element Access

    const vector<V>& operator[](const K& key) const
    {
        return mmap.get(MPair<K,V> (key)).value_list;
    }
    vector<V>& operator[](const K& key)
    {
        return mmap.get(MPair<K,V> (key)).value_list;
    }

    //  Modifiers
    void insert(const K& k, const V& v)
    {
        mmap.insert(MPair<K,V> (k,v));
    }
    void erase(const K& key)
    {
        mmap.remove(key);
    }
    void clear()
    {
        mmap.clear_tree();
    }
    void printTest()
    {
        cout << mmap << endl;
    }
    //  Operations:
    bool contains(const K& key) const
    {
        return (mmap.contains(key))?true:false;
    }
    bool contains(const K& key)
    {
        return (mmap.contains(key))?true:false;
    }
    vector<V> get(const K& key)
    {
        return mmap.get(MPair<K,V> (key,V())).value_list;
    }
    string get_string(const K& key)
    {
        return mmap.get(MPair<K,V> (key)).value_list;
    }
    Iterator find(const K& key)
    {
        return mmap.find(MPair<K,V> (key));
    }
    int count(const K& key)
    {
        return (*mmap.find(MPair<K,V> (key))).value_list.size();
    }
    // I have not writtent hese yet, but we will need them:
    //    int count(const K& key);
    //    lower_bound
    //    upper_bound
    //    equal_range:

    /*
template <class ForwardIterator, class T>
  ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
  ForwardIterator it;
  iterator_traits<ForwardIterator>::difference_type count, step;
  count = std::distance(first,last);
  while (count>0)
  {
    it = first; step=count/2;
    std::advance (it,step);
    if (!(val<*it))                 // or: if (!comp(val,*it)), for version (2)
    {
    first=++it; count-=step+1;
    }
    else count=step;
  }
  return first;
}
     */

/*
template <class ForwardIterator, class T>
  pair<ForwardIterator,ForwardIterator>
    equal_range (ForwardIterator first, ForwardIterator last, const T& val)
{
  ForwardIterator it = std::lower_bound (first,last,val);
  return std::make_pair ( it, std::upper_bound(it,last,val) );
}
*/

Iterator upper_bound(const K&key)
{
    Iterator it = begin();
    while((*it).key>=key)
    {
        ++it;

    }
    return ++it;

}

Iterator lower_bound(const K&key)
{
    if(mmap.contains(key))
        return mmap.find(key);
    else
        return ++mmap.find(key);
}
    /*
template <class ForwardIterator, class T>
  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
  ForwardIterator it;
  iterator_traits<ForwardIterator>::difference_type count, step;
  count = distance(first,last);
  while (count>0)
  {
    it = first; step=count/2; advance (it,step);
    if (*it<val) {                 // or: if (comp(*it,val)), for version (2)
      first=++it;
      count-=step+1;
    }
    else count=step;
  }
  return first;
}

    */
    bool is_valid()
    {
        return mmap.is_valid();
    }
    MMap<K,V> &operator = (const MMap<K,V> &other)
    {
        mmap.clear_tree();
        mmap.copy_tree(other.mmap);
        return *this;
    }
    friend bool operator ==(MMap<K,V> lhs, string rhs)
    {
        return lhs[COMMAND_str] == rhs;
    }

    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me)
    {
        outs<<print_me.mmap;
//        return outs;
//            MMap<K,V>::Iterator it, prev;
//            MMap<K,V> temp = print_me;
//            it = temp.begin();
//            cout<<"It: "<<temp.begin()<<endl;
//            while(!it.is_null())
//            {
//                if(!it.at(prev))
//                {
//                    cout<<it;
//                    prev = it;
//                }
//                else
//                    it ++;
//            }
            return outs;
//        for(MMap<K, V>::Iterator it = print_me.begin(); !it.is_null();it++)
//        {
//            cout<<"I'm in da zone"<<endl;
//            MPair<K,V> A = *it;
//            cout<<A<<endl;
//                //outs<<*it<<endl;
//        }
//        return outs;
    }
//    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me)
//    {
//        for(MMap<K, V>::Iterator it = print_me.mmap.begin(); it!=print_me.mmap.end();it++)
//        {
//            outs<<*it<<" ";
//        }
//        return outs;
//    }

private:
    BPlusTree<MPair<K, V> > mmap;
};

#endif // MMAP_H


