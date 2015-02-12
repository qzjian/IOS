#ifndef _ANY_NODE_
#define _ANY_NODE_
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <assert.h>
#include <sstream> 
using namespace std;

//vector<vector<int> > result;
#pragma pack(1)
typedef struct  
{
	int len;
	int midindex;
	int type;
}LenInfo;

typedef struct
{
	int r;
	int c;
	int cur_index;
	int total_index;
}sudoInfo;

struct Interval {
    int start;
	int end;
	Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

#pragma pack()



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	     int val;
	     TreeNode *left;
	     TreeNode *right;
	     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
    };
struct RandomListNode {
	     int label;
	     RandomListNode *next, *random;
	     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };

typedef void*	QPoint;
typedef vector<int>::iterator Iter;
struct Node
{
	int	  value;
	int	  index;
	QPoint qp;
	Node* parent;
	Node* left;
	Node* right;
};

struct Qnode
{
	int i_;
	int j_;
	Qnode(int x,int y):i_(x),j_(y){};
	Qnode(){};
 }; 

class AnyNode
{
public:
	AnyNode();
	~AnyNode();
	
	void InitAscendArray(int size);
	void InitRandArray(int size);
	void printArray();

	void freeNode();
	void freeNode(Node* nd);
	void ListNode(int type);
	void MidListNode(Node* rt);
	void preListNode(Node* rt);
	Node* FindNode(int value);
	Node* FindPreNode(int value,int type);
	Node* FindPreNode(int value,Node* Pre,Node* cur);
	Node* FindNode(int value,Node* nd);

	Node* FindInsertPreNode(int value,Node* Pre,Node* cur);
	int InsertNode(int value);

	int DeleteNode(int value);


	void ArrayToBstTree();
	void ArrayToBstTreeHelper(int array[],int left,int right,Node* insert);

//	Node* m_Root;
private:
	int* m_Array;
	int  m_num;
	Node* m_Root;

	int m_test;
};


class MinStack {
public:  
    stack<int> data;  
    stack<int> mindata; 
	
    void push(int x) {
		data.push(x);  
        if(mindata.empty()||mindata.top()>=x)//优化  
            mindata.push(x);  
    }
	
    void pop() {
        if(mindata.top()==data.top())//优化  
            mindata.pop();  
        data.pop();  
    }
	
    int top() {
        return data.top();  
    }
	
    int getMin() {
		return mindata.top();  
    }
};

#endif