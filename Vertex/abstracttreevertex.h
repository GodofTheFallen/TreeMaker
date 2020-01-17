#ifndef TREEMAKER_ABSTRACTTREEVERTEX_H
#define TREEMAKER_ABSTRACTTREEVERTEX_H

template<typename DataType>
class AbstractTreeVertex
{
protected:
    AbstractTreeVertex<DataType> *father;

    AbstractTreeVertex<DataType> *setFather(AbstractTreeVertex<DataType> *newFather);

public:
    DataType data;

    const AbstractTreeVertex<DataType> *getFather();

    void delFather();

    virtual void delChild(AbstractTreeVertex<DataType> child2Del) = 0;
};

template<typename DataType>
AbstractTreeVertex<DataType> *AbstractTreeVertex<DataType>::setFather(AbstractTreeVertex<DataType> *newFather)
{
    father = newFather;
    return father;
}

template<typename DataType>
const AbstractTreeVertex<DataType> *AbstractTreeVertex<DataType>::getFather()
{
    return father;
}

template<typename DataType>
void AbstractTreeVertex<DataType>::delFather()
{

}

#endif //TREEMAKER_ABSTRACTTREEVERTEX_H
