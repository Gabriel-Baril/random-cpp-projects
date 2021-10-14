#include <iostream>

using namespace std;

class Rectangle
{
public:
    Rectangle(int base, int hauteur) : m_base(base), m_hauteur(hauteur)
    {
    }

    int getBase() {return m_base;}
    int getHauteur() {return m_hauteur;}

    int additionne(Rectangle const& b)
    {
        return m_base += b.m_base;
    }



private:
    int m_base, m_hauteur;
    int aire;
};

    Rectangle::Rectangle operator+(Rectangle const& a,Rectangle const& b)
    {
        Rectangle() result;
        result = a.additionne(b);
        return result;
    }

int main()
{

    Rectangle rect_1(10,5);
    Rectangle rect_2(20,15);

    cout << rect_1 + rect_2 << endl;


    return 0;
}
