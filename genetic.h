/* IME-USP
 * Evolutive Queens:
 *      Eight queens by the evolutive way
 *
 * Victor Alberto Romero
 * Universidade de São Paulo
 * Intenigência Artificial
 * Outubro de 2013
 */

#ifndef GENETIC_H
#define GENETIC_H

#include "solution.h"

class Genetic
{
private:
    int n, population, cross, mutation;
    Solution** matinPool;
    Solution* hasSolution();
    void mergeSort(int start, int end, Solution** array);
    void merge(int start1, int end1, int start2, int end2, Solution** array);

public:
    Genetic(int nIn);
    ~Genetic();
    void solve();
};

#endif // GENETIC_H
