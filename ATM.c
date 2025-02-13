#include<stdio.h>
#include<string.h>
void deposit();
void mainmenu();
void balance(int);
void withdraw();
void transactions();
void pinchange();
struct user{
	char name[20];
	char pass[6];
	int balance;
	int deposit[10];
	int withdraw[10];
}user1={"Bhanu","1234",0};
int d_i=0,w_i=0;
void pinchange(){
	printf("\n\t\tPlease enter your old pin");
	char ch[10];
	scanf("%s",ch);
	if(strcmp(ch,user1.pass)==0){
		printf("\n\t\tPlease enter new pin");
		scanf("%s",ch);
		strcpy(user1.pass,ch);
		printf("PIN updated successfully");
	}
	else{
		printf("Unauthorised Access");
		mainmenu();
	}
}
void transactions(){
	printf("\n\t\tPlease enter your pin");
	char pin[10];
	int i=0;
	scanf("%s",pin);
	if(strcmp(pin,user1.pass)==0){
		printf("\n\t\tList of Deposits");
		for(i=0;i<d_i;i++){
			printf("Deposit :%d=%d\n",i,user1.deposit[i]);
		}
		for(i=0;i<w_i;i++){
			printf("Withdrawals :%d=%d\n",i,user1.withdraw[i]);
		}
	}
	else{
		printf("Unauthorized Access");
		mainmenu();
	}
}
void withdraw(){
	printf("\n\t\tplease Enter your pin");
	char pin[10];
	scanf("%s",pin);
	if(strcmp(pin,user1.pass)==0){
		printf("\n\n\t\tPlease enter the amount to withdraw");
		int w;
		scanf("%d",&w);
		if(user1.balance>w){
			user1.balance-=w;
			user1.withdraw[w_i++]=w;
			printf("\n\tPlease collect your cash",w);
			printf("\n\t1>Check the current balance");
			printf("\n\t2>Go back to main-menu");
			int ch;
			scanf("%d",&ch);
			switch(ch){
				case 1:balance(1);
				       break;
				case 2:mainmenu();
				       break;
			}
		}
	}
	else{
		printf("\n\tIncorrect password");
		mainmenu();
	}
}
void balance(int n){
	if(n==1){
		printf("\n\t\tYour Current balance is:%d",user1.balance);
	}
	else{
		printf("\n\t\tEnter your pin to check balance");
        char pin[10];
        char ch;
        int i=0;
		while((ch=getch())!='\r'&&i<6){
			putch('*');
			pin[i++]=ch;
		}		
		pin[i]='\0';
		if(strcmp(pin,user1.pass)==0){
			printf("\nYour current balance is:%d",user1.balance);
		}
		else{
			printf("\nIncorrect pin");
			return;
		}
	}
}
void deposit(){
	system("cls");
	printf("\n\n\t\tplease Enter your password");
	    char pin[100];
	    int i=0;
	    char ch;
	    while((ch=getch())!='\r'&&i<6){
	    	putch('*');
	    	pin[i++]=ch;
		}
		pin[i]='\0';
		if(strcmp(pin,user1.pass)==0){
			printf("\n\t\twelcome %s",user1.name);
			printf("\n\t\tEnter Deposit amount");
			int dep;
			scanf("%d",&dep);
			user1.balance+=dep;
			user1.deposit[d_i++]=dep;
			while(1){
				printf("\n\t\t1>See your current balance");
				printf("\n\t\t2>Go back to main menu");
				int ch;
				scanf("%d",&ch);
				switch(ch){
					case 1:balance(1);
					       break;
					case 2:mainmenu();
				}
			}
		}
		else{
			printf("\n\t\tIncorrect password");
			mainmenu();
		}
	
}
void main(){
	mainmenu();
}
void mainmenu(){
	while(1){
		printf("\n\n\n\t\t\t********************************");
		printf("\n\t\t\t*    Welcome To ATM Machine    *");
		printf("\n\t\t\t********************************");
		printf("\n\n\n\t\t\t1>Deposit");
		printf("\n\t\t\t2>Withdraw");
		printf("\n\t\t\t3>Balance Enquiry");
		printf("\n\t\t\t4>Transaction History");
		printf("\n\t\t\t5>Pin Change");
		printf("\n\t\t\t6>Cancel");
		printf("\n\n\t\t\tPlease Enter your choice");
		int ch;
		scanf("%d",&ch);
		switch(ch){
			case 1:deposit();
			       break;
			case 2:withdraw();
			       break;
			case 3:balance(0);
			       break;
			case 4:transactions();
			       break;
			case 5:pinchange();
			       break;
			case 6:return 0;
			default:printf("\n\t\tInvalid choice");
		}

	}
}
