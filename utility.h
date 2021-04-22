/*Name Hongda Lin (lin.3235)*/
/*Date: 23/3/2021*/
#include <iostream>
#include <ios>
#include <stdlib.h>

using namespace std;

#define default_overflow 9999
#define pause_constant 400000000
#define digit_limit 9
#define double_constant 100.0

class Counter{
     public: 
         /* defualt constructors */ 
         Counter();
         /* Overload operator >> for non-default constructors */
         friend istream& operator >>(istream& cin, Counter &redCounter);   

         /* public void function that do increment, (friend Counter operator --(int): version2) */
         friend void operator --(Counter &redCounter);
	 friend void operator -(Counter &redCounter);
	 friend void operator +(Counter &redCounter);
	 friend void operator ++(Counter &redCounter);
        
         /* reset private members to default */
         void reset(); 
         /* set counter mode */
         void add();
         void sub();
         /* public const function that detects overflow and underflow */
         bool overflow() const;
         bool maxoverflow() const;
         bool underZero() const;
         /* public const function that returns the current mode */
	 bool checkMode() const;
         /* public const function that display private members */
         void displayOverflow() const;
         void displayMaxOverflow() const;
         void displayMode() const;
         /* Overload operator << for display current count */
         friend ostream& operator <<(ostream& cout, Counter &redCounter);   
       
     private:
         int count;
         int units;
         int tens;
         int hundreds; 
         int thousands;
         int user_overflow;
         bool addition_mode;
         bool subtraction_mode;
};

/* function prototypes */
/* diplay alert message when overflow or underflow happened */
void displayAlert(const Counter redCounter);
/* display operating menu */
void displayMenu();
/* check user input for instruction */
bool instructionCheck(char instr[50]);
/* Reset Object memeber varaiables and local bool value by reference(address) */
void resetCounter(Counter &redCounter, bool &safe);
/* change addtion_mode to true */
void changeModeAdd(Counter &redCounter);
/* change subtraction_mode to true */
void changeModeSub(Counter &redCounter);
/* function that returns information about current count and user_overflow */
void inquireOverflow(Counter redCounter);
/* function that returns information about current count and default_overflow */
void inquireCapacityOverflow(Counter redCounter);
/* function that returns information about current count and underflow */
void inquireUnderflow(Counter redCounter);
/* check validity for user increment/decrement value (1-9) */
bool valueChecker(int value);
/* units increment/decrement, Object is passed by reference, checkValue is set as false */
void unitsModify(int value, bool checkValue, Counter &redCounter);
/* tens increment/decrement, Object is passed by reference, checkValue is set as false */
void tensModify(int value, bool checkValue, Counter &redCounter);
/* hundreds increment/decrement, Object is passed by reference, checkValue is set as false */
void hundredsModify(int value, bool checkValue, Counter &redCounter);
/* thousands increment/decrement , Object is passed by reference, checkValue is set as false */
void thousandsModify(int value, bool checkValue, Counter &redCounter);
/* clear the console */
void clearConsole();
/* function that could pause and clear the console */
void pause();
/* print error messgae when detect overflow */
void printErrorMessageOver(const Counter redCounter);
/* print error messgae when detect underflow */
void printErrorMessageUnder(const Counter redCounter);
