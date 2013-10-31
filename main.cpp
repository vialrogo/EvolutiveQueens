/*
 * Evolutive Queens:
 *      Eight queens by the evolutive way
 *
 * Victor Alberto Romero
 * Universidade de São Paulo
 * Intenigência Artificial
 * Outubro de 2013
 */

#include "genetic.h"

int main(int argc, char* archv[])
{
    int n=8;

    if(argc == 2)
        n  = atoi (archv[1]);

    srand (time(NULL)); // Inicialize rand. Use includes of solution.h
    Genetic* g = new Genetic(n);
    g->solve();

    // Deletes
    delete g;
}
