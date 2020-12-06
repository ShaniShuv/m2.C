#include "myBank.h"
#include <stdio.h>

#ifndef MAX
#define MAX 50
#endif

void openA(double bankA[][2], double deposit){
	int accountNum=1;
	for(int i=1; i<=MAX; i++){
		if(!bankA[i][1]){
			accountNum=i;
			break;
		}
	}
	bankA[accountNum][0] = deposit;
	bankA[accountNum][1] = 1;
	printf("New account number is: %d \n", accountNum+900);
	
}
void getBalance(double bankA[][2], int accountNum){
	printf("The balance of account number %d is: %0.2lf \n", accountNum+900 , bankA[accountNum][0]);
}
void deposit(double bankA[][2], int accountNum, double deposit){
	bankA[accountNum][0] += deposit;	
	printf("Account number: %d, balance: %0.2lf \n", accountNum+900 , bankA[accountNum][0]);
}
void withdrawal(double bankA[][2], int accountNum, double withdrawal){
	bankA[accountNum][0] -= withdrawal;	
	printf("The new balance is:%0.2lf \n", bankA[accountNum][0]);
}
void closeA(double bankA[][2], int accountNum){
	bankA[accountNum][1] = 0;
	printf("Closed account number: %d", accountNum+900);		

}
void interestRate(double bankA [][2], double rate){
	for(int i=1; i<=MAX; i++){
		bankA[i][0] *= rate;
	}
}
void printAll(double bankA[][2]){
	for(int i=1; i<=MAX; i++){
		if(bankA[i][1]==1){
			printf("Account number: %d, balance: %0.2lf \n", i+900 , bankA[i][0]);
		}
	}
}
void closeAll(double bankA[][2]){
	for(int i=1; i<=MAX; i++){
		bankA[i][1] = 0;
	}
}
