#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int ok = 0;
    int n = 50;
    for (int i = 1; i <= n; ++i)
    {
        system("data.exe > in.txt");
        system("std.exe < in.txt > std.txt");
        double begin = clock();
        system("baoli.exe < in.txt > baoli.txt");
        double end = clock();

        double t = (end - begin);
        if (system("fc std.txt baoli.txt"))
        {
            printf("���Ե�#%d Wrong Answer\n", i);
        }
        else if (t > 1000) //1��
        {
            printf("���Ե�#%d Time Limited Exceeded ��ʱ %.0lfms\n", i, t);
        }
        else
        {
            printf("���Ե�#%d Accepted ��ʱ%.0lfms\n", i, t);
            ok++; //AC����+1
        }
    }
    printf("\n");
    double res = 100.0 * ok / n;
    printf("�� %d ��������ݣ�AC���� %d �顣 �÷�%.1lf��", n, ok, res);
}
