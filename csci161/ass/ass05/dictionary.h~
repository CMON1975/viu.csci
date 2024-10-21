#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include "dict_except.h"
using namespace std;
template <class K, class T>
class Dictionary {
 public:
  Dictionary();
  ~Dictionary();
  void Insert(K, T &) throw (DuplicateKey);
  T & Lookup(K) throw (NotFound);
  T & Remove(K) throw (NotFound);
 private:
  int Search(K);
  struct Entry {
    K key;
    T * obj;
  };
  Entry * data;
  int cap; //capacity
  int size;
  void GrowArray();
};

template <class K, class T>
  Dictionary <K,T> :: Dictionary()
{ 
  cap = 10;
  size = 0;
  data = new Entry[cap];
}

template <class K, class T>
  Dictionary <K,T> :: ~Dictionary()
{
  delete [] data;
}

template <class K, class T>
  void Dictionary <K,T> :: GrowArray()
{
  cap = cap * 2;
  Entry *tmp = data;
  data = new Entry[cap];
  for(int i=0; i<size; i++) {
    data[i].key = tmp[i].key;
    data[i].obj = tmp[i].obj;
  }
  delete [] tmp;
}

template <class K, class T>
  int Dictionary<K,T> :: Search(K key)
{
  int low = 0;
  int high = size-1;
  int mid;
  while(low <= high) {
    mid = (low+high)/2;
    if(data[mid].key == key)
      return mid;
    if(data[mid].key > key)
      high = mid-1;
    else
      low = mid+1;
  }
  return low;
}

template <class K, class T>
  T & Dictionary <K,T> :: Lookup(K key) throw (NotFound)
{
  int index = Search(key);
  if(index < size && data[index].key == key)
    return *data[index].obj;
  else
    throw NotFound();
}

template <class K, class T>
  void Dictionary <K,T> :: Insert(K key, T & obj) throw (DuplicateKey)
{
  int index = Search(key);
  if(index < size && data[index].key == key)
    throw DuplicateKey();
  if(size >= cap)
    GrowArray();
  for(int i=size; i>index; i--) {
    data[i].key = data[i-1].key;
    data[i].obj = data[i-1].obj;
  }
  data[index].key = key;
  data[index].obj = & obj;
  size++;
}

template <class K, class T>
  T & Dictionary<K,T> :: Remove(K key) throw (NotFound)
{
  int index = Search(key);
  if(index >= size || data[index].key != key)
    throw NotFound();
  T & obj = *data[index].obj;
  for(int i=index; i<size-1; i++) {
    data[i].key = data[i+1].key;
    data[i].obj = data[i+1].obj;
  }
  size--;
  return obj;
}
#endif
