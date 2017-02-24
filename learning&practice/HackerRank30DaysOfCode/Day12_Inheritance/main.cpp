//
// Created by Trung on 2/24/2017.
//


/**
 * PROBLEM STATEMENT:
 * Person and Student, where Person is the base class and Student is the derived class.
 * Completed code for Person and a declaration for Student are provided for you in the editor.
 * Observe that Student inherits all the properties of Person.
 * Complete the Student class by writing the following:
 *
 * A Student class constructor, which has  parameters:
 *       A string, .
 *       A string, .
 *       An integer, .
 *       An integer array (or vector) of test scores, .
 * A char calculate() method that calculates a Student object's average and returns the grade character
 * representative of their calculated average
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


class Person{
protected:
    string firstName;
    string lastName;
    int id;
public:
    Person(string firstName, string lastName, int identification){
        this->firstName = firstName;
        this->lastName = lastName;
        this->id = identification;
    }
    void printPerson(){
        cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
    }

};

class Student :  public Person{
	private:
		vector<int> testScores;
	public:
        /*
        *   Class Constructor
        *
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
          Student(string firstName, string lastName, int id, vector<int> scores)
          : Person(firstName, lastName, id) {
               this->testScores = scores;
           }
        /*
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate() {
            char ans = ' ';
            int sum = 0, a = 0;
           for (int i =0; i < testScores.size(); i++) {
               sum += testScores[i];
           }
            a = sum / testScores.size();
            if (a >= 90 && a <= 100) return 'O';
            else if (a >= 80 && a < 90) return 'E';
            else if (a >= 70 && a < 80) return 'A';
            else if (a >= 55 && a < 70) return 'P';
            else if (a >= 40 && a < 55) return 'D';
            else return 'T';
        }
};
/***
 * http://stackoverflow.com/questions/236129/split-a-string-in-c
 *
 * @param file
 * @return
 */
vector<int> readVectorInput(ifstream & file, int numScores) {
    vector<int> ans(numScores);
    string line;
    while (!file.eof()) {
        getline(file, line);
        std::istringstream iss1(line);
        for (int i = 0; i < numScores; i++) {
            int score;
            iss1 >> score;
            ans[i] = score;
        }
    }
    return ans;
}
int main() {
    string fileName = "input.txt";
    string firstName;
    string lastName;
    int id;
    int numScores;
    vector<int> scores;
    ifstream file("input.txt");
    if (file.is_open()) {
        string line;
        //cin >> firstName >> lastName >> id >> numScores;

        //Get names and id
        getline(file, line);
        std::istringstream iss(line);
        if (!(iss >> firstName >> lastName >> id)) {
            cout << "Error" << endl;
        };

        //Get num of scores
        getline(file, line);
        iss.str(line);
        if (!(iss >> numScores)) {
            cout << "Error" << endl;
        };

        //Get all the scores
        scores = readVectorInput(file, numScores);

        file.close();
    } else {
        cout << "Unable to read file" << endl;
    }

    Student* s = new Student(firstName, lastName, id, scores);
    s->printPerson();
    cout << "Grade: " << s->calculate() << "\n";
    return 0;
}