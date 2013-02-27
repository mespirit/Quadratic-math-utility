// Quadratic math utility.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <iomanip>

using namespace std;
/*
Defines
*/
//#define Pause 'PAUSE';
//#define clear 'CLS';

/*
 Declare variables
*/
double a,b,c; // Quadratic vars
double randx,randy;
double x,x1,x2;
double answ1,answ2;
int loop =0;
int sw = 0;
int cont = 0;
int menuslot = 5;
char menu_array[10][100];
char solv_array[10][100];
char yes_no;

/*
 Declare functions
*/
void main_menu();
void qtest();
int RandomNumber(int Min, int Max);
void qhelp(int a, int b, int c);
int menu(char sel_array[10][100]);

int main(int argc, _TCHAR* argv[])
{
/*
    default menu array values
*/
    strcpy_s(menu_array[1],"1. Test Yourself");
    strcpy_s(menu_array[2],"2. Helper ");
    strcpy_s(menu_array[3],"3. how to solve a Quadratic Equation ");
    strcpy_s(menu_array[4],"4. Quit ");

/*
    how to solve array values
*/
    strcpy_s(solv_array[1],"1. How to use Factoring?");
    strcpy_s(solv_array[2],"2. How to use the Quadratic Formula?");
    strcpy_s(solv_array[3],"3. Back to main menu");

 cout  << showpoint << setprecision(3) << endl;
    start:
    menu(menu_array);
    //qhelp();
	goto start;
    system("CLS");
}

void main_menu()
{
    while(sw > menuslot)
    {
        sw = 0;
    }
    system("CLS");
    switch(sw)
    {
        case 0:
    cout << "Please Choose an option e.g. 1. Start. \n" ;
    for(int i = 0 ; i <= menuslot; i++)
    {
     cout << menu_array[i] << endl ;
    }
    cin >> sw ;
    break;
        case 1:
            qtest();
            break;
        case 2:
            cout << "not yet implemented \n";
            sw = 0;
            break;
        case 3:
            cout << "not yet implemented \n";
            sw = 0;
            break;
        case 4:
            exit(0);
            break;
    }

    system("PAUSE");
}

int menu(char sel_array[10][100])
{
    sw = 0;
    while(sw > menuslot)
    {
        sw = 0;
    }
    if(sw == 0)
    {
    cout << "Please Choose an option e.g. 1. Start. \n" ;
    for(int i = 0 ; i <= menuslot; i++)
    {
     cout << sel_array[i] << endl ;
    }
    sw = 0;
    }
    if(sel_array == menu_array)
    {
        cin >> sw ;

        switch(sw)
        {

        case 1:
            qtest();
            break;
        case 2:
            cout << "not yet implemented \n";
            sw = 0;
            break;
        case 3:
            menu(solv_array);
            sw = 0;
            break;
        case 4:
            exit(0);
            break;
    }
    }

    if(sel_array == solv_array)
    {
        sw = 0;
        cout <<"BLAH \n";
        cin >> sw;
        switch(sw)
        {
        case 1:
            main;
            sw = 0;
            break;
        case 2:
            cout << "BLAH \n";
            sw = 0;
            break;
        case 3:
            cout << "not yet implemented \n";
            sw = 0;
            break;
        case 4:
            exit(0);
            break;
    }

    system("PAUSE");
}

}

void qtest()
{
    start:
/*
    Initialize variables
*/
    sw = 0;
    randx = RandomNumber(-10, 10);
    randy = RandomNumber(-10, 10);
    a = 1;
    b = randx + randy;
    c = randx * randy;
    x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 *a);
    x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

    while(b == 0 || c == 0) // if b or c is 0 regenerate the variables
    {
        randx = RandomNumber(-10, 10);
        randy = RandomNumber(-10, 10);
        a = 1;
        b = randx + randy;
        c = randx * randy;
        x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 *a);
        x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    }

    cout << a <<"x^2 + " << b << "x + " << c << endl;

    cout << "answer x = " << x1 << "," << x2 << endl;

    cout << "Solve " << a << "^2 + " << b << "x + " << c << endl;

    cin >> answ1;
    cin >> answ2;
    if(answ1 == x1 || answ1 == x2 && answ2 == x1 || answ2 == x2)
    {
        cout << "Congratulations!!!!! \n Your Correct" << endl;
    }
    else if(answ1 != x1 || answ1 != x2 && answ2 != x1 || answ2 != x2)
    {
        cout << "You are Wrong :( \n Do you want to try another one? Y/N \n";
        cin >> yes_no;
    }

    if(yes_no == 'y' || yes_no == 'Y')
    {
        goto start;
    }
    else
    {
        cout << "Do you want this equation to be explained \? Y/N \n";
        cin >> yes_no;
    if(yes_no == 'y' || yes_no == 'Y')
    {
        qhelp(a,b,c);
        system("PAUSE");
    }

        system("PAUSE");
    }

}

void qhelp(int a, int b, int c)
{
    cout << "function not yet implemented \n Quiting to main menu \n";
    system("PAUSE");
    system("CLS");
	cout << "Ok our equation is \n" << a << "x^2 + " << b << " + " << c << endl;
	cout << "The way we solve is is :\n " << b << " +- sqrt( (" << b << "^2) - ( 4(" << a << ")" << c << ") ) / " << "2(" << a <<") \n";
	cout << ( -b + sqrt((b*b) - ( 4*1*c) )) / 2*a << endl;
	cout << ( -b - sqrt((b*b) - ( 4*1*c) )) / 2*a << endl;
    cout << x1 << "," << x2 << endl;
		system("PAUSE");
	 
}

int RandomNumber(int Min, int Max)
{
    return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}


