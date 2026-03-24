for(i=0;i<n;i++){
    small=0;
    for(j=i+1;j!=i;j++){
        if(j==n-1) {
            j=0;
        }
        else{
            if(arr[j]<arr[i]) small++;
        }
    }
    ans.push_back(small);
}
//