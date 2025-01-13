# Event Organizer

This project is a custom event organizer implemented in C++ using classes. It allows users to manage events by scheduling them on specific dates and times while ensuring no conflicts. The program supports dynamic memory management, sorting, and deep copying for robust functionality.

## Overview of Header Files

- **Time Class**
  - Stores the hour and minute of an event in 24-hour format.
  - Provides getter and setter functions for managing time attributes.

- **Date Class**
  - Stores the day, month, and year of an event.
  - Calculates the day of the week using Zeller's Congruence.

- **Event Class**
  - Represents an event with attributes like name, location, start time, end time, and additional details.

- **DailySchedule Class**
  - Manages events for a single day.
  - Supports dynamic resizing, conflict resolution, and sorting of events by time.

- **Organizer Class**
  - Manages the entire schedule by maintaining multiple daily schedules.
  - Dynamically scales and sorts schedules by date.
