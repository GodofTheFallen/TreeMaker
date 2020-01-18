#ifndef TREEMAKER_BINTREE_H
#define TREEMAKER_BINTREE_H

#include <vector>
#include <map>
#include "../Vertex/bintreevertex.h"

template<typename DataType>
class BinTree
{
private:
    std::vector<BinTreeVertex<DataType> *> vertexList;
    std::map<BinTreeVertex<DataType> *, int> vertexIndex;
public:
    int size();

    BinTreeVertex<DataType> *getVertex(int id);

    enum ChildType
    {
        Left = 0,
        Right = 1
    };

    bool addVertex(BinTreeVertex<DataType> *vertex, ChildType type);

    bool addVertex(int id, ChildType type);

};

template<typename DataType>
int BinTree<DataType>::size()
{
    return vertexList.size();
}

template<typename DataType>
BinTreeVertex<DataType> *BinTree<DataType>::getVertex(int id)
{
    return vertexList.at(id);
}

template<typename DataType>
bool BinTree<DataType>::addVertex(BinTreeVertex<DataType> *vertex, BinTree::ChildType type)
{
    if (!vertexIndex.count(vertex)) return false;
    switch (type) {
        case Left:
            if (vertex->hasLeftChild()) return false;
            break;
        case Right:
            if (vertex->hasRightChild()) return false;
            break;
    }
    auto *tempVertex = new BinTreeVertex<DataType>;
    vertexList.push_back(tempVertex);
    vertexIndex[tempVertex] = size() - 1;
    switch (type) {
        case Left:
            vertex->setLeftChild(tempVertex);
            break;
        case Right:
            vertex->setRightChild(tempVertex);
            break;
    }
    return true;
}

template<typename DataType>
bool BinTree<DataType>::addVertex(int id, BinTree::ChildType type)
{
    if (id < 0 || id >= size()) return false;
    BinTreeVertex<DataType> *vertex = vertexList[id];
    return addVertex(vertex, type);
}


#endif //TREEMAKER_BINTREE_H
