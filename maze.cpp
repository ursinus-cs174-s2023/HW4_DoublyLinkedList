#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
#include "maze.h"
#include "linkedlist.h"

using namespace std;

Maze::Maze(string filename) {
    ifstream fin(filename);
    string line;
    int lineNo = 0;
    rows = 0;
    cols = 0;
    while (getline(fin, line)) {
        if (lineNo == 0) {
            rows = stoi(line);
            maze = new char*[rows];
        }
        else if (lineNo == 1) {
            cols = stoi(line);
            for (int i = 0; i < rows; i++) {
                maze[i] = new char[cols];
            }
        }
        else {
            for (int j = 0; j < cols; j++) {
                maze[lineNo-2][j] = line[j];
            }
        }
        lineNo++;
    }
    fin.close();
}

/**
 * @brief Print out an ASCII representation of the maze
 * 
 */
void Maze::print() {
    for (int j = 0; j < cols+1; j++) {
        cout << "==";
    }
    cout << "\n";
    for (int i = 0; i < rows; i++) {
        cout << "|";
        for (int j = 0; j < cols; j++) {
            cout << maze[i][j] << " ";
        }
        cout << "|\n";
    }
    for (int j = 0; j < cols+1; j++) {
        cout << "==";
    }
    cout << "\n";
}

/**
 * @brief Traverse the maze
 * 
 * @param milliseconds Number of milliseconds to pause in between each frame
 * @param bfs If true, do a breadth-first search.  If false, do a depth-first search
 */
void Maze::traverse(long milliseconds, bool bfs) {
    // TODO: This is a dummy loop that fills in the maze
    // with x's row by row.  You should instead just have a while
    // loop that goes through as long as something is a linked list
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j< cols; j++) {
            print();
            maze[i][j] = 'X';
            this_thread::sleep_for(chrono::milliseconds(milliseconds));
        }
    }
    
}


Maze::~Maze() {
    for (int i = 0; i < rows; i++) {
        delete[] maze[i];
    }
    delete[] maze;
}

