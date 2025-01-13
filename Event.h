#include <iostream>
#include "Date.h"
#include "Time.h"

using namespace std;

class Event
{
private:
    string name, location, comment;
    Date date;
    Time start_time;
    Time end_time;

public:
    Event()
    {
        name="";
        location="";
        comment="";

    }

    Event(string n, string l, string c, Date d, Time st, Time et)
    {
        name=n;
        location=l;
        comment=c;
        date=d;
        start_time=st;
        end_time=et;

    }

    Event(Event &event2)
    {
        *this=event2;
    }

    string getName()
    {
        return name;
    }

    string getLocation()
    {
        return location;
    }

    string getComment()
    {
        return comment;
    }

    Date getDate()
    {
        return date;
    }

    Time getStartTime()
    {
        return start_time;
    }

    Time getEndTime()
    {
        return end_time;
    }

    void setName(const string &n)
    {
        name=n;
    }

    void setLocation(const string &l)
    {
        location=l;
    }

    void setComment(const string &c)
    {
        comment=c;
    }

    void setDate(Date &d)
    {
        date=d;
    }

    void setStartTime(Time &t)
    {
        start_time=t;
    }

    void setEndTime(Time &t)
    {
        end_time=t;
    }
    void displayEvent()
    {   
        for(int i=0;i<50;i++)
        {
            cout<<"-";
        }
        cout<<endl;
        cout<<"Event: "<<name<<" at "<<location<<endl;
        cout<<"Start: ";
        start_time.showTime();
        cout<<endl;
        cout<<"End: ";
        end_time.showTime();
        cout<<endl;
        for(int i=0;i<50;i++)
        {
            cout<<"-";
        }
        cout<<endl;
    }
//---------------------------------------DO NOT EDIT---------------------------------------------------

    Event &operator=(const Event &event2)
    {
        
        this->name = event2.name;
        this->location = event2.location;
        this->comment = event2.comment;
        this->date = event2.date;
        this->start_time = event2.start_time;
        this->end_time = event2.end_time;

        return *this;
    }

//-----------------------------------------------------------------------------------------------------

};