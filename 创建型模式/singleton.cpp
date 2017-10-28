class Singleton {
public:
    static Singleton* getInstance();
    static void destroyInstance();
private:
    static Singleton* instance_;

    Singleton() {}
    Singleton(const Singleton& rhs) {}
};
Singleton* Singleton::instance_ = nullptr;
Singleton* Singleton::getInstance() {
    if (instance_ == nullptr) {
        instance_ = new Singleton();
    }
    return instance_;
}
void Singleton::destroyInstance() {
    delete instance_;
    instance_ = nullptr;
}
