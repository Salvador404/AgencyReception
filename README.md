Within this project, I tried to use as many different data structures as possible, 
and there wasn't much focus on efficiency, speed, and improving performance.

"Right now, the program isn't doing exactly what it's supposed to ;)"



The program can get data in 2 ways: manually or from a file.
It stores data in a linked list called eventList with two attributes: vip and enter.

## Processing:

It checks each custom_Node (each event)
The enter attribute shows which data is being checked now
emp gets updated with each event (shows when an employee becomes free based on queue status)
New people go to either vip or nonVip queue based on their vip status

If a new VIP arrives and the nonVip queue isn't empty:

      The program accesses people in this queue through res arr[]
      Increases their wait time using the upck function
      
At each processing step, it calculates time passed since last event (delta)
Processes as many items as possible from queues (VIP first) during this time

## Final Output:

    Calculates average wait time by checking res arr[]
    Can save detailed report to a file if user wants

