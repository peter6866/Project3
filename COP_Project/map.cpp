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
        Node *next;

        Node(T_Key key, T_Value value, Node *next)
        {
            this->key = key;
            this->value = value;
            this->next = next;
        }
    };
    //Constant
    const float MAX_LOAD_FACTOR = 0.75;
    // Variable
    vector<Node *> mapKeys;
    unsigned int mapSize;
    unsigned int mapCapacity;
    float loadFactor;
    hash<T_Key> toGenerateHashValue;
    T_Value defaultValue;

    //T_Key key;

    T_Value value;

public:
    Map()
    {
        mapSize = 0;
        mapCapacity = 3;
        loadFactor = mapSize / mapCapacity;

        mapKeys.resize(mapCapacity);
    }

    void push(T_Key const &key, T_Value const &value)
    {
        // size_t Better compatibility than unorder int
        // *Generate hash code
        size_t hashKey = toGenerateHashValue(key);
        size_t mapKey = hashKey % mapCapacity;
        cout << mapKey << ", " << value << endl;
        // *add new map value in vector;
        // if mapKey in map is empty
        if (mapKeys[mapKey] == nullptr)
        {
            Node *node = new Node(key, value, nullptr);
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
            Node *node = new Node(key, value, mapKeys[mapKey]);
            mapKeys[mapKey] = node;
        }
    }

    // Check if it is overloaded, if so, expand the map capacity by a factor of 2, and re-hash all nodes to encode and store
    void ifOverloadIncreaseCapacity()
    {
        if (loadFactor > MAX_LOAD_FACTOR)
        {
            cout << "increase" << endl;
            // *The map is expanded by a factor of 2. And map re-hash all node list from back to front, and set them
            mapCapacity *= 2;
            mapKeys.resize(mapCapacity);
            for (int i = mapCapacity / 2; i >= 0; i--)
            {
                if (mapKeys[i] != nullptr)
                {
                    size_t hashKey = toGenerateHashValue(mapKeys[i]->key);
                    size_t mapKey = hashKey % mapCapacity;
                    swap(mapKeys[i], mapKeys[mapKey]);
                }
            }
        }
    }

    void showAll()
    {
        cout << "******************" << endl;
        for (size_t i = 0; i < mapCapacity; i++)
        {
            if (mapKeys[i] != nullptr)
            {
                while (mapKeys[i] != nullptr)
                {
                    cout << i << ": " << mapKeys[i]->key << endl;
                    mapKeys[i] = mapKeys[i]->next;
                }
            }
        }
    }
};

main()
{
    Map<string, int> m;
    //m.push("qwe", 1);
    m.push("1", 1);
    m.push("2", 2);
    m.push("3", 3);
    m.push("4", 4);
    m.push("5", 5);
    m.push("6", 6);
    m.push("7", 7);
    m.push("8", 8);
    m.push("9", 9);
    // Map<string, string> m;
    // m.push("1", "1");
    // m.push("2", "2");
    // m.push("3", "3");
    // m.push("4", "4");
    // m.push("5", "5");
    // m.push("6", "6");
    // m.push("7", "7");
    // m.push("8", "8");
    // m.push("9", "9");
    m.showAll();

    return 0;
}
