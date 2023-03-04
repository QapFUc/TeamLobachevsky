#ifndef __TMap_H__
#define __TMap_H__

template <class Key, class Data>
class TMap
{
protected:
  int size;
  int count;
  Key** keys;
  Data** items;
  int FindID(Key* k);
public:
  TMap(int _size = 100);
  TMap(const TMap<Key, Data>& p);
  ~TMap();
  Data& operator[](Key* k);
  void Add(Key* k, Data* d);
  void Del(Key* k);
};

#endif

template<class Key, class Data>
int TMap<Key, Data>::FindID(Key* k)
{
  for (int i = 0; i < size; i++)
  {
    if (keys[i] != nullptr)
    {
      if (*(keys[i]) == *(k))
      {
        return i;
      }
    }
  }
  return -1;
}

template<class Key, class Data>
TMap<Key, Data>::TMap(int _size)
{
  if ( _size <= 0 ) { throw "Invalid size"; }
  size = _size;
  count = 0;
  keys = new Key*[size];
  items = new Data*[size];
  for (int i = 0; i < size; i++)
  {
    keys[i] = nullptr;
    items[i] = nullptr;
  }
}

template<class Key, class Data>
TMap<Key, Data>::TMap(const TMap<Key, Data>& p)
{
  size = p.size;
  count = p.count;
  keys = new Key*[size];
  items = new Data*[size];
  for (int i = 0; i < size; i++)
  {
    keys[i] = p.keys[i];
    items[i] = p.items[i];
  }
}

template<class Key, class Data>
TMap<Key, Data>::~TMap()
{
  size = 0;
  count = 0;
  if (keys != nullptr) { delete[] keys; }
  if (items != nullptr) { delete[] items; }
  keys = nullptr;
  items = nullptr;
}

template<class Key, class Data>
Data& TMap<Key, Data>::operator[](Key* k)
{
  for (int i = 0; i < size; i++)
  {
    if (keys[i] != nullptr)
    {
      if (*(keys[i]) == *(k))
      {
        return *(items[i]);
      }
    }
  }
}

template<class Key, class Data>
void TMap<Key, Data>::Add(Key* k, Data* d)
{
  if (count >= size)
  {
    throw "OOR";
  }
  keys[count] = k;
  items[count] = d;
  count++;
}

template<class Key, class Data>
void TMap<Key, Data>::Del(Key* k)
{
  if (count > 0)
  {
    int i = FindID(k);
    if (i != -1)
    {
      keys[i] = nullptr;
      items[i] = nullptr;
      for (; i < count - 1; i++)
      {
        keys[i] = keys[i + 1];
        items[i] = items[i + 1];
      }
      count--;
    }
  }
  else { throw "OOR"; }
}