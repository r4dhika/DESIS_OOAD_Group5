Feedback on Group Assignment-
-> Person class should be named as 'Student',(should be more specific, as only students can participate)
-> Class names should represent what they're about.
-> difference between getName function and displayInfo for person
Participant class 
- events should be private, should be event objects instead of strings(event names), just like done for Coordinator class 
- Renaming issue- rename displayInfo to getEvents
- chooseEvents function should insert event to that participant's list of events, addParticipant should only add participant in Event class, just like done in Event constructor
- What if a particpant tries to register in same event twice, unordered_set is used to handle that, but a message can be displayed. (suggestion, not error)
Event class
- addParticipant shouldn't directly be available, it should be a private function, since we can't directly add a particpant in an event.
- It would be done only when a particpant chooses to register for an event.
- Hence particpant class can be declared as a friend of Event class, and this function should only be accessible from there.
Coordinator class
- workforce and events can be unordered_set/or there should be some way to check duplicacy.
Main.cpp
- Add infinite loop to let user perform multiple actions
- Can show multiple actions with the help of functions instead of keeping it hard-coded
