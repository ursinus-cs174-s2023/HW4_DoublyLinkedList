#include "linkedlist.h"
#include <stdio.h>
#include <time.h> 
#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;


/**
 * Compare a student list to an array implementation of list
 * @param gtList A ground truth list
 * @param myList Student list
 * @return 
 */
bool listsEqual(list<int>& gtList, LinkedList<int>& myList) {
    bool equal = true;
    int* arr1 = new int[gtList.size()];
    std::copy(gtList.begin(), gtList.end(), arr1);
    size_t N;
    int* arr2 = myList.toArray(&N);
    for (size_t i = 0; (i < gtList.size()) && (i < N) && equal; i++) {
        equal = arr1[i] == arr2[i];
    }
    delete[] arr2;
    return equal;
}

/**
 * @brief Remove the first instance of a particular element from 
 *        an STL list if that element exists
 * 
 * @param l STL list
 * @param item Element to remove
 */
void removeListItem(list<int>& l, int item) {
    list<int>::iterator it = l.begin();
    bool found = false;
    while (!found && it != l.end()) {
        if (*it == item) {
            found = true;
            l.erase(it);
        }
        else {
            it++;
        }
    }
}

/**
 * @brief Return the int at a particular index in the list
 * 
 * @param l STL list
 * @param idx Index
 * @return int Element to return
 */
int getListAtIndex(list<int>& l, int idx) {
    list<int>::iterator it = l.begin();
    for (int i = 0; i < idx; i++) {
        it++;
    }
    return *it;
}

/**
 * @brief Print out a linked list
 * 
 * @param l STL list
 */
void printList(list<int>& l) {
    list<int>::iterator it = l.begin();
    while (it != l.end()) {
        cout << *it << " ==> ";
        it++;
    }
}

/**
 * @brief Compare student doubly-linked list implementation to 
 * STL's ground truth implementation
 * 
 * @param numOps Number of operations to perform
 * @param seed Random seed for repeatability
 */
void doTest(int numOps, int seed) {
    list<int> gtList;
    LinkedList<int> myList;
    srand(seed);
    for (int i = 0; i < numOps; i++) {
        string operation = "no operation";
        int op = rand() % 100;
        if (op < 40) {
            int x = rand() % numOps;
            stringstream stream;
            stream << "addFirst(" << x << ")";
            operation = stream.str();
            gtList.push_front(x);
            myList.addFirst(x);
        }
        else if (op < 80) {
            int x = rand() % numOps;
            stringstream stream;
            stream << "addLast(" << x << ")";
            operation = stream.str();
            gtList.push_back(x);
            myList.addFirst(x);
        }
        else if (op < 85 && gtList.size() > 0) {
            operation = "removeFirst()";
            gtList.pop_front();
            myList.removeFirst();
        }
        else if (op < 95 && gtList.size() > 0) {
            operation = "removeLast()";
            gtList.pop_back();
            myList.removeLast();
        }
        else if (gtList.size() > 0) {
            int item = getListAtIndex(gtList, rand() % gtList.size());
            stringstream stream;
            stream << "remove(" << item << ")";
            operation = stream.str();
            removeListItem(gtList, item);
            myList.remove(item);
        }
        
        cout << operation << "\n";
        
        if (gtList.size() != myList.size()) {
            cout << "lists do not have the same reported size after a " << operation << "\n";
            cout << "Ground truth size " << gtList.size() <<  ", my size " + myList.size() << "\n";
            cout << "Ground truth list\n-------------------------------\n";
            printList(gtList);
            cout << "\n\nMy list\n-------------------------------\n";
            myList.print();
            return;
        }

        if (!listsEqual(gtList, myList)) {
            cout << "lists not equal after a " + operation << "\n";
            return;
        }
    }
}


int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Usage: ./tester <number of operations> <seed>\n";
        return 1;
    }
    int numOps = atoi(argv[1]);
    int seed = atoi(argv[2]);
    doTest(numOps, seed);
    return 0;
}
