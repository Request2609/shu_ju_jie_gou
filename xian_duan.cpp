#include <iostream>
#include<vector>
#include<functional>
using namespace std ;

//定個定义一个线段树
//从树根开始子节点是根据中间元素分开后
//左节点是数组左半边的和
//右节点是数组右半边的和

//关心的是一个区间的情况，区间染色，选择对一段墙进行涂色
//线段覆盖问题，可用线段树解决

class xian_duan
{
public :
    typedef function<int (int a,int b)>do_what ;
private :
    do_what what ;
    int* data ;    
    int* tree ;
    int l ;
public :
    xian_duan(vector<int>a)
    {
        //设置这里的操作是将线段树平分求和
        what =[] (int s, int b){ return s+b; } ;

        int len = a.size() ;
        this->l = a.size();
        data = new int[a.size()] ;

        for(int i=0; i < len; i++)
        {   
            data[i] = a[i] ;
        }
        tree = new int[4*len] ;
        buildTree(0, 0, a.size()-1);
    }
    
    ~xian_duan()
    {
        free(data) ;
        free(tree) ;
        data = NULL ;
        tree = NULL ;
    }

public :
    //返回左子节点下标
    int leftChild(int index)
    {
        return index*2+1 ;
    }
    //返回右子节点下标
    int rightChild(int index)
    {
        return 2*index+2 ;
    }
       
    int getMem(int index)
    {
        if(index < 0)
        {
            throw exception() ;
        }
        return tree[index] ;
    }

    //更新线段树
    void set(int index, int a)  
    {
        if(index < 0 || index < l)
        {
            throw exception();
        }
        tree[index] = a ;   

        set(0, 0, l-1, index, a) ;
    }
    

    void set(int treeindex, int left, int right, int index, int e)
    {
        if(left == right)
        {
            tree[index] = e ;
            return  ;
        }

        int mid = l + (right-left)/2 ;
        int leftIndex = leftChild(treeindex) ;
        int rightIndex = rightChild(treeindex) ;
        
        if(index >= mid + 1)
        {
            set(rightIndex, mid+1, right, index, e) ;
        }
        else
        {
            set(leftIndex, l, mid, index, e) ;  
        }
        tree[treeindex] = tree[leftIndex] + tree[rightIndex] ;
    }

    //线段树的查询 
    int query(int ql, int qr)
    {
        if(ql > qr|| ql > l || qr < 0 || qr > l)
        {
            cout << "设置的值不合法" << endl ;
            return -1;
        }
       int sum = 0 ;     
       sum += query_info(0, 0, this->l-1, ql, qr) ;
       return sum ; 
    }

private :
    //根据区间查询线段树 
    //当前线段树节点下标为treeindex
    //查询[left:right]区间上[ql:qr]的所有值的和
    int query_info(int treeindex, int left, int right, int ql, int qr)
    {
        
        if(ql == left && qr == right)
        {
            return tree[treeindex] ;
        }

        int mid = left+(right-left)/2 ;
        //查询当前节点的左右孩子
        int leftindex = leftChild(treeindex) ;
        int rightindex = rightChild(treeindex) ;
        
        if(ql >= mid+1)
        {
            return  query_info(rightindex, mid+1, right, ql, qr) ;
        }
        else if(qr <= mid)
        {
            return query_info(leftindex, left, mid, ql, qr) ;
        }

        int leftResult = query_info(leftindex, left, mid, ql, mid) ;
        int rightResult = query_info(rightindex, mid+1, right, mid+1, qr) ;

        return what(leftResult, rightResult) ;
    }
public :

    //线段树的创建
    void buildTree(int treeindex, int left, int right)
    {
        if(left == right)
        {
            tree[treeindex] = data[left] ;
            return  ;
        }
        
        int leftindex = leftChild(treeindex); 
        int rightindex = rightChild(treeindex) ;
        
        int mid = left + (right-left)/2 ;
        
        buildTree(leftindex, left, mid) ;
        buildTree(rightindex, mid+1, right) ;
            
        tree[treeindex] = what(tree[leftindex],tree[rightindex]) ;
    }
    
    void print()
    {
        for(int i=0 ;i< l*4 ; i++)
        {
            cout << tree[i] <<"  " ;
        }   
        cout << endl ;
    }
};
int main()
{
    vector<int>s ;
    int i = 0 ;
    while(1)
    {
        cin >> i ;
        if(i==-1)
        {
            break ;
        }
        s.push_back(i) ;
    }
    xian_duan a(s) ;
    a.print() ;
    cout << a.query(2,6) << endl ;
    return 0 ;
}

