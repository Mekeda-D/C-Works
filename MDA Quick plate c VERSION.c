#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>



void mainmenu();
void administration();
void customer_sign_up();
void customer_login();
void generate_order_numbers_bk();     
void generate_order_numbers_ig();
void generate_order_numbers_kfc();
       
void displayordersbk(); 
void displayordersig();
void displayorderskfc();
void Island_Grill();
void Burger_King();
void Kentucky_Fried_Chicken();
void restaurants();

void KFCPayment();
void IGPayment();
void BKPayment();
void KFC_menu();
void IG_menu();
void BK_menu();
void Customer_Profiles();
void vieworders();



struct customers
{
    char fname[100], lname[100], username[100], password[100], email_address[100], phonenum[100], address[100];  
	int id;                  
    struct customers *nextptr;       
}*node, profile[400];


struct ordersbk
{
    int quantity, price, itemno, cost, BkGrand_total;
	char foodname[200];                  
    struct ordersbk *nextptr;       
}*stnode, *mtnode, *ntnode, *dtnode, *ltnode, *btnode, *ktnode;

struct ordersig
{
    int quantity, price, itemno, cost, IgGrand_total;
	char foodname[200];                  
    struct ordersig *nextptr;       
}*inode, *snode, *lnode, *anode, *dnode, *gnode;

struct orderskfc
{
    int quantity, price, itemno, cost, KfcGrand_total;
	char foodname[200];                  
    struct orderskfc *nextptr;       
}*knode, *ynode, *fnode, *cnode, *hnode, *enode;


int main()
{
	mainmenu();
	
	return 0;
}

void mainmenu(void)
{
	char username[15], password[12];
    int wait, rest, choice;
	
	system("cls");
	printf("                                        **************************************************************************\n");
	printf("                                                                   WELCOME TO QUICK PLATE\n");
	printf("                                        ***************************************************************************\n\n\n");
	printf("		1. ADMINISTRATION LOGIN--> \n\n		2. CUSTOMER SIGN UP--> \n\n		3. CUSTOMER LOGIN--> \n\n		4. Exit--> \n\n\n	Enter Your Choice --->\t");
	scanf("%d",&choice);
	
	if(choice==1)
	{
			
		system("cls");
		
		printf("\n\nEnter your username:\t");
	    scanf("%s",username);
	 
	    printf("\n\nEnter your password:\t");
	    scanf("%s",password);
	 
	    if(strcmp(username,"M.D-071601")==0 && strcmp(password,"%pV&44")==0 || strcmp(username,"D.W-060101")==0 && strcmp(password,"%pV&44")==0 || strcmp(username,"A.J-121701")==0 && strcmp(password,"%pV&44")==0)
		{
		        //Remember your password: % park VISA & 4 4
		        
		        	printf("\n\nWelcome!\n\nLogin Success!\n\n");
		        	for(wait=0;wait<=80000;wait++)
					{
						printf("\rIn progress : %d",wait/1000);
					}
					system("cls");
		        	
		        	administration();
   		}
				
		else if (strcmp(username,"M.D-071601")==0 && strcmp(password,"%pV&44")!=0 || strcmp(username,"D.W-060101")==0 && strcmp(password,"%pV&44")!=0 || strcmp(username,"A.J-121701")==0 && strcmp(password,"%pV&44")!=0)
		{
		    		printf("\nWRONG PASSWORD!   TRY AGAIN.\n\n");
		    		for(wait=0;wait<=80000;wait++)
					{
						printf("\rIn progress : %d",wait/1000);
					}
					mainmenu ();
		}
	
		else if (strcmp(username,"M.D-071601")!=0 && strcmp(password,"%pV&44")==0 || strcmp(username,"D.W-060101")!=0 && strcmp(password,"%pV&44")==0 || strcmp(username,"A.J-121701")!=0 && strcmp(password,"%pV&44")==0)
		{
	    	printf("\nUSER DOESN'T EXIST!    TRY AGAIN. \n\n");
	    	for(wait=0;wait<=80000;wait++)
					{
						printf("\rIn progress : %d",wait/1000);
					}
					mainmenu ();
		}
		
		else if (strcmp(username,"M.D-071601")!=0 && strcmp(password,"%pV&44")!=0 || strcmp(username,"D.W-060101")!=0 && strcmp(password,"%pV&44")!=0 || strcmp(username,"A.J-121701")!=0 && strcmp(password,"%pV&44")!=0)
		{
	    	printf("\nNO RECORD OF EITHER USERNAME OR PASSWORD!    TRY AGAIN.\n\n ");
	    	for(wait=0;wait<=80000;wait++)
					{
						printf("\rIn progress : %d",wait/1000);
					}
					mainmenu ();
		}
		
		
	}
	
	else if(choice==2)
	{
		customer_sign_up();
	}
	
	else if(choice==3)
	{
		customer_login();
	}
	
	else if(choice==4)
	{
		system("cls");
		printf("\n\n\n");
		printf("                                     *******************************THANK YOU**************************************\n");

		printf("                                     *****************Feeling HUNGRY ? Call or Walk-In QUICK PLATE*****************\n\n");
		printf("                                                                  CONTACT US:\n");
		printf("                                                   6 Red Hills Road, Kingston 10 Jamaica\n");
		printf("                                                                 876-627-9493\n");
		printf("                                                        customercare@myquickplate.com\n\n\n\n");
		exit(0);
	}
}

void administration(void)
{
    int n, wait, rest;

	
	printf("\n\n");

	printf("************************************************************WELCOME TO THE ADMINISTRATION SECTION***********************************************************************\n\n");
	printf("          1. View Customer Profiles\n\n          2. View previous orders placed\n\n          3. Back To Main Menu \n\n             Enter Your Choice --->\t");

	scanf("%d",&n);
	printf("\n\n");
		

	 if(n==1)
	{
				system("cls");
				
				Customer_Profiles();
	}
	else if(n==2)
	{
				system("cls");
		
				vieworders();
	}
	else if(n==3)
	{
				system("cls");
				
				mainmenu();
	}
	else
	{
		printf("Wrong Input !! PLease Re-enter The Correct Option");
		printf("\n\n");
		for(wait=0;wait<=50000;wait++)
		{
			printf("\rIn progress : %d",wait/500);
		}
		system("cls");
		administration();
	}
	
}

