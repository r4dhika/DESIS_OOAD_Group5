#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Event;
unordered_map<string,Event*> allevents;

class CoreMember;

class Person
{
protected:
    string name;
    string ID;
    long long phoneNum;

public:
    Person(const string &n, string id, long long phno) : name(n), ID(id), phoneNum(phno) {}
    string getName() const { return name; }
    void displayInfo() const { 
        cout << "Name  : " << name << endl;
        cout << "ID    : " << ID << endl;
        cout << "Ph.No.: " << phoneNum << endl;
        }
};

class Workforce;
class Coordinator;
class CoreMember;

class Participant : public Person
{
    public:
    unordered_set<string> events;

    Participant(string name, string id, long long phno) : Person(name,id,phno){}

    void chooseEvents(string event) ;
    //Participant(const string &n, int a, const string &e);
    void displayInfo() const;
    
};

class Event
{
    string eventName;
    Coordinator *coordinator;
    unordered_set<Participant *> participants;

public:
    Event(const string &name, Coordinator *coord);
    void addParticipant(Participant *participant);
    void displayInfo() const;
    void displayParticipants() const;
};

class Workforce : public Person
{
    Coordinator *coordinator;

public:
    Workforce(const string &n, string id, long long phno, Coordinator *coord);
    void displayInfo() const;
};

class Coordinator : public Person
{
    CoreMember *coreMember;
    vector<Workforce *> workforce;
    vector<Event *> events;

public:
    Coordinator(const string &n, string id, long long phno, CoreMember *cm);
    void addWorkforce(Workforce *wf);
    void addEvent(Event *event);
    void displayInfo() const;
};

class CoreMember : public Person
{
    string specialization;
    vector<Coordinator *> coordinators;

public:
    CoreMember(const string &n, string id, long long phno, const string &s);
    void addCoordinator(Coordinator *coordinator);
    void displayInfo() const;
};

// Participant
//Participant::Participant(const string &n, int a, const string &e) : Person(n, a), event(e) {}

void Participant::displayInfo() const
{
    Person::displayInfo();
    cout << "Events registered: " << endl;
        for (auto i:events){
            cout << i << endl;
        }
        cout<<endl;
    
}

void Participant::chooseEvents(string event) {
        if (allevents.find(event) == allevents.end()){
            cout << "No such event as "<<event<<" in fest" <<endl;
        }
        else{
        allevents[event]->addParticipant(this);
        cout<< "Hi "<< this->name <<"! Event "<<event<<" added successfully!"<<endl;
        }
        
    }

// Event
Event::Event(const string &name, Coordinator *coord) : eventName(name), coordinator(coord)
{   if (allevents.find(name) == allevents.end()){
    coordinator->addEvent(this);
    allevents.insert(make_pair(name,this));
    cout <<"Event "<<name<<" created!" << endl;}
    else{cout<< "Event already exists!" << endl;}
}

void Event::addParticipant(Participant *participant)
{
    participants.insert(participant);
    participant->events.insert(this->eventName);
}

void Event::displayInfo() const
{
    cout << "Event: " << eventName << endl;
    cout << "Coordinator: " << coordinator->getName() << endl;
    cout << "Total Participants = " << participants.size()<<endl;
}

void Event::displayParticipants() const {
    for (auto i:participants){
        i->Person::displayInfo();
        cout<<endl;
    }cout<<endl;
}

// Workforce 
Workforce::Workforce(const string &n, string id, long long phno, Coordinator *coord) : Person(n, id, phno), coordinator(coord)
{
    coordinator->addWorkforce(this);
}

void Workforce::displayInfo() const
{
    Person::displayInfo();
    cout << "Coordinator: " << coordinator->getName() << endl;
}

// Coordinator
Coordinator::Coordinator(const string &n, string id, long long phno, CoreMember *cm) : Person(n, id, phno), coreMember(cm)
{
    coreMember->addCoordinator(this);
}

void Coordinator::addWorkforce(Workforce *wf)
{
    workforce.push_back(wf);
}

void Coordinator::addEvent(Event *event)
{
    events.push_back(event);
}

void Coordinator::displayInfo() const
{
    Person::displayInfo();
    cout << "Core Member: " << coreMember->getName() << endl;
}

// CoreMember
CoreMember::CoreMember(const string &n, string id, long long phno, const string &s) : Person(n, id, phno), specialization(s) {}

void CoreMember::addCoordinator(Coordinator *coordinator)
{
    coordinators.push_back(coordinator);
}

void CoreMember::displayInfo() const
{
    Person::displayInfo();
    cout << "Specialization: " << specialization << endl;
}

int main()
{
    // initialize
    CoreMember core1("Rajesh Sharma","2020EE11234", 1234567890, "Robotics");
    CoreMember core2("Arya Mishra","2020EE11238",1256893470,"Dance");

    Coordinator coordinator1("Jaya Srivastava","2021MS17896", 1357902468, &core1);
    Coordinator coordinator2("Satvik Singh","2021MS15678",1278345690,&core2);

    Workforce workforce1("Sahil Jain","2022EE33456", 2468097531, &coordinator1);
    Workforce workforce2("Avni Srivastava","2022EE29486", 2445097531, &coordinator2);

    Participant participant1("Harshvardhan Malhotra", "2023CS51152", 9988776655);
    Participant participant2("Harshita Mehra", "2022MT61152", 9879776655);
    
    // displaying the details - 
    cout << "\nCoremember 1:"<<endl;
    core1.displayInfo();
    cout << "\nCoremember 2: "<<endl;
    core2.displayInfo();


    cout << "\nCoordinator 1: "<<endl;
    coordinator1.displayInfo();
    cout << "\nCoordinator 2: "<<endl;
    coordinator2.displayInfo();

    cout << "\nWorkforce 1: "<<endl;
    workforce1.displayInfo();
    cout << "\nWorkforce 2: "<<endl;
    workforce2.displayInfo();


    //adding events
    Event event1("Technotron - Robotics Competition", &coordinator1);
    Event event2("Dance Competition", &coordinator2);

    //displaying details of the participants
    cout << "\nParticipant 1: "<<endl;
    participant1.displayInfo();
    participant1.chooseEvents("Dance garba Competition");
    participant1.chooseEvents("Dance Competition");    
    event2.addParticipant(&participant1);


    cout << "\nParticipant 2: "<<endl;
    participant2.displayInfo();
    participant2.chooseEvents("Technotron - Robotics Competition");
    event1.addParticipant(&participant2);


    //displaying details of events
    cout << "\nEvent 1: "<<endl;
    event1.displayInfo();
    cout << "\nEvent 2: "<<endl;
    event2.displayInfo();

    event1.displayParticipants();
    event2.displayParticipants();

    return 0;
}
