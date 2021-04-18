#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T_Key, class T_Value>
class Map
{
private:
    class Node
    {
    public:
        T_Key key;
        T_Value value;
        Node* next;

        Node(T_Key key, T_Value value, Node* next)
        {
            this->key = key;
            this->value = value;
            this->next = next;
        }
    };
    //Constant
    const float MAX_LOAD_FACTOR = 0.75;
    // Variable
    vector<Node*> mapKeys;
    unsigned int mapSize;
    unsigned int mapCapacity;
    float loadFactor;
    hash<T_Key> toGenerateHashValue;
    T_Value defaultValue;

public:
    Map()
    {
        mapSize = 0;
        mapCapacity = 3;
        loadFactor = mapSize / mapCapacity;
        mapKeys.resize(mapCapacity);

    }

    void push(T_Key const& key, T_Value const& value)
    {
        // size_t Better compatibility than unorder int
        // *Generate hash code
        size_t hashKey = toGenerateHashValue(key);
        size_t mapKey = hashKey % mapCapacity;
                // *add new map value in vector;
                // if mapKey in map is empty
        if (mapKeys[mapKey] == nullptr)
        {
            Node* node = new Node(key, value, nullptr);
            mapKeys[mapKey] = node;
            mapSize++;
            loadFactor = (float)mapSize / (float)mapCapacity;
            ifOverloadIncreaseCapacity();
        }
        // *add new map value in node list;
        // if have same mapKey; hash conflict
        // !The newly generated node is stored in the vector, and the next attribute points to the previously stored node
        else
        {
            Node* node = new Node(key, value, mapKeys[mapKey]);
            mapKeys[mapKey] = node;
        }
    }

    // Check if it is overloaded, if so, expand the map capacity by a factor of 2, and re-hash all nodes to encode and store
    void ifOverloadIncreaseCapacity()
    {
        if (loadFactor > MAX_LOAD_FACTOR)
        {
            // *The map is expanded by a factor of 2. And map re-hash all node list from back to front, and set them
            mapCapacity *= 2;
            vector<Node*> tempMapKeys;
            tempMapKeys.resize(mapCapacity);
            int tempMapSize = 0;
            float tempLoadFactor = 0;
            // *Traverse each element of mapkey
            for (int i = mapCapacity / 2 - 1; i >= 0; i--)
            {
                if (mapKeys[i] != nullptr)
                {
                    // * Traverse through the list elements corresponding to each mapkey element
                    Node* curListNodeTemp = mapKeys[i]; // list head
                    while (curListNodeTemp != nullptr)
                    {
                        size_t hashKey = toGenerateHashValue(curListNodeTemp->key);
                        size_t mapKey = hashKey % mapCapacity;
                        // * as same as push() function, no ifOverloadIncreaseCapacity()
                        if (tempMapKeys[mapKey] == nullptr)
                        {
                            Node* node = new Node(curListNodeTemp->key, curListNodeTemp->value, nullptr);
                            tempMapKeys[mapKey] = node;
                            tempMapSize++;
                            tempLoadFactor = (float)tempMapSize / (float)mapCapacity;
                        }
                        // *add new map value in node list;
                        // if have same mapKey; hash conflict
                        // !The newly generated node is stored in the vector, and the next attribute points to the previously stored node
                        else
                        {
                            Node* node = new Node(curListNodeTemp->key, curListNodeTemp->value, tempMapKeys[mapKey]);
                            tempMapKeys[mapKey] = node;
                        }
                        curListNodeTemp = curListNodeTemp->next;
                    }
                }
            }
            mapKeys = tempMapKeys;
            tempMapKeys.clear();
            mapSize = tempMapSize;
            loadFactor = tempLoadFactor;
        }
    }

    T_Value& at(T_Key key)
    {
        size_t hashKey = toGenerateHashValue(key);
        size_t mapKey = hashKey % mapCapacity;
        
        // mapKey must be valid
        // traverse node list until key is found, return value
        Node* tempNode = mapKeys[mapKey];
        while (tempNode != nullptr)
        {
            if (tempNode->key == key)
            {
                T_Value& value = tempNode->value;
                return value;
            }
            else
            {
                tempNode = tempNode->next;
            }
        }
        // If the key is not found after traversal, it means there is no key in the node list, and an error is thrown
        cerr << "error: out of range, can not find this key" << endl;
        throw "can not find key";
    }

    T_Value& operator[](T_Key key)
    {
        try
        {
            return at(key);
        }
        catch (const char* msg)
        {
            cout << "create a new pair value" << endl;
            push(key, defaultValue);
        }
        return at(key);
    }

    void showAll()
    {
        cout << "*********show all*********" << endl;
        for (size_t i = 0; i < mapCapacity; i++)
        {
            if (mapKeys[i] != nullptr)
            {
                Node* curListNodeTemp = mapKeys[i];
                while (curListNodeTemp != nullptr)
                {
                    cout << "mapKey: " << i << ": "
                        << "  key: " << curListNodeTemp->key << "  value: " << curListNodeTemp->value << endl;
                    curListNodeTemp = curListNodeTemp->next;
                }
            }
        }
        cout << "----------show all----------------" << endl;
    }
};
