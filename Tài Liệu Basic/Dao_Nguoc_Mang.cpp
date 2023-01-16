
// đảo ngược mảng 

// Cách 1:
void reverseArray1(int a[],int n){
	int i=0,j=n-1;
	while(i<j){
		swap(a[i],a[j]);
		i++;
		j--;
	}
}

// Cách 2:              
void reverseArray2(int a[],int n){
	int i=0,j=n-1;
	while(i<j){
		a[i]^=a[j];
		a[j]^=a[i];
		a[i]^=a[j];
		i++;
		j--;
	}

	//!
    for(int i=0; i<len; i++) {
        for(int j=i+1; j<len; j++){
            a[i] ^= a[j] ^= a[i] ^= a[j];
        }
    }
}

// Cách 3:
void reverseArray3(int a[],int n){
	int tmp;
	for(int i=0;i<n/2;i++){
		tmp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=tmp;
	}
}
