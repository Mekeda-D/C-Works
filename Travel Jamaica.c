#include<stdio.h>
// This program suggest touring services, restaurants, attractions, clubs and hotels that users can attend when visiting Jamaica's hottest tourist or resort areas or parishes

//Each module represents what item the user will be suggested based on their standards and last module allows an administrator to updat the files

void Touring_services ();	
void Restaurants ();
void Attractions ();
void Clubs ();
void Hotels ();
void Make_Updates ();

int main ()
{
// function declarations 
char password[20], username[40];
int options;
			printf ("\t\t\t\t\t\t\t\t **** WELCOME TO TRAVEL JAMAICA: ****\n\n");
			printf ("Where you will be advised of all the best touring services, restaurants, hotels, attractions, clubs you can attend during your stay in Jamaica that are within the top, tourist hot spots of Jamaica.\n");
			printf ("\nIf you are admin to this program, you are also allowed to make updates to this program for the user's continued enjoyment.\n");
			printf ("\nWhen you are finished, enter 7 when the option is available to you to terminate the program.\n\n");
			printf ("I hope you find this program useful.\n\n");
			printf ("\t\t\t\t\t **** ENJOY!  :) ****\n\n");
			
//Main menu provided where user can choose what product they would like suggestions for or if they would like to add more products to the files
//Each option represents a function of the program 
			
			printf ("\t** Options: **\n\n");
			printf ("\t 1: Touring services\n");
			printf ("\t 2: Restaurants\n");
			printf ("\t 3: Attractions\n");
			printf ("\t 4: Clubs\n");
			printf ("\t 5: Hotels\n");
			printf ("\t 6: Make updates to files\n");
			printf ("\t 7: Finished\n");
	
	
	printf("Enter the corresponding number of the item you are interested in\n");
	
	scanf("%d",&options);
	
	while (1)//this function is repeated until the user instructs the program to terminate 
	{
				
		if (options == 1)
			{
				 Touring_services (); //choosing option 1, carries out touring services function
			}

		else if (options == 2)
			{		
				Restaurants (); //choosing option 2, carries out restaurants function
			}
			
		else if (options == 3)
			{
				 Attractions ();	//choosing option 3, carries out attractions function
			}
			
		else if (options == 4)
			{
				Clubs ();	//choosing option 4, carries out clubs function
			}
		else if (options == 5)
			{
				Hotels ();	//choosing option 5, carries out hotels function
			}
		else if (options == 6)	//choosing option 6, will require user to enter a password that will grant them access to make update to used files
			{
				printf("Enter username. Your username can have no spaces.\n");
				scanf ("%s", username); 
				
				printf("Enter password\n");
				scanf ("%s", password);
				
				if (strcmp(password,"MD&CTravels")==0) //MD&CTravels is the password used to gain access.
				{
					printf("\n\nACCESS GRANTED!\n\nYOU MAY PROCEED.\n\n");
					Make_Updates ();
				}
				
				else
				{
					printf("\n\nACCESS DENIED!\n\nYOU HAVE NOT BEEN AUTHORISED.\n\n\nYou will now be taken back to main menu.\n\n\n\n");
					main (); //if wrong password is entered, user is taken back up to main menu or start of program
				}
			
			}
		else if (options == 7)
			{
				printf ("\t\t\t **** Thank You For Using This Program. Have A Nice Day!!****\n\n");
				break; //program is terminated
			}
			
			printf ("\t** Options: **\n\n");
			printf ("\t 1: Touring services\n");
			printf ("\t 2: Restaurants\n");
			printf ("\t 3: Attractions\n");
			printf ("\t 4: Clubs\n");
			printf ("\t 5: Hotels\n");
			printf ("\t 6: Make updates to files\n");
			printf ("\t 7: Finished\n");
	
	
			printf("Enter the corresponding number of the item you are interested in\n");
		
			scanf("%d",&options);
	
	}

			
	return 0;
}
	
//Function suggests touring services that user can use to get a poductive and pleasurable tour of Jamaica or a fraction of Jamaica

