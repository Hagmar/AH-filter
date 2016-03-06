#include <iostream>
#include "adaptiveHuffman.h"

class AdaptiveHuffmanModel {
    class Node {
        public:
            int weight;
            char symbol;
            unsigned char number;
            Node* parent;
            Node* lchild;
            Node* rchild;

            Node();
            Node(int);
            ~Node();
    };
    private:
        Node* root;
        Node* nyt;
    public:
        AdaptiveHuffmanModel();
        ~AdaptiveHuffmanModel();

        bool newSymbol(char);
        Node* splitNYT();
        Node* findNode(char);
        Node* findMaxInBlock(int);
        Node* findMaxInBlockRecursive(int, Node*, int);
        void switchNodes(Node*, Node*);
        std::string encode(char);
};

AdaptiveHuffmanModel::AdaptiveHuffmanModel() {
    root = new Node;
    nyt = root;
    root->number = 255;
    std::cout << "Model created" << std::endl;
}

AdaptiveHuffmanModel::~AdaptiveHuffmanModel() {
    delete root;
    std::cout << "Model destroyed" << std::endl;
}

AdaptiveHuffmanModel::Node::Node() {
    Node(0);
}

AdaptiveHuffmanModel::Node::Node(int w) {
    weight = w;
    lchild = NULL;
    rchild = NULL;
    std::cout << "Node created" << std::endl;
}

AdaptiveHuffmanModel::Node::~Node(){
    if (lchild) {
        delete lchild;
    }
    if (rchild) {
        delete rchild;
    }
    std::cout << "Node destroyed" << std::endl;
}

AdaptiveHuffmanModel::Node* AdaptiveHuffmanModel::splitNYT() {
    Node* newLeaf = new Node();
    nyt->rchild = newLeaf;
    newLeaf->number = nyt->number-1;
    nyt->lchild = new Node();
    nyt->lchild->number = nyt->number-2;
    nyt = nyt->lchild;
    return newLeaf;
}

AdaptiveHuffmanModel::Node* AdaptiveHuffmanModel::findMaxInBlock(int weight){
    return findMaxInBlockRecursive(weight, root, 0);
}

//UNTESTED
AdaptiveHuffmanModel::Node* AdaptiveHuffmanModel::findMaxInBlockRecursive(int weight, AdaptiveHuffmanModel::Node* currNode, int bestNum){
    if (!currNode){
        return NULL;
    }

    if (currNode->weight == weight){
        return currNode;
    } else if (currNode->weight < weight || currNode->number < bestNum){
        return NULL;
    }

    Node* returnNode = NULL;
    Node* rightNode = findMaxInBlockRecursive(weight, currNode->rchild, bestNum);
    if (rightNode){
        if (rightNode->number > bestNum){
            returnNode = rightNode;
            bestNum = rightNode->number;
        }
    }

    Node* leftNode = findMaxInBlockRecursive(weight, currNode->lchild, bestNum);
    if (leftNode){
        if (leftNode->number > bestNum){
            return leftNode;
        }
    }

    return returnNode;
}

//TODO
void AdaptiveHuffmanModel::switchNodes(Node* node1, Node* node2){
    return;
}

std::string AdaptiveHuffmanModel::encode(char c) {
    Node* currNode;
    if (newSymbol(c)){
        Node* newLeaf = splitNYT();
        newLeaf->weight = 1;
        newLeaf->symbol = c;
        currNode = newLeaf->parent;
        currNode->weight = 1;
    } else {
        currNode = findNode(c);
    }

    Node* maxBlockNode;
    while (currNode != root){
        currNode = currNode->parent;
        maxBlockNode = findMaxInBlock(currNode->weight);
        if (currNode != maxBlockNode){
            switchNodes(currNode, maxBlockNode);
        }
        currNode->weight++;
    }
    return "hi";
 }

int main(int argc, char** argv){
    AdaptiveHuffmanModel* a = new AdaptiveHuffmanModel;
    std::cout << "tjenna" << std::endl;
    return 0;
}
