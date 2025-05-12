#pragma once
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class new_vector final {
    T* massive;
    int volume;
    int elements;

public:
    new_vector();
    ~new_vector();

    void push_back_vector(T znachenie);
    void push_in_index(T znachenie, int index);
    T poluchenie_po_indexu(int index);
    void pop_back_vector();
    int size_vector();
    int size_volume();
    bool empty_vector();
    bool operator == (const new_vector<T>& new_v);
    bool operator != (const new_vector<T>& new_v);
    friend ostream& operator << <T>(ostream& vyvod, const new_vector<T>& new_v);
    T& operator[](int index);
};

template <class T>
T& new_vector<T>::operator[](int index) {
    assert(index >= 0 && index < elements);

    return massive[index];
}

template <class T>
new_vector<T>::new_vector() {
    massive = new T[1];
    volume = 1;
    elements = 0;
}

template <class T>
new_vector<T>::~new_vector() {
    delete[] massive;
}

template <class T>
bool new_vector<T>::empty_vector() {
    if (elements == 0) {
        return true;
    }

    else {
        return false;
    }
}

template <class T>
void new_vector<T>::push_back_vector(T znachenie) {
    if (elements == volume) {
        T* new_massive = new T[2 * volume];

        for (int i = 0; i < volume; i++) {
            new_massive[i] = massive[i];
        }

        delete[] massive;

        volume *= 2;
        massive = new_massive;
    }

    massive[elements] = znachenie;
    elements++;
}

template <class T>
void new_vector<T>::push_in_index(T znachenie, int index) {
    if (index == volume) {
        push_back_vector(znachenie);
    }

    else {
        massive[index] = znachenie;
    }
}

template <class T>
T new_vector<T>::poluchenie_po_indexu(int index) {
    if (index < elements) {
        return massive[index];
    }
}

template <class T>
void new_vector<T>::pop_back_vector() {
    elements--;
}

template <class T>
int new_vector<T>::size_vector() {
    return elements;
}

template <class T>
int new_vector<T>::size_volume() {
    return volume;
}

template <class T>
bool new_vector<T>::operator == (const new_vector<T>& new_v) {
    if (this->elements != new_v.elements) {
        return false;
    }

    for (size_t i = 0; i < this->elements; i++) {
        if (this->massive[i] != new_v.massive[i]) {
            return false;
        }
    }

    return true;
}

template <class T>
bool new_vector<T>::operator != (const new_vector<T>& new_v) {
    return !(this->operator==(new_v));
}

template <class T9>
ostream& operator <<(ostream& vyvod, const new_vector<T9>& new_v) {
    for (int i = 0; i < new_v.elements; i++) {
        vyvod << new_v.massive[i] << " ";
    }

    return vyvod;
}
