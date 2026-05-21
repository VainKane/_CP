#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	unsigned int usage;
	int cost;

	cin >> usage;

	if (usage <= 100)
	{
		cost = 2000 * usage;
	}
	else if (usage >= 101 && usage <= 200)
	{
		cost = (usage - 100) * 3000 + 100 * 2000;
	}
	else if (usage >= 201 && usage <= 300)
	{
		cost = (usage - 200) * 5000 + 100 * 5000;
	}
	else
	{
		cost = (usage - 300) * 10000 + 100 * 10000;
	}

	cout << cost;
}