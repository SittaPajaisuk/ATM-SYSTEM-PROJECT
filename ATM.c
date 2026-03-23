#include<stdio.h> 
#include<string.h> 
#include<windows.h>
#include<stdlib.h>
int i;
FILE *fptr;

struct money{
	int with;
	int depos;
	int current;
	int newbalance;
};

struct money mny;

void checkFile(){
	fptr = fopen("aacountdata.dat","rb");
	if (fptr == NULL){
		fptr = fopen("aacountdata.dat","wb");
		mny.current = 1000;
		fwrite(&mny.current,sizeof(struct money),1,fptr);
	}
	fclose(fptr);
	
}

void saveFile(int *saveBalance){
	fptr = fopen("aacountdata.dat","wb");
	mny.current = saveBalance;
	fwrite(&mny.current,sizeof(struct money),1,fptr);
	fclose(fptr);
}

struct choice{
	int ATMmenu;
	int withdrawal;
	int deposit;
	int check;
	int cont;
};

struct choice ch;

void printATM(){
		printf("------------------------------------------------\n");
		printf("	    ##     ########  ##       ##\n");
		printf("	   ####       ##     ####   ####\n");
		printf("	  ##  ##      ##     ## ## ## ##\n");
		printf("	 ########     ##     ##  ###  ##\n");
		printf("	##      ##    ##     ##   #   ##\n");
		printf("------------------------------------------------\n");
}

void printWelcome(){
	printf("-----------------------------------------------------------------------------------------\n");
	printf("	##     #     ##  #######  ##        #####    ######   ##       ##  ######\n");
	printf("	 ##   ###   ##   ##       ##       ##   ##  ##    ##  ####   ####  ##\n");
	printf("	  ## ## ## ##    #######  ##       ##       ##    ##  ## ## ## ##  ###### \n");
	printf("	   ###   ###     ##       ##       ##   ##  ##    ##  ##  ###  ##  ##\n");
	printf("	    #     #      #######  #######   #####    ######   ##   #   ##  ######\n");
	printf("-----------------------------------------------------------------------------------------\n");
}

void printIncorrect(){
	printf("----------------------------------------------------------------------------------------------\n");
	printf("	####  ##    ##   #####    ######   ######   ######   ######   #####   ########\n");
	printf("	 ##   ####  ##  ##   ##  ##    ##  ##   ##  ##   ##  ##      ##   ##     ##\n");
	printf("	 ##   ## ## ##  ##       ##    ##  ######   ######   ######  ##          ##\n");
	printf("	 ##   ##  ####  ##   ##  ##    ##  ##  ##   ##  ##   ##      ##   ##     ##\n");
	printf("	####  ##   ###   #####    ######   ##   ##  ##   ##  ######   #####      ##\n");
	printf("----------------------------------------------------------------------------------------------\n");
}

void printExit(){
	printf("-----------------------------------------------\n");
	printf("	######  ##   ##  ####  ########\n");
	printf("	##       ## ##    ##      ##\n");
	printf("	######    ###     ##      ##\n");
	printf("	##       ## ##    ##      ##\n");
	printf("	######  ##   ##  ####     ##\n");
	printf("-----------------------------------------------\n");
}

void printError(){
	printf("######  ######  ######    ######   ######   ##  ##\n");
	printf("##      ##   ## ##   ##  ##    ##  ##   ##  ##  ##\n");
	printf("######  ######  ######   ##    ##  ######   ##  ##\n");
	printf("##      ##  ##  ##  ##   ##    ##  ##  ##\n");
	printf("######  ##   ## ##   ##   ######   ##   ##  ##  ##\n");
}

void processWith(int withdrawal){
	fptr = fopen("aacountdata.dat","rb");
	fread(&mny.current,sizeof (struct money),1,fptr);
	mny.newbalance = mny.current - mny.with;
	saveFile(mny.newbalance);
	printf("--------------------------------------------\n");
	printf("Withdrawal Balance: %d\n",mny.with);
	printf("--------------------------------------------\n");
	printf("Current Balance : %d\n",mny.current);
	printf("--------------------------------------------\n");
	fclose(fptr);
	Sleep(2000);
	printf("Do you wish to perform another transaction?\n");
	printf("YES[1]\n");
	printf("NO[0]\n");
	printf("--------------------------------------------\n");
	printf("Enter your choice : ");
	scanf("%d",&ch.cont);
	if (ch.cont == 1){
		system("cls");
		menuATM();
	}
	
	else if(ch.cont == 0){
		system("cls");
		printExit();
	}
}

void checkWith(){
	fptr = fopen("aacountdata.dat","rb");
	fread(&mny.current,sizeof (struct money),1,fptr);
	if (mny.current < mny.with)
		insuffBalance();
	else
		processWith(mny.with);
	fclose(fptr);
}

void insuffBalance(){
	system("cls");
	printf("--------------------------------------------\n");
	printf("	Your balance is insufficient!!\n");
	printf("--------------------------------------------\n");
	Sleep(3000);
	system("cls");
	printExit();
}

