class A;
class B {
public:
    void func1() { 
        A* a = new A();
    }

    void func2(const A& a) {
        //statements
    }

    void func3() {
        A::func(); //static function
    }
};
