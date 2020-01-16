#ifndef TREEMAKER_TREEVERTEX_H
#define TREEMAKER_TREEVERTEX_H

#include <deque>
#include "abstracttreevertex.h"

template<typename DataType>
class DefaultTreeVertex : public AbstractTreeVertex<DataType>
{
private:
    std::deque<DefaultTreeVertex<DataType> *> sons;

public:
    int getSonSize();

    void addSon(DefaultTreeVertex<DataType> *newSon, int k = -1);

    DefaultTreeVertex<DataType> *getKthSon(int k);

};

template<typename DataType>
int DefaultTreeVertex<DataType>::getSonSize()
{
    return sons.size();
}

template<typename DataType>
void DefaultTreeVertex<DataType>::addSon(DefaultTreeVertex<DataType> *newSon, int k)
{
    if (k < 0) sons.push_back(newSon);
    else sons.insert(sons.begin() + k, newSon);
    newSon->setFather(this);
}

#endif //TREEMAKER_TREEVERTEX_H
