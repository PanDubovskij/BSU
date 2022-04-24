#include <iostream>
#include <vector>

struct Node {
    long long value;
    long long max;
    long long min;

    Node(long long value) {
        this->value = value;
        max = LLONG_MAX;
        min = LLONG_MIN;
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen(R"(D:\programs\JetBrains\Toolbox\projects_clion\tree03\bst.in)", "r", stdin);
    freopen(R"(D:\programs\JetBrains\Toolbox\projects_clion\tree03\bst.out)", "w", stdout);

    int n=0; //number of verges
    std::cin>>n;
    long long _root=0; //root value
    std::cin >> _root;

    std::vector<Node*> tree(n, nullptr); //amount of verges
    Node* root = new Node(_root);
    tree[0]=root;

    long long m=0; //current verge
    int p=0; // its parent
    char c; //type of son
    bool flag= true;

    int i=0;
    while (flag && (std::cin>>m>>p>>c)) {
        Node* current = new Node(m);
        ++i;
        tree[i]=current;
        if (c == 'L') {
            current->min = tree[p-1]->min;
            current->max = tree[p-1]->value;
        } else {
            current->min = tree[p-1]->value-1;
            current->max = tree[p-1]->max;
        }
        if (current->value <= current->min || current->value >= current->max) {flag= false;}
    }

    if (n==1 || flag) {
        std::cout<<"YES\n";
    } else {
        std::cout<<"NO\n";
    }
    return 0;
}
