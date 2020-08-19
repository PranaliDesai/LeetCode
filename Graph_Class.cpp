#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <stack>
#include <queue>

using namespace std;

class Graph {
	private:
		int graphSize;
		std::vector<int> nodeArray; 
		std::vector<int> edge1Array;
		std::vector<int> edge2Array;
		void addEdge(int node1, int node2);
		void deleteEdge(int node1, int node2);

	public:
		void addNode(int node);
		void addUEdge(int node1, int node2);
		int connectedComponents(void);
		int checkNode(int node);
		int checkEdge(int node1 , int node2);
		void deleteNode(int node);
		void deleteUEdge(int node1, int node2);
		void printNodeList(void);
    		void dfs();
   		void bfs();
		Graph(int size); //Constructor of the class
};



//Constructor
Graph::Graph(int size){
	cout << "Graph object being created with max nodes size:" << size << "\n\n";
	graphSize = size;
	// cout << "Graph object created"<<endl;
}

void Graph::addNode(int node){
	nodeArray.push_back(node);
	cout << "adding node" << endl;
}

void Graph::addEdge(int node1, int node2){
	edge1Array.push_back(node1);
	edge2Array.push_back(node2);
	cout << "adding edge" << node1 << node2 <<"\n";
}
void Graph::addUEdge(int node1, int node2){
	addEdge(node1,node2);
	addEdge(node2,node1);
}

int Graph::checkNode(int node){
	/*
	Checks the node 
	Returns 1 if the node is found 0 otherwise
	*/

	for(int i=0; i< nodeArray.size(); i++){
		if (nodeArray[i] == node){
			cout << "The node exists\n";
			return 1;
		}
	}
	return 0;
}
int Graph::checkEdge(int node1, int node2){
	/*
	Checks the edge (node1,node2)
	Returns 1 if the edge is found 0 otherwise
	*/
	for(int i=0; i< edge1Array.size(); i++){
		if (edge1Array[i] == node1 && edge2Array[i] == node2){
      cout<<"n1"<<edge1Array[i]<<edge2Array[i] <<endl;
			return 1;
		}
	}
	return 0;
}

void Graph::deleteNode(int node){
	/*
	Deletes the node from the nodeArray
	*/
	int out;
	out = checkNode(node);
	if (out ==1 ){
		int count = 0;
		//find the node and delete it
		//Using an iterator to go through the vector
		for (vector<int>::const_iterator i = nodeArray.begin(); i != (nodeArray.end());i++){
			if (*i == node){
				nodeArray.erase(nodeArray.begin() + count);
			}
			count++; 
		}

	}
	else{
	}
}

void Graph::printNodeList(void){
	/*
	Prints the node list
	*/
	for (vector<int>::const_iterator i = nodeArray.begin(); i != (nodeArray.end());i++){
		cout << "Node :" << (*i) <<endl;
	}
}

void Graph::deleteUEdge(int node1, int node2){
	/*
	Delete the edge (node1, node2)
	(node2, node1)
	*/
	deleteEdge(node1,node2);
	deleteEdge(node2,node1);
}

void Graph::deleteEdge(int node1, int node2){
	/*
	Deletes the edge (node1, node2)
	If the edge does not exist, then nothing is done.
	*/

	int out;
	out = checkEdge(node1, node2);
	if (out ==1 ){ //The edge exists

    for(int i =0;i<edge1Array.size();i++){
      if(edge1Array[i]==node1 && edge2Array[i]==node2){
        edge1Array.erase(edge1Array.begin()+i);
        edge2Array.erase(edge2Array.begin()+i);
      }
    }

	}
	else{ //The edge does not exist. Dont do anything.
	}
}

