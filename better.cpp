#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int w_1m = 1000000;
int w[w_1m];

int binarySearch(int t, int low, int high)
{
    //对排序后的有序数据进行二分查找
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (t < w[mid])high = mid - 1;
        else if (t > w[mid])low = mid + 1;
        else return mid;
    }
    return -1;
}

// brute -w whitelist < T
int main(int argc, char* argv[])
{
    if (argc != 3 || strcmp(argv[1], "-w"))
    {
        return 1;
    }

    // init w
    ////    for(int i=0;i<w_1m)
    ////    {
    ////        w[i]=-1; //填充非法数据
    ////    }
    ifstream infile;
    infile.open(argv[2]);
    int i = 0;
    cout << argv[2] << endl;
    while (infile >> w[i++])
    {
    }
    int w_length = i - 1;
    cout << w_length << endl;
    // check t
    int t = 0;

    sort(w, w + w_length);
    //对w中的数据进行排序
    while (cin >> t)
    {
        if (binarySearch(t, 0, w_length) != -1)
        {
            //cout << t << endl;
            printf("%d", t);
        }
    }
}