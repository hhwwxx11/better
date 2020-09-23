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
    //���������������ݽ��ж��ֲ���
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
    ////        w[i]=-1; //���Ƿ�����
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
    //��w�е����ݽ�������
    while (cin >> t)
    {
        if (binarySearch(t, 0, w_length) != -1)
        {
            //cout << t << endl;
            printf("%d", t);
        }
    }
}