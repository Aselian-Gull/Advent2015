
#include <iostream>
#include <vector>
#include <stdint.h>

int main() {
	std::cout << "Here comes the brute squad!" << std::endl;
	std::vector<int> sizes;
	int val;
	while(!(std::cin >> val).fail())
	    sizes.push_back(val);

	unsigned int count =sizes.size();
	uint32_t max = 1 << count;
	int valid = 0; uint32_t maxtot = 150;
	std::vector<int> fillcounts(count, 0);

	for(uint32_t i = 0; i < max; i++)
	{
	    uint32_t total = 0;
	    int filled = 0;
	    for(unsigned int j = 0; j < count; j++)
	    {
	        if(i & (1 << j))
	        {
	            total += sizes[j];
	            filled++;
	        }
	        if(total > maxtot)
	            j = count;
	    }
	    if(total == maxtot)
	    {
	        valid++;
	        fillcounts[filled]++;
	    }
	}
	std::cout << count << " jugs, " << valid << " combos." << std::endl;
	for(int i = 0; i < count; i++)
	    std::cout << i << ": " << fillcounts[i] << std::endl;

	return 0;


}
