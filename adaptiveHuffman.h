#ifndef ADAPTIVEHUFFMAN_H
#define ADAPTIVEHUFFMAN_H

class AdaptiveHuffmanModel {
    class Block;
    class Node {
        private:
            void Construct(unsigned int);

        public:
            unsigned int weight;
            unsigned char symbol;
            Node* parent;
            Node* lchild;
            Node* rchild;
            Node* next;
            Node* prev;
            Block* block;

            Node();
            Node(unsigned int);
            ~Node();
    };
    class Block {
        private:
            void Construct(bool, unsigned int);

        public:
            bool internal;
            unsigned int weight;
            Block* next;
            Block* prev;
            Node* leader;
            Node* tail;

            Block();
            ~Block();
            Block(bool);
            Block(bool, unsigned int);

            bool isEmpty();
            void insert(Node*);
            void remove(Node*);
    };
    private:
        bool split;

        Node* root;
        Node* nyt;
        Block* startBlock;

        void Construct(bool);
        void deleteAllBlocks();

        Node* findNode(unsigned char);
        Node* findNodeRecursive(unsigned char, Node*);
        Node* splitNYT();
        Node* addSymbol(unsigned char);
        void switchNodes(Node*, Node*);
        Block* insertNodeIntoBlock(Node*);
        std::string nodeToString(Node*);
        void shiftBlock(Block*, Node*);
    public:
        AdaptiveHuffmanModel();
        AdaptiveHuffmanModel(bool);
        ~AdaptiveHuffmanModel();

        std::string encode(unsigned char);
        std::string decode(std::string);
        void updateModel(unsigned char);
        Node* slideAndIncrement(Node*);
        void printBlocks();
        void printTree(Node*, int);
};

#endif
