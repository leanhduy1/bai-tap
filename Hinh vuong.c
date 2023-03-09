#include<math.h>
#include<stdio.h>

int main(){
    int a1,a2,b1,b2,c1,c2,dem,x,dem1,dem2,dem3;
    float canh;
    scanf("%d%d%d%d%d%d",&a1,&a2,&b1,&b2,&c1,&c2);
    
    int arr[6] ={a1,a2,b1,b2,c1,c2};
    
    canh=sqrt(a1*a2+b1*b2+c1*c2);
    for (int i=0;i<6;++i){
		if(arr[i]==canh){
			++dem;
			if(i%2==0) x=arr[i+1];
			else x=arr[i-1];
		}
	}
    
    int h1[2] ={a1,a2};
    int h2[2] ={b1,b2};
    int h3[2] ={c1,c2};

    switch(dem){
    	case 3: printf("YES"); break;
    	case 1: 
    	for (int j=0;j<2;j++){
    		if(h1[j]+x=canh && dem1<1) ++dem1;
		}
    	
    	for (int k=0;k<2;k++){
    		if(h2[k]+x==canh && dem2<1) ++dem2;
		}
		for (int h=0;h<2;h++){
			if(h3[h]+x==canh && dem3<1) ++dem3;
		}
    	if (dem1+dem2+dem3==2 || dem1+dem2+dem3==3)
		printf("YES");
    	break;
    	default :printf("NO");	
	}
	
    return 0;
}

