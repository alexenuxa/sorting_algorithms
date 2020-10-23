#include <vector>
using namespace std;

void BubbleSort(vector<int> & data)
{
    int length = data.size();

    for (int i = 0; i < length; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < length - (i+1); ++j)
        {
            if (data[j] > data[j+1])
            {
                swap(data, j, j+1);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

int main()
{
    int a[] = {5, 6, 1, 2, 0, 8, -1, -2, 8, 0};
    std::vector<int> data(a, a + sizeof(a)/sizeof(int));

    //Bubble sort
    BubbleSort(data);
    print(data);
   return 0;
}
