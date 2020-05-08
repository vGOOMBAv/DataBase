# DataBase
Simple Database written on C++<br>
Can store list of events for certain dates. Was made for solution of end task of C++ course for beginners.<br>
There are four operators to communicate with Database:<br>
* <b>Add:</b><br>
Adds new event for a certain date.<br>
Syntax:<br>
Add year-month-day event<br>
* <b>Del</b><br>
There are two versions of usage of this function<br>
First one:<br>
Del year-month-day  -- Deletes all events on this day and erases date from the database<br>
Second one:<br>
Del year-month-day EVENT -- Deletes event EVENT from the entered date<br>
* <b>Find</b><br>
Finds all the events on the certain day<br>
Syntax:<br>
Find year-month-day<br>
* <b>Print</b><br>
Prints down all the events from the data base in format<br>
year-month-day event<br>
<b>Syntax:</b><br>
Print<br>

# What could possibly could go wrong
This program have a simple exception handling mechanism. Important thing to know is that in case of<br>
exception catching program will stop its working. Possible errors are:<br>
* Wrong date format
* Wrong Month/Day value
* Wrong command<br>
Program don`t check year value, but if data was entered with some signs before year value you will get<br>
and error. Program accepts digit input in format sign+value. -25 or +25 for example.
