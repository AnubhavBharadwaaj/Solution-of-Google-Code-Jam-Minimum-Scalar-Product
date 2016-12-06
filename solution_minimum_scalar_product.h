#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fac(int a)
{
	int mul=1;
	for(int i=a;i>=1;i--)
	{
		mul=mul*i;
	}
	return mul;
}

int main()
{

	int n,i,j,k=0;
	cin>>n;
	vector<int> v1[n+1],v2[n+1];
	int *num=new int[n+1];
	for(i=0;i<n;i++)
	{
		cin>>num[k];
		if(num[k]>8||num[k]<1)
        {
            exit(0);
        }
		for(j=0;j<num[k];j++)
		{
			int c;
			cin>>c;
			if(c>1000||c<-1000)
            {
                exit(0);
            }
			(v1[i]).push_back(c);
		}
		for(j=0;j<num[k];j++)
		{
			int c;

			cin>>c;
			if(c>1000||c<-1000)
            {
                exit(0);
            }
			(v2[i]).push_back(c);
		}
		k++;
	}
	int *repeat=new int[k];
	for(j=0;j<k;j++)
    {
        repeat[j]=(fac(num[j]))*(fac(num[j]));
    }
    
    vector<int> result[5];
    
    for(i=0;i<n;i++)
    {
        int p=0,sum=0;
        while(p<=repeat[i])
        {
            sum=0;
            random_shuffle((v1[i]).begin(),(v1[i]).end());
            for(j=0;j<num[i];j++)
            {
                int pro=1;
                pro=((v1[i])[j])*((v2[i])[j]);
                sum=sum+pro;
            }
            //cout<<sum<<endl;
            (result[i]).push_back(sum);
            p++;
        }
        //sort((result[i]).begin(),(result[i]).end());
    }
    for(i=0;i<n;i++)
    {
        sort((result[i]).begin(),(result[i]).end());
    }
    for(i=0;i<n;i++)
    {
        cout<<"Case #"<<(i+1)<<": "<<((result[i])[0])<<endl;
    }
	return 0;
}