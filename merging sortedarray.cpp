#include<iostream>
using namespace std;
void merge_array(int a1[],int a2[],int a3[],int s1,int s2)
{
	int i = 0,j = 0,k = 0;
	while(i < s1 && j < s2)
	{
	  if(a1[i] < a2[j])
	  {
	   a3[k++] = a1[i++];  	
	  }	
	  else
	  {
	  	a3[k++] = a2[j++];
	  }
	}	
	while(i < s1)
	{
		a3[k++] = a1[i++];
	}
	while(j < s2)
	{
		a3[k++] = a2[j++];
	}
	

}


int main()
{
	int a1[5] = {0,4,2,6,8},a2[3] = {6,4,5},a3[10];
    for(int i=0;i<3;i++)
    {
    	for(int j = i+1;j<3;j++)
    	{
    		if(a1[i] > a1[j])
    		{
    		  int temp = a1[i];
			  a1[i] = a1[j];
			  a1[j] = temp;	
			}
    		 
		}
	}
	 for(int i=0;i<3;i++)
    {
    	for(int j = i+1;j<3;j++)
    	{
    		if(a2[i] > a2[j])
    		{
    		  int temp = a2[i];
			  a2[i] = a2[j];
			  a2[j] = temp;	
			}
    		 
		}
	}
	merge_array(a1,a2,a3,3,3);
		cout<<endl<<"print sorted merged array : "<<endl;
	for(int k=0;k<6;k++)
	{
		cout<<endl<<a3[k];
	}
    
	return 0;
}
