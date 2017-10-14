// proj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

template<class T, const int W>
struct AverageCalc : public vector<T> {
	double sum;
	AverageCalc() : sum(0) {}
	AverageCalc & insert(const T & t) {
		push_back(t);
		sum += t;

		return *this;
	}
	double operator()() {
		return sum / size();
	}
};

template<class T, const int W>
struct MovingAverageCalc: public AverageCalc<T, W> {
	MovingAverageCalc & insert(const T & t) {
		if (size() == W) {
			sum -= *(begin());
			erase(begin());
		}
		push_back(t);
		sum += t;

		return *this;
	}
};




int main()
{
	MovingAverageCalc<int, 3> movcalc;
	movcalc.insert(1).insert(2).insert(3).insert(4).insert(4);
	cout << movcalc() << endl;
	AverageCalc<int, 3> avgcalc;
	avgcalc.insert(1).insert(2).insert(3).insert(4).insert(4);
	cout << avgcalc() << endl;
	system("pause");
    return 0;
}

