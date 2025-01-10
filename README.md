# DSDB: Tree-Based Database Management System

## Overview
DSDB (Data Structure Database) is a tree-based database management system implemented in C++. It uses advanced data structures (B-Trees, AVL Trees, and Red-Black Trees) to store, index, and manage data efficiently. The system was designed as a semester project for the **Data Structures** course at FAST National University of Computer and Emerging Sciences.

This project focuses on managing and querying large datasets efficiently using various indexing methods.

## Features
### Supported Operations
1. **Index Creation**:
   - Supports indexing using B-Trees, AVL Trees, and Red-Black Trees.
   - Indexing fields include `ID`, `State`, `Deaths`, and other dataset attributes.
2. **Point Search**:
   - Search for a specific key to retrieve corresponding records.
3. **Range Search**:
   - Retrieve all records within a specified key range.
4. **Update Records**:
   - Modify field values of existing records by specifying the key.
5. **Delete Records**:
   - Remove records based on the specified key.
6. **Where Clause**:
   - Advanced queries with conditions (e.g., delete records where `state = Michigan`).

### Data Management
- Efficient handling of duplicates using linked lists.
- Dynamic memory management for optimal performance.
- Persistent data storage across sessions.

### Performance Tracking
- Tracks the number of disk I/O operations for various operations to measure performance.

## Technology Stack
- **Language**: C++
- **Data Structures**:
  - AVL Trees
  - B-Trees
  - Red-Black Trees
- **Dataset**:
  - Leading causes of death in U.S. states, with fields such as:
    - `ID`, `Year`, `Cause Name`, `State`, `Deaths`, and `Age-Adjusted Death Rate`.

## Installation and Setup
1. Clone the repository:
   ```bash
   git clone https://github.com/Nouman-Amjad/DSDB-TreeDatabase.git
2. Navigate to the project directory:
   ```bash
   cd DSDB-TreeDatabase
3. Compile the code:
   ```bash
   g++ -o DSDB DSDB-TreeDatabase.cpp
4. Run the game:
   ```bash
   ./DSDB

## Directory Structure
- **Main.cpp**: Main program logic.
- **USER.h** & **util.h**: Header file defining tree structures and utilities.
- **data/**: Directory for storing indexed files and temporary data (Will be created on executing code).

## How to Use
- ### Choose a Tree Type:
    - Select between Red-Black Tree, B-Tree, or AVL Tree.
- ### Load or Create Data:
    - Create a new dataset or load an existing one for queries.
- ### Perform Operations:
    - Use the menu-driven interface to execute operations such as search, range queries, updates, deletions, and advanced where clause queries.

## Learning Outcomes
- Mastered tree-based data structures for real-world applications.
- Designed and implemented a database system with efficient data indexing.
- Practiced dynamic memory management and file handling in C++.

## Future Enhancements:
- Implement a graphical user interface (GUI) for better user interaction.
- Add support for multi-threaded operations for faster indexing and querying.
- Extend to support additional indexing methods, such as hash-based indexing.

## Acknowledgments
Special thanks to the faculty at FAST-NUCES for their guidance and support during this project.

## License
This project is licensed under the MIT License.
