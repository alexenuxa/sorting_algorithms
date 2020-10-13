namespace Algorithms.Sort
{
    /// <summary>
    /// HEAPSORT
    /// </summary>
    class HeapSorter : ISorter<int>
    {
        private void Swap(ref int a, ref int b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }

        private void Heapify(int[] a, int i, int N)
        {
            while (2 * i + 1 < N)
            {
                int k = 2 * i + 1;

                if (2 * i + 2 < N && a[2 * i + 2] >= a[k])
                {
                    k = 2 * i + 2;
                }
                if (a[i] < a[k])
                {
                    Swap(ref a[i], ref a[k]);
                    i = k;
                }
                else
                    break;
            }
        }

        /// <summary>
        /// In-place heapsort
        /// </summary>
        public void Sort(int[] a, int l, int r)
        {
            int N = r - l + 1;

            // build heap
            for (int i = r; i >= l; i--)
            {
                Heapify(a, i, N);
            }

            // sort heap
            while (N > 0)
            {
                Swap(ref a[l], ref a[N - 1]);
                Heapify(a, l, --N);
            }
        }
    }
}