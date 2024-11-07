#include<iostream>
using namespace std;

struct queue {
    int *arr;
    int size;
    int f = 0;
    int r = -1;

    queue(int t_size) {
        size = t_size;
        arr = new int[size];
    }

    void enqueue(int ele) {
        if (isfull()) {
            cout << "Your queue is full" << endl;
        }
        else {
            r = r + 1;
            arr[r] = ele;
        }
    }

    int dequeue() {
        if (isempty()) {
            cout << "Your queue is empty";
            return -1; // Or handle the empty condition appropriately
        }
        else {
            int val = arr[f];
            f = f + 1;
            return val;
        }
    }

    void show() {
        int index = f;
        if (isempty()) {
            cout << "Your queue is empty";
        }
        else {
            while (index <= r) {
                cout << arr[index] << " ";
                index = index + 1;
            }
        }
    }

    int isfull() {
        if (r >= (size - 1)) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int isempty() {
        if (r < f) {
            return 1;
        }
        else {
            return 0;
        }
    }
};

int main() {
    queue exp(5);
    int i = 0;
    int j;
    int visited[4] = { 0,0,0,0 };
    int adj_matrix[4][4] = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0}
    };
    cout << i;
    visited[i] = 1;
    exp.enqueue(i);
    while (!exp.isempty()) {
        int node = exp.dequeue();
        for (int j = 0; j < 4; j++) { 
            if (adj_matrix[node][j] == 1 && visited[j] == 0) {
                cout << j;
                visited[j] = 1;
                exp.enqueue(j);
            }
        }
    }
    return 0;
}

