#include <iostream>
#include "Event.h"

using namespace std;

class DailySchedule
{
private:
    Event *scheduled_events;
    int count;
    Date date;

public:
    DailySchedule()
    {
        scheduled_events = nullptr;
        count = 0;
        date = Date();
    }

    DailySchedule(Date d)
    {
        scheduled_events = nullptr;
        count = 0;
        date = d;
    }

    DailySchedule(const DailySchedule &other)
    {
        count = other.count;
        date = other.date;
        scheduled_events = new Event[count];
        for (int i = 0; i < count; i++)
        {
            scheduled_events[i] = other.scheduled_events[i];
        }
    }

    ~DailySchedule()
    {
        delete[] scheduled_events;
    }

    Date getDate()
    {
        return date;
    }

    Event *getEvents()
    {
        return scheduled_events;
    }
    void sortEvents()
    {
        for(int i=0;i<count-1;i++)
        {
            for(int j=0;j<count-i-1;j++)
            {
                if (scheduled_events[j].getStartTime().getHr() > scheduled_events[j + 1].getStartTime().getHr() ||
                (scheduled_events[j].getStartTime().getHr() == scheduled_events[j + 1].getStartTime().getHr() &&
                scheduled_events[j].getStartTime().getMin() > scheduled_events[j + 1].getStartTime().getMin()))
                {
                    Event temp= scheduled_events[j];
                    scheduled_events[j]=scheduled_events[j+1];
                    scheduled_events[j+1]=temp;

                }
            }
        }
    }

    bool compareTime(Event &e1, Event &e2)
    {
        Time start_time1 = e1.getStartTime();
        Time end_time1 = e1.getEndTime();
        Time start_time2 = e2.getStartTime();
        Time end_time2 = e2.getEndTime();
    if (((start_time1.getHr() < end_time2.getHr()) ||(start_time1.getHr() == end_time2.getHr() && start_time1.getMin() < end_time2.getMin())) &&
        (start_time2.getHr() < end_time1.getHr() ||(start_time2.getHr() == end_time1.getHr() && start_time2.getMin() < end_time1.getMin()))) 
        {
            return true;
        }
        return false;
    }
    void scheduleEvent(Event e)
    {
        if (!e.getDate().isEqual(date))
        {
            cout << "Event date is not the same. Cannot schedule the event." << endl;
            return;
        }

        for (int i = 0; i < count; i++)
        {
            if (compareTime(e, scheduled_events[i]))
            {
                cout << "Event conflict detected. Cannot schedule the event." << endl;
                return;
            }
        }
        Event *newScheduledEvents = new Event[count + 1];
        for (int i = 0; i < count; i++)
        {
            newScheduledEvents[i] = scheduled_events[i];
        }

        newScheduledEvents[count] = e;
        delete[] scheduled_events;
        scheduled_events = newScheduledEvents;
        count++;
        sortEvents();
    }

    void printSchedule()
    {
        for(int i=0;i<50;i++)
        {
            cout<<"*";
        }
        cout<<endl;
        date.dateDisplay();
        cout<<endl;
        for(int i=0;i<count;i++)
        {
            scheduled_events[i].displayEvent();
        }
        for(int i=0;i<50;i++)
        {
            cout<<"*";
        }
    }

    //---------------------------------------DO NOT EDIT---------------------------------------------------

    DailySchedule &operator=(const DailySchedule &other)
    {

        delete[] scheduled_events;

        date = other.date;
        count = other.count;

        if (other.scheduled_events != NULL)
        {
            scheduled_events = new Event[count];
            for (int i = 0; i < count; ++i)
            {
                scheduled_events[i] = other.scheduled_events[i];
            }
        }
        else
        {
            scheduled_events = NULL;
        }

        return *this;
    }
    //-----------------------------------------------------------------------------------------------------
};