#include "AnyNode.h"

AnyNode::AnyNode()
{
	m_num=0;
	m_Array=NULL;
	m_Root=NULL;

	m_test=0;
}
void AnyNode::freeNode()
{
	freeNode(m_Root);
}
void AnyNode::freeNode(Node* nd)
{
	if (nd)
	{
		freeNode(nd->left);
		freeNode(nd->right);
		free(nd);
	}
}
AnyNode::~AnyNode()
{
	freeNode();
	if (m_Array) 
	{
		free(m_Array);
		m_Array=NULL;
	}
}
void AnyNode::InitAscendArray(int size)
{
	if(m_Array)	free(m_Array);
	m_num=size;
	m_Array=(int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++)
	{
		m_Array[i]=i;
	}
}

void AnyNode::ListNode(int type)
{
	if(type==0)		preListNode(m_Root);
	if (type==1)	MidListNode(m_Root);
}

void AnyNode::preListNode(Node* rt)
{
	if (rt&&rt->value!=INT_MIN)
	{
		printf("v=%d\t",rt->value);
		preListNode(rt->left);
		preListNode(rt->right);
	}
}

void AnyNode::MidListNode(Node* rt)
{
	if (rt&&rt->value!=INT_MIN)
	{
		MidListNode(rt->left);
		printf("v=%d\t",rt->value);
		MidListNode(rt->right);
	}
}

int AnyNode::DeleteNode(int value)
{
	Node* pre=FindPreNode(value,0);
	if (!pre)	return -1;
	if (pre==m_Root)
	{
		Node* new_root;
		if (pre->right)
		{
			new_root=pre->right;
			Node* nr_left=new_root->left;
			Node* nr_right=new_root->right;
		}
	}
	return 0;
}

void AnyNode::ArrayToBstTree()
{
	if (m_num<1)	return ;
	printf("------m_num=%d\n",m_num);
	if(m_Root==NULL)
	{
		m_Root=(Node*)malloc(sizeof(Node));
		memset(m_Root,0,sizeof(Node));
		m_Root->value=INT_MIN;
	}
	ArrayToBstTreeHelper(m_Array,0,m_num,m_Root);
}

void AnyNode::ArrayToBstTreeHelper(int array[],int left,int right,Node* insert)
{	
	if (left>right)	return ;
	int middle=(left+right)/2;
	insert->value=array[middle];
	insert->index=middle;

	insert->left=(Node*)malloc(sizeof(Node));
	memset(insert->left,0,sizeof(Node));
	insert->left->value=INT_MIN;

	insert->right=(Node*)malloc(sizeof(Node));
	memset(insert->right,0,sizeof(Node));
	insert->right->value=INT_MIN;

	ArrayToBstTreeHelper(array,left,middle-1,insert->left);
	ArrayToBstTreeHelper(array,middle+1,right,insert->right);
}

Node* AnyNode::FindNode(int value)
{
	return FindNode(value,m_Root);
}

Node* AnyNode::FindPreNode(int value,int type)
{
	Node* preNode=m_Root;
	if(type==0) return FindPreNode(value,preNode,m_Root);
	if(type==1)	return FindInsertPreNode(value,preNode,m_Root);
}

Node* AnyNode::FindInsertPreNode(int value,Node* pre,Node* cur)
{
	if(cur==NULL)	return pre;
	if (cur->value==value)	return pre;
	if(cur->value<value)
	{
		pre=cur;
		return FindInsertPreNode(value,pre,cur->right);
	}else if (cur->value>value)
	{
		pre=cur;
		return FindInsertPreNode(value,pre,cur->left);
	}
	printf("---------prev=%d----\n",pre->value);
	return pre;
}

int AnyNode::InsertNode(int value)
{
	Node* nd=FindPreNode(value,1);
	if (nd==m_Root)
	{
		nd=(Node*)malloc(sizeof(Node));
		memset(nd,0,sizeof(Node));
		nd->value=value;
		if (m_Root==NULL)
		{
			m_Root=nd;
		}else
		{
			printf("-------------\n");
			if (m_Root->value==value)	return 0;
			else if (m_Root->value<value)	m_Root->right=nd;
			else	m_Root->left=nd;
		}
	}
	return 0;
}

Node* AnyNode::FindPreNode(int value,Node* Pre,Node* cur)
{
	if(cur==NULL)	return NULL;
	if (cur->value==value)	return Pre;
	if(cur->value<value)
	{
		Pre=cur;
		return FindPreNode(value,Pre,cur->right);
	}else if (cur->value>value)
	{
		Pre=cur;
		return FindPreNode(value,Pre,cur->left);
	}
	return NULL;
}

Node* AnyNode::FindNode(int value,Node* nd)
{
	if (nd==NULL)	return nd;
	if(nd->value==value) return nd;
	if(nd->value<value)	 return FindNode(value,nd->right);
	if(nd->value>value)	 return FindNode(value,nd->left);
	return NULL;
}

void AnyNode::printArray()
{
	for (int i=0;i<m_num;i++)
	{
		printf("a[%d]=%d\t",i,m_Array[i]);
		if ((i+1)%10==0)	printf("\n");
	}
}