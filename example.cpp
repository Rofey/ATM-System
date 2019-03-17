#include <stdio.h>
#include <fstream>


struct People{
	//string name;
	int number;
	int password;
	int balance;

};

void balanceEnquiry(struct People people[], int index){
	printf("Your Remaining Balance is: %d\n", people[index].balance);
}


void fastCash(struct People people[], int index) {
	int n;
	printf("\n1. 500");
	printf("\n2. 1000");
	printf("\n3. 3000");
	printf("\n4. 5000");
	printf("\n5. 7000");

	scanf("%d", &n);
	switch(n) {
		case 1:
			people[index].balance -= 500;
			balanceEnquiry(people, index);
			break;


		case 2:
			people[index].balance -= 1000;
			balanceEnquiry(people, index);
			break;

		case 3:
			people[index].balance -= 3000;
			balanceEnquiry(people, index);
			break;

		case 4:
			people[index].balance -= 5000;
			balanceEnquiry(people, index);
			break;

		case 5:
			people[index].balance -= 7000;
			balanceEnquiry(people, index);
			break;




	}
}


void deposit(struct People people[], int index) {
	printf("Enter the amount you want to deposit");
	int amount;
	scanf("%d", &amount);
	people[index].balance += amount;
	balanceEnquiry(people, index); 

}
void withdrawal(struct People people[], int index ) {

	printf("Enter the amount you want to withdraw (in multiples of 500");
	int amount;
	scanf("%d", &amount);
	if(amount%500 == 0) {
		people[index].balance -= amount;
		balanceEnquiry(people, index);
	} else {
		withdrawal(people, index);
	}

}



void transfer() {}


void menu(struct People people[], int index) {
	printf("1. Fast Cash\n");
	printf("2. Balance Enquiry\n");
	printf("3. Deposit\n");
	printf("4. Withdrawal\n");
	printf("5. Transfer\n");
	printf("6. Change Pin\n\n\n");
	printf("\tPress your desired key: ");

	int n;
	scanf("%d", &n);
	switch(n) {
		case 1:
			fastCash(people, index);
			break;

		case 2:
			//balanceEnquiry();
			break;

		case 3:
			deposit(people, index);
			break;

		case 4:
			withdrawal(people, index);
			break;

		case 5:
			transfer();
			break;

		case 6:
			//changePin();
			break;

	}
}


int main() {
	People people[2];
	int password;
	people[0].number = 1;
	people[0].password = 1234;
	people[0].balance = 6000;

	people[1].number = 2;
	people[1].password = 4321;
	people[1].balance = 1000;

	char option = 'y';

	int number;
	printf("Enter your Account Number\n");
	scanf("%d", &number);
	switch(number) {
		case 1:
			printf("Enter your Password\n");
			scanf("%d", &password);
			if(password == people[0].password) {
				printf("Welcome Hamza\n");
				do {
					menu(people, 0);
					printf("Do you want to make another transaction?(y/n) \n");
				} while(option == 'y');

			} else {
				printf("Your password is incorrect!\n");
				main();
			}

			break;

		case 2:
			printf("Enter your Password\n");
			scanf("%d", &password);
			if(password == people[1].password) {
				printf("Welcome Bilal\n");
				do {
					menu(people, 0);
					printf("Do you want to make another transaction?(y/n) \n");
				} while(option == 'y');


			} else {
				printf("Your password is incorrect!\n");
				main();
			}

		break;

	}

}