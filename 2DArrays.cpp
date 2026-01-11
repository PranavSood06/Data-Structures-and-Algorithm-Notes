#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
/*
      <<< 2D ARRAYS >>>
*/

void Traversing(){
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int rows = 3,cols = 3;
    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
}

/*
in memory 
 
there are two ways the 2d array can be stored in memmory 
 - Row major 
   1,2,3,4,5,6,7,8,9,10,11,12  (--->)
 - Column major
   1,4,7,10,2,5,8,11,3,6,9,12
*/

// Linear search in 2D Arrays

bool Linear_Search(int arr[][3],int rows,int cols,int target){ // important to initialise the cols in arrto pass through 
    for(int i =0;i<rows;i++){
        for(int j=0;j<cols;j++){
            // Checking each cell if it is == target
            if(target==arr[i][j])return true;
        }
    }
    return false;
}


// MAx Row Sum 
int getMaxRowSum_(int arr[][3],int rows,int cols){
    int maximum = INT_MIN;
    for(int i =0;i<rows;i++){
        int sum =0;
        for(int j=0;j<cols;j++){
            sum += arr[i][j];
        }
        maximum = max(maximum,sum);
    }
    return maximum;
}

// Max Cols Sum 
int getMaxColSum_(int arr[][3],int rows,int cols){
    int maximum = INT_MIN;
    for(int i =0;i<cols;i++){
        int sum =0;
        for(int j=0;j<rows;j++){
            // we want cols to remain same in this loop 
              sum += arr[j][i];
        } 
        maximum = max(maximum,sum);
    }
    return maximum;
}

int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    //cout<<Linear_Search(arr,4,3,11);
    //cout<<getMaxRowSum_(arr,4,3);
    Traversing();
    cout<<endl;
    cout<<getMaxColSum_(arr,3,3);
    return 0;
}
