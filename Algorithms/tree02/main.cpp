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

    TNode* FindMin(TNode* node) {
        if (node->Left) {return FindMin(node->Left);}
        else {return node;}
    }

    TNode* DeleteRecursive(TNode* node, int x) {
        if( !node ) {
            return nullptr;
        }
        else if (x < node->Key) {
            node->Left = DeleteRecursive(node->Left, x);
            return node;
        } else if (x > node->Key) {
            node->Right = DeleteRecursive(node->Right, x);
            return node;
        }
        else if (!node->Left) {return node->Right;}
        else if (!node->Right) {return node->Left;}
        else {
            int MinKey = FindMin(node->Right)->Key;
            node->Key =MinKey;
            node->Right = DeleteRecursive(node->Right, MinKey);
            return node;
        }
    }
    void Delete(int key) {
        Root = DeleteRecursive(Root, key);
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


    freopen("D:\\programs\\JetBrains\\Toolbox\\projects_clion\\tree02\\input.txt", "r", stdin);
    freopen("D:\\programs\\JetBrains\\Toolbox\\projects_clion\\tree02\\output.txt", "w", stdout);
    TTree tree;
    int delVer=0;
    std::cin>>delVer;
    int x=0;
    while (std::cin>>x) {
        tree.Insert(x);
    }
    tree.Delete(delVer);
    tree.traversePreOrder();
    return 0;
}
