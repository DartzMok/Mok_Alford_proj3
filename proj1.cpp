#include <iostream>
#include <string>
#include <array>
#include "proj1.h"

using namespace std;

typedef int (*Functions) (int a, int b);
int counter = 0;

/* Method that converts the given command line arguments
to integers then passes those variables to methods to compute
for a target number
*/

void runProgram(array<string,5> numbers, string target, bool op){
  array<int, 5> nums = {};
  
  for(unsigned int i = 0; i < numbers.size(); i++){
    nums[i] = atoi(numbers[i].c_str());
  }
  int goal = atoi(target.c_str());
  
  if(op == true){
    bruteForceArithmetic(nums, goal);
  }
  else if(op == false){
    bruteForceBitwise(nums, goal);
  }
}


/* Method that checks for duplicate numbers in the expressions
   to ensure that each operand is only used once
*/

bool checkDups(int num1, int num2, int num3, int num4, int num5){
  if(num1 == num2 || num1 == num3 || num1 == num4 || num1 == num5 ||
     num2 == num3 || num2 == num4 || num2 == num5 || num3 == num4 ||
     num3 == num5 || num4 == num5){

    return false;  
  }
  else{
    return true;
  }
}

/* Method that checks every single possible combintation of
arithmetic operators and operands that evaluate to a certain target number.
Then counts the number of correct expressions and prints them out
*/

void bruteForceArithmetic(array<int, 5> numbers, int goal){
  int calculated;
  counter = 0;
  Functions arithmetic[] =
    {
     addition,
     subtraction,
     multiplication,
     division,
     modulous,
    };
  array<string, 5> operands = {"+","-","*","/","%"};
                            
  for(unsigned int a = 0; a < numbers.size(); a++){
    for(unsigned int b = 0; b < numbers.size(); b++){
      for(unsigned int c = 0; c < numbers.size(); c++){
        for(unsigned int d = 0; d < numbers.size(); d++){
          for(unsigned int e = 0; e < numbers.size(); e++){
            for(unsigned int f = 0; f < numbers.size(); f++){
              for(unsigned int g = 0; g < numbers.size(); g++){
                for(unsigned int h = 0; h < numbers.size(); h++){
                  for(unsigned int i = 0; i < numbers.size(); i++){
                    if(checkDups(numbers[a], numbers[c], numbers[e], numbers[g], numbers[i])
                       == true){

                       try{
                         calculated = arithmetic[h](
                                          arithmetic[f](
                                          arithmetic[d](
                                          arithmetic[b](
                                               numbers[a],
                                               numbers[c]),
                                               numbers[e]),
                                               numbers[g]),
                                               numbers[i]);


                         if(calculated == goal){
                           counter++;
                           cout << "(((" << numbers[a] << operands[b] << numbers[c]
                                << ")" << operands[d] << numbers[e] << ")" << operands[f]
                                << numbers[g] << ")" << operands[h] << numbers[i] << endl;
                         }
                       }
                       catch(overflow_error e){
                         calculated = 0;
                       }
                    }
                  }
                }
              }
            }
          }            
        }
      }
    }
  }
 cout << counter << " arithmetic expressions found that evaluate to " << goal << endl;
}

/* Method that checks every single possible combintation of
  bitwise operators and operands that evaluate to a certain target number.
  Then counts the number of correct expressions and prints them out
*/

void bruteForceBitwise(array<int, 5> numbers, int goal){
    int calculated;
    counter = 0;
    Functions bitwise[] =
      {
       bitwiseAnd,
       bitwiseOr,
       bitwiseXOr,
       bitwiseShiftLeft,
       bitwiseShiftRight,
      };
    array<string, 5> operands = {"&","|","^","<<",">>"};

    for(unsigned int a = 0; a < numbers.size(); a++){
      for(unsigned int b = 0; b < numbers.size(); b++){
        for(unsigned int c = 0; c < numbers.size(); c++){
          for(unsigned int d = 0; d < numbers.size(); d++){
            for(unsigned int e = 0; e < numbers.size(); e++){
              for(unsigned int f = 0; f < numbers.size(); f++){
                for(unsigned int g = 0; g < numbers.size(); g++){
                  for(unsigned int h = 0; h < numbers.size(); h++){
                    for(unsigned int i = 0; i < numbers.size(); i++){
                      if(checkDups(numbers[a], numbers[c], numbers[e], numbers[g], numbers[i])
                         == true){

                        try{
                          calculated = bitwise[h](
                                            bitwise[f](
                                            bitwise[d](
                                            bitwise[b](
                                                 numbers[a],
                                                 numbers[c]),
                                                 numbers[e]),
                                                 numbers[g]),
                                                 numbers[i]);


                          if(calculated == goal){
                            counter++;
                            cout << "(((" << numbers[a] << operands[b] << numbers[c]
                                 << ")" << operands[d] << numbers[e] << ")" << operands[f]
                                 << numbers[g] << ")" << operands[h] << numbers[i] << endl;

                          }
                        }
                        catch(overflow_error e){
                          calculated = 0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  cout << counter << " bitwise expressions found that evaluate to " << goal << endl;
}


/* Operators are defined in function form to allow them 
to be put in an array and traversed through during the 
exhaustive search */

int addition(int a, int b) {return a + b;}
int subtraction(int a, int b) {return a - b;}
int multiplication(int a, int b) {return a * b;}
int division(int a, int b) {
  if(b==0){throw overflow_error("Divide by zero");}
  return a / b;
}
int modulous(int a, int b) {
  if(b==0){throw overflow_error("Divide by zero");}
  return a % b;
}

int bitwiseAnd(int a, int b) {return a & b;}
int bitwiseOr(int a, int b) {return a | b;}
int bitwiseXOr(int a, int b) {return a ^ b;}
int bitwiseShiftLeft(int a, int b) {return a << b;}
int bitwiseShiftRight(int a, int b) {return a >> b;}

