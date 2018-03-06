using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;



namespace dsuCSharp
{
    class DSU
    {
        int[] parent;

        public DSU(int size)
        {
            parent = new int[size];
            for (int i = 0; i < size; i++)
            {
                parent[i] = -1;
            }
        }

        public void hang(int vertex, int parentNew)
        {
            parent[vertex] = parentNew;
        }

        public int find(int vertex)
        {
            int rootsearch = vertex;
            while (parent[rootsearch] != -1)
            { 	
                rootsearch = parent[rootsearch];
            }
            while (parent[vertex] != -1)
            {  
                int t = parent[vertex];
                parent[vertex] = rootsearch;
                vertex = t;
            }
            return rootsearch;
        }

        public void reset (int n)
        {
            if (n > parent.Length)
            {
                int[] newParent = new int[n];
                for (int i = 0; i < parent.Length; i++)
                {
                    newParent[i] = parent[i];
                }
                parent = newParent;
            }

            for (int i = 0; i < n; i++)
            {
                parent[i] = -1;
            }
        }

        public void union (int vertexA, int vertexB)
        {
            int jRoot = find(vertexA);
            int kRoot = find(vertexB);
            if (jRoot != kRoot)
            {
                if (jRoot < kRoot)
                {

                    int t = jRoot;
                    jRoot = kRoot;
                    kRoot = t;
                }
                hang(kRoot, jRoot);
            }
        }

        public bool check(int vertexA, int vertexB)
        {
            int jRoot = find(vertexA);
            int kRoot = find(vertexB);
            if (jRoot == kRoot)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public override string ToString()
        {
            string print = "";
            for (int i = 0; i < parent.Length; i++)
            {
                print += i.ToString() + "--" + parent[i].ToString() + "\n";
            }
            return print;
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            DSU test = new DSU(5);
            //test.hang(2, 4);
            //test.hang(0, 3);
            //Console.WriteLine(test);
            //Console.WriteLine(test.find(2));


            FileStream fstreamR = File.OpenRead(@"D:\t.txt");
            FileStream fstreamW = new FileStream(@"D:\t2.txt", FileMode.OpenOrCreate);

            string sFile;
            int currentWord = 0;
            byte[] arrayW;
            byte[] array = new byte[fstreamR.Length];
            fstreamR.Read(array, 0, array.Length);
            sFile = System.Text.Encoding.Default.GetString(array);
            string[] strArray = sFile.Split(' ', '\n');
            while (currentWord < (strArray.Length - 1))
            {
                if (strArray[currentWord] == "RESET")
                {
                    currentWord++;
                    test.reset(int.Parse(strArray[currentWord++]));
                    arrayW = System.Text.Encoding.Default.GetBytes("RESET DONE\r\n");
                    fstreamW.Write(arrayW, 0, arrayW.Length);

                }
                if (strArray[currentWord] == "JOIN")
                {
                    currentWord++;
                    int vertexA = int.Parse(strArray[currentWord++]);
                    int vertexB = int.Parse(strArray[currentWord++]);
                    if (test.check(vertexA, vertexB))
                    {
                        arrayW = System.Text.Encoding.Default.GetBytes("ALREADY\r\n");
                        fstreamW.Write(arrayW, 0, arrayW.Length);
                    }
                    else
                    {
                        test.union(vertexA, vertexB);
                    }
                }
                if (strArray[currentWord] == "CHECK")
                {
                    currentWord++;
                    int vertexA = int.Parse(strArray[currentWord++]);
                    int vertexB = int.Parse(strArray[currentWord++]);
                    if (test.check(vertexA, vertexB))
                    {
                        arrayW = System.Text.Encoding.Default.GetBytes("YES\r\n");
                        fstreamW.Write(arrayW, 0, arrayW.Length);
                    }
                    else
                    {
                        arrayW = System.Text.Encoding.Default.GetBytes("NO\r\n");
                        fstreamW.Write(arrayW, 0, arrayW.Length);
                    }
                }
            }


            string s;
            s = Console.ReadLine();
            while (s != "end")
            {
                string[] str = s.Split(' ');
                if (str[0] == "RESET")
                {
                    test.reset(int.Parse(str[1]));
                    Console.WriteLine("RESET DONE");
                }
                if (str[0] == "JOIN")
                {
                    int vertexA = int.Parse(str[1]);
                    int vertexB = int.Parse(str[2]);
                    if (test.check(vertexA, vertexB))
                    {
                        Console.WriteLine("ALREADY");
                    }
                    else
                    {
                        test.union(vertexA, vertexB);
                    }
                }
                if (str[0] == "CHECK")
                {
                    int vertexA = int.Parse(str[1]);
                    int vertexB = int.Parse(str[2]);
                    if (test.check(vertexA, vertexB))
                    {
                        Console.WriteLine("YES");
                    }
                    else
                    {
                        Console.WriteLine("NO");
                    }
                }
                s = Console.ReadLine();
            }
        }
    }
}
