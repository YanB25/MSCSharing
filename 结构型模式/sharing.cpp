#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Object {
public:
    Object(string s) : s_(s) {}
    virtual ~Object() {}
    string getString() const { return s_; }

    void operation() const { cout << "I am " << s_ << " and I am working.." << endl; }
private:
    string s_;
};

class Factory {
public:
    Factory() {}
    virtual ~Factory(); 
    Object* getObj(string s);
private:
    vector<Object*> strs_;
};

Object* Factory::getObj(string s) {
    for (const auto& i : strs_) {
        if (i->getString() == s) {
            return i;
        }
    }
    strs_.push_back(new Object(s));
    return strs_.back();
}

Factory::~Factory() {
    for (auto& addr : strs_) {
        delete addr;
        addr = nullptr;
    }
}

int main() {
    const string str1 = "yb";
    const string str2 = "lzh";
    Factory factory;
    auto obj1 = factory.getObj(str1);
    auto obj2 = factory.getObj(str2);
    obj1->operation();
    obj2->operation();

    auto obj3 = factory.getObj(str1);
    if (obj1 == obj3) {
        cout << "they are the same obj!" << endl; 
    } else {
        cout << "they are NOT the same obj" << endl;
    }
    return 0;
}
