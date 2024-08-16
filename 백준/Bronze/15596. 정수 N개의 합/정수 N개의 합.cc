#include <vector>
#include <bits/stdc++.h>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    for (auto itr : a) ans += itr;
	return ans;
}