void Customer_Profiles()
{
	char fname[100], lname[100], username[100], password[100], email_address[100], phonenum[100], address[100];
	char view, answer;
	FILE *cpd;
	FILE *ps;
	struct customers temp;
	int i=0,size,j, id, ans, wait;
		
		cpd = fopen("Customer Profile Directory.txt","r");
		printf("\n\n");
		while(fscanf (cpd, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", profile[i].fname, profile[i].lname, profile[i].username, profile[i].password, profile[i].email_address, profile[i].phonenum, profile[i].address, &profile[i].id)!=EOF)
		{
			
			printf("%s\t%s\t%s\t    %s\t    %s\t    %s\t    %s\t    %d\n", profile[i].fname, profile[i].lname, profile[i].username, profile[i].password, profile[i].email_address, profile[i].phonenum, profile[i].address, profile[i].id);
		}
		fclose(cpd);
		
		printf("\n\n\nWould you like to sort these profiles in alphabetical order?\n\nEnter 'y' for yes or 'n' to be taken back to administration\t");
    		scanf(" %c", &answer);
			if(answer=='y')
			{
				
				cpd = fopen("Customer Profile Directory.txt","r");
				if(cpd==NULL)
				{ 
				printf("\n Cannot open the file \n");
				exit(0);
				}
				else 
				{
					
					while(fscanf (cpd, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", profile[i].fname, profile[i].lname, profile[i].username, profile[i].password, profile[i].email_address, profile[i].phonenum, profile[i].address, &profile[i].id)!=EOF)
					{
							i=i+1;  
							
					}
							
							size=i+1;
							
							for(i=1;i<size;++i)
							{
								for(j=0;j<size-i;j++)
								{
									if(strcmp(profile[j+1].fname,profile[j].fname)<0)
									{
										temp=profile[j];
										profile[j]=profile[j+1];
										profile[j+1]=temp;
									}
									else if(!strcmp(profile[j+1].fname,profile[j].fname)<0 && strcmp(profile[j+1].lname,profile[j].lname)<0)
									{
										temp=profile[j];
										profile[j]=profile[j+1];
										profile[j+1]=temp;
									}
			
								}
								
							}
				
				} 
				
				ps=fopen("profiles sorted.txt","w");
				printf("\n\n\n\n");
				for(i=1;i<size;i++)
				{
					fprintf(ps,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", profile[i].fname, profile[i].lname, profile[i].username, profile[i].password, profile[i].email_address, profile[i].phonenum, profile[i].address, profile[i].id);
					printf("%s\t%s\t%s\t    %s\t    %s\t    %s\t    %s\t    %d\n", profile[i].fname, profile[i].lname, profile[i].username, profile[i].password, profile[i].email_address, profile[i].phonenum, profile[i].address, profile[i].id);
				}	
				fclose(ps); 
				
				fclose(cpd);
				
			printf("\n\n\n The file is sorted successfully and saved in 'profiles sorted.txt' \n");
			
		}
		else if(answer=='n')
		{
			system("cls");
			administration();
		}
		
		printf("\n\n Do you want to go back to main menu or administration?");
		printf("\n Enter: [1] for main menu");
		printf("\n Enter: [2] for administration");
		printf("\n Choice ------>\t ");
		scanf ("%d", &ans);
	
		if(ans == 1)
			{
				printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				mainmenu();
			}
		
		else if(ans == 2)
			{
				printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				administration();
			}
}

void vieworders()
{
	FILE *view;
	char viw;
	int rest, wait, ans;
		
		printf("\n\nWhich restaurant's order log would you like to view?\n");
		printf("[1] Kentucky Fried Chicken\n");
		printf("[2] Island Grill\n");
		printf("[3] Burger King\n");
		printf("    select-->\t");
		scanf("%d",&rest);
		
		if (rest == 1)
		{
			printf("\n\n");
			for(wait=0;wait<=100000;wait++)
			{
				printf("\rIn progress : %d",wait/1000);
			}
				system("cls");
				
				view = fopen("kfcorders.txt","rt");
				while((viw=fgetc(view))!=EOF)
				{
					printf("%c",viw);
				}
		fclose(view);
		}
		
		else if (rest == 2)
		{
			printf("\n\n");
			for(wait=0;wait<=100000;wait++)
			{
				printf("\rIn progress : %d",wait/1000);
			}
				system("cls");
				
				view = fopen("igorders.txt","rt");
				while((viw=fgetc(view))!=EOF)
				{
					printf("%c",viw);
				}
				fclose(view);
		}
		
		else if (rest == 3)
		{
			printf("\n\n");
			for(wait=0;wait<=100000;wait++)
			{
				printf("\rIn progress : %d",wait/1000);
			}
				system("cls");
				
				view = fopen("bkorders.txt","rt");
				while((viw=fgetc(view))!=EOF)
				{
					printf("%c",viw);
				}
				fclose(view);
		}
		
		printf("\n\n\n Do you want to go back to main menu or administration?");
		printf("\n Enter: [1] for main menu");
		printf("\n Enter: [2] for administration");
		printf("\n Choice ------>\t ");
		scanf ("%d", &ans);
	
		if(ans == 1)
			{
				printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				mainmenu();
			}
		
		else if(ans == 2)
			{
				printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				administration();
			}
		
}

void customer_login()
{
	char username[100], fname[100], lname[100], fusername[100], fpassword[100];
    char password[12], answer, email_address[100], phonenum[100], address[100];
    int wait, id;
    FILE*cpd;
	
	system("cls");
	
	printf("\n\n*************************************************************Hi! Please enter username and password to login************************************************************\n\n");

		printf("\n\nEnter your username:\t");
    	scanf("%s",username);
    	
    	printf("\n\nEnter your password:\t");
    	scanf("%s",password);
 		
 		cpd = fopen("Customer Profile Directory.txt","r");		
 		
		while (fscanf (cpd, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", fname, lname, fusername, fpassword, email_address, phonenum, address, &id)!=EOF) 
		{
		    if(strcmp(fusername,username)==0 && strcmp(fpassword,password)==0)
			{
		        	printf("\nWelcome! Login Success!\n\n");
		        	
					for(wait=0;wait<=50000;wait++)
					{
						printf("\rIn progress : %d",wait/500);
					}
					
					system("cls");
					
					restaurants();
		 
		    }
				
				else if (strcmp(fusername,username)==0 && strcmp(fpassword,password) !=0)
				{
		    		printf("\nWRONG PASSWORD!");
		    		printf("\n\n\nWould you like to try again? \n\nEnter 'y' if you want to try again \nEnter 'm' if you want to be taken back to main menu \nEnter 's' if you want to sign up \nselect--->\t");
		    		scanf(" %c", &answer);
					if(answer=='y')
					{
						customer_login();
					}
					else if (answer=='m')
					{
						mainmenu();
					}
					else if (answer=='s')
					{
						customer_sign_up();
					}
				}
				
				else if (strcmp(fusername,username)!=0 && strcmp(fpassword,password)==0)
				{
		    	printf("\nUSER DOESN'T EXIST");
		    	printf("\n\n\nWould you like to try again? \n\nEnter 'y' if you want to try again \nEnter 'm' if you want to be taken back to main menu \nEnter 's' if you want to sign up \nselect--->\t");
		    	scanf(" %c", &answer);
					if(answer=='y')
					{
						customer_login();
					}
					else if (answer=='m')
					{
						mainmenu();
					}
					else if (answer=='s')
					{
						customer_sign_up();
					}
				}
				
				else if (strcmp(fusername,username)!=0 && strcmp(fpassword,password)!=0)
				{
		    	printf("\nNO RECORD OF USER OR PASSWORD!");
		    	printf("\n\n\nWould you like to try again? \n\nEnter 'y' if you want to try again \nEnter 'm' if you want to be taken back to main menu \nEnter 's' if you want to sign up \nselect--->\t");
		    	scanf(" %c", &answer);
					if(answer=='y')
					{
						customer_login();
					}
					else if (answer=='m')
					{
						mainmenu();
					}
					else if (answer=='s')
					{
						customer_sign_up();
					}
				}
		}	
		
		fclose (cpd);	
	}
	
void customer_sign_up()
{
	char fname[100], lname[100], username[100], password[100], email_address[100], phonenum[100], address[100], answer;
	char ffname[100], flname[100], fusername[100], fpassword[100], femail_address[100], fphonenum[100], faddress[100];
	int wait, id, fid, lower = 0, upper = 7000000;
	FILE*cpd;
	
	system("cls");
	
	printf("\n\n************************************************************Hi! Are you ready to sign up?************************************************************\n\n");

	printf("\n\nEnter your First name:\t");
    scanf("%s", fname);
    
    printf("\n\nEnter your Last name:\t");
    scanf("%s", lname);
    
    printf("\n\nEnter your username (username cannot have spaces):\t");
    scanf("%s",username);
    
    printf("\n\nEnter your password:\t");
    scanf("%s",password);
    
    printf("\n\nEnter your email address:\t");
    scanf("%s", email_address);
    
    printf("\n\nEnter your phone number (format: 876-####-###):\t");
    scanf("%s", phonenum);
    
    printf("\n\nEnter your address (format: 20_Magnolio_Terrace,_Kingston_10,_St.Andrew,_Jamaica):\n");
    scanf("%s", address);   
        
    printf("\n\nFirst name = %s\n", fname);  

	printf("Last name = %s\n", lname);  
	
	printf("Email address = %s\n", email_address);  
	
	printf("Phone number = %s\n", phonenum);  
	
	printf("Address = %s\n", address);  
	
    // Use current time as  
    // seed for random generator 
    srand(time(0)); 
    
	id = (rand() %
    (upper - lower + 1)) + lower; 
    
    cpd = fopen("Customer Profile Directory.txt","r");		
    
   	while (fscanf (cpd, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", ffname, flname, fusername, fpassword, femail_address, fphonenum, faddress, &fid)!=EOF)
   	{
   		if (id == fid)
   		{
   			id = (rand() % 
   			(upper - lower + 1)) + lower; 
   		}
   		else 
   		{
   			fclose (cpd);
	        cpd = fopen("Customer Profile Directory.txt","a+");		
			
			fprintf (cpd, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", fname, lname, username, password, email_address, phonenum, address, id);
			
			printf("\n\n Your id is: %d", id);
			printf("\n THIS ID IS PERMANENT, SO PLEASE REMEMBER IT. YOU WILL NEED IT.");
			fclose (cpd);
   		}
   	} 
   	
	
	printf("\n\n Ensure that your information is correct");
	
	printf("\n\n Are you ready to continue? \t Enter 'y' to continue and enter 'n' to input new information\t");	
	scanf(" %c", &answer);
	
	printf("\n\n");
	if(answer == 'y')
		{
			for(wait=0;wait<=50000;wait++)
			{
				printf("\rIn progress : %d",wait/500);
			}
			
			system("cls");
			
			restaurants();
		}
		
		else if (answer == 'n')
		  {
		  	customer_sign_up();
		  }
		  
		   
} 

void restaurants()
{
	int k, wait;

	printf("                                                 ************************************************\n                                                                      WELCOME\n                                                 ************************************************\n\n");
	printf("               MAKE YOUR CHOICE--->\n\n               1. Kentucky Fried Chicken\n\n               2. Island Grill\n\n               3. Burger King\n\n                      OR\n\n               4. Back To Main Menu\n\n   Enter Your Choice  -->\t");
	
	scanf("%d",&k);
		
	printf("\n\n");
	for(wait=0;wait<=50000;wait++)
	{
		printf("\rIn progress : %d",wait/500);
	}
	if(k==1)
	{
		system("cls");
		 Kentucky_Fried_Chicken();
	}
	else if(k==2)
	{
		system("cls");
		 Island_Grill();
	}
	else if(k==3)
	{
		system("cls");
		Burger_King();
	}
	else if(k==4)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		printf("Wrong Input !Please Re-enter The Correct Option......\n\n");
		restaurants();
	}
}

void Kentucky_Fried_Chicken()
{
	int choice, wait, quantity, price, itemno, cost, i, order_amount=0, count=1, Total_cost, fid, id, GCT, KfcGrand_total, answer;
	char item1[30], item2[30], item3[30], item4[30],item5[30], item6[30], size[30], username[100], password[100], foodname[200] ={0};
	char fname[100], lname[100], fusername[100], fpassword[100], email_address[100], phonenum[100], address[100], fullname[200]={0};
	char str1[] = " ", email[100]={0}, phone[100]={0}, add[100]={0};
	FILE *kfcmenu;
	FILE *kfco;
	FILE *cpd;
	
	struct orderskfc *fnNode, *tmp, *snNode, *temp, *tnNode, *tmpo, *fournNode, *tempo, *fifnNode, *tempy, *tempor;
	
	knode = (struct orderskfc *)malloc(sizeof(struct orderskfc));
	ynode = (struct orderskfc *)malloc(sizeof(struct orderskfc));
	fnode = (struct orderskfc *)malloc(sizeof(struct orderskfc));
	cnode = (struct orderskfc *)malloc(sizeof(struct orderskfc));
	hnode = (struct orderskfc *)malloc(sizeof(struct orderskfc));
	enode = (struct orderskfc *)malloc(sizeof(struct orderskfc));
 	
	 	
	printf("\n\nEnter your id:\t");
	scanf("%d",&id);
	
	cpd = fopen("Customer Profile Directory.txt","r");		
 		
	while (fscanf (cpd, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", fname, lname, fusername, fpassword, email_address, phonenum, address, &fid) !=EOF) 
	{
 		if( id == fid)
		{
	        kfco = fopen("kfcorders.txt","a+");
	        
			fprintf (kfco, "%s\t%s\n%s\n%s\n%s\n\n", fname, lname, email_address, phonenum, address);
			
			strcat(fullname,fname);
			strcat(fullname,str1);
			strcat(fullname,lname);
			
			strcat(email, email_address);
			strcat(phone, phonenum);
			strcat(add, address);
	        
	 		fclose(kfco);
    	}
				
	}
	fclose(cpd);
    	
	
	
	printf("                                                   *********************************************************                                                 \n");
	printf("                                                                       KFC Menu                                                                     \n");
	printf("                                                   *********************************************************                                                 \n");
	printf("Item Code#   Menu Item                                                  Description                                                            Price($)     \n");
	printf("[01]--------|BIG DEAL                     3 pcs. of Chicken, 1 Reg. Fries, 1 Pepsi 475mL                                                     |----| 815\n");
	printf("[02]--------|MEAL DEAL                    2 pcs. of Chicken,1 Reg. Fries, 1 Pepsi 457mL                                                      |----| 635\n");
	printf("[03]--------|Hot 'n' Spicy Zinger         with Cheese,1 Reg. Fries, 1 Pepsi 457mL                                                            |----| 675\n");
	printf("[04]--------|Hot 'n' Spicy Zinger(ONLY)   1 Zinger with cheese only                                                                          |----| 575\n");
	printf("[05]--------|BBQ ZINGER COMBO             with Cheese                                                                                        |----| 665\n");
	printf("[06]--------|BBQ ZINGER (ONLY)            1 BBQ Zinger with cheese only                                                                      |----| 565\n");
	printf("[07]--------|WESTERN ZINGER               1 Hot 'n' Spicy Zinger with Cheese, Bacon, Onion Rings & BBQ Sauce, 1 Reg. Fries, 1 Pepsi 457mL    |----| 735\n");
	printf("[08]--------|WESTERN ZINGER (ONLY)        1 Western Zinger only                                                                              |----| 640\n");
	printf("[09]--------|BIG SIX                      6 Pcs. Chicken, 2 Reg. Fries, 1 Small Coleslaw, 2 Pepsi 457mL                                      |----| 1700\n");
	printf("[10]--------|FAMILY 12                    12 Pcs. Chicken, 1 Family Fries, 4 Biscuits, 3 Mashed Potatoes, 3 Coleslaws, 4 Cookies,1 Pepsi 2L  |----| 3,910\n");
	printf("[11]--------|FAMILY 9                     9 Pcs. Chicken, 2 Lg. Fries, 4 Biscuits, 3 Corn Cobbettes, 1 Pepsi 2L                              |----| 2,975\n");
	printf("[12]--------|PARTY 15                     15 Pcs. Chicken, 1 Pepsi 2L                                                                        |----| 3,605\n");
	printf("[13]--------|PARTY 21                     21 Pcs. Chicken, 1 Pepsi 2L                                                                        |----| 4,760\n");
	printf("[14]--------|WINGS 5 COMBO                5 Pcs. Wings, 1 Reg. Fries, 1 Pepsi 457mL                                                          |----| 605\n");
	printf("[15]--------|WINGS 5 ONLY                 5 Pcs. Wings only                                                                                  |----| 490\n");
	printf("[16]--------|WINGS 8 COMBO                8 Pcs. Wings, 1 Reg. Fries, 1 Pepsi 457mL                                                          |----| 900\n");
	printf("[17]--------|WINGS 10 COMBO               10 Pcs. Wings, 1 Reg Fries, 1 Pepsi 457mL                                                          |----| 1,035\n");
	printf("[18]--------|WINGS 10 ONLY                10 Pcs. Wings only                                                                                 |----| 925\n");
	printf("[19]--------|WINGS 15 ONLY                15 Pcs. Wings only                                                                                 |----| 1,315\n");
	printf("[20]--------|PARTY 25                     25 Pcs. Wings, 1 Pepsi 2L                                                                          |----| 2,460\n");
	printf("[21]--------|KRISPERS-3 PCS. COMBO        3 Krispers, 1 Reg. Fries, 2 Dipping Sauces, 1 Pepsi 457mL                                          |----| 585\n");
	printf("[22]--------|KRISPERS-3 PCS. ONLY         3 Krispers only, 2 Dipping Sauces                                                                  |----| 475\n");
	printf("[23]--------|KRISPERS-5 PCS. COMBO        5 Krispers, 1 Reg. Fries, 2 Dipping Sauces, 1 Pepsi 457mL                                          |----| 755\n");
	printf("[24]--------|KRISPERS-5PCS. ONLY          5 Krispers only, 2 Dipping Sauces                                                                  |----| 640\n");
	printf("[25]--------|KRISPERS-10 PCS. ONLY        10 Krispers only, 4 Dipping Sauces                                                                 |----| 1,135\n");
	printf("[26]--------|CHICKEN BOX COMBO            1 Pc. Chicken, 1 Reg Fries, 1 Biscuit, 1 Pepsi 457mL                                               |----| 415\n");
	printf("[27]--------|POP CORN CHICKEN(SM)COMBO    1 Small Popcorn Chicken, 1 Reg. Fries, 1 Pepsi 457mL                                               |----| 405\n");
	printf("[28]--------|FAMOUS BOWL                  1 Famous Bowl, 1 Pepsi 457mL                                                                       |----| 405\n");
	printf("[29]--------|POP CORN CHICKEN ONLY        1 Large Popcorn Chicken only                                                                       |----| 415\n");
	printf("[30]--------|POPCORN CHICKEN (LG) COMBO   1 Large Popcorn Chicken, 1 Reg. Fries, 1 Pepsi 457mL                                               |----| 565\n");
	printf("[31]--------|CATERING CHICKEN             minimum order of 50 pcs.                                                                           |----| 190 per piece\n");
	printf("[32]--------|CATERING KRISPERS            minimum order of 50 pcs.                                                                           |----| 100 per piece\n");
	printf("[33]--------|CATERING WINGS               minimum order of 45 pcs.                                                                           |----| 85 per piece\n");
	printf("[34]--------|FRIES                        Regular                                                                                            |----| 135\n");
	printf("[35]--------|FRIES                        Large                                                                                              |----| 175\n");
	printf("[36]--------|CORN                         1                                                                                                  |----| 70\n");
	printf("[37]--------|MASHED POTATOES              1                                                                                                  |----| 165\n");
	printf("[38]--------|COLESLAW                     1                                                                                                  |----| 170\n");
	printf("[39]--------|BISCUIT                      1                                                                                                  |----| 70\n");
	printf("[40]--------|Salad Wrap with Chicken      Regular salad with 600mL Ocean Spray Flavour Splash                                                |----| 665\n");
	printf("[41]--------|Salad Wrap (no chicken)      Regular salad with 600mL Ocean Spray Flavour Splash                                                |----| 565\n");
	printf("[42]--------|Salad Combo with Chicken     Large salad with 600mL Ocean Spray Flavour Splash                                                  |----| 910\n");
	printf("[43]--------|Salad Combo (no chicken)     Large Salad with 600mL Ocean Spray Flavour Splash                                                  |----| 810\n");
	printf("[44]--------|Salad with Chicken           1 Regular Salad with 600mL Ocean Spray Flavour Splash                                              |----| 665\n");
	printf("[45]--------|Salad (no chicken)           1 Regular Salad with 600mL Ocean Spray Flavour Splash                                              |----| 565\n");
	printf("[46]--------|Salad with Chicken Only      1 Large Salad                                                                                      |----| 820\n");
	printf("[47]--------|Salad Only (no chicken)      1 Large Salad                                                                                      |----| 720\n");
	printf("[48]--------|Salad with Chicken only      1 Large Salad                                                                                      |----| 575\n");
	printf("[49]--------|Salad (no chicken) only      1 Regular Salad                                                                                    |----| 475\n");
	printf("[50]--------|COOKIES                      Chocolate Chip (1)                                                                                 |----| 70\n");
	printf("[51]--------|COOKIES                      Oatmeal (1)                                                                                        |----| 70\n");
	printf("[52]--------|PIE                          1                                                                                                  |----| 280\n");
	printf("[53]--------|AQUA WATER                   1                                                                                                  |----| 95\n");
	printf("[54]--------|SPLASH                       1                                                                                                  |----| 100\n");
	printf("[55]--------|PEPSI                        21oz.                                                                                              |----| 180\n");
	printf("[56]--------|DG GRAPE SOFT DRINK          21oz.                                                                                              |----| 180\n");
	printf("[57]--------|DG KOLA SOFT DRINK           21oz.                                                                                              |----| 180\n");
	printf("[58]--------|7UP                          21oz.                                                                                              |----| 180\n");
		
	kfco = fopen("kfcorders.txt","a+");
	 
	printf("\n\nHow many orders are you placing?\t ");
	scanf("%d", &order_amount);	
							
	printf("\n\n Enter '59' for your order number to choose a different restaurant or '60' to go back to main menu");
			
	printf("\n\nEnter Order #1:\t");
			scanf("%d",&choice);
			
			if(choice == 59)
			{
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				restaurants();
			}
			
			else if(choice == 60)
			{
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				mainmenu();
			}
			
			else if (choice > 60)
			{
				printf("Wrong Input! Re-enter THe Correct Option\n\n");
					printf("\n\n");
					for(wait=0;wait<=50000;wait++)
					{
						printf("\rIn progress : %d",wait/500);
					}
					system("cls");
				 Kentucky_Fried_Chicken();
			}
	
	kfcmenu = fopen("Kentucky Fried Chicken Menu.txt","r");	
	
	while (fscanf (kfcmenu, "%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", &itemno, item1, item2, item3, item4, item5, item6, &price)!=EOF)
		{
											
			if(choice == itemno) 
			{
		
				printf ("\n\nOrder:\t%d %s %s %s %s %s %s\n", itemno, item1, item2, item3, item4, item5, item6);
				
				fprintf (kfco, "Order #1:\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", itemno, item1, item2, item3, item4, item5, item6);
				
				ynode->itemno = itemno;
				ynode-> nextptr = NULL;
	            temp = ynode;
				
				strcpy(knode->foodname, item1); strcat(knode->foodname, str1);
				strcat(knode->foodname, item2); strcat(knode->foodname, str1);
				strcat(knode->foodname, item3); strcat(knode->foodname, str1);
				strcat(knode->foodname, item4); strcat(knode->foodname, str1);
				strcat(knode->foodname, item5); strcat(knode->foodname, str1);
				strcat(knode->foodname, item6);
				
				knode-> nextptr = NULL; 
	            tmp = knode;
				
				fnode->price = price;
				printf("\nPrice for one:\t%d", fnode->price);
				fprintf (kfco, "Price for one:\t%d\n", fnode->price);
				fnode-> nextptr = NULL; 
	            tmpo = fnode;
			
				printf("\n\nQuantity:\t");
				scanf(" %d",&quantity);
				cnode->quantity = quantity;
				fprintf (kfco, "Quantity:\t\t%d\n", cnode->quantity);
				cnode-> nextptr = NULL; 
	            tempo = cnode;
	            
				cost = price*quantity;
				hnode->cost = cost;			
		 		printf("\n\nCost:\t%d", hnode->cost);
				fprintf (kfco, "Cost for item:\t%d\n\n", hnode->cost);
				hnode-> nextptr = NULL; 
	            tempy = hnode;
			   				
			}
				Total_cost = cost;		
		}
		fclose (kfcmenu);

	for (i=2; i <= order_amount; i++)
		{
			fnNode = (struct orderskfc *)malloc(sizeof(struct orderskfc));
			snNode = (struct orderskfc *)malloc(sizeof(struct orderskfc));
			tnNode = (struct orderskfc *)malloc(sizeof(struct orderskfc));
			fournNode = (struct orderskfc *)malloc(sizeof(struct orderskfc));
			fifnNode = (struct orderskfc *)malloc(sizeof(struct orderskfc));
			enode = (struct orderskfc *)malloc(sizeof(struct orderskfc));
			
			printf("\n\n Enter '59' for your order number to choose a different restaurant or '60' to go back to main menu");
			
			printf("\n\nEnter Order #%d:\t", i);
			scanf("%d",&choice);
			
			if(choice == 59)
			{
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				restaurants();
			}
			
			else if(choice == 60)
			{
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				mainmenu();
			}
			
			else if (choice > 60)
			{
				printf("Wrong Input! Re-enter THe Correct Option\n\n");
				printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				 Kentucky_Fried_Chicken();
			}
				
			kfcmenu = fopen("Kentucky Fried Chicken Menu.txt","r");	
			
		while (fscanf (kfcmenu, "%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", &itemno, item1, item2, item3, item4, item5, item6, &price)!=EOF)
				{
											
					if(choice == itemno)
						{
						
							printf ("\n\nOrder:\t%d %s %s %s %s %s %s\n", itemno, item1, item2, item3, item4, item5, item6);
							
							fprintf (kfco, "Order #%d:\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", i, itemno, item1, item2, item3, item4, item5, item6);
							
							snNode->itemno = itemno;
							snNode->nextptr = temp-> nextptr;
                			temp->nextptr = snNode; 
               				temp = snNode;
							
							strcpy(fnNode->foodname, item1); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item2); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item3); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item4); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item5); strcat(fnNode->foodname, str1);
						 	strcat(fnNode->foodname, item6);
							
               				fnNode->nextptr = tmp-> nextptr; 
                			tmp->nextptr = fnNode; 
                			tmp = fnNode;
                			
							tnNode->price = price;
							printf("\nPrice for one:\t%d", tnNode->price);
							fprintf (kfco, "Price for one:\t%d\n", tnNode->price);
							tnNode->nextptr = tmpo-> nextptr;
                			tmpo->nextptr = tnNode; 
                			tmpo = tnNode;
							
							printf("\n\nQuantity:\t");
							scanf(" %d",&quantity);
							fournNode->quantity = quantity;
							fprintf (kfco, "Quantity:\t\t%d\n", fournNode->quantity);
							fournNode->nextptr = tempo-> nextptr;
                			tempo->nextptr = fournNode; 
                			tempo = fournNode;
                            
							cost = price*quantity;		
							fifnNode->cost =cost;	
					 		printf("\n\nCost:\t%d", fifnNode->cost);
							fprintf (kfco, "Cost for item:\t%d\n\n", fifnNode->cost);
							fifnNode->nextptr = tempy-> nextptr;
			                tempy->nextptr = fifnNode; 
			                tempy = fifnNode;
							   				
						}
							
				}
				
				Total_cost = Total_cost + cost;	
				fclose (kfcmenu);	
			
		}
	printf("\n\nYour total before GCT:\t%d",Total_cost);
	fprintf(kfco,"Total before GCT:\t%d\n",Total_cost);
	
	GCT = Total_cost*0.165;	
	
	printf("\n\nGCT added (16.5%):\t%d",GCT);
	fprintf(kfco,"GCT added (16.5%):\t%d\n",GCT);
		
	enode->KfcGrand_total = Total_cost + GCT + 1000;
	

	printf("\n\nYour total is:\t%d",enode->KfcGrand_total);
	
	printf("\n");
	
	fprintf(kfco,"Grand Total: \t%d\n",enode->KfcGrand_total);
	enode-> nextptr = NULL; 
	tempor = enode;
	
	fclose(kfco);
	printf("\n\nYour bill is being generated. Please wait a minute. Thank You!");
	printf("\n\n");
	for(wait=0;wait<=50000;wait++)
	{
		printf("\rIn progress : %d",wait/500);
	}
	
	system("cls");
	printf("\n\n\n\n");
	printf("__________________________________________________________________________________________________\n");
    printf("                                        CUSTOMER INFORMATION                                     \n");
	printf("Name on Order: %s\n", fullname);
	printf("Email Address: %s\n", email);
	printf("Callback Phone #: %s\n",phone);
	printf("Delivery Address: %s\n", add);
    printf("Restaurant: Kentucky Fried Chicken\n");
    printf("\n");        
    printf("                                          ORDER DETAILS                                          \n");
    generate_order_numbers_kfc();
    printf("\n");  
    printf("        The following order is being delivered hot and fresh to your door:                       \n");      
    printf("\n");
    printf("\n");	
    printf("| Food No. |            Food Name               | Unit Price    | Quantity   |       Total     |");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
	printf("\n");
	displayorderskfc();
	printf("\n                                                                             ___________________\n");
	printf("\n                                                    Your total before GCT:         $%-5d",Total_cost);
	printf("\n                                                         GCT added (16.5%):         $%-5d",GCT);
	printf("\n                                                         Delivery Charge:          $1000");	
	printf("\n                                                                             ____________________\n");
	printf("\n                                                              Grand Total:         $%-5d", enode->KfcGrand_total);
	printf("\n");
	printf("____________________________________________________________________________________________________\n");
	
	
	printf("\n\nAre you ready to proceed with payment?\n\n Enter '1' when you are ready or press any other key \t");
	scanf ("%d", &answer);
	
	if(answer == 1)
			{
				printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				KFCPayment();
			}
}

void displayorderskfc()
{
    struct orderskfc *temp, *tmp, *tmpo, *tempo, *tempy;
	if(ynode == NULL && knode == NULL && fnode == NULL && cnode == NULL && hnode == NULL )
    {
        printf(" No data found in the list.");
    }
    else
    {
        temp = ynode; tmp = knode; tmpo = fnode; tempo = cnode; tempy = hnode;
        while(temp != NULL && tmp != NULL && tmpo != NULL && tempo != NULL && tempy != NULL)
        {
            printf("|    %02d    | %-35s|    $%-4d      |   %-4d     |     $%-5d      |\n",temp->itemno, tmp->foodname, tmpo->price, tempo->quantity, tempy->cost);  
            temp = temp->nextptr; tmp = tmp->nextptr; tmpo = tmpo->nextptr; tempo = tempo->nextptr; tempy = tempy->nextptr;              
        }
    }
}

void generate_order_numbers_kfc() 
{ 
   int i, ordernum, fordernum, lower = 0, upper = 4000000; 
    FILE *onu;
    FILE *kfco;
     
	 
	 // Use current time as  
    // seed for random generator 
    srand(time(0)); 
    
	ordernum = (rand() %
    (upper - lower + 1)) + lower; 
    
    onu = fopen("order numbers used.txt","r");	
    
   	while (fscanf (onu,"%d\n", &fordernum)!=EOF)
   	{
   		if (ordernum == fordernum)
   		{
   			int ordernum = (rand() % 
   			(upper - lower + 1)) + lower; 
   		}
   		else 
   		{
   			fclose (onu);
	        printf("Receipt Number:\t%d\n ", ordernum);
	        onu = fopen("order numbers used.txt","a+");	
	        fprintf (onu,"%d\n ", ordernum);
	        fclose (onu);
	        kfco = fopen("kfcorders.txt","a+");
	        fprintf(kfco, "Receipt Number:\t%d\n", ordernum);
	        fclose (kfco);
   		}
   	} 
   	
   	
} 

void KFCPayment()
{
	int card_number[100], pin, pay, select, wait;
	struct orderskfc *tempor;
	FILE *kfco;
	
	printf("\n\nAre you paying with cash or credit card? \n");
	printf("Enter: [1] for cash \n");
	printf("       [2] for credit card \n");
	printf("       [3] to CANCEL order and payment \n");
	scanf ("%d", &pay);
	
	if (pay == 1)
	{
		if(enode == NULL)
    	{
        printf(" No data found in the list.\n\n");
    	}
    	else
    	{
	        tempor = enode; 
	        while(tempor != NULL)
	        {
				printf("\n\nPayment Method: Pay with Cash upon Delivery $%d", tempor->KfcGrand_total );
				printf("\n\n*Note: Drivers carry less than $1,000 in change. Feeling generous? You can tip at the door.\n\n");
				tempor = tempor->nextptr;
			}
			kfco = fopen("kfcorders.txt","a+");
	        fprintf(kfco, "APPROVED!\n\n");
	        fclose (kfco);
		}
		
	}
	
	else if (pay == 2)
	{
		if(enode == NULL)
    	{
        	printf(" No data found in the list.\n\n");
    	}
    	else
    	{
	        tempor = enode; 
	        
	        while(tempor != NULL)
	        {
	        	
				printf("\n\nPayment Method: Credit Card \n\n Amount: $%d", tempor->KfcGrand_total );
				tempor = tempor->nextptr;
				
				printf("\n\nEnter Your Card No [we never save your card number]: ");
				scanf("%d",&card_number);
				
				printf("\n\nEnter Your Card Pin [we never save your pin]  : ");
				scanf("%d",&pin);
				
				kfco = fopen("kfcorders.txt","a+");
		        fprintf(kfco, "APPROVED!\n\n");
		        fclose (kfco);
				
				printf("\n\nPAYMENT SUCCESS!\n\n");
			}
		}
	}
		else if (pay == 3)
		{
			kfco = fopen("kfcorders.txt","a+");
	        fprintf(kfco, "CANCELLED!\n\n");
	        fclose (kfco);
		}

	
	printf("\n\n 1. Wanna Buy Another Delicious?");
	printf("\n 2. Main Menu \n\n");
	printf("     select:\t ");
	scanf("%d", &select);
	
	if (select == 1)
	{
		printf("\n\n");
		for(wait=0;wait<=50000;wait++)
		{
			printf("\rIn progress : %d",wait/500);
		}
	
		system("cls");
		restaurants();
	}
	
	else if (select == 2)
	{
		printf("\n\n");
		for(wait=0;wait<=50000;wait++)
		{
			printf("\rIn progress : %d",wait/500);
		}
	
		system("cls");
		mainmenu();
	}
}

void Island_Grill()
{
	int choice, wait, quantity, price, itemno, cost, i, order_amount=0, count=1, Total_cost, fid, id, GCT, IgGrand_total;
	char item1[30], item2[30], item3[30], item4[30],item5[30], item6[30], item7[30], item8[30], item9[30],item10[30];
	char size[30], username[100], password[100], foodname[200] ={0};
	char fname[100], lname[100], fusername[100], fpassword[100], email_address[100], phonenum[100], address[100], fullname[200]={0};
	char str1[] = " ", email[100]={0}, phone[100]={0}, add[100]={0}, answer;
	FILE *igmenu;
	FILE *igo;
	FILE *cpd;
	
	struct ordersig *fnNode, *tmp, *snNode, *temp, *tnNode, *tmpo, *fournNode, *tempo, *fifnNode, *tempy, *tm;
	
	inode = (struct ordersig *)malloc(sizeof(struct ordersig));
	snode = (struct ordersig *)malloc(sizeof(struct ordersig));
	lnode = (struct ordersig *)malloc(sizeof(struct ordersig));
	anode = (struct ordersig *)malloc(sizeof(struct ordersig));
	dnode = (struct ordersig *)malloc(sizeof(struct ordersig));
	gnode = (struct ordersig *)malloc(sizeof(struct ordersig));
 	
	 printf("\n\nEnter your id:\t");
	scanf("%d", &id);	
	
	cpd = fopen("Customer Profile Directory.txt","r");		
 		
	while (fscanf (cpd, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", fname, lname, fusername, fpassword, email_address, phonenum, address, &fid) !=EOF) 
	{
 		if( id == fid)
		{
	        igo = fopen("igorders.txt","a+");
	        
			fprintf (igo, "%s\t%s\n%s\n%s\n%s\n\n", fname, lname, email_address, phonenum, address);
			
			strcat(fullname,fname);
			strcat(fullname,str1);
			strcat(fullname,lname);
			
			strcat(email, email_address);
			strcat(phone, phonenum);
			strcat(add, address);
	        
	 		fclose(igo);
    	}	
	}
	fclose(cpd);
	
	printf("                                                   *********************************************************                                                 \n");
	printf("                                                                       Island Grill Menu                                                                     \n");
	printf("                                                   *********************************************************                                                 \n");
	printf("Item Code#                Menu Item                         Price($)   ");printf("  Item Code#                Menu Item                         Price($)   \n\n");
	printf("[1]---------|Go Lite w/ Steamed Veg & Sweet Corn 1/4       |----| 830  ");printf("  [44]--------|Cran WATA                                     |----| 160  \n");
	printf("[2]---------|Go Lite w/ Steamed Veg 1/4                    |----| 810  ");printf("  [45]--------|Bottled Water                                 |----| 110  \n");
	printf("[3]---------|Go Lite with Salad 1/4                        |----| 715  ");printf("  [46]--------|Tea                                           |----| 160  \n");
	printf("[4]---------|Special 1/4                                   |----| 640  ");printf("  [47]--------|Ackee & Saltfish - Regular                    |----| 540  \n");
	printf("[5]---------|Satisfaction 1/4                              |----| 655  ");printf("  [48]--------|Ackee & Saltfish - Large                      |----| 690  \n");
	printf("[6]---------|Jus Nuff 1/4                                  |----| 580  ");printf("  [49]--------|Callaloo & Saltfish - Regular                 |----| 420  \n");
	printf("[7]---------|Family Time Dinnah                            |----| 2970 ");printf("  [50]--------|Callaloo & Saltfish - Large                   |----| 525  \n");
	printf("[8]---------|Family Time Dinnah w/ 2 Litre                 |----| 3180 ");printf("  [51]--------|Escoveitch Fish & Festival                    |----| 635  \n");
	printf("[9]---------|Session Pack                                  |----| 2150 ");printf("  [52]--------|Stewed Chicken - Regular                      |----| 440  \n");
	printf("[10]--------|Escoveitch Fish Fillet & Rice                 |----| 635  ");printf("  [53]--------|Stewed Chicken - Large                        |----| 545  \n");
	printf("[11]--------|Escoveitch Fish Go Lite w/ Salad              |----| 710  ");printf("  [54]--------|Hominy Porridge Only - Large                  |----| 295  \n");
	printf("[12]--------|Escoveitch Fish Go Lite w/ Steam Veg & Corn   |----| 820  ");printf("  [55]--------|Hominy Porridge Only - Regular                |----| 255  \n");
	printf("[13]--------|Escoveitch Fish & Festival                    |----| 635  ");printf("  [56]--------|Cornmeal Porridge Only - Large                |----| 265  \n");
	printf("[14]--------|Escoveitch Fish Go Lite w/ Steam Veg          |----| 790  ");printf("  [57]--------|Cornmeal Porridge Only - Regular              |----| 235  \n");
	printf("[15]--------|Regular Soup                                  |----| 265  ");printf("  [58]--------|Cornmeal Porridge with Festival - Regular     |----| 265  \n");
	printf("[16]--------|Medium Soup                                   |----| 325  ");printf("  [59]--------|Cornmeal Porridge with Festival - Large       |----| 295  \n");
	printf("[17]--------|Large Soup                                    |----| 430  ");printf("  [60]--------|Hominy Porridge with Festival - Large         |----| 325  \n");
	printf("[18]--------|Regular Soup & 1 Festival                     |----| 335  ");printf("  [61]--------|Hominy Porridge with Festival - Regular       |----| 285  \n");
	printf("[19]--------|Medium Soup & 2 Festival                      |----| 400  ");printf("  [62]--------|Yabbas (Curry & Fricassee) - Regular          |----| 430  \n");
	printf("[20]--------|Large Soup & 2 Festival                       |----| 500  ");printf("  [63]--------|Yabbas (Curry & Fricassee) - Large            |----| 545  \n");
	printf("[21]--------|Festival (6)                                  |----| 370  ");printf("  [64]--------|Yabbas (Veggie) - Regular                     |----| 420  \n");
	printf("[22]--------|Festival (2)                                  |----| 130  ");printf("  [65]--------|Yabbas (Veggie) - Large                       |----| 535  \n");
	printf("[23]--------|Festival (1)                                  |----| 70   ");printf("  [66]--------|Yabbas(with plantain)-Curry & Fricassee Large |----| 655  \n");
	printf("[24]--------|Seasoned Fries                                |----| 200  ");printf("  [67]--------|Yabbas (with plantain) - Veggie Large         |----| 645  \n");
	printf("[25]--------|Rice Regular                                  |----| 185  ");printf("  [68]--------|Yabbas - Curry & Fricassee with Salad         |----| 645  \n");
	printf("[26]--------|Rice Large                                    |----| 420  ");printf("  [69]--------|Yabbas - Veggie Large with Salad              |----| 625  \n");
	printf("[27]--------|Green Plantain                                |----| 245  ");printf("  [70]--------|Yabbas - Curry & Fricassee with Steamed Veg   |----| 740  \n");
	printf("[28]--------|Sweet Corn (1pc.)                             |----| 115  ");printf("  [71]--------|Yabbas - Veggie Large with Steamed Veg        |----| 720  \n");
	printf("[29]--------|Sweet Corn (2pc.)                             |----| 200  ");printf("  [72]--------|Yabbas-Curry & Fricassee w/ Steamed.Veg&Corn  |----| 770  \n");
	printf("[30]--------|Soda & Freshh 16oz.                           |----| 135  ");printf("  [73]--------|Yabbas - Veggie Large with Steamed Veg & Corn |----| 750  \n");
	printf("[31]--------|Soda & Freshh 24oz.                           |----| 155  ");printf("  [74]--------|Chicken Sandwich Only                         |----| 500  \n");
	printf("[32]--------|Soda & Freshh 32oz.                           |----| 175  ");printf("  [75]--------|Chicken Sandwich & Fries                      |----| 630  \n");
	printf("[33]--------|Soda & Freshh 44oz.                           |----| 215  ");printf("  [76]--------|Chicken Sandwich Combo                        |----| 710  \n");
	printf("[34]--------|Wakefield Juice 16oz.                         |----| 205  ");printf("  [77]--------|Yaad Style Chicken Sandwich Only              |----| 610  \n");
	printf("[35]--------|Wakefield Juice 24oz.                         |----| 280  ");printf("  [78]--------|Yaad Style Sandwich & Fries                   |----| 745  \n");
	printf("[36]--------|Wakefield Juice 32oz.                         |----| 340  ");printf("  [79]--------|Yaad Style Combo                              |----| 825  \n");
	printf("[37]--------|Wakefield Juice 44oz.                         |----| 450  ");printf("  [80]--------|Jerk Burger & Fish - Sandwich Only            |----| 510  \n");
	printf("[38]--------|Supaah Juices 16oz.                           |----| 320  ");printf("  [81]--------|Jerk Burger & Fish - Sandwich & Fries         |----| 630  \n");
	printf("[39]--------|Supaah Juices 24oz.                           |----| 430  ");printf("  [82]--------|Jerk Burger & Fish - Sandwich Combo           |----| 710  \n");
	printf("[40]--------|Supaah Juices 32oz.                           |----| 540  ");printf("  [83]--------|Yaad Style Fish Sandwich Only                 |----| 620  \n");
	printf("[41]--------|Supaah Juices 44oz.                           |----| 680  ");printf("  [84]--------|Yaad Style Fish Sandwich & Fries              |----| 755  \n");
	printf("[42]--------|Hot Milo, Coffee                              |----| 170  ");printf("  [85]--------|Yaad Style Fish Sandwich Combo                |----| 840  \n");
	printf("[43]--------|Red Stripe/Light                              |----| 300  ");printf("  [86]--------|Ripe Plantain                                 |----| 225  \n");

	igo = fopen("igorders.txt","a+");
	 
	printf("\n\nHow many orders are you placing?\t ");
	scanf("%d", &order_amount);	
							
	printf("\n\n Enter '87' for your order number to choose a different restaurant or '88' to go back to main menu");
			
	printf("\n\nEnter Order #1:\t");
			scanf("%d",&choice);
			
			if(choice == 87)
			{
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				restaurants();
			}
			
			else if(choice == 88)
			{
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				mainmenu();
			}
			
			else if (choice > 88)
			{
				printf("Wrong Input! Re-enter THe Correct Option\n\n");
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				 Island_Grill();
			}	
	
	igmenu = fopen("Island Grill Menu.txt","r");	
	
	while (fscanf (igmenu, "%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", &itemno, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10, &price)!=EOF)
		{
											
			if( choice == itemno) 
			{
		
				printf ("\n\nOrder:\t%d %s %s %s %s %s %s %s %s %s %s\n", itemno, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10);
				
				fprintf (igo, "Order #1:\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", itemno, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10);
				
				snode->itemno = itemno;
				snode-> nextptr = NULL;
	            temp = snode;
				
				strcpy(inode->foodname, item1); strcat(inode->foodname, str1);
				strcat(inode->foodname, item2); strcat(inode->foodname, str1);
				strcat(inode->foodname, item3); strcat(inode->foodname, str1);
				strcat(inode->foodname, item4); strcat(inode->foodname, str1);
				strcat(inode->foodname, item5); strcat(inode->foodname, str1);
				strcat(inode->foodname, item6); strcat(inode->foodname, str1);
				strcat(inode->foodname, item7); strcat(inode->foodname, str1);
				strcat(inode->foodname, item8); strcat(inode->foodname, str1);
				strcat(inode->foodname, item9); strcat(inode->foodname, str1);
				strcat(inode->foodname, item10); 
				
				inode-> nextptr = NULL; 
	            tmp = inode;
				
				lnode->price = price;
				printf("\nPrice for one:\t%d", lnode->price);
				fprintf (igo, "Price for one:\t%d\n", lnode->price);
				lnode-> nextptr = NULL; 
	            tmpo = lnode;
			
				printf("\n\nQuantity:\t");
				scanf(" %d",&quantity);
				anode->quantity = quantity;
				fprintf (igo, "Quantity:\t\t%d\n", anode->quantity);
				anode-> nextptr = NULL; 
	            tempo = anode;
	            
				cost = price*quantity;
				dnode->cost = cost;			
		 		printf("\n\nCost:\t%d", dnode->cost);
				fprintf (igo, "Cost for item:\t%d\n\n", dnode->cost);
				dnode-> nextptr = NULL; 
	            tempy = dnode;
			   				
			}
				Total_cost = cost;		
		}
		fclose (igmenu);

	for (i=2; i <= order_amount; i++)
		{
			fnNode = (struct ordersig *)malloc(sizeof(struct ordersig));
			snNode = (struct ordersig *)malloc(sizeof(struct ordersig));
			tnNode = (struct ordersig *)malloc(sizeof(struct ordersig));
			fournNode = (struct ordersig *)malloc(sizeof(struct ordersig));
			fifnNode = (struct ordersig *)malloc(sizeof(struct ordersig));
			gnode = (struct ordersig *)malloc(sizeof(struct ordersig));
			
			printf("\n\n Enter '87' for your order number to choose a different restaurant or '88' to go back to main menu");
			
			printf("\n\nEnter Order #%d:\t", i);
			scanf("%d",&choice);
			
			if(choice == 87)
			{
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				restaurants();
			}
			
			else if(choice == 88)
			{
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				mainmenu();
			}
			
			else if (choice > 88)
			{
				printf("Wrong Input! Re-enter THe Correct Option\n\n");
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				 Island_Grill();
			}
				
			igmenu = fopen("Island Grill Menu.txt","r");	
			
				while (fscanf (igmenu, "%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", &itemno, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10, &price)!=EOF)
					{
														
						if(choice == itemno) 
						{
					
							printf ("\n\nOrder:\t%d %s %s %s %s %s %s %s %s %s %s\n", itemno, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10);
							
							fprintf (igo, "Order #%d:\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", i, itemno, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10);
								
							snNode->itemno = itemno;
							snNode->nextptr = temp-> nextptr;
                			temp->nextptr = snNode; 
               				temp = snNode;
							
							strcpy(fnNode->foodname, item1); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item2); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item3); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item4); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item5); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item6); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item7); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item8); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item9); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item10); 
							
               				fnNode->nextptr = tmp-> nextptr; 
                			tmp->nextptr = fnNode; 
                			tmp = fnNode;
                			
							tnNode->price = price;
							printf("\nPrice for one:\t%d", tnNode->price);
							fprintf (igo, "Price for one:\t%d\n", tnNode->price);
							tnNode->nextptr = tmpo-> nextptr;
                			tmpo->nextptr = tnNode; 
                			tmpo = tnNode;
							
							printf("\n\nQuantity:\t");
							scanf(" %d",&quantity);
							fournNode->quantity = quantity;
							fprintf (igo, "Quantity:\t\t%d\n", fournNode->quantity);
							fournNode->nextptr = tempo-> nextptr;
                			tempo->nextptr = fournNode; 
                			tempo = fournNode;
                            
							cost = price*quantity;		
							fifnNode->cost =cost;	
					 		printf("\n\nCost:\t%d", fifnNode->cost);
							fprintf (igo, "Cost for item:\t%d\n\n", fifnNode->cost);
							fifnNode->nextptr = tempy-> nextptr;
			                tempy->nextptr = fifnNode; 
			                tempy = fifnNode;
							   				
						}
							
				}
				
				Total_cost = Total_cost + cost;	
				fclose (igmenu);	
			
		}
	printf("\n\nYour total before GCT:\t%d",Total_cost);
	fprintf(igo,"Total before GCT:\t%d\n",Total_cost);
	
	GCT = Total_cost*0.165;	
	
	printf("\n\nGCT added (16.5%):\t%d",GCT);
	fprintf(igo,"GCT added (16.5%):\t%d\n",GCT);
		
	gnode->IgGrand_total = Total_cost + GCT + 1000;

	printf("\n\nYour total is:\t%d",gnode->IgGrand_total);
	
	printf("\n");
	
	fprintf(igo,"Grand Total: \t%d\n",gnode->IgGrand_total);
	gnode-> nextptr = NULL; 
	tm = gnode;
	
	fclose(igo);
	
	printf("\n\nYour bill is being generated. Please wait a minute. Thank You!");
	printf("\n\n");
	for(wait=0;wait<=50000;wait++)
	{
		printf("\rIn progress : %d",wait/500);
	}
	
	system("cls");
	printf("\n\n\n\n");
	printf("_______________________________________________________________________________________________________________\n");
    printf("                                        CUSTOMER INFORMATION                                     \n");
	printf("Name on Order: %s\n", fullname);
	printf("Email Address: %s\n", email);
	printf("Callback Phone #: %s\n",phone);
	printf("Delivery Address: %s\n", add);
    printf("Restaurant: Island Grill\n");
    printf("\n");        
    printf("                                          ORDER DETAILS                                          \n");
    generate_order_numbers_ig();
    printf("\n");  
    printf("        The following order is being delivered hot and fresh to your door:                       \n");      
    printf("\n");
    printf("\n");	
    printf("|Food No.|                       Food Name                      | Unit Price | Quantity   |      Total       |");
    printf("\n");
    printf("________________________________________________________________________________________________________________\n");
	printf("\n");
	displayordersig();
	printf("\n                                                                                            __________________\n");
	printf("\n                                                                   Your total before GCT:         $%-5d",Total_cost);
	printf("\n                                                                        GCT added (16.5%):         $%-5d",GCT);
	printf("\n                                                                         Delivery Charge:         $1000");	
	printf("\n                                                                                            ___________________\n");
	printf("\n                                                                             Grand Total:         $%-5d", gnode->IgGrand_total);
	printf("\n");
	printf("_________________________________________________________________________________________________________________\n");
	
	printf("\n\nAre you ready to proceed with payment?\n\n Enter '1' when you are ready\t");
	scanf ("%d", &answer);
	
	if(answer == 1)
			{
				printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				IGPayment();
			}
}

