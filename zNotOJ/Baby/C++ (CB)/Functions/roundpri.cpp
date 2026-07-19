#include <bits/stdc++.h>

std::string ToString(int num, int count);
int Reverse(int num);
int Count(int num);

void numsFind(std::string n);
void Sieve(int n);
bool Check(std::string n);


void NumsFind2(int n);
bool Check2(int n);


int n;
int nums[6];
bool prime[1000001];

long long sum = 0;
int count = 0;

int main()
{
    std::cin >> n;


    Sieve(1000001);

    // for (int i = 2; i < std::stoi(n); i++)
    // {
    //     if (Check(ToString(i, Count(i))) == true)
    //     {
    //         count += 1;
    //     }
    // }
    
    // for (int i = 2; i <= n; i++)
    // {
    //     if (prime[i] == true)
    //     {
    //         NumsFind2(i);
            
    //         if (Check2(n) == true)
    //         {
    //             count += 1;
    //             std::cout << i << ' ';
    //         }
    //     }
    // }

    NumsFind2(n);

    std::cout << Check2(n);
   
}

int Count(int num)
{
    int count = 0;

    while (num > 0)
    {
        count += 1;
        num /= 10;
    }

    return count;
}

void NumsFind2(int n)
{
    for (int i = 0; i < n; i++)
    {
        n += std::pow(10, Count(n)) * (n % 10);
        n /= 10;
        nums[i] = n;
    }
}

bool Check2(int n)
{
    for (int i = 0; i < Count(n); i++)
    {
        if (prime[nums[i]] == false)
        {
            return false;
        }
    }

    return true;
}

std::string ToString(int num, int count)
{
	num = Reverse(num);

	std::string str;

	for (int i = 0; i < count; i++)
	{
		str += (char)((int)'0' + (num % 10));
		num /= 10;
	}

	return str;
}

int Reverse(int num)
{
	int reversedNum = 0;

	while (num > 0)
	{
		reversedNum += num % 10;
		reversedNum *= 10;

		num /= 10;
	}

	reversedNum /= 10;

	return reversedNum;
}


bool Check(std::string n)
{
    bool result = true;

    numsFind(n);

    for (int i = 0; i < n.length(); i++)
    {
        // std::cout << nums[i] << '\n';

        if (prime[nums[i]] == false)
        {
            result = false;
            break;
        }
    }   

    return result;
}

void numsFind(std::string n)
{
    for (int i = 0; i < n.length(); i++)
    {
        nums[i] = (int)n[i] - (int)'0'; // lay so dau tien cua so
        
        for(int j = i + 1; j < n.length(); j++) // lay cac chu so sau i
        {
            nums[i] *= 10;
            nums[i] += (int)n[j] - (int)'0';
        }

        for (int j = 0; j < i; j++) // lay cac chu so truoc i
        {
            nums[i] *= 10;
            nums[i] += (int)n[j] - (int)'0';
        }
    }
}

void Sieve(int n)
{
    for (int i = 0; i <= n; i++)
    {
        prime[i] = true;
    }

    prime[0] = prime[1] = false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    
}
