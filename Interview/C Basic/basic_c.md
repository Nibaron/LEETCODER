
# Find the largest number among the three numbers.


> My Code

```cpp

// C Program to find
// Largest of three numbers
#include  <stdio.h>

int  main()
{

int a = 1, b = 2, c = 3;
// condition for a is greatest
if (a > b && a > c) printf("%d", a);

// condition for b is greatest
else  if (b > a && b > c) printf("%d", b);

// remaining conditions
// c is greatest
else printf("%d", c);
  
return  0;

}

  

```

# Write a Program to check whether a number is prime or not.

>My Code

```cpp
// C Program for 
// Checking value is 
// Prime or not 
#include <stdio.h> 
  
int main() 
{ 
    int N = 91; 
    int flag = 0; 
  
    // Iterate from 2 to N/2 
    for (int i = 2; i <= N / 2; i++) { 
  
        // If n is divisible by any number between 2 and 
        // n/2, it is not prime 
        if (N % i == 0) { 
            flag = 1; 
            break; 
        } 
    } 
  
    if (flag == 0) 
        printf("Not a Prime Number"); 
    else
        printf("Is a Prime Number"); 
    return 0; 
}
```

# Prime between a Range


> Basic Code
```cpp
// C++ program to find the prime numbers
// between a given interval

#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Declare the variables
	int a, b, i, j, flag;

	// Ask user to enter lower value of interval
	cout << "Enter lower bound of the interval: ";
	cin >> a; // Take input

	// Ask user to enter upper value of interval
	cout << "\nEnter upper bound of the interval: ";
	cin >> b; // Take input

	// Print display message
	cout << "\nPrime numbers between "
		<< a << " and " << b << " are: ";

	// Traverse each number in the interval
	// with the help of for loop
	for (i = a; i <= b; i++) {
		// Skip 0 and 1 as they are
		// neither prime nor composite
		if (i == 1 || i == 0)
			continue;

		// flag variable to tell
		// if i is prime or not
		flag = 1;

		for (j = 2; j <= i / 2; ++j) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}

		// flag = 1 means i is prime
		// and flag = 0 means i is not prime
		if (flag == 1)
			cout << i << " ";
	}

	return 0;
}

// This code is contributed by Akanksha Rai
```

> skip the even numbers
```cpp
// C++ program to find the prime numbers
// between a given interval

#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Declare the variables
	int a, b, i, j;

	// Ask user to enter lower value of interval 
	// interval < 0 cannot be prime numbers
	cout << "Enter lower bound of the interval: ";
	cin >> a; // Take input

	// Ask user to enter upper value of interval
	cout << "\nEnter upper bound of the interval: ";
	cin >> b; // Take input

	// Print display message
	cout << "\nPrime numbers between " << a << " and " << b
		<< " are: ";

	// Explicitly handling the cases when a is less than 2
	// since 0 and 1 are not prime numbers
	if (a <= 2) {
		a = 2;
		if (b >= 2) {
			cout << a << " ";
			a++;
		}
	}

	// MAKING SURE THAT a IS ODD BEFORE WE BEGIN
	// THE LOOP
	if (a % 2 == 0)
		a++;

	// NOTE : WE TRAVERSE THROUGH ODD NUMBERS ONLY
	for (i = a; i <= b; i = i + 2) {

		// flag variable to tell
		// if i is prime or not
		bool flag = 1;

		// WE TRAVERSE TILL SQUARE ROOT OF j only.
		// (LARGEST POSSIBLE VALUE OF A PRIME FACTOR)
		for (j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}

		// flag = 1 means i is prime
		// and flag = 0 means i is not prime
	
		if (flag == 1){
		if(i==1)
			continue;
		else
			cout << i << " ";
		} 
	}

	return 0;
}

```

> Sieve Algorithm
```cpp
// C++ program to find the prime numbers
// between a given interval using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int srt, int n)
{
	// Create a boolean array "prime[srt to n]" and
	// initialize all entries it as true. A value in
	// prime[i] will finally be false if i is Not a prime,
	// else true.
	bool prime[n + 2];
	memset(prime, true, sizeof(prime));
	prime[0] = false;
	prime[1] = false;

	for (int p = 2; p * p <= n; p++) {
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true) {
			// Update all multiples of p greater than or
			// equal to the square of it numbers which are
			// multiple of p and are less than p^2 are
			// already been marked.
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers
	for (int p = srt; p <= n; p++)
		if (prime[p])
			cout << p << " ";
}

// Driver Code
int main()
{
	int srt = 1;
	int end = 10;
	SieveOfEratosthenes(srt, end);
	return 0;
}

// This code is contributed by Susobhan Akhuli

```

# Write a Program to Replace all 0’s with 1’s in a Number.

>My Code

