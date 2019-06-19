/*Problem: https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum/0
 Author: Swapnil Raykar
*/

#include<vector>
#include<map>
using namespace std;

int main() {
	//code
	int tcount;
	cin >> tcount;
	int n, reqSum;
	while(tcount--){
	    cin >> n;
	    vector<int> list(n, 0);
	    for( int i= 0; i <n ; i++)
	        cin  >> list[i];
	    cin >> reqSum ;
	    int prefixSum =0, count =0;
	    multimap<int,int> psMap;
	    multimap<int,int>::iterator mapIt;
	    pair< multimap<int,int>::iterator,  multimap<int,int>::iterator> res;
	    for( int i= 0; i <n ; i++){
	       //cout <<list[i]<<" ";
	       prefixSum+=list[i];
	       if(prefixSum == reqSum){
	           count++;
	          // cout<<0<<"--"<<i<<"C: "<<count<<"\n";
	       }
	       // check prefixSum - reqSum is present in map
	       mapIt = psMap.find(prefixSum-reqSum);
	       // PResent
	       if(mapIt!= psMap.end())
	       {
	           int c = 0;
	           c = psMap.count(prefixSum -reqSum);
	           count+=c;
	           //res = psMap.equal_range(prefixSum - reqSum);
	           //for(auto j = res.first ; j!= res.second ; j++)
       	    //       cout<<j->second +1<<"--"<<i<<"C: "<<++count<<"\n";
   					psMap.insert({prefixSum, i});

	           //cout<<mapIt->second +1<<"--"<<i<<"C: "<<count<<"\n";
	       }
	       else{
	           psMap.insert({prefixSum, i});
	       }

	     }
	     cout<< count<<"\n";

	}
	return 0;

}
