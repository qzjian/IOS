#include "AnyNode.h"

int findMin(vector<int> &num) {
	int min=num.at(0);
	for(int i=0;i<num.size();i++){
		int cur=num.at(i);
		if(cur<min)
			min=cur;
	}
	return min;
 }

int mmax(int a,int b)
{
	return a>b?a:b;
}
int mmmax(int a,int b,int c)
{
	int m=a>b?a:b;
	return m>c?m:c;
}

int abs(int num)
{
	return num<0?-num:num;
}

int getNozeroValue(int A[],int l,int r)
{
	if (l>=r)
	{
		return A[r];
	}
	int maxv=A[l];
	int curv=maxv;
	
	int frontIndex=-1;
	int  lastIndex=-1;
	int neg_ct=0;
	for (int i=l;i<r;i++)
	{
		if (A[i]<0)
		{
			if (frontIndex==-1)
			{
				frontIndex=i;
			}else
				lastIndex=i;
			neg_ct++;
		}
		if (i==l)
		{
			curv=A[i];
		}else
			curv*=A[i];
		
		if (maxv<curv)
			maxv=curv;
	}
	
	if (neg_ct%2)
	{
		int large1=1;
		bool getin=false;
		for (int i=l;i<frontIndex;i++)
		{
			getin=true;
			large1*=A[i];
		}
		if(getin) maxv=mmax(maxv,large1);
		getin = false;
		int large2=1;
		if(lastIndex==-1)
		{
			lastIndex=frontIndex;
		}
		for (i=lastIndex+1;i<r;i++)
		{
			getin=true;
			large2*=A[i];
		}
		
		if(getin) maxv=mmax(maxv,large2);
		
		int l3=1;
		getin=false;
		for (i=l;i<lastIndex;i++)
		{
			getin=true;
			l3*=A[i];
		}
		if(getin) maxv=mmax(maxv,l3);
		int l4=1;
		getin=false;
		for (i=frontIndex+1;i<r;i++)
		{
			getin=true;
			l4*=A[i];
		}
		if(getin) maxv=mmax(maxv,l4);
	}
	return maxv;
}

int maxProduct(int A[], int n) {
	if (n<=0) return -1;
	int largest_value=A[0];
	int cur_value=0;
	
	int firt_zero_index=-1;
	int second_zero_index=-1;
	for (int i=0;i<n;i++)
	{
		if (A[i]==0)
		{
			if (firt_zero_index==-1)
			{
				firt_zero_index=i;
				cur_value=getNozeroValue(A,0,firt_zero_index);
				largest_value=mmax(cur_value,largest_value);
				firt_zero_index++;
			}else
			{
				second_zero_index=i;
				cur_value=getNozeroValue(A,firt_zero_index,second_zero_index);
				largest_value=mmax(cur_value,largest_value);
				firt_zero_index=second_zero_index;
			}
			largest_value=mmax(largest_value,0);
		}
	}
	
	if (firt_zero_index==-1)
	{
		largest_value=getNozeroValue(A,0,n);
	}
	
	if (second_zero_index!=-1)
	{
		cur_value=getNozeroValue(A,second_zero_index,n);
		largest_value=mmax(cur_value,largest_value);
	}else if (firt_zero_index!=-1)
	{
		cur_value=getNozeroValue(A,firt_zero_index,n);
		largest_value=mmax(cur_value,largest_value);
	}
	
	return largest_value;
 }

void reverseWords(string &s) {
	int sz=s.size();
	if(sz==0)
	{
		s=string("");
		return ;
	}
	char* asc=(char*)malloc(sz);
	memset(asc,0,sz);
	memcpy(asc, s.data(),sz);
	
	printf("as:%s\n",asc);
	
	char* p1=asc;
	char* p2=asc+sz-1;
	int e=sz-1;
	for (int i=0;i<sz/2;i++)
	{
		char temp=*p1;
		*p1=*p2;
		*p2=temp;
		p1++;
		p2--;
	}
	
	int index=0;
	int len=0;
	p1=asc;
	p2=asc;
	char* pswap=p2;
	while(index<sz)
	{
		if (index==sz-1)
		{
			for (int i=0;i<=len/2;i++)
			{
				char temp=*p1;
				*p1=*p2;
				*p2=temp;
				p1++;
				p2--;
			}
			p2+=2;
			p1=p2;
			len=0;
			break;
		}

		if(*p2!=' ')
		{
			p2++;
			index++;
			len++;
			continue;
		}

		p2--;
		char* ptemp=p2;
		for (int i=0;i<len/2;i++)
		{
			char temp=*p1;
			*p1=*p2;
			*p2=temp;
			p1++;
			p2--;
		}
		p2=ptemp+2;
		p1=p2;
		len=0;
		index++;
	}

	p1=asc;
	p2=asc;
	while (*p1++==' ')	sz--;
	p1-=1;
	for (i=0;i<sz-1;i++)
	{
		*p2++=*p1++;
	}
	if(sz==1)
	    s=string(asc);
	printf("as2:%s\n",asc);
  }


void printList(ListNode *head)
{
	ListNode* p=head;
	while(head)
	{
		printf("value=%d\n",head->val);
		head=head->next;
	}
}

ListNode *insertionSortList(ListNode *head) {
	ListNode* phead=head;
	ListNode* p1=phead;
	ListNode* pre1=p1;
	
	ListNode* p2=phead->next;
	ListNode* pre2=head;
	
	while (p2)
	{
		int tv=p2->val;
		while(p1!=p2)
		{
			if (tv<=p1->val)
			{
				if (p1==phead)//头部插入
				{
					pre2->next=p2->next;
					p2->next=phead;
					phead=p2;
					p1=phead;
					p2=pre2->next;
					break;
				}else
				{
					pre2->next=p2->next;
					pre1->next=p2;
					p2->next=p1;
					p1=phead;
					p2=pre2->next;
					break;
				}
			}else
			{
				pre1=p1;
				p1=p1->next;
			}
		}
		if (p1==p2)
		{
			pre2=p2;
			p2=p2->next;
			p1=phead;
		}
	}
		
		return p1;
    }

vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> tmpV(numbers.begin(),numbers.begin()+numbers.size()) ;
	std::sort (tmpV.begin(), tmpV.end());
	vector<int> dst;
	int num1;
	int num2;
	int left=0;
	int right=tmpV.size();
	int curl=left;
	int curr=right-1;
	int cs=0;
	while (curl<curr)
	{
		cs=tmpV.at(curl)+tmpV.at(curr);
		if (cs==target)
		{
			num1=tmpV.at(curl);
			num2=tmpV.at(curr);
			break;
		}else if (cs>target)
		{
			curr--;
		}else
		{
			curl++;
		}
	}
	int index1=0;
	int index2=0;
	if (curl<=curr)
	{
		for (int i=0;i<numbers.size();i++)
		{
			if (numbers.at(i)==num1&&index1==0)
			{
				index1=i+1;
			}else if(numbers.at(i)==num2)
			{
				index2=i+1;
			}
			if (index2>0&&index1>0)
			{
				printf("index1=%d index2=%d\n",index1,index2);
				break;
			}
		}
	}
	
	if (index1<index2)
	{
		dst.push_back(index1);
		dst.push_back(index2);
	}else
	{
		dst.push_back(index2);
		dst.push_back(index1);
	}
	
	return dst;
 }


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode* p1=l1;
	ListNode* p2=l2;
	
	ListNode* result=(ListNode*)malloc(sizeof(ListNode));
	result->val=0;
	result->next=NULL;
	ListNode* head=result;
	ListNode* pre=result;
	int add=0;
	while(p1&&p2)
	{
		pre=result;
		int cur_sum=p1->val+p2->val+add;
		int mod=cur_sum%10;
		result->val=mod;
		result->next=(ListNode*)malloc(sizeof(ListNode));
		result->next->val=0;
		result=result->next;
		p1=p1->next;
		p2=p2->next;
		add=cur_sum/10;
	}
	while(p1)
	{
		pre=result;
		int cur_sum=p1->val+add;
		int mod=cur_sum%10;
		result->val=mod;
		result->next=(ListNode*)malloc(sizeof(ListNode));
		result->next->val=0;
		result=result->next;
		p1=p1->next;
		add=cur_sum/10;
	}
	
	while(p2)
	{
		pre=result;
		int cur_sum=p2->val+add;
		int mod=cur_sum%10;
		result->val=mod;
		result->next=(ListNode*)malloc(sizeof(ListNode));
		result->next->val=0;
		result=result->next;
		p2=p2->next;
		add=cur_sum/10;
	}
	if (add>0)
	{
		pre=result;
		result->val=add;
		result=NULL;
	}else
	{
		pre->next=NULL;
		free(result);
		result=NULL;	
	}
	
	return head;
  }

 int charInString(string data,char c)
 {
        int i=0;
        while(data[i]!=c)  i++;
	    return i+1;
 }
int lengthOfLongestSubstring(string s) {
	if(s.size()==0) return 0;
    	char char_table[1024]={0};
    	int sz=s.size();
    	string temdata="";
    	
		int cur_size=0;
		int max_size=0;
		int cur_index=0;
		for (int i=cur_index;i<sz;)
		{
			char cur_c=s[i];
			if (char_table[cur_c]==1)
			{
			   	int ret=charInString(temdata,cur_c);
				max_size=max_size>cur_size?max_size:cur_size;
				if(max_size>=126)   return 126;
				
				cur_size=0;
				cur_index+=ret;
				i=cur_index;
				memset(char_table,0,1024);
				temdata="";
			}else
			{	
			    i++;
			    char_table[cur_c]++;
				temdata[cur_size++]=cur_c;
			}
		}
		max_size=max_size>cur_size?max_size:cur_size;
		return max_size;
}

double findMedianSortedArrays(int A[], int m, int B[], int n ){
	
    if(m==0&&n==0)  return 0;
	int* tmp_array=(int*)malloc(sizeof(int)*(m+n));
	int index_a=0;
	int index_b=0;
	int index_tmp=0;
	int mid=(m+n)>>1;
	while(index_a<m&&index_b<n)
	{
		if (A[index_a]<=B[index_b])
		{
			tmp_array[index_tmp++]=A[index_a++];
		}else
			tmp_array[index_tmp++]=B[index_b++];
	}
	while(index_a<m)
		tmp_array[index_tmp++]=A[index_a++];
	while(index_b<n)
		tmp_array[index_tmp++]=B[index_b++];
	double diff=0;
	if((m+n)%2==0&&mid-1>=0)
	{
		diff =(tmp_array[mid]+tmp_array[mid-1])/2.0;  
	}else
		diff=tmp_array[mid];
	return diff;
}

LenInfo PalindromeLenAtIndex(char* cs,int midindex,int left,int right)
{
	int l=midindex-1;
	int r=midindex+1;
	int len=1;
	while(l>=0&&r<right)
	{
		if (cs[l]==cs[r])
		{
			len+=2;
			l--;
			r++;
		}else
			break;
	}
    l=midindex-1;
	r=midindex;
	int len2=0;
	if (cs[l]==cs[r]&&l>=0&&r<right)
	{
		len2=2;
		l--;
		r++;
		while(l>=0&&r<right)
		{
			if (cs[l]==cs[r])
			{
				len2+=2;
				l--;
				r++;
			}else
				break;
		}
	}
	
	int type=0;
	int final_len=0;
	if (len>len2)
	{
		final_len=len;
		type=0;
	}else
	{
		final_len=len2;
		type=1;
	}
	LenInfo li;
	li.len=final_len;
	li.type=type;
	li.midindex=midindex;
	return li;
}

string longestPalindrome(string s)
{
	int size=s.size();
	if (size==0||size==1)	return s;
	
	char* p_s=(char*)s.c_str();
	char* cd=(char*)malloc(size);
	memset(cd,0,size);
	strcpy(cd,p_s);
	
	int mid=size/2;
	int max_len=1;
	int max_mid_index=mid;
	LenInfo finale_li;
	for (int i=0;i<size;i++)
	{
		max_mid_index=i;
		LenInfo li =PalindromeLenAtIndex(cd,max_mid_index,0,size);
		if (li.len>max_len)
		{
			finale_li=li;
			max_len=finale_li.len;
		}
	}
	string result_s;
	max_mid_index=finale_li.midindex;
	int type=finale_li.type;
	if (type==0)
	{
		int start=max_mid_index-(finale_li.len-1)/2;
		int i=0;
		while(i++<finale_li.len)
		{
			printf("i=%d\n",i);
			result_s+=cd[start++];
		}
		return result_s;
	}
	if (type==1)
	{
		int start=max_mid_index-(finale_li.len)/2;
		int i=0;
		while(i++<finale_li.len)
		{
			result_s+=cd[start++];
		}
		return result_s;
	}
	
	return result_s;
 }

