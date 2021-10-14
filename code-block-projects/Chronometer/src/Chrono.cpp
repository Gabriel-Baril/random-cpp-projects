#include "Chrono.h"
#include <iostream>

Chrono::Chrono(int milli,int second,int minute,int hour)
{
    Chrono::setMilliSecond(milli);
    Chrono::setSecond(second);
    Chrono::setMinute(minute);
    Chrono::setHour(hour);

    Chrono::convert();
}

void Chrono::convert(){
    if(Chrono::getMilliSecond() >= 1000){
        Chrono::setSecond(Chrono::getSecond() + (int)(Chrono::getMilliSecond()/1000));
        Chrono::setMilliSecond(Chrono::getMilliSecond() % 1000);
    }
    if(Chrono::getSecond() >= 60){
        Chrono::setMinute(Chrono::getMinute() + (int)(Chrono::getSecond()/60));
        Chrono::setSecond(Chrono::getSecond() % 60);
    }
    if(Chrono::getMinute() >= 60){
        Chrono::setHour(Chrono::getHour() + (int)(Chrono::getMinute()/60));
        Chrono::setMinute(Chrono::getMinute() % 60);
    }
}

Chrono Chrono::operator+(Chrono c){
    Chrono chrono(0,0,0,0);
    chrono.setMilliSecond(Chrono::getMilliSecond() + c.getMilliSecond());
    chrono.setSecond(Chrono::getSecond() + c.getSecond());
    chrono.setMinute(Chrono::getMinute() + c.getMinute());
    chrono.setHour(Chrono::getHour() + c.getHour());

    chrono.convert();

    return chrono;
}

Chrono Chrono::operator-(Chrono c){
    Chrono chrono(0,0,0,0);
    chrono.setMilliSecond(Chrono::getMilliSecond() - c.getMilliSecond());
    chrono.setSecond(Chrono::getSecond() - c.getSecond());
    chrono.setMinute(Chrono::getMinute() - c.getMinute());
    chrono.setHour(Chrono::getHour() - c.getHour());

    chrono.convert();

    return chrono;
}

void Chrono::show(){
    std::cout << getHour() << "H ," << getMinute() << "M ," << getSecond() << "S ," << getMilliSecond() << "MS" << std::endl;
    Chrono::convert();
}

Chrono::~Chrono()
{
    //dtor
}
