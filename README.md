# DataBase
Simple Database written on C++
Can store list of events for certain dates. Was made for solution of end task of C++ course for beginners.
There are four operators to communicate with Database:
-Add:
Adds new event for a certain date.
###Syntaxis:
Add year-month-day event
-Del
There are two versions of usage of this function
###First one:
Del year-month-day  -- Deletes all events on this day and erases date from the database
###Second one:
Del year-month-day EVENT -- Deletes event EVENT from the entered date
-Find
Finds all the events on the certain day
###Syntaxis:
Find year-month-day
-Print
Prints down all the events from the data base in format
year-month-day event
###Syntaxis:
Print
