/* IME-USP
 * Evolutive Queens:
 *      Eight queens by the evolutive way
 *
 * Victor Alberto Romero
 * Universidade de São Paulo
 * Intenigência Artificial
 * Outubro de 2013
 */

#include "solution.h"

Solution::Solution(int nIn)
{
    n = nIn;
    state = new int[n];

    for (int i = 0; i < n; i++)
        state[i]=i;
    
    for (int i = 0; i < n; i++)
        mutate();

    evaluate();
}

Solution::~Solution()
{
    delete state;
}

void Solution::mutate()
{
    int tmp, id1, id2;
    id1 = rand()%n;
    id2 = rand()%n;
    tmp = state[id1];
    state[id1] = state[id2];
    state[id2] = tmp;
    evaluate();
}

Solution* Solution::cross(Solution* otherSolution)
{
    Solution* output = new Solution(n);
    bool* used = new bool[n];
    int countB = floor(n/2);
    int idB = floor(n/2);

    for (int i = 0; i < n; i++) 
        used[i] = false;
    
    for (int i = 0; i < idB; i++)
    {
       output->state[i] = state[i];
       used[state[i]] = true;
    }

    while(countB < n)
    {
        if(!used[otherSolution->state[idB%n]])
        {
            output->state[countB] = otherSolution->state[idB%n];
            used[otherSolution->state[idB%n]] = true;
            countB++;
        }
        idB++;
    }

    output->evaluate();

    delete used;
    return output;
}

void Solution::printState(bool arrayWay)
{
    if(arrayWay)
    {
        printStateLine();
        cout<<"| ";
        for (int i = 0; i < n; i++) cout << state[i] << " | ";
        printStateLine();
    }
    else
    {
        printStateLine();
        for (int i = 0; i < n; i++)
        {
            cout<<"|";
            for (int j = 0; j < n; j++) 
            {
                if(i == state[j]) cout<<" X |";
                else              cout<<"   |";
            }
            printStateLine();
        }
    }
}

void Solution::printStateLine()
{
    //Print horizontal line
    cout<<endl<<"+";
    for (int j = 0; j < n; j++) cout<<"---+";
    cout<<endl;
}

void Solution::evaluate()
{
    // A evaluation is the number of queens in attack
    attacks = 0;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < (n-i); j++)
            if(state[i+j]==(state[i]+j) || state[i+j]==(state[i]-j))
                attacks++;
}

