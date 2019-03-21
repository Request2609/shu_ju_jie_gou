#include <iostream>
#include<vector>
#include<iterator>
using namespace std ;
#define MAX 65535
//简单的最大堆实现
//保证子节点不大于其对应的父节点的值
//设置元素个数接口
//是否为空的接口
//获取父亲节点的借口


class Dui
{

private :

    vector<int>p ;
    int last ;

public :
    Dui()
    {
    }
    ~Dui(){}

public :

    void print()
    {
        int i ;
        while(1)
        {
            cin >> i ;
            if(i == -1)
            {
                break ;
            }
            add(i) ;
        }

        cout << "这是一个最大堆" << endl ;
        for(int i=0 ; i <= last; i++)
        {

            cout << p[i] <<endl ;
        
        }

        cout << "当前最大堆顶部元素是" << endl ;
        cout << getMax() << endl ;
        cout << "堆尾元素" << endl ;
        cout << p[last] <<endl ;
    }
    //往堆中添加元素
    void add(int e)
    {
        p.push_back(e) ;
        last = p.size() - 1 ;
        siftUp();
    }
    
    //交换父子节点信息
    void swap( int& t1, int& t2 )
    {   
        int s ;
        s = t1 ;
        t1 = t2 ;
        t2 = s ;
    }
    
    //获取堆的规模
    int get_size()
    {
        return last+1 ;
    }

    //获取其父亲节点的下表
    int getParent(int index)
    {
        return (index-1)/2 ;
    }

    //将添加的元素移动到正确的位置
    void siftUp()
    {
        //堆中的子节点不能大于其父结点的值
        int f = getParent(last) ;          
        int cur = last ;

        while(cur >0 && p[f] < p[cur])
        {
            swap(p[f], p[cur]) ;
            cur = getParent(cur);
            f = getParent(cur) ;
        }
    }
    
    //获取其左孩子的下标
    int get_right_child(int index)
    {
        return index*2+2 ;
    }

    //获取其右孩子的下标
    int get_left_child(int index)
    {
        return index*2+1 ;
    }

    //从堆顶开始比较父亲节点和字节点的大小
    //要是父亲节点比其子节点要小的话，交换两者的值
    void change(int& left, int& right, int& cur, int& swaps)
    {
          swap(p[swaps], p[cur]) ;
          cur = swaps ;
          left = get_left_child(swaps) ;  
          right = get_right_child(swaps) ;
    }

    //从堆定调整使整个堆保持为完全二叉树
    void siftDown()
    {
        int cur = 0 ;
        int left = get_left_child(0) ;
        int right = get_right_child(0) ;

        while(left < last&&(p[cur] < p[left]||p[cur] < p[right]))
        {
            
            if(left == last && right >last )
            {
                  if(p[right] > p[cur])  
                  {
                      swap(p[right], p[cur]) ;
                      break ;
                  }
            } 
            //如果左右节点都比其父亲节点大,找最大的那个进行交换
            else if(p[cur] < p[left] && p[cur] < p[right])
            {
                if(p[left] < p[right])
                {
                    change(left, right, cur, right) ;
                }

                else
                {
                    change(left, right, cur, left) ;
                }
            }
            else
            {
                if(p[left] > p[cur])
                {
                    change(left, right, cur, left) ;
                }
                else
                {
                    change(left, right, cur, left) ;
                }
            }
        }
    }

    //从堆中取出最大元素
    int getMax()
    {
        //获取到最大元素
        int max_ = p[0] ;
        cout << max_ <<endl ;
        int ll = p[last] ;
        //将最后一个元素获取到
        p[0] = ll ;
        siftDown() ;
        remove_last() ;
        return max_ ;
    }

    //将最后一个元素删除掉
    void remove_last()
    {
        p.pop_back() ;
        last -- ;
    }
};

///test 例子
int main()
{
    Dui dd ;
    dd.print() ;
    
    return 0;
}

