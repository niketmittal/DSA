#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

class Heap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    Heap(int capacity);

    void siftUp(int i);

    void siftDown(int i);

    int parent(int i) { return (i-1)/2; }

    int leftChild(int i) { return (2*i + 1); }

    int rightChild(int i) { return (2*i + 2); }

    int extractMax();

    void changePriority(int i, int new_val);

    int getMax() { return harr[0]; }

    void remove(int i);

    void insert(int k);
};

Heap::Heap(int cap){
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
        cout<<"Heap created...\n";
}

void Heap::siftUp(int i){
        while(i>0 && harr[parent(i)] < harr[i]){
                swap(&harr[parent(i)], &harr[i]);
                i = parent(i);
        }
}

void Heap::siftDown(int i){
        int maxindex = i;
        int l = leftChild(i);
        if(l <= heap_size && harr[l] > harr[maxindex])
                maxindex = l;
        int r = rightChild(i);
        if(r <= heap_size && harr[r] > harr[maxindex])
                maxindex = r;
        if(maxindex != i){
                swap(&harr[i], &harr[maxindex]);
                siftDown(maxindex);
        }
}

void Heap::insert(int k){
        if(heap_size == capacity){
                cout<<"cannot be inserted";
                return;
        }
        heap_size++;
        harr[heap_size-1] = k;
        siftUp(heap_size-1);
        cout<<k<<" inserted\n";
}

void Heap::remove(int i){
        harr[i] = INT_MAX;
        siftUp(i);
        extractMax();
}

void Heap::changePriority(int i, int new_val){
        int old_val = harr[i];
        harr[i] = new_val;
        if(new_val > old_val)
                siftUp(i);
        else
                siftDown(i);
}

int Heap::extractMax(){
        int result = harr[0];
        harr[0] = harr[heap_size-1];
        heap_size--;
        siftDown(0);
        return result;
}

int main(){
        Heap h(11);
        h.insert(3);
        h.insert(2);
        h.remove(1); //remove element at 1st index
        h.insert(15);
        h.insert(5);
        h.insert(4);
        h.insert(45);
        cout << h.extractMax() << " ";
        cout << h.getMax() << " ";
        h.changePriority(0, 111);
        cout << h.getMax();
        return 0;
}
