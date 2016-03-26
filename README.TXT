Adaptive Huffman encoding and decoding
Author: Magnus Hagmar
ZID: z5088131

The provided code implements the adaptive Huffman compression algorithm
proposed by Jeff Vitter.

I decided to implement my encoder and decoder as a traditional UNIX filter.
This means that they can be run in one of three modes. First, they can be run
interactively, reading input from the user line by line, processing it as it
is received. Second, they can run in batch mode by feeding the contents of a
file to it through a pipe or stream redirection. Third, a list of files can be
provided as command line arguments, in which case it will attempt to open and
process the contents of these files in order. In all three execution methods,
any output is printed to stdout.

The implementation consists of several files, described below.

- filter.h & filter.cpp
    These two files define an abstract Filter class, which provides
    functionality for the UNIX filter behavior described above. It is intended
    to be extended by a class implementing its "process" function, which
    determines in what way its input is modified.

- ahencode.h & ahencode.cpp
    These files implement a class AHEncodeFilter, which extends the Filter
    base class. Its process function creates an instance of an
    AdaptiveHuffmanModel (described below) and uses it to encode the input
    lines character by character.

- ahdecode.h & ahdecode.cpp
    Similarly to the encoder, these files define a class AHDecodeFilter, which
    takes an AH-encoded string and decodes it back into the original message.
    It also makes use of the AdaptiveHuffmanModel class to process its input.

- adaptiveHuffman.h & adaptiveHuffman.cpp
    These files contain a class AdaptiveHuffmanModel which can be used to
    maintain a Huffman tree for encoding and decoding.

    As described in Vitter's paper from 1987, a linked list of blocks are
    maintained in order to satisfy the provided invariant. The blocks contain
    a pointer to their first and last nodes, as well as their corresponding
    weight and whether they are are internal or leaf nodes.

    Nodes both point to the block they are contained in, as well as the next
    and previous nodes in its block. In addition to this, they are placed in a
    tree structure, pointing to both children and its parent. 

    The model's encode function takes a single character to encode. It uses
    the Huffman tree to determine the correct encoding of the character and
    returns a string of 1's and 0's to represent this.

    The decode function needs to be supplied with a string of 1's and 0's,
    rather than just a single character. It maintains a pointer to a node
    within the tree, progressing to its children depending on the string.
    Once a leaf node is found it can determine whether to output the symbol
    for that node or interpret the next 8 bits as a byte of output.

    The updateModel function is intended to be called after every single
    encoded or decoded character. It updates the Huffman tree by increasing
    the weight of the recently transmitted character. In addition, it
    maintains Vitter's invariant using the slideAndIncrement procedur
    described in his paper (with the bug of not updating the root's weight
    fixed).
