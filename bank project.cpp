#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct user
{
    char phone[10];
    char name[30];
    char account_no[15];
    char pass[15];
    float balance; 
};
int cont;
int main()
{
    struct user usr,usr1;
    FILE *fp;
    char filename[50],phone[10],pass[15],ph[10];
    int option,choice;
    float amount;
    printf("what do you want to do?");
    printf("\n 1.Register an account");
    printf("\n 2.Login to an account");
    printf("\n Enter Choice:\t");
    scanf("%d",&option); 
    if(option==1)
    {
        system("cls");
        printf("\nEnter your account no:\t");
        scanf("%s",&usr.account_no);
        printf("\nEnter your name:\t");
        scanf("%s",&usr.name);
        printf("\nEnter your phone no:\t");
        scanf("%s",&usr.phone);
		printf("\nEnter your new password:\t");
        scanf("%s",&usr.pass);
        usr.balance=0;
		strcpy(filename,usr.phone);
		fp=fopen(strcat(filename,".txt"),"wb");
		fwrite(&usr,sizeof(struct user),1,fp);
		if(fwrite!=0)
		{
			printf("\n\n Account successfully registered");
		}
		else
		{
			printf("something went wrong please try again");
		}
	}
	if(option==2)
	{
		system("cls");
		printf("\nphone no:\t");
		scanf("%s",phone);
		printf("\npassword:\t");
		scanf("%s",pass);
		strcpy(filename,phone);
		fp=fopen(strcat(filename,".txt"),"rb");
		if(fp==NULL)
		{
			printf("\n Account number not registered");
		}
		else
		{
			fread(&usr,sizeof(struct user),1,fp);
			fclose(fp);
			if(strcmp(pass,usr.pass)==0&&strcmp(phone,usr.phone)==0)
			{
				printf("\n\n Welcome %s",usr.phone);
				printf("\npress 1 to continue");
				scanf("%d",&cont);
				while(cont==1)
				{
					system("cls");
					printf("\n press 1 to check balance");
					printf("\n press 2 to deposit an amount");
					printf("\n press 3 to withdraw");
					printf("\n press 4 to transfer the balance");
					printf("\n press 5 to change the password");
					printf("\n\n Your choice:");
					scanf("%d",&choice);
					
					switch(choice)
					{
						case 1:
							printf("\n Your current balance is Rs %.2f",usr.balance);
							break;
						case 2:
							printf("\n enter the amount");
							scanf("%f",&amount);           
							usr.balance=amount+usr.balance;
							fp=fopen(filename,"wb");
							fwrite(&usr,sizeof(struct user),1,fp);
							printf("\n Succesfully deposited.");
							printf("\n New balance is Rs.%.2f",usr.balance);
							fclose(fp);
							break;
						case 3:
							printf("\n enter the amount");
							scanf("%f",&amount); 
							if(usr.balance>amount||usr.balance==amount)
							{          
							usr.balance=usr.balance-amount;
							fp=fopen(filename,"wb");
							fwrite(&usr,sizeof(struct user),1,fp);
							if(fwrite!= NULL)
							printf("\n you withdrew Rs.%.2f",amount);
							printf("\n New balance is Rs.%.2f",usr.balance);
							fclose(fp);
							}
							else
							{
								printf("\nInsufficient balance");
							}
							break;
						case 4:
							printf("\n please enter the phone number");
							scanf("%s",&ph);
							printf("\n Please enter the amount to transfer:");
							scanf("%f",&amount);
							strcpy(filename,ph);
							fp=fopen(strcat(filename,".txt"),"rb+");
							if(fp==NULL)
							{
								printf("\n account number not found");
							}
							else
							{
								fread(&usr1,sizeof(struct user),1,fp);
								fclose(fp);
								if(amount>usr.balance)
									printf("\n Insufficient balance");
								else
								{
									
										fp=fopen(filename,"rb");
									if(fp==NULL)
									{
										printf("\n Phone number not registered");
										return 0;
									}
									fread(&usr1,sizeof(struct user),1,fp);
									fclose(fp);
									fp=fopen(filename,"wb");
									usr1.balance=usr1.balance+amount;
									fwrite(&usr1,sizeof(struct user),1,fp);
									fclose(fp);
									if(fwrite!=NULL)
									{
										printf("\n you have successfully transfered Rs.%.2f to %s",amount,ph);
										strcpy(filename,usr.phone);
										fp=fopen(strcat(filename,".txt"),"wb");
										usr.balance=usr.balance-amount;
										printf("\n Your new balance is Rs.%.2f",usr.balance);
										fwrite(&usr,sizeof(struct user),1,fp);
										fclose(fp);
									}
							    }
							}
							break;
						case 5:
							printf("\n Please enter your new password:\t");
							scanf("%s",pass);
							fp=fopen(filename,"wb");
							strcpy(usr.pass,pass);
							fwrite(&usr,sizeof(struct user),1,fp);
							if(fwrite!=NULL)
							printf("\n Password changed successfully");
							break;
						default:
							printf("\n Invalid option");
					}
					printf("\n 1-continue");
					printf("\n 0-exit");
					scanf("%d",&cont);
				}
			}
			else
			{
				printf("\n invalid password");
			}	
		}
	}
		if(option!=1 && option!=2)
		{
			printf("\n invalid input");
		}
		printf("\n\t{*******************Thank You*******************}");
		return 0;
}