void Touring_services ()
{
//Each variable accept information about the touring service from the file and of the touring service the user desires. 

			char file_name[1000], file_destination[10], file_website[100], file_phonenum[50], file_address[100], destination[10];
			int	count=0, file_types, types, min_price, max_price;
			float file_rating,rating;
			
			FILE *filepointer;

//These parishes are the tourist hotspots of Jamaica 

			printf ("\n\n\t\t\t **** Destinations: ****\n\n");
			printf ("\t K&A       = Kingston & St.Andrew\n");
			printf ("\t POR       = Portland\n");
			printf ("\t ANN       = St.Ann\n");
			printf ("\t JAM       = St.James\n");
			printf ("\t MAR       = St.Mary\n");
			printf ("\t TRE       = Trelawny\n");
			printf ("\t WML       = Westmoreland\n");
	
			printf("Enter the abbreviation of your desired destination\n");
			scanf("%s", destination); //variable accepts the target destination of the user 
			
						
			printf ("\n\n\t\t\t **** Types of Touring Services: ****\n\n");
			printf ("\t 1  = Bus and Minivan Tours\n");
			printf ("\t 2  = Cruises, Sailing and Water Tours\n");
			printf ("\t 3  = City Tours\n");
			printf ("\t 4  = Cultural and Theme Tours\n");
			printf ("\t 5  = Historical and Heritage tours\n");
			printf ("\t 6  = Literary, Art and Music Tours\n");
			printf ("\t 7  = 4WD, ATV and off road tours\n");
			printf ("\t 8  = Private Sightseeing Tours\n");
			printf ("\t 9  = Walking,Biking, mountain biking Tours\n");
			printf ("\t 10 = Western Caribbean Shore Excursions\n");
		
			
			printf("\nEnter the number for the type you want.\n");
			scanf("%d", &types); //variable accepts the type of touring service the user wants to embark on which indicates what the user will be doing on the tour
			
	
			
			printf("\nEnter ratings : 1-5\n");
			scanf("%f", &rating); //variable accepts the rating the person desires the service to be at or more
		
//file containing all touring services is opened to be read from
			
				filepointer= fopen("C:\\Users\\dayna\\Documents\\Computer science\\files to c programs\\touring services.txt", "r");
					
				if (filepointer==NULL) //If file does not exist an error will be printed and if it is the touring services can be read from it
				{
					printf("Error: File does not exist.\nPlease create File\n\n.");
					exit(0);
				}
				
				else
				{
					fscanf (filepointer, "%s\t%s\t%d\t%d\t%f\t%d\t%s\t%s\t%s\n", file_name, file_destination, &min_price, &max_price, &file_rating, &file_types, file_website, file_phonenum, file_address );
					
//the name, parish of location, estimated minimum and maximum price, the service rating, type, website, phone number and address is read from file
 
					while (!feof (filepointer)) //checks if the "end-of-file" (EOF) has been reached and continues reading from file until it has been
					{
						
						if(strcmp(file_destination, destination)==0 && file_rating >= rating && file_types == types) //ensures that all user's specifications are met in order to suggest a particular tour
						{
							printf("NAME: %s\n DESTINATION: %s\n ESIMATED MINIMUM PRICE: US%d\n ESIMATED MAXIMUM PRICE: US%d\n RATING: %0.1f\n TYPE #: %d\n WEBSITE: %s\n PHONE NUMBER: %s\n ADDRESS: %s\n\n", file_name, file_destination, min_price, max_price, file_rating, file_types, file_website, file_phonenum, file_address );
							// prints the information of the tour to the user
					
							count++;
						}
						
						else
						{
							count;
						}
						fscanf (filepointer, "%s\t%s\t%d\t%d\t%f\t%d\t%s\t%s\t%s\n", file_name, file_destination, &min_price, &max_price, &file_rating, &file_types, file_website, file_phonenum, file_address );
					}
						
						fclose (filepointer); // file is closed 
						
						if (count == 0)
						{
							printf(" \n\nNO TOURING SERVICES AVAILABLE :( \n\n\n\n"); 
						}	//the count was incremented if a touring service was found and it remained the same if by the end of the search no tour was found
							//So if the count remained at 0 then the program will know that no touring service had been found that matches all user's preferences
							//Hence, the user will be notified of such
						
							
				}
				
}	
//Function suggests restaurants that user can visit in Jamaica

void Restaurants ()
{
	//Each variable accept information about the restaurant from the file and of the trestaurant the user desires. 
	
	char R_name[1000], R_destination[10], R_website[100], R_phonenum[50], R_address[100],R_culture[20],destination[10], types[1000],culture[20];
	int count=0,Rmin_price, Rmax_price;
	float R_rating, rating;
	
	FILE *fp;

		
			//These parishes are the tourist hotspots of Jamaica 

			printf ("\n\n\t\t\t **** Destinations: ****\n\n");
			printf ("\t K&A       = Kingston & St.Andrew\n");
			printf ("\t POR       = Portland\n");
			printf ("\t ANN       = St.Ann\n");
			printf ("\t JAM       = St.James\n");
			printf ("\t MAR       = St.Mary\n");
			printf ("\t TRE       = Trelawny\n");
			printf ("\t WML       = Westmoreland\n");
	
			printf("Enter the abbreviation of your desired destination\n");
			scanf("%s", destination); //variable accepts the target destination of the user 
			
					
			printf ("\n\n\t\t\t **** Culture of Restaurant: ****\n\n");
			printf ("\t African\n");
			printf ("\t America\n");
			printf ("\t Chinese\n");
			printf ("\t French\n");
			printf ("\t Greek\n");
			printf ("\t Indian\n");
			printf ("\t Italian\n");
			printf ("\t Jamaica\n");
			printf ("\t Japan\n");
			printf ("\t Spanish\n");
			
			printf("Enter the Culture you want\n");
			scanf("%s", culture); //variable accepts the cuture of the restaurant the user wants to attend
			
			printf("\nEnter ratings : 1-5\n");
			scanf("%f", &rating); //variable accepts the rating the person desires the establishment to be at or more
			
	
			//file containing all restaurants is opened to be read from
				
				fp= fopen("C:\\Users\\dayna\\Documents\\Computer science\\files to c programs\\restaurants.txt", "r");
	
				if (fp==NULL)
				{
					printf("Error: File does not exist.\nPlease create File\n\n."); //If file does not exist an error will be printed and if it is the restaurants can be read from it
					exit(0);
				}
				
				else
				{
					fscanf (fp, "%s\t%s\t%d\t%d\t%f\t%s\t%s\t%s\t%s\n", R_name, R_destination, &Rmin_price, &Rmax_price, &R_rating, R_culture, R_website, R_phonenum, R_address );
										
//the name, parish of location, estimated minimum and maximum price, the establsihment rating, culture, website, phone number and address is read from file					
					
					while (!feof (fp))//checks if the "end-of-file" (EOF) has been reached and continues reading from file until it has been
					{
						
						if(strcmp(R_destination, destination)==0 && R_rating >= rating && strcmp(R_culture, culture)==0 )//ensures that all user's specifications are met in order to suggest a particular restaurant
						{
							printf("NAME: %s\n DESTINATION: %s\n ESIMATED MINIMUM PRICE: US%d\n ESIMATED MAXIMUM PRICE: US%d\n RATING: %0.1f\n CULTURE: %s\n WEBSITE: %s\n PHONE NUMBER: %s\n ADDRESS: %s\n\n", R_name, R_destination, Rmin_price, Rmax_price, R_rating, R_culture, R_website, R_phonenum, R_address );
							
							// prints the information of the restaurant to the user
							
							count++;
						}
						else
						{
							count;
						}
						
						fscanf (fp, "%s\t%s\t%d\t%d\t%f\t%s\t%s\t%s\t%s\n", R_name, R_destination, &Rmin_price, &Rmax_price, &R_rating, R_culture, R_website, R_phonenum, R_address );
				
					}
					
						fclose (fp); //file is closed
						
						
						if (count == 0)
						{
							printf(" \n\n\nNO RESTAURANTS AVAILABLE :( \n\n\n\n");
						}	//the count was incremented if a restaurant was found and it remained the same if by the end of the search no restaurant was found
							//So if the count remained at 0 then the program will know that no restaurant had been found that matches all user's preferences
							//Hence, the user will be notified of such
				}
						
}
//Function suggests attractions in Jamaica that user can savour
		
