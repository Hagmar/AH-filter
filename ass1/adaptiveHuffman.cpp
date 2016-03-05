#include <iostream>
#include "adaptiveHuffman.h"

class AdaptiveHuffmanModel {
    class Node {
        public:
            int weight;
            Node* lchild;
            Node* rchild;

            Node();
            Node(int);
    };
    private:
        Node* root;
    public:
        AdaptiveHuffmanModel();
};

AdaptiveHuffmanModel::AdaptiveHuffmanModel() {
    Node n = Node();
    root = &n;
}

AdaptiveHuffmanModel::Node::Node() {
    Node(0);
}

AdaptiveHuffmanModel::Node::Node(int w) {
    weight = w;
    lchild = NULL;
    rchild = NULL;
}

