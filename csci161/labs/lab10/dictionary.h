/******************************************************************* 
File: dictionary.h
Author: Christopher Nilssen (Jack)
Date: Mar 31/07
Updated: Apr 4/07

Overview: Template dictionary ADT, implemented to manage generic
data. Uses array for data management, can grow if required or set
at fixed size.

Notes: Dump function feels like a hack; would likely be better 
with a proper Traverse function.

References: dict_except.h
*******************************************************************/
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include "dict_except.h"
using namespace std;
template <class K, class T>
class Dictionary {
 public:
  Dictionary();
  Dictionary(int);
  ~Dictionary();
  void Insert(K, T &) throw (DuplicateKey, DictionaryFull);
  T & Lookup(K) throw (NotFound);
  T & Remove(K) throw (NotFound);
  T & Dump(int index);
  void DisplayKeys() throw (DictionaryEmpty);
  int GetSize();
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
int Dictionary <K,T> :: GetSize()
{
  //cout << "GetSize called" << endl;
  return size;
}

template <class K, class T>
Dictionary <K,T> :: Dictionary()
{
  //cout << "Default dictionary constructor called" << endl;
  cap = 10;
  size = 0;
  data = new Entry[cap];
}

template <class K, class T>
Dictionary <K,T> :: Dictionary(int cap_in)
{
  //cout << "Overloaded dictionary constructor called" << endl;
  cap = cap_in;
  size = 0;
  data = new Entry[cap];
}

template <class K, class T>
Dictionary <K,T> :: ~Dictionary()
{
  //cout << "Dictionary destructor called" << endl;
  delete [] data;
}

template <class K, class T>
void Dictionary <K,T> :: GrowArray()
{
  //cout << "GrowArray called" << endl;
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
  //cout << "Search called" << endl;
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
  //cout << "Lookup called" << endl;
  int index = Search(key);
  if(index < size && data[index].key == key)
    return *data[index].obj;
  else
    throw NotFound();
}

template <class K, class T>
void Dictionary <K,T> :: Insert(K key, T & obj)
  throw (DuplicateKey, DictionaryFull)
{
  //cout << "Insert called" << endl;
  int index = Search(key);
  if(index < size && data[index].key == key)
    throw DuplicateKey();
  if(size >= cap) {
    //cout << "size:" << size << endl
    //	 << "cap:" << cap << endl;
    //GrowArray(); //if not fixed size
    throw DictionaryFull();
  }
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
  //cout << "Remove called" << endl;
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

template <class K, class T>
T & Dictionary<K,T> :: Dump(int index)
{
  //cout << "Dump called" << endl;
  T & obj = *data[index].obj;
  return obj;
}

template <class K, class T>
void Dictionary<K,T> :: DisplayKeys() throw (DictionaryEmpty)
{
  //cout << "DisplayKeys called" << endl;
  if(size == 0)
    throw DictionaryEmpty();
  for (int i=0; i<size; i++) {
    cout << data[i].key << endl;
  }
}
#endif
