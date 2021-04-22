/*Name Hongda Lin (lin.3235)*/
/*Date: 23/3/2021*/
#include <iostream>
#include <ios>
#include <limits>
#include <cctype>
#include <stdlib.h>
#include <cstring>
#include "utility.h"


using namespace std;

int main(){
    char instr[50];
    int value = 0;
    /* declare object redCounter, invoke default constructor */
    Counter redCounter;
    bool continueProgram = true, checkValue = false, safe = true;
    /* let user decide default_overflow or user_overflow */
    cout<<"Please select your counter mode. \nPress 'n' for non-default counter, else the counter is set as default: ";
    cin>>instr;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    pause();
    /* if instruction is 'n', user_overflow, get overflow value from user */
    if(strcmp(instr, "n") == 0){   
       /* invoke non default constructor by operator >> */ 
       cin>>redCounter;
    /* else, default_overflow */
    }else{
       cout<<"DEFAULT MODE ACTIVATED.\n"<<endl;
    }
    /* display overflow value */
    cout<<"THE OVERFLOW VALUE: $"; 
    redCounter.displayOverflow();
    pause();
    /* loop until continueProgram become false */
    while(continueProgram){
          /* display current count at top */
          cout<<redCounter;
          redCounter.displayMode();
	  displayAlert(redCounter);
          cout<<endl;
          /* display menu */
          displayMenu();
          cin>>instr;
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
          /* check user input */
          if(!instructionCheck(instr)){
             pause();          
          } 
          if(strcmp(instr, "+") == 0){
             clearConsole();
             changeModeAdd(redCounter);
             pause();
          }else if(strcmp(instr, "-") == 0){
             clearConsole();
             changeModeSub(redCounter);
             pause();
          /* inquireOverflow when instruction is "o" */
          }else if(strcmp(instr, "o") == 0){
             clearConsole();
             inquireOverflow(redCounter);
             pause();
          /* resetCounter when instruction is "r" */
          }else if(strcmp(instr, "r") == 0){
             clearConsole();
             /* bool value notOverflow will be reset to true */
             resetCounter(redCounter, safe);
             pause();
          /* inquireCapacityOverflow when instruction is "m" */
          }else if(strcmp(instr, "m") == 0){
             clearConsole();
             inquireCapacityOverflow(redCounter);
             pause();
          }else if(strcmp(instr, "n") == 0){
             clearConsole();
             inquireUnderflow(redCounter);
             pause();
          /* change continueProgram to false when instruction is "Q" or "q" */
          }else if(strcmp(instr, "Q") == 0 || strcmp(instr, "q") == 0){
             clearConsole();
             cout<<"Goodbye."<<endl;
             continueProgram = false; 
             pause();    
          /* deal with increment */
          }else{ 
             /* check overflow before increment. If overflow, display error message, set notOverflow to false. User have to reset counter in order to proceed increment */
             if(redCounter.overflow()){
                clearConsole();
                printErrorMessageOver(redCounter);
                safe = false;
             }
	     if(redCounter.underZero()){
                clearConsole();
                printErrorMessageUnder(redCounter);
                safe = false;
	     }
             /* unitsIncrement when instruction is "a" and notOverflow is true */
             if(strcmp(instr, "a") == 0 && safe){
                clearConsole();
                unitsModify(value, checkValue, redCounter);
                /* check overflow, display error message */
                if(redCounter.overflow()){
                   printErrorMessageOver(redCounter);
                }else if(redCounter.underZero()){
                   printErrorMessageUnder(redCounter);
                }
             /* tensIncrement when instruction is "s" and notOverflow is true */
             }else if(strcmp(instr, "s") == 0 && safe){
                clearConsole();
                tensModify(value, checkValue, redCounter);
                /* check overflow, display error message */
                if(redCounter.overflow()){
                   printErrorMessageOver(redCounter);
                }else if(redCounter.underZero()){
                   printErrorMessageUnder(redCounter);
                }
             /* hundredsIncrement when instruction is "d" and notOverflow is true */
             }else if(strcmp(instr, "d") == 0 && safe){
                clearConsole();
                hundredsModify(value, checkValue, redCounter);
                /* check overflow, display error message */
                if(redCounter.overflow()){
                   printErrorMessageOver(redCounter);
                }else if(redCounter.underZero()){
                   printErrorMessageUnder(redCounter);
                }
             /* hundredsIncrement when instruction is "f" and notOverflow is true */
             }else if(strcmp(instr, "f") == 0 && safe){
                clearConsole();
                thousandsModify(value, checkValue, redCounter);
                /* check overflow, display error message */
                if(redCounter.overflow()){
                   printErrorMessageOver(redCounter);
                }else if(redCounter.underZero()){
                   printErrorMessageUnder(redCounter);
                }
             }
          }
    }

}
