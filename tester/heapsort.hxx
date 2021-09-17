#pragma once
#include <iostream>
#include <vector>
#include <iterator>

class Heap { 
    int largest {0}, length{0};
    int  l, r, node;
    int heap_comparison, heap_swap;
    std::vector<int> v_{0};
    void heapify(std::vector<int> &a, int n, int i){

        l = LEFT(i);
        r = RIGHT(i);

       
        if(l < n && a[l] > a[i]){
            largest = l;
        }else largest = i;
        
        if(r < n && a[r] > a[largest]){
            largest = r;
        }

        if(largest != i){
            std::swap(a[i],a[largest]);
            heapify(a, n, largest);
        }
    
        
    } 
    int PARENT(int i){++heap_comparison; return i/2;}
    int LEFT(int i){++heap_comparison; return 2*i;}
    int RIGHT(int i){++heap_comparison; return 2*i+1;}

public:

    void build(const std::vector<int> &a){
        for(int j = 0; j < a.size(); j++)
            v_.push_back(a[j]);

        length = v_.size();

        for(int i = length/2; i > 0 ; i--){
            heapify(v_, v_.size(), i);
        }

    } 
    void push(int x){

        if(empty()){
            v_.push_back(x);
        }else{
        int j;
            node = v_.size();
            v_.push_back(x); 
            
            j =  PARENT(node);

            while( node > 1 && v_[j] < x )
            {
                v_[node] = v_[j];
                node = j;
                j =  PARENT(node);
            }

            v_[node] = x;
        }
  
    } 
    int pop(){
        if(empty())throw std::out_of_range("EMPTY"); 
          int temp = v_[1];
        std::swap(v_[1],v_[v_.size()-1]);
        v_.pop_back();
        //node = v_.size()-1;
        heapify(v_, v_.size(), 1);
        return std::move(temp);
    } 

    int& top(){ return v_.back(); } 
    int size(){ return v_.size()-1; } 
    bool empty(){ return v_.size()==1; } 
    bool check(){
        if(empty())return true;
        node = 1;
        while(node <= PARENT(size())){
            if(v_[node] <= v_[RIGHT(node)] || v_[node] <= v_[LEFT(node)] )
                return false; 
            ++node;
        }
        return true;
        
    } 
    void heapsort(std::vector<int>&a){
        build(a);
        node = v_.size()-1;
        for(int i = node; i > 1; i--){
            std::swap(v_[1],v_[i]);
            ++heap_swap;
            heapify(v_, i ,1);
        }
        for(int i = 0; i<a.size();i++)
        a[i] = v_[i+1];
        //heap_comparison+=v_.size()
    }
    
    void view_stat(){
       std::cout<<heap_comparison<<"\t"<<heap_swap;
    }
};