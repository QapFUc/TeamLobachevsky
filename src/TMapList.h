#ifndef TMAPLIST_H
#define TMAPLIST_H
template <class Key, class Data>
class TMapList
{
protected:
    class ItemTMapList{
    protected:
        Key* key;
        Data* data;
        ItemTMapList* next;
        ItemTMapList* prev;
    public:
        ItemTMapList(){key = nullptr;data= nullptr;next=this;prev=this;};
        Key GetKey(){return key;};
        void SetKey(Key* k){key = k;};
        Data GetData(){return data;};
        void SetData(Data* d){data = d};
    };
    ItemTMapList* items;
    int size = 0;
public:
    TMapList(const Key* );
    TMapList(const TMapList<Key, Data>& p);
    ~TMapList();
    Data& operator[](Key* k);
    void Add(Key* k, Data* d);
    void Del(Key* k);
};
template <class Key, class Data>
TMapList<Key,Data>::TMapList()
{
    items = new(ItemTMapList);
    size += 1;
    next = nullptr;
    prev = nullptr;
}

template <class Key, class Data>
TMapList<Key,Data>::~TMapList()
{
    for(int i = 0:i<size;i++)
    {   
        if (items != nullptr) { delete[] items; }
        items = next;
    }
    size = 0;
}

template <class Key, class Data>
TMapList<Key,Data>::TMapList(const TMapList<Key, Data>& p)
{
  for (int i = 0; i < size; i++)
  {
    items.SetKey(p.GetKey());
    items.SetData(p.GetData());
  }
  size = p.size;
}


template <class Key, class Data>
void TMapList<Key,Data>::Add(Key *k, Data *d)
{
    items.prev = items;
    items = new(ItemTMapList);
    items.SetData(d);
    items.SetKey(k);
}

template <class Key, class Data>
void TMapList<Key,Data>::Del(Key *k)
{
}

template <class Key, class Data>
Data& TMapList<Key,Data>::operator[](Key *k)
{

}
#endif //TMAPLIST_H
