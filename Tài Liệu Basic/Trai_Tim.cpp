
#include<bits/stdc++.h>
using namespace std;
int main(){
	int mid=20,y1=5,y2=35,t1=-1,t2=1;
	int y3=12,y4=28;

	for(int i=1;i<=y1;i++)cout<<" ";cout<<"v";
	for(int i=y1+1;i<=y3-2;i++)cout<<"v";
	for(int i=y3+2;i<=y4+2;i++)cout<<" ";cout<<"v";
	for(int i=y4;i<=y2-3;i++)cout<<"v";cout<<endl;

	while(1){
		for(int i=1;i<=y1-1;i++)cout<<" ";cout<<"v";
		if(y3>y4){
			for(int i=y1+1;i<=y2-1;i++)cout<<" ";cout<<"v";	
		}else {
			if(y1<y3){
				for(int i=y1+1;i<=y3-1;i++)cout<<" ";cout<<"v";
			}
			if(y3<y4){
				for(int i=y3+1;i<=y4-1;i++)cout<<" ";cout<<"v";
			}			
			if(y4<y2){
				for(int i=y4+1;i<=y2-1;i++)cout<<" ";cout<<"v";
			}
			y3+=1;y4-=1;
		}	
		cout<<endl;
		y1+=t1;y2+=t2;
		if(y1==0){
			t1=1;t2=-1;
			y1+=t1;y2+=t2;
		}
		if(y1==y2) {
			for(int i=1;i<=y1-1;i++)cout<<" ";cout<<"v";
			break;	
		}
	}
	return 0;
}