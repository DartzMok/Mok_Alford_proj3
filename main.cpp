#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <vector>
#include <array>
#include "proj1.h"
using namespace std;

/* Main method that calls other methods from
proj1.cpp in order to exhaustively search through 
an array of numbers and using arithmetic or bitwise
operators to compute a certain number */

int main(int argc, char * argv[]){
  vector<string> commandLineArgs;
  array<string,5> operands = {};
  bool usingArithmetic;
  string targetNum;
    
  for(int i = 1; i < argc; i++){
    commandLineArgs.push_back(argv[i]);
  }
  
  for(unsigned int i = 0; i < commandLineArgs.size(); i++){
    if(commandLineArgs[i] == "-v"){
      int populate = 0;
      while(populate < 5){
        operands[populate] = commandLineArgs[i+1];
        i++;
        populate++;
      }
    }
    else if(commandLineArgs[i] == "-a"){usingArithmetic = true;}
    else if(commandLineArgs[i] == "-b"){usingArithmetic = false;}
    else if(commandLineArgs[i] == "-e"){
      targetNum = commandLineArgs[i+1];
    }
  }
  runProgram(operands, targetNum, usingArithmetic);
  return 0;
}
