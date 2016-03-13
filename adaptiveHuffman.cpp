#include <iostream>
#include "adaptiveHuffman.h"

AdaptiveHuffmanModel::AdaptiveHuffmanModel() {
    root = new Node();
    nyt = root;
    root->number = 255;
}

AdaptiveHuffmanModel::~AdaptiveHuffmanModel() {
    delete root;
}

AdaptiveHuffmanModel::Node::Node() {
    Construct(0);
}

AdaptiveHuffmanModel::Node::Node(unsigned int w) {
    Construct(w);
}

void AdaptiveHuffmanModel::Node::Construct(unsigned int w) {
    weight = w;
    lchild = NULL;
    rchild = NULL;
    parent = NULL;
}

AdaptiveHuffmanModel::Node::~Node(){
    if (lchild) {
        delete lchild;
    }
    if (rchild) {
        delete rchild;
    }
}

AdaptiveHuffmanModel::Node* AdaptiveHuffmanModel::splitNYT() {
    Node* newLeaf = new Node();
    nyt->rchild = newLeaf;
    newLeaf->parent = nyt;
    newLeaf->number = nyt->number-1;
    nyt->lchild = new Node();
    nyt->lchild->number = nyt->number-2;
    nyt->lchild->parent = nyt;
    nyt = nyt->lchild;
    return newLeaf;
}

AdaptiveHuffmanModel::Node* AdaptiveHuffmanModel::findNode(char c){
    return findNodeRecursive(c, root);
}

AdaptiveHuffmanModel::Node* AdaptiveHuffmanModel::findNodeRecursive(char c, AdaptiveHuffmanModel::Node* node){
    if (!node){
        return NULL;
    }

    if (node->symbol == c){
        return node;
    }
    
    Node* returnNode = findNodeRecursive(c, node->rchild);
    if (returnNode){
        return returnNode;
    }
    return findNodeRecursive(c, node->lchild);
}

AdaptiveHuffmanModel::Node* AdaptiveHuffmanModel::findMaxInBlock(unsigned int weight){
    return findMaxInBlockRecursive(weight, root, 0);
}

//UNTESTED
AdaptiveHuffmanModel::Node* AdaptiveHuffmanModel::findMaxInBlockRecursive(unsigned int weight, AdaptiveHuffmanModel::Node* currNode, unsigned char bestNum){
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

AdaptiveHuffmanModel::Node* AdaptiveHuffmanModel::addSymbol(char c){
    Node* newLeaf = splitNYT();
    newLeaf->weight = 1;
    newLeaf->symbol = c;

    newLeaf->parent->weight = 1;
    return newLeaf->parent;
}

// Switches the position of two nodes, while leaving the numbering intact
void AdaptiveHuffmanModel::switchNodes(Node* node1, Node* node2){
    unsigned char tempNum = node1->number;
    Node* tempParent = node1->parent;

    node1->number = node2->number;
    node1->parent = node2->parent;
    if (node1->parent->lchild == node2){
        node1->parent->lchild = node1;
    } else {
        node1->parent->rchild = node1;
    }

    node2->number = tempNum;
    node2->parent = tempParent;
    if (tempParent->lchild == node1){
        tempParent->lchild = node2;
    } else {
        tempParent->rchild = node2;
    }
}

// Switches nodes by swapping children and symbol
// In effect switches the pointers
void AdaptiveHuffmanModel::switchNodes2(Node* node1, Node* node2){
    char tempSymbol = node1->symbol;
    Node* tempLChild = node1->lchild;
    Node* tempRChild = node1->rchild;

    node1->symbol = node2->symbol;
    node1->lchild = node2->lchild;
    node1->lchild->parent = node1;
    node1->rchild = node2->rchild;
    node1->rchild->parent = node1;

    node2->symbol = tempSymbol;
    node2->lchild = tempLChild;
    node2->lchild->parent = node2;
    node2->rchild = tempRChild;
    node2->rchild->parent = node2;
}


void AdaptiveHuffmanModel::blockSwitch(Node* node){
    Node* maxBlockNode = findMaxInBlock(node->weight);
    if (node != maxBlockNode && maxBlockNode != node->parent){
        switchNodes(node, maxBlockNode);
    }
    node->weight++;
}

std::string AdaptiveHuffmanModel::encode(char c){
    std::string output = "";
    Node* node = findNode(c);
    if (!node){
        output = c;
    } else {
        output = nodeToString(node);
    }

    return output;
}

std::string AdaptiveHuffmanModel::nodeToString(AdaptiveHuffmanModel::Node* node){
    std::string output = "";

    while (node != root){
        output = (node == node->parent->rchild) ? "1" + output : "0" + output;
        node = node->parent;
    }

    return output;
}

void AdaptiveHuffmanModel::updateModel(char c) {
    Node* currNode = findNode(c);
    if (!currNode){
        currNode = addSymbol(c);
    } else {
        blockSwitch(currNode);
    }

    while (currNode != root){
        currNode = currNode->parent;
        blockSwitch(currNode);
    }
}
