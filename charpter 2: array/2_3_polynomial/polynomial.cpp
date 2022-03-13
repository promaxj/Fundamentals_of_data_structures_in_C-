/*
Programmer:-   Shivam Mohite
Topic:-        Operator Overloading

Problem Statement:- Implement a class quadratic that represents two degree polynomial of type ax^2+bx+c.
                    Your class will require three data member corresponding to a,b,c.
                    Implement the following operations:
                    1]A constructor( including a default constructor which creates the 0 polynomial).
                    2]Overloaded operator + to add two polynomials of degree 2.
                    3]Overloaded << and >> to print and read polynomials.To do this you will need to decide what you want your
                    input and output format to look like.
                    4]A function eval that computes the value of a polynomial for a given value of x.
                    5]A function that computes the two solutions of the equation ax^2+bx+c=0.

Algorithm:-
     1]Start
     2]Enter the polynomial
     3]Add
     4]Evaluate
     5]Solve
     6]End
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

class poly
{

    float a, b, c;

public:
    poly()
    {
        a = b = c = 0;
    }

    poly(float a, float b, float c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        cout << "\n"
             << a << " x^2 + " << b << " x + " << c;
    }

    //display
    friend void operator<<(ostream &a, poly &p)
    {
        cout << "\n"
             << p.a << " x^2 + " << p.b << " x + " << p.c;
    }

    friend istream &operator>>(istream &input, poly &p)
    {
        input >> p.a >> p.b >> p.c;
        return input;
    }

    poly operator+(poly p)
    {
        poly temp;
        temp.a = a + p.a;
        temp.b = b + p.b;
        temp.c = c + p.c;
        return temp;
    }

    void eval()
    {
        int x;
        cout << "\n Enter the value of x:    ";
        cin >> x;
        float sol = (a * x * x) + (b * x) + c;
        cout << "\n Evaluation of polynomial is:   " << sol;
    }

    void solution()
    {
        float x1, x2;
        x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        cout << "\n Root of the quadratic equation are: " << x1 << "  " << x2;
    }
};

int main()
{
    int ch;
    poly p1, p2, p3;
    cout << "\n Polynomial Operation ";

    while (1)
    {
        cout << "\n\n Menu";
        cout << "\n 1. Create polynomial";
        cout << "\n 2. Accept polynomial";
        cout << "\n 3. Display polynomial";
        cout << "\n 4. Add polynomial";
        cout << "\n 5. Evaluate polynomial";
        cout << "\n 6. Solutions of polynomial";
        cout << "\n 7. Exit";
        cout << "\n Enter Choice:  ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\n Polynomial after initialization ";
            cout << p1;
            cout << p2;
            break;

        case 2:
            cout << "\n Enter first polynomial (a,b,c):    ";
            cin >> p1;
            cout << "\n Enter second polynomial (a,b,c):    ";
            cin >> p2;
            break;

        case 3:
            cout << "\n First polynomial is ";
            cout << p1;
            cout << "\n Second polynomial is ";
            cout << p2;
            break;

        case 4:
            p3 = p1 + p2;
            cout << "\n Addition of two polynomial is    ";
            cout << p3;
            break;

        case 5:
            cout << "\n For first polynomial";
            p1.eval();
            cout << "\n For second polynomial";
            p2.eval();
            break;

        case 6:
            cout << "\n For first polynomial";
            p1.solution();
            cout << "\n For second polynomial";
            p2.solution();
            break;

        case 7:
            exit(0);
            break;
        }
    }
    return 0;
}