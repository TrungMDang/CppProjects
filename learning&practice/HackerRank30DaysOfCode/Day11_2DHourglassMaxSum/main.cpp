//
// Created by trung on 2/24/2017.
//

/***
 * Find the maximum sum of values of hourglasses of a 2D vector.
 *
 * Link: https://www.hackerrank.com/challenges/30-2d-arrays
 *
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

/***
 * Print an hourglass.
 *
 * @param hg input vector
 */
void printHourglass(vector<vector<int>> hg) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << hg[row][col] << " ";
        }
        cout << endl;
    }
}
/***
 * Get the hourglasses from a 2D vector of vectors of type int.
 * The [0][0] index of the hourglass returned starts at index [r][c] of the input vector.
 *
 * @param arr The 2D vector of vectors
 * @param r number of rows
 * @param c number of columns
 * @return an hourglass starting from element at index arr[r][c]
 */
vector<vector<int>> getHourglass(vector<vector<int>> arr, int r, int c) {
    vector<vector<int>> hg(3, vector<int>(3, 0));
    //i     j+1  maxC
    //i+1   j+1  maxC
    //maxR  j+1  maxC

    int maxR = r + 2, maxC = c + 2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i != 1 && (j != 0 || j != 2)) || (i == 1 && j == 1))
                hg[i][j] = arr[i + r][j + c];
        }
    }
    printHourglass(hg);
    return hg;
}
/***
 * Return the sum of values of an hourglass.
 *
 * @param hg The hourglass to be operated.
 * @return The sum of values of an hourglass.
 */
int getHgSum(vector<vector<int>> hg) {
    int sum = 0;
    for (int row = 0; row < hg.size(); row++) {
        for (int col = 0; col < hg[0].size(); col++) {
            sum += hg[row][col];
        }
    }
    return sum;
}

/***
 * Return a vector of vectors from specified input file.
 * Modified from http://www.cplusplus.com/forum/beginner/82458/.
 *
 * @param col The maximum number of columns of input 2D array.
 * @return A 2D vector of vectors.
 */
std::vector<std::vector<int>> read2DVectorInput(string inputName, int col) {
    std::fstream input;
    input.open(inputName, ios::in);
    std::vector<std::vector<int>> v;
    std::vector<int> rowV(col);
    int row = 0;
    if (input.is_open()) {
        while (!input.eof()) {
            v.push_back(rowV);
            for (int c = 0; c < col; c++) {
                input >> v[row][c];
            }
            row++;
        }
        input.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    input.close();
    return v;
}

int main(){
    string fileName = "input.txt";
    vector< vector<int> > arr = read2DVectorInput(fileName, 6);
    int maxSum = 0;
    for (int i =0; i < arr.size() - 2; i++) {
        for (int j = 0; j < arr[0].size() - 2; j++) {
            vector<vector<int>> hg = getHourglass(arr, i, j);
            cout << "-----------" << endl;
            int sum = getHgSum(hg);
            if (sum > maxSum) maxSum = sum;
        }
    }
    cout << maxSum << endl;
    return 0;
}