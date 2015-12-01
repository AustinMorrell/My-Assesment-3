////////////////////////////////////////////////////////////////
//Austin Morrell//
//December 1th 2015//
//Templated Vector4//
///////////////////////////////////////////////////////////////

#ifndef _VECTOR4_H_
#define _VECTOR4_H_

template<typename T>
class Vector4
{

public:
	Vector4<T>();
	Vector4<T>(T x, T y, T z, T w);
	~Vector4<T>();
	Vector4 Normalising(Vector4 &a);

	int x;
	int y;
	int z;
	int w;
};
#endif _VECTOR4_H_

template<typename T>
Vector4<T>::Vector4()
{

}

template<typename T>
Vector4<T>::Vector4(T X, T Y, T Z, T W)
{
	x = X;
	y = Y;
	z = Z;
	w = W;
}

template<typename T>
Vector4<T>::~Vector4()
{

}

//Normalising
template<typename T>
Vector4<T> Vector4<T>::Normalising(Vector4 &a)
{
	Vector4 c;
	T A;
	float Thesqrt;
	A = (a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.w * a.w);
	Thesqrt = sqrt(A);
	c.x = (a.x / Thesqrt);
	c.y = (a.y / Thesqrt);
	c.z = (a.z / Thesqrt);
	c.w = (a.w / Thesqrt);
	return c;
}
