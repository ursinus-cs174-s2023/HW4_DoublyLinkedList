#include <iostream>
#include "maze.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Usage: ./mazetester <path to maze> <bfs/dfs>\n";
    }
    else {
        Maze maze(argv[1]);
        int bfs = atoi(argv[2]);
        maze.traverse(500, bfs==1);
    }
    return 0;
}