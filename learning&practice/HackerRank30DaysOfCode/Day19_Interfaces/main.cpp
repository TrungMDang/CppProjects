//
// Created by Trung on 3/9/2017.
//

/**
 * The AdvancedArithmetic interface and the method declaration for the abstract int divisorSum(int n) method
 * are provided in the editor below. Write the Calculator class, which implements the AdvancedArithmetic interface.
 * The implementation for the divisorSum method must be public and take an integer parameter, n, and return the sum of
 * all its divisors.
 * Note: Because we are writing multiple classes in the same file, do not use an access modifier (e.g.: public) in
 * class declaration (or code will not compile); however, the public access modifier before your method declaration
 * for it to be accessible by the other classes in the file.
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class AdvancedArithmetic{
public:
    virtual int divisorSum(int n)=0;
};


class Calculator : public AdvancedArithmetic {
public:
    int divisorSum(int n) {
        int sumDivisors = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                sumDivisors += i;
            }
        }
        return sumDivisors;
    }

};
int main(){
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator();
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;
    return 0;
}