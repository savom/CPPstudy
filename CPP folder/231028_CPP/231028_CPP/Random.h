#pragma once
#include <random>
using namespace std;

class Random
{
private:
	static random_device rd;
	static mt19937_64 gen;

public:
	static int Range(int minInclusive, int maxExclusive);
	static float Range(float minInclusive, float maxInclusive);
};