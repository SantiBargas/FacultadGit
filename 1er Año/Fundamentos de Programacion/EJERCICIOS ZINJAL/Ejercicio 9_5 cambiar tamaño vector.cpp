#include <iostream>
#include <vector>
using namespace std;
void eliminar(vector<int> &v, int pos);
int buscar(const vector<int> &v,int x);
int main() {
	int N;
	cin>>N;
	vector<int> v;
	
	for(int i=0;i<N;i++){
		cin>> v[i];
	}
	
	int pos= buscar(v,523);
	if (pos!=-1) eliminar(v,pos);
	
	for(int i=0;i<N;i++){
		cout<<v[i]<<endl;
	}
	return 0;
}

int buscar(const vector<int> &v,int x){
	
	for( int i=0;i<v.size();i++){
		if(v[i]==x){
			return i;
		}
	}
	return -1;
	
}

void eliminar(vector<int> &v, int pos){
	for(int i=pos+1; i<v.size();i++){
		v[i-1]=v[i];
	}
	v.resize(v.size()-1);
	
}
