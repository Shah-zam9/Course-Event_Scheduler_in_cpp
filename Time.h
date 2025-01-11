#include <iostream>
using namespace std;

// Time class template
class Time
{
private:
    int hr, min;

    // Defining functions
public:
    Time(int h, int m)
    {
        hr=h;
        min=m;
    }

    Time()
    {
        hr=0;
        min=0;
    }

    // Functions to set the time attributes
    void setHr(int h)
    {
        hr=h;
    }

    void setMin(int m)
    {
        min=m;
    }


    // Functions to get the time attributes
    int getHr()
    {
        return hr;
    }

    int getMin()
    {
        return min;
    }

    // Functions to set the time
    // in the Time class template
    void setTime(int x, int y, int z)
    {
        hr=x;
        min=y;
    }

    // Function to print the time
    // in HH:MM:SS format
    void showTime()
    {
        cout<<(hr<10? "0":"")<<hr<<":"<<(min<10?"0":"")<<min;
    }

    
    // = Operator overloading to assign the time from one object to another
    Time &operator=(const Time &t)
    {
        if (this != &t)
        {
            hr = t.hr;
            min = t.min;
        }
        return *this;
    }
};