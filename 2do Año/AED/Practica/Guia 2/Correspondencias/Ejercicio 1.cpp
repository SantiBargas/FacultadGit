#include <iostream>
#include <list>
#include <map>
using namespace std;
/*1) map2list. Escribir una funci´on que dado un map M retorna las listas de claves y valores, utilice la
signatura void map2list(map<int,int> &M, list<int> &Keys, list<int> &Vals). Ejemplo:
si M={1->2, 3->5, 8->20}, entonces debe retornar Keys = (1,3,8) y Vals = (2,5,20).*/
void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}
void map2list(map<int,int> &M, list<int> &Keys, list<int> &Vals){
	
	map<int,int>::iterator it=M.begin();
	
	
	while(it!=M.end()){
		
		Keys.push_back(it->first);
		Vals.push_back(it->second);
		it++;
		
		
	}
}
void print_map(map<int,int>&M){
	map<int,int>::iterator it=M.begin();
	while(it!=M.end()){
		cout<<it->first<<" -> "<<it->second<<endl;
		it++;
	}
	cout<<endl;
}
int main() {
	
	map<int,int>M;
	
	list<int>K;
	list<int>V;
	
	M.insert({1,2});
	M.insert({3,5});
	M.insert({8,20});
	M[1]++;
	map2list(M,K,V);
	print_map(M);
	show_list(K);
	show_list(V);
	return 0;
}







