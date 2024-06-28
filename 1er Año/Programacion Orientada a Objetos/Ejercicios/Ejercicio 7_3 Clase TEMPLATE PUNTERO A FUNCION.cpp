#include <iostream>
#include <vector>
using namespace std;

template<typename T>class Vector{
private:
	Vector(const Vector &v);///< privado para que no se pueda copiar, porque tiene punteros
	Vector&operator=(const Vector &v); ///< privado para que no se pueda copiar, porque tiene punteros
	//estos dos es para que no se haga un delete dos veces
	
	int m_tamanio;
	T *m_p;
public:
	
	template<typename PF>
	Vector(int n, PF f):m_tamanio(n),m_p(new T[n]){ //PF seria un puntero a una funcion de un tipo
		for(int i=0;i<n;i++) { 
			m_p[i]=f();
		}
	}
	
	
	T &operator[](int i){return m_p[i];}
	int size(){return m_tamanio;} 
	~Vector(){delete []m_p;}
};

template<typename T> void mostrar(Vector<T> &v){
	for(int i=0;i<v.size();i++) { 
		cout<<v[i]<<"    ";
	}
	cout<<endl;
}
float frand(){
	return (rand()%1001/1000.0);
}	
string str_rand(){
	string s(5+rand()%6,' ');
	for(char &c : s)
		c='a'+rand()%('z'-'a'+1);
	return s;
}
int main() {
	
	Vector<float> v(3,frand);
	Vector<int> vi(3,rand);
	Vector<string> vs(3,str_rand);
	
	mostrar(v);
	mostrar(vi);
	mostrar(vs);
	
	return 0;
}

