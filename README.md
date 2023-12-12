# OOAD GROUP ASSIGNMENT - Group 5

## Overview

This C++ program implements a simple event coordination system where participants can register for events, and the system tracks various roles such as Core Members, Coordinators, Workforce, and Events.

## Table of Contents

- [Getting Started](#getting-started)
- [Usage](#usage)
- [Classes](#classes)
- [contributions](#contributions)

## Getting Started

1. **Clone the repository:**

    ```bash
    git clone https://github.com/yourusername/event-coordination-system.git
    ```

2. **Navigate to the project directory:**

    ```bash
    cd DESIS_OOAD_Group5
    ```

## Usage

Compile the code and run the executable:

```bash
g++ -o fest fest.cpp
./fest
```

Follow the on-screen instructions to interact with the event coordination system.

## Classes

1. **Person:**
    - Base class representing an individual with a name, ID, and phone number.

2. **Participant:**
    - Derived from Person, represents participants who can choose and register for events.

3. **Event:**
    - Represents an event with a name, coordinator, and a set of participants.

4. **Workforce:**
    - Derived from Person, represents individuals involved in event coordination under a Coordinator.

5. **Coordinator:**
    - Derived from Person, represents coordinators overseeing Workforce and managing Events.

6. **CoreMember:**
    - Derived from Person, represents core members with specializations and associations with Coordinators.
  
## UML Class Diagram
The UML class diagram for the event coordination system depicts the relationships and hierarchies among various classes. The system revolves around the base class, `Person`, which encapsulates common attributes such as name, ID, and phone number. Derived from `Person`, the classes include `Participant`, representing individuals registering for events, and three pivotal classes: `CoreMember`, `Workforce`, and `Coordinator`. The latter three classes inherit from `Person` and represent the fundamental roles in the event coordination system. Furthermore, the `CoreMember` class, also derived from `Person`, signifies individuals with specializations and is associated with multiple `Coordinator` instances. The relationships are established through methods such as participant registration, workforce coordination, and event management, forming a comprehensive and interconnected class structure.


![UML Class Diagram](https://raw.githubusercontent.com/r4dhika/DESIS_OOAD_Group5/master/class_diagram.png)

## UML Sequence Diagram
The sequence diagram provides a visual representation of the interactions within the event coordination system when a participant registers for an event. The process is initiated by the user triggering the main function. Subsequently, the system orchestrates a series of method calls and messages as depicted.

![Sequence Diagram](https://raw.githubusercontent.com/r4dhika/DESIS_OOAD_Group5/master/sequence_diagram.png)

## Contributions
This is the group assignment of DESIS group 5.
The contributions are made by:
1. Prachi Jindal
2. Radhika Maheshwari
3. Rashi Kulshreshtha
4. Rishmitha Rachakonda
5. Sanika Damle

