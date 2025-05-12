#pragma once
#include <iostream>

#define s <sledovanie>

using namespace std;

template<class T, class new_operator>
struct Left_side {
	T left;
};

enum { sledovanie };

template<class T>
Left_side<T, decltype(sledovanie)> operator<(const T& levaya, decltype(sledovanie))
{
	return { levaya };
}

template<class T1, class T2>
bool operator>(Left_side<T1, decltype(sledovanie)> levaya, T2 right_part)
{
	T1& left_part = levaya.left;
	return (!left_part || right_part); // реализация оператора
}