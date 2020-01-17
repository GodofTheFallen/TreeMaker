#ifndef TREEMAKER_DEFAULTTREEVERTEX_H
#define TREEMAKER_DEFAULTTREEVERTEX_H

#include <deque>
#include "abstracttreevertex.h"

template<typename DataType>
class DefaultTreeVertex : public AbstractTreeVertex<DataType>
{
private:
    std::deque<AbstractTreeVertex<DataType> *> Children;

public:
    int getSonSize();

    void addChildren(DefaultTreeVertex<DataType> *newChildren, int k = -1);

    AbstractTreeVertex<DataType> *getKthSon(int k);

    //TODO: finish delChild

};

template<typename DataType>
int DefaultTreeVertex<DataType>::getSonSize()
{
    return Children.size();
}

template<typename DataType>
void DefaultTreeVertex<DataType>::addChildren(DefaultTreeVertex<DataType> *newChildren, int k)
{
    if (k < 0) Children.push_back(newChildren);
    else Children.insert(Children.begin() + k, newChildren);
    newChildren->setFather(this);
}

#endif //TREEMAKER_DEFAULTTREEVERTEX_H
