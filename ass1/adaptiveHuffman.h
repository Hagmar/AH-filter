#ifndef ADAPTIVEHUFFMAN_H
#define ADAPTIVEHUFFMAN_H

class AdaptiveHuffmanModel {
    class Node {
        private:
            void Construct(int);

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

        Node* findNode(char);
        Node* findNodeRecursive(char, Node*);
        Node* splitNYT();
        void blockSwitch(Node*);
        void switchNodes(Node*, Node*);
        void switchNodes2(Node*, Node*);
        Node* findMaxInBlock(int);
        Node* findMaxInBlockRecursive(int, Node*, int);
    public:
        AdaptiveHuffmanModel();
        ~AdaptiveHuffmanModel();

        Node* addSymbol(char);
        std::string encode(char);
        void updateModel(char);
};

#endif