void displayordersig()
{
    struct ordersig *temp, *tmp, *tmpo, *tempo, *tempy;
	if(snode == NULL && inode == NULL && lnode == NULL && anode == NULL && dnode == NULL )
    {
        printf(" No data found in the list.");
    }
    else
    {
        temp = snode; tmp = inode; tmpo = lnode; tempo = anode; tempy = dnode;
        while(temp != NULL && tmp != NULL && tmpo != NULL && tempo != NULL && tempy != NULL)
        {
            printf("|  %02d    | %-53s|  $%-4d     |    %-4d    |        $%-5d    |\n",temp->itemno, tmp->foodname, tmpo->price, tempo->quantity, tempy->cost);  
            temp = temp->nextptr; tmp = tmp->nextptr; tmpo = tmpo->nextptr; tempo = tempo->nextptr; tempy = tempy->nextptr;              
        }
    }
}

void generate_order_numbers_ig() 
{ 
   int i, ordernum, fordernum, lower = 0, upper = 4000000; 
    FILE *onu;
    FILE *igo;
     
	 
	 // Use current time as  
    // seed for random generator 
    srand(time(0)); 
    
	ordernum = (rand() %
    (upper - lower + 1)) + lower; 
    
    onu = fopen("order numbers used.txt","r");	
    
   	while (fscanf (onu,"%d\n", &fordernum)!=EOF)
   	{
   		if (ordernum == fordernum)
   		{
   			int ordernum = (rand() % 
   			(upper - lower + 1)) + lower; 
   		}
   		else 
   		{
   			fclose (onu);
	        printf("Receipt Number:\t%d\n ", ordernum);
	        onu = fopen("order numbers used.txt","a+");	
	        fprintf (onu,"%d\n ", ordernum);
	        fclose (onu);
	        igo = fopen("igorders.txt","a+");
	        fprintf(igo, "Receipt Number:\t%d\n", ordernum);
	        fclose (igo);
   		}
   	} 
   	
   	
} 

