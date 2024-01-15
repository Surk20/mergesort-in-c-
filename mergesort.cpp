#include<iostream>
using namespace std;//contains header files and others
//*****************************************
void insert(int a[],int n)//signature,Camel case-insertArray
{
	for(int i=0;i<=n-1;i++)
	cin>>a[i];//after cin, extraction
}
//*****************************************
void display(int a[],int n){
	for(int i=0;i<n;i++) 
	cout<<a[i]<<" ";// after cout, insertion
}
//***************************************
void merge(int a[],int l,int r, int mid){
	int n1=mid-l+1;
	int n2=r-mid;
	int A[n1+1],B[n2+1];
	for(int i=0;i<n1;i++)
	A[i]=a[l+i]; 
	A[n1]=10000;
	
	for(int j=0;j<n2;j++)
	B[j]=a[mid+1+j];
	B[n2]=10000;
	
	int i=0,j=0,k;
	for(k=l;k<=r;k++){
		if(A[i]<B[j]) a[k]=A[i++];
		else if(A[i]>B[j]) a[k]=B[j++];
		else
		{
			a[k++]=A[i++];
			a[k]=B[j++];
		}
	}
}
//****************************************
void mergeSort(int a[],int l,int r){
	if(l<r)
	{
		int mid=(l+r)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);
		merge(a,l,r,mid);
	}
}

//*****************************************
int main()//1st
{
int n;//int n,a[n];  This will make an array of garbage value and it will not match with our array.
cout<<"Enter size:"; cin>>n; 
int a[n];
cout<<"Enter array elements:\t";//\t will make 4 spaces.
insert(a,n);

cout<<"\n unsorted array elements are:\t";
display(a,n);
cout<<endl;

mergeSort(a,0,n-1);

cout<<"Sorted array:";
display(a,n);
}


