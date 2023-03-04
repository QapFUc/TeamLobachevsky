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
        ItemTMapList(){key = nullptr;data= nullptr;next= this;prev= this;};
        Key GetKey(){};
        void SetKey(Key* k){};
        Data GetData(){};
        void SetData(Data* d){};
    };
    ItemTMapList* items;
    int size;
public:
    TMapList();
    TMapList(const TMapList<Key, Data>& p);
    ~TMapList();
    Data& operator[](Key* k);
    void Add(Key* k, Data* d);
    void Del(Key* k);
};
template <class Key, class Data>
TMapList<Key,Data>::TMapList() {}

template <class Key, class Data>
TMapList<Key,Data>::~TMapList() {}

template <class Key, class Data>
TMapList<Key,Data>::TMapList(const TMapList<Key, Data>& p) {}


template <class Key, class Data>
void TMapList<Key,Data>::Add(Key *k, Data *d) {}

template <class Key, class Data>
void TMapList<Key,Data>::Del(Key *k) {}

template <class Key, class Data>
Data& TMapList<Key,Data>::operator[](Key *k) {}
#endif //TMAPLIST_H
