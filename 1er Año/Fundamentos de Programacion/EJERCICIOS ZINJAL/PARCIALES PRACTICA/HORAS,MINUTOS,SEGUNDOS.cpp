#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct datatime{
	int hh;
	int mm;
	int ss;
};

tuple<int,int,int,int> dif_time(vector<datatime>lista);

int main() {
	
	vector<datatime>lista(2);
	
	for(int i=0;i<lista.size();i++){
		cout<<"ingrese horas minutos y segundos"<<endl;
		cin>>lista[i].hh>>lista[i].mm>>lista[i].ss;
	}
	int dif,hora,min,seg;
	tie(dif,hora,min,seg)=dif_time(lista);
	cout<<"La diferencia es de"<<endl<<" horas: "<<hora<<" minutos: "<<min<<" segundos "<<seg;
	
	return 0;
}

tuple<int,int,int,int> dif_time(vector<datatime>lista){
	int dif,hora,min,seg;
	int total1,total2;
	total1=((lista[0].hh*60)*60)+(lista[0].mm*60)+lista[0].ss;
	total2=((lista[1].hh*60)*60)+(lista[1].mm*60)+lista[1].ss;
	
	dif=total1-total2;
	
	hora=dif/3600;
	dif=dif%3600;
	min=dif/60;
	seg=dif%60;
	
	return make_tuple(dif,hora,min,seg);
	
}
