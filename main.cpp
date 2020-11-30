#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Node
{
    int howManyKeys; // licznik ile kluczy zawiera dany wierzchołek -> każdy wierzchołek może posiadać howManyKeys + 1 dzieci
    int *keys;       // tablica z kluczami (wartościami) przechowywanymi w danym wierzchołku
    Node *children;  // tablica ze wskaźnikami do dzieci danego wierzchołka
    Node *parent;    // wskaźnik do rodzica wierzchołka

public:
    Node();                                      // domyślny konstruktor
    Node(int *k, int sizeK);                     // konstruktor z przekazaną tablicą kluczy
    Node(int howManyK, bool insertKeysManually); // konstruktor z przekazaną liczbą kluczy do wpisania ręcznie (bool == true)/wylosowania (bool == false)
    int getKeysNumber();                         // zwraca liczbę kluczy w wierzchołku
    void setKeysNumber(int x);                   // ustawia licznik kluczy
    int getKeyValue(int pos);                    // zwraca wartość klucza z pozycji pos
    void setKeyValue(int pos, int x);            // ustawia wartość x klucza na pozycji pos
    Node *getChild(int pos);                     // zwraca dziecko z pozycji pos
    void setChild(int pos, Node *n);             // ustawia wskaźnik do dziecka n na pozysji pos
    void setParent(Node *n);                     // ustawia rodzica n
    Node *getParent();                           // zwraca rodzica
};
//konstruktor domyślny
Node::Node() {}

//konstruktor tworzący węzeł na podstawie tablicy kluczy
Node::Node(int *k, int sizeK)
{

    this->howManyKeys = sizeK;
    this->keys = new int[sizeK];
    for (int i = 0; i < sizeK; i++)
    {
        this->keys[i] = k[i];
    }
    this->children = new Node[sizeK + 1]{};
    this->parent = nullptr;
}
//konstruuktor tworzący węzeł z ilością kluczy przekazaną i możliwością wprowadzenia wartości ręcznie lub wylosowania
Node::Node(int howManyK, bool insertKeysManually)
{
    this->howManyKeys = howManyK;
    this->keys = new int[howManyKeys];
    this->children = new Node[howManyKeys + 1]{};
    this->parent = nullptr;
    srand(time(NULL));
    if (insertKeysManually)
    {
        for (int i = 0; i < howManyK; i++)
        {
            cin >> this->keys[i];
        }
    }
    else
    {
        for (int i = 0; i < howManyK; i++)
        {
            this->keys[i] = rand() % 100 + 1;
        }
    }
}

//zwraca ilość
int Node::getKeysNumber()
{
    return this->howManyKeys;
}

//ustawia ilość kluczy węzła
void Node::setKeysNumber(int x)
{
    this->howManyKeys = x;
}

//zwaraca wartość klucza na danej pozycji
int Node::getKeyValue(int pos)
{
    if (pos >= 0 && pos < this->howManyKeys)
    {
        return this->keys[pos];
    }
    else
    {
        return -1;
    }
}

//ustawia nową wartość wskazanego przez nas klucza
void Node::setKeyValue(int pos, int x)
{
    if (pos >= 0 && pos < this->howManyKeys)
    {
        this->keys[pos] = x;
    }
}

//zwraca dziecko z podanej pozycji
Node *Node::getChild(int pos)
{
    if (pos >= 0 && pos < this->howManyKeys + 1)
    {
        return &this->children[pos];
    }
    else
    {
        return nullptr;
    }
}

//ustawia dziecko na wskazanej pozycji
void Node::setChild(int pos, Node *n)
{
    if (pos >= 0 && pos < this->howManyKeys + 1)
    {
        this->children[pos] = *n;
    }
}

//ustawia ojca dla węzła
void Node::setParent(Node *n)
{
    this->parent = n;
}

//zwraca ojca
Node *Node::getParent()
{
    return this->parent;
}

class BTree
{
    int minKeys; // minimalna liczba kluczy przechowywana w jednym wierzchołku
    int maxKeys; // maksymalna liczba kluczy przechowywana w jednym wierzchołku
    Node *root;  // korzeń drzewa

public:
    BTree();                           // konstruktor tworzący puste drzewo
    bool empty();                      // zwraca wartość true dla drzewa pustego, false dla niepustego
    Node *getRoot();                   // zwraca wskaźnik do korzenia
    void inorderTraversal(Node *n);    // wypisuje wartości kluczy w porządku rosnącym
    Node *search(int x);               // zwraca wskaźnik do wierzchołka zawierającego klucz x
    void splitNode(Node *n);           // dzieli wierzchołek n na dwa wierzchołki
    void mergeNodes(Node *n, Node *m); // łączy wierzchołki n i m o wspólnym rodzicu
    void insertKey(int x);             // wstawia klucz x do drzewa
    void deleteKey(int x);             // usuwa klucz x z drzewa

    int size(Node *n);   // zwraca rozmiar poddrzewa o korzeniu n
    int height(Node *n); // zwraca wysokość poddrzewa o korzeniu n
    int minimum();       // zwraca wartość minimalną drzewa
    int maximum();       // zwraca wartość maksymalną drzewa
    void clear();        // usuwa wszystkie wierzchołki drzewa
};

int main()
{

    return 0;
}
