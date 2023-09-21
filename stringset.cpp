/*
 * Name: Calvin Aduma
 * Date Submitted:
 * Lab Section: 002
 * Assignment Name: Spell Checker Using Hash Table
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    // resizes Stringset if it gets full. Copies elements in old Stringset
    // to new Stringset and deletes memory allocation of old one.
    hash<string> hashMode;
    if (find(word))
    {
        return;
    }
    if (size==num_elems){
        vector<list<string>> newTable;
        size*=2;
        newTable.resize(size);
        /*for (int i=0; i<num_elems; i++)
            for (auto x:table[i])
                newTable[i].push_back(x);*/
        // clears table and resizes value
        //table.clear();
        //table.resize(size);
        for (int i=0; i<size/2; i++) // accesses elements of vector
        {
            list<string>::iterator pos;
            for (pos = table[i].begin(); pos != table[i].end(); pos++)   // accesses the elements of list and stores in x
                newTable[hashMode(*pos)%size].push_back(*pos); // places x in list after hash
        }
        table = newTable;
    }
    int insert_location = hashMode(word)%size;  // location to place in vector
    table[insert_location].push_back(word);
    num_elems++;
    //cout << "num_elems is: " << num_elems << endl;
}

bool Stringset::find(string word) const
{
    hash<string> hashMode;
    list<string>::const_iterator pos;
    size_t i = hashMode(word) % size;
    //Implement this function
    for (pos = table[i].begin(); pos != table[i].end(); pos++) {
        if (word == *pos){
            return true;
        }
    }
    return false;
}

void Stringset::remove(string word)
{
    hash<string> hashMode;
    list<string>::iterator pos;
    size_t i = hashMode(word) % size;
    //Implement this function
    for (pos = table[i].begin(); pos != table[i].end(); pos++) {
        if (*pos==word){ // front element is a match
            pos = table[i].erase(pos);
            num_elems--; // decrease the size since element was popped
            return;
        }
    }
}