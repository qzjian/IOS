#ifndef _FUNCTION_H
#define _FUNCTION_H

#include "AnyNode.h"

int findMin(vector<int> &num);
int mmmax(int a,int b,int c);
int mmax(int a,int b);
int abs(int num);

int getNozeroValue(int A[],int l,int r);
int maxProduct(int A[], int n);
void reverseWords(string &s);

void printList(ListNode *head);
ListNode *insertionSortList(ListNode *head);

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
vector<int> twoSum(vector<int> &numbers, int target);

int lengthOfLongestSubstring(string s);

int charInString(char* data,char c);
double findMedianSortedArrays(int A[], int m, int B[], int n );

LenInfo PalindromeLenAtIndex(char* cs,int midindex,int left,int right);
string longestPalindrome(string s);

string convert(string text, int nRows);
int reverse(int x);

bool isPalindrome(int x);

bool dig(char c);
bool sig(char c);
int atoi(const char *str);

bool isMatch(const char *s, const char *p);

int maxArea(vector<int> &height);

void intToRoman(int num,char* rs,int index);
string intToRoman(int num);

int getThousand(char* pd);
int computeOffset(int ct);
int getCount(char* pd,int type);
int romanToInt(string s);

string longestCommonPrefix(vector<string> &strs);

int threeSumClosest(vector<int> &num, int target);
vector<vector<int> > fourSum(vector<int> &num, int target);

vector<string> letterCombinations(string digits);
ListNode *removeNthFromEnd(ListNode *head, int n);

void  generateParenthesisHelper(int l,int r,string cur,vector<string> &gvs);
vector<string> generateParenthesis(int n);

ListNode *mergeKLists(vector<ListNode *> &lists);
ListNode* mergeTwoLists(ListNode * head1, ListNode* head2);

ListNode *swapPairs(ListNode *head);
int strStr(char *haystack, char *needle);

int strStr(char *haystack, char *needle);

void nextPermutation(vector<int> &num);
int longestValidParentheses(string s);
int search(int A[], int n, int target);
bool isValidSudoku(vector<vector<char> > &board);
void solveSudoku(vector<vector<char> > &board);
bool dfs(vector<vector<char> > &board);
bool isValid(vector<vector<char> > &board, int x,int y);

string countAndSay(int n);

void dfs2(vector<int>& candidates, int target, int start);
vector<vector<int> > combinationSum2(vector<int> &num, int target);
void dfs(vector<int>& candidates, int target, int start);
vector<vector<int> > combinationSum(vector<int> &candidates, int target);

int firstMissingPositive(int A[], int n);
int trap(int A[], int n);

string multiply(string num1, string num2);

bool isMatchex(const char *s, const char *p);

int jump(int A[], int n);

vector<vector<int> > permute(vector<int> &num);
void dfs(int k,int n,vector<int> &num);

vector<vector<int> > permuteUnique(vector<int> &num);
void permuteUnique(vector<int> &num,vector<int>& out,vector<bool>& visited);

void rotate(vector<vector<int> > &matrix);

bool isValid(vector<int> &state, int row, int col);
void helper(vector<int> &state, int row);
vector<vector<string> > solveNQueens(int n);

int maxSubArray(int A[], int n);

vector<int> spiralOrder(vector<vector<int> > &matrix);

vector<Interval> merge(vector<Interval> &intervals);
static bool compareInterval( Interval v1, Interval v2);

vector<Interval> insert(vector<Interval> &v, Interval nv);

int lengthOfLastWord(const char *s);
vector<vector<int> > generateMatrix(int n);
void PermutationHelper(int a[],int l,int right,int k);

string getPermutationEx(int n, int k);
ListNode *rotateRight(ListNode *head, int k);

int uniquePaths(int m, int n);

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid);
int minPathSum(vector<vector<int> > &grid);

vector<int> plusOne(vector<int> &digits);
string addBinary(string a, string b);

vector<string> fullJustify(vector<string> &words, int L);
void addSpace(string &s, int count);

int sqrt(int x);
int climbStairs2(int n);
int climbStairs(int n);
string simplifyPath(string path);

int mymin(int x,int y);
int minDistance(string word1, string word2);

void setZeroes(vector<vector<int> > &matrix);
bool searchMatrix(vector<vector<int> > &matrix, int target);

void sortColors(int A[], int n);

string minWindow(string S, string T);

void  combineHelper(int l,int k,int n,vector<vector<int> > &rst,vector<int> &vi);
vector<vector<int> > combine(int n, int k);

void  subsetsHelper(vector<int> &src,vector<int> &tmp,int ie,vector<vector<int> > &rst);
vector<vector<int> > subsets(vector<int> &S);
vector<vector<int> > subsets2(vector<int> &S);

bool exist(vector<vector<char> > &board, string word);
bool existHelper(vector<vector<char> > &board, string word, int index,int x, int y, vector<vector<bool> >& visited);