string convert(string text, int nRows)
{
	if (nRows<=1)	return text;
	
	int zig_sz=2*nRows-2;//关键
	int sz=text.size();
	string rs;
	for (int i=0;i<nRows;i++)
	{
		for (int base=i;;base+=zig_sz)
		{
			if (base>=sz)	break;
			rs+=text[base];
			if (i>0&&i<nRows-1)
			{
				int mid_index=base+zig_sz-2*i;
				if (mid_index<sz)
				{
					rs+=text[mid_index];
				}
			}
		}
	}
	return rs;
}
int reverse(int x) {
	int ret = 0;
	while (x != 0) {
		// handle overflow/underflow
		if (abs(ret) > 214748364) {
			return 0;
		}
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}

bool isPalindrome(int x) {
	if(x<0)			return false;
	if (x/10==0)	return true;
	unsigned char mod[10]={0};
	int index=0;
	int total=0;
	int tx=x;
	while(tx)
	{
		mod[index++]=tx%10;
		total++;
		tx=tx/10;
	}
	total++;
	int l=0;
	int r=total-1;
	while(l<r)
	{
		if (mod[l++]!=mod[r++])	return false;
	}
	return true;
}

bool dig(char c)
{
	int ret=c-'0';
	if (ret>=0&&ret<=9)	return true;
	return false;
}

bool sig(char c)
{
	if (c=='+'||c=='-')	return true;
	return false;
}

int atoi(const char *str) {
	if (str==NULL)	return 0;
    int len=strlen(str);
    if(len==0) return 0;
    char* p=(char*)str;
	int sign=1;
	vector<int> rs;
	while(p&&len--)
	{
		if (sig(*p)||dig(*p))
		{
			if (*p=='+')        sign=1;
			else if(*p=='-')    sign=-1;
			else                rs.push_back(*p-'0');
			break;
		}else if(*p!=' ')
		    return 0;
		p++;
	}
	while(p++&&len--)
	{
	    if(len<0)       return 0;
		if (p&&dig(*p)) rs.push_back(*p-'0');
		else            break;
	}

	double rst=0;
	int sz=rs.size();
	for (int i=0;i<sz;i++)
	{
		rst=rst*10+rs[i];
        if(sign==1&&rst>INT_MAX) return INT_MAX;
        if(sign==-1&&rst<INT_MIN) return INT_MIN;
	}
	return (int)rst*sign;
}

bool isMatchex(const char *s, const char *p) 
{
	const char* star=NULL;  
	const char* ss=s;   
	while (*s){  
		if ((*p=='?')||(*p==*s)){s++;p++;continue;}  
		if (*p=='*'){star=p++; ss=s;continue;}  
		if (star){ p = star+1; s=++ss;continue;}  
		return false;  
	}  
	while (*p=='*'){p++;}  
	return !*p;  
}

bool isMatch(const char *s, const char *p) 
{
	if(*p==0)			return (*s==0);
	
	if (*s==0)
	{
		if (*p=='*')	return isMatch(s,p+1);
		else			return false;
	}

	if (*p=='*')
	{
		while (*(p+1)=='*') p++;
		while (*s!=0)
		{
			if (isMatch(s,p+1)) return true;
			s++;
		}
	}else if (*p=='?'||*p==*s)
	{
		return isMatch(s+1,p+1);
	}
	return false;
}

int maxArea(vector<int> &height)
{
	int len=height.size();
	if (len<2)	return 0;
	int l=0;
	int r=len-1;
	int lh=height.at(l);
	int rh=height.at(r);
	int h=lh<rh?lh:rh;
	int maxara=(r-l)*h;
	
	int cur_ara=0;
	
	while(l<r)
	{
		h=lh<rh?lh:rh;
		if (lh==h)
		{
			l++;
			lh=height.at(l);
			if(lh>h)
			{
				h=lh;
				h=lh<rh?lh:rh;
				cur_ara=(r-l)*h;
				if (cur_ara>maxara)	maxara=cur_ara;
			}
		}else 
		{
			r--;
			rh=height.at(r);
			if (rh>h)
			{
				h=rh;
				h=lh<rh?lh:rh;
				cur_ara=(r-l)*h;
				if (cur_ara>maxara)	maxara=cur_ara;
			}
		}
	}
	return maxara;
}

void intToRoman(int num,char* rs,int index)
{
	if (num==0)	return ;
	int now_index=index; 
	string result;
	int tn=num;
	int ct=1;
	int front=num;
	while(tn/10)
	{
		front=tn/10;
		ct*=10;
		tn=tn/10;
	}

	int sf=front;

	if (ct==1000)
	{
		if(front<4)
		{
			while(front--)
			{
				rs[now_index++]='M';
			}
		}
	}else if (ct==100)
	{
		if(front<4)
		{
			while(front--)
			{
				rs[now_index++]='C';
			}
		}else if (front==4)
		{
			rs[now_index++]='C';
			rs[now_index++]='D';
		}else if (front==5)
		{
			rs[now_index++]='D';
		}else if (front!=9)
		{
			rs[now_index++]='D';
			while((-5+front--))
			{
				rs[now_index++]='C';
			}
		}else
		{
			rs[now_index++]='C';
			rs[now_index++]='M';
		}
	}else if (ct==10)
	{
		if(front<4)
		{
			while(front--)
			{
				rs[now_index++]='X';
			}
		}else if (front==4)
		{
			rs[now_index++]='X';
			rs[now_index++]='L';
		}else if (front==5)
		{
			rs[now_index++]='L';
		}else if (front!=9)
		{
			rs[now_index++]='L';
			while((-5+front--))
			{
				rs[now_index++]='X';
			}
		}else
		{
			rs[now_index++]='X';
			rs[now_index++]='C';
		}
	}else if (ct==1)
	{
		if(front<4)
		{
			while(front--)
			{
				rs[now_index++]='I';
			}
		}else if (front==4)
		{
			rs[now_index++]='I';
			rs[now_index++]='V';
		}else if (front==5)
		{
			rs[now_index++]='V';
		}else if (front!=9)
		{
			rs[now_index++]='V';
			while((-5+front--))
			{
				rs[now_index++]='I';
			}
		}else
		{
			rs[now_index++]='I';
			rs[now_index++]='X';	
		}
	}
	int cur_v=num-(ct*sf);
	intToRoman(cur_v,rs,now_index);
}

string intToRoman(int num) {
	if (num<1||num>3999)	return "";
	char rs[32]={0};
	intToRoman(num,rs,0);

	string str(rs);
	return str;
 }

int getThousand(char* pd)
{
	if (*pd==0)	return -1;
	int ct=0;
	while(*pd=='M')
	{
		pd++;
		ct++;
	}
	return ct;
}

int getCount(char* pd,int type)
{
	char sign[4]={0};
	if (type==1)
	{
		sign[0]='I';
		sign[1]='V';
		sign[2]='X';
	}else if (type==2)
	{
		sign[0]='X';
		sign[1]='L';
		sign[2]='C';
	}else if (type==3)
	{
		sign[0]='C';
		sign[1]='D';
		sign[2]='M';
	}
	if (*pd==0)	return -1;
	int ct=0;
	if(*pd==sign[0])
	{
		pd++;
		if(*pd==sign[1])		return 4;
		else if(*pd==sign[2])	return 9;
		else
		{
			ct++;
			while(*pd==sign[0])
			{
				ct++;
				pd++;
				if (ct>3)	return -1;	
			}
		}
	}else if (*pd==sign[1])
	{
		pd++;
		ct=5;
		while(*pd==sign[0])
		{
			ct++;
			pd++;
			if(ct>8)	return -1;
		}
	}
	return ct;
}

int computeOffset(int ct)
{
	if (ct<4)	return ct;
	if (ct==5)	return 1;
	if (ct==9||ct==4)	return 2;
	return ct-4;
}
int romanToInt(string s) {
	
	int sz=s.size();
	if (sz==0)	return 0;
	char* pd=(char*)malloc(sz+1);
	memset(pd,0,sz+1);
	strcpy(pd,s.c_str());
	char* p=pd;
	int final_v=0;
	
	int ret=getThousand(p);
	if (ret==-1)	return final_v;
	final_v=final_v+ret*1000;
	p+=computeOffset(ret);
	
	int type=3;
	while(type)
	{
		int muti=1;
		int tt=type;
		while(--tt) muti*=10;
		ret=getCount(p,type);
		if (ret==-1)	return final_v;
		final_v=final_v+ret*muti;
		p+=computeOffset(ret);
		type--;
	}
	return final_v;
 }

string longestCommonPrefix(vector<string> &strs) {
	
	string result;
	int sz=strs.size();
	
	string s1=strs.at(0);
	int j=0;
	for (int i=0;i<s1.length();i++)
	{
		char cur=s1[i];
		j=1;
		for (j=1;j<sz;j++)
		{
			string s2=strs.at(j);
			if (s2.length()<i+1)	return result;
			char sec=s2[i];
			if (sec!=cur)	return result;
		}
		result+=cur;
	}
	
	return result;
  }

int threeSumClosest(vector<int> &num, int target) {
	int sz=num.size();
	if (sz<3)	return 0;
	sort(num.begin(),num.end());
	int dst=INT_MAX;
	int best=INT_MAX;
	for (int i=0;i<sz-2;i++)
	{
		int one=num[i];
		if (i==0||num[i]>num[i-1])
		{
			int l=i+1;
			int r=sz-1;
			while (l<r)
			{
				int cv=one+num[l]+num[r];
				int diff=cv-target;
				if (diff==0)		return target;
				if (diff>0)			r--;
				if (diff<0)			l++;
				if(abs(diff)<dst)
				{
					dst=abs(diff);
					best=cv;
				}
			}
		}
	}
	return best;
 }

vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > rs;
	int sz=num.size();
	if (sz<4)	return rs;
	sort(num.begin(),num.end());
	int dst=INT_MAX;
	int best=INT_MAX;
	for (int i=0;i<sz-3;i++)
	{
		int one=num[i];
		if(i!=0&&num[i]==num[i-1]) continue;
		for (int j=i+1;j<sz-2;j++)
		{
			int two=num[j];
			if (j==i+1||num[j]>num[j-1])
			{
				int l=j+1;
				int r=sz-1;
				while (l<r)
				{
					int cv=one+two+num[l]+num[r];
					if (cv<target)		l++;
					else if(cv>target)	r--;
					else
					{
						vector<int> fv(4);
						fv[0]=one;
						fv[1]=two;
						fv[2]=num[l];
						fv[3]=num[r];
						rs.push_back(fv);
						l++;
						r--;
						while(num[l]==num[l-1]&&l<r)	l++;
						while(num[r]==num[r+1]&&l<r)	r--;
					}
				}
			}
			
		}
	}
	return rs;
   }
vector<string> letterCombinations(string digits) {
	string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	vector<string> dst_rs;
	int sz=digits.size();
	string em="";
	if(sz<=0)
	{
		dst_rs.push_back(em);
		return dst_rs;
	}
	
	int ifs=digits[0]-'0';
	string fs=numap[ifs];
	for (int a=0;a<fs.length();a++)
	{
		string cst;
		cst+=fs[a];
		dst_rs.push_back(cst);
	}
	for (int i=1;i<digits.length();i++)
	{
		int num=digits[i]-'0';
		string first_str=numap[num];
		char one=first_str[i];
		vector<string> tem_rs;
		for (int j=0;j<dst_rs.size();j++)
		{	
			for (int k=0;k<first_str.length();k++)
			{
				string cs;
				cs+=dst_rs[j];
				cs+=first_str[k];
				tem_rs.push_back(cs);
			}
		}
		dst_rs=tem_rs;
	}
	return  dst_rs;
    }

ListNode *removeNthFromEnd(ListNode *head, int n) {
	if (head==NULL)	return head;
	int len=0;
	ListNode* ph=head;
	while(ph)
	{
		len++;
		ph=ph->next;
	}
	ph=head;
	int diff=len-n;
	if (diff<0)	return head;
	if (diff==0) 
	{
		ListNode* tn=head->next;
		free(head);
		head=NULL;
		return tn;
	}
	
	ListNode* preDst=ph;
	ListNode* Dst=ph;
	while(diff--)
	{
		preDst=Dst;
		Dst=Dst->next;
	}
	
	preDst->next=Dst->next;
	free(Dst);
	Dst=NULL;
	return ph;
  }

void  generateParenthesisHelper(int l,int r,string cur,vector<string> &gvs)
{
	if(l==0&&r==0)  
	{  
		gvs.push_back(cur);  
	}  
	if(l>0)  
	{  
		generateParenthesisHelper(l-1,r,cur+'(',gvs);  
	}  
	if(r>0&&l<r)  
	{  
		generateParenthesisHelper(l,r-1,cur+')',gvs);  
	}  
}
vector<string> generateParenthesis(int n) {
	string cs;
	vector<string> vs(0,"");
	generateParenthesisHelper(n,n,cs,vs);
	return vs;
}

ListNode* mergeTwoLists(ListNode * head1, ListNode* head2)
{
	ListNode node(0), *res = &node;
	while(head1 && head2)
	{
		if(head1->val <= head2->val)
		{
			res->next = head1;
			head1 = head1->next;
		}else
		{
			res->next = head2;
			head2 = head2->next;
		}
		res = res->next;
	}
	if(head1)
		res->next = head1;
	else if(head2)
		res->next = head2;
	return node.next;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
	
	int sz=lists.size();
	if (sz==0)	return NULL;
	ListNode* hl=lists[0];
	while(sz >1)
	{
		int k = (sz+1)/2;
		for(int i = 0; i < sz/2; i++)
			lists[i] = mergeTwoLists(lists[i], lists[i + k]);
		sz = k;
	}
    return lists[0];
}


