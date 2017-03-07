//
// Created by Trung on 3/5/2017.
//

/**
 * The absolute difference between two integers a and b, is written as |a - b|. The maximum absolute difference
 * between two integers in a set of positive integers, elements, is the largest absolute difference between any
 * two integers in elements.
 * Task:
 *      Complete the Difference class by writing the following:
 *          A class constructor that takes an array of integers as a parameter and saves it to the elements
 *          instance variable.
 *          A computeDifference method that finds the maximum absolute difference between any numbers in
 *          elements and stores it in the maximumDifference instance variable.
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
private:
    vector<int> elements;

public:
    int maximumDifference;

    //Constructor
    Difference(vector<int> ele) {
        this->elements = ele;
    }

    /**
     * Solution:
     *      Sort the array using stable_sort: N * log^2(N)
     *      Return difference between the fist and last elements.
     */
    void computeDifference() {
        std::stable_sort(elements.begin(), elements.end());
        this->maximumDifference = elements[elements.size() - 1] - elements[0];
    }

}; // End of Difference class

int main() {
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}