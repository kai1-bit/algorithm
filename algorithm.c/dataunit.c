#include <stdio.h>
#define N 100010

int arr[N];
int size[N];

void initialize_size(int n){
    for(int i = 0;i < n;i++) size[i] = 1;
}

void initialize_arr(int n){

    for(int x = 0;x < n;x++) arr[x] = x;    
    
}

int root(int n){
    if(n != arr[n]){
        n = root(arr[n]);
    }
    return n;
}

int root_with_decline_path(int n){
    int next = n;
    while(next != arr[next]){
        next = arr[next];
        arr[next] = root_with_decline_path(next);
    }
    return next;
} 

int search(int x,int y){
    int mid = root_with_decline_path(x);
    int tem = root_with_decline_path(y);

    if(mid == tem) return 1;//yes
    else return 0;//no
}

void unit(int x,int y){
    int mid = root_with_decline_path(x);
    int tem = root_with_decline_path(y);

    if(mid == tem) return;

    else arr[mid] = arr[tem];
}

void unit_with_weight(int x,int y){
    int mid = root_with_decline_path(x);
    int tem = root_with_decline_path(y);

    if(mid == tem) return;

    else if(size[mid] <= size[tem]){
        arr[mid] = arr[tem];
        size[tem] += size[mid];
        size[mid] = 0;
    }

    else{
        arr[tem] = arr[mid];
        size[mid] += size[tem];
        size[tem] = 0;
    }
}

int main(){
    int n;
    printf("数据数量；");
    scanf("%d",&n);

}