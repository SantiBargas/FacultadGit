#include <iostream>
using namespace std;

/*13) maxSubList. Programar una funci´on list<int> max_sublist(list<int> &L) la cual reciba una lista de enteros y encuentre y retorne 
la sublista Lmax que obtenga la mayor suma entre todos sus elementos. Notar que debido a que algunos elementos pueden ser negativos el problema no se
resuelve simplemente tomando todos los elementos. Tambi´en es posible que la sublista resultado
no contenga ning´un elemento, en el caso de que todos los elementos de L sean negativos. Si hay
varias sublistas que den la misma suma, debe retornar la que comience primero y sea m´as corta.
Por ejemplo: [1,2,-5,4,-3,2]->[4], [5,-3,-5,1,7,-2]->[1,7], [4,-3,11,-2]->[4,-3,11].*/


void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}


list<int> max_sublist_Geronimo(list<int> &L) {
	list<int> Lmax;
	int sum = 0, maxSum = 0;
	
	list<int>::iterator beginLmax = L.begin(), endLmax = L.end();
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) {
		for( list<int>::iterator it2=it; it2!=L.end(); ++it2 ) {
			sum += *it2;
			if (maxSum < sum) {
				endLmax = it2;
				beginLmax = it;
				maxSum = sum;
			}
		}
		
		sum = 0;
	}
	
	if (maxSum > 0) {
		Lmax.assign(beginLmax, ++endLmax);
	}
	
	return Lmax;
}


list<int>max_sublist2(list<int>&Ñ){
	int suma_maxima =0;
	list<int>Lmax;
	
	for(list<int>::iterator it1=L.begin();it1!L.end();it1++){
		int suma_parcial=0;
		for(list<int>::iterator it2=it1;it2!L.end();it2++){
			suma_parcial+=*it2;
			if(suma_parcial>suma_maxima){
				suma_maxima=suma_parcial;
				Lmax.clear();
				Lmax.insert(Lmax.begin(),it1,next(it2));
			}
		}
	}
	
	return list<int>(itIni,itFin);
}

int main() {
	
	return 0;
}

