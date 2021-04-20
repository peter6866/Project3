#include "demo.h"
#include <iostream>
#include <vector>

using namespace std;




   Box::Box(){
        name = "yao";
        id = 911;
        addr = "us";
        phone = 999;
    }

    void Box::makeFriends(){
        friends.push_back("qqq");
        friends.push_back("www");
        friends.push_back("eee");
        friends.push_back("rrr");
        friends.push_back("ttt");
        friends.push_back("yyy");
        friends.push_back("uuu");
        friends.push_back("iii");
        friends.push_back("ooo");
    }
    void Box::makeMoney(){
        money.push_back(111);
        money.push_back(222);
        money.push_back(333);
        money.push_back(444);
        money.push_back(555);
        money.push_back(666);
        
    }

    vector<string> Box::getFriends(){
        return friends;
    }

    vector<int> Box::getMoney(){
        return money;
    }

