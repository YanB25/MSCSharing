#include <vector>
#include <iostream>
using namespace std;

class Account {
public:
    Account() : money(0) {}
    Account(double m) : money(m) {}
    void MoneyIn(double m) { money += m; cout << "money is " << money << endl; }
    void MoneyOut(double m) { money -= m; cout << "money is " << money << endl;}
private:
    double money;
};

class Command {
public:
    virtual void excute(Account* acc) = 0;
    virtual ~Command(){}
protected:
    double amount_;
};

class PutInMoneyCommand : public Command {
public:
    PutInMoneyCommand(double amount) { amount_ = amount; }
    virtual void excute(Account* acc) { acc->MoneyIn(amount_); }
};

class PutOutMoneyCommand : public Command {
public:
    PutOutMoneyCommand(double amount) { amount_ = amount; }
    virtual void excute(Account* acc) { acc->MoneyOut(amount_); }
};

class PutInAndOutCommand : public Command {
public:
    PutInAndOutCommand() { 
        commands.push_back(new PutInMoneyCommand(100));
        commands.push_back(new PutOutMoneyCommand(20));
    }
    virtual void excute(Account* acc) {
        for (const auto& com : commands) {
           com->excute(acc);
        }
    }
    virtual ~PutInAndOutCommand() {
        for (auto &com : commands) {
            delete com;
        }
    }
private:
    vector<Command*> commands;
};
class Invoker {
public:
    void setCommand(Command* c) { command_ = c; }
    Command* getCommand() { return command_; }
    void call(Account* acc) { command_->excute(acc); }
private:
    Command* command_;
};

int main() {
    Account account(100);
    Command* moneyIn = new PutInMoneyCommand(10);
    Command* moneyOut = new PutOutMoneyCommand(20);
    Command* moneyInAndOut = new PutInAndOutCommand();
    Invoker* invoker = new Invoker();

    invoker->setCommand(moneyIn);
    invoker->call(&account);
    
    delete invoker->getCommand();
    invoker->setCommand(moneyOut);
    invoker->call(&account);

    delete invoker->getCommand();
    invoker->setCommand(moneyInAndOut);
    invoker->call(&account);

    delete invoker->getCommand();
    delete invoker;
    return 0;
}
