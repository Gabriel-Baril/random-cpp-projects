using System;

namespace TestCSharp2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(factorial_recursive(5));
            Console.WriteLine(factorial_iterative(5));
            Console.WriteLine(imul(4, 5));
        }

        static long factorial_recursive(int n)
        {
            if (n <= 1)
                return 1;
            return n * factorial_recursive(n - 1);
        }

        static long factorial_iterative(int n)
        {
            long fact = 1;
            for (int i = 2;i <= n;i++)
                fact *= i;
            return fact;
        }
        
        static int max(int a, int b)
        {
            if (a >= b)
                return a;
            return b;
        }

        static int min(int a, int b)
        {
            if (a <= b)
                return a;
            return b;
        }

        static int imul(int a, int b)
        {
            int result = 0;
            int min_val = min(a, b);
            int max_val = max(a, b);

            for (int i = 0; i < min_val; i++)
                result += max_val;
            return result;
        }
    }
}
