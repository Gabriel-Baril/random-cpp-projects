#ifndef CHRONO_H
#define CHRONO_H


class Chrono
{
    public:
        Chrono(int,int,int,int);
        virtual ~Chrono();

        void convert();
        void show();
        Chrono operator+(Chrono);
        Chrono operator-(Chrono);

        void setMilliSecond(int millisecond){m_millisecond = millisecond;}
        void setSecond(int second){m_second = second;}
        void setMinute(int minute){m_minute = minute;}
        void setHour(int hour){m_hour = hour;}
        int const getMilliSecond(){return m_millisecond;}
        int const getSecond(){return m_second;}
        int const getMinute(){return m_minute;}
        int const getHour(){return m_hour;}

    protected:

    private:
        int m_millisecond;
        int m_second;
        int m_minute;
        int m_hour;
};


#endif // CHRONO_H
