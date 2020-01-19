#ifndef TREEMAKER_BINTREEMODIFIER_H
#define TREEMAKER_BINTREEMODIFIER_H


#include <random>
#include "../Tree/bintree.h"

using std::default_random_engine;
using std::uniform_int_distribution;

template<typename DataType>
class BinTreeModifier
{
private:
    BinTree<DataType> *tree;

    default_random_engine engine;
public:
    explicit BinTreeModifier(BinTree<DataType> *initTree = nullptr) : tree(initTree) {}

    auto setTree(BinTree<DataType> *newTree) { return tree = newTree; }

    void setSeed(int seed) { engine.seed(seed); }

    BinTree<DataType> *getTree() { return tree; }

    bool modifyOnce(int type);

    bool modifyTimes(int t);
};


template<typename DataType>
bool BinTreeModifier<DataType>::modifyOnce(int type)
{
    if (tree == nullptr) return false;
    int vertexID, childType;
    uniform_int_distribution<int> idGen(0, tree->size() - 1);
    uniform_int_distribution<int> typeGen(0, 1);
    switch (type) {
        case 0:
            vertexID = idGen(engine);
            tree->getVertex(vertexID)->swapChildren();
            break;
        case 1:
            do {
                vertexID = idGen(engine);
                childType = typeGen(engine);
            } while (tree->getVertex(vertexID)->hasChild(childType));
            tree->addVertex(vertexID, childType);
            break;
    }
    return true;
}

template<typename DataType>
bool BinTreeModifier<DataType>::modifyTimes(int t)
{
    for (int i = 0; i < t; ++i) {
        int type = uniform_int_distribution<>(0, 1)(engine);
        if (!modifyOnce(type)) return false;
    }
    return true;
}


#endif //TREEMAKER_BINTREEMODIFIER_H