int removeDuplicates(int A[], int n);

ListNode *deleteDuplicates(ListNode *head);
ListNode *deleteDuplicates2(ListNode *head);

int largestRectangleArea(vector<int> &height);
int maximalRectangle(vector<vector<char> > &matrix);

ListNode *partition(ListNode *head, int x);

bool isScramble(string s1, string s2);
bool isScrambleHelper(string &s1, string &s2);

void merge(int A[], int m, int B[], int n);
vector<int> grayCode(int n);

int numDecodings(string s);
vector<vector<int> > subsetsWithDup(vector<int> &S);
ListNode *reverseBetween(ListNode *head, int m, int n);

vector<string> restoreIpAddresses(string s);
void dfs_ip(string s, size_t start, size_t step, string ip,vector<string> &result);

void inorderTraversalHelper(TreeNode *root,vector<int> &tvi);
vector<int> inorderTraversal(TreeNode *root);

vector<TreeNode *> generateTrees(int start, int end);
vector<TreeNode *> generateTrees(int n);

bool isInterleave(string s1, string s2, string s3);
bool isInterleaveHelper(string s1, string s2, string s3,int i1,int i2,int i3);
bool isInterleave_dp(string s1, string s2, string s3);

void isValidBSTHelper(TreeNode *root, vector<int> &vi);
bool isValidBST(TreeNode *root);

void recoverTreeHelper(TreeNode *root);
void recoverTree(TreeNode *root);

bool isSameTree(TreeNode *p, TreeNode *q);
bool isSymmetric(TreeNode *root);
bool isSymmetric(TreeNode *lt, TreeNode *rt);

vector<vector<int> > levelOrder(TreeNode *root);
vector<vector<int> > zigzagLevelOrder(TreeNode *root);

int maxDepth(TreeNode *root);

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
TreeNode *buildTreeHelper(Iter istart, Iter iend, Iter pstart, Iter pend);

TreeNode *buildTreeHelper2(Iter istart, Iter iend, Iter pstart, Iter pend);
TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder);
vector<vector<int> > levelOrderBottom(TreeNode *root);

TreeNode *sortedArrayToBST(vector<int> &num);
TreeNode * sortedArrayToBST(vector<int> &num,int l,int r);

TreeNode *sortedListToBST(ListNode *head);

bool isBalanced(TreeNode *root, int *depth);
bool isBalanced(TreeNode *root);

int minDepth(TreeNode *root);
void  pathSum(vector<vector<int> > &res,TreeNode *root, int sum,vector<int> &vi);
vector<vector<int> > pathSum(TreeNode *root, int sum);
bool hasPathSum(TreeNode *root, int sum);
void flatten(TreeNode *root);

int numDistinct(string S, string T);
void connect(TreeLinkNode *root);
void connect2(TreeLinkNode *root);

vector<vector<int> > generate(int numRows);
vector<int> getRow(int rowIndex);

int minimumTotal(vector<vector<int> > &triangle);
int mymin(int x,int y);
int minimumTotal2(vector<vector<int> > &triangle);
//int minimumTotal(vector<vector<int> > &triangle, int i, int j);
int maxProfit(vector<int> &prices);
int maxProfit2(vector<int> &prices);
int maxProfit3(vector<int> &prices);

int maxPathSumRe(TreeNode *node, int &res);
int maxPathSum(TreeNode *root);

bool isStr(char &ch);
bool isPalindrome(string s);

int sumNumbers(TreeNode *root,int sum);
int sumNumbers(TreeNode *root);

void dfs(vector<vector<char> > &board, int i, int j);
void solve(vector<vector<char> > &board);

vector<vector<string> > partition(string s);
void DFSRecur(const string &s, bool **f, int i, vector< vector<string> > &res, vector<string> &tmp);

int minCut(string s);//*
int IsPalindrome(string &s, int i, int j);//*

int canCompleteCircuit(vector<int> &gas, vector<int> &cost);
int candy(vector<int> &ratings);

int singleNumber(int A[], int n);
int singleNumber2(int A[], int n);
RandomListNode *copyRandomList(RandomListNode *head);

bool hasCycle(ListNode *head);
ListNode *detectCycle(ListNode *head);
void reorderList(ListNode *head);

void preorderTraversal(TreeNode *root,vector<int> &vi);
vector<int> preorderTraversal(TreeNode *root);
vector<int> postorderTraversal(TreeNode *root);
void postorderTraversal(TreeNode *root,vector<int> &vi);

int op(int op1, int op2, char optor);
int evalRPN(vector<string> &tokens);

ListNode *sortList(ListNode *head);
ListNode *merge(ListNode *head1, ListNode *head2);

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
int findPeakElement(const vector<int> &num);
int maximumGap(vector<int> &num);
int compareVersion(string version1, string version2);
int majorityElement(vector<int> &num);

string convertToTitle(int n,char* table);
string convertToTitle(int n);
#endif