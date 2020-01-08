#include <iostream>

using namespace std;

int main() {
  // Declare your variables
	int digit=0;
	cin >> digit;
	int num1[digit], num2[digit], num3[digit+1];
	for (int i = 0; i<digit; i++){
		cin >> num1[i];
	}

	for (int i = 0; i<digit; i++){
		cin >> num2[i];
	}

	int temp= 0;
	for (int i = digit-1; i >= 0; i--){

		num3[i+1]=(int(num1[i])+int(num2[i])+temp)%10;
		if((num1[i]+num2[i]+temp) > 9){
			temp =1;
		}
		else{
			temp =0;
		}
		
	}
	num3[0] = temp;

	
	for (int i = 0; i<digit; i++){
		if(i == 0 && num3[0] == 0){
		}
		else{
			cout << num3[i] << " ";
		}
	}
	cout << num3[digit]<<endl;
	

  return 0;
}
