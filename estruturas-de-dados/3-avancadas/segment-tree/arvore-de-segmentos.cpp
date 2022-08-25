/**
 * @file arvore-de-segmentos.cpp
 * @author Gabriel Bergoc (gabriel.bergoc@outlook.com)
 * @brief Algoritmos de manipulação de árvore de segmentos. Fonte: https://neps.academy/br/course/estruturas-de-dados-(codcad)/lesson/arvore-de-segmentos
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 * h = floor(log2(f)) (f = n. folhas, h = altura)
 * N = 2^(h + 1) - 1 (N = n. elementos)
 */

#include <iostream>
#include <cmath>

const int MAX_N = 1E5;              // max n. of leaves
const int H = ceil(log2(MAX_N));    // max height
const int TOTAL = pow(2, H + 1);    // max n. of nodes in tree

int values[MAX_N]{ 0 };
int segTree[TOTAL]{ 0 };

// update value at index <POS> with <NEW_VALUE> and path of segment tree
void update(int iNode, int i, int j, int POS, int NEW_VALUE)
{
    if (i == j) // we found the leaf in desired position
    {
        // update values
        // update segTree node
    }
    else    // keep searching
    {
        int l = 2 * iNode;        // left child
        int r = 2 * iNode + 1;    // right child
        int m = (i + j) / 2;      // divide interval in half

        if (POS <= m)   // choose the child that contains the wanted position
        {
            update(l, i, m, POS, NEW_VALUE);
        }
        else
        {
            update(r, m + 1, j, POS, NEW_VALUE);
        }

        // update current segTree node

    }
}

// retrieve wanted info in interval [A, B]
int retrieve(int iNode, int i, int j, int A, int B)
{
    // Case 1: [i, j]⊆[A, B] -> return the value of this node
    if (A <= i && j <= B)
    {
        return segTree[iNode];
    }

    // Case 2: [i, j] and [A, B] are disjoint -> return -1 (not found)
    if (j < A || i > B)
    {
        return -1;
    }

    // Case 3: [i, j]∩[A, B] ≠ ∅ but [i, j]⊄[A, B]
    int l = 2 * iNode;        // left child
    int r = 2 * iNode + 1;    // right child
    int m = (i + j) / 2;      // middle of interval

    // return the best between the children
}

int main()
{
}