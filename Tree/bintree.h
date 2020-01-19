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
    BinTreeVertex<DataType> *root;
public:
    int size();

    explicit BinTree(DataType initRootData)
    {
        root = new BinTreeVertex<DataType>(initRootData);
        vertexList.push_back(root);
        vertexIndex[root] = 0;
    }

    BinTreeVertex<DataType> *getVertex(int id);

    BinTreeVertex<DataType> *getRoot();

    enum ChildType
    {
        Left = 0,
        Right = 1
    };

    bool addVertex(BinTreeVertex<DataType> *vertex, ChildType type, DataType data = DataType());

    bool addVertex(int id, ChildType type, DataType data = DataType());

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
bool BinTree<DataType>::addVertex(BinTreeVertex<DataType> *vertex, ChildType type, DataType data)
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
    auto *tempVertex = new BinTreeVertex<DataType>(data);
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
bool BinTree<DataType>::addVertex(int id, BinTree::ChildType type, DataType data)
{
    if (id < 0 || id >= size()) return false;
    BinTreeVertex<DataType> *vertex = vertexList[id];
    return addVertex(vertex, type, data);
}

template<typename DataType>
BinTreeVertex<DataType> *BinTree<DataType>::getRoot()
{
    return root;
}


#endif //TREEMAKER_BINTREE_H
