#include <iostream>
using namespace std;

class Vector {
public:
	Vector(const Vector &ov) {
		this->m_n = ov.m_n;
		this->m_ptr = new int[m_n];
		for(int i=0;i<m_n;++i)
			this->m_ptr[i] = ov.m_ptr[i];
	}
	Vector(int n) {
		m_ptr = new int[n];
		for(int i=0;i<n;++i) m_ptr[i] = 0;
		m_n = n;
	}
	void Cargar(int i, int x) { m_ptr[i] = x; }
	int Ver(int i) { return m_ptr[i]; }
	int Tamanio() { return m_n; }
	~Vector( ) {
		delete [] m_ptr;
	}
private:
		int *m_ptr, m_n;
};

int main() {
	Vector v(5);
	v.Cargar(0,10);
	v.Cargar(1,11);
	v.Cargar(2,12);
	v.Cargar(3,13);
	v.Cargar(4,14);
	
	Vector v2(v);
	v2.Cargar(0,999);
	
	for(int i=0;i<v.Tamanio();++i)
		cout << v.Ver(i) << " ";
	cout << endl;
	
	return 0;
}
