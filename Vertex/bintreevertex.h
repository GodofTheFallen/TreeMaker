#ifndef TREEMAKER_BINTREEVERTEX_H
#define TREEMAKER_BINTREEVERTEX_H

#include <algorithm>
#include "abstracttreevertex.h"

template<typename DataType>
class BinTreeVertex : public AbstractTreeVertex<DataType>
{
protected:
    AbstractTreeVertex<DataType> *leftChild, *rightChild;
public:
    BinTreeVertex() : leftChild(nullptr), rightChild(nullptr) {}

    const BinTreeVertex<DataType> *getLeftChild() { return leftChild; }

    const BinTreeVertex<DataType> *getRightChild() { return rightChild; }

    BinTreeVertex<DataType> *setLeftChild(AbstractTreeVertex<DataType> *newChildren)
    {
        newChildren->delFather();
        leftChild = newChildren;
        newChildren->setFather(this);
    }

    BinTreeVertex<DataType> *setRightChild(AbstractTreeVertex<DataType> *newChildren)
    {
        newChildren->delFather();
        rightChild = newChildren;
        newChildren->setFather(this);
    }

    void delChild(AbstractTreeVertex<DataType> child2Del);

    void swapChildren();

    bool hasLeftChild();

    bool hasRightChild();

    bool hasBothChildren();


};

template<typename DataType>
void BinTreeVertex<DataType>::delChild(AbstractTreeVertex<DataType> child2Del)
{
    if (leftChild == child2Del) leftChild = nullptr;
    if (rightChild == child2Del) rightChild = nullptr;
}

template<typename DataType>
void BinTreeVertex<DataType>::swapChildren()
{
    std::swap(leftChild, rightChild);
}

template<typename DataType>
bool BinTreeVertex<DataType>::hasLeftChild()
{
    return leftChild != nullptr;
}

template<typename DataType>
bool BinTreeVertex<DataType>::hasRightChild()
{
    return rightChild != nullptr;
}

template<typename DataType>
bool BinTreeVertex<DataType>::hasBothChildren()
{
    return hasLeftChild() && hasRightChild();
}


#endif //TREEMAKER_BINTREEVERTEX_H
