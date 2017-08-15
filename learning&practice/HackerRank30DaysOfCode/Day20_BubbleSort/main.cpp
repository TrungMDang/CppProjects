//
// Created by Trung on 3/9/2017.
//

/** Given an array, a, of size n containing distinct elements, sort array a in ascending order using the Bubble Sort
 *  algorithm. Once sorted, print the following  lines:
 *      Array is sorted in numSwaps swaps. where numSwaps is the number of swaps that took place.
 *      First element: firstElement where firstElement is the first element in the sorted array.
 *      Last element: lastElement where lastElement is the last element in the sorted array.
 *  Input:
 *      The first line contains an integer, n, denoting the number of elements in array .
 *      The second line contains n space-separated integers describing a.
 */
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * Swap 2 integers without using extra memory.
 */
vector<int> swap(vector<int> arr, int index) {
    arr[index] = arr[index] + arr[index + 1];
    arr[index + 1] = arr[index] - arr[index + 1];
    arr[index] = arr[index] - arr[index + 1];
    return arr;
}

vector<int> bubbleSort(vector<int> a) {
    int numSwaps = 0;
    for (int i = 0; i < a.size(); i++) {
        int numberOfSwaps = 0;
        for (int j = 0; j < a.size() - 1; j++) {
            if (a[j] > a[j+1]) {
                a = swap(a, j);
                numberOfSwaps++;
                numSwaps++;
            }
        }
        if (numberOfSwaps == 0) // No swapping takes place
            break;
    }
    int firstElement = a[0];
    int lastElement = a[a.size() - 1];
    cout << "Array is sorted in " << numSwaps << " swaps." << endl;
    cout << "First Element: " << firstElement << endl;
    cout << "Last Element: " << lastElement << endl;
    return a;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    a = bubbleSort(a);
    return 0;
}
