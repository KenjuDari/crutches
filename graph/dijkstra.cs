using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dijkstra
{
    struct Edge
    {
        public int from, to, weight;
        public Edge(int from, int to, int weight)
        {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }
    class Program
    {
        static int nVertex = 5; // количество вершин в графе
        static int nEdge = 10;  // количество ребер в графе
        static Edge[] edges = new Edge[nEdge]; // ребра
        static List<int>[] incidentEdges = new List<int>[nVertex]; // списки инцидентных ребер для каждой вершины
        static int dMax = int.MaxValue; // бесконечность
        static bool[] visited = new bool[nVertex]; // посещенные вершины
        static int[] distance = new int[nVertex]; // путь от рассматриваемой вершины до данной (индекс массива)
        static int[] parent = new int[nVertex]; // родители в дереве кратчайшего пути

        static void Main(string[] args)
        {


            int[] I = { 0, 0, 0, 0, 3, 3, 4, 2, 4, 4 };
            int[] J = { 1, 2, 3, 4, 1, 2, 3, 4, 0, 2 };
            int[] W = { 10, 30, 50, 10, 40, 20, 30, 10, 10, 10};


            /////////////// инициализация переменных для алгоритма
            for (int i = 0; i < nEdge; i++)
            {
                edges[i] = new Edge(I[i], J[i], W[i]);
            }

            for (int i = 0; i < nVertex; i++)
            {
                incidentEdges[i] = new List<int>();
                parent[i] = -1;

            }

            for (int i = 0; i < nEdge; i++)
            {
                incidentEdges[edges[i].from].Add(i);
            }

            /////////////////////////////////////

            ///////////////////////////////////// обход

            distance[0] = 0; // вершина, от которой считаем расстояния
            visited[0] = false;
            for (int i = 1; i < nVertex; i++) // инициализируем все длины до вершин как бесконечность, вершины как не посещенные 
            {
                distance[i] = dMax;
                visited[i] = false;
            }

            int currentVertex = 0; // начинаем обход с начальной вершины
            int distMin = 0; // путь до ночальной вершины 0

            while(distMin < dMax) // пока есть непостроенный пути
            {
                look(currentVertex); // начинаем рассматривать
                distMin = dMax;
                for (int i = 0; i < nVertex; i++)
                {
                    if (!visited[i] && distance[i] < distMin)  // ищем нерассмотренную вершину с минимальным расстоянием
                    {
                        distMin = distance[i];
                        currentVertex = i;
                    }
                }               
            }
            ///////////////////////////////////////////////////

            ////////////////////////////////////////////////// вывод
            Console.WriteLine("Min distance");
            for (int i = 0; i < distance.Length; i++)
            {
                Console.Write(distance[i] + " ");
            }
            Console.WriteLine();
            Console.WriteLine("Shortest backwards way to 3 vertex: ");
            int v = 2;
            Console.Write(v + 1);
            while (parent[v] != -1)
            {
                Console.Write(" <- " + (parent[v] + 1));
                v = parent[v];
            }
            Console.WriteLine();
            /////////////////////////////////////////////////////
        }



        static void look(int currentVertex)
        {
            visited[currentVertex] = true;               
            for (int i = 0; i < incidentEdges[currentVertex].Count; i++) // рассмотрим все инцидентные вершины рассматриваемой вершины
            {
                int indexEdge = incidentEdges[currentVertex][i]; // индекс инцедентного ребра в массиве ребер
                Edge incEdge = edges[indexEdge];                 // инцидентное ребро
                int incVertex = incEdge.to;                      // инцидентная вершина
                if (distance[currentVertex] + incEdge.weight < distance[incVertex])
                {
                    distance[incVertex] = distance[currentVertex] + incEdge.weight; // если через текущую вершину путь лучше, присваиваем новое значение
                    parent[incVertex] = currentVertex;
                }
            }
        }
    }
}
