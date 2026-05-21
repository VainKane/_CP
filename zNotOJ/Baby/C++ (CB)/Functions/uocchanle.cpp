#include <bits/stdc++.h>

// int Count(long long n);
short int FastCount(long long &n);
// void Sieve();

std::string Check(long long &n);


// bool prime[50000001];
// int primeNums[50000001];

short int times;
long long num;
// int count = 0;

int main()
{
    // Sieve();

    std::cin >> times;

    for (int i = 0; i < times; i++)
    {
        std::cin >> num;

        std::cout << Check(num) << '\n';
    }


}

// int Count(long long n)
// {
//     int count = 0;

//     for (long long i = 1; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             if (i != sqrt(n))
//             {
//                 count += 2;
//             }
//             else
//             {
//                 count += 1;
//             }
//         }
//     }
    
//     return count;
// }


std::string Check(long long &n)
{
    std::string result = "CHAN";

    if ((long long)sqrt(n) * (int)sqrt(n) == n)
    {
        result = "LE";
    }

    return result;
}

short int FastCount(long long &n)
{
    short int result = 1;
    short int soMu;

    for (int i = 2; i <= sqrt(n); i++)
    {
        soMu = 0;

        while (n % i == 0)
        {
            soMu += 1;
            n /= i; // => i chac chan nguyen to
        }

        result *= soMu + 1;
    }
    
    if (n != 1)
    {
        result *= 2; // vi khi n la thua so nt cuoi cung thi no ko co uoc i nen khong duoc tinh o phan tren
    }
    
    // if (n != 1)
    // {
    //     for (int primeNum : primeNums)
    //     {
    //         if (primeNum > n)
    //         {
    //             break;
    //         }
    //         else
    //         {
    //             soMu = 0;

    //             while (n % primeNum == 0)
    //             {
    //                 soMu += 1;
    //                 n /= primeNum;
    //             }

    //             result *= soMu + 1;
    //         }
    //     }
    // }
    // else
    // {
    //     result = 1;
    // }

    return result;
}

// void Sieve()
// {
//     for (int i = 0; i < 50000001; i++)
//     {
//         prime[i] = true;
//     }

//     prime[0] = prime[1] = false;

//     for (int i = 2; i <= 7071; i++)
//     {
//         for (int j = i * i; j <= 50000000; j += i)
//         {
//             prime[j] = false;
//         }
//     }

//     for (int i = 2; i <= 50000000; i++)
//     {
//         if (prime[i] == true)
//         {
//             primeNums[count] = i;
//             count += 1;
//         }
//     }
// }

