//
// Created by Trung on 3/4/2017.
//

/**
 * TASK:
 *      Given a Book class and a Solution class, write a MyBook class that does the following:
 *          Inherits from Book
 *          Has a parameterized constructor taking these  parameters:
 *              title: string
 *              author: string
 *              price: int
 *      Implements the Book class' abstract display() method so it prints these  lines:
 *          Title: , a space, and then the current instance's .
 *          Author: , a space, and then the current instance's .
 *           Price: , a space, and then the current instance's .
 */

#include <cmath>
#include <iostream>

using namespace std;

class Book{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a){
            title=t;
            author=a;
        }
        virtual void display()=0;

};

class MyBook : public Book {
    private:
        int myPrice;
    public:
        MyBook(string t, string a, int p)
            : Book(t, a){
            this->myPrice = p;
        }
        void display() {
            cout << "Title: " << this->title << endl;
            cout << "Author: " << this->author << endl;
            cout << "Price: " << this->myPrice << endl;
        }
};

int main() {
    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
};
