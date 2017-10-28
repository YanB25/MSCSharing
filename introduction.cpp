class String {
public:
    void append(char c) { 
        // xxxxx
        size++;
    }
    void trunc(int n) {
        size -= n;
    }
    int size;
private:
    char* buff_;
}

//change to
class String {
public:
    void append(char c){...}
    void trunc(intn) {...}
    int size() {
        int i = 0;
        while (buff_[i] != '\0') i++;
        return i;
    }
private:
    char* buff_;
};

// Ex2
class Book {}
class Magazine{}
void read(const Book& book) {
    cout << book.readout();
}
void read(const Magazine& magazine) {
    cout << magazine.readout();
}

// a bad version
template <typename T>
void read(const T& readable) {
    cout << readable.readout();
}

// a good version
class Readable_Interface {
public:
    virtual string readout() = 0;
};
class Book : public Readable_Interface {}
class Magazine : public Readable_Interface {}
void read(const Readable_Interface& readable) {
    cout << readable.readout();
}