void Attractions ()
{
	//Each variable accept information about an attraction from the file and of the attraction the user desires. 
	
	char A_name[1000], A_destination[10], A_website[100], A_phonenum[50], A_address[100],destination[10];
	int count=0, A_types, types, Amin_price, Amax_price;
	float A_rating, rating;
	
	FILE *fp1;

			//These parishes are the tourist hotspots of Jamaica 
			
			printf ("\n\n\t\t\t **** Destinations: ****\n\n");
			printf ("\t K&A       = Kingston & St.Andrew\n");
			printf ("\t POR       = Portland\n");
			printf ("\t ANN       = St.Ann\n");
			printf ("\t JAM       = St.James\n");
			printf ("\t MAR      = St.Mary\n");
			printf ("\t TRE       = Trelawny\n");
			printf ("\t WML       = Westmoreland\n");
			
			printf("Enter the abbreviation of your desired destination\n");
			scanf("%s", destination);	//variable accepts the target destination of the user
			
			printf ("\n\n\t\t\t **** Types of Attractions: ****\n\n");
			printf ("\t 1 = Art Galleries\n");
			printf ("\t 2 = Bodies of Water,Beaches, Marinas & Cruises\n");
			printf ("\t 3 = Hiking,Camping & Horseback riding\n");
			printf ("\t 4 = Museums\n");
			printf ("\t 5 = Nature & Wildlife\n");
			printf ("\t 6 = Shops & Malls\n");
			printf ("\t 7 = Spas\n");
			printf ("\t 8 = Water & Amusement Parks & Excursions\n");
		
			printf("Enter the number for the type you want\n");
			scanf("%d", &types);	//variable accepts the type of attraction the user wants to revel in
			
			printf("\nEnter ratings : 1-5\n");
			scanf("%f", &rating);	//variable accepts the rating the person desires the attraction to be at or more
			
			
				//file containing all attractions is opened to be read from
			
				fp1= fopen("C:\\Users\\dayna\\Documents\\Computer science\\files to c programs\\attractions.txt", "r");
	
				if (fp1==NULL)
				{
					printf("Error: File does not exist.\nPlease create File\n\n.");	//If file does not exist an error will be printed and if it is the attractions can be read from it
					exit(0);
				}
				
				else
				{
					fscanf (fp1, "%s\t%s\t%d\t%d\t%f\t%d\t%s\t%s\t%s\n", A_name, A_destination, &Amin_price, &Amax_price, &A_rating, &A_types, A_website, A_phonenum, A_address );
					
					//the name, parish of location, estimated minimum and maximum price, the attraction rating, type, website, phone number and address is read from file
					
					while (!feof (fp1))//checks if the "end-of-file" (EOF) has been reached and continues reading from file until it has been
					
					{
						if(strcmp(A_destination, destination)==0 && A_rating >= rating && (A_types==types))//ensures that all user's specifications are met in order to suggest a particular attraction
						{
							printf("NAME: %s\n DESTINATION: %s\n ESIMATED MINIMUM PRICE: US%d\n ESIMATED MAXIMUM PRICE: US%d\n RATING: %0.1f\n TYPE #: %d\n WEBSITE: %s\n PHONE NUMBER: %s\n ADDRESS: %s\n\n", A_name, A_destination, Amin_price, Amax_price, A_rating, A_types, A_website, A_phonenum, A_address  );
							
							// prints the information of the attraction to the user
				
							count++;
						}
						else
						{
							count;
						}
						
						fscanf (fp1, "%s\t%s\t%d\t%d\t%f\t%d\t%s\t%s\t%s\n", A_name, A_destination, &Amin_price, &Amax_price, &A_rating, &A_types, A_website, A_phonenum, A_address );
					
					}
					
						fclose (fp1);	// file is closed 
						
					
						if (count == 0)
						
						{
							printf(" \n\n\nNO ATTRACTIONS AVAILABLE :( \n\n\n\n"); 
						}	//the count was incremented if an attraction was found and it remained the same if by the end of the search none was found
							//So if the count remained at 0 then the program will know that no attraction had been found that matches all user's preferences
							//Hence, the user will be notified of such
				}
					
}				