void cashWith(){
	printf("----------------------------\n");
	printf("	Cash Withdrawal\n");
	printf("----------------------------\n");
	printf("1. 100 Baht\n");
	printf("2. 400 Baht\n");
	printf("3. 500 Baht\n");
	printf("4. 900 Baht\n");
	printf("5. 1000 Baht\n");
	printf("6. 5000 Baht\n");
	printf("7.Specify the amount manually\n");
	printf("----------------------------\n");
	printf("Enter your choice(1-7): ");
	scanf("%d",&ch.withdrawal);
	switch(ch.withdrawal){
		case 1:
			system("cls");
			mny.with = 100;
			checkWith();
			break;
		case 2:
			system("cls");
			mny.with = 400;
			checkWith();
			break;
		case 3:
			system("cls");
			mny.with = 500;
			checkWith();
			break;
		case 4:
			system("cls");
			mny.with = 900;
			checkWith();
			break;
		case 5:
			system("cls");
			mny.with = 1000;
			checkWith();
			break;
		case 6:
			system("cls");
			mny.with = 5000;
			checkWith();
			break;
		case 7:
			system("cls");
			printf("-----------------------\n");
			printf("Enter the amount : ");
			scanf("%d",&mny.with);
			checkWith();
			break;
		default:
			system("cls");
			printError();
			break;
	}
}

void processDepos(int Depos){
	fptr = fopen("aacountdata.dat","rb");
	fread(&mny.current,sizeof (struct money),1,fptr);
	mny.newbalance = mny.current + mny.depos;
	saveFile(mny.newbalance);
	printf("--------------------------------------------\n");
	printf("Deposit Balance: %d\n",mny.depos);
	printf("--------------------------------------------\n");
	printf("Current Balance : %d\n",mny.current);
	printf("--------------------------------------------\n");
	fclose(fptr);
	Sleep(2000);
	printf("Do you wish to perform another transaction?\n");
	printf("YES[1]\n");
	printf("NO[0]\n");
	printf("--------------------------------------------\n");
	printf("Enter your choice : ");
	scanf("%d",&ch.cont);
	if (ch.cont == 1){
		system("cls");
		menuATM();
	}
	
	else if(ch.cont == 0){
		system("cls");
		printExit();
	}
	else{
		system("cls");
		printError();
	}
}

void cashDepos(){ 
	printf("----------------------------\n");
	printf("	Cash Deposit\n");
	printf("----------------------------\n");
	printf("1. 100 Baht\n");
	printf("2. 400 Baht\n");
	printf("3. 500 Baht\n");
	printf("4. 900 Baht\n");
	printf("5. 1000 Baht\n");
	printf("6. 5000 Baht\n");
	printf("7.Specify the amount manually\n");
	printf("----------------------------\n");
	printf("Enter your choice(1-4): ");
	scanf("%d",&ch.deposit);
	switch(ch.deposit){
		case 1:
			system("cls");
			mny.depos = 100;
			processDepos(mny.depos);
			break;
		case 2:
			system("cls");
			mny.depos = 400;
			processDepos(mny.depos);
			break;
		case 3:
			system("cls");
			mny.depos = 500;
			processDepos(mny.depos);
			break;
		case 4:
			system("cls");
			mny.depos = 900;
			processDepos(mny.depos);
			break;
		case 5:
			system("cls");
			mny.depos = 1000;
			processDepos(mny.depos);
			break;
		case 6:
			system("cls");
			mny.depos = 5000;
			processDepos(mny.depos);
			break;
		case 7:
			system("cls");
			printf("-----------------------\n");
			printf("Enter the amount : ");
			scanf("%d",&mny.depos);
			system("cls");
			processDepos(mny.depos);
			break;
		default:
			system("cls");
			printError();
			break;
	}
}

void checkBal(){
	fptr = fopen("aacountdata.dat","rb");
	fread(&mny.current,sizeof (struct money),1,fptr);
	printf("--------------------------------------------\n");
	printf("	Check balance\n");
	printf("--------------------------------------------\n");
	printf("Current Balance : %d\n",mny.current);
	printf("--------------------------------------------\n");
	fclose(fptr);
	Sleep(2000);
	printf("Do you wish to perform another transaction?\n");
	printf("YES[1]\n");
	printf("NO[0]\n");
	printf("--------------------------------------------\n");
	printf("Enter your choice : ");
	scanf("%d",&ch.cont);
	if (ch.cont == 1){
		system("cls");
		menuATM();
	}
	
	else if(ch.cont == 0){
		system("cls");
		printExit();
	}
	else{
		system("cls");
		printError();
	}
	
}

void menuATM(){
	printf("----------------------------\n");
	printf("	ATM Main Menu\n");
	printf("----------------------------\n");
	printf("1.Cash Withdrawal\n"); 
	printf("2.Cash Deposit\n"); 
	printf("3.Check balance\n");
	printf("4.Exit\n");
	printf("----------------------------\n");
	printf("Enter your choice(1-4): ");
	scanf("%d",&ch.ATMmenu);
	switch(ch.ATMmenu){
		case 1:	
			system("cls");
			cashWith();
			break;
		case 2:
			system("cls");
			cashDepos();
			break;
		case 3:
			system("cls");
			checkBal();
			break;
		case 4:
			system("cls");
			printExit();
			break;
		default:
			system("cls");
			printError();
			break;		
	}
}	
void login(){
	char name[50],password[10];
	printf(" Enter Name : ");
	scanf("%s", name);
	printf(" Enter Password : ");
	scanf("%s", password);
	if (strcmp(name,"admin") == 0 && strcmp(password,"1234") == 0){
		system("cls");
		printWelcome();
		checkFile();
		Sleep(1500);
		system("cls");
		menuATM();
	}
	else{
		system("cls");
		for (i=0;i<3;i++){
			printIncorrect();
			printf("Enter Name : ");
			scanf("%s", name);
			printf("Enter Password : ");
			scanf("%s", password);
			if (strcmp(name,"admin") == 0 && strcmp(password,"1234") == 0){
				system("cls");
				printWelcome();
				checkFile();
				Sleep(1500);
				system("cls");
				menuATM();
				break;
			}
			else{
				system("cls");
				continue;
			}
		}
		if (i == 3){
			printExit();
		}
	}
}	


main(){
	login();
	getch();
}