```cpp
// C Program for 
// Replacing 0 to 1 
#include <math.h> 
#include <stdio.h> 

int main() 
{ 
	int N = 102301; 

	int ans = 0; 
	while (N != 0) { 
		// Condition to change value 
		int last_digit = N % 10;
		if (last_digit == 0) 
			ans = ans*10  + 1; 
		else
			ans = ans*10 + last_digit; 

		N = N / 10; 
	} 

	printf("%d", ans); 

	return 0; 
}
```

# Write a Program to convert the binary number into a decimal number.

>My Code

```cpp
// C Program for converting 
// binary to decimal 
#include <stdio.h> 

int main() 
{ 
	int N = 1101; 

	// Initializing base value a to 1 
	int a = 1; 
	int ans = 0; 
	while (N != 0) 
	{ 
		if( N%10 == 1) ans = ans + a;
		
		N = N / 10; 
		a = a * 2; 
	} 

	printf("%d", ans); 
	return 0; 
}
```

# Write a Program to check if the year is a leap year or not.

>My Code

```cpp
// C Program to check 
// Year is leap year or not 
#include <stdio.h> 

// Function Declaration to check leap year 
void leap_year(int year) 
{ 
	// If a year is multiple of 400, then leap year 
	if (year % 400 == 0) 
		printf("%d is a leap year.\n", year); 

	// If a year is multiple of 100, then not a leap year 
	else if (year % 100 == 0) 
		printf("%d is not a leap year.\n", year); 

	// If a year is multiple of 4, then leap year 
	else if (year % 4 == 0) 
		printf("%d is a leap year.\n", year); 

	// Not leap year 
	else
		printf("%d is not a leap year.\n", year); 
} 

int main() 
{ 
	leap_year(2000); 
	leap_year(2002); 
	leap_year(2008); 

	return 0; 
}

```
# Write a program to Factorial of a Number.

>My Code

```cpp
// C Program to calculate 
// Factorial of a number 
#include <stdio.h> 

// Calculating factorial using iteration 
void factorial_iteration(int N) 
{ 
	unsigned long long int ans = 1; 
	for (int i = 1; i <= N; i++) { 
		ans = ans * i; 
	} 

	printf("Factorial of %d is %lld\n", N, ans); 
} 

// Calculating factorial using recursion 
int factorial(int N) 
{ 
	if (N == 0) 
		return 1; 

	// Recursive call 
	return N * factorial(N - 1); 
} 

int main() 
{ 
	int n; 
	n = 13; 
	factorial_iteration(n); 

	n = 9; 
	printf("Factorial of %d using recursion:%d\n", n, 
		factorial(n)); 

	return 0; 
}

```

# Write a Program to reverse a number.

>My Code

```cpp
// C Programs to Calculate 
// reverse of a number 
#include <stdio.h> 

// Iterative approach 
int reverse_iteration(int N) 
{ 
	int ans = 0; 
	while (N != 0) { 

		ans = ans * 10 + (N % 10); 
		N = N / 10; 
	} 

	return ans; 
} 

// recursive approach 
int reverse(int n, int ans) 
{ 
	if (n == 0) 
		return ans; 

	ans = ans * 10 + n % 10; 
	return reverse(n / 10, ans); 
} 

int main() 
{ 
	int N = 15942; 
	printf("Initial number:%d\n", N); 

	N = reverse_iteration(N); 
	printf("%d after reverse using iteration\n", N); 

	int ans = 0; 
	ans = reverse(N, ans); 
	printf("%d after again reverse using recursion", ans); 

	return 0; 
}

```

# Check whether a number is a palindrome. 

>My Code

```cpp
// C Program for 
// Checking Palindrome 
#include <stdio.h> 

// Checking if the number is 
// Palindrome number 
void check_palindrome(int N) 
{ 
	int T = N; 
	int rev = 0; // This variable stored reversed digit 

	// Execute a while loop to reverse digits of given 
	// number 
	while (T != 0) { 
		rev = rev * 10 + T % 10; 
		T = T / 10; 
	} 

	// Compare original_number with reversed number 
	if (rev == N) 
		printf("%d is palindrome\n", N); 
	else
		printf("%d is not a palindrome\n", N); 
} 

int main() 
{ 
	int N = 13431; 
	int M = 12345; 

	// Function call 
	check_palindrome(N); 
	check_palindrome(M); 

	return 0; 
}

```

# Write a C Program to check if two numbers are equal without using the bitwise operator. 

>My Code

```cpp
// C Program for checking numbers 
// are equal using bitwise operator 
#include <stdio.h> 

int main() 
{ 
	int x = 1; 
	int y = 2; 

	// Using XOR 
	// XOR of two equal numbers is 0 
	if (!(x ^ y)) 
		printf(" %d is equal to %d ", x, y); 
	else
		printf(" %d is not equal to %d ", x, y); 

	return 0; 
}

```

