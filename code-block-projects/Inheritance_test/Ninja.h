#ifndef NINJA_H_INCLUDED
#define NINJA_H_INCLUDED


class Ninja : public Enemy
{
public:
    Ninja();
    Ninja(int);

    void saySomething(string msg) const;
};

#endif // NINJA_H_INCLUDED