void IGPayment()
{
	int card_number[100], pin, pay, select, wait;
	struct ordersig *tm;
	FILE *igo;
	
	printf("\n\nAre you paying with cash or credit card? \n");
	printf("Enter: [1] for cash \n");
	printf("       [2] for credit card \n");
	printf("       [3] to CANCEL order and payment \n");
	scanf ("%d", &pay);
	
	if (pay == 1)
	{
		if(gnode == NULL)
    	{
        printf(" No data found in the list.\n\n");
    	}
    	else
    	{
	        tm = gnode;
	        while(tm != NULL)
	        {
				printf("\n\nPayment Method: Pay with Cash upon Delivery $%d", tm->IgGrand_total );
				printf("\n\n*Note: Drivers carry less than $1,000 in change. Feeling generous? You can tip at the door.\n\n");
				tm = tm->nextptr;
			}
			igo = fopen("igorders.txt","a+");
   			fprintf(igo, "APPROVED!\n\n");
      		fclose (igo);
		}
		
	}
	
	else if (pay == 2)
	{
		if(gnode == NULL)
    	{
        printf(" No data found in the list.\n\n");
    	}
    	else
    	{
	        tm = gnode;
	        while(tm != NULL)
	        {
	        	
				printf("\n\nPayment Method: Credit Card \n\n Amount: $%d", tm->IgGrand_total );
				tm = tm->nextptr;
				
				printf("\n\nEnter Your Card No [we never save your card number]: ");
				scanf("%d",&card_number);
				
				printf("\n\nEnter Your Card Pin [we never save your pin]  : ");
				scanf("%d",&pin);
				
				igo = fopen("igorders.txt","a+");
		        fprintf(igo, "APPROVED!\n\n");
		        fclose (igo);
				
				printf("\n\nPAYMENT SUCCESS!\n\n");
			}
		}
	
	}
	else if (pay == 3)
		{
			igo = fopen("igorders.txt","a+");
	        fprintf(igo, "CANCELLED!\n\n");
	        fclose (igo);
		}
	
	printf("\n\n 1. Wanna Buy Another Delicious?");
	printf("\n 2. Main Menu \n\n");
	printf("     select:\t ");
	scanf("%d", &select);
	
	if (select == 1)
	{
		printf("\n\n");
		for(wait=0;wait<=50000;wait++)
		{
			printf("\rIn progress : %d",wait/500);
		}
	
		system("cls");
		restaurants();
	}
	
	else if (select == 2)
	{
		printf("\n\n");
		for(wait=0;wait<=50000;wait++)
		{
			printf("\rIn progress : %d",wait/500);
		}
	
		system("cls");
		mainmenu();
	}
}