//Function suggests clubs that user can attend to have a pleasurable time in Jamaica 

void Clubs ()
{
	//Each variable accept information about a club from the file and of the club the user desires. 

	char C_name[1000], C_destination[10], C_website[100], C_phonenum[50], C_address[100], destination[10];
	int count=0, C_criteria, criteria, Cmin_price, Cmax_price;
	float C_rating, rating;
	
	FILE *fp2;

			//These parishes are the tourist hotspots of Jamaica 

			printf ("\n\n\t\t\t **** Destinations: ****\n\n");
			printf ("\t K&A       = Kingston & St.Andrew\n");
			printf ("\t POR       = Portland\n");
			printf ("\t ANN       = St.Ann\n");
			printf ("\t JAM       = St.James\n");
			printf ("\t MAR      = St.Mary\n");
			printf ("\t TRE       = Trelawny\n");
			printf ("\t WML       = Westmoreland\n");
			
			
			printf("Enter the abbreviation of your desired destination\n");
			scanf("%s", destination);	//variable accepts the target destination of the user 
			
			printf ("\n\n\t\t\t **** Criteria: ****\n\n");
			printf ("\t 1  = Dance & Disco\n");
			printf ("\t 2  = Good for couples\n");
			printf ("\t 3  = Good for big groups\n");
			printf ("\t 4  = Serves food\n");
			printf ("\t 5  = Host parties\n");

			printf("Enter the number for the Criteria you want\n");
			scanf("%d", &criteria);	//variable accepts the criteria of the club the user wants to go to
			
			
			printf("\nEnter ratings : 1-5\n");
			scanf("%f", &rating);	//variable accepts the rating the person desires the club to be at or more
			
			
			//file containing all clubs is opened to be read from
				fp2= fopen("C:\\Users\\dayna\\Documents\\Computer science\\files to c programs\\clubs.txt", "r");
	
				if (fp2==NULL)
				{
					printf("Error: File does not exist.\nPlease create File\n\n.");	//If file does not exist an error will be printed and if it is the clubs can be read from it
					exit(0);
				}
				
				else
				{
					fscanf (fp2, "%s\t%s\t%d\t%d\t%f\t%d\t%s\t%s\t%s\n", C_name, C_destination, &Cmin_price, &Cmax_price, &C_rating, &C_criteria, C_website, C_phonenum, C_address );
					
					//the name, parish of location, estimated minimum and maximum price, the club rating, criteria, website, phone number and address is read from file
					
					while (!feof (fp2))	//checks if the "end-of-file" (EOF) has been reached and continues reading from file until it has been
					{
						
						if(strcmp(C_destination,destination)==0 && C_rating >= rating && (C_criteria == criteria))	//ensures that all user's specifications are met in order to suggest a particular club
						{
							printf("NAME: %s\n DESTINATION: %s\n ESIMATED MINIMUM PRICE: US%d\n ESIMATED MAXIMUM PRICE: US%d\n RATING: %0.1f\n CRITERIA #:%d\n WEBSITE: %s\n PHONE NUMBER: %s\n ADDRESS: %s\n\n", C_name, C_destination, Cmin_price, Cmax_price, C_rating, C_criteria, C_website, C_phonenum, C_address);
							
							// prints the information of the club to the user
							
							count++;
						}
						else
						{
							count;
						}
						
						fscanf (fp2, "%s\t%s\t%d\t%d\t%f\t%d\t%s\t%s\t%s\n", C_name, C_destination, &Cmin_price, &Cmax_price, &C_rating, &C_criteria, C_website, C_phonenum, C_address );
					
					}
						
						fclose (fp2); //file is closed
						
						if (count == 0)
						{
							printf(" \n\n\nNO ClUBS AVAILABLE :( \n\n\n\n");
						}//the count was incremented if a club was found and it remained the same if by the end of the search none was found
						//So if the count remained at 0 then the program will know that no club had been found that mathces all user's preferences
						//Hence, the user will be notified of such
				}
					
}		
//Function suggests hotels that user can stay at in Jamaica
		