ListNode *swapPairs(ListNode *head) {
	ListNode* p1=head;
	if (p1==NULL||p1->next==NULL)	return p1;
	ListNode* p2=p1->next;
	while (p1&&p2)
	{
		int tv=p1->val;
		p1->val=p2->val;
		p2->val=tv;
		
		p2=p2->next;
		if(p2&&p2->next)
		{
			p1=p2;
			p2=p2->next;
		}else
			return head;
		
	}
	return head;
  }
int strStr(char *haystack, char *needle) {
	
    if (haystack==NULL||needle==NULL)	return -1;
	int len1=strlen(haystack);
	int len2=strlen(needle);
	if (len2>len1)	return -1;
	if(len2==0)    return 0;
	int index=0;
	int v_index=index;
	int diff=len1-len2;
	char* p1=haystack;
	char* p2=needle;
	while (index<=diff)
	{
		v_index=0;
		p1=haystack+index++;
		p2=needle;
		while (p1&&p2&&*p1==*p2)
		{
			v_index++;
			if (v_index==len2)	return index;
			p1++;
			p2++;
		}
	}
	return -1;
  }

void nextPermutation(vector<int> &num) {
	
	int sz=num.size();
	if (sz<=1) return;
	
	int dstindex1=-1;
	int dstindex2;
	for (int i=sz-1;i>0;i--)
	{
		if (num[i]>num[i-1])
		{
			dstindex1=i-1;
			break;
		}
	}
	if (dstindex1==-1)
	{
		int left=0;
		int right=sz-1;
		while (left<right)
		{
			int t=num[left];
			num[left]=num[right];
			num[right]=t;
			left++;
			right--;
		}
	}else
	{
		for (int j=sz-1;j>dstindex1;j--)
		{
			if (num[j]>num[dstindex1])	break;
		}
		int t=num[dstindex1];
		num[dstindex1]=num[j];
		num[j]=t;
		int l=dstindex1+1;
		int r=sz-1;
		while (l<r)
		{
			int t=num[l];
			num[l]=num[r];
			num[r]=t;
			l++;
			r--;
		}
	}
}

int longestValidParentheses(string s) {
	int slen=s.length();
	int* vi=(int*)malloc(sizeof(int)*slen);
	for (int a=0;a<slen;a++)
	{
		vi[a]=0;
	}
	int pre_index=0;
	
	int max_len=0;
	
	stack<char> pre_sign;
	for (int i=0;i<slen;i++){
		if (s[i]==')')
		{
			if (pre_sign.size()==0){
				if (vi[0]>max_len)	max_len=vi[0];
				vi[0]=0;
				continue;
			}else{
				pre_sign.pop();
				if (pre_sign.size()==pre_index)
				{
					vi[pre_index]+=2;
				}else if (pre_sign.size()>pre_index)
				{
					pre_index=pre_sign.size();
					vi[pre_index]+=2;
				}else if(pre_sign.size()<pre_index)
				{
					pre_index=pre_sign.size();
					vi[pre_index]+=2;
					vi[pre_index]=vi[pre_index]+vi[pre_index+1];
					vi[pre_index+1]=0;
				}
			}
		}else{
			pre_sign.push(s[i]);
		}
	}
	int vmax=0;
	for (int k=0;k<=pre_index;k++)
	{
		if(vi[k]>vmax)	vmax=vi[k];
	}
	return vmax>max_len?vmax:max_len;
 }

bool search(int A[], int n, int target) {
	if(n==0)	return false;
	int l=0;
	int r=n-1;
	while (l<=r)
	{
		int m=(l+r)/2;
		if(A[m]==target)	return true;
		if(A[m]>A[l])
		{
			if (A[m]>target&&A[l]<=target)	r=m-1;
			else							l=m+1;
		}else if (A[m]<A[l])
		{
			if (A[m]<target&&A[r]>=target)	l=m+1;
			else							r=m-1;
		}else
			l++;
	}
	return false;
  }


bool isValid(vector<vector<char> > &board, int x,int y){  
	int temp = board[x][y];  
	for(int i=0;i<9;i++){  
		if(i!=x && board[i][y]==temp){  
			return false;  
		}  
	}  
	for(int j=0;j<9;j++){  
		if(j!=y && board[x][j]==temp){  
			return false;  
		}  
	}  
	
	for( i=0;i<3;i++){  
		for(int j=0;j<3;j++){  
			int tempx = 3*(x/3)+i;  
			int tempy = 3*(y/3)+j;  
			if (tempx != x && tempy != y && board[tempx][tempy] == temp)    
				return false;    
		}  
	}   
	
	return true;    
}  

bool dfs(vector<vector<char> > &board){  
	for(int i=0;i<9;i++){  
		for(int j=0;j<9;j++){  
			if(board[i][j]=='.'){  
				for(int k=0;k<9;k++){  
					board[i][j]=(char)(k+'1');  
					if(isValid(board,i,j)&&dfs(board)){  
						return true;  
					}  
					board[i][j]='.';  
				}  
				return false;  
			}  
		}  
	}  
	return true; 
}
void solveSudoku(vector<vector<char> > &board) {
	dfs(board);  
  }

bool isValidSudoku(vector<vector<char> > &board) {
	unsigned char sudo_table[9]={0};
	int all_num[9][9]={0};
	
	int colum=board.size();
	if (colum!=9)	return false;
	int c;
	int r;
	for (c=0;c<colum;c++)
	{
		vector<char> vc=board.at(c);
		int vcsz=vc.size();
		if (vcsz!=9)	return false;
		for (r=0;r<vcsz;r++)
		{
			char cnum=vc.at(r);
			if(cnum=='.')	all_num[c][r]=0;
			else			all_num[c][r]=cnum-'0';
		}
	}
	
	for (c=0;c<9;c++)
	{
		memset(sudo_table,0,9);
		for (r=0;r<9;r++)
		{
			int num=all_num[c][r];
			if (num>0)
			{
				sudo_table[num-1]++;
				if (sudo_table[num-1]>1)	return false;
			}
		}
	}
	
	for (r=0;r<9;r++)
	{
		memset(sudo_table,0,9);
		for (c=0;c<9;c++)
		{
			int num=all_num[c][r];
			if (num>0)
			{
				sudo_table[num-1]++;
				if (sudo_table[num-1]>1)	return false;
			}
		}
	}
	
	for (r=0;r<3;r++)
	{
		for (c=0;c<3;c++)
		{
			int rr=0+3*r;
			int cc=0+3*c;
			memset(sudo_table,0,9);
			for (int one=0;one<3;one++)
			{
				for (int two=0;two<3;two++)
				{
					int num=all_num[rr+one][cc+two];
					if (num>0)
					{
						sudo_table[num-1]++;
						if (sudo_table[num-1]>1)	return false;
					}
				}
			}
		}
	}
	return true;
  }
string countAndSay(int n) {
	if (n==1)	return "1";
	string reslut;
	string src="1";
	int ct=0;
	while (--n)
	{
		ct=1;
		reslut="";
		for (int i=1;i<src.length();i++)
		{
			if (src[i]==src[i-1])
			{
				ct++;
			}else
			{
				reslut+= ct+'0';
				reslut+=src[i-1];
				ct=1;
			}	
		}
		reslut+=ct+'0';
		reslut+=src[i-1];
		src=reslut;	
	}
	return reslut;
 }

vector<vector<int> > result; 
vector<int> res;

void dfs2(vector<int>& candidates, int target, int start) {
	if (target <= 0) {
		if(target == 0){
			result.push_back(res);
		}
		return;
	}
	for (int i = start; i < candidates.size(); i++) {
		res.push_back(candidates[i]); 
		dfs2(candidates, target - candidates[i], i+1);
		res.pop_back();
		while(i <candidates.size()-1&& candidates[i] == candidates[i+1])
			i++;
	}
   }

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
	sort(num.begin(), num.end());
	dfs2(num, target, 0);
	return result;
    }

void dfs(vector<int>& candidates, int target, int start) {
	if (target <= 0) {
		if(target == 0){
			result.push_back(res);
		}
		return;
	}
	for (int i = start; i < candidates.size(); i++) {
		res.push_back(candidates[i]); 
		dfs(candidates, target - candidates[i], i);
		res.pop_back();
	}
}
vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	sort(candidates.begin(), candidates.end());
	dfs(candidates, target, 0);
	return result;
    }

int firstMissingPositive(int A[], int n) {
	for (int i = 0; i < n; )  
	{  
		if (0<A[i]&& A[i]<n && A[i] != i && A[A[i]] != A[i])   
			swap(A[i], A[A[i]]);  
		else i++;  
	}  
	for (i = 1; i < n; i++)   
		if (A[i] != i) return i;  
		
		return A[0] == n? n+1:n;
}

int trap(int A[], int n) {
	if (n<=2)	return 0;
	int perfect_index=0;
	int cur_height=0;
	int i;
	for (i=0;i<n;i++)
	{
		if (A[i]>cur_height)
		{
			perfect_index=i;
			cur_height=A[i];
		}
	}
	int cur_area=0;
	cur_height=0;
	for (i=0;i<perfect_index;i++)
	{
		if (A[i]>=cur_height)	cur_height=A[i];
		else	cur_area+=cur_height-A[i];	
	}
	
	cur_height=0;
	for (i=n-1;i>perfect_index;i--)
	{
		if (A[i]>=cur_height)	cur_height=A[i];
		else	cur_area+=cur_height-A[i];
	}
	
	return cur_area;
} 

string multiply(string num1, string num2) {
	int len1=num1.size();
	int len2=num2.size();
	
	int limit_sz=len1+len2-2;
	
	vector<int> tmp_vi(len1+len2,0);
	for (int i=0;i<len1;i++)
	{
		for (int j=0;j<len2;j++)
		{
			tmp_vi[limit_sz-i-j]+=(num1[i]-'0')*(num2[j]-'0');
		}
	}
	
	int gostep=0;
	for (int a=0;a<limit_sz+2;a++)
	{
		tmp_vi[a]+=gostep;
		gostep=tmp_vi[a]/10;
		tmp_vi[a]%=10;
	}
	
	int b=limit_sz+1;
	while(tmp_vi[b]==0)	b--;
	if(b<0)	return "0";
	string rs;
	while(b>=0)
	{
		rs+=tmp_vi[b]+'0';
		b--;
	}
	return rs;
}

int jump(int A[], int n) {
	int ct=0;
	int end=n-1;
	for (int i=0;i<end;i++)
	{
		ct++;
		int cv=A[i];
		if (cv==0)	return -1;
		if (cv==1)	continue;
		if (i+cv>=end)	return ct;
		int max_index=i;
		int cur_len=i+cv;
		for (int j=i+1;j<=i+cv;j++)
		{
			int ccv=j+A[j];
			if (ccv>=end)	return ct+1;
			if (ccv>cur_len)
			{
				cur_len=ccv;
				max_index=j;
			}
		}
		if(max_index==i) i+=cv-1;
		else			 i=max_index-1;
	}
	return ct;
  }

void dfs(int k,int n,vector<int> &num){  
	if(k>n){  
		result.push_back(num);  
		return;  
	}else
	{
		for(int i=k;i<=n;i++){  
			int tv;
			tv=num[k];
			num[k]=num[i];
			num[i]=tv;
			dfs(k+1,n,num);  
			tv=num[k];
			num[k]=num[i];
			num[i]=tv; 
		}
	}  
}  
vector<vector<int> > permute(vector<int> &num) {
	dfs(0,num.size()-1,num);  
    return result;  	
}

vector<vector<int> > rs;

void permuteUnique(vector<int> &num,vector<int>& out,vector<bool>& visited)
{
	if (out.size()==num.size())
	{
		rs.push_back(out);
		return ;
	}
	for (int i=0;i<num.size();i++)
	{
		if (!visited[i])
		{
			visited[i]=true;
			out.push_back(num[i]);
			permuteUnique(num,out,visited);
			out.pop_back();
			visited[i]=false;;
			for (int curi=i;i<num.size()&&num[i]==num[curi];i++);
			i--;
		}
	}
}

vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<int> out;
    vector<bool> visited(num.size());
	sort(num.begin(),num.end());
	permuteUnique(num,out,visited);
	return rs;
}

void rotate(vector<vector<int> > &matrix) {
	vector<vector<int> > tmp_mtx;
	vector<int>			 tmp_vi;
	int sn=matrix.size();
	for (int i=0;i<sn;i++)
	{
		for (int j=0;j<sn;j++)
		{
			vector<int> tvi=matrix[(sn-j-1)];
			tmp_vi.push_back(tvi[i]);
			printf("row:%d tvi:%d\n",sn-j-1,tvi[i]);
		}
		tmp_mtx.push_back(tmp_vi);
		tmp_vi.clear();
	}
	for (int k=0;k<sn;k++)
	{
		matrix[k]=tmp_mtx[k];
	}
}


vector<vector<string> > qres;

bool isValid(vector<int> &state, int row, int col)
{
	for(int i = 0; i < row; i++)
		if(state[i] == col || abs(row - i) == abs(col - state[i]))
			return false;
        return true;
}
void helper(vector<int> &state, int row)
{//放置第row行的皇后
	int n = state.size();
	if(row == n)
	{
		vector<string>tmpres(n, string(n,'.'));
		for(int i = 0; i < n; i++)
			tmpres[i][state[i]] = 'Q';
		qres.push_back(tmpres);
		return;
	}
	for(int col = 0; col < n; col++)
		if(isValid(state, row, col))
		{
			state[row] = col;
			helper(state, row+1);
			state[row] = -1;;
		}
}

