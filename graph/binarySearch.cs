using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace binarySearch
{
    class BinarySearch
    {
        static void Main(string[] args)
        {
            int N, K;
            string str = Console.ReadLine();
            string[] strArray = str.Split(' ');
            N = int.Parse(strArray[0]);
            K = int.Parse(strArray[1]);
            int[] value = new int[N];
            for (int i =0; i < N; i++)
            {
                value[i] = int.Parse(Console.ReadLine());
            }
            int l = 1;
            int r = value.Max();
            int middle, quantityL;
            while (l < r - 1)
            {
                middle = (l + r) / 2;
                quantityL = 0;

                for (int i = 0; i < N; i++)
                {
                    quantityL += (value[i] / middle);
                }
                Console.WriteLine("quantityL = {0}", quantityL);

                if (quantityL < K)
                {
                    r = middle;
                    Console.WriteLine("r = {0}", r);
                }
                else
                {
                    l = middle;
                    Console.WriteLine("l = {0}", l);
                }
            }
            Console.WriteLine();
            Console.WriteLine(l);
        }
    }
}
