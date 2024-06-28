#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template<typename T> void maxmin(vector<T>&v){
	
	T max=*max_element(v.begin(),v.end());
	T min=*min_element(v.begin(),v.end());
	auto it=remove(v.begin(),v.end(),max);
	v.erase(it,v.end());
	auto it2=remove(v.begin(),v.end(),min);
	v.erase(it2,v.end());
}

int main() {
	vector<int>v{10,2,3,6,10,10,1,5,1,7};
	cout<<"Vector original: "<<endl;
	for(int x:v)cout<<x<<"   ";
	cout<<endl;
	
	maxmin(v);
	cout<<"Vector sin min y max elemento: "<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<"  ";
	}
	
	return 0;
}

