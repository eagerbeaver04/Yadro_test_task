# Computer Club Management Program

## Description
This project is a program for managing a computer club. The program reads input data from a text file, processes events during the club's working day, calculates revenue, and outputs all the events that occurred as well as the final occupancy and revenue data for each table to the console.

## Project Structure

This section describes the project structure, including a list of files and their purposes:

- [`Message.h`](src/ReaderLib/Message.h): Header file implementing the Message class for convenient string data concatenation.
- [`Time.h`](src/ReaderLib/Time.h): Header file implementing the Time structure for handling time.
- [`Event.h`](src/ReaderLib/Event.h): Header file implementing the Event structure for representing events in the club.
- [`Table.h`](src/ReaderLib/Table.h): Header file implementing the Table structure for representing tables in the club.
- [`Computer_club.h`](src/ReaderLib/Computer_club.h): Header file implementing the Computer_club class, which manages the club.
- [`Computer_club.cpp`](src/ReaderLib/Computer_club.cpp): Source file containing the implementation of the Computer_club class methods.
- [`Parser.h`](src/ReaderLib/Parser.h): Header file implementing the Parser class for parsing input data.
- [`Parser.cpp`](src/ReaderLib/Parser.cpp): Source file containing the implementation of the Parser class methods.
- [`Reader.h`](src/ReaderLib/Reader.h): Header file implementing the Reader class for reading data from a file.
- [`Reader.cpp`](src/ReaderLib/Reader.cpp): Source file containing the implementation of the Reader class methods.
- [`main.cpp`](src/main.cpp): Main source file containing the entry point of the program.
- [`test.txt`](text.txt): Text file with example input data for testing the program.
- `README.md`: The file you are reading now. Contains project description, usage instructions, and other information.

## Input Data Format
The input data is a text file containing:

1. The number of tables as a positive integer.
2. The start and end time of the club's operation, separated by a space.
3. The hourly rate of the club as a positive integer.
4. A list of incoming events, separated by new lines.

## Example Input File
The project includes a test file `test.txt` with the following content:  
```
3  
09:00 19:00  
10  
08:48 1 client1  
09:41 1 client1  
09:48 1 client2  
09:52 3 client1  
09:54 2 client1 1  
10:25 2 client2 2  
10:58 1 client3  
10:59 2 client3 3  
11:30 1 client4  
11:35 2 client4 2  
11:45 3 client4  
12:33 4 client1  
12:43 4 client2  
15:52 4 client4  
```
# Requirements
To build and run the project, you need a C++ compiler (gcc or clang) on Linux, or MinGW/Cygwin on Windows.

## Cloning the Repository
To get a copy of this project on your computer, follow these steps:

1. Open the terminal (command line) on your computer.

2. Choose or create a directory where you want to place the project.

3. Enter the following command to clone the repository:

   ```sh
   git clone https://github.com/eagerbeaver04/Yadro_test_task.git
   ```

## Building and Running
1. Using only gcc compiler:  

To build and run the project, follow these steps:

    1.1. Check the gcc compiler version:
    ```sh
    g++ --version
    ```
    If the compiler is not installed, you need to install it.

    1.2. Navigate to the project folder.

    1.3 Navigate to src directory:
    ```sh
    cd src
    ```
    1.4. Compile the project:
    ```sh
    g++ ReaderLib/Computer_club.cpp ReaderLib/Parser.cpp ReaderLib/Reader.cpp main.cpp -o main_executable
    ```

    1.5. Run the program with the path to input file:
    ```sh
    ./main_executable ../test.txt
    ```

2. Using Cmake utils:

To build and run the project, follow these steps:

    2.1 Check the gcc compiler version:  
     ```sh
    g++ --version
    ```

    If the compiler is not installed, you need to install it.  

    2.2 Navigate to the project folder.    

    2.3 Create `build` directory  
    ```sh
    mkdir build
    ```

    2.4 Navigate to `build` folder  
    ```sh
    cd build
    ```
    2.5 Build project
    ```sh 
    cmake ..
    ```
    2.6 Make project
    ```sh 
    cmake --build .
    ```
    2.7. Navigate to `src` folder
    ```sh
    cd src
    ```
    1.5. Run the program with the path to input file:
    ```sh
    ./main_executable ../../test.txt
    ``` 


