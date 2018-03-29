using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;



namespace dsuCSharp
{
    class Edge
    {
        public int from = 0, to = 0, w = 0; // пара вершин и вес

        public Edge()
        {
        }

        public Edge(int from, int to, int w)
        {
            this.from = from;
            this.to = to;
            this.w = w;
        }

        public int compare(Edge o1, Edge o2)
        {
            if (o1.w > o2.w)
                return 1;
            else if (o1.w < o2.w)
                return -1;
            else
                return 0;
        }
    }
    class DSU
    {
        int[] parent;
        public int count = 0;

        public DSU(int size)
        {
            parent = new int[size];
            for (int i = 0; i < size; i++)
            {
                parent[i] = -1;
                count = size;
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

        public void reset(int n)
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

        public void union(int vertexA, int vertexB)
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
            count--;
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
    class Kraskala
    {
        static void Main(string[] args)
        {
            string sizeStr = Console.ReadLine();
            string[] sizeArray = sizeStr.Split(' ');
            int vGraph = int.Parse(sizeArray[0]), eFirst = int.Parse(sizeArray[1]);


            DSU test = new DSU(vGraph);
            Edge[] eArray = new Edge[eFirst];
            int[] mean = new int[3];

            string str = "";
            for (int i = 0; i < eFirst; i++)
            {
                str = Console.ReadLine();
                string[] strSplit = str.Split(' ');
                eArray[i] = new Edge(int.Parse(strSplit[0]), int.Parse(strSplit[1]), int.Parse(strSplit[2]));
            }

            Array.Sort(eArray);

            bool[] eTrue = new bool[eFirst];
            for (int i = 0; i < eFirst; i++)
            {
                eTrue[i] = false;
            }

            Edge e = new Edge();
            for (int i = 0; i < eFirst; i++)
            {
                e = eArray[i];

                if (test.check(e.from, e.to))
                {
                    test.union(e.from, e.to);
                    eTrue[i] = true;
                    Console.WriteLine(e.from + "--" + e.to + ";");
                }
                if (test.count == 1) break;

            }
        }
    }
}
