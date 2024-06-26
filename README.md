# MorningstarScript

MorningstarScript is a simple custom terminal shell built in C++ that includes basic command execution and additional features such as background color change commands. This project demonstrates basic shell functionality and can be extended with more features.

## Features

- Execute standard shell commands.
- Autocomplete common commands.
- Change terminal background color amd text color.

## Getting Started

These instructions will help you set up and run MorningstarScript on your local machine or a cloud-based development environment.

### Prerequisites

- C++ compiler (e.g., g++).

### Compilation and Running

1. *Clone the Repository*:
    sh
    git clone https://github.com/yourusername/MorningstarScript.git
    

2. *Compile the Program*:
    sh
     g++ powerShell.cpp -o powerShell
    

3. *Run the Program*:
    sh
    ./powerShell
    

### Commands

Once the shell is running, you can use the following commands:

- *Standard Commands*:
    - Execute commands like dir, cd, copy, del, mkdir, rmdir, echo, ipconfig, ping, tasklist, systeminfo, ls, cp, rm, uname, ps.
- *Change Background Color*:
    - color <bg_color> <fg_color>: Changes the terminal background color and text color
- *Exit the Shell*:
    - exit: Exits the MorningstarScript.

### Example Session

```sh
> dir
 Volume in drive C has no label.
 Volume Serial Number is XXXX-XXXX

 Directory of C:\Users\YourUsername

05/20/2024  10:00 AM    <DIR>          .
05/20/2024  10:00 AM    <DIR>          ..
05/20/2024  10:00 AM                 0 example.txt
               1 File(s)              0 bytes
               2 Dir(s)  XXX,XXX,XXX bytes free
> color 4E
# The background color should change to red and text color to black.
> exit
Bye!