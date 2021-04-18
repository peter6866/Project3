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

public:
    Map()
    {
        mapSize = 0;
        mapCapacity = 3;
        loadFactor = mapSize / mapCapacity;
        mapKeys.resize(mapCapacity);

        // // ! set defaultValue
        // if (typeid(defaultValue).name() == typeid(bool).name()                  //bool
        //     || typeid(defaultValue).name() == typeid(short).name()              //short
        //     || typeid(defaultValue).name() == typeid(unsigned short).name()     //unsigned short
        //     || typeid(defaultValue).name() == typeid(int).name()                //int
        //     || typeid(defaultValue).name() == typeid(unsigned int).name()       //unsigned int
        //     || typeid(defaultValue).name() == typeid(long).name()               //long
        //     || typeid(defaultValue).name() == typeid(unsigned long).name()      //unsigned long
        //     || typeid(defaultValue).name() == typeid(long long).name()          //long long
        //     || typeid(defaultValue).name() == typeid(unsigned long long).name() //unsigned long long
        //     || typeid(defaultValue).name() == typeid(float).name()              //float
        //     || typeid(defaultValue).name() == typeid(double).name()             //double
        //     || typeid(defaultValue).name() == typeid(long double).name()        //long double
        // )
        // {
        //     try
        //     {
        //         defaultValue = 0;
        //     }
        //     catch(const std::exception& e)
        //     {
        //         std::cerr << e.what() << '\n';
        //     }
        // }
        // else if (typeid(defaultValue).name() == typeid(char).name()                 //char
        //          || typeid(defaultValue).name() == typeid(signed char).name()       //signed char
        //          || typeid(defaultValue).name() == typeid(unsigned char).name()     //unsigned char
        // )
        // {
        //     defaultValue = ' ';
        // }
        // else if (typeid(defaultValue).name() == typeid(string).name()) //string
        // {
        //     cout << "in string" << endl;
        //     defaultValue = NULL;
        // }
    }

    void push(T_Key const &key, T_Value const &value)
    {
        // size_t Better compatibility than unorder int
        // *Generate hash code
        size_t hashKey = toGenerateHashValue(key);
        size_t mapKey = hashKey % mapCapacity;
        cout << "mapKey: " << mapKey << "   key: " << key << ", "
             << "  value: " << value << endl;
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

    // void traverseListUtility(Node *curList)
    // {
    //     if (curList == nullptr)
    //     {
    //         return;
    //     }
    //     traverseListUtility(curList->next)
    //     curList
    // }

    // Check if it is overloaded, if so, expand the map capacity by a factor of 2, and re-hash all nodes to encode and store
    void ifOverloadIncreaseCapacity()
    {
        if (loadFactor > MAX_LOAD_FACTOR)
        {
            cout << "increase" << endl;
            // *The map is expanded by a factor of 2. And map re-hash all node list from back to front, and set them
            mapCapacity *= 2;
            vector<Node *> tempMapKeys;
            tempMapKeys.resize(mapCapacity);
            int tempMapSize = 0;
            float tempLoadFactor = 0;
            // *Traverse each element of mapkey
            for (int i = mapCapacity / 2 - 1; i >= 0; i--)
            {
                if (mapKeys[i] != nullptr)
                {
                    // * Traverse through the list elements corresponding to each mapkey element
                    Node *curListNodeTemp = mapKeys[i]; // list head
                    while (curListNodeTemp != nullptr)
                    {
                        size_t hashKey = toGenerateHashValue(curListNodeTemp->key);
                        size_t mapKey = hashKey % mapCapacity;
                        // * as same as push() function, no ifOverloadIncreaseCapacity()
                        if (tempMapKeys[mapKey] == nullptr)
                        {
                            Node *node = new Node(curListNodeTemp->key, curListNodeTemp->value, nullptr);
                            tempMapKeys[mapKey] = node;
                            tempMapSize++;
                            tempLoadFactor = (float)tempMapSize / (float)mapCapacity;
                        }
                        // *add new map value in node list;
                        // if have same mapKey; hash conflict
                        // !The newly generated node is stored in the vector, and the next attribute points to the previously stored node
                        else
                        {
                            Node *node = new Node(curListNodeTemp->key, curListNodeTemp->value, tempMapKeys[mapKey]);
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

    T_Value &at(T_Key key)
    {
        cout << "*********at*********" << endl;
        size_t hashKey = toGenerateHashValue(key);
        size_t mapKey = hashKey % mapCapacity;
        //cout << mapKey << ", " << key <<  endl;
        // mapKey must be valid
        // traverse node list until key is found, return value
        Node *tempNode = mapKeys[mapKey];
        while (tempNode != nullptr)
        {
            if (tempNode->key == key)
            {
                T_Value &value = tempNode->value;
                cout << "----------at------------" << endl;
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

    T_Value &operator[](T_Key key)
    {
        try
        {
            return at(key);
        }
        catch (const char *msg)
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
                Node *curListNodeTemp = mapKeys[i];
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

main()
{
    Map<string, int> m;
    //m.push("qwe", 1);
    m.push("1", 1);
    m.push("3", 2);
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

    cout << m.at("8") << endl;
    //cout << m.at("2") << endl;
    cout << m.at("3") << endl;
    //cout << m.at("14") << endl;

    cout << "----------[]------------" << endl;
    cout << m["4"] << endl;
    cout << m["8"] << endl;
    cout << m["7"] << endl;
    cout << m["6"] << endl;
    cout << m["5"] << endl;
    //cout << m["4"] << endl;
    //m["13"] = 9999;
    cout << m["13"] << endl;
    // try
    // {
    //     cout << m["8"] << endl;
    //     cout << m["7"] << endl;
    //     cout << m["6"] << endl;
    //     cout << m["5"] << endl;
    //     //cout << m["4"] << endl;
    //     cout << m["16"] << endl;
    // }
    // catch (const char *msg)
    // {
    //     cerr << msg << endl;
    // }

    m.showAll();
    return 0;
}
