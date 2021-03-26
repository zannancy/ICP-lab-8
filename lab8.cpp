#include <iostream>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

//(Part A)
//Store i and i of A[i][j] in inverseIdx()
int arrij[2];

//Arrays used as parameters for two functions
int A [7][7];
int B[24];

//LinearIndx()
int LinearIndx(int i, int j){
    if(j>1) return -1;
    else{
        int I =(((i*i)+i)/2)+j;
        return I;
    }
}

//ReverseIdx()
int* ReverseIdx(int arr2d[7][7], int I, int arr1d[24]){
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if(j<=i){
                int tempoI = (((i*i)+i)/2)+j;
                if(tempoI==I){
                    arrij[0] = i;
                    arrij[1] = j;
                    return arrij;
                }
            }
        }
    }
    return arrij;
}

//Main Method (Part B)
int main(int argc, char *argv[])
{
    //predefining Array sizes
    int n = 128;
    int m = 16000;


    //Generating the lwer trianguular array between 0 and 150
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j<=i){
                A[i][j]=rand()%1000;
            }
            else{
                A[i][j]=0;
            }
        }
    }

    //Assigning A[i][j] to B[I]
    for(int i=0;i<=n; ++i){
        for (int j = 0; j < n; ++j)
        {
            int I = LinearIndx(i,j);
            if(I != -1){
                B[I]=A[i][j];
            }
        }
        
    }


    //Assigning B[I] to C[i][i]
    int C[n][n];
    for (int i=0; i<m; i++){
        int *D = ReverseIdx(C,i,B);
        int g=D[0];
        int h=D[1];

        C[g][h]=B[i];
    }

    //Printing the first 20 elements of A and the indexes
     for(int i=0; i<7; ++i){
         for(int j=0; j<7; ++j){
             if(A[i][j] != 0){
                 cout<<"A[ "<<i<<" ] [ "<<j<<" ] "<<A[i][j]<<endl;
             }
        }
     }
     
    cout<<"A has ended"<<endl;
    cout<<" "<<endl;
        

    //Printing the first 20 elements of B and the indexes
    for (int i = 0; i < 20; ++i)
    {
        cout<<"B[ "<<i<<" ] "<<B[i]<<endl;
    }
    cout<<"B has ended"<<endl;
    cout<<" "<<endl;
    

    //Printing the first 20 elements of C and the indexes
    for (int i = 0; i < 7; ++i){
        for (int j = 0; j < 7; ++j)
        {
            if(C[i][j] != 0){
                cout<<"C[ "<<i<<" ] [ "<<j<<" ] "<<C[i][j]<<endl;
            }
        }
        
    }
    cout<<"C has ended"<<endl;
    cout<<" "<<endl;
    return 0;
}