# Write a  C program to find the LCM of two numbers.

>My Code

```cpp
#include <stdio.h>

int GCD(int a, int b)
{
    if (a == 0) return b;
    return GCD(b % a, a);
}

int LCM(int a, int b) 
{
    if (a == 0 || b == 0)
        return 0;
    
    // a * b = gcd(a,b) * lcm(a,b)
    return (a / GCD(a, b)) * b;
}

int main() 
{
    // Given N & M 
    int N = 12, M = 9;

    // Function Call 
    int ans = LCM(N, M);

    printf("%d\n", ans);

    return 0; 
}

```

# Write a C Program to find the Maximum and minimum of two numbers without using any loop or condition. 

>My Code

```cpp
// C Program to check 
// Maximum and Minimum 
// Between two numbers 
// Without any condition or loop 
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
	int a = 55, b = 23; 

	// return maximum among the two numbers 
	printf("max = %d\n", ((a + b) + abs(a - b)) / 2); 

	// return minimum among the two numbers 
	printf("min = %d", ((a + b) - abs(a - b)) / 2); 

	return 0; 
}

```

# Write a Program in C to Print all natural numbers up to N without using a semi-colon.

>My Code

```cpp
#include <stdio.h>

int N = 10;

void recursivePrint(int val) 
{
    if (val <= N && printf("%d ", val) && recursivePrint(val + 1))
    {
        // This block is intentionally left empty.
    }
}

int main() 
{
    recursivePrint(1);
    return 0;
}

```

# Write a Program to sort First half in Ascending order and the Second in Descending order. 

>My Code

```cpp
#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(std::vector<int>& arr, int start, int end) {
    for (int i = start; i < end; ++i) {
        for (int j = start; j < end - i + start - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void reverseArray(std::vector<int>& arr, int start, int end) {
    while (start < end) {
        std::swap(arr[start], arr[end]);
        ++start;
        --end;
    }
}

int main() {
    // Example array
    std::vector<int> arr = {5, 2, 9, 1, 5, 6, 7, 3, 8, 0};

    // Calculate the midpoint
    int n = arr.size();
    int midpoint = n / 2;

    // Sort the entire array in ascending order
    bubbleSort(arr, 0, n);

    // Reverse the second half of the array
    reverseArray(arr, midpoint, n - 1);

    // Print the result
    std::cout << "Array after sorting first half in ascending order and second half in descending order:" << std::endl;
    printArray(arr);

    return 0;
}

```

# Write a program to count the sum of numbers in a string. 

>My Code

```cpp
#include <stdio.h> 

int main() 
{ 

	char s[] = "124259"; 

	int ans = 0; 
	// iterate through all the number 
	for (int i = 0; s[i] != '\0'; i++) { 
		int num = s[i] - '0'; 
		ans += num;
	} 
	
	// print sum of the numbers 
	printf("%d", ans); 

	return 0; 
}


#include <stdio.h>
#include <string.h>

int main() 
{ 

	char s[] = "124259"; 
	

	int ans = 0; 
	// iterate through all the number 
	for (int i = 0; i<strlen(s); i++) { 
		int num = s[i] - '0'; 
		ans += num;
	} 
	
	// print sum of the numbers 
	printf("%d", ans); 

	return 0; 
}
```

# Write a program to calculate the Power of a Number using Recursion in C. 

>My Code

```cpp
// C program to calculate the Power of a Number using 
// Recursion 
#include <stdio.h> 

int power(int a, int b) 
{ 
	if (b == 0) return 1; 

	return a * power(a, b - 1); 
} 

int main() 
{ 
	int a = 4, b = 5; 

	int ans = power(a, b); 

	printf("%d", ans); 
	return 0; 
}

```

# Write a Code to print the Fibonacci series using recursion. 

>My Code

```cpp
/ C Program to illustrate 
// Fibonacci Series using Recursion 
#include <stdio.h> 

int fibonacci(int n) 
{ 
	if (n <= 1) 
		return n; 
	return fibonacci(n - 1) + fibonacci(n - 2); 
} 

int fibonacci_iteration(int n) 
{ 
	if (n <= 1) 
		return 1; 

	int arr[n + 1]; 
	arr[0] = 1; 
	arr[1] = 1; 
	printf("%d %d", arr[0],arr[1]);

	for (int i = 2; i <= n; i++) 
	{
	    arr[i] = arr[i - 1] + arr[i - 2];
	    printf(" %d" , arr[i]);
	}
	

	return arr[n]; 
} 

int main() 
{ 
	int n = 9; 
	printf("Fibonacci using recursion of %d:%d\n", n, 
		fibonacci(n)); 

	n = 11; 
	printf("\nFibonacci using iteration of %d:%d", n, 
		fibonacci_iteration(n)); 
	return 0; 
}



```

