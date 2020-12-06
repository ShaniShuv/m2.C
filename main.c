#include "myBank.h"
#include <stdio.h>
// ******livdok mishtane globali------------------- lo kriti
#ifndef MAX
#define MAX 50
#endif
double bankA [MAX][2] = {{0,0}};
int main(){
	int accountC =0;
	int end = 1;
	
	
	while(end){
		char func=0;
		printf("\nPlease choose a transaction type: \nO-Open Account \nB-Balance Inquiry \nD-Deposit \nW-Withdrawal \nC-Close Account \nI-Interest \nP-Print \nE-Exit\n");
		if(!(scanf(" %c", &func)==1)){
			printf("Invalid transaction type\n");
		}
		else if(!(func-'O')){
			if(accountC-MAX){
				double deposit=0;
				printf("Please enter amount for deposit: \n");
				if((scanf(" %lf", &deposit)==0)){
					printf("Failed to read the amount\n");
				}
				else{
					deposit *= 100;
					int temp = deposit;
					deposit = (double)temp/100;
					if(deposit>=0){
						openA(bankA, deposit);
						accountC++;
					}
					else{
						printf("Invalid Amount\n");
					}
				}
			}
			else{
				printf("We don't have availble bank account \n");
			}
		}
		else if(!(func-'B')){
			int bankAN=0;
			printf("Please enter account number:\n");
			if(!(scanf(" %d", &bankAN)==1)){
				printf("Failed to read the account number\n");;
			}
			else{
				bankAN-=900;
				if(0<bankAN && MAX>= bankAN){
					if( bankA[bankAN][1]==1){
						getBalance(bankA, bankAN);
					}
					else{
						printf("This account is closed\n");
					}
				}
				else{
					printf("Invalid bank account\n");
				}
			}		
		}
		else if(!(func-'D')){
			int bankAN=0;
			printf("Please enter account number:  \n");
			if((scanf(" %d", &bankAN)==1)){
				bankAN-=900;
				double amount=0;
				if(0<bankAN && MAX>= bankAN){
					if(!bankA[bankAN][1]){
						printf("This account is closed \n");
					}
					else{
						printf("Please enter the amount to deposit: \n");
						if(!(scanf(" %lf", &amount)==1)){
							printf("Failed to read amount\n");
						}
						else if(amount<0){
							printf("Cannot deposit a negative amount\n");
						}
						else{
							amount *= 100;
							int temp = amount;
							amount = (double)temp/100;
							deposit(bankA, bankAN, amount);
						}
					}
				}
				else{
					printf("Invalid account number\n");
				}
			}
			else{
				printf("Failed to read account number\n");
			}
			
				
		}
		else if(!(func-'W')){
			int bankAN=0;
			printf("Please enter account number: \n");
			if(!(scanf(" %d", &bankAN)==1)){
				printf("Failed to read account number\n");
			}
			else{
				bankAN-=900;
				if(0>bankAN || MAX< bankAN){
					printf("Invalid account number \n");
				}
				else if( !(bankA[bankAN][1])){
					printf("This Account is closed");
				}
				else{
					double amount=0;
					printf("Please enter the amount to withdraw: \n");
					scanf(" %lf", &amount);
					amount *= 100;
					int temp = amount;
					amount = (double)temp/100;
					if(bankA[bankAN][0]-amount<0){
						printf("Cannot withdraw more than the balance\n");
					}
					else{
						withdrawal(bankA, bankAN, amount);
					}	
				}
			}
		}
		else if(!(func-'C')){
			int bankAN=0;
			printf("Please enter account number: \n");
			if(!(scanf(" %d", &bankAN)==1)){
				printf("Failed to read account number\n");;
			}
			else{
				bankAN-=900;
				if(0<bankAN && MAX>= bankAN ){
					if(bankA[bankAN][1]){
						closeA(bankA, bankAN);
						accountC--;
					}
					else{
						printf("This Account is already closed");
					}
				}
				else{
					printf("Invalid account number\n");
				}
			}		
		}
		else if(!(func-'I')){
			double interestR =0;
			int i =0;
			printf("Please enter interest rate: \n");
			if((scanf(" %d", &i)==0)){
				printf("Failed to read the interest rate\n");
			}
			else{
				interestR = (double) i/ 100;
				interestR+=1;
				if(interestR<=-1){
					printf("Not a valid rate\n");
				}
				else if(0<accountC){
					interestRate(bankA, interestR);
				}
				
			}		
		}
		else if(!(func-'P')){
			if(0<accountC){
				printAll(bankA);
			}
			else{
				printf("There is no valid bank account \n");
			}
			
		}
		else if(!(func-'E')){
			closeAll(bankA);
			end=0;
			accountC=0;
		}
		else{
			printf("Invalid transaction type\n");
		}
		

	}
	return 0;
}