vector<vector<string> > solveNQueens(int n) {
	vector<int> state(n, -1);
	helper(state, 0);
	return qres;
   }

int maxSubArray(int A[], int n) {
	if(n<=0)	return 0;
	int maxv=A[0];
	int curv=0;
	for (int i=0;i<n;i++)
	{
		curv+=A[i];
		if (curv>maxv)	maxv=curv;
		if (curv<=0) curv=0;
	}
	return maxv;
    }

vector<int> spiralOrder(vector<vector<int> > &matrix) {
	vector<int> rvi;
	int m=matrix.size();
	if (m<=0)	return rvi;
	vector<int> r0=matrix.at(0);
	int n=r0.size();
	
	int cr=m;
	int cc=n;
	int cx=0;
	int cy=0;
	int direct=1;
	int i;
	while (cr&&cc)
	{
		if (direct==5)	direct=1;
		if (direct==1)
		{
			for (i=0;i<cc;i++)
				rvi.push_back(matrix[cx][cy+i]);
			cy+=cc-1;
			cx++;
			
			cr--;
			direct++;
			continue;
		}
		if (direct==2)
		{
			for (i=0;i<cr;i++)
				rvi.push_back(matrix[cx+i][cy]);
			cx+=cr-1;
			cy--;
			cc--;
			direct++;
			continue;
		}
		if (direct==3)
		{
			for (i=0;i<cc;i++)
				rvi.push_back(matrix[cx][cy-i]);
			cy-=cc-1;
			cx--;
			
			cr--;
			direct++;
			continue;
		}
		if (direct==4)
		{
			for (i=0;i<cr;i++)
				rvi.push_back(matrix[cx-i][cy]);
			cx-=cr-1;
			cy++;
			cc--;
			direct++;
			continue;
		}
	}
	return rvi;
 }


static bool compareInterval( Interval v1, Interval v2) 
{  
    return v1.start < v2.start; 
} 

vector<Interval> merge(vector<Interval> &intervals) {
	vector<Interval> rsi;
	sort(intervals.begin(),intervals.end(),compareInterval);  
	if(intervals.empty())      return intervals;
	rsi.push_back(intervals[0]);
	for (int i=1;i<intervals.size();i++)
	{
		Interval& bi=rsi.back();
		if(intervals[i].start>bi.end)	rsi.push_back(intervals[i]);
		else if(intervals[i].end>bi.end)	bi.end=intervals[i].end;
	}
	return rsi;
  }

vector<Interval> insert(vector<Interval> &v, Interval nv) {
    vector<Interval> rs;  
	int i = 0;  
	while(i < v.size() && v[i].end < nv.start)  
	{  
		rs.push_back(v[i++]);
	}  
	if (i == v.size())  
	{  
		rs.push_back(nv);  
		return rs;  
	}  
	if(v[i].start<nv.start)  nv.start=v[i].start;
	
	while(i < v.size() && v[i].start <= nv.end)  
	{  
		if(v[i].end>nv.end)   nv.end=v[i].end;
		i++;
	}  
	rs.push_back(nv);  
	
	while(i < v.size())  
	{  
		rs.push_back(v[i++]);
	}  
	return rs; 
}

int lengthOfLastWord(const char *s) {
	
	int len=strlen(s);
	int index1=len-1;
	while (index1>=0&&s[index1]==' ')	index1--;
	int index2=index1;
	while (index2>=0&&s[index2]!=' ')     index2--;
	return index1-index2;
   }

vector<vector<int> > generateMatrix(int n) {
   	vector<vector<int> > rst(n,vector<int>(n,0));
	int cr=n;
	int cc=n;
	int cx=0;
	int cy=0;
	int direct=1;
	int i;
	int cv=1;
	while (cr&&cc)
	{
		if (direct==5)	direct=1;
		if (direct==1)
		{
			for (i=0;i<cc;i++)
				rst[cx][cy+i]=cv++;
			cy+=cc-1;
			cx++;
			
			cr--;
			direct++;
			continue;	
		}
		if (direct==2)
		{
			for (i=0;i<cr;i++)
				rst[cx+i][cy]=cv++;
			cx+=cr-1;
			cy--;
			cc--;
			direct++;
			continue;
		}
		if (direct==3)
		{
			for (i=0;i<cc;i++)
				rst[cx][cy-i]=cv++;
			cy-=cc-1;
			cx--;
			
			cr--;
			direct++;
			continue;
		}
		if (direct==4)
		{
			for (i=0;i<cr;i++)
				rst[cx-i][cy]=cv++;
			cx-=cr-1;
			cy++;
			cc--;
			direct++;
			continue;
		}
	}
	
	return rst;
  }

string rs_p;
int pct=0;

void PermutationHelper(int a[],int l,int right,int k)
{
	if (l==right)
	{
		pct++;
		if (pct==k)
		{
			for (int i=0;i<right;i++)
			{
				rs_p+=a[i]+'0';
			}
		}
		return ;
	}
	
	for (int j=l;j<right;j++)
	{
		swap(a[l],a[j]);
		PermutationHelper(a,l+1,right,k);
		swap(a[l],a[j]);
	}
}

string getPermutation(int n, int k) {
	int A[10]={0};
	for (int i=0;i<n;i++)
		A[i]=i+1;
	PermutationHelper(A,0,n,k);
	return rs_p;
  }

string getPermutationEx(int n, int k) {
	int A[10]={0};
	int basenum=1;
	for (int i=0;i<n;i++)
	{
		A[i]=i+1;
		basenum*=(i+1);
	}
	k--;
	string rs;
	for(i = 0; i < n; ++i)
	{
		basenum = basenum/(n-i);
		int choosed = k/basenum;
		rs+=A[choosed]+'0';
		
		for(int j = choosed; j < n-i;++j)//delete the deleted one
			A[j] = A[j+1];
		k = k%basenum;
	}
	return rs;
  }


ListNode *rotateRight(ListNode *head, int k) {
	if (head==NULL)	return NULL;
	int len=0;
	ListNode* p_head=head;
	ListNode* p_tail=head;
	while (p_head)
	{
		len++;
		p_tail=p_head;
		p_head=p_head->next;
	}
	ListNode* p_k=head;
	k%=len;
	k=len-k;
	while(--k)	p_k=p_k->next;
	ListNode* p_knext=p_k->next;
	if(p_knext==NULL) return head;
	p_tail->next=head;
	p_k->next=NULL;
	return p_knext;
 }

int uniquePaths(int m, int n) {
	   vector<vector<int> > table(m, vector<int>(n, 1));  
	   for (int i = 1; i < m; i++)  
	   {  
		   for (int j = 1; j < n; j++)  
		   {  
			   table[i][j] = table[i-1][j] + table[i][j-1];  
		   }  
	   }  
	   return table[m-1][n-1];  
  }

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	const int m = obstacleGrid.size();
	const int n = obstacleGrid[0].size();
	if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
	vector<int> f(n, 0);
	f[0] = obstacleGrid[0][0] ? 0 : 1;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			f[j] = obstacleGrid[i][j] ? 0 : (j == 0 ? 0 : f[j - 1]) + f[j];
		
		return f[n - 1];
}

int minPathSum(vector<vector<int> > &grid) {
	const int m = grid.size();
	const int n = grid[0].size();
	
	int k;
	for(k=1;k<m;k++){
		grid[k][0] += grid[k-1][0];
	}
	for(k=1;k<n;k++){
		grid[0][k] += grid[0][k-1];
	}
	int top,left,val;
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			top = grid[i-1][j];
			left = grid[i][j-1];
			val = top>left?left:top;
			grid[i][j]+=val;
		}
	}
    return grid[m-1][n-1];
  }

vector<int> plusOne(vector<int> &digits) {
	
	int sz=digits.size();
	int flag=0;
	for (int i=sz-1;i>=0;i--)
	{
		int cv;
		if (i==sz-1)	cv=1+digits[i]+flag;
		else			cv=digits[i]+flag;	
		digits[i]=cv%10;
		flag=cv/10;
		if(flag==0) break;
	}
	if (flag==1)
	{
		vector<int> rst(sz,0);
		rst[0]=1;
		return rst;
	}
	return digits;
 }

string addBinary(string a, string b) {
	
	int len1=a.size();
	int len2=b.size();
	int flag=0;
	
	int i;
	int j;
	string frs;
	if (len1>=len2)
	{
		int diff=len1-len2;
		string rs(len1+1,'0');
		for (i=len1-1;i>=0;i--)
		{
			int cv;
			if (i-diff>=0)	cv=(a[i]-'0')+(b[i-diff]-'0')+flag;
			else			cv=(a[i]-'0')+flag;
			rs[i]='0'+cv%2;
			flag=cv/2;
		}
		if (flag==1)			frs+='1';
		for (i=0;i<len1;i++)	frs+=rs[i];
	}else
	{
		int diff=len2-len1;
		string rs(len2+1,'0');
		for (i=len2-1;i>=0;i--)
		{
			int cv;
			if (i-diff>=0)	cv=(b[i]-'0')+(a[i-diff]-'0')+flag;
			else			cv=(b[i]-'0')+flag;
			rs[i]='0'+cv%2;
			flag=cv/2;
		}
		if (flag==1)			frs+='1';
		for (i=0;i<len2;i++)	frs+=rs[i];
	}
	return frs;
 }


bool isNumber(const char *s) {
	if (s == NULL || s[0] ==0) return false;
	bool cansign = true;
	bool cane = false;
	bool havee = false;
	bool candot = true;
	bool onlyspace = false;
	bool havenum = false;
	bool numbegin = false;
	while(*s != 0) {
		char c = *(s++);
		if (c == ' '){
			if (numbegin)
				onlyspace = true;
			continue;//skip space
		} else if (onlyspace) {
			return false;
		}
		if (c == '+' || c == '-') {
			if(!cansign) return false;
			cansign = false;
			numbegin = true;
			continue;
		}
		if (c == 'e') {
			if(!cane) return false;
			cane = false;
			havenum = false;
			numbegin = true;
			cansign = true;
			havee = true;
			candot = false;
			continue;
		}
		if (c == '.') {
			if(!candot) return false;
			candot = false;
			numbegin = true;
			cansign = false;
			continue;
		}
		if (c >= '0' && c <= '9') {
			havenum = true;
			numbegin = true;
			cansign = false;
			if(!havee) cane = true;
		} else {
			return false;
		}
	}
	return havenum;
 }

void addSpace(string &s, int count)
{
	for(int i = 1; i <= count; i++)
		s+=' ';
}

vector<string> fullJustify(vector<string> &words, int L) {
	vector<string>res;
	int len = words.size(), i = 0;
	while(i < len)
	{
		int rowlen = 0, j = i;
		while(j < len && rowlen + words[j].size() <= L)
			rowlen += (words[j++].size() + 1);
		//j-i是该行放入单词的数目
		if(j - i == 1)
		{//处理放入一个单词的特殊情况
			res.push_back(words[i]);
			addSpace(res.back(), L - words[i].size());
			i = j; continue;
		}
		//charaLen是当前行字母总长度
		int charaLen = rowlen - (j - i);
		//平均每个单词后的空格,j < len 表示不是最后一行
		int meanSpace = j < len ? (L - charaLen) / (j - i - 1) : 1;
		//多余的空格
		int leftSpace = j < len ? (L - charaLen) % (j - i - 1) : L - charaLen - (j - i -1);
		string tmp;
		for(int k = i; k < j - 1; k++)
		{
			tmp += words[k];
			addSpace(tmp, meanSpace);
			if(j < len && leftSpace > 0)
			{
				tmp+=' ';
				leftSpace--;
			}
		}
		tmp += words[j - 1];//放入最后一个单词
		if(leftSpace > 0)	addSpace(tmp, leftSpace); //对最后一行
		res.push_back(tmp);
		i = j;
	}
	return res;
}

int climbStairs(int n) {
	
	if (n<=0)	return 0;
	if (n==1)	return 1;
	if (n==2)   return 2;
	return  climbStairs(n-1)+climbStairs(n-2);
}

int climbStairs2(int n) {
	if (n<=0)	return 0;
	if (n==1)	return 1;
	if (n==2)   return 2;
	
	int a[3];
	a[0]=1;
	a[1]=2;
	for (int i=2;i<n;i++)
	{	
		a[2]=a[0]+a[1];
		a[0]=a[1];
		a[1]=a[2];
	}
	return a[2];
 }


