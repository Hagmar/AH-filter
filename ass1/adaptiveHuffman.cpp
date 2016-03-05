#include <iostream>
#include "adaptiveHuffman.h"

class AdaptiveHuffmanModel {
    class Node {
        public:
            int weight;
            char symbol;
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
        std::string encode(char);
};

AdaptiveHuffmanModel::AdaptiveHuffmanModel() {
    root = new Node;
    nyt = root;
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
    nyt->lchild = new Node();
    nyt = nyt->lchild;
    return newLeaf;
}

std::string AdaptiveHuffmanModel::encode(char c) {
    Node* currNode;
    if (newSymbol(c)){
        Node* newNode = splitNYT();
        newNode->weight = 1;
        currNode = newNode->parent;
        currNode->weight += 1;
    } else {
        currNode = findNode(c);
    }

    return "hi";
 }

int main(int argc, char** argv){
    AdaptiveHuffmanModel* a = new AdaptiveHuffmanModel;
    std::cout << "tjenna" << std::endl;
    return 0;
}