void Burger_King()
{
	int choice, wait, quantity, price, itemno, cost, i, order_amount=0, count=1, Total_cost, fid, id, GCT, BkGrand_total;
	char item1[30], item2[30], item3[30], item4[30],item5[30], type[30], size[30], username[100], password[100], foodname[200] ={0};
	char fname[100], lname[100], fusername[100], fpassword[100], email_address[100], phonenum[100], address[100], fullname[200]={0};
	char str1[] = " ", email[100]={0}, phone[100]={0}, add[100]={0}, answer;
	FILE *bkmenu;
	FILE *bko;
	FILE *cpd;
	
	struct ordersbk *fnNode, *tmp, *snNode, *temp, *tnNode, *tmpo, *fournNode, *tempo, *fifnNode, *tempy, *tp;
	
	stnode = (struct ordersbk *)malloc(sizeof(struct ordersbk));
	mtnode = (struct ordersbk *)malloc(sizeof(struct ordersbk));
	ntnode = (struct ordersbk *)malloc(sizeof(struct ordersbk));
	dtnode = (struct ordersbk *)malloc(sizeof(struct ordersbk));
	ltnode = (struct ordersbk *)malloc(sizeof(struct ordersbk));
	ktnode = (struct ordersbk *)malloc(sizeof(struct ordersbk));

	printf("\n\nEnter your id:\t");
	scanf("%d", &id);
	
	cpd = fopen("Customer Profile Directory.txt","r");		
 		
	while (fscanf (cpd, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", fname, lname, fusername, fpassword, email_address, phonenum, address, &fid) !=EOF) 
	{
 		if( id == fid)
		{
	        bko = fopen("bkorders.txt","a+");
	        
			fprintf (bko, "%s\t%s\n%s\n%s\n%s\n\n", fname, lname, email_address, phonenum, address);
			
			strcat(fullname,fname);
			strcat(fullname,str1);
			strcat(fullname,lname);
			
			strcat(email, email_address);
			strcat(phone, phonenum);
			strcat(add, address);
	        
	 		fclose(bko);
    	}
				
	}
	fclose(cpd);
	
	printf("                                       **********************************************                               \n");
	printf("                                                      Burger King Menu                                              \n");
	printf("                                       **********************************************                               \n");
	printf("Item Code#        Menu Item                                         Size                          Price($)          \n");
	
	printf("[01]--------|Whopper w/ cheese                              |--| combo / only               |----| 720 / 560        \n");
	printf("[02]--------|Double Whopper w/ cheese                       |--| combo / only               |----| 950 / 790        \n");
	printf("[03]--------|Whopper w/ cheese & bacon                      |--| combo / only               |----| 800 / 640        \n");
	printf("[04]--------|Steakhouse Sandwich                            |--| combo / only               |----| 800 / 640        \n");
	printf("[05]--------|Double Cheeseburger                            |--| combo / only               |----| 615 / 455        \n");
	printf("[06]--------|Whopper Jr                                     |--| combo / only               |----| 480 / 325        \n");
	printf("[07]--------|Original Chicken Sandwich                      |--| combo / only               |----| 520 / 350        \n");
	printf("[08]--------|American Chicken Sandwich                      |--| combo / only               |----| 600 / 430        \n");
	printf("[09]--------|Chicken Club Sandwich                          |--| combo / only               |----| 660 / 500        \n");
	printf("[10]--------|Chicken Nuggets                                |--| combo / only               |----| 600 / 430        \n");
	printf("[11]--------|Tendergrilled Chicken                          |--| combo / only               |----| 900 / 740        \n");
	printf("[12]--------|Big Fish Deluxe                                |--| combo / only               |----| 620 / 440        \n");
	printf("[13]--------|Garden Side Salad                              |--| only                       |----| 270              \n");
	printf("[14]--------|Chicken Garden Salad                           |--| only                       |----| 730              \n");
	printf("[15]--------|Chicken Club Salad                             |--| only                       |----| 730              \n");
	printf("[16]--------|Sausage, Egg & Cheese Croissan'wich            |--| combo / only               |----| 210 / 150        \n");
	printf("[17]--------|Ham, Egg & Cheese Croissan'wich                |--| combo / only               |----| 210 / 150        \n");
	printf("[18]--------|Bacon, Egg & Cheese Croissan'wich              |--| combo / only               |----| 210 / 150        \n");
	printf("[19]--------|Egg & Cheese Croissan'wich                     |--| combo / only               |----| 170 / 110        \n");
	printf("[20]--------|French Toast Sticks w/ syrup                   |--| combo / only               |----| 130 / 100        \n");
	printf("[21]--------|Scrambled Egg Platter w/ (bacon/ham)           |--| combo                      |----| 240              \n");
	printf("[22]--------|Hash Browns                                    |--| only                       |----| 80               \n");
	printf("[23]--------|Escovietch Fish & Bammy                        |--| combo                      |----| 720              \n");
	printf("[24]--------|Soda                                           |--| small / medium / large     |----| 245 / 270 / 300  \n");
	printf("[25]--------|Smoothie                                       |--| small / medium / large     |----| 345 / 370 / 400  \n");
	printf("[26]--------|Orange Juice                                   |--| regular                    |----| 200		        \n");
	printf("[27]--------|Bottled Water                                  |--| regular                    |----| 200              \n");
	printf("[28]--------|Shake                                          |--| small / medium / large     |----| 230 / 310 / 420	\n");
	printf("[29]--------|2Pc. Cookies                                   |--| only                       |----| 135              \n");
	printf("[30]--------|4Pc. Cookies                                   |--| only                       |----| 270              \n");
	printf("[31]--------|Oreo Cheesecake                                |--| only                       |----| 300              \n");
	printf("[32]--------|Hershey's Sundae Pie                           |--| only                       |----| 260              \n");
	printf("[33]--------|Apple Pie                                      |--| only                       |----| 200              \n");
	printf("[34]--------|Coffee                                         |--| regular                    |----| 400              \n");
	printf("[35]--------|Fries                                          |--| small / large              |----| 200 / 160        \n");

	bko = fopen("bkorders.txt","a+");
	 
	printf("\n\nHow many orders are you placing?\t ");
	scanf("%d", &order_amount);	
							
	printf("\n\n Enter '36' for your order number to choose a different restaurant or '37' to go back to main menu");
			
	printf("\n\nEnter Order #%d:\t", count);
			scanf("%d",&choice);
			
			if(choice == 36)
			{
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				restaurants();
			}
			
			else if(choice == 37)
			{
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				mainmenu();
			}
			
			else if (choice > 37)
			{
				printf("Wrong Input! Re-enter THe Correct Option\n\n");
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				Burger_King();
			}
	
	printf("\n\n Enter your desired size (small, regular, medium, large, combo or only ):\t");
	scanf("%s", size);	
	
	bkmenu = fopen("Burger King Menu.txt","r");	
	
	while (fscanf (bkmenu, "%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", &itemno, item1, item2, item3, item4, item5, type, &price)!=EOF)
		{
											
			if( strcmp(type, size)==0 && (choice == itemno)) 
			{
		
				printf ("\n\nOrder:\t%d %s %s %s %s %s %s\n", itemno, item1, item2, item3, item4, item5, type);
				
				fprintf (bko, "Order #1:\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", itemno, item1, item2, item3, item4, item5, type);
				
				mtnode->itemno = itemno;
				mtnode-> nextptr = NULL;
	            temp = mtnode;
				
				strcpy(stnode->foodname, item1); strcat(stnode->foodname, str1);
				strcat(stnode->foodname, item2); strcat(stnode->foodname, str1);
				strcat(stnode->foodname, item3); strcat(stnode->foodname, str1);
				strcat(stnode->foodname, item4); strcat(stnode->foodname, str1);
				strcat(stnode->foodname, item5); strcat(stnode->foodname, str1);
				strcat(stnode->foodname, str1); strcat(stnode->foodname, type);
				
				stnode-> nextptr = NULL; 
	            tmp = stnode;
				
				ntnode->price = price;
				printf("\nPrice for one:\t%d", ntnode->price);
				fprintf (bko, "Price for one:\t%d\n", ntnode->price);
				ntnode-> nextptr = NULL; 
	            tmpo = ntnode;
			
				printf("\n\nQuantity:\t");
				scanf(" %d",&quantity);
				dtnode->quantity = quantity;
				fprintf (bko, "Quantity:\t\t%d\n", dtnode->quantity);
				dtnode-> nextptr = NULL; 
	            tempo = dtnode;
	            
				cost = price*quantity;
				ltnode->cost = cost;			
		 		printf("\n\nCost:\t%d", ltnode->cost);
				fprintf (bko, "Cost for item:\t%d\n\n", ltnode->cost);
				ltnode-> nextptr = NULL; 
	            tempy = ltnode;
			   				
			}
				Total_cost = cost;		
		}
		fclose (bkmenu);

	for (i=2; i <= order_amount; i++)
		{
			fnNode = (struct ordersbk *)malloc(sizeof(struct ordersbk));
			snNode = (struct ordersbk *)malloc(sizeof(struct ordersbk));
			tnNode = (struct ordersbk *)malloc(sizeof(struct ordersbk));
			fournNode = (struct ordersbk *)malloc(sizeof(struct ordersbk));
			fifnNode = (struct ordersbk *)malloc(sizeof(struct ordersbk));
			ktnode = (struct ordersbk *)malloc(sizeof(struct ordersbk));
			
			
			printf("\n\n Enter '36' for your order number to choose a different restaurant or '37' to go back to main menu");
			
			printf("\n\nEnter Order #%d:\t", i);
			scanf("%d",&choice);
			
			if(choice == 36)
			{
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				restaurants();
			}
			
			else if(choice == 37)
			{
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				mainmenu();
			}
			
			else if (choice > 37)
			{
				printf("Wrong Input! Re-enter THe Correct Option\n\n");
					printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				Burger_King();
			}
			
			printf("\n\n Enter your desired size (small, regular, medium, large, combo or only ):\t");
			scanf("%s", size);	
			bkmenu = fopen("Burger King Menu.txt","r");	
			
		while (fscanf (bkmenu, "%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n", &itemno, item1, item2, item3, item4, item5, type, &price)!=EOF)
				{
											
					if( strcmp(type, size)==0 && (choice == itemno)) 
						{
						
							printf ("\n\nOrder:\t%d %s %s %s %s %s %s\n", itemno, item1, item2, item3, item4, item5, type);
							
							fprintf (bko, "Order #%d:\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", i, itemno, item1, item2, item3, item4, item5, type);
							
							snNode->itemno = itemno;
							snNode->nextptr = temp-> nextptr;
                			temp->nextptr = snNode; 
               				temp = snNode;
							
							strcpy(fnNode->foodname, item1); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item2); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item3); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item4); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, item5); strcat(fnNode->foodname, str1);
							strcat(fnNode->foodname, str1); strcat(fnNode->foodname, type);
							
               				fnNode->nextptr = tmp-> nextptr; 
                			tmp->nextptr = fnNode; 
                			tmp = fnNode;
                			
							tnNode->price = price;
							printf("\nPrice for one:\t%d", tnNode->price);
							fprintf (bko, "Price for one:\t%d\n", tnNode->price);
							tnNode->nextptr = tmpo-> nextptr;
                			tmpo->nextptr = tnNode; 
                			tmpo = tnNode;
							
							printf("\n\nQuantity:\t");
							scanf(" %d",&quantity);
							fournNode->quantity = quantity;
							fprintf (bko, "Quantity:\t\t%d\n", fournNode->quantity);
							fournNode->nextptr = tempo-> nextptr;
                			tempo->nextptr = fournNode; 
                			tempo = fournNode;
                            
							cost = price*quantity;		
							fifnNode->cost =cost;	
					 		printf("\n\nCost:\t%d", fifnNode->cost);
							fprintf (bko, "Cost for item:\t%d\n\n", fifnNode->cost);
							fifnNode->nextptr = tempy-> nextptr;
			                tempy->nextptr = fifnNode; 
			                tempy = fifnNode;
							   				
						}
							
				}
				
				Total_cost = Total_cost + cost;	
				fclose (bkmenu);	
			
		}
	printf("\n\nYour total before GCT:\t%d",Total_cost);
	fprintf(bko,"Total before GCT:\t%d\n",Total_cost);
	
	GCT = Total_cost*0.165;	
	
	printf("\n\nGCT added (16.5%):\t%d",GCT);
	fprintf(bko,"GCT added (16.5%):\t%d\n",GCT);
		
	ktnode->BkGrand_total = Total_cost + GCT + 1000;

	printf("\n\nYour total is:\t%d",ktnode->BkGrand_total);
	
	printf("\n");
	
	fprintf(bko,"Grand Total: \t%d\n",ktnode->BkGrand_total);
	ktnode-> nextptr = NULL; 
	tp = ktnode;
	
	fclose(bko);
	printf("\n\nYour bill is being generated. Please wait a minute. Thank You!");
	printf("\n\n");
	for(wait=0;wait<=50000;wait++)
	{
		printf("\rIn progress : %d",wait/500);
	}
	system("cls");
	printf("\n\n\n\n");
	printf("____________________________________________________________________________________________________________\n");
    printf("                                        CUSTOMER INFORMATION                                     \n");
	printf("Name on Order: %s\n", fullname);
	printf("Email Address: %s\n", email);
	printf("Callback Phone #: %s\n",phone);
	printf("Delivery Address: %s\n", add);
    printf("Restaurant: Burger King\n");
    printf("\n");        
    printf("                                          ORDER DETAILS                                          \n");
    generate_order_numbers_bk();
    printf("\n");  
    printf("        The following order is being delivered hot and fresh to your door:                       \n");      
    printf("\n");
    printf("\n");	
    printf("|Food No.|                 Food Name                    |  Unit Price   | Quantity   |       Total      |");
    printf("\n");
    printf("____________________________________________________________________________________________________________\n");
	printf("\n");
	displayordersbk();
	printf("\n                                                                                      __________________\n");
	printf("\n                                                              Your total before GCT:         $%-5d",Total_cost);
	printf("\n                                                                   GCT added (16.5%):         $%-5d",GCT);
	printf("\n                                                                    Delivery Charge:         $1000");	
	printf("\n                                                                                      __________________\n");
	printf("\n                                                                        Grand Total:         $%-5d", ktnode->BkGrand_total);
	printf("\n");
	printf("_____________________________________________________________________________________________________________\n");


	printf("\n\nAre you ready to proceed with payment?\n\n Enter '1' when you are ready\t");
	scanf ("%d", &answer);
	
	if(answer == 1)
			{
				printf("\n\n");
				for(wait=0;wait<=50000;wait++)
				{
					printf("\rIn progress : %d",wait/500);
				}
				system("cls");
				
				BKPayment();
			}
}

