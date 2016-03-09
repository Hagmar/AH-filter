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
    public:
        AdaptiveHuffmanModel();
        ~AdaptiveHuffmanModel();

        bool newSymbol(char);
        Node* splitNYT();
        Node* findNode(char);
        Node* findMaxInBlock(int);
        Node* findMaxInBlockRecursive(int, Node*, int);
        void switchNodes(Node*, Node*);
        void switchNodes2(Node*, Node*);
        std::string encode(char);
};

#endif
