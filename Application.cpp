#include "DsAlgolib.h"
#include<iostream>
using namespace std;
using namespace DsAlgo;
int main(){
	// Linked List implementation
	/*
	linked_list<int> a;
	a.append_at_end(1);
	a.append_at_end(2);
	a.append_at_end(3);
	a.append_at_begin(45);
	a.append_at_n_pos(60,2);
	a.delete_node(45);
	a.print_all_nodes();
	cout<<"\n";
	cout<<"Reversed Linked List: ";
	a.reverse_linked_list();
	cout<<"\n";
	cout<<"sorted Linked List: ";
	a.sort();
	a.print_all_nodes();
	cout<<"\n";
	*/
	
	
	
	// Stack implementation.
	/*
	Stack<int> s;
	s.push(4);
	s.push(2);
	s.push(3);
	cout<<s.pop()<<"\n";
	cout<<s.peek();
	cout<<"\n";
	s.push(8);
	s.push(6);
//	s.print_stack();
//	cout<<"\n";
	s.sortstack("decending");
	s.print_stack();
	cout<<"\n";
	*/
	
	
	
	// Queue implementetion
	/*
	Queue<char> q;
	q.push('d');
	q.push('b');
	q.push('a');
	cout<<q.pop()<<"\n";
	cout<<q.peek();
	cout<<"\n";
	q.push('e');
	q.push('c');
	q.sortqueue("ascending");
	q.print_queue();
	*/
	
	
	
	// Binary Tree implementation
	/*
	BSTree<int> b;
	b.insert(15);
	b.insert(10);
	b.insert(20);
	b.insert(12);
	if(b.search(20)){
		cout<<"Found!!"<<"\n";
	}
	cout<<b.findMin()<<"\n";
	cout<<b.findMax()<<"\n";
	cout<<b.height()<<"\n";
	cout<<b.maxnodes()<<"\n";
	b.bfs();
	cout<<"\n";
	b.preorder();
	cout<<"\n";
	b.inorder();
	cout<<"\n";
	b.postorder();
	cout<<"\n";
	if(b.isBSTree()){
		cout<<"It is Binary Tree!!"<<"\n";
	}
	b.delete_node(10);
	b.insert(13);
	b.insert(9);
	b.inorder();
	cout<<"\n";
	cout<<b.GetSuccesor(9)<<"\n";
	b.invert_BSTree();
	b.inorder();
	*/
	
	
	
	// Depth First Search Implementation (Graphs)
	/*
	Graph g(4);
	//for directed graph we use addedge
	g.addedge(0, 1);
	g.addedge(0, 2); 
    g.addedge(1, 2); 
    g.addedge(2, 0); 
    g.addedge(2, 3); 
    g.addedge(3, 3);
    g.DFS(2);
    //for undirected graph we use add_edge
    */
    // Breadth First Search Implementation (Graphs)
    /*
    Graph g(8);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(0,3);
    g.add_edge(0,4);
    g.add_edge(1,5);
    g.add_edge(2,5);
    g.add_edge(3,6);
    g.add_edge(4,6);
    g.add_edge(5,7);
    g.add_edge(6,7);
    g.BFS(1);
    */
    
    
    
    // Convert String to integer
    //cout<<str_to_int("12345")+1<<"\n";
    
    
    
    
    // To multiply big integers!!
    /*
    string s1="1235421415454545454545454544";
    string s2="1714546546546545454544548544544545";
    cout<<mul_big_nums(s1,s2);
    */
    
    
    /*
	// Find power of large numbers
	cout<<big_power(12345,234)<<endl;
    */
    
    
    // Hash Table implmentation
    /*
    HashTable<string> h;
    h.insertItem(905,"harsha");
    h.insertItem(404,"sunil");
    h.insertItem(123,"sravya");
    h.insertItem(202,"danzo");
    h.insertItem(302,"tingting");
    h.removeItem(302);
    h.printTable();
    if(!h.isempty()){
    	cout<<"Good Job!!"<<endl;
	}
	*/
	
	//Mod- Inverse
//	mod_inverse(3,11);
}