void Graph::dfs(){
  map<int,vector<int>> mp;
  for(int i=0;i<edge1Array.size();i++){
    mp[edge1Array[i]].push_back(edge2Array[i]);
  }
  vector<int> visited(edge1Array.size(),0);
  stack<int> st;
  st.push(0);
  while(!st.empty()){
    int top =st.top();
    visited[top]=1;
    cout<<top<<endl;
    st.pop();
    for(int i = 0;i<mp[top].size();i++){
      //cout<<mp[top][i]<<endl;
      if (visited[mp[top][i]] ==0) st.push(mp[top][i]);
    }
  }
}

void Graph::bfs(){
  map<int,vector<int>> mp;
  for(int i=0;i<edge1Array.size();i++){
    mp[edge1Array[i]].push_back(edge2Array[i]);
  }
  vector<int> visited(edge1Array.size(),0);
  queue<int> st;
  st.push(0);
  while(!st.empty()){
    int top =st.front();
    visited[top]=1;
    cout<<top<<endl;
    st.pop();
    for(int i = 0;i<mp[top].size();i++){
      //cout<<mp[top][i]<<endl;
      if (visited[mp[top][i]] ==0) st.push(mp[top][i]);
    }
  }
}

int Graph::connectedComponents(void ){
	/*
	Computes the connected compoonents of the UNDIRECTED graph
	stores the components in an map :(node, component_number)  
	private data: connected_components
	Suggestion: Maybe this is the update function!
	And we need another function that can access the connected components and give it
	to you
	*/


	//Create an adjacency list
	map< int, vector<int> > adjacency_list;
	int count = 0;
	//Go through the edge list and create the adjacency list
	for (vector<int>::const_iterator i = edge1Array.begin(); i != (edge1Array.end());i++){
		adjacency_list[edge1Array[count]].push_back(edge2Array[count]);
		count++;
	}
	// print the connected components
	// for (map< int , vector<int> >::iterator it = adjacency_list.begin();it != adjacency_list.end();it++){
	// 	vector<int> value_list = it->second;
	// 	for (int i =0;i<value_list.size();i++){
	// 	}
	// }

	
	cout << "\n\nConnected Components\n";
	for (int l=0;l<nodeArray.size();l++){   
		int node = nodeArray[l];
		cout << "node is:" << node << "  connected_component:" << adjacency_list[nodeArray[l]].size() << endl;

	}
	return 1;
}

using namespace std;


int main(){
	int count;
	Graph firstGraph(10);

	firstGraph.addNode(1);
  firstGraph.addNode(0);
	firstGraph.addNode(2);
	firstGraph.addNode(3);
	firstGraph.addNode(4);
  firstGraph.addNode(9);
	// firstGraph.addNode(6);
	// firstGraph.addNode(7);
	// firstGraph.addNode(8);
	// firstGraph.addNode(9);
	firstGraph.addNode(10);
	// firstGraph.addNode(11);
  firstGraph.addUEdge(0,1);
	firstGraph.addUEdge(0,2);
	firstGraph.addUEdge(0,3);
	firstGraph.addUEdge(0,4);
  firstGraph.addUEdge(4,9);
  firstGraph.addUEdge(4,10);
	//firstGraph.addUEdge(2,5);
	// firstGraph.addUEdge(6,7);
	// firstGraph.addUEdge(7,8);
	// // firstGraph.addUEdge(8,9);
	// firstGraph.addUEdge(9,10);
	// firstGraph.addUEdge(10,11);


	// firstGraph.addUEdge(3,4);

	// firstGraph.deleteEdge(1,3);
	//firstGraph.deleteUEdge(1,100);
	//firstGraph.checkNode(1);

	// firstGraph.checkNode(2);
	// firstGraph.checkEdge(1,2);
	// firstGraph.checkEdge(1,3);
	// firstGraph.checkEdge(2,4);

	// firstGraph.deleteNode(1);
	// firstGraph.checkNode(1);
	// firstGraph.printNodeList();
	// firstGraph.deleteNode(100);
	cout << "\n\n\nDONE!!!"<<endl;

	count = firstGraph.connectedComponents();
  firstGraph.dfs();
  firstGraph.bfs();
    return 0;
}
