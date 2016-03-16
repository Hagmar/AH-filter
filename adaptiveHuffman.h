#ifndef ADAPTIVEHUFFMAN_H
#define ADAPTIVEHUFFMAN_H

class AdaptiveHuffmanModel {
    class Node {
        private:
            void Construct(unsigned int);

        public:
            unsigned int weight;
            unsigned char symbol;
            unsigned char number;
            Node* parent;
            Node* lchild;
            Node* rchild;

            Node();
            Node(unsigned int);
            ~Node();
    };
    private:
        bool split;

        Node* root;
        Node* nyt;

        void Construct(bool);

        Node* findNode(unsigned char);
        Node* findNodeRecursive(unsigned char, Node*);
        Node* splitNYT();
        Node* addSymbol(unsigned char);
        void switchNodes(Node*, Node*);
        void switchNodes2(Node*, Node*);
        void blockSwitch(Node*);
        Node* findMaxInBlock(unsigned int);
        Node* findMaxInBlockRecursive(unsigned int, Node*, unsigned char);
        std::string nodeToString(Node*);
    public:
        AdaptiveHuffmanModel();
        AdaptiveHuffmanModel(bool);
        ~AdaptiveHuffmanModel();

        std::string encode(unsigned char);
        std::string decode(std::string);
        void updateModel(unsigned char);
};

#endif
