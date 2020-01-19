#ifndef TREEMAKER_BINTREE_H
#define TREEMAKER_BINTREE_H

#include <vector>
#include <map>
#include "../Vertex/bintreevertex.h"

template<typename DataType>
class BinTree
{
private:
    BinTreeVertex<DataType> *root;
public:
    std::vector<BinTreeVertex<DataType> *> vertexList;
    std::map<BinTreeVertex<DataType> *, int> vertexIndex;

    int size();

    explicit BinTree(DataType initRootData = DataType())
    {
        root = new BinTreeVertex<DataType>(initRootData);
        vertexList.push_back(root);
        vertexIndex[root] = 0;
    }

    explicit BinTree(BinTree<DataType> &anotherTree)
    {
        for (BinTreeVertex<DataType> *vertex : anotherTree.vertexList) {
            auto temp = new BinTreeVertex<DataType>(vertex->data);
            vertexIndex[temp] = vertexList.size();
            vertexList.push_back(temp);
        }
        for (BinTreeVertex<DataType> *vertex : anotherTree.vertexList) {
            int i = anotherTree.vertexIndex[vertex];
            for (int childType = 0; childType <= 1; ++childType)
                if (vertex->hasChild(childType)) {
                    auto child = vertex->getChild(childType);
                    int id = anotherTree.vertexIndex[child];
                    vertexList[i]->setChild(vertexList[id], childType);
                }
        }
        root = vertexList[anotherTree.vertexIndex[anotherTree.root]];
    }

    BinTreeVertex<DataType> *getVertex(int id);

    BinTreeVertex<DataType> *getRoot();

    bool addVertex(BinTreeVertex<DataType> *vertex, int type, DataType data = DataType());

    bool addVertex(int id, int type, DataType data = DataType());

    friend BinTree<int> *merge(BinTree<int> *tree1, BinTree<int> *tree2);

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
bool BinTree<DataType>::addVertex(BinTreeVertex<DataType> *vertex, int type, DataType data)
{
    if (!vertexIndex.count(vertex)) return false;
    switch (type) {
        case 0:
            if (vertex->hasLeftChild()) return false;
            break;
        case 1:
            if (vertex->hasRightChild()) return false;
            break;
    }
    auto *tempVertex = new BinTreeVertex<DataType>(data);
    vertexList.push_back(tempVertex);
    vertexIndex[tempVertex] = size() - 1;
    switch (type) {
        case 0:
            vertex->setLeftChild(tempVertex);
            break;
        case 1:
            vertex->setRightChild(tempVertex);
            break;
    }
    return true;
}

template<typename DataType>
bool BinTree<DataType>::addVertex(int id, int type, DataType data)
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

BinTree<int> *merge(BinTree<int> *tree1, BinTree<int> *tree2)
{
    auto tree = new BinTree<int>(tree1->getRoot()->data + tree2->getRoot()->data);
    for (auto vertex : tree1->vertexList) tree->vertexList.push_back(vertex);
    for (auto vertex : tree2->vertexList) tree->vertexList.push_back(vertex);
    tree->root->setLeftChild(tree1->root);
    tree->root->setRightChild(tree2->root);
    for (int i = 0; i < tree->vertexList.size(); ++i)
        tree->vertexIndex[tree->vertexList[i]] = i;
    return tree;
}


#endif //TREEMAKER_BINTREE_H
