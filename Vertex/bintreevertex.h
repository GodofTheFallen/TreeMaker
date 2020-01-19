#ifndef TREEMAKER_BINTREEVERTEX_H
#define TREEMAKER_BINTREEVERTEX_H

#include <algorithm>
#include "abstracttreevertex.h"

template<typename DataType>
class BinTreeVertex : public AbstractTreeVertex<DataType>
{
protected:
    BinTreeVertex<DataType> *leftChild, *rightChild;
public:
    explicit BinTreeVertex(DataType initData = DataType()) :
            AbstractTreeVertex<DataType>(initData),
            leftChild(nullptr), rightChild(nullptr) {}

    BinTreeVertex<DataType> *getLeftChild() const { return leftChild; }

    BinTreeVertex<DataType> *getRightChild() const { return rightChild; }

    BinTreeVertex<DataType> *getChild(int childType) const
    {
        if (!childType) return leftChild;
        else return rightChild;
    }

    void setLeftChild(BinTreeVertex<DataType> *newChild)
    {
        newChild->delFather();
        leftChild = newChild;
        newChild->setFather(this);
    }

    void setRightChild(BinTreeVertex<DataType> *newChild)
    {
        newChild->delFather();
        rightChild = newChild;
        newChild->setFather(this);
    }

    void setChild(BinTreeVertex<DataType> *newChild, int childType);

    void delChild(AbstractTreeVertex<DataType> *child2Del);

    void swapChildren();

    bool hasLeftChild();

    bool hasRightChild();

    bool isLeaf();

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
void BinTreeVertex<DataType>::setChild(BinTreeVertex<DataType> *newChild, int childType)
{
    if (!childType) setLeftChild(newChild);
    else setRightChild(newChild);
}

template<typename DataType>
bool BinTreeVertex<DataType>::isLeaf()
{
    return !hasLeftChild() && !hasRightChild();
}


#endif //TREEMAKER_BINTREEVERTEX_H
