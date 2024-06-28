#include "Random.h"

random_device Random::rd;
mt19937_64 Random::gen(rd());

int Random::Range(int minInclusive, int maxExclusive)
{
    uniform_int_distribution<int> dis(minInclusive, maxExclusive - 1);
    return dis(gen);
}

float Random::Range(float minInclusive, float maxInclusive)
{
    uniform_real_distribution<float> dis(minInclusive, maxInclusive);
    return dis(gen);
}