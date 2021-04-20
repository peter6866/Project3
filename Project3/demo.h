#include <iostream>
#include <vector>

using namespace std;

class Box{

private:
    int id;
    string name;
    string addr;
    int phone;
    vector<string> friends;
    vector<int> money;


public:


    Box();

    void makeFriends();
    void makeMoney();

    vector<string> getFriends();

    vector<int> getMoney();
};
