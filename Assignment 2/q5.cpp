#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};
void printCodes(Node* root, string code) {
    if (!root)
        return;
    if (!root->left && !root->right) {
        cout << root->ch << "\t\t" << code << endl;
    }
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}
int main() {
    vector<char> chars;
    vector<int> freq;
    chars.push_back('a');
    chars.push_back('b');
    chars.push_back('c');
    chars.push_back('d');
    chars.push_back('e');
    chars.push_back('f');
    freq.push_back(5);
    freq.push_back(9);
    freq.push_back(12);
    freq.push_back(13);
    freq.push_back(16);
    freq.push_back(45);
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < chars.size(); i++) {
        pq.push(new Node(chars[i], freq[i]));
    }
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    Node* root = pq.top();
    cout << "Character\tHuffman Code\n";
    printCodes(root, "");
    return 0;
}
