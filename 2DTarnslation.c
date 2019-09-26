/******************************************************************************

                            Program which takem the original point and Translating factor and 
                            print the matrix of object after transtlation

*******************************************************************************/
#include<stdio.h>
void print(int a[3][3],int n){
    int i,j;
    for(i = 0;i<n;i++){
        for(j = 0; j < n;j++){
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
}
void initialize(int a[3][3],int n,int value){
    int i,j;
    for(i = 0;i<n;i++){
        for(j = 0; j < n;j++){
            a[i][j] = value;
        }
    }
    for(i = 0,j=0; i <n; i++,j++){
        a[i][j] = 1;
    }
}
void Translation(int a[3][3],int b[3][1],int r1Size,int c2Size ){
    int sum = 0, i , j , k, c[r1Size][c2Size];
    for(i = 0;i<r1Size;i++){
        for(j = 0; j < c2Size;j++){
            c[i][j] = 0;
            for(k = 0; k < r1Size; k++){
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
            sum = 0;
        }
    }
    for(i = 0; i<3; i++){
        for(j = 0; j<1; j++){
            printf("%d " , c[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int T[3][3],P[3][1],tx,ty,x,y,i,j;
    initialize(T,3,0);
    print(T,3);
    printf("Enter original point");
    scanf("%d %d",&x,&y);
    printf("Enter new  point");
    scanf("%d %d",&tx,&ty);
    T[0][2] = tx;
    T[1][2] = ty;
    P[0][0] = x;
    P[1][0] = y;
    P[2][0] = 1;
    Translation(T,P,3,3);
    return 0;
}
