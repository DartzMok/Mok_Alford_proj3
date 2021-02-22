#ifndef PROJ1_H
#define PROJ1_H
#include <string>
#include <array>
using namespace std;

void runProgram(array<string, 5> numbers, string goal, bool op);
bool checkDups(int num1, int num2, int num3, int num4, int num5);
void bruteForceArithmetic(array<int, 5> numbers, int goal);
void bruteForceBitwise(array<int, 5> numbers, int goal);

int addition(int a, int b);
int subtraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);
int modulous(int a, int b);

int bitwiseAnd(int a, int b);
int bitwiseOr(int a, int b);
int bitwiseXOr(int a, int b);
int bitwiseShiftLeft(int a, int b);
int bitwiseShiftRight(int a, int b);



#endif
