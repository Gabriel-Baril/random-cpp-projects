#include "ZFraction.h"
#include <string>
#include <iostream>

ZFraction::ZFraction(int num, int den) : m_num(num), m_den(den)
{
}

ZFraction::ZFraction(int num) : m_num(num)
{
}

ZFraction::ZFraction()
{
}

int ZFraction::getNum() const
{
    return m_num;
}

int ZFraction::getDen() const
{
    return m_den;
}

int ZFraction::simplification()
{
    int pg = pgcd(m_num, m_den);
    m_num /= pg;
    m_den /= pg;

    return m_num , m_den;
}

ZFraction den_comm(ZFraction const& a, ZFraction const& b)
{
    ZFraction resultat;
    int oldDenA = a.getDen();
    int oldDenB = b.getDen();

    int pp = (a.getDen() * b.getDen())/pgcd(a.getDen(),b.getDen());

    a.getDen() = pp;
    b.getDen() = pp;

    int div_b = pp/oldDenB;
    b.getNum() *= div_b;

    int div_a = pp/oldDenA;
    a.getNum() *= div_a;

    return resultat;
}

int pgcd(int a,int b)
{
    while(b != 0)
    {
        const int t = b;
        b = a%b;
        a = t;
    }
    return a;
}




