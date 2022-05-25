#include <iostream>

class TTree {
private:
    class TNode {
    public:
        TNode(int key):Key(key){}

        int Key;
        TNode* Left = nullptr;
        TNode* Right = nullptr;
    };

    static void DestroyNode(TNode* node) {
        if (node) {
            DestroyNode(node->Left);
            DestroyNode(node->Right);
            delete node;
        }
    }

    TNode* Root = nullptr;

public:
    TTree(){}
    ~TTree() { DestroyNode(Root); }

    void Insert(int x) {
        TNode** cur = &Root;
        while (*cur) {
            TNode& node = **cur;
            if (x < node.Key) {
                cur = &node.Left;
            } else if (x > node.Key) {
                cur = &node.Right;
            } else {
                return;
            }
        }
        *cur = new TNode(x);
    }

    void traversePreOrderRecursive(TNode* node) {
        if (node) {
            std::cout << node->Key << "\n";
            traversePreOrderRecursive(node->Left);
            traversePreOrderRecursive(node->Right);
        }
    }

    void traversePreOrder(){
        traversePreOrderRecursive(Root);
    }
};

int main() {
    freopen("D:\\programs\\JetBrains\\Toolbox\\projects_clion\\tree01\\input.txt", "r", stdin);
    freopen("D:\\programs\\JetBrains\\Toolbox\\projects_clion\\tree01\\output.txt", "w", stdout);
    TTree tree;
    int x=0;
    while (std::cin>>x) {
        tree.Insert(x);
    }
    tree.traversePreOrder();
    return 0;
}
