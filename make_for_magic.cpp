#include <iostream>
#include "RandomMaker/bintreemaker.h"
#include "RandomMaker/bintreemodifier.h"
#include "RandomMaker/huffmanmergemaker.h"

using namespace std;

const int MO_MAX = 3;
const int MAX_DATA = 1e5;

int main()
{
    freopen("make.req", "r", stdin);
    freopen("magic.in", "w", stdout);
    int nSize, reTime, moTime;
    scanf("%d%d%d", &nSize, &reTime, &moTime);
    BinTreeMaker<int> maker;
    maker.setSeed(time(nullptr));
    maker.setSize(nSize);
    BinTree<int> *sTree = maker.genBinTree();
    auto **tTreeSec = new BinTree<int> *[reTime];
    for (int i = 0; i < reTime; ++i)
        tTreeSec[i] = new BinTree<int>(*sTree);
    BinTreeModifier<int> modifier;
    modifier.setSeed(time(nullptr));
    default_random_engine engine;
    engine.seed(time(nullptr));
    for (int i = 0; i < moTime; ++i) {
        modifier.setTree(tTreeSec[i]);
        modifier.modifyTimes(uniform_int_distribution<int>(1, MO_MAX)(engine));
    }
    for (int i = 0; i < reTime; ++i) {
        uniform_int_distribution<int> dataGen(1, MAX_DATA);
        tTreeSec[i]->getRoot()->data = dataGen(engine);
    }
    BinTree<int> *tTree = HuffmanMergeMaker().mergeList(tTreeSec, reTime);
    int n = sTree->size();
    printf("%d\n", n);
    int *id = new int[n], *rank = new int[n + 1];
    for (int i = 0; i < n; ++i) id[i] = i + 1;
    std::shuffle(id, id + n, engine);
    for (int i = 0; i < n; ++i) rank[id[i]] = i;
    for (int i = 1; i <= n; ++i) {
        auto vertex = sTree->vertexList[rank[i]];
        int lC = vertex->hasLeftChild() ? id[sTree->vertexIndex[vertex->getLeftChild()]] : 0;
        int rC = vertex->hasRightChild() ? id[sTree->vertexIndex[vertex->getRightChild()]] : 0;
        printf("%d %d\n", lC, rC);
    }
    int m = tTree->size();
    printf("%d\n", m);
    id = new int[m];
    rank = new int[m + 1];
    for (int i = 0; i < m; ++i) id[i] = i + 1;
    std::shuffle(id, id + m, engine);
    for (int i = 1; i < m; ++i) rank[id[i]] = i;
    for (int i = 1; i <= m; ++i) {
        auto vertex = tTree->vertexList[rank[i]];
        int lC = vertex->hasLeftChild() ? id[tTree->vertexIndex[vertex->getLeftChild()]] : 0;
        int rC = vertex->hasRightChild() ? id[tTree->vertexIndex[vertex->getRightChild()]] : 0;
        printf("%d %d\n", lC, rC);
    }
    return 0;
}