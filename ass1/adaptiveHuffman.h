#ifndef ADAPTIVEHUFFMAN_H
#define ADAPTIVEHUFFMAN_H

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

        bool newSymbol(char);
        Node* findNode(char);
        Node* findNodeRecursive(char, Node*);
        Node* splitNYT();
        void switchNodes(Node*, Node*);
        void switchNodes2(Node*, Node*);
        Node* findMaxInBlockRecursive(int, Node*, int);
    public:
        AdaptiveHuffmanModel();
        ~AdaptiveHuffmanModel();

        Node* findMaxInBlock(int);
        Node* addSymbol(char);
        void blockSwitch(Node*);
        std::string encode(char);
};

#endif
