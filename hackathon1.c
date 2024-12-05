#include<stdio.h>
int isprime(int num) {
if (num <= 1) 
	return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) 
			return 0;
    }
return 1;
}
int main(){
	int n;
	int arr[100];
	int value;
	int choice;
	int found = 0;
	int currentlength = 0;
	int addindex;
	int index;
	int count = 0;
	while(1){
		printf("\nMENU\n");
		printf("1. Nhap so phan tu va gia tri cho mang\n");
		printf("2. In ra gia tri cac phan tu trong mang\n");
		printf("3. Dem so luong cac so nguyen to co trong mang\n");
		printf("4. Tim gia tri nho thu hai trong mang\n");
		printf("5. Them mot phan tu nhap vao vao vi tri ngau nhien trong mang\n");
		printf("6. Xoa phan tu tai vi tri nhap vao\n");
		printf("7. Sap xep mang theo thu tu giam dan\n");
		printf("8. Nhap vao phan tu va tim kiem phan tu co thuoc mang khong\n");
		printf("9. Xoa toan bo phan tu trung lap, chi hien thi mot lan\n");
		printf("10. Dao nguoc thu tu cac phan tu co trong mang\n");
		printf("11. Thoat\n");
		printf("Lua chon cua ban la: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Moi ban nhap so phan tu cua mang(<=100): ");
				scanf("%d", &n);
				if(n<=0){
						printf("Moi ban nhap lai so phan tu cua mang(>0): ");
						scanf(("%d"), &n);
				}
				else{
					printf ("Moi ban nhap gia tri cac phan tu:\n ");
					for (int i=0;i<n;i++){
						printf("Phan tu %d: ", i+1);
						scanf("%d", &arr[i]);
					}
				}
				break;
			case 2:
				printf("Cac phan tu hien co trong mang la: ");
				for (int i=0;i<n;i++){
					printf("%d  ", arr[i]);
				}
				break;
			case 3:
                for (int i = 0; i < n; i++) {
                    if (isprime(arr[i])) {
                        count++;
                    }
                }
                printf("Mang co %d so nguyen to", count);
                break; 
			case 4:
				for (int i = 0;i<n;i++){
					for(int j=0;j<n-1-i;j++){
						if(arr[j]>arr[j+1]){
							int temp = arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=temp;
						}
					}
				}
				printf("Gia tri nho thu hai trong mang la: %d", arr[1]);
				break;
			case 5:
				currentlength = n;  
    			printf("\nNhap gia tri phan tu can them: ");
    			scanf("%d", &value);
    			printf("Nhap vi tri can them (0 den %d): ", currentlength-1);
    			scanf("%d", &addindex);
    			if (addindex < 0 || addindex > currentlength) {
        			printf("Vi tri khong hop le\n");
}   
				else {
        			if (addindex == currentlength) {
            			arr[currentlength] = value;
            			currentlength++;  
} 
					else {
            			for (int i = currentlength; i > addindex; i--) {
                			arr[i] = arr[i - 1];
            		}
            			arr[addindex] = value;  
            			currentlength++;  
        }
        			printf("\nMang sau khi them phan tu: ");
        			for (int i = 0; i < currentlength; i++) {
            			printf("%d ", arr[i]);
        }
        			printf("\n");
        		}
        		break;
        	case 6:
        	 	printf("Nhap gia tri phan tu can xoa: ");
                scanf("%d", &value);
                found = -1;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        for (int j = i; j < n - 1; j++) {
                            arr[j] = arr[j + 1];
                        }
                        n--;
                        found++;
                        printf("Phan tu %d da duoc xoa khoi mang.\n", value);
                        break;
                    }
                }
                if (found==-1) {
                    printf("Phan tu %d khong tim thay trong mang.\n", value);
                }
                break;
            case 7:
			case 10:
				printf("Thu tu dao nguoc cua cac phan tu trong mang la: ");
				for (int i=n-1;i>=0;i--){
					printf("%d", arr[i]);
				}
				break;			
			case 11:
				printf("Thoat chuong trinh");
				return 0;
			default:
				printf("Lua chon khong hop le vui long chon lai");
}			
}
 	return 0;
 }
