# C-Beginner-Projects

A collection of basic C programs I built while learning C programming.

## Projects

### 1. Contact Book
A terminal-based contact manager. Contacts are saved to `contact_data.txt`, so they persist between runs.

**Files**
- `main.c`: program entry point
- `contact.c`: contact-related functions
- `terminal.c`: terminal/UI helper functions
- `my_lib.h`: header file with declarations
- `contact_data.txt`: stored contact data

**Compile and run**
```bash
cd "Contact Book"
gcc main.c contact.c terminal.c -o contact_book
./contact_book
```

### 2. Number Guessing Game
The computer picks a random number and you try to guess it. Scores/data are stored in `data.txt`.

**Files**
- `main.c`: program entry point
- `user_defined_fn.c`: custom functions
- `user_defined_lib.h`: header file with declarations
- `data.txt`: stored game data
- `Upcoming features`: planned improvements

**Compile and run**
```bash
cd "Number Guessing Game"
gcc main.c user_defined_fn.c -o number_game
./number_game
```

## Prerequisites
- A C compiler such as GCC

## Concepts Practiced
- Functions and header files
- Multi-file C programs
- File handling (reading and writing `.txt` data)
- Random number generation
- Loops and conditionals

## Folder Structure
```
C-Beginner-Projects/
├── Contact Book/
│   ├── main.c
│   ├── contact.c
│   ├── terminal.c
│   ├── my_lib.h
│   └── contact_data.txt
├── Number Guessing Game/
│   ├── main.c
│   ├── user_defined_fn.c
│   ├── user_defined_lib.h
│   ├── data.txt
│   └── Upcoming features
└── README.md
```

## Future Plans
See the `Upcoming features` file in each project folder.
