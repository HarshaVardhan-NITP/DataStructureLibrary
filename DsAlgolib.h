#include<bits/stdc++.h>
using namespace std;
namespace DsAlgo{
	int gcd(int a,int b){
		if(b==0){
			return a;
		}
		return gcd(b,a%b);
	}
	int gcd_extended(int a,int b,int *x,int *y){
		if(a==0){
			*x=0;
			*y=1;
			return b;
		}
		int x1,y1;
		int gcd=gcd_extended(b%a,a,&x1,&y1);
		*x=y1-(b/a)*x1;
		*y=x1;
		return gcd;
	}
	void mod_inverse(int a,int m){
		int x,y;
		int g=gcd_extended(a,m,&x,&y);
		if(g==1){
			int ans=(x%m+m)%m;
			cout<<ans<<endl;
		}
		else{
			cout<<"inverse doesn't exist!!"<<endl;
		}
	}
	
	
	
///   Linked List Data Structure
	template<typename T>
	class linked_list{
		public:
			
		//	struct node{
			T data;
			linked_list* next;
			//};
			linked_list* head=NULL;
			
			void append_at_end(T n){
				
				linked_list* tmp=new linked_list();
				tmp->data=n;
				tmp->next=NULL;
				if(head==NULL){
					head=tmp;
				}
				else{
					linked_list* tmp1=head;
					while(tmp1->next!=NULL){
						tmp1=tmp1->next;
					}
				
					tmp1->next=tmp;
				}
			}
			void print_all_nodes(){
				linked_list* tmp1=head;
				while(tmp1->next!=NULL){
					cout<<tmp1->data<<" ";
					tmp1=tmp1->next;
				}
				cout<<tmp1->data<<" ";
			}
			void append_at_begin(T n){
				linked_list* tmp=new linked_list();
				tmp->data=n;
				tmp->next=head;
				head=tmp;
			}
			void append_at_n_pos(T num,T pos){
				linked_list* tmp=new linked_list();
				linked_list* tmp1=head;
				tmp->data=num;
				int i=1;
				while(i<pos){
					tmp1=tmp1->next;
					i++;
				}
				tmp->next=tmp1->next;
				tmp1->next=tmp;
			}
			void delete_node(T n){
				linked_list* tmp=head;
				linked_list* tmp1;
				if(tmp->data==n){
					tmp1=tmp;
					head=tmp->next;
					tmp1->next=NULL;
				}
				else{
					while(tmp->next->data!=n){
						tmp=tmp->next;
					}
					tmp1=tmp->next;
					tmp->next=tmp->next->next;
					tmp1->next=NULL;
				}
			}
			void reverse_linked_list(){
				linked_list* curr=head;
				linked_list* prev=NULL;
				linked_list* next=NULL;
				while(curr!=NULL){
					next=curr->next;
					curr->next=prev;
					prev=curr;
					curr=next;
				}
				head=prev;
				print_all_nodes();
			}
			void sort(){
				mergesort(&head);
			}
			void mergesort(linked_list** head){
				linked_list* headref=*head;
				linked_list* a;
				linked_list* b;
				if(headref==NULL||headref->next==NULL){
					return;
				}
				partition(headref,&a,&b);
				mergesort(&a);
				mergesort(&b);
				*head=mergeLists(a,b);
			}
			void partition(linked_list* source,linked_list** front,linked_list** back){
				linked_list* fast;
				linked_list* slow;
				slow=source;
				fast=source->next;
				while(fast!=NULL){
					fast=fast->next;
					if(fast!=NULL){
						slow=slow->next;
						fast=fast->next;
					}
				}
				*front=source;
				*back=slow->next;
				slow->next=NULL;
			}
			linked_list* mergeLists(linked_list* a,linked_list* b){
				linked_list* mergedlist=NULL;
				if(a==NULL){
					return b;
				}
				else if(b==NULL){
					return a;
				}
				if(a->data<=b->data){
					mergedlist=a;
					mergedlist->next=mergeLists(a->next,b);
				}
				else{
					mergedlist=b;
					mergedlist->next=mergeLists(a,b->next);
				}
				return (mergedlist);
			}
	};
	
	
	
///   Stack DataStructure
	template<typename T>
	class Stack{
		public:
			T data;
			Stack* next;
			Stack* head=NULL;
			bool isempty(){
				return !head;
			}
			void push(T n){
				Stack* temp=new Stack();
				temp->data=n;
				temp->next=head;
				head=temp;
			}
			T pop(){
				if(isempty()){
					cout<<"Stack Underflow!!"<<"\n";
					return -1;
				}
				Stack* temp=head;
				head=head->next;
				T x=temp->data;
				free(temp);
				return x;
			}
			T peek(){
				if(isempty()){
					return -1;
					cout<<"Stack empty!!"<<"\n";
				}
				return head->data;
			}
			void print_stack(){
				while(!isempty()){
					cout<<peek()<<" ";
					pop();
				}
			}
			void sortstack(string order){
				sorting(head,order);
			}
			void sorting(Stack* root,string ord){
				if(!isempty()){
					T x = pop();
					sorting(root,ord);
					sort_util(root,x,ord);
				}
				
			}
			void sort_util(Stack* root,T element,string ord){
				if(ord=="descending"){
					if(isempty() || element>peek()){
						push(element);
					}
					else{
						int temp=pop();
						sort_util(root,element,ord);
						push(temp);
					}
				}
				else if(ord=="ascending"){
					if(isempty() || element<peek()){
						push(element);
					}
					else{
						int temp=pop();
						sort_util(root,element,ord);
						push(temp);
					}
				}
			}
	};
	
	
	
	
///    Queue DataStructure
	template<typename T>
	class Queue{
		public:
			T data;
			Queue* next;
			Queue* head=NULL;
			bool isempty(){
				return !head;
			}
			void push(T n){
				Queue* temp=new Queue();
				temp->next=NULL;
				temp->data=n;
				if(head==NULL){
					head=temp;
				}
				else{
					Queue* temp1=head;
					while(temp1->next!=NULL){
						temp1=temp1->next;
					}
					temp1->next=temp;
				}
			}
			T pop(){
				if(isempty()){
					cout<<"Stack Underflow"<<"\n";
					return -1;
				}
				Queue* temp=head;
				head=head->next;
				T x=temp->data;
				free(temp);
				return x;
			}
			T peek(){
				if(isempty()){
					cout<<"Stack Empty!!"<<"\n";
					return -1;
				}
				return head->data;
			}
			void print_queue(){
				while(!isempty()){
					cout<<peek()<<" ";
					pop();
				}
			}
			void sortqueue(string order){
				Stack<T> s;
				while(!isempty()){
					s.push(pop());
				}
				if(order=="ascending"){
					s.sortstack("ascending");
					while(!s.isempty()){
						push(s.pop());
					}
				}
				else if(order=="descending"){
					s.sortstack("descending");
					while(!s.isempty()){
						push(s.pop());
					}
				}
				
			}
		
	};
	
	
	
///   Binary Search Tree DataStructure	
	template<typename T>
	class BSTree{
		public:
			T data;
			BSTree* left;
			BSTree* right;
			BSTree* head=NULL;
			void insert(T n){
				head=add(head,n);
			}
			BSTree* add(BSTree* root,T n){
				BSTree* temp=new BSTree();
				temp->data=n;
				temp->left=NULL;
				temp->right=NULL;
				if(root==NULL){
					//cout<<root->data<<" ";
					root=temp;
				}
				else if(n<=root->data){
					//cout<<root->data<<" ";
					root->left=add(root->left,n);
				}
				else{
					//cout<<root->data<<" ";
					root->right=add(root->right,n);
				}
				return root;
			}
			bool search(T n){
				return find(head,n);
			}
			bool find(BSTree* root,T n){
				if(root==NULL){
					return false;
				}
				else if(n==root->data){
					return true;
				}
				else if(n<=root->data){
					return find(root->left,n);
				}
				else{
					return find(root->right,n);
				}
			}
			T findMin(){
				return mini(head);
			}
			T mini(BSTree* root){
				if(root==NULL){
					cout<<"Empty Tree!!"<<" ";
					return -1;
				}
				if(root->left==NULL){
					return root->data;
				}
				return mini(root->left);
			}
			T findMax(){
				return maxi(head);
			}
			T maxi(BSTree* root){
				if(root==NULL){
					cout<<"Empty Tree!!"<<" ";
					return -1;
				}
				if(root->right==NULL){
					return root->data;
				}
				return maxi(root->right);
			}
			T height(){
				return depth(head);
			}
			T depth(BSTree* root){
				if(root==NULL){
					return -1;
				}
				return max(depth(root->left),depth(root->right))+1;
			}
			T maxnodes(){
				return height()+1;
			}
			void bfs(){
				if(head==NULL){
					return;
				}
				queue<BSTree*>q;
				q.push(head);
				while(!q.empty()){
					BSTree* curr=q.front();
					cout<<curr->data<<" ";
					if(curr->left!=NULL){
						q.push(curr->left);
					}
					if(curr->right!=NULL){
						q.push(curr->right);
					}
					q.pop();
				}
			}
			void preorder(){
				order_pre(head);
			}
			void order_pre(BSTree* root){
				if(root==NULL){
					return;
				}
				cout<<root->data<<" ";
				order_pre(root->left);
				order_pre(root->right);
			}
			void inorder(){
				order_in(head);
			}
			void order_in(BSTree* root){
				if(root==NULL){
					return;
				}
				order_in(root->left);
				cout<<root->data<<" ";
				order_in(root->right);
			}
			void postorder(){
				order_post(head);
			}
			void order_post(BSTree* root){
				if(root==NULL){
					return;
				}
				order_post(root->left);
				order_post(root->right);
				cout<<root->data<<" ";
			}
			bool isBSTree(){
				return BSTUtil(head,INT_MIN,INT_MAX);
			}
			bool BSTUtil(BSTree* root,T mini,T maxi){
				if(root==NULL){
					return true;
				}
				if(root->data>mini&&root->data<maxi&&BSTUtil(root->left,mini,root->data)&&BSTUtil(root->right,root->data,maxi)){
					return true;
				}
				else{
					return false;
				}
			}
			void delete_node(T n){
				deleteUtil(head,n);
			}
			BSTree* deleteUtil(BSTree* root,T n){
				if(root==NULL){
					return root;
				}
				else if(root->data>n){
					root->left=deleteUtil(root->left,n);
				}
				else if(root->data<n){
					root->right=deleteUtil(root->right,n);
				}
				else{
					if(root->left==NULL&&root->right==NULL){
						delete root;
						root=NULL;
					}
					else if(root->left==NULL){
						BSTree* temp=root;
						root=root->right;
						delete temp;
					}
					else if(root->right==NULL){
						BSTree* temp=root;
						root=root->left;
						delete temp;
					}
					else{
						int temp=mini(root->right);
						root->data=temp;
						root->right=deleteUtil(root->right,temp);
					}
				}
				return root;
			}
			BSTree* Find(BSTree* root,T n){
				if(root==NULL){
					return NULL;
				}
				if(root->data==n){
					return root;
				}
				else if(root->data<n){
					return Find(root->right,n);
				}
				else{
					return Find(root->left,n);
				}
			}
			T GetSuccesor(T n){
				BSTree* current=Find(head,n);
				if(current==NULL){
					return 0;
				}
				if(current->right!=NULL){
					return mini(current->right);
				}
				else{
					BSTree* successor=NULL;
					BSTree* ancestor=head;
					while(ancestor!=current){
						if(current->data<ancestor->data){
							successor=ancestor;
							ancestor=ancestor->left;
						}
						else{
							ancestor=ancestor->right;
						}
					}
					return successor->data;
				}
			}
			void invert_BSTree(){
				invert(head);
			}
			void invert(BSTree* root){
				if(root==NULL){
					return;
				}
				else{
					BSTree* temp;
					invert(root->left);
					invert(root->right);
					temp=root->left;
					root->left=root->right;
					root->right=temp;
				}
			}
	};
	
	
	
	
///   Graph DataStructure	
	class Graph{
		public:
			int v;
			vector<int> *adj;
			Graph(int v){
				this->v=v;
				adj=new vector<int>[v];
			}
			void addedge(int a,int b){
				adj[a].push_back(b);
			}
			void add_edge(int a,int b){
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
			void DFS(int n){
				bool visited[v];
				for(int i=0;i<v;i++){
					visited[i]=false;
				}
				DFSUtil(visited,n);
			}
			void DFSUtil(bool visited[],int n){
				visited[n]=true;
				cout<<n<<" ";
				vector<int>::iterator it;
				for(it=adj[n].begin();it!=adj[n].end();++it){
					if(visited[*it]!=true){
						DFSUtil(visited,*it);
					}
				}
			}
			void BFS(int n){
				queue<int> level;
				bool visited[v];
				for(int i=0;i<v;i++){
					visited[i]=false;
				}
				level.push(n);
				visited[n]=true;
				int siz=0,lev=0;
				while(!level.empty()){
					siz=level.size();
					while(siz--){
						int x=level.front();
						level.pop();
						cout<<x<<" ";
						vector<int>::iterator it;
						for(it=adj[x].begin();it!=adj[x].end();++it){
							if(!visited[*it]){
								visited[*it]=true;
								level.push(*it);
							}
						}
					}
					lev++;
				}
			}
	};
	long long str_to_int(string s){
		int ans=0;
		for(int i=0;i<s.length();i++){
			ans=10*ans+(s[i]-'0');
		}
		return ans;
	}
	string mul_big_nums(string a,string b){
		int len1=a.length();
		int len2=b.length();
		if(len1==0||len2==0){
			return "0";
		}
		vector<int>v(len1+len2,0);
		int a_ind=0;
		int b_ind=0;
		for(int i=len1-1;i>=0;i--){
			int num1=a[i]-'0';
			int carry=0;
			b_ind=0;
			for(int j=len2-1;j>=0;j--){
				int num2=b[j]-'0';
				int sum= num1*num2+v[a_ind+b_ind]+carry;
				carry=sum/10;
				v[a_ind+b_ind]=sum%10;
				b_ind++;
			}
			if(carry>0){
				v[a_ind+b_ind]+=carry;
			}
			a_ind++;
		}
		int i=v.size()-1;
		while(i>=0&&v[i]==0){
			i--;
		}
		if(i==-1){
			return "0";
		}
		string s="";
		for(int j=i;j>=0;j--){
			ostringstream s1;
			s1<<v[j];
			s+=s1.str();
		}
		return s;
	}
	
	
	//  Hash Table Data Structure
	template<typename V> 
	class HashTable{
		private:
			static const int hashGroups=10;
			list< pair<int,V> >table[hashGroups];
		public:
			bool isempty(){
				int sum=0;
				for(int i=0;i<hashGroups;i++){
					sum+=table[i].size();
				}
				if(sum==0){
					return true;
				}
				return false;
			}
			int hashFunction(int key){
				return key%hashGroups;
			}
			void insertItem(int key,V value){
				int hashvalue=hashFunction(key);
				auto& cell=table[hashvalue];
				auto itr = begin(cell);
				bool keyExists=false;
				for(;itr!=end(cell);++itr){
					if(itr->first==key){
						keyExists=true;
						itr->second=value;
						cout<<"[WARNING] Key exists. Value Replaced!"<<endl;
						break;
					}
				}
				if(!keyExists){
					cell.emplace_back(key,value);
				}
				return;
			}
			void removeItem(int key){
				int hashvalue=hashFunction(key);
				auto& cell=table[hashvalue];
				auto itr= begin(cell);
				bool keyExists=false;
				for(;itr!=end(cell);++itr){
					if(itr->first==key){
						keyExists=true;
						itr=cell.erase(itr);
						cout<<"[INFO] item removed!!"<<endl;
						break;
					}
				}
				if(!keyExists){
					cout<<"[WARNING] Key Not Found!!"<<endl;
				}
				return;
			}
			void printTable(){
				for(int i=0;i<hashGroups;i++){
					if(table[i].size()==0) continue;
					auto itr=table[i].begin();
					for(;itr!=table[i].end();++itr){
						cout<<"[INFO] Key: "<<itr->first<<" "<<"Value: "<<itr->second<<"\n";
					}	
				}
				return;
			}
	};
	string big_power(long long a, long long b){
		long long ans=1;
		ostringstream stri,str1;
		stri<<ans;
		str1<<a;
		string s=stri.str(),s1=str1.str(),s2;
		while(b!=0){
			if(b%2!=0){
				s=mul_big_nums(s,s1);
			}
			s1=mul_big_nums(s1,s1);
			b=b/2;
		}
		return s;
	}
}
