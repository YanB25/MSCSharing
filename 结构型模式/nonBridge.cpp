#include <string>
#include <iostream>
using namespace std;
class Shape {
public:
    virtual string getName() const = 0;
};

class Rectangle : public Shape {
public:
    virtual string getName() const { return "Rectangle"; }
};

class Circle : public Shape{
public:
    virtual string getName() { return "circle"; }
};

class RedRectangle : public Rectangle {
public:
    string getColor() const { return "red"; }
};

class BlueRectangle : public Rectangle {
public:
    string getColor() const { return "blue"; }
};

