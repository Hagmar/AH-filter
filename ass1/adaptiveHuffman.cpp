#include <iostream>
#include "adaptiveHuffman.h"

class AdaptiveHuffmanModel {
    class Node {
        public:
            int weight;
            char symbol;
            Node* lchild;
            Node* rchild;

            Node();
            Node(int);
            ~Node();
    };
    private:
        Node* root;
    public:
        AdaptiveHuffmanModel();
        ~AdaptiveHuffmanModel();

        std::string encode(char);
};

AdaptiveHuffmanModel::AdaptiveHuffmanModel() {
    root = new Node;
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

int main(int argc, char** argv){
    AdaptiveHuffmanModel* a = new AdaptiveHuffmanModel;
    std::cout << "tjenna" << std::endl;
    return 0;
}
