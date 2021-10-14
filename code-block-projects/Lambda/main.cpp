#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

enum Direction {Nord,Sud,Est,Ouest};

struct Stu
{
    int data = 18;
};


class Cat
{
public:
    void speak()
    {
        cout << "HELLO" << endl;
    }

    bool operator()(int x)
    {
        return x % 2;
    }
    class Inner
    {
    public:
        static int a;
    };
};

void test(int x,int y)
{
    class Inner
    {
    public:
        static void speak(int x,int y,string message, function<int(int,int)> func)
        {
            cout << message << " " << func(x,y) << endl;
        }
    };
    Inner::speak(x,y,"MDR",[](int a,int b)
    {
        return a*b;
    });
}

int myMethod(int a)
{
    return a;
}

class
{
private:
    int i = 0;
public:
    void operator()(int x)
    {
        i = x;
    }
    int getData() const
    {
        return i;
    }
} obj,obj2;

int main()
{
    vector<Cat*> arr = {new Cat,new Cat};
    for(unsigned int i = 0;i < arr.size();i++){
        arr.at(i)->speak();
    }

    //function<int(int)> f = myMethod;

    //cout << f(7) << endl;

    //test(6,5);

//    Direction dir = Sud;
//
//    cout << dir << endl;
//
//    int a = 6;
//    function<int(int)> lamb = [a](int x) mutable
//    {
//        a = 10;
//        return (x + a);
//    };
//    Cat cat;

    //cout << cat(5) << endl;
    return 0;
}