void displayordersbk()
{
    struct ordersbk *temp, *tmp, *tmpo, *tempo, *tempy;
	if(mtnode == NULL && stnode == NULL && ntnode == NULL && dtnode == NULL && ltnode == NULL )
    {
        printf(" No data found in the list.");
    }
    else
    {
        temp = mtnode; tmp = stnode; tmpo = ntnode; tempo = dtnode; tempy = ltnode;
        while(temp != NULL && tmp != NULL && tmpo != NULL && tempo != NULL && tempy != NULL)
        {
            printf("|  %02d    | %-45s|  $%-4d        |    %-4d    |        $%-5d    |\n",temp->itemno, tmp->foodname, tmpo->price, tempo->quantity, tempy->cost);  
            temp = temp->nextptr; tmp = tmp->nextptr; tmpo = tmpo->nextptr; tempo = tempo->nextptr; tempy = tempy->nextptr;              
        }
    }
}

void generate_order_numbers_bk() 
{ 
   int i, ordernum, fordernum, lower = 0, upper = 4000000; 
    FILE *onu;
    FILE *bko;
     
	 
	 // Use current time as  
    // seed for random generator 
    srand(time(0)); 
    
	ordernum = (rand() %
    (upper - lower + 1)) + lower; 
    
    onu = fopen("order numbers used.txt","r");	
    
   	while (fscanf (onu,"%d\n", &fordernum)!=EOF)
   	{
   		if (ordernum == fordernum)
   		{
   			int ordernum = (rand() % 
   			(upper - lower + 1)) + lower; 
   		}
   		else 
   		{
   			fclose (onu);
	        printf("Receipt Number:\t%d\n ", ordernum);
	        onu = fopen("order numbers used.txt","a+");	
	        fprintf (onu,"%d\n ", ordernum);
	        fclose (onu);
	        bko = fopen("bkorders.txt","a+");
	        fprintf(bko, "Receipt Number:\t%d\n", ordernum);
	        fclose (bko);
   		}
   	} 
   	
   	
} 

