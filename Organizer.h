#include <iostream>
#include "DailySchedule.h"

using namespace std;

class Organizer
{
private:
    DailySchedule *daily_schedules;
    int count;

public:
    Organizer()
    {
        daily_schedules = nullptr;
        count = 0;
    }

    bool compareDates( Date d1,  Date d2)
    {
        return (d1.getYear() > d2.getYear()) ||(d1.getYear() == d2.getYear() && d1.getMonth() > d2.getMonth()) ||
               (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() > d2.getDay());
    }
    void sortDailySchedules()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (!compareDates(daily_schedules[j + 1].getDate(), daily_schedules[j].getDate()))
                {
                    DailySchedule temp = daily_schedules[j];
                    daily_schedules[j] = daily_schedules[j + 1];
                    daily_schedules[j + 1] = temp;
                }
            }
        }
    }
    void scheduleEvent(Event e)
    {
        for (int i = 0; i < count; i++)
        {
            if (daily_schedules[i].getDate().isEqual(e.getDate()))
            {

                daily_schedules[i].scheduleEvent(e);
                return;
            }
        }
        DailySchedule *newSchedules = new DailySchedule[count + 1];
        for (int i = 0; i < count; i++)
        {
            newSchedules[i] = daily_schedules[i];
        }

        newSchedules[count] = DailySchedule(e.getDate());
        newSchedules[count].scheduleEvent(e);

        delete[] daily_schedules;
        daily_schedules = newSchedules;
        count++;
        sortDailySchedules();
    }

    void printAllSchedules()
    {
        for (int i = 0; i < count; i++)
        {
            daily_schedules[i].printSchedule();
            cout << endl;
            cout << endl;
        }
    }
};