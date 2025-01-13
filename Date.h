#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year,test,test_day,test_month,test_year;
    string dayOfTheWeek;

public:
    // Parameterized constructor
    Date(int _day, int _month, int _year)
    {
        day = _day;
        month = _month;
        year = _year;
        calculateDayOfWeek();
    }

    // Default constructor
    Date()
    {
        day = 30;
        month = 12;
        year = 2000;
        dayOfTheWeek = "";
    }

    // Accessor methods (getters)
    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }

    string getDayOfTheWeek()
    {
        return dayOfTheWeek;
    }

    // Mutator methods (setters)
    void setDay(int _day)
    {
        day = _day;
    }

    void setMonth(int _month)
    {
        month = _month;
    }

    void setYear(int _year)
    {
        year = _year;
    }
        bool isEqual(const Date &other) const
    {
        return (day == other.day) && (month == other.month) && (year == other.year);
    }

    void calculateDayOfWeek()
    {
        int d = day;
        int m = month;
        int y = year;
        if (m < 3)
        {
            m += 12;
            y--;
        }
        int K = y % 100;
        int J = y / 100;
        int dayOfWeek = ((d + ((13 * (m + 1)) / 5) + K +( K / 4) +( J / 4) + (5 * J))) % 7;
       static const string days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        dayOfTheWeek=days[dayOfWeek];
    }
    void dateDisplay()
    {
        cout<<"Schedule for "<<dayOfTheWeek<<", "<<day<<"/"<<month<<"/"<<year<<":"<<endl;
       
    }

    //---------------------------------------DO NOT EDIT---------------------------------------------------

    Date &operator=(const Date &date2)
    {
        if (this == &date2)
        {
            return *this;
        }
        this->day = date2.day;
        this->month = date2.month;
        this->year = date2.year;
        this->dayOfTheWeek = date2.dayOfTheWeek;

        return *this;
    }

    //-----------------------------------------------------------------------------------------------------
};
