#include <cstring>
#include <cstddef>
#include <iostream>
#include <string>
#include <set>
using namespace std;
class StringPool {
public:
    virtual ~StringPool() {} 
    string* getString(const char*);
    static StringPool* getInstance();
    static void destroyInstance();
private:
    set<string*> strs_;
    StringPool() {}
    StringPool(const StringPool&) {}
    static StringPool* instance_;
};
StringPool* StringPool::instance_ = nullptr;


string* StringPool::getString(const char* s) {
    for (auto& str : strs_) {
        if (strcmp(s, str->c_str()) == 0) {
            return str;
        }
    }
    strs_.insert(new string(s));
    return StringPool::getString(s);
}

StringPool* StringPool::getInstance() {
    if (instance_ == nullptr) {
        instance_ = new StringPool();
    }
    return instance_;
}

void StringPool::destroyInstance() {
    for (auto& item : instance_->strs_) {
        delete item;
    }
    delete instance_;
}

int main() {
    auto p_str1 = StringPool::getInstance()->getString("yb");
    auto p_str2 = StringPool::getInstance()->getString("lzh");
    auto p_str3 = StringPool::getInstance()->getString("yb");
    cout << *p_str1 << endl;
    cout << *p_str2 << endl;
    cout << *p_str3 << endl;
    cout << (p_str1 == p_str3) << endl;
    StringPool::destroyInstance();
    return 0;
}