string simplifyPath(string path)
{
	string ans,now;  
	vector<string> list;  
	stringstream ss(path); 
	int sz=path.size();
	int i;
	for (i=0;i<sz;i++)
	{  
		if(path[i]!='/')
		{
			now+=path[i];	continue;
		}
		if(now.length()==0 || now==".")  
		{
			now="";continue;  
		}
		if(now=="..")  
		{  
			if(!list.empty())  list.pop_back();  
		}else  
			list.push_back(now);  
		now="";
	}  
	if (!now.empty()){
		if(now=="..")  
		{  
			if(!list.empty())  list.pop_back();  
		}else  
			list.push_back(now);  
	}
	for(i=0; i<list.size(); i++)  
	{  
		if(list[i]==".") continue;
		ans += "/";  
		ans += list[i];  
	}  
	if(ans.length()==0) ans = "/";    
	return ans;   
}
int mymin(int x,int y)
{
	return x<y?x:y;
}
int mymax(int x,int y)
{
	return x>y?x:y;
}
int minDistance(string word1, string word2) {
	int row=word1.size()+1;
	int col=word2.size()+1;
	
	vector<vector<int> > dp(row,vector<int>(col));
	int i,j;
	for (i=0;i<row;i++)
		dp[i][0]=i;
	
	for (i=0;i<col;i++)
		dp[0][i]=i;
	
	for (i=1;i<row;i++)
	{
		for (j=1;j<col;j++)
		{
			if (word1[i-1]==word2[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}else
				dp[i][j]=dp[i-1][j-1]+1;
			dp[i][j]=mymin(dp[i][j],mymin(dp[i-1][j]+1,dp[i][j-1]+1));
		}
	}
	
	return dp[row-1][col-1];
}

void setZeroes(vector<vector<int> > &matrix) {
	
	int row=matrix.size();
	if (row<=0)	return ;
	vector<int> c0=matrix[0];
	int col=c0.size();
	if (col<=0)	return;
	
	vector<bool> mark_row(row,false);
	vector<bool> mark_col(col,false);
	int i,j;
	for (i=0;i<row;i++)
		for (j=0;j<col;j++)
			if (matrix[i][j]==0)
			{
				mark_row[i]=true;
				mark_col[j]=true;
			}
			
			for (i=0;i<row;i++)
				if (mark_row[i])
					for (j=0;j<col;j++)
						matrix[i][j]=0;
					
					for (i=0;i<col;i++)
						if (mark_col[i])
							for (j=0;j<row;j++)
								matrix[j][i]=0;
}

bool searchMatrix(vector<vector<int> > &matrix, int target) {
	
    int row=matrix.size();
	if(row<=0)	return false;
	vector<int> c0=matrix[0]; 
	int col=c0.size();
	if(col<=0)	return false;
	int total=row*col;
	
	int left=0;
	int right=total-1;
	int mid_v;
	while (left<=right)
	{
		int mid=left+(right-left)/2;
		mid_v=matrix[mid/col][mid%col];
		if (mid_v==target)		return true;
		if (mid_v<target)		left=mid+1;
		else					right=mid-1;
	}
	return false;
    }

void sortColors(int A[], int n) {
	
	if (n<=0)	return;
	int front_index=0;
	int tail_index=n-1;
	int i=0;
	for (i=0;i<n;i++)
	{
		if(A[i]==0)	front_index++;
		if(A[i]==2) tail_index--;
	}
	
	for (i=0; i<front_index;i++)
		A[i]=0;
	for (i=front_index; i<=tail_index;i++)
		A[i]=1;
	for (i=tail_index+1; i<=n-1;i++)
		A[i]=2;
  }

string minWindow(string S, string T) {
	if(S.empty()||T.empty()||S.length()<T.length()) return "";
	vector<int> cnt1(256,0);
	vector<int> cnt2(256,0);
	int cnt=0;
	int pos=0;
	int minlen=S.length();
	int minpos=-1;
	int i;
	for(i=0;i<T.length();i++)
		cnt1[T[i]-'0']++;
    
	for(i=0;i<S.length();i++)
	{
		if(cnt1[S[i]-'0'])
		{
			cnt2[S[i]-'0']++;
			if(cnt1[S[i]-'0']>=cnt2[S[i]-'0'])	cnt++;
		}
		if(T.length()==cnt)
		{
			while(pos<=i)
			{
				if(cnt1[S[pos]-'0'])
				{
					if(cnt1[S[pos]-'0']<cnt2[S[pos]-'0']) cnt2[S[pos]-'0']--;
					else break;
				}
				pos++;
			}
			if(i-pos+1<=minlen) minlen=i-pos+1,minpos=pos;
		}
	}
    return -1!=minpos?S.substr(minpos,minlen):"";
}

void  combineHelper(int l,int k,int n,vector<vector<int> > &rst,vector<int> &vi)
{
	if (vi.size()==k)
	{
		rst.push_back(vi);
		return ;
	}
	for (int i=l;i<=n;i++)
	{
		vi.push_back(i);
		if (vi.size() == k)  
		{  
			rst.push_back(vi);  
			vi.pop_back();  
			continue;  
		}  
		combineHelper(i+1,k,n,rst,vi);
		vi.pop_back();
	}
}

vector<vector<int> > combine(int n, int k) {
	vector<vector<int> > _rst;
	vector<int> tmp;
	combineHelper(1,k,n,_rst,tmp);
	return _rst;
 }
 void dfs(vector<int> &S, int iend, vector<int> &tmpres,vector<vector<int> > &res)
{
         if(iend == S.size())
             {res.push_back(tmpres); return;}
         //选择S[iend]
         tmpres.push_back(S[iend]);
         dfs(S, iend+1, tmpres,res);
         tmpres.pop_back();
         //不选择S[iend]
         dfs(S, iend+1, tmpres,res);
 }

vector<vector<int> > subsets(vector<int> &S) {
       vector<vector<int> > res;
       sort(S.begin(), S.end());
       vector<int>tmpres;
       dfs(S, 0, tmpres,res);
       return res;
 }

vector<vector<int> > subsets2(vector<int> &S) {
	int len = S.size();
	sort(S.begin(), S.end());
	vector<vector<int> > res(1);//开始加入一个空集
	for(int i = 0; i < len; ++i)
	{
		int resSize = res.size();
		for(int j = 0; j< resSize; j++)
		{
			res.push_back(res[j]);
			res.back().push_back(S[i]);
		}
	}
	return res;
    }

bool existHelper(vector<vector<char> > &board, string word, int index,int x, int y, vector<vector<bool> >& visited)
{
	if(index == word.size())    
		return true;
	vector<char> vc=board[0];
	if(x < 0 || y < 0 || x >= board.size() || y >= vc.size()) //不可越界
		return false;
	if(visited[x][y]) //如果之前访问过，那么直接返回false
		return false;
	if(board[x][y] != word[index]) //不相等，这条路走不通，剪枝
		return false;
	visited[x][y] = true; //先标记为走过，因为下一次会走向四个方向
	bool ret =	existHelper(board, word, index + 1, x, y + 1, visited)||
		existHelper(board, word, index + 1, x, y - 1, visited)||
		existHelper(board, word, index + 1, x - 1, y, visited)|| 
		existHelper(board, word, index + 1, x + 1, y, visited); 
	visited[x][y] = false;  //走过之后，不过不匹配，要还原为没有走过
    return ret;
}

bool exist(vector<vector<char> > &board, string word) {
	const int m = board.size();
	vector<char> vc=board[0];
	const int n = vc.size();
	vector<vector<bool> > visited(m, vector<bool>(n, false));//将访问标记数组置空
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(existHelper(board, word, 0, i, j, visited))//单词可在任意位置开始匹配
				return true;                      //只要有一个位置完全匹配即匹配
			return false;
}

int removeDuplicates(int A[], int n) {
	if (n==0)	return 0;
	int diff=0;
	int ct=1;
	int index=1;
	for (int i=1;i<n;i++)
	{
		if (A[i]==A[i-1])
		{
			if (++ct>=3)	continue;
		}else
			ct=1;
		A[index++]=A[i];
	}
	return index;
 }

ListNode *deleteDuplicates(ListNode *head) {
	if (head==NULL)	return	head;
	ListNode* p1=head;
	ListNode* p2=NULL;
	if (p1->next)	p2=p1->next;
	else			return  head;
	while (p2)
	{
		ListNode* next=p2->next;
		if (p1->val==p2->val)
		{
			p1->next=next;
			p2=next;
		}else
		{
			p1=p2;
			p2=next;
		}
	}
	return head;
	
    }

ListNode *deleteDuplicates2(ListNode *head) {
	
   	if (head==NULL)	return head;
	ListNode* pHead=head;
	ListNode* pPre=NULL;
	bool isnull=true;
	
	ListNode* p1=head;
	ListNode* p2=p1->next;
	while(p2)
	{
		if(p2->val==p1->val)
		{
			while (p2&&p2->val==p1->val)
			{
				p2=p2->next;
			}
			if(p2)
			{
				if(pPre)	pPre->next=p2;
				p1=p2;
				p2=p2->next;
			}else
			{
				if(pPre)	pPre->next=NULL;
				else		return NULL;
			}
		}else
		{
			pPre=p1;
			if(isnull)
			{
				isnull=false;
				pHead=pPre;
			}
			p1=p2;
			p2=p2->next;
		}
		
	}
	if (pPre==NULL)	return p1;
	return pHead;
    }


int largestRectangleArea(vector<int> &height) {
	
	stack<int>	ascend_index;
	int maxArea=0;
	height.push_back(0);
	int i=0;
	while (i<height.size())
	{
		if (ascend_index.empty())
		{
			ascend_index.push(i++);
			continue;
		}
		int bi=ascend_index.top();
		if (height[i]>=height[bi])
		{
			ascend_index.push(i++);
		}else
		{
			ascend_index.pop();
			
			int cur_area=0;
			if (ascend_index.empty())
			{
				cur_area=height[i]*i;
			}else
				cur_area=height[bi]*(i-ascend_index.top()-1);
			
			if(cur_area>maxArea)	maxArea=cur_area;
		}
	}
	return maxArea;
}

int maximalRectangle(vector<vector<char> > &matrix) {
	int i,j,row,col,max_rc=0; 
	row=matrix.size();  
	if(row==0)	return 0;
	col=matrix[0].size();
	if(col==0)	return 0;
	vector<vector<int> > height(row+1,vector<int>(col+1,0)); 
	for(j=0;j<col;++j)  
		for(i=0;i<row;++i) 
			if(matrix[i][j]=='0')	height[i][j]=0;
			else if(i==0)			height[0][j]=1;
			else					height[i][j]=height[i-1][j]+1; 
			
			stack<int>s;
			for(i=0;i<row;++i)  
			{  
				for(j=0;j<col;++j)  
				{  
					if(s.empty())	s.push(j);
					else  
					{  
						while(!s.empty()&&height[i][s.top()]>height[i][j])  
						{  
							int ci=s.top();  
							s.pop();
							int cv;
							if(s.empty())	cv=height[i][ci]*j;
							else			cv=height[i][ci]*(j-s.top()-1);
							if (cv>max_rc)	max_rc=cv;
						}
						s.push(j);
					}
				}  
				while(!s.empty())  
				{  
					int ci=s.top();  
					s.pop();  
					int cv;
					if(s.empty())  cv=height[i][ci]*col;  
					else		   cv=height[i][ci]*(col-s.top()-1);   
					if(cv>max_rc)	max_rc=cv;
				}
			}
			return max_rc;
}


ListNode *partition(ListNode *head, int x) {
	
    ListNode *head1,*head2,*p1,*p2;  
    head1=new ListNode(0);  
    head2=new ListNode(0); 
	p1=head1;  
    p2=head2;
	while(head)
	{
		if(head->val<x)  
		{  
			p1->next=new ListNode(head->val);  
			p1=p1->next;                  
        }else   
		{  
			p2->next=new ListNode(head->val);  
			p2=p2->next;  
        } 
		head=head->next;
	}
	if(head2->next!=NULL)	p1->next=head2->next;  
	delete(head1);  
    delete(head2);
	return head1->next;
 }

bool isScrambleHelper(string &s1, string &s2)
{         
	string tmps1= s1, tmps2 = s2;
	sort(tmps1.begin(), tmps1.end());
	sort(tmps2.begin(), tmps2.end());
	if(tmps1!= tmps2)	return false;//两个字符串所含字母不同
	if(s1 == s2)		return true;
	
	int len = s1.size();
	for(int i = 1; i < len; i++)//分割位置
	{
		string s1left = s1.substr(0, i);
		string s1right = s1.substr(i);
		string s2left = s2.substr(0, i);
		string s2right = s2.substr(i);
		if(isScrambleHelper(s1left, s2left) && isScrambleHelper(s1right, s2right))
			return true;
		s2left = s2.substr(0, len-i);
		s2right = s2.substr(len-i);
		if(isScrambleHelper(s1left, s2right) && isScrambleHelper(s1right, s2left))
			return true;
	}
	return false;
}

bool isScramble(string s1, string s2) {
	return isScrambleHelper(s1,s2);
    }

void merge(int A[], int m, int B[], int n) {
	int index1=0;
	int index2=0;
	int tmp_index=0;
	int* tmpA=(int*)malloc(sizeof(int)*(m+n+1));
	
	while (index1!=m&&index2!=n)
	{
		if (A[index1]<B[index2])	tmpA[tmp_index++]=A[index1++];
		else						tmpA[tmp_index++]=B[index2++];
	}
	while(index1!=m)				tmpA[tmp_index++]=A[index1++];
	while(index2!=n)				tmpA[tmp_index++]=B[index2++];
	index1=0;
	index2=m+n;
	while(index2--)					A[index1]=tmpA[index1++];
	free(tmpA);
   }

vector<int> grayCode(int n) {
	int num = 1<<n;
	vector<int> res;
	res.reserve(num);
	for(int i = 0; i < num; i++)
		res.push_back(i^(i>>1));
	return res;
    }

int numDecodings(string s) {
	int size = s.length();
	if(size == 0 || s[0] == '0') return 0;
	vector<int> res(size+1, 0);
	res[0] = 1; res[1] = 1;
	for(int i=2; i<=size; i++) {
		if((s[i-2] == '0' || s[i-2] > '2') && s[i-1] == '0') return 0;
		if((s[i-2] == '2' || s[i-2] == '1') && s[i-1] == '0') {
			res[i] = res[i-2];
		}
		else if((s[i-2] == '1') || (s[i-2] == '2' && s[i-1] >= '1' && s[i-1] <= '6')) {
			res[i] = res[i-1] + res[i-2];
		}
		else {
			res[i] = res[i-1];
		}
	}
	return res[size];
   }

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    int len = S.size();
	sort(S.begin(), S.end());
	vector<vector<int> > res(1);//开始加入一个空集
	int si=0;
	for(int i = 0; i < len; ++i)
	{
		int resSize = res.size();
		for(int j = si; j< resSize; j++)
		{
			res.push_back(res[j]);
			res.back().push_back(S[i]);
		}
		if(i+1<len && S[i]==S[i+1])  si = resSize;  
        else  si = 0;   
	}
	return res;
    }

