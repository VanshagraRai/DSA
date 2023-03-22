#include <bits/stdc++.h>
using namespace std;

struct arr{
    int profit;
    int weight;
};
bool compare(arr a,arr b){
    double r1 = a.profit/(a.weight*1.0);
    double r2 = b.profit/(b.weight*1.0);
    return r1 > r2;
}

double knapsack(arr x[],int total_weight,int n){
    sort(x,x+n,compare);
    int current_weight = 0;
    double final_val = 0.0;
    for(int i = 0;i<n;i++){
        if(current_weight+x[i].weight <=total_weight){
            current_weight += x[i].weight;
            final_val += x[i].profit;
        }
        else{
            int remain = total_weight - current_weight;
            final_val += (x[i].profit / (double) x[i].weight) * (double) remain;
        }
    }
    return final_val;
}


int main(){

    int n,total_weight;
    n = 3;
    total_weight = 50;
    arr x[] = {{60, 10}, {100, 20}, {120, 30}};
    cout << "Answer is " << knapsack(x,total_weight,n);
    return 0;
}
