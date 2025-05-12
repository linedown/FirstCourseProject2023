#include "operator.h"
#include "new_vector.h"
#include "network.h"
#include <iostream>
#include <ctime>

using namespace std;

bool testirovanie_sledovaniya(bool a, bool b, bool c) {
	return a s(c s(b s a) s c s b) s(b s c) s ((b s a) s a s(b s c) s b) s (a s c) s b;
}

bool testirovanie_equal_sledovaniya(bool a, bool b, bool c) {
	return !a || !(!c || !(!b || a) || !c || b) || !(!b || c) || !((!b || a) || !a || !(!b || c) || !b) || !(!a || c) || b;
}

void pushelements(new_vector<int> *vec, int j) {
	for (int i = 0; i <= j; i++) {
		vec->push_back_vector(i);
		cout << i << "\n";
	}
}

int main() {
	setlocale(LC_ALL, "russian");
	new_vector<int>* test_1 = new new_vector<int>;
	pushelements(test_1, 500);
	cout << test_1->size_volume() << " " << test_1->size_vector();
	return 0;

}