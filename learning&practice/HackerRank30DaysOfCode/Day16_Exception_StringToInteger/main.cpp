//
// Created by Trung on 3/7/2017.
//

/**
 * Task: Read a string, S, and print its integer value; if S cannot be converted to an integer, print Bad String.
 *
 * Note: You must use the String-to-Integer and exception handling constructs built into your submission language.
 * If you attempt to use loops/conditional statements, you will get a 0 score.
 *
 */
#include <map>
#include <fstream>
#include <iostream>

using namespace std;


int main() {
    string S;
    cin >> S;
    string::size_type st;
    int i;
    try {
        i = stoi(S, &st);
    } catch (invalid_argument) {
        cout << "Bad String" << endl;
        return 0;
    }
    cout << i << endl;
    return 0;
}