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
    explicit BinTreeVertex(DataType initData = DataType()) :
            AbstractTreeVertex<DataType>(initData),
            leftChild(nullptr), rightChild(nullptr) {}

    const BinTreeVertex<DataType> *getLeftChild() { return leftChild; }

    const BinTreeVertex<DataType> *getRightChild() { return rightChild; }

    BinTreeVertex<DataType> *setLeftChild(AbstractTreeVertex<DataType> *newChild)
    {
        newChild->delFather();
        leftChild = newChild;
        newChild->setFather(this);
        return leftChild;
    }

    BinTreeVertex<DataType> *setRightChild(AbstractTreeVertex<DataType> *newChild)
    {
        newChild->delFather();
        rightChild = newChild;
        newChild->setFather(this);
        return rightChild;
    }

    AbstractTreeVertex<DataType> *setChild(AbstractTreeVertex<DataType> *newChild, int childType);

    void delChild(AbstractTreeVertex<DataType> *child2Del);

    void swapChildren();

    bool hasLeftChild();

    bool hasRightChild();

    bool hasBothChildren();

    bool hasChild(int childType);

};

template<typename DataType>
void BinTreeVertex<DataType>::delChild(AbstractTreeVertex<DataType> *child2Del)
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

template<typename DataType>
bool BinTreeVertex<DataType>::hasChild(int childType)
{
    if (!childType) return hasLeftChild();
    else return hasRightChild();
}

template<typename DataType>
AbstractTreeVertex<DataType> *BinTreeVertex<DataType>::setChild(AbstractTreeVertex<DataType> *newChild, int childType)
{
    if (!childType) return setLeftChild(newChild);
    else return setRightChild(newChild);
}


#endif //TREEMAKER_BINTREEVERTEX_H
