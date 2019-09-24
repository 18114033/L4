#include <iostream>
#include <iterator>
#include <map>

using namespace std;
void func(){
	int n,i;
	int sum=0,max=0,k,low=0,high=0;
map<int,int> num;


    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
    scanf("%d",&a[i]);
       num.insert(pair<int, int>(i, a[i]));
    }
    printf("Enter the value of k");
    scanf("%d",&k);
    

    map<int, int>::iterator itr;
    for (itr = num.begin(); itr != num.end(); itr++) 
	{
	 sum=0;
    for(i=itr->first;i<n;i++){
         sum+=a[i]; 
		 if(high-low>max) max=high-low;
          if(sum==k){
           high=i;
              low=itr->first;
          if(high-low>max){  max=high-low+1;  }
         }
    }
    }
    printf("Length of longest sub array=%d\n",max);
    printf("Index from %d to %d\n",low,high);
}
void m(){
	func();
}
int main(){
	m();
}
