#ifndef ADAPTIVEHUFFMAN_H
#define ADAPTIVEHUFFMAN_H

class AdaptiveHuffmanModel {
    class Node {
        private:
            void Construct(unsigned int);

        public:
            unsigned int weight;
            char symbol;
            unsigned char number;
            Node* parent;
            Node* lchild;
            Node* rchild;

            Node();
            Node(unsigned int);
            ~Node();
    };
    private:
        Node* root;
        Node* nyt;

        Node* findNode(char);
        Node* findNodeRecursive(char, Node*);
        Node* splitNYT();
        Node* addSymbol(char);
        void switchNodes(Node*, Node*);
        void switchNodes2(Node*, Node*);
        void blockSwitch(Node*);
        Node* findMaxInBlock(unsigned int);
        Node* findMaxInBlockRecursive(unsigned int, Node*, unsigned char);
        std::string nodeToString(Node*);
    public:
        AdaptiveHuffmanModel();
        ~AdaptiveHuffmanModel();

        std::string encode(char);
        void updateModel(char);
};

#endif