void Hotels ()	
{
	//Each variable accept information about a hotel from the file and of the hotel the user desires. 
	
	char H_name[1000], H_destination[10], H_website[100], H_phonenum[50], H_address[100], destination[10];
	int count=0,H_fun, H_services, H_facilities, fun, services, facilities, Hmin_price, Hmax_price;
	float H_rating, rating;
	
	FILE *fp4;
			
			//These parishes are the tourist hotspots of Jamaica 

			printf ("\n\n\t\t\t **** Destinations: ****\n\n");
			printf ("\t K&A       = Kingston & St.Andrew\n");
			printf ("\t POR       = Portland\n");
			printf ("\t ANN       = St.Ann\n");
			printf ("\t JAM       = St.James\n");
			printf ("\t MAR      = St.Mary\n");
			printf ("\t TRE       = Trelawny\n");
			printf ("\t WML       = Westmoreland\n");
			
			printf("Enter the abbreviation of your desired destination\n");
			scanf("%s", destination);	//variable accepts the target destination of the user
			
			printf ("\n\n\t\t\t **** Fun things to Do: ****\n\n");
			printf ("\t 1 = Beach, Water skiing, Diving, Swimming pool \n");
			printf ("\t 2 = Games room\n");
			printf ("\t 3 = Golf course\n");
			printf ("\t 4 = Horse riding\n");
			printf ("\t 5 = Water & Amusement park close by\n");
			printf ("\t 6 = Playing and seeing see creatures,scuba diving & Fishing\n");
			printf ("\t 7 = Sailing\n");
			printf ("\t 8 = Spa\n");
			
			printf("Enter the number that correspond with the fun thing you want to do\n");
			scanf("%d", &fun);	 //variable accepts the activity the user wants to do 
			
			printf ("\n\n\t\t\t **** Services: ****\n\n");
			printf ("\t 1 = 24-Hour Front Desk\n");
			printf ("\t 2 = All meals included\n");
			printf ("\t 3 = Room service\n");
			
		
			printf("Enter the number that corresponds with the service you want.\n");
			scanf("%d", &services);	 //variable accepts the service the user wants
			
			printf ("\n\n\t\t\t **** Facilities: ****\n\n");
			printf ("\t 1  = Air conditioning\n");
			printf ("\t 2  = Bar/Lounge\n");
			printf ("\t 3  = Cable tv\n");
			printf ("\t 4  = Casino\n");
			printf ("\t 5  = Family rooms\n");
			printf ("\t 6  = Fitness centre\n");
			printf ("\t 7  = Free Wi-Fi\n");
			printf ("\t 8  = Landmarks\n");
			printf ("\t 9  = Parking\n");
			printf ("\t 10 = Pet Friendly\n");
			printf ("\t 11 = Bar/Lounge\n");
			printf ("\t 12 = Private pool\n");
			printf ("\t 13 = Restaurant\n");
			
		
			printf("Enter the number for the facility you want\n");
			scanf("%d", &facilities);	 //variable accepts the facility the user want to take pleasure from during their stay
			
			printf("\nEnter ratings : 1-5\n");
			scanf("%f", &rating);	//variable accepts the rating the person desires the hotel to be at or more
			
			
				//file containing all hotels is opened to be read from
			
				fp4= fopen("C:\\Users\\dayna\\Documents\\Computer science\\files to c programs\\hotels.txt", "r");
	
				if (fp4==NULL)
				{
					printf("Error: File does not exist.\nPlease create File\n\n.");	//If file does not exist an error will be printed and if it is the hotels can be read from it
					exit(0);
				}
				
				else
				{
					fscanf (fp4, "%s\t%s\t%d\t%d\t%f\t%d\t%d\t%d\t%s\t%s\t%s\n", H_name, H_destination, &Hmin_price, &Hmax_price, &H_rating, &H_fun, &H_services, &H_facilities, H_website, H_phonenum, H_address );
					
					//the name, parish of location, estimated minimum and maximum price, the service rating, activity, service, facility, website, phone number and address is read from file
					
					while (!feof (fp4))	//checks if the "end-of-file" (EOF) has been reached and continues reading from file until it has been
					{
						
						if(strcmp(H_destination,destination)==0 && H_rating >= rating && H_fun == fun && H_services == services && H_facilities ==facilities )	//ensures that all user's specifications are met in order to suggest a particular hotel
						{
							printf("NAME: %s\n DESTINATION: %s\n ESIMATED MINIMUM PRICE PER NIGHT: US%d\n ESIMATED MAXIMUM PRICE PER NIGHT: US%d\n RATING: %0.1f\n FUN THINGS #: %d\n SERVICE #: %d\n FACILITY #: %d\n WEBSITE: %s\n PHONE NUMBER: %s\n ADDRESS: %s\n\n", H_name, H_destination, Hmin_price, Hmax_price, H_rating, H_fun, H_services, H_facilities, H_website, H_phonenum, H_address );
							
							// prints the information of the hotel to the user
							
							count++;
						}
						else
						{
							count;
						}
						
						fscanf (fp4, "%s\t%s\t%d\t%d\t%f\t%d\t%d\t%d\t%s\t%s\t%s\n", H_name, H_destination, &Hmin_price, &Hmax_price, &H_rating, &H_fun, &H_services, &H_facilities, H_website, H_phonenum, H_address);
					
					}
						
						fclose (fp4);	// file is closed 
						
						if (count == 0)
						{
							printf(" \n\n\nNO HOTELS AVAILABLE :(\n\n\n\n ");
						}	//the count was incremented if a hotel was found and it remained the same if by the end of the search none was found
							//So if the count remained at 0 then the program will know that no hotel had been found that mathces all user's preferences
							//Hence, the user will be notified of such
				}
				
}		
//function allows the administrator to update each file used in the program

