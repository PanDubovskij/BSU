#include <iostream>
#include <vector>

int Optimus(int Begin, int End, const std::vector<int>& snow) {

 if (Begin == End) { return 0; }
 int** dp = new int* [snow.size()];
 for (int i = 0; i < snow.size(); i++) {
  dp[i] = new int[snow.size()]{};
 }
 for (int i = End - 1; i >= Begin; i--) {
  for (int j = i + 1; j <= End ; j++) {

   if (j - i == 1) {

    if (snow[j - 1] == 2) {

     ((i == Begin) && (j == Begin + 1)) ?
      dp[i][j] = 2 :
      dp[i][j] = 3;
    }
    else { dp[i][j] = 1; }

   }
   else { dp[i][j] = dp[i][j - 1] + dp[j - 1][j]; }
  }
 }
 return dp[Begin][End];
}

int SnowMachine(int begin, int end, int k,const  std::vector<int>& snow) {

 if (begin == -1) { return 0; }

 else if (k < begin) {
  return Optimus(k, end, snow) < 2 * (end - k) ?
         Optimus(k, end, snow) :
   2 * (end - k);
 }
 else if (k > end) {
  return Optimus(begin, k, snow) < 2 * (k - begin) ?
         Optimus(begin, k, snow) :
   2 * (k - begin);
 }
 else {
  int min1 = Optimus(begin, k, snow);
  if (min1 > 2 * (k - begin)) { min1 = 2 * (k - begin); }

  int min2 = Optimus(k, end, snow);
  if (min2 > 2 * (end - k)) { min2 = 2 * (end - k); }

  return 2 * (end - k) + min1 > 2 * (k - begin) + min2 ?
   2 * (k - begin) + min2 :
   2 * (end - k) + min1;
 }
 return 0;
}

int main() {
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 freopen("in.txt", "r", stdin);
 freopen("out.txt", "w", stdout);

 int n, k;
 std::cin >> n >> k;
 std::vector<int> snow(n);

 int begin = -1, end = -1;
 for (int i = 0; i < n; i++) {
  int first, second;
  std::cin >> first >> second;
  snow[i] = first + second;

  if (!snow[i]) { continue; }
  else {
   if (begin == -1) { begin = i; }
   else if (i > end) { end = i; }
  }
 }

 std::cout << SnowMachine(begin, end + 1, k, snow);

 return 0;
}