#pragma once

#include <iostream>
#include<memory>
using namespace std ;

template<typename T>
class MergeSort
{

private :
    //>0表示从大到小排序
    //0为从小到大排序
    int flag = 1 ;

public :
    //arr 为待排序数组，n为待排序数组的元素个数
    MergeSort(T *arr, int len, int flag)
    {
        //定义合并的单个序列长度为1
        this->flag = flag ;
        int s = 1 ;
        //shared_ptr<T>b = make_shared<T>(new T[len]) ;
        int* b = new int[len] ;
        //当合并到数组的长度比原是数组大
        while(s < len)
        {
            //将arr中的元素分为以s为长度的多个子序列
            //并对这些序列两两进行排序
            MergePass(arr, b, s, len) ;
            s += s ;
            MergePass(b, arr, s, len) ;
        }
        delete[]b ;
    }

    void MergePass(T* a, T* b, int s, int n)
    {
        int i = 0 ;

        while(i <= n-2*s)
        {   
            //合并大小为s的相邻两段数组
            Merge(a, b, i, i+s-1, i+2*s-1) ;
            i = i+2*s ;
        }
        
        // 处理类似以下情况（不好）:
        // 1).左：2,4,7,8|右：3,4,5 
        // 2).左：2,3,4,5|右：1 
        if(i+s < n)
        {
            Merge(a, b, i, i+s-1, n-1) ;
        }
        
        //元素长度为奇数个，还没到最后一轮合并排序，
        //将最后没有谁和他进行归合并的那个元素直接放到最后
        else
        {
            for(int j = i; j <= n-1; j++)
            {
                b[j] = a[j] ;
            }
        }
    }

    void Merge(int *a, int *b, int l, int m, int r)
    {
        //合并a[l:m]与a[m:r]到d[l:r]
        int i=l, j=m+1, k=l ;
        
        while(i <= m && j <= r)
        {
            if(a[i] > a[j])b[k++] = a[i++] ;
            else b[k++] = a[j++] ;  
        }
        if(i > m)
        {
            for(int q = j; q <= r; q++)
            {
                b[k++] = a[q] ;
            }
        }
        else
        {
            for(int q = i; q <= m; q++)
                b[k++] = a[q] ;
        }
    }
    
    void Print(int* a, int n)
    {
        cout << "The array infomation is here!" <<endl ;
        for(int i = 0; i < n; i++)
        {
            cout << a[i] << endl ;
        }
    }
};


