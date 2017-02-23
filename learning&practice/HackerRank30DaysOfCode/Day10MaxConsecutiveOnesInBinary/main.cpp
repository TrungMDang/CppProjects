//
// Created by trung on 2/23/2017.
//
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
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

stack<bool> findBinary(int n) {
    stack<bool> s;
    while (n > 0) {
        int r = n % 2;
        n = n / 2;
        if (r == 1) s.push(true);
        else s.push(false);
    }
    return s;
}
void printArray(int a[], int size){
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int findOnesInBinary(int n) {
    int ans = 0, max = 0;
    int data[64] = {0};
    int i = 0;
    bool sawOne = false;
    stack<bool> s = findBinary(n);
    while (!s.empty()) {
        bool e = s.top();
        if (e == true) {
            data[i] += 1;
            if (data[i] > max) max = data[i];
            //cout << "i: " << i << " data: ";
            //printArray(data, i + 1);
        } else {
            i++;
        }
        s.pop();
    }
    return max;
}
int main(){
    int n = 439;
    //cin >> n;
    cout << findOnesInBinary(n) << endl;
    return 0;
}
