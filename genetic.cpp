/* IME-USP
 * Evolutive Queens:
 *      Eight queens by the evolutive way
 *
 * Victor Alberto Romero
 * Universidade de São Paulo
 * Intenigência Artificial
 * Outubro de 2013
 */

#include "genetic.h"

Genetic::Genetic(int nIn)
{
    //Commom values
    population = 100;
    cross = 60;
    mutation = 5;
    
    n = nIn;
    matinPool = new Solution*[population];
}

Genetic::~Genetic()
{
    delete matinPool;
}

void Genetic::solve()
{
    for (int i = 0; i < population; i++)
        matinPool[i] = new Solution(n);

    Solution* solution = hasSolution();

    while(solution == 0)
    {
        mergeSort(0, (population-1), matinPool);
    }
    

    solution->printState();

    // Deletes
    for (int i = 0; i < population; i++)
        delete matinPool[i];
}

Solution* Genetic::hasSolution()
{
    for (int i = 0; i < population; i++)
        if(matinPool[i]->evaluate() == 0 )
            return matinPool[i];

    return 0;
}

void Genetic::mergeSort(int start, int end, Solution** array)
{
    int size = end-start+1;

    if(size>1 && size==2)
    {
        if(array[start]->attacks > array[end]->attacks)
        {
            Solution* temp = array[start];
            array[start]=array[end];
            array[end]=temp;
        }
    }
    if(size>2)
    {
        int sizeL =floor(((double)size)/2.0);
        int sizeR =ceil(((double)size)/2.0);

        int start1 = start;
        int end1 = start+sizeL-1;
        int start2 = start+sizeL;
        int end2 = start+sizeL+sizeR-1;

        mergeSort(start1, end1, array);
        mergeSort(start2, end2, array);
        merge(start1, end1, start2, end2, array);
    }
}

void Genetic::merge(int start1, int end1, int start2, int end2, Solution** array)
{
    int startO = start1;
    int sizeTotal = end2-start1+1;
    Solution** temp = new Solution*[sizeTotal];

    for (int i = 0; i < sizeTotal; ++i)
    {
        if(start1 > end1)
        {
            temp[i]=array[start2];
            start2++;
        }
        else if(start2 > end2)
        {
            temp[i]=array[start1];
            start1++;
        }
        else
        {
            if(array[start1]->attacks < array[start2]->attacks)
            {
                temp[i]=array[start1];
                start1++;
            }
            else
            {
                temp[i]=array[start2];
                start2++;
            }
        }
    }

    for (int i = 0; i < sizeTotal; ++i)
    {
        array[i+startO] = temp[i];
    }

    // Deletes
    delete temp;
}
