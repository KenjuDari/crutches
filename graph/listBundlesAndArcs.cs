using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace listBundlesAndArсs
{
    class Edge
    {
        public Edge(int from, int to, int weight)
        {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
        int from;
        int to;
        int weight;
        public int From
        {
            get { return from;  }
        }
        public int To
        {
            get { return to; }
        }
        public int Weight
        {
            get { return weight; }
        }

        public override string ToString()
        {
            return (from + " -> " + to + ";");
        }

        public static int compare(Edge o1, Edge o2)
        {
            if (o1.Weight > o2.Weight)
                return 1;
            else if (o1.Weight < o2.Weight)
                return -1;
            else
                return 0;
        }

        //public int compareTo(Edge o1, Edge o2)
        //{
        //    if (o1.Weight > o2.Weight)
        //        return 1;
        //    else if (o1.Weight < o2.Weight)
        //        return -1;
        //    else
        //        return 0;
        //}


    }

    class ListBundlesAndArcs
    {
        Edge[] edges; // ребра
        int[] headsFrom; 
        int[] headsTo;
        int[] linksFrom; 
        int[] linksTo;    
        public ListBundlesAndArcs(int nVertexs, Edge[] edges)
        {
            this.edges = edges;
            headsFrom = new int[nVertexs];
            headsTo = new int[nVertexs];
            linksFrom = new int[edges.Length];
            linksTo = new int[edges.Length];

            for (int i = 0; i < nVertexs; i++)
            
            {
                
                headsFrom[i] = -1;
                headsTo[i] = -1;
            }

            for (int k = 0; k < edges.Length; k++) // начинаем обход всех ребер
            
                {
                int from = edges[k].From;             
                linksFrom[k] = headsFrom[from];  
                headsFrom[from] = k; 

                int to = edges[k].To; 
                
                linksTo[k] = headsTo[to];
                headsTo[to] = k;
            }
        }

        public override string ToString() // вывод всех ребер графа
        {
            string str = "";
            int link;
            for (int i = 0; i < headsFrom.Length; i++)
            {
                link = headsFrom[i]; // берем номер первого ребра

                while (link != -1) // пока есть ребра
                {
                    str += edges[link].ToString() + "\n";
                    link = linksFrom[link]; // берем следующее ребро из списка, пока они не закончатся (== -1)
                }
            }
            return str;
        }

        public string writeVertexWeights() // вывести все веса для каждой вершины
        {
            string str = "";
            int linkFrom, weight;
            for (int i = 0; i < headsFrom.Length; i++) 
            {
                weight = 0;
                linkFrom = headsFrom[i]; 

                while (linkFrom != -1) 
                {
                    weight += edges[linkFrom].Weight;
                    linkFrom = linksFrom[linkFrom]; 
                }

                str += "Vertex " + i + " has " + weight + " weight\n";
            }
            return str;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int nArcs = 7;
            int nVertexs = 5;
            int[] I = { 0, 0, 0, 4, 1, 1, 3 };
            
            int[] J = { 4, 3, 1, 3, 3, 2, 2 };
            int[] W = { 4, 7, 1, 0, 5, 2, 7 };
            Edge[] edges = new Edge[nArcs];
            for (int i = 0; i < nArcs; i++)
            {
                edges[i] = new Edge(I[i], J[i], W[i]); // создаем массив ребер
            }
            ListBundlesAndArcs list = new ListBundlesAndArcs(nVertexs, edges);
            Console.WriteLine(list); // выводим все ребра

            Console.WriteLine();
            Console.WriteLine(list.writeVertexWeights());
        }
    }
}
