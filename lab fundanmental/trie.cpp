#include <bits/stdc++.h>
#define N 100
#define Max 26
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
struct Node {
    struct Node *child[Max];
    int countWord;
};
struct Node *newNode() {
    struct Node *node = new Node;
    node->countWord = 0;
    for (int i = 0; i < Max; i++) {
        node->child[i] = NULL;
    }
    return node;
};
void addWord(struct Node *root, string s) {
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL) {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
    }
    temp->countWord++;
}
bool findWord(Node *root, string s) {
    int ch;
    struct Node *temp = root;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
            return false;
        temp = temp->child[ch];
    }
    return temp->countWord > 0;
}
bool isWord(struct Node *node) {
    return (node->countWord != 0);
}
bool isEmpty(struct Node *node) {
    for (int i = 0; i < Max; i++) {
        if (node->child[i] != NULL)
            return false;
    }
    return true;
}
bool removeWord(struct Node *root, string s, int level, int len) {
    if (!root)
        return false;
    int ch = s[level] - 'a';
    if (level == len) {
        if (root->countWord > 0) {
            root->countWord--;
            return true;
        }
        return false;
    }
    bool flag = removeWord(root->child[ch], s, level + 1, len);
    if (flag && !isWord(root->child[ch]) && isEmpty(root->child[ch])) {
        delete root->child[ch];
        root->child[ch] = NULL;
    }
    return flag;
}
void printWord(struct Node *root, string s) {
    if (isWord(root))
        cout << s << endl;
    for (int i = 0; i < Max; i++) {
        printWord(root->child[i], s + (char)('a' + i));
    }
}

int main() {
    struct Node *root = newNode();
    addWord(root, "the");
    addWord(root, "then");
    addWord(root, "quyen");
    //removeWord(root, "quyen", 0,5 );
    cout << findWord(root, "quyen");
    //printWord(root, "");
}