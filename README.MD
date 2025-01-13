<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Event Organizer Project</title>
</head>
<body style="font-family: Arial, sans-serif; line-height: 1.6; margin: 20px;">

    <h1 style="text-align: center;">Event Organizer</h1>
    <p style="text-align: justify;">
        This project is a custom event organizer implemented in C++ using classes. It allows users to manage events efficiently by scheduling them on specific dates and times while ensuring no conflicts. The program supports dynamic memory management, sorting, and deep copying for robust functionality.
    </p>

    <h2>Overview of Header Files</h2>

    <ul>
        <li>
            <strong>Time Class:</strong> 
            Stores the hour and minute for an event in 24-hour format. Provides getter and setter functions to manage time attributes.
        </li>
        <li>
            <strong>Date Class:</strong> 
            Stores the day, month, and year of an event and calculates the day of the week using Zeller's Congruence.
        </li>
        <li>
            <strong>Event Class:</strong> 
            Represents a single event with attributes such as name, location, start time, end time, and additional details. 
        </li>
        <li>
            <strong>DailySchedule Class:</strong> 
            Manages events for a single day. Supports dynamic resizing, conflict resolution, and sorting of events by time.
        </li>
        <li>
            <strong>Organizer Class:</strong> 
            Maintains the entire schedule by managing multiple daily schedules. Dynamically scales and sorts schedules by date.
        </li>
    </ul>

</body>
</html>