ListNode *reverseBetween(ListNode *head, int m, int n) {
	
	if(m>=n)	return	head;
	ListNode* pm;
	ListNode* pn;
	
	ListNode* phead=head;
	ListNode* pcur=head;
	
	ListNode* pre_pm=NULL;
	ListNode* pre_pn=NULL;
	
	int i=0;
	for (i=0;i<n;i++)
	{
		if(i==m-2)	pre_pm=pcur;
		if(i==m-1)	pm=pcur;
		if(i==n-2)	pre_pn=pcur;
		if(i==n-1)	pn=pcur;
		pcur=pcur->next;
	}
	
	ListNode* next_pn=pn->next;
	ListNode* p2=NULL;
	ListNode* save_pm1=pm;
	ListNode* pm1=pm;
	pm=pm->next;
	while(pm!=pn)
	{
		p2=pm->next;
		pm->next=pm1;
		pm1=pm;
		pm=p2;
	}
	pm->next=pm1;
	save_pm1->next=next_pn;
	if(pre_pm) pre_pm->next=pm;
	else			 return pm;
	
	return phead;
}

void dfs_ip(string s, size_t start, size_t step, string ip,vector<string> &result) {
	if (start == s.size() && step == 4) {  // 找到一个合法解
		ip.resize(ip.size() - 1);
		result.push_back(ip);
		return;
	}	
	if (s.size() - start > (4 - step) * 3)	return;  // 剪枝
	if (s.size() - start < (4 - step))		return;  // 剪枝	
	int num = 0;
	for (size_t i = start; i < start + 3; i++)
	{
		num = num * 10 + (s[i] - '0');
		if (num <= 255) 
		{  // 当前结点合法，则继续往下递归
			ip += s[i];
			dfs_ip(s, i + 1, step + 1, ip + '.', result);
		}
		if (num == 0) break;  // 不允许前缀0，但允许单个0			
	}
}
vector<string> restoreIpAddresses(string s) {
	vector<string> result;
	string ip; // 存放中间结果
	dfs_ip(s, 0, 0, ip, result);
	return result;
}

void inorderTraversalHelper(TreeNode *root,vector<int> &tvi)
{
	if (root->val!='#'-'0')
	{
		inorderTraversalHelper(root->left,tvi);
		tvi.push_back(root->val);
		inorderTraversalHelper(root->right,tvi);
	}
}

vector<int> inorderTraversal(TreeNode *root) {
	
	vector<int> vi;
	inorderTraversalHelper(root,vi);
	return vi;
  }

int numTrees(int n) {
	if(n==0||n==1)	return 1;
	int num=0;
	for (int i=1;i<=n;i++)
		num+=numTrees(n-i)*numTrees(i-1);
	return num;
   }

vector<TreeNode *> generateTrees(int start, int end)
{
	vector<TreeNode *> trees;
	if (start>end)
	{
		trees.push_back(NULL);
		return trees;
	}
	if(start==end)
	{
		trees.push_back(new TreeNode(start));
		return trees;
	}
	
	for (int i=start;i<=end;i++)
	{
		vector<TreeNode *> l_trees=generateTrees(start,i-1);
		vector<TreeNode *> r_trees=generateTrees(i+1,end);
		
		for (int l=0;l<l_trees.size();l++)
		{
			for (int r=0;r<r_trees.size();r++)
			{
				TreeNode *root_i = new TreeNode(i);
				root_i->left=l_trees[l];
				root_i->right=r_trees[r];
				trees.push_back(root_i);
			}
		}
	}
	return trees;
}

vector<TreeNode *> generateTrees(int n) {
	return generateTrees(1,n);
  }

bool isInterleaveHelper(string s1, string s2, string s3,int i1,int i2,int i3)
{
	if (i3==s3.length())	return true;
	if (s3[i3]!=s1[i1]&&s3[i3]!=s2[i2])	return false;
	
	if (i1==s1.length())
	{
		if(s3[i3]==s2[i2])	return	isInterleaveHelper(s1,s2,s3,i1,i2+1,i3+1);
		else				return  false;	
	}
	if (i2==s2.length())
	{
		if(s3[i3]==s1[i1])	return isInterleaveHelper(s1,s2,s3,i1+1,i2,i3+1);
		else				return false;
	}
	
	bool is_inter=false;
	if(s3[i3]==s1[i1]&&s3[i3]!=s2[i2])
	{
		return isInterleaveHelper(s1,s2,s3,i1+1,i2,i3+1);
	}else if (s3[i3]!=s1[i1]&&s3[i3]==s2[i2])
	{
		return isInterleaveHelper(s1,s2,s3,i1,i2+1,i3+1);
	}else
	{
		is_inter=isInterleaveHelper(s1,s2,s3,i1,i2+1,i3+1);
		if (is_inter)	return true;
		return isInterleaveHelper(s1,s2,s3,i1+1,i2,i3+1);
	}
}

bool isInterleave(string s1, string s2, string s3) {
	int len1=s1.length();
	int len2=s2.length();
	int len3=s3.length();
	if(len1+len2!=len3)	return false;
	return isInterleaveHelper(s1,s2,s3,0,0,0);
 }

bool isInterleave_dp(string s1, string s2, string s3)
{
	if (s1.length()+s2.length()!=s3.length())	return false;
	vector<vector<bool> > rs_table(s1.length()+1,vector<bool>(s2.length()+1,false));
	rs_table[0][0]=true;
	int i;
	for (i=1;i<=s1.length();i++)
		rs_table[i][0]=rs_table[i-1][0]&&s1[i-1]==s3[i-1];
	for (i=1;i<=s2.length();i++)
		rs_table[0][i]=rs_table[0][i-1]&&s2[i-1]==s3[i-1];
	for (i=1;i<=s1.length();i++)
	{
		for (int j=1;j<=s2.length();j++)
		{
			rs_table[i][j]=rs_table[i-1][j]&&s1[i-1]==s3[i+j-1]||rs_table[i][j-1]&&s2[j-1]==s3[i+j-1];
		}
	}
	return rs_table[s1.length()][s2.length()];
}

void isValidBSTHelper(TreeNode *root, vector<int> &vi)
{
	if (root)
	{
		isValidBSTHelper(root->left,vi);
		vi.push_back(root->val);
		isValidBSTHelper(root->right,vi);
	}
}

bool isValidBST(TreeNode *root) {
    vector<int> vi;
	isValidBSTHelper(root,vi);
	if (vi.size()==0)	return true;
	int first=vi[0];
	for (int i=1;i<vi.size();i++)
	{
		int curv=vi[i];
		if (first>=curv)	return false;
		first=curv;
	}
	return true;
    }

TreeNode *first=NULL;
TreeNode *second=NULL;
TreeNode *pre=NULL;

void recoverTreeHelper(TreeNode *root)
{
	if (root)
	{
		recoverTreeHelper(root->left);
		if (pre&&pre->val>root->val)
		{
			if (first==NULL)
			{
				first=pre;
				second=root;
			}else
				second=root;
		}
		pre=root;
		recoverTreeHelper(root->right);
	}
}


void recoverTree(TreeNode *root) {
	first=second=pre=NULL;
	recoverTreeHelper(root);
	int v=first->val;
	first->val=second->val;
	second->val=v;
   }

bool isSameTree(TreeNode *p, TreeNode *q)
{
	if(p==NULL&&q==NULL)	return true;
	if(p==NULL&&q!=NULL)	return false;
	if(p!=NULL&&q==NULL)	return false;
	if(p->val!=q->val)		return false;
	return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}

bool isSymmetric(TreeNode *lt, TreeNode *rt)  
{  
	if (!lt && !rt) return true;  
	if (lt && !rt || !lt && rt || lt->val != rt->val) return false;  
	return isSymmetric(lt->left, rt->right) &&isSymmetric(lt->right, rt->left);  
}  

bool isSymmetric(TreeNode *root) {
	if (!root) return true;  
	return isSymmetric(root->left, root->right); 	
}

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> >	rst;
	queue<TreeNode*>		st1;
	queue<TreeNode*>		st2;
	if (root)				st1.push(root);
	while (!st1.empty()||!st2.empty())
	{
		vector<int> tvi;
		while (!st1.empty())
		{
			TreeNode* trn=st1.front();
			st1.pop();
			if (trn->left)	st2.push(trn->left);
			if (trn->right)	st2.push(trn->right);
			tvi.push_back(trn->val);
		}
		rst.push_back(tvi);
		
		if(st2.empty())     continue;
		tvi.clear();
		while (!st2.empty())
		{
			TreeNode* trn=st2.front();
			st2.pop();
			if (trn->left)	st1.push(trn->left);
			if (trn->right)	st1.push(trn->right);
			tvi.push_back(trn->val);
		}
		rst.push_back(tvi);
	}
	return rst;
}

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> >	rst;
	stack<TreeNode*>		st1;
	stack<TreeNode*>		st2;
	if (root)				st1.push(root);
	while (!st1.empty()||!st2.empty())
	{
		vector<int> tvi;
		while (!st1.empty())
		{
			TreeNode* trn=st1.top();
			st1.pop();
			if (trn->left)	st2.push(trn->left);
			if (trn->right)	st2.push(trn->right);
			tvi.push_back(trn->val);
		}
		rst.push_back(tvi);
		
		if(st2.empty())     continue;
		tvi.clear();
		while (!st2.empty())
		{
			TreeNode* trn=st2.top();
			st2.pop();
			if (trn->right)	st1.push(trn->right);
			if (trn->left)	st1.push(trn->left);
			tvi.push_back(trn->val);
		}
		rst.push_back(tvi);
	}
	return rst;
    }

int maxDepth(TreeNode *root) {
    if(!root)   return 0;
	int lh=0;
	int rh=0;
	if(root->left)  lh=1+maxDepth(root->left);
	if(root->right) rh=1+maxDepth(root->right);
	int h=rh>lh?rh:lh;
	return h>1?h:1;
}

TreeNode *buildTreeHelper(Iter istart, Iter iend, Iter pstart, Iter pend)
{
	if (istart==iend)	return NULL;
	int v=*pstart;
	Iter iterroot =find(istart,iend,v);
	TreeNode* res=new TreeNode(v);
	res->left=buildTreeHelper(istart,iterroot,pstart+1,pstart+1+(iterroot-istart));
	res->right=buildTreeHelper(iterroot+1,iend,pstart+1+(iterroot-istart),pend);
	return res;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	return buildTreeHelper(inorder.begin(),inorder.end(),preorder.begin(),preorder.end());	
	}

TreeNode *buildTreeHelper2(Iter istart, Iter iend, Iter pstart, Iter pend)
{
	if (istart==iend)	return NULL;
	int v=*(pend-1);
	Iter iterroot =find(istart,iend,v);
	TreeNode* res=new TreeNode(v);
	res->left=buildTreeHelper2(istart,iterroot,pstart,pstart+(iterroot-istart));
	res->right=buildTreeHelper2(iterroot+1,iend,pstart+(iterroot-istart),pend-1);
	return res;
}

TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder) {
	return buildTreeHelper2(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }

vector<vector<int> > levelOrderBottom(TreeNode *root) {
	vector<vector<int> >	rst;
	queue<TreeNode*>		st1;
	queue<TreeNode*>		st2;
	std::vector<vector<int> >::iterator it;
	if (root)				st1.push(root);
	while (!st1.empty()||!st2.empty())
	{
		vector<int> tvi;
		while (!st1.empty())
		{
			TreeNode* trn=st1.front();
			st1.pop();
			if (trn->left)	st2.push(trn->left);
			if (trn->right)	st2.push(trn->right);
			tvi.push_back(trn->val);
		}
		it=rst.begin();
		rst.insert(it,tvi);
		
		if(st2.empty())     continue;
		tvi.clear();
		while (!st2.empty())
		{
			TreeNode* trn=st2.front();
			st2.pop();
			if (trn->left)	st1.push(trn->left);
			if (trn->right)	st1.push(trn->right);
			tvi.push_back(trn->val);
		}
		it=rst.begin();
		rst.insert(it,tvi);
	}
	return rst;
    }

TreeNode * sortedArrayToBST(vector<int> &num,int l,int r)
{
	if (l>r)	return NULL;
	int mid=(l+r)/2;
	TreeNode *rt = new TreeNode(num[mid]);
	rt->left=sortedArrayToBST(num,l,mid-1);
	rt->right=sortedArrayToBST(num,mid+1,r);
	return rt;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
	return sortedArrayToBST(num,0,num.size()-1);
  }

TreeNode *sortedListToBST(ListNode *head)
{
	if (head == NULL)  
	{  
		return NULL;  
	}  
	
	ListNode *pre=NULL, *slow=head, *fast=head;  
	while (fast->next!=NULL && fast->next->next!=NULL)  
	{  
		pre = slow;  
		slow = slow->next;  
		fast = fast->next->next;  
	}  
	TreeNode *tree = new TreeNode(slow->val);  
	if (pre != NULL)  
	{  
		pre->next = NULL;  
		tree->left = sortedListToBST(head);  
	} else  
	{  
		tree->left = NULL;  
	}  
	tree->right = sortedListToBST(slow->next);  
	
	return tree;  
}

bool isBalanced(TreeNode *root, int *depth)
{
	if(NULL == root){
		*depth = 0;
		return true;
	}
	int left, right;
	if(isBalanced(root->left, &left) && isBalanced(root->right, &right)){
		int diff = left - right;
		if((diff>1) || (diff<-1))
		{
			return false;
		}
		*depth = 1 + (left > right ? left : right);
		return true;
	}
} 

bool isBalanced(TreeNode *root) {
	int depth = 0;
	return isBalanced(root, &depth);
}

int minDepth(TreeNode *root) {
	if(NULL == root)	return 0;
	int left=minDepth(root->left);
	int right=minDepth(root->right);
	if (0==left)		return 1+right;
	else if (right==0)	return left+1;
	int minv=left<right?left:right;
	return minv+1;
 }

void  pathSum(vector<vector<int> > &res,TreeNode *root, int sum,vector<int> &vi)
{
	if(root->left == NULL && root->right == NULL && root->val == sum){
		res.push_back(vi);
		return;
	}
	if(root->left){
		vi.push_back(root->left->val);
		pathSum(res,root->left,sum- root->val,vi);
		vi.pop_back();
	}
	if(root->right){
		vi.push_back(root->right->val);
        pathSum(res,root->right, sum - root->val,vi);
		vi.pop_back();
	}
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
	vector<vector<int> > rst;
	if(root == NULL)	return rst;
	vector<int>	vi;
	vi.push_back(root->val);
	pathSum(rst,root,sum,vi);
	return rst;
}

bool hasPathSum(TreeNode *root, int sum) {
	if (root==NULL)	return false;
	if(root->left==NULL&&root->right==NULL&&root->val==sum)	return true;
	return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
  }

void flatten(TreeNode *root) {
	if (root == NULL) return;
	if (root->left)
		flatten(root->left);
	if (root->right)
		flatten(root->right);
	if (NULL == root->left)
		return;
	
	TreeNode ** ptn = & (root->left->right);
	while (*ptn)
		ptn = & ((*ptn)->right);
	*ptn = root->right;
	root->right = root->left;
    root->left = NULL;
    }

int numDistinct(string S, string T) {  
	int m = T.length();  
	int n = S.length();  
	vector<vector<int> > dp(m+1,vector<int>(n+1,0));  
	dp[0][0] = 1;
	int i,j;
	for(i=0;i<=m;i++)  
		dp[i][0] = 0;  
	for(j=0;j<=n;j++)  
		dp[0][j] = 1;  
	for(i=1;i<=m;i++)  
		for(int j=1;j<=n;j++){  
			if (T[i-1]==S[j-1])  
				dp[i][j] = dp[i][j-1] + dp[i-1][j-1];  
			else  
				dp[i][j] = dp[i][j-1];  
		}  
        return dp[m][n]; 
   }  

void connect(TreeLinkNode *root) {
	if(!root)	return ;
	if (root->left){
		root->left->next=root->right;
	}
	if(root->right){  
		root->right->next = root->next==NULL?NULL: root->next->left;  
	}  
	connect(root->left);  
    connect(root->right);  
  }

void connect2(TreeLinkNode *root) {
	if(!root)	return ;
	if (root->left){
		if(root->right)
		{
			root->left->next=root->right;
		}else
		{
			TreeLinkNode* rightRoot=root->next;
			if (!rightRoot) root->left->next=NULL;
			else{
				while (root->left->next==NULL&&rightRoot)
				{
					if (rightRoot->left)
					{
						root->left->next=rightRoot->left;
					}else if (rightRoot->right)
					{
						root->left->next=rightRoot->right;
					}else
						root->left->next=NULL;
					rightRoot=rightRoot->next;
				}
			}
		}
	}
	if(root->right){  
		TreeLinkNode* rightRoot=root->next;
		if (!rightRoot)	root->right->next=NULL;
		else{
			while(root->right->next==NULL&&rightRoot)
			{
				if (rightRoot->left)
				{
					root->right->next=rightRoot->left;
				}else if (rightRoot->right)
				{
					root->right->next=rightRoot->right;
				}else
					root->right->next=NULL;
				rightRoot=rightRoot->next;
			}
		}
	}  
	connect2(root->right);
	connect2(root->left);     
}

vector<vector<int> > generate(int numRows) {
	vector<vector<int> > rst;
	vector<int>			 vi;
	if (numRows<=0)		return rst;
	vi.push_back(1);
	rst.push_back(vi);
	vi.clear();
	for (int i=1;i<numRows;i++)
	{
		for (int j=0;j<=i;j++)
		{
			if (j==0||j==i) vi.push_back(1);
			else{
				int cv=rst[i-1][j-1]+rst[i-1][j];
				vi.push_back(cv);
			}
		}
		rst.push_back(vi);
		vi.clear();
	}
	return rst;
}

vector<int> getRow(int rowIndex) {
	vector<int> v;
    if(rowIndex < 0) return v;
    for(int i = 0; i <= rowIndex; ++i){
		v.push_back(0);
    }
    for(int j = 0; j <= rowIndex; ++j){
		v[rowIndex] = 1;
		for(int k = rowIndex-1; k > 0; --k)
		{
			v[k] = v[k] + v[k-1];
		}
		v[0] = 1;
	}
	return v;
}

int minimumTotal(vector<vector<int> > &triangle, int i, int j)  
{  
	if(i == triangle.size()-1)  
		return triangle[i][j];  
	
	int sum0 = minimumTotal(triangle,i+1,j);  
	int sum1 = minimumTotal(triangle,i+1,j+1);  
	
	int minv=sum0>sum1?sum1:sum0;
	
	return minv+triangle[i][j];  
}  

int minimumTotal2(vector<vector<int> > &triangle) {
	return minimumTotal(triangle,0,0); 
}


int minimumTotal(vector<vector<int> > &triangle) {
	int numRow = triangle.size();  
	vector<int> ibuffer;  
	ibuffer.resize(numRow);  
	
	for (int i=numRow-1; i>=0; --i)  
	{  
		vector<int> &row = triangle[i];  
		
		for (int j=0; j<row.size(); ++j)  
		{  
			if(i==numRow-1)  
				ibuffer[j] = row[j];  
			else  
				ibuffer[j] = mymin(row[j]+ibuffer[j], row[j]+ibuffer[j+1]);  
		}  
	} 
    return ibuffer[0];  
}

int maxProfit3(vector<int> &prices) {
	if(prices.size()<=1) return 0;
	int len = prices.size();
	vector<int> historyPro(len,0);
	historyPro[0] = 0;
	int lowest = prices[0];
	int i;
	for(i=1;i<len;++i) {
		lowest = mymin(lowest, prices[i]);
		historyPro[i] = mymax(historyPro[i-1], prices[i]-lowest);
	}
	vector<int>  futurePro(len,0);
	futurePro[len-1] = 0;
	int highest = prices[len-1];
	for(i=len-2;i>=0;--i) {
		highest = mymax(highest, prices[i]);
		futurePro[i] = mymax(futurePro[i+1], highest-prices[i]);
	}
	int maxPro = 0; 
	for(i=0;i<len;i++)
		maxPro = mymax(maxPro, historyPro[i]+futurePro[i]);
    return maxPro;
}

int maxProfit2(vector<int> &prices) {
    int sz=prices.size();
	if (sz<=0)	return 0;
	int incoming=0;
	int start_index=0;
	int i=0;
	for (i=1;i<sz;i++)
	{
		if (prices[i]<prices[i-1])
		{
			incoming+=prices[i-1]-prices[start_index];
			start_index = i;
		}
	}
	if (prices[i-1]>prices[start_index])
	{
		incoming+=prices[i-1]-prices[start_index];
	}
	return incoming;
	
}

int maxProfit(vector<int> &prices) {
	int sz=prices.size();
	if (sz<=0)	return 0;
	int minv=prices[0];
	int incoming=0;
	for (int i=0;i<sz;i++)
	{
		if (prices[i]<minv)	minv=prices[i];
		else{
			if (prices[i]-minv>incoming)
			{
				incoming=prices[i]-minv;
			}
		}
	}
	return incoming;
  }

int maxPathSumRe(TreeNode *node, int &res)  
{  
	if (!node) return 0;  
	int l = maxPathSumRe(node->left, res);  
	int r = maxPathSumRe(node->right, res);  
	int sum = mymax(node->val, mymax(l, r) + node->val);  
	res = mymax(res, sum);  
	res = mymax(res, l + r + node->val);  
	return sum;  
}  
int maxPathSum(TreeNode *root) {
	int res = INT_MIN;  
	maxPathSumRe(root, res);  
	return res;  
    }


bool isStr(char &ch){  
	if(ch >= '0' && ch <= '9'){  
		return true;  
	} else if(ch >= 'a' && ch <= 'z'){  
		return true;  
	} else if(ch >= 'A' && ch <= 'Z'){  
		ch += 32;  
		return true;  
	}   
	return false;  
} 

bool isPalindrome(string s) {
	
	string tmp;
	int i;
	for (i=0;i<s.length();i++)
	{
		if (isStr(s[i]))
		{
			tmp+=s[i];
		}
	}
	
	i=0;
	int j=tmp.size()-1;
	while (i<j)
	{
		if (tmp[i]==tmp[j])
		{
			i++;
			j--;
		}else
			return false;
	}
	return i>=j?true:false;
  }

int sumNumbers(TreeNode *root,int sum)
{
	if (!root)	return 0;
	if (!root->left&&!root->right) return 10*sum+root->val;
	return sumNumbers(root->left,10*sum+root->val)+sumNumbers(root->right,10*sum+root->val);
}
int sumNumbers(TreeNode *root) {
	return sumNumbers(root,0); 
}

void dfs(vector<vector<char> > &board, int i, int j)
{
	int row = board.size(), col = board[0].size();
	if(i > 1 && board[i-1][j] == 'O')
	{
		board[i-1][j] = '#';
		dfs(board, i-1, j);
	}
	if(i < row-1 && board[i+1][j] == 'O')
	{
		board[i+1][j] = '#';
		dfs(board, i+1, j);
	}
	if(j > 1 && board[i][j-1] == 'O')
	{
		board[i][j-1] = '#';
		dfs(board, i, j-1);
	}
	if(j < col-1 && board[i][j+1] == 'O')
	{
		board[i][j+1] = '#';
		dfs(board, i, j+1);
	}
} 
void solve(vector<vector<char> > &board) {
	if (board.size() < 3) return ;
	if (board[0].size() < 3) return ;
	int m = board.size(), n = board[0].size();
	for(int j=0;j<n;j++)
	{
		if (board[0][j] == 'O')
		{
			board[0][j] = '#';
			dfs(board,0,j);
		}
		if (board[m-1][j] == 'O')
		{
			board[m-1][j] = '#';
			dfs(board,m-1,j);
		}
	}
	for(int i=1;i<m-1;i++)
	{
		if (board[i][0] == 'O')
		{
			board[i][0] = '#';
			dfs(board,i,0);
		}
		if (board[i][n-1] == 'O')
		{
			board[i][n-1] = '#';
			dfs(board,i,n-1);
		}
	}
	for( i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(board[i][j]=='O') board[i][j]='X';
			else if(board[i][j]=='#') board[i][j]='O';
		} 
    }


void DFSRecur(const string &s, bool **f, int i, 
			  vector< vector<string> > &res, vector<string> &tmp)
{//i为遍历的起点
	int len = s.length();
	if(i >= len){
		res.push_back(tmp); 
		return;
			 }
	for(int k = 1; k <= len - i; k++)
		if(f[i][k] == true)
		{
			tmp.push_back(s.substr(i, k));
			DFSRecur(s, f, i+k, res, tmp);
			tmp.pop_back();
		}                 
} 

vector<vector<string> > partition(string s) {
	vector< vector<string> >res;
	int len = s.length();
	if(len == 0)return res;
	//f[i][j] = true表示以i为起点，长度为j的子串是回文
	bool **f = new bool*[len];
	for(int i = 0 ; i < len; i++)
	{
		f[i] = new bool[len+1];
		for(int j = 0; j < len+1; j++)
			f[i][j] = 0;
		f[i][1] = true;
	}
	for(int k = 2; k <= len; k++)
	{
		for(int i = 0; i <= len-k; i++)
		{
			if(k == 2)f[i][2] = (s[i] == s[i+1]);
			else f[i][k] = f[i+1][k-2] && (s[i] == s[i+k-1]);
		}
	}
	vector<string> tmp;
	DFSRecur(s, f, 0, res, tmp);
	for(i = 0 ; i < len; i++)
		delete [](f[i]);
	delete []f;
	return res;
  }

vector< vector<int> > map;
int IsPalindrome(string &s, int i, int j){
	if(i>j) return false;
	if(map[i][j]!=-1)
		return map[i][j];
	if(i==j){
		return map[i][j] = 1;
	}
	
	if(s[i]!=s[j])
		return map[i][j] = 0;
	else{
		if(j-i==1)
			return map[i][j] = 1;
		else
			return map[i][j] = IsPalindrome(s, i+1, j-1);
	}
}
int minCut(string s) {
	int n = s.length();
	if(n==0 || n==1)    
		return 0;
	vector<int> min, vtmp;
	
	min.clear(); vtmp.clear(); map.clear();
	for(int i=0; i<n; i++){
		min.push_back(0);
		vtmp.push_back(-1);
	}
	for(i=0; i<n; i++)
		map.push_back(vtmp);
	
	int tmp, ans;
	for(int inter=1; inter<n; inter++){
		if(IsPalindrome(s, 0, inter)){
			min[inter]=0;
		}
		else{
			ans = n+1;
			for(int k=0; k<inter; k++){
				if(IsPalindrome(s, k+1, inter))
					tmp = min[k]+1;
				else
					tmp = min[k]+inter-k;
				if(tmp<ans)
					ans = tmp;
			}
			min[inter]=ans;
		}
	}
	return min[n-1];   
    }

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	int N = gas.size(), startIndex = -1;
	int sum = 0, total = 0;
	for(int i = 0; i < N; i++)
	{
		sum += (gas[i] - cost[i]);
		total += (gas[i] - cost[i]);
		if(sum < 0)
		{
			startIndex = i; 
			sum = 0;
		}
    }
	return total >= 0 ? startIndex + 1 : -1;
}

