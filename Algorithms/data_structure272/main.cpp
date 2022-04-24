#include <iostream>
#include <cstring>

constexpr int N = 101;
int gMap[N][N], nMap[N][N];
int mapNo[N];
int connC;
int inC[N], outC[N];
bool visit[N];
int n;
int stack[N * N], sn;

void dfs1(int x) {
    visit[x] = true;
    for (int i = 1; i <= n; ++i) {
        if (gMap[x][i] && !visit[i]) { dfs1(i); }
    }
    stack[++sn] = x;
}

void dfs2(int x, int mark) {
    visit[x] = true;
    mapNo[x] = mark;
    for (int i = 1; i <= n; ++i) {
        if (gMap[i][x] && !visit[i]) { dfs2(i, mark); }
    }
}

void kosaraju() {
    int i, j;
    for (i = 1; i <= n; ++i) {
        if (!visit[i]) { dfs1(i); }
    }
    memset(visit, false, sizeof(visit));
    for (i = sn; i >= 1; --i) {
        if (!visit[stack[i]]) { dfs2(stack[i], ++connC); }
    }
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            if (gMap[i][j] && mapNo[i] != mapNo[j]) { nMap[mapNo[i]][mapNo[j]] = true; }
        }
    }
}



void Solve() {
    //I love Olya too much
    kosaraju();
    memset(inC, 0, sizeof(inC));
    memset(outC, 0, sizeof(outC));
    int i, j;
    for (i = 1; i <= connC; ++i) {
        for (j = 1; j <= connC; ++j) {
            if (nMap[i][j]) { ++outC[i], ++inC[j]; }
        }
    }
    int zeroIn = 0, zeroOut = 0;
    for (i = 1; i <= connC; ++i) {
        if (!inC[i]) { ++zeroIn; }
        if (!outC[i]) { ++zeroOut; }
    }
    printf("%d\n", zeroIn);
    if (connC == 1) { puts("0"); }
    else { printf("%d\n", zeroIn > zeroOut ? zeroIn : zeroOut); }
}

bool Read() {
    if (scanf("%d", &n) == EOF || n == -1) { return false; }
    for (int i = 1, t; i <= n; ++i) {
        while (scanf("%d", &t), t) { gMap[i][t] = true; }
    }
    return true;
}

int main() {
    //Olya is the best girlfriend in the world

    int n;
    std::cin>>n;
//    int receiver;
//    std::cin>>receiver;
    for (int i = 1, j; i <= n; ++i) {
        while (std::cin>>j) { gMap[i][j] = true; }
    }

    while (Read()) { Solve(); }
    return 0;
}