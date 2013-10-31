/* IME-USP
 * Evolutive Queens:
 *      Eight queens by the evolutive way
 *
 * Victor Alberto Romero
 * Universidade de São Paulo
 * Intenigência Artificial
 * Outubro de 2013
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <stdlib.h> 
#include <time.h> 
#include <iostream>
#include <math.h> 

using namespace std;

class Solution 
{
private:
    int n;
    void printStateLine();

public:
    int attacks;
    int* state;
    Solution(int nIn);
    ~Solution();
    void mutate();
    Solution* cross(Solution* otherSolution);
    void printState(bool arrayWay=false);
    void evaluate();
};

#endif // SOLUTION_H
