#ifndef TREEMAKER_BINTREEMAKER_H
#define TREEMAKER_BINTREEMAKER_H

#include "../Tree/bintree.h"
#include <random>

using std::default_random_engine;

using std::uniform_int_distribution;

template<typename DataType>
class BinTreeMaker
{
private:
    int size = 0;

    default_random_engine engine;

public:
    int getSize() { return size; }

    void setSize(int size2Set) { size = size2Set; }

    void setSeed(int seed) { engine.seed(seed); }

    BinTree<DataType> *genBinTree();

};

template<typename DataType>
BinTree<DataType> *BinTreeMaker<DataType>::genBinTree()
{
    if (size <= 0) return nullptr;
    auto *tree = new BinTree<DataType>;
    for (int i = 1; i < size; ++i) {
        uniform_int_distribution<int> idGen(i / 2, i - 1);
        uniform_int_distribution<int> typeGen(0, 1);
        int fatherId, childType; //father
        do {
            fatherId = idGen(engine);
            childType = typeGen(engine);
        } while (tree->getVertex(fatherId)->hasChild(childType));
        tree->addVertex(fatherId, childType);
    }
    return tree;
}


#endif //TREEMAKER_BINTREEMAKER_H
