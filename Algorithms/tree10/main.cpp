#include <iostream>

class TTree {
private:
    class TNode {
    public:
        TNode(long long key):Key(key){}

        long long Key;
        long long h=0;
        long long b=0;
        long long l=0;
        long long a=0;
        long long msl_=0;
        long long c=0;
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
    long long msl=0;
    long long c_max=0;
    long long n=0; //количество вершин

public:
    TTree(){}
    ~TTree() { DestroyNode(Root); }

    void Insert(long long x) {
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
        n++;
    }

    TNode* FindMin(TNode* node) {
        if (node->Left) {return FindMin(node->Left);}
        else {return node;}
    }

    //rigth delete
    TNode* DeleteRecursive(TNode* node, long long x) {
        if( !node ) { return nullptr; }
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
            long long MinKey = FindMin(node->Right)->Key;
            node->Key =MinKey;
            node->Right = DeleteRecursive(node->Right, MinKey);
            return node;
        }
    }
    void Delete(long long key) { Root = DeleteRecursive(Root, key);}

    //прямой левый обход
    void traversePreOrderRecursive(TNode* node) {
        if (node) {
            std::cout << node->Key << "\n";
            traversePreOrderRecursive(node->Left);
            traversePreOrderRecursive(node->Right);
        }
    }

    void traversePreOrder(){traversePreOrderRecursive(Root);}

    void traversePostOrderRecursiveDelete(TNode* node) {
        if (node) {
            traversePostOrderRecursiveDelete(node->Left);
            traversePostOrderRecursiveDelete(node->Right);
            if(node->c==c_max && n>1)
            {
                Delete(node->Key);
                n--;
            }
        }
    }

    void traversePostOrderDelete(){traversePostOrderRecursiveDelete(Root);}

    //обратный левый с подсчетом высоты и листья и длина наибольшего полупути
    void traversePostOrderRecursive(TNode* node) {
        if (node) {
            traversePostOrderRecursive(node->Left);
            traversePostOrderRecursive(node->Right);
            if (!(node->Right) && !(node->Left))
            {
                node->h=0;
                node->l=1;
                node->msl_=0;
            } else if (!(node->Right) && node->Left)
            {
                node->h=node->Left->h+1;
                node->l=node->Left->l;
                node->msl_=node->Left->h+1;
            } else if (!(node->Left) && node->Right)
            {
                node->h=node->Right->h+1;
                node->l=node->Right->l;
                node->msl_=node->Right->h+1;
            } else {
             node->h = std::max(node->Left->h, node->Right->h)+1;
             node->msl_=node->Left->h+node->Right->h+2;
                if (node->Left->h==node->Right->h)
                {
                    node->l=node->Left->l + node->Right->l;
                }  else if (node->Left->h > node->Right->h)
                {
                    node->l=node->Left->l;
                } else
                {
                    node->l=node->Right->l;
                }
            }
            if (node->msl_>msl){ msl=node->msl_;}
        }
    }

    void traversePostOrder(){traversePostOrderRecursive(Root);}

    void setBRecursive(TNode* node){
        if (node) {
            setBRecursive(node->Left);
            setBRecursive(node->Right);
            if(node->msl_!=msl){
                node->b=0;
            }else {
                if (node->Left && node->Right) {
                    node->b = node->Left->l * node->Right->l;
                } else if (node->Left && !(node->Right)) {
                    node->b = node->Left->l;
                } else if (!(node->Left) && node->Right) {
                    node->b=node->Right->l;
                }else{
                    node->b=1;
                }
            }
        }
    }

    void setB(){setBRecursive(Root);}

    void setARecursive(TNode* node) {
        if (node) {
            if(node==Root){
                Root->a=0;
            }
            if(node->Left && !(node->Right)) {
                node->Left->a=node->a+node->b;
            }else if(node->Right && !(node->Left)){
                node->Right->a=node->a+node->b;
            }else if(node->Right && node->Left){
                if(node->Right->h>node->Left->h){
                    node->Right->a=node->a+node->b;
                    node->Left->a=node->b;
                }else if(node->Left->h>node->Right->h){
                    node->Left->a=node->a+node->b;
                    node->Right->a=node->b;
                }else {
                    node->Right->a = node->b + node->Right->l * (node->a / (long double)node->l);
                    node->Left->a = node->b + node->Left->l * (node->a / (long double)node->l);
                }
            }
            node->c = node->a+node->b;
            if (node->c>c_max) { c_max=node->c; }
            setARecursive(node->Left);
            setARecursive(node->Right);
        }
    }

    void setA() {setARecursive(Root);}
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen(R"(D:\programs\JetBrains\Toolbox\projects_clion\tree10\in.txt)", "r", stdin);
    freopen(R"(D:\programs\JetBrains\Toolbox\projects_clion\tree10\out.txt)", "w", stdout);
    TTree tree;
    long long x=0;
    while (std::cin>>x) {
        tree.Insert(x);
    }
    tree.traversePostOrder();
    tree.setB();
    tree.setA();
    tree.traversePostOrderDelete();
    tree.traversePreOrder();
    return 0;
}
