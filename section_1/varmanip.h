// These are forward declarations of the file varmanip.cpp
// Could theoretically also be .hpp but .h is convention
// Best practice is to not define functions / variables here don't violate ODR

// Headers may include other headers

// Header Guard, use #pragma once at the top of headers now
#ifndef VARIABLE_MANIPULATION // Header guards can have name collisions too
#define VARIABLE_MANIPULATION
// If you must define a variable / function, consider putting it here to prevent ODR violations
#endif

void varInit();
void varMath();
void basicIO();

void emptyFunction();
int doubleNum(int num);
int multiplyThree(int num1, int num2, int num3);
// All default values must be on the right
int defaultMultiply(int num1, int num2 = 2); // Only define the default value in the header
void ignoreParam(int num1, int);
void passBy(int value, int &reference);
void justStub();
