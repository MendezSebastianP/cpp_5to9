#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;
	std::vector<int> c;

    // a C‐array of the values you want
    int nums[] = { 11, 2, 17, 0, 16, 8 };

	c.insert(c.end(), nums, nums + sizeof(nums)/sizeof(*nums));
    // bulk‐insert at the end:
    v.insert(v.end(),4);
    v.insert(v.begin(), c.begin(), c.end());

    // print it to verify
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << ' ';
    std::cout << '\n';
}