void BKPayment()
{
	int card_number[100], pin, pay, select, wait;
	struct ordersbk *tp;
	FILE *bko;
	
	printf("\n\nAre you paying with cash or credit card? \n");
	printf("Enter: [1] for cash \n");
	printf("       [2] for credit card \n");
	printf("       [3] to CANCEL order and payment \n");
	scanf ("%d", &pay);
	
	if (pay == 1)
	{
		if( ktnode == NULL)
    	{
        printf(" No data found in the list.\n\n");
    	}
    	else
    	{
     		tp = ktnode; 
	        while( tp != NULL)
	        {
				printf("\n\nPayment Method: Pay with Cash upon Delivery $%d", tp->BkGrand_total );
				printf("\n\n*Note: Drivers carry less than $1,000 in change. Feeling generous? You can tip at the door.\n\n");
				tp = tp->nextptr;
			}
			bko = fopen("bkorders.txt","a+");
   			fprintf(bko, "APPROVED!\n\n");
      		fclose (bko);
		}
		
	}
	
	else if (pay == 2)
	{
		if( ktnode == NULL)
    	{
        printf(" No data found in the list.\n\n");
    	}
    	else
    	{
     		tp = ktnode; 
	        while( tp != NULL)
	        {
	        	
				printf("\n\nPayment Method: Credit Card \n\n Amount: $%d", tp->BkGrand_total );
				tp = tp->nextptr;
				
				printf("\n\nEnter Your Card No [we never save your card number]: ");
				scanf("%d",&card_number);
				
				printf("\n\nEnter Your Card Pin [we never save your pin]  : ");
				scanf("%d",&pin);
				
				bko = fopen("bkorders.txt","a+");
		        fprintf(bko, "APPROVED!\n\n");
		        fclose (bko);
				
				printf("\n\nPAYMENT SUCCESS!\n\n");
			}
		}
	
	}
	else if (pay == 3)
		{
			bko = fopen("bkorders.txt","a+");
	        fprintf(bko, "CANCELLED!\n\n");
	        fclose (bko);
		}
	
	printf("\n\n 1. Wanna Buy Another Delicious?");
	printf("\n 2. Main Menu \n\n");
	printf("     select:\t ");
	scanf("%d", &select);
	
	if (select == 1)
	{
		printf("\n\n");
		for(wait=0;wait<=50000;wait++)
		{
			printf("\rIn progress : %d",wait/500);
		}
	
		system("cls");
		restaurants();
	}
	
	else if (select == 2)
	{
		printf("\n\n");
		for(wait=0;wait<=50000;wait++)
		{
			printf("\rIn progress : %d",wait/500);
		}
	
		system("cls");
		mainmenu();
	}
}