int candy(vector<int> &ratings)
{
	int *candyNum = new int[ratings.size()];//每个小孩的糖数目
	for(int i = 0; i < ratings.size(); i++)
		candyNum[i] = 1;
	for(i = 1; i < ratings.size(); i++)
		if(ratings[i] > ratings[i-1])
			candyNum[i] = candyNum[i-1] + 1;
		for(i = ratings.size()-2; i>=0; i--)
			if(ratings[i] > ratings[i+1] && candyNum[i] <= candyNum[i+1])
				candyNum[i] = candyNum[i+1] + 1;
			int result = 0;
			for(i = 0; i < ratings.size(); i++)
				result += candyNum[i];
			delete []candyNum;
			return result;
     }

int singleNumber2(int A[], int n) {
	if(n<=0)	return 0;
	int rs=0;
	for (int i=0;i<32;i++)
	{
		int ct=0;
		int flag=1<<i;
		for (int j=0;j<n;j++)
			if (A[j]&flag)
				ct;
			if (ct%3)	rs|=flag;
	}
	return rs;
}

int singleNumber(int A[], int n) {
	if(n==0)	return 0;
	int rs=A[0];
	for (int i=1;i<n;i++)
	{
		rs^=A[i];
	}
	return rs;
  }

RandomListNode *copyRandomList(RandomListNode *head) {
	
	RandomListNode *tHead = head;
	RandomListNode *next = NULL;
	while(tHead)  
	{  
		next = tHead->next;  
		RandomListNode *node = new RandomListNode(tHead->label);  
		node->next = tHead->next;  
		//node->random = tHead->random;  
		tHead->next = node;  
		tHead= next;  
    }  
	tHead = head;
	while(tHead)  
	{  
		if(tHead->random) tHead->next->random = tHead->random->next;  
		tHead = tHead->next->next;  
    }  
	RandomListNode *retHead = NULL;
	RandomListNode *tRet = NULL;
	
	tHead = head; 
	RandomListNode *next2 = NULL;  
	while(tHead)  
	{  
		if(retHead == NULL)  
		{    
			next2 = tHead->next->next;  
			retHead = tHead->next;  
			tRet = retHead;  
			tHead->next = next2;  
			tHead = next2;  
		}  
		else  
		{  
			next2 = tHead->next->next;  
			tRet->next = tHead->next;  
			tHead->next = next2;  
			tHead = next2;  
			tRet = tRet->next;  
		}  
		
	}  
	return retHead;  
  }

bool hasCycle(ListNode *head) {
	if(head == NULL || head->next == NULL)return false;
	ListNode *fast = head, *low = head;
	while(fast != NULL && fast->next != NULL)
	{
		low  = low->next;
		fast = fast->next->next;
		if(low == fast)return true;
	}
	return false;
     }

ListNode *detectCycle(ListNode *head)  {
    ListNode* slow = head;
    ListNode* fast = head;
	
    while (true) {
        if (fast == NULL || fast->next == NULL) {
            return NULL;    //遇到null了，说明不存在环
        }
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            break;    //第一次相遇在Z点
        }
    }
	
    slow = head;    //slow从头开始走，
    while (slow != fast) {    //二者相遇在Y点，则退出
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
void reorderList(ListNode *head) {
	if (head == NULL || head->next == NULL)  
        return;  
	ListNode* slowNode = head;
	ListNode* fastNode = head; 
	while (fastNode->next != NULL) {  
        fastNode = fastNode->next;  
        if (fastNode->next != NULL) {  
            fastNode = fastNode->next;  
        } else {  
            break;  
        }  
        slowNode = slowNode->next;  
    }  
	
	ListNode* head1 = head;
	ListNode* head2 = slowNode->next;  
    // detach the two sublists  
    slowNode->next = NULL;  
	
	ListNode* cur = head2;
	ListNode* post = cur->next;  
	cur->next=NULL;
	while (post != NULL) {  
        ListNode* temp = post->next;  
        post->next = cur;  
        cur = post;  
        post = temp;  
    }  
    head2 = cur; // the new head of the reversed sublist  
	ListNode* p = head1;
	ListNode* q = head2;  
    while (q != NULL) {  
        ListNode* temp1 = p->next;  
        ListNode* temp2 = q->next;  
        p->next = q;  
        q->next = temp1;  
        p = temp1;  
        q = temp2;  
    }  
  }

void preorderTraversal(TreeNode *root,vector<int> &vi)
{
	if (root)
	{
		vi.push_back(root->val);
		preorderTraversal(root->left,vi);
		preorderTraversal(root->right,vi);
	}
}
vector<int> preorderTraversal(TreeNode *root) {
	vector<int> rst;
	preorderTraversal(root,rst);
	return rst;
    }

void postorderTraversal(TreeNode *root,vector<int> &vi)
{
	if (root)
	{
		postorderTraversal(root->left,vi);
		postorderTraversal(root->right,vi);
		vi.push_back(root->val);
	}
}
vector<int> postorderTraversal(TreeNode *root) {
	vector<int> rst;
	postorderTraversal(root,rst);
	return rst;
    }

int op(int op1, int op2, char optor)
{
	if(optor == '+')return op1 + op2;
	else if(optor == '-')return op1 - op2;
	else if(optor == '*')return op1 * op2;
	else return op1 / op2;
}
int evalRPN(vector<string> &tokens) {
    int len = tokens.size();
	stack<int> S;
	for(int i = 0; i < len; i++)
	{
		if(tokens[i] == "+" || tokens[i] == "-" ||tokens[i] == "*" || tokens[i] == "/")
		{
			int op2 = S.top(); S.pop();
			int op1 = S.top(); S.pop();
			S.push( op(op1, op2, tokens[i][0]) );
		}else
			S.push(atoi(tokens[i].c_str()));
	}
	return S.top();
  }

ListNode *merge(ListNode *head1, ListNode *head2)
{
	if(head1 == NULL)return head2;
	if(head2 == NULL)return head1;
	ListNode *res , *p ;
	if(head1->val < head2->val)
	{
		res = head1;
		head1 = head1->next;
			 }else
			 {
				 res = head2; 
				 head2 = head2->next;
			 }
			 p = res;         
			 while(head1 != NULL && head2 != NULL)
			 {
				 if(head1->val < head2->val)
				 {
					 p->next = head1;
					 head1 = head1->next;
				 }else
				 {
					 p->next = head2;
					 head2 = head2->next;
				 }
				 p = p->next;
			 }
			 if(head1 != NULL)	p->next = head1;
			 else if(head2 != NULL)p->next = head2;
			 return res;
}
ListNode *sortList(ListNode *head) {
	//链表归并排序
	if(head == NULL || head->next == NULL)	return head;
	else
	{
		//快慢指针找到中间节点
		ListNode *fast = head;
		ListNode* slow = head;
		while(fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow;
		slow = slow->next;
		fast->next = NULL;
		fast = sortList(head);//前半段排序
		slow = sortList(slow);//后半段排序
		return merge(fast,slow);
	}         
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode* pa=headA;
	ListNode* pa_tail=headA;
	ListNode* pb=headB;
	ListNode* pb_tail=headB;
	int lena=0;
	int lenb=0;
	while (pa)
	{
		pa_tail=pa;
		pa=pa->next;
		lena++;
	}
	
	while (pb)
	{
		pb_tail=pb;
		pb=pb->next;
		lenb++;
	}
	
	if (pa_tail!=pb_tail||lena==0||lenb==0)
	{
		return NULL;
	}
	
	int diff=lena-lenb;
	
	ListNode* p1=NULL;
	ListNode* p2=NULL;
	if (diff>0)
	{
		p1=headA;
		p2=headB;
	}else
	{
		p1=headB;
		p2=headA;
	}
	while (diff--)
	{
		p1=p1->next;
	}
	
	while (p1!=p2)
	{
		p1=p1->next;
		p2=p2->next;
	}
	return p1;
}    

int findPeakElement(const vector<int> &num) {
	if (num.size()<=1)	return 0;
	int index=0;
	for (int i=1;i<num.size();i++)
	{
		if (num[index]<num[i])
		{
			if (i+1<num.size())
			{
				if (num[i]>num[i+1])
				{
					return i;
				}else
				{
					index=i;
				}
			}else
				return i;
		}
	}
	return index;
  }

int maximumGap(vector<int> &num) {  
	int sizes=num.size();  
	if(sizes<2)  
		return 0;  
	sort(num.begin(),num.end());  
	int pre=num[0];  
	int max=-1;  
	for(int i=1;i<sizes;i++)  
	{  
		if(num[i]-pre>max)  
			max=num[i]-pre;  
		pre=num[i];  
	}  
	return max;  
 }  

int compareVersion(string version1, string version2) {
	vector<int> v1;
	vector<int> v2;
	string tmp="";
	int i;
	int len1=version1.length();
	int len2=version2.length();
	for (i=0;i<len1;i++)
	{
		if (version1[i]=='.')
		{
			if (tmp.length()>0)
			{
				v1.push_back(atoi(tmp.c_str()));
				tmp="";
			}
		}else
			tmp+=version1[i];
	}
	if (tmp.length()>0)
	{
		v1.push_back(atoi(tmp.c_str()));
	}
	
	tmp="";
	for (i=0;i<len2;i++)
	{
		if (version2[i]=='.')
		{
			if (tmp.length()>0)
			{
				v2.push_back(atoi(tmp.c_str()));
				tmp="";
			}
		}else
			tmp+=version2[i];
	}
	if (tmp.length()>0)
	{
		v2.push_back(atoi(tmp.c_str()));
	}
	
    len1=v1.size();
	len2=v2.size();
	int len=len1>len2?len2:len1;
	for (i=0;i<len;i++)
	{
		int cv1=v1[i];
		int cv2=v2[i];
		if (cv1>cv2)		return 1;
		else if (cv1<cv2)	return -1;
	}
	
	if (len1<len2){
		for(int i=len;i<len2;i++)
		{
			if(v2[i]!=0)    return -1;
		}
	}
    if (len1>len2)	
    {
		for(int i=len;i<len1;i++)
		{
			if(v1[i]!=0)    return 1;
		}
    }
	return 0;
 }

int majorityElement(vector<int> &num) {
	
	sort(num.begin(),num.end());
	return num[num.size()/2];
    }

string convertToTitle(int n,char* table)
{
	string tmp="";
	if (n>0){
		int a=n%26;
		int b=n/26;
		if (a==0){
			tmp+=table[25];b-=1;
		}else
			tmp+=table[n%26 -1];
		if (b>=26)      return tmp+convertToTitle(b,table);
		else if (b>0)   return tmp+table[b-1];
	}
	return tmp;
}
string convertToTitle(int n) {
    char table[]={'A','B','C','D','E','F','G','H','I','J',\
		'K','L','M','N','O','P','Q','R','S','T',\
		'U','V','W','X','Y','Z'};
	string trs=convertToTitle(n,table);
	int l=0; 
	int r=trs.length()-1;
	while(l<r)
	{
		char tc=trs[l];
		trs[l]=trs[r];
		trs[r]=tc;
		l++;
		r--;
	}
	return trs;
  }

int titleToNumber(string s) {
	if(s.length()== 0) return 0;  
	int sum = 0;  
	for(int i=0; i<s.length(); i++) {  
		sum = 26*sum + s[i] - 'A' + 1;  
	}  
	return sum; 
}
int trailingZeroes(int n) {
	int res = 0;  
	while(n)  
	{  
		res += n/5;  
		n /= 5;  
	}  
	return res;  
    }