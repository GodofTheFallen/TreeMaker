#ifndef TREEMAKER_HUFFMANMERGEMAKER_H
#define TREEMAKER_HUFFMANMERGEMAKER_H

#include <queue>
#include "../Tree/bintree.h"

class HuffmanMergeMaker
{
public:
    class BinTreeComparer
    {
    public:
        bool operator()(BinTree<int> *&tree1, BinTree<int> *&tree2) const
        {
            return tree1->getRoot()->data > tree2->getRoot()->data;
        }
    };

    BinTree<int> *mergeList(BinTree<int> **treeSec, int num)
    {
        std::priority_queue<BinTree<int> *, std::vector<BinTree<int> *>, BinTreeComparer> heap;
        for (int i = 0; i < num; ++i) heap.push(new BinTree<int>(*treeSec[i]));
        while (heap.size() > 1) {
            BinTree<int> *tree1 = heap.top();
            heap.pop();
            BinTree<int> *tree2 = heap.top();
            heap.pop();
            heap.push(merge(tree1, tree2));
        }
        return heap.top();
    }
};


#endif //TREEMAKER_HUFFMANMERGEMAKER_H
