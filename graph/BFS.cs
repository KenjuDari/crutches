using System;
using System.Collections.Generic;

namespace bfs
{
    class Program
    {
        static int nVertex = 5; // количество вершин в графе
        static int nEdge = 6;  // количество ребер в графе
        static Edge[] edges = new Edge[nEdge]; // ребра
        static List<int>[] incidentEdges = new List<int>[nVertex]; // списки инцидентных ребер для каждой вершины
        static bool[] visited = new bool[nVertex]; // посещенные вершины
        static int[] distance = new int[nVertex]; // путь от рассматриваемой вершины до данной (индекс массива)
        static int[] parent = new int[nVertex]; // родители в дереве кратчайшего пути
        static int start = 0;

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

        static void BFS()
        {
            Queue<int> q = new Queue<int>();
            // Инициализация: есть информация про начальную вершину
            q.Enqueue(start);
            distance[start] = 0;
            parent[start] = -1;
            visited[start] = true;
            // Главный цикл - пока есть нерассмотренные вершины
            while (q.Count != 0)
            {               
                int v = q.Dequeue(); // Берем первую из них             
                for (int i = 0; i < incidentEdges[v].Count; ++i)  // Пробегаемся по всем ее соседям
                {                    
                    if (!visited[incidentEdges[v][i]]) // Если сосед еще не был рассмотрен
                    {
                        distance[incidentEdges[v][i]] = distance[v] + 1;  // То вычисляем расстояние                       
                        visited[incidentEdges[v][i]] = true; // И он становится рассмотренным                    
                        parent[v] = incidentEdges[v][i]; // запоминаем родителя
                        q.Enqueue(incidentEdges[v][i]); // добавляем в очередь для рассмотрения следующих соседей
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            int[] I = { 0, 0, 3, 3, 4, 2  };
            int[] J = { 1, 2, 1, 2, 3, 4  };
            int[] W = { 10, 30,  40, 20, 30, 10 };


            /////////////// инициализация переменных для алгоритма
            for (int i = 0; i < nEdge; i++)
            {
                edges[i] = new Edge(I[i], J[i], W[i]);
                Console.WriteLine(I[i] + " -> " + J[i] + ";");
            }
            Console.WriteLine();

            for (int i = 0; i < nVertex; i++)
            {
                incidentEdges[i] = new List<int>();
                parent[i] = -1;
            }

            for (int i = 0; i < nEdge; i++)
            {
                incidentEdges[edges[i].from].Add(J[i]);
            }

            BFS();

            for (int i = 0; i < nVertex; i++)
            {
                Console.WriteLine( i + ": " + distance[i]);
            }
        }
    }
}
