#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <fstream>
#include <assert.h>
using namespace std;

#define CHAR_TO_INDEX(c) ((int)c - (int)'0')
#define ALPHABET_SIZE 26
#define BITS 2

struct TrieNode
{
    TrieNode *children[BITS];
    bool isLeaf;
    int t;
};

TrieNode *getNode(void){
    TrieNode *node = new TrieNode;

    for (int i = 0; i < BITS; i++)
        node->children[i] = NULL;
    node->isLeaf = false;
    node->t = 1;

    return node;
}


void insert(TrieNode *&root, string key){
    int index = -1;
    TrieNode *temp = root;
    for (int i = 0; i < key.length(); ++i){
        index =  CHAR_TO_INDEX(key[i]);
        if (temp->children[index] == NULL)
            temp->children[index] = getNode();
        else
            temp->t++;

        temp = temp->children[index];
    }
    temp->isLeaf = true;
}


bool search(TrieNode *Node, string key, int i, int & count){
    int len = key.length();
    int index;
    for (int i = 0; i < len; ++i ){
        index = CHAR_TO_INDEX(key[i]);

        if (Node->isLeaf == true){
            cout << "f";
            count = Node->t;
             return true;
         }

        if (Node->children[index] == NULL)
            return false;
        Node = Node->children[index];
    }

    //if (Node != NULL && Node->isLeaf == true || )
        count = Node->t;
        return true;
}

TrieNode *root = getNode();



int main(int argc, char const *argv[])
{
   /* ifstream fin("input.in");
    freopen("input.in", "r", stdin);
    string tem = "";
    char c;

    int M, N, nbits;
    for (int i = 0; i < M; i++){
        fin >> nbits;
        for (int i = 0; i < nbits; ++i){
            fin >> c;
            tem += c;
        }
        insert(root, tem);
    }


for (int )*/
    int count = 0;
    insert(root, "1");
    insert(root, "110");
    cout <<  search(root, "11", 0, count) << endl;
    cout << count << endl;

     return 0;
}