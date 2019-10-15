/**
 * @file bitonicSearch.cpp
 * @author Swapnil Raykar (swap612@gmail.com)
 * @brief GeeksforGeeks-Find a Number
 * @version 0.1
 * @date 2019-08-04
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include<iostream>
using namespace std;

/**
 * @brief Return the index of max element
 * 
 * @param arr 
 * @param l 
 * @param r 
 * @return int - max_index
 */
int findmax(int arr[], int l, int r){
    while(l <=r){
        int mid = l+ (r-l)/2;
        // cout << mid<<endl;
        if( (arr[mid] > arr[mid+1]) && (arr[mid] > arr[mid-1]) )
            return mid ;
        else if(arr[mid] < arr[mid+1])
            l = mid+1;
        else
            r = mid-1;
    }
    return r;
}

/**
 * @brief Binary search on Increasing sequence
 * 
 * @param arr - input array
 * @param l - left index
 * @param r - right index
 * @param key - Search Element
 * @return int - index of element or -1
 */
int bsearchI(int arr[], int l, int r, int key)
{
    while(l <=r){
        int mid = l + (r-l)/2;
        // cout << mid<<endl;
        if(arr[mid] == key)
            return mid;
        if( arr[mid] > key )
            r = mid -1 ;
        else 
            l = mid+1;
    }
    return -1;
}

/**
 * @brief Binary search on Decreasing sequence
 * 
 * @param arr - input array
 * @param l - left index
 * @param r - right index
 * @param key - Search Element
 * @return int - index of element or -1
 */
int bsearchD(int arr[], int l, int r, int key)
{
    while(l <=r){
        int mid = l + (r-l)/2;
        // cout << mid<<endl;
        if(arr[mid] == key)
            return mid;
        if( arr[mid] > key )
            l = mid + 1 ;
        else 
            r = mid - 1;
    }
    return -1;
}

int main()
{
	//code
	int t, n;
	cin >> t;
	while(t--){
	    cin >> n;
	    int arr[n];
	    for(int i =0; i< n; i++)
	        cin >> arr[i];
	    int key;
	    cin >> key;
	    // Get the index of max element
	    int max_ind = findmax(arr, 0, n-1);
	    // cout<<"Max: "<<max_ind<<endl;
	    if(key > arr[max_ind])      // KEY greater than max element in sequence
	        cout<< -1;
	    else if(key == arr[max_ind]) // max element is KEY
	        cout<< max_ind;
	    else if(max_ind == n-1)     // Sequence is Increasing only
	        cout<<bsearchI(arr, 0, n-2, key);
	    else if(max_ind == 0)       // sequence is Decreasing only
	        cout<<bsearchD(arr, 1, n-1, key);
	    else{       
            // Check first increasing sequence, if not found check decreasing sequence
	        int indI = bsearchI(arr, 0, max_ind-1, key);
	        if( indI == -1 )
	            cout<< bsearchD(arr, max_ind+1, n-1, key);
	        else
	            cout<<indI;
	    }
	    cout<<endl;
	}
		
	return 0;
}
