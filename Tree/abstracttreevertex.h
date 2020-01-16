#ifndef TREEMAKER_ABSTRACTTREEVERTEX_H
#define TREEMAKER_ABSTRACTTREEVERTEX_H

template<typename DataType>
class AbstractTreeVertex
{
private:
    AbstractTreeVertex<DataType> *father;

    AbstractTreeVertex<DataType> *setFather(AbstractTreeVertex<DataType> *newFather);

public:
    DataType data;

    const AbstractTreeVertex<DataType> *getFather();
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

#endif //TREEMAKER_ABSTRACTTREEVERTEX_H
