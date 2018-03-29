using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace heapFull
{
    class Heap  // c min в корне
    {
        int[] arrayHeap;
        int countV;
        public Heap(int[] values)
        {
            countV = values.Length;
            arrayHeap = new int[countV + 1];  // массив заполняется начиная с 1 индекса
            arrayHeap[0] = 0;
            for (int i = 1; i <= countV; i++)
            {
                arrayHeap[i] = values[i - 1];
            }
            heapify();
        }

        void remontOut( int v)          // наружный ремонт при увелечении элемента с интексом v
        {
            int indexChild1 = 0;
            int indexChild2 = 0;
            for (int indexCurrent = v; indexCurrent <= countV / 2; indexCurrent = indexChild1)  // от текущего элемента до уровня перед листьями (предпоследний)
            {
                indexChild1 = 2 * indexCurrent;
                indexChild2 = 2 * indexCurrent + 1;
                if ((indexChild2 <= countV) && (arrayHeap[indexChild2] < arrayHeap[indexChild1]))  // второй ребенок есть (индекс меньше последнего)
                                                                                            // второй ребенок меньше первого
                {
                    indexChild1 = indexChild2; // работаем с меньшим из потомков
                }
                if (indexChild1 > countV) // потомки закончились
                {
                    break;
                }
                if (arrayHeap[indexCurrent] < arrayHeap[indexChild1]) // соотношение порядка соблюдено
                {
                    break;
                }
                                                                             // если нрушен порядок, меняем текущей элемент с потомком
                int t = arrayHeap[indexCurrent];
                arrayHeap[indexCurrent] = arrayHeap[indexChild1];
                arrayHeap[indexChild1] = t;
            }
        }

        void remontIn (int v)            // внутренний ремонт при уменьшении элемента с интексом v
        {
            int parent = 0;
            for (int indexCurrent = v; indexCurrent > 1; indexCurrent = parent)
            {
                parent = indexCurrent / 2;
                if (arrayHeap[indexCurrent] > arrayHeap[parent])
                {
                    break;
                }

                int t = arrayHeap[indexCurrent];
                arrayHeap[indexCurrent] = arrayHeap[parent];
                arrayHeap[parent] = t;
            }
        }

        public void add (int newElement)
        {
            if (countV >= arrayHeap.Length - 1)
            {
                int[] arrayHeapNew = new int[arrayHeap.Length + 1];
                Array.Copy(arrayHeap, arrayHeapNew, arrayHeap.Length);
                arrayHeap = arrayHeapNew;

            }
            arrayHeap[++countV] = newElement;
            remontIn(countV);
        }      

        public void delete(int indexDel)
        {
            int elementDel = arrayHeap[indexDel];
            arrayHeap[indexDel] = arrayHeap[countV--];
            if (elementDel > arrayHeap[indexDel])
            {
                remontIn(indexDel);
            }
            else
            {
                remontOut(indexDel);
            }
        }

        int deleteRoot()
        {
            int valueRoot = arrayHeap[1];
            arrayHeap[1] = arrayHeap[countV--];
            remontOut(1);
            return valueRoot;
        }

        void heapify()
        {
            for (int indexCurrent = countV/2; indexCurrent > 0; indexCurrent--)
            {
                remontOut(indexCurrent);
            }
        }

        public void pyramidSort()
        {
            int countVRemember = countV;
            while (countV > 0)
            {
                arrayHeap[countV] = deleteRoot();
            }
            countV = countVRemember;
        }

        public void writeArray()
        {
            for (int i = 1; i < countV; i++)
            {
                Console.Write(arrayHeap[i] + " ");
            }
            Console.WriteLine();
        }

        public override string ToString()
        {
            string print = "";
            for (int i = 1; i < countV / 2; i++)
            {
                print += arrayHeap[i].ToString() + "->" + arrayHeap[i * 2].ToString() + "\n";
                if (i * 2 + 1 <= countV)
                {
                    print += arrayHeap[i].ToString() + "->" + arrayHeap[i * 2 + 1].ToString() + "\n";
                }
            }
            return print;
        }
    }

    class heapProg
    {
        static void Main(string[] args)
        {
            Heap test = new Heap(new int[] {4, 5, 234, 10, 67, 21, 0, -6, -2, -10, 100 });
            test.add(-100);
            test.delete(5);
            Console.WriteLine(test);
            test.pyramidSort();
            test.writeArray();

        }
    }
}
