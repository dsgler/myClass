#include <stdio.h>
#include <assert.h>
#define N 5
#include <stdbool.h>
#include <time.h>

void swap(int *arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void print_arr(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int length)
{
    if (length <= 1)
        return;

    for (int i = length - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}

void quickSort(int *arr, int l, int r)
{
    if (l >= r)
        return;
    int lp = l;
    int rp = r;

    int base = arr[l + (r - l) / 2];
    while (lp <= rp)
    {
        while (arr[lp] < base)
            lp++;
        while (arr[rp] > base)
            rp--;
        if (lp <= rp)
        {
            swap(arr, lp, rp);
            lp++;
            rp--;
        }
    }

    quickSort(arr, l, rp);
    quickSort(arr, lp, r);
}

int mod(int x)
{
    x = x % N;
    if (x < 0)
    {
        x += N;
    }
    return x;
}

void HuanFang(int arr[N][N])
{
    int y = (N - 1) / 2;
    int x = 0;
    for (int i = 1; i <= N*N; i++)
    {
        arr[x][y] = i;

        // 右上角特判
        if (y==N-1 && x==0){
            x=1;
            continue;
        }

        int y2 = y + 1;
        int x2 = x - 1;
        y2 = mod(y2);
        x2 = mod(x2);


        if (arr[x2][y2] == 0)
        {
            y=y2;
            x=x2;
        }else{
            x=mod(x+1);
        }
    }
}

int chessboard[20]={0};

void print_chessboard(int n){
    return;
    for (int row=0;row<n;row++){
        int col=chessboard[row];
        for (int x=0;x<=col-1;x++) printf("0 ");
        printf("1 ");
        for (int x=col+1;x<=n-1;x++) printf("0 ");
        printf("\n");
    }
    printf("\n");
}

int abs(int x){
    return x<0?-x:x;
}

bool isAvialible(int row,int col){
    for (int n=0;n<row;n++){
        if (col==chessboard[n]) return false;
        if (abs(row-n)==abs(col-chessboard[n])) return false;
    }
    return true;
}

int queen(int n){
    int row=0;
    int col=0;
    int cnt=0;
    while (1){
        if (row == 0 && col==n) break;

        if (row==n){
            row--;
            col=chessboard[row]+1;
            print_chessboard(n);
            cnt++;
            continue;
        }

        if (col==n){
            row--;
            col=chessboard[row]+1;
            continue;
        }

        if (isAvialible(row,col)){
            chessboard[row]=col;
            row++;
            col=0;
            continue;
        }else{
            col++;
        }
    }

    return cnt;
}


int cnt=0;
void queen_recursion(int n,int row){
    if (row==n){
        print_chessboard(n);
        cnt++;
        return;
    }
    for (int col=0;col<n;col++){
        if (isAvialible(row,col)){
            chessboard[row]=col;
            queen_recursion(n,row+1);
        }
    }
}


int main()
{
    // int arr[] = {4, 5, 0, 1, 3, 2};
    // int length = sizeof(arr) / sizeof(int);
    // printf("修改前:\n");
    // print_arr(arr, length);
    // bubbleSort(arr,length);
    // quickSort(arr, 0, length - 1);
    // printf("修改后:\n");
    // print_arr(arr, length);

    // int arr2[N][N]={0};
    // HuanFang(arr2);
    // for (int i=0;i<N;i++){
    //     print_arr(arr2[i],N);
    // }

    // int n=8;
    // queen_recursion(n,0);
    // printf("%d\n",cnt);

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    // queen_recursion(14,0);
    queen(14);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Function execution time: %f seconds\n", cpu_time_used);
}