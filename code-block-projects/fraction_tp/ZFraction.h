#ifndef ZFRACTION_H_INCLUDED
#define ZFRACTION_H_INCLUDED

class ZFraction
{
    public:

        ZFraction(int num, int den);
        ZFraction(int num);
        ZFraction();

        int getNum() const;
        int getDen() const;
        int simplification();
        ZFraction den_comm(ZFraction const& a, ZFraction const& b);

    private:

        int m_num;
        int m_den;

};

ZFraction operator+(ZFraction const& a, ZFraction const& b);

int pgcd(int a,int b);


#endif // ZFRACTION_H_INCLUDED
