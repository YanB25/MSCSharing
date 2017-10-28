class Square {
public:
    Square() {}
    virtual void setSide(double s) { side = s; }
    double getSide() const { return side; }
private:
    double side;
};

class Rectangle : public Square {
public:
    Rectangle() {}
    virtual void setSide(double s) { // ??? }
    double getSide() const { return side; }
private:
    int width;
    int height;
    // ??? what about side ?
};


