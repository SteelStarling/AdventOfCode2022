
//
// Created by Taylor Hancock on 12/03/22.
//

#include "DayThree.h"
using namespace DayThree;

void DayThree::test() {
    cout << "------ DAY 03 ------" << endl << endl;

    cout << "---- PART ONE ----" << endl;
    cout << "Example: ";
    solvePartOne("exampleInput.txt");
    cout << endl << "Input: ";
    solvePartOne("input.txt");
    cout << "---- PART TWO ----" << endl;
    cout << "Example: ";
    solvePartTwo("exampleInput.txt");
    cout << endl << "Input: ";
    solvePartTwo("input.txt");
}

void DayThree::solvePartOne(string file) {

    ifstream fin(PATH + file);

    if(fin.fail()) { // throws unhandled exception if given invalid input
        throw errc::no_such_file_or_directory;
    }

    int sum = 0;
    for(string line; getline(fin, line, '\n'); ) {
        string first = line.substr(0, line.size() / 2); // holds first half
        string last = line.substr(line.size() / 2); // holds last half

        bool itemExists[52];
        for(int i = 0; i < 52; i++) {
            itemExists[i] = false;
        }

        for(char c : first) {
            if(isupper(c)) { // uppercase
                c -= 39;
            } else { // lowercase
                c -= 97;
            }

            itemExists[c] = true;

        }

        bool found = false;
        for(int i = 0; i < last.length() && !found; i++) {
            char c = last.at(i);
            if(isupper(c)) { // uppercase
                c -= 39;
            } else { // lowercase
                c -= 97;
            }

            if(itemExists[c]) {
                sum += c + 1;
                found = true;
            }
        }
    }

    cout << sum << endl;
}

void DayThree::solvePartTwo(string file) {

}