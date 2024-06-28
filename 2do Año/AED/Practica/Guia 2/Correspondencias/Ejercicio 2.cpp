#include <iostream>
#include <map>
#include <list>
using namespace std;
/*2) list2map. Escribir una funci´on que dadas las listas de claves (k1,k2,k3, ...) y valores
(v1,v2,v3, ...) retorna el map M con las asignaciones correspondientes
{ k1->v1, k2->v2, k3->v3, ...}. Utilice la signatura void list2map(map<int,int> &M,
list<int> &Keys, list<int> &Vals). Nota: si hay claves repetidas, s´olo debe quedar la
asignaci´on correspondiente a la ´ultima clave en la lista. Si hay menos valores que claves utilizar
cero como valor. Si hay m´as valores que claves, ignorarlos.*/
void print_map(map<int,int>&M){
	map<int,int>::iterator it=M.begin();
	while(it!=M.end()){
		cout<<it->first<<" -> "<<it->second<<endl;
		it++;
	}
	cout<<endl;
}
void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}
void list2map(map<int,int> &M,list<int> &Keys, list<int> &Vals){
	
	list<int>::iterator itK =Keys.begin();
	list<int>::iterator itV =Vals.begin();
	while(itK!=Keys.end()){
		if(itV!=Vals.end()){
			
			//M= {{1,2} , {3,4} , {5,6}}
			//M[1]=10;
			//M= {{1,10} , {3,4} , {5,6}}
			//M[7]=8
			//M= {{1,10} , {3,4} , {5,6}, {7,8}}
			
			M[*itK]=*itV; //si la llave existe lo reemplaza, si no existe inserta
			++itV;
		}else{
			//hay mas llaves q valores, completamos con ceros
			//M[*itK]=0;
			M.insert({*itK,0});
		}
		++itK;
	}
	
}
int main() {
	
	list<int>K={1,2,3,4,5,12,15,19};
	list<int>V={6,7,8,9,10};
	map<int,int>M;
	
	list2map(M,K,V);
	print_map(M);
	
	
	return 0;
}







