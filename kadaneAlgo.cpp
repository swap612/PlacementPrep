/*Problem: [https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0]

*/
#include <iostream>
#include<limits.h>
using namespace std;

int main() {
	//code
	int tcount;
	cin >> tcount;
	int n;
    while(tcount--){
        cin >> n;
        int arr[n];
        for(int i =0; i<n; i++)
            cin >> arr[i];
        int max_sum = INT_MIN;
        int sum =0, j=0, max_i=0, max_j=0;
        for(int i =0; i<n; i++){
            //cout<< arr[i];
            sum+=arr[i];
            if(max_sum < sum){
                max_sum = sum;
                max_i=i;
            }
            if(sum < 0){
                sum = 0;
                max_j=i;
            }
            //cout<< "max_sum:"<<max_sum<<" max_i:" << max_i <<" max_j:"<<max_j <<" sum"<< sum<<endl ;   
        }
        cout<<max_sum<<endl;
    }
	return 0;
}
