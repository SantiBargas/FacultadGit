#include <iostream>
using namespace std;


class Vector3D{
private:
	float m_x, m_y, m_z;  
public:
	Vector3D(float x,float y, float z):m_x(x),m_y(y),m_z(z){}
	float VerX(){return m_x;}
	float VerY(){return m_y;}
	float VerZ(){return m_z;}
	float & operator [] (float i) { ///para modificar
		if(i == 0) 	return m_x;
		if(i == 1)	return m_y;
			else	return m_z;
	}
	float operator [] (float i) const{ ///para leer
		if(i == 0) 	return m_x;
		if(i == 1)	return m_y;
			else	return m_z;
	}
	bool operator == (const Vector3D &B){
		return this->m_x == B.m_x && this->m_y == B.m_y and this->m_z == B.m_z;
	}
};

Vector3D operator+(Vector3D a, Vector3D b){
	
	float v1=(a.VerX()+b.VerX());
	float v2=(a.VerY()+b.VerY());
	float	v3=(a.VerZ()+b.VerZ());
	
	Vector3D p(v1,v2,v3);
	return p;
}
Vector3D operator*(Vector3D a, Vector3D b){
	
	float v1=(a.VerX()*b.VerX());
	float v2=(a.VerY()*b.VerY());
	float	v3=(a.VerZ()*b.VerZ());
	
	Vector3D p(v1,v2,v3);
	return p;
}
Vector3D operator-(Vector3D a, Vector3D b){
	
	float v1=(a.VerX()-b.VerX());
	float v2=(a.VerY()-b.VerY());
	float	v3=(a.VerZ()-b.VerZ());
	
	Vector3D p(v1,v2,v3);
	return p;
}

int main() {
	
	Vector3D a(2,5,7);
	Vector3D b(2,5,7);
	cout<<"VECTOR 1: "<<endl;
	cout<<"("<<a.VerX()<<"  "<<a.VerY()<<"  "<<a.VerZ()<<")"<<endl;
	cout<<"VECTOR 2: "<<endl;
	cout<<"("<<b.VerX()<<"  "<<b.VerY()<<"  "<<b.VerZ()<<")"<<endl<<endl<<endl;
	
	Vector3D p=a+b;
	cout<<"LA SUMA ES: "<<endl;
	cout<<"("<<p.VerX()<<"  "<<p.VerY()<<"  "<<p.VerZ()<<")"<<endl<<endl;
	p=a*b;
	cout<<"LA MULTIPLICACION ES: "<<endl;
	cout<<"("<<p.VerX()<<"  "<<p.VerY()<<"  "<<p.VerZ()<<")"<<endl<<endl;
	p=a-b;
	cout<<"LA RESTA ES: "<<endl;
	cout<<"("<<p.VerX()<<"  "<<p.VerY()<<"  "<<p.VerZ()<<")"<<endl;
	
	
	return 0;
}