void Make_Updates ()
{
	//Each variable accept information about the touring service, hotel, restaurant, club and attration from the user and print to the file
	
	int min_price, max_price,sec_options, amount, types, fun, services, facilities, criteria, i ;
	float sec_rating;
	char name[1000], destination[100], phone_number[100], address[100], website[100], culture[100];
	FILE*fp5;

			printf ("\t\t\t **** Options: ****\n\n");
			printf ("\t 1: Touring services\n");
			printf ("\t 2: Restaurants\n");
			printf ("\t 3: Attractions\n");
			printf ("\t 4: Clubs\n");
			printf ("\t 5: Hotels\n");
			printf ("\t 6: Finished\n");
	
	printf("Enter the corresponding number of the file you are interested in updating\n");
	
	scanf("%d",&sec_options); //accepts from a user a number that allows them to update the file it corresponds with or to terminate program when ready
	
	while (1) //this module is repeated until the user instructs it to terminate where there are then taken back to main menu
	{
				
		if (sec_options == 1)
			{
				 //file containing all touring services is opened to be read from and appended
				 
				 fp5= fopen("C:\\Users\\dayna\\Documents\\Computer science\\files to c programs\\touring services.txt", "a+");
	
				if (fp5==NULL)
				{
					printf("Error: File does not exist.\nPlease create File\n\n.");
					exit(0);
				}
				
				else
				{
					printf("How many entries are you making?\n ");
    				scanf("%d", &amount);	//the user will instruct the program on the amount of entries needed to made
    				
					for(i = 0; i < amount; ++i) //the program will allow the user to make continuous entries until the amount they specified is reached 
    				{
						printf("Enter name with no spaces: ");
	        			scanf("%s", name);
	        			
						printf ("\n\n\t\t\t **** Destinations: ****\n\n");
						printf ("\t K&A       = Kingston & St.Andrew\n");
						printf ("\t POR       = Portland\n");
						printf ("\t ANN       = St.Ann\n");
						printf ("\t JAM       = St.James\n");
						printf ("\t MAR      = St.Mary\n");
						printf ("\t TRE       = Trelawny\n");
						printf ("\t WML       = Westmoreland\n");
   						
		   				printf("Enter destination: ");
	        			scanf("%s", destination);
	        			
	        			printf("Enter website: ");
				        scanf("%s", website);
				        
				        printf("Enter the phone number with no spaces: ");
				        scanf("%s", phone_number);
				        
				        printf("Enter the address with no spaces: ");
				        scanf("%s", address);
	        			
						printf ("Enter Esimated Minimum Price, Esimated Maximum Price & Rating");
						scanf ("%d %d %f", &min_price, &max_price, &sec_rating);
					 
						printf ("\n\n\t\t\t **** Types of Touring Services: ****\n\n");
						printf ("\t 1   = Bus and Minivan Tours\n");
						printf ("\t 2   = Cruises, Sailing and Water Tours\n");
						printf ("\t 3   = City Tours\n");
						printf ("\t 4   = Cultural and Theme Tours\n");
						printf ("\t 5   = Historical and Heritage tours\n");
						printf ("\t 6   = Literary, Art and Music Tours\n");
						printf ("\t 7   = 4WD, ATV and off road tours\n");
						printf ("\t 8   = Private Sightseeing Tours\n");
						printf ("\t 9   = Walking,Biking, mountain biking Tours\n");
						printf ("\t 10  = Western Caribbean Shore Excursions\n");
		
						printf("Enter the corresponding number for the type touring service: ");
				        scanf("%d", &types);
								
						fprintf(fp5, "%s\t %s\t %d\t %d\t %0.1f\t %d\t %s\t %s\t %s\n", name, destination, min_price, max_price, sec_rating, types, website, phone_number, address );
						
						//the name, parish of location, estimated minimum and maximum price, the service rating, type, website, phone number and address is printed to file
					}
    				fclose (fp5); //file is closed
				}
			}

		else if (sec_options == 2)
			{		
				//file containing all restaurants is opened to be read from and appended
				
				fp5= fopen("C:\\Users\\dayna\\Documents\\Computer science\\files to c programs\\restaurants.txt", "a+");
	
				if (fp5==NULL)
				{
					printf("Error: File does not exist.\nPlease create File\n\n.");
					exit(0);
				}
				
				else
				{
					printf("How many entries are you making?\n ");
    				scanf("%d", &amount);//the user will instruct the program on the amount of entries needed to made
    				
					for(i = 0; i < amount; ++i) //the program will allow the user to make continuous entries until the amount they specified is reached 
    				{
						printf("Enter name with no spaces: ");
	        			scanf("%s", name);
	        			
						printf ("\n\n\t\t\t **** Destinations: ****\n\n");
						printf ("\t K&A       = Kingston & St.Andrew\n");
						printf ("\t POR       = Portland\n");
						printf ("\t ANN       = St.Ann\n");
						printf ("\t JAM       = St.James\n");
						printf ("\t MAR      = St.Mary\n");
						printf ("\t TRE       = Trelawny\n");
						printf ("\t WML       = Westmoreland\n");
   						
		   				printf("Enter destination: ");
	        			scanf("%s", destination);
	        			
	        			printf("Enter website: ");
				        scanf("%s", website);
				        
				        printf("Enter the phone number with no spaces: ");
				        scanf("%s", phone_number);
				        
				        printf("Enter the address with no spaces: ");
				        scanf("%s", address);
	        			
						printf ("Enter Esimated Minimum Price, Esimated Maximum Price & Rating");
						scanf ("%d %d %f", &min_price, &max_price, &sec_rating);
	        			
        				printf ("\n\n\t\t\t **** Culture of Restaurant: ****\n\n");
						printf ("\t African\n");
						printf ("\t America\n");
						printf ("\t Chinese\n");
						printf ("\t French\n");
						printf ("\t Greek\n");
						printf ("\t Indian\n");
						printf ("\t Italian\n");
						printf ("\t Jamaica\n");
						printf ("\t Japan\n");
						printf ("\t Spanish\n");
						
						printf("Enter the culture of the restaurant: ");
				        scanf("%s", culture);
								
						fprintf(fp5, "%s\t %s\t %d\t %d\t %0.1f\t %s\t %s\t %s\t %s\n", name, destination, min_price, max_price, sec_rating, culture, website, phone_number, address );
    					
    					//the name, parish of location, estimated minimum and maximum price, the service rating, culture, website, phone number and address is printed to file
					}
    				fclose (fp5); //file is closed
				}
			}
			
		else if (sec_options == 3)
			{
				 //file containing all attractions is opened to be read from and appended
				 
				 fp5= fopen("C:\\Users\\dayna\\Documents\\Computer science\\files to c programs\\attractions.txt", "a+");
	
				if (fp5==NULL)
				{
					printf("Error: File does not exist.\nPlease create File\n\n.");
					exit(0);
				}
				
				else
				{
					printf("How many entries are you making?\n ");
    				scanf("%d", &amount);//the user will instruct the program on the amount of entries needed to made
    				
					for(i = 0; i < amount; ++i) //the program will allow the user to make continuous entries until the amount they specified is reached 
    				{
						printf("Enter name with no spaces: ");
	        			scanf("%s", name);
	        			
						printf ("\n\n\t\t\t **** Destinations: ****\n\n");
						printf ("\t K&A       = Kingston & St.Andrew\n");
						printf ("\t POR       = Portland\n");
						printf ("\t ANN       = St.Ann\n");
						printf ("\t JAM       = St.James\n");
						printf ("\t MAR      = St.Mary\n");
						printf ("\t TRE       = Trelawny\n");
						printf ("\t WML       = Westmoreland\n");
   						
		   				printf("Enter destination: ");
	        			scanf("%s", destination);
	        			
	        			printf("Enter website: ");
				        scanf("%s", website);
				        
				        printf("Enter the phone number with no spaces: ");
				        scanf("%s", phone_number);
				        
				        printf("Enter the address with no spaces: ");
				        scanf("%s", address);
	        			
						printf ("Enter Esimated Minimum Price, Esimated Maximum Price & Rating");
						scanf ("%d %d %f", &min_price, &max_price, &sec_rating);
					 
						printf ("\n\n\t\t\t **** Types of Attractions: ****\n\n");
						printf ("\t 1 = Art Galleries\n");
						printf ("\t 2 = Beaches, Marinas & Cruises\n");
						printf ("\t 3 = Hiking,Camping & Horseback riding\n");
						printf ("\t 4 = Museums\n");
						printf ("\t 5 = Nature & Wildlife\n");
						printf ("\t 6 = Shops & Malls\n");
						printf ("\t 7 = Spas\n");
						printf ("\t 8 = Water & Amusement Parks\n");
		
						printf("Enter the corresponding number for the type of attractions: ");
				        scanf("%d", &types);
								
						fprintf(fp5, "%s\t %s\t %d\t %d\t %0.1f\t %d\t %s\t %s\t %s\n", name, destination, min_price, max_price, sec_rating, types, website, phone_number, address );
    				
					//the name, parish of location, estimated minimum and maximum price, the service rating, type, website, phone number and address is printed to file
					}
    				fclose (fp5); //file is closed
				}
			}
			
		else if (sec_options == 4)
			{
				//file containing all clubs is opened to be read from and appended
				
				fp5= fopen("C:\\Users\\dayna\\Documents\\Computer science\\files to c programs\\clubs.txt", "a+");
	
				if (fp5==NULL)
				{
					printf("Error: File does not exist.\nPlease create File\n\n.");
					exit(0);
				}
				
				else
				{
					printf("How many entries are you making?\n ");
    				scanf("%d", &amount);//the user will instruct the program on the amount of entries needed to made
    				
					for(i = 0; i < amount; ++i) //the program will allow the user to make continuous entries until the amount they specified is reached 
    				{
						printf("Enter name with no spaces: ");
	        			scanf("%s", name);
	        			
						printf ("\n\n\t\t\t **** Destinations: ****\n\n");
						printf ("\t K&A       = Kingston & St.Andrew\n");
						printf ("\t POR       = Portland\n");
						printf ("\t ANN       = St.Ann\n");
						printf ("\t JAM       = St.James\n");
						printf ("\t MAR      = St.Mary\n");
						printf ("\t TRE       = Trelawny\n");
						printf ("\t WML       = Westmoreland\n");
   						
		   				printf("Enter destination: ");
	        			scanf("%s", destination);
	        			
	        			printf("Enter website: ");
				        scanf("%s", website);
				        
				        printf("Enter the phone number with no spaces: ");
				        scanf("%s", phone_number);
				        
				        printf("Enter the address with no spaces: ");
				        scanf("%s", address);
	        			
						printf ("Enter Esimated Minimum Price, Esimated Maximum Price & Rating");
						scanf ("%d %d %f", &min_price, &max_price, &sec_rating);
					 
						printf ("\n\n\t\t\t **** Criteria: ****\n\n");
						printf ("\t 1  	= Dance & Disco\n");
						printf ("\t 2  	= Good for couples\n");
						printf ("\t 3 	= Good for big groups\n");
						printf ("\t 4   = Serves food\n");
						printf ("\t 5   = Host parties\n");
		
						printf("Enter the corresponding number for the criteria of the club: ");
				        scanf("%d", &criteria);
				        
						fprintf(fp5, "%s\t %s\t %d\t %d\t %0.1f\t %d\t %s\t %s\t %s\n", name, destination, min_price, max_price, sec_rating, criteria, website, phone_number, address );
    				//the name, parish of location, estimated minimum and maximum price, the service rating, criteria, website, phone number and address is printed to file
					}
    				fclose (fp5); //file is closed
				}
			}
		else if (sec_options == 5)
			{
				//file containing all hotels is opened to be read from and appended
				
				fp5= fopen("C:\\Users\\dayna\\Documents\\Computer science\\files to c programs\\hotels.txt", "a+");
	
				if (fp5==NULL)
				{
					printf("Error: File does not exist.\nPlease create File\n\n.");
					exit(0);
				}
				
				else
				{
					printf("How many entries are you making?\n ");
    				scanf("%d", &amount);//the user will instruct the program on the amount of entries needed to made
    				
					for(i = 0; i < amount; ++i) //the program will allow the user to make continuous entries until the amount they specified is reached 
    				{
						printf("Enter name with no spaces: ");
	        			scanf("%s", name);
	        			
						printf ("\n\n\t\t\t **** Destinations: ****\n\n");
						printf ("\t K&A       = Kingston & St.Andrew\n");
						printf ("\t POR       = Portland\n");
						printf ("\t ANN       = St.Ann\n");
						printf ("\t JAM       = St.James\n");
						printf ("\t MAR      = St.Mary\n");
						printf ("\t TRE       = Trelawny\n");
						printf ("\t WML       = Westmoreland\n");
   						
		   				printf("Enter destination: ");
	        			scanf("%s", destination);
	        			
	        			printf("Enter website: ");
				        scanf("%s", website);
				        
				        printf("Enter the phone number with no spaces: ");
				        scanf("%s", phone_number);
				        
				        printf("Enter the address with no spaces: ");
				        scanf("%s", address);
	        			
						printf ("Enter the Esimated Minimum Price for one night, Esimated Maximum Price for one night & Rating");
						scanf ("%d %d %f", &min_price, &max_price, &sec_rating);
					 
						printf ("\n\n\t\t\t **** Fun things to Do: ****\n\n");
						printf ("\t 1 = Beach, Water skiing, scuba diving & Fishing\n");
						printf ("\t 2 = Games room\n");
						printf ("\t 3 = Golf course\n");
						printf ("\t 4 = Horse riding\n");
						printf ("\t 5 = Water & Amusement park close by\n");
						printf ("\t 6 = Playing and seeing see creatures\n");
						printf ("\t 7 = Sailing\n");
						printf ("\t 8 = Spa\n");
						printf ("\t 9 = Swimming pool, Water slides, Water skiing & Diving\n");
						
						
						printf("Enter the number that correspond with the fun thing you want to input.\n");
						scanf("%d", &fun);
						
						printf ("\n\n\t\t\t **** Services: ****\n\n");
						printf ("\t 1 = 24-Hour Front Desk\n");
						printf ("\t 2 = All meals included\n");
						printf ("\t 3 = Room service\n");
						
					
						printf("Enter the number that corresponds with the service you want to input.\n");
						scanf("%d", &services);
						
						printf ("\n\n\t\t\t **** Facilities: ****\n\n");
						printf ("\t 1  = Air conditioning\n");
						printf ("\t 2  = Bar/Lounge\n");
						printf ("\t 3  = Cable tv\n");
						printf ("\t 4  = Casino\n");
						printf ("\t 5  = Family rooms\n");
						printf ("\t 6  = Fitness centre\n");
						printf ("\t 7  = Free Wi-Fi\n");
						printf ("\t 8  = Landmarks\n");
						printf ("\t 9  = Parking\n");
						printf ("\t 10 = Pet Friendly\n");
						printf ("\t 11 = Bar/Lounge\n");
						printf ("\t 12 = Private pool\n");
						printf ("\t 13 = Restaurant\n");
						
					
						printf("Enter the number that correspond with the facility you want to input.");
						scanf("%d", &facilities);
						
						fprintf(fp5, "%s\t %s\t %d\t %d\t %0.1f\t %d\t %d\t %d\t%s\t %s\t %s\n", name, destination, min_price, max_price, sec_rating, fun, services, facilities, website, phone_number, address );
    				
					//the name, parish of location, estimated minimum and maximum price, the service rating, activity, service, facility, website, phone number and address is printed to file
					}
    				fclose (fp5); //file is closed
				}
			}
		else if (sec_options == 6)
			{
				break; //Make updates function is closed and user is take back to main menu or start of program
			}
			printf ("\t\t\t **** Options: ****\n\n");
			printf ("\t 1: Touring services\n");
			printf ("\t 2: Restaurants\n");
			printf ("\t 3: Attractions\n");
			printf ("\t 4: Clubs\n");
			printf ("\t 5: Hotels\n");
			printf ("\t 6: Finished\n");
	
	
			printf("Enter the corresponding number of the file you are interested in updating\n");
			
			scanf("%d", &sec_options);
	
	}
}
