#include<math.h>
#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    
    for(int m=0;m<n;++m){
    	int a,x,y,b=1,l=1,logic=0,tmp;
    	scanf("%d",&a);
    	
		for(int k=0;k<a-1;++k) b*=10;
    	for(int j=0;j<a;++j) l*=10;
    	
		for(int i=b;i<=l-1;++i){
			tmp=i;
			x=tmp%10;
    		while(tmp>0){
    			tmp/=10;
    			y=tmp%10;
    			if(x<y){
    				logic=0;
    				break;
				} else {
					logic=1;
					x=y;
				}
			}
			if(logic==1 && i>b && i<l) printf("%d ",i);
			
		}
		
		printf("%d\n");
    	
    	
    }
}
