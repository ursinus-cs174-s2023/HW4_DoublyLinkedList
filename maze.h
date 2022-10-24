#ifndef MAZE_H
#define MAZE_H

#include <string>
using namespace std;

class Maze {
    private:
        int rows;
        int cols;
        char** maze;
    
    public:
        Maze(string filename);
        
        /**
         * @brief Print out an ASCII representation of the maze
         * 
         */
        void print();

        /**
         * @brief Traverse the maze
         * 
         * @param milliseconds Number of milliseconds to pause in between each frame
         * @param bfs If true, do a breadth-first search.  If false, do a depth-first search
         */
        void traverse(long milliseconds, bool bfs);

        ~Maze();
};

#endif 