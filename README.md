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
g++ -o main main.cpp
./main
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

## Contributions
This is the group assignment of DESIS group 5.
The contributions are made by:
1. Prachi Jindal
2. Radhika Maheshwari
3. Rashi Kulshreshtha
4. Rishmitha Rachakonda
5. Sanika Damle
