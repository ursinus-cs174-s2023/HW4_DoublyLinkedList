#include <iostream>
#include "maze.h"

using namespace std;

int main(int argc, char** argv) {
    Maze maze(argv[1]);
    maze.traverse(500);
}