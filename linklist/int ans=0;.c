int ans=0;
for(int i=low;i<=high;i++){
    int count=0;
    int j=i;
    while(j>0){
        count++;
        j=j/10;
    }

    if(count%2!=0){
        continue;

    }

    else{
int ash=i;
int sum1=0;
int sum2=0;
        for(int k=0;k<(count/2);k++){
            sum1+=ash%10;
            ash=ash/10;
        }

        
        for(int l=0;l<(count/2);l++){
            sum2+=ash%10;
            ash=ash/10;
        }

        if(sum1==sum2)
        ans++;
    }
}