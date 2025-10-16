#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
const int ROWS = 15, SEATS_PER_ROW = 30; //Global constants for rows and columns.

void showMenu();
void displaySeatingChart(char[][SEATS_PER_ROW]);
void sellTickets(char[][30], double[], double&, int&);
void displayStatistics(char[][30], double&, int&);
void inputRowPrices(double[]);//To input row prices.
void initializeSeatingChart(char[][30]);//To update seats in theater.
bool loadFromFile(char[][30], double[], double&, int&, string);
void saveToFile(char[][SEATS_PER_ROW], double[], double&, int&, string);
int main()
{
	char seating[ROWS][SEATS_PER_ROW];     
	double rowPrices[ROWS] = { 0 };       
	double totalRevenue = 0.0;           
	int seatsSold = 0;  

	string filename = "theater_data.txt";

	// Load data from file or initialize defaults
	if (!loadFromFile(seating, rowPrices, totalRevenue, seatsSold, filename)) {
		initializeSeatingChart(seating);
		inputRowPrices(rowPrices);
	}
	int choice;
	do {
		showMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			displaySeatingChart(seating);
			break;
		case 2:
			sellTickets(seating, rowPrices, totalRevenue, seatsSold);
			break;
		case 3:
			displayStatistics(seating, totalRevenue, seatsSold);
			break;
		case 4:
			saveToFile(seating, rowPrices, totalRevenue, seatsSold, filename);
			cout << "Data saved. Exiting program.\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 4);
	return 0;
}

//This fuction will bring previous record if file is open otherwise it will create a file and store entered data in it.
bool loadFromFile(char seating[][SEATS_PER_ROW], double rowPrices[], double& totalRevenue, int& seatsSold, string filename)
{
	fstream load(filename);
	if (!load)  // if there is no file then it will create.
	{
		cout << setw(10) << "\nfile not found .Creating new file " << endl;
		return false;
	}
	else        //if file exists then it will display saved previous contents. 
	{
		ifstream load(filename);//To load existing data in a file.
		for (int i = 0; i < ROWS; i++)
		{
			load >> rowPrices[i];
			cout << setw(10) << "Price of row " << i + 1 << " :" << setw(8) << rowPrices[i] << endl;
		}

		cout << endl;  // for formatted output.
		
		cout << "                                        SEATING CHART " << endl; //for heading on                                                                             chart.
		
		cout << endl; // for formatted output.


		for (int i = -1;i < 30;i++) // I added separate loop for column identification.
		{
			if (i == -1)
			{
				cout << setw(11);
			}
			else if (i <= 9)
			{
				cout << i << "  ";
			}
			else if (i > 9 && i < 20)
			{
				cout << i - 10 << "  ";
			}
			else
				cout << i - 20 << "  ";
		}


		cout << "\n";


		for (int i = 0; i < ROWS; i++)
		{
			for (int j = -1; j < SEATS_PER_ROW; j++) //this will save chart which shows # available                                           seats and * seats sold out in a file.
			{
				if (j != -1) // index -1 contains row id.
				{
					load >> seating[i][j];
				}
				if (j == -1 && i <= 9)  //for proper alignment of rows id in chart.
				{
					cout << "ROW " << i  << "     ";
				}
				else if (i > 9 && j == -1)
				{
					cout << "ROW" << i  << "     ";
				}
				else
				{
					cout << seating[i][j] << "  ";  // display seating chart saved previously in file
				}
			}
			cout << endl;
		}
		cout << endl;

		//display total revenue generated and no. of seats sold out.
		load >> totalRevenue; cout << "\tTotal revenue generated is : " << totalRevenue << endl;
		load >> seatsSold; cout << "\tTotal seats sold are : " << seatsSold << endl;

		load.close();  // file named load will be closed. 
		return true;
	}
}


//This function will set chart to initial stage .
void initializeSeatingChart(char seating[][SEATS_PER_ROW])
{
	cout << "                                        SEATING CHART " << endl; //for heading on                                                                                 chart.
	cout << endl;

	for (int i = -1; i < 30; i++) //loop for adjustment of seats numbers.
	{
		if (i == -1)
		{
			cout << setw(11);
		}
		else if (i >= 0 && i <= 9)
		{
			cout << i << "  ";
		}
		else if (i >= 10 && i < 20)
		{
			cout << i - 10 << "  ";
		}
		else
			cout << i - 20 << "  ";
	}
	cout << endl;


	for (int i = 0; i < ROWS; i++)
	{
		for (int j = -1; j < SEATS_PER_ROW; j++)
		{
			if (j == -1 && i <= 9)  //for proper alignment of rows in chart.
			{
				cout << "ROW " << i << "     ";
			}
			else if (i > 9 && j == -1)
			{
				cout << "ROW" << i << "     ";
			}
			else
			{
				seating[i][j] = '#';              // # represent available seat.
				                             //this 2D array will display available seats in chart
				cout << seating[i][j] << "  ";
			}

		}
		cout << endl;
	}
}


//This function will take input of prices.
void inputRowPrices(double rowPrices[])
{
	cout << "\n\n\tEnter price for each row : \n";
	for (int i = 0; i < ROWS; i++)
	{
		do {
			cout << "\tROW " << i << ":  ";
			cin >> rowPrices[i];  //store prices in rowprice array.
			if (rowPrices[i] < 0)
			{
				cout << "\tYOU cannot enter negative value \n.";
			}
		} while (rowPrices[i] < 0);
	}
}


void showMenu() //To show menu for selection.
{
	cout << "\n\tWhich service do you want to opt : \n\t 1. Display the current seating chart. \n\t 2. Sell tickets. \n\t 3. View total sales and seating statistics. \n\t 4. Save current data and exit the program. \n";
}



//To display seats in theater.
void displaySeatingChart(char seating[][SEATS_PER_ROW]) //this will update seating chart according to user reserved seats.  
{
	//THERE ARE 15 ROWS STARTING FROM 1 TO 15 AND EACH ROW HAS 30 COLUMNS (SEATS) FROM 0 TO 9.

	for (int i = -1; i < 30; i++) // I added separate loop for column identification.
	{
		if (i == -1)
		{
			cout << setw(11);
		}
		else if (i >= 0 && i <= 9)
		{
			cout << i << "  ";
		}
		else if (i >= 10 && i < 20)
		{
			cout << i - 10 << "  ";
		}
		else
			cout << i - 20 << "  ";
	}


	cout << endl;


	for (int i = 0; i < ROWS; i++)
	{
		for (int j = -1; j < SEATS_PER_ROW; j++)
		{
			if (j == -1 && i <= 9)  //for proper alignment of rows in chart.
			{
				cout << "ROW " << i  << "     ";
			}
			else if (i > 9 && j == -1)
			{
				cout << "ROW" << i << "     ";
			}
			else
			{
				cout << seating[i][j] << "  ";  //display seats available and sold out.If user buys a                                seat then seating 2d array related index character                                 # will change into *.
			}
		}
		cout << endl;
	}
	cout << endl;
}



//This function will let user to choose seat and calculate revenue,seats Sold and update seating chart.
void sellTickets(char seating[][SEATS_PER_ROW], double rowPrices[], double& totalRevenue, int& seatsSold)
{
	int r, c;
	do {
		cout << "\n\nEnter row number for seat : ";
		cin >> r;
		cout << "Enter seat number in row " << r << "  ";
		cin >> c;
		if (seating[r][c] == '*')
		{
			cout << "This seat is already sold out \n";
		}
		else if (r > 15 || c > 30 || r < 0 || c < 0)                //validation for correct row and column number.
		{
			cout << "invalid number. Re-enter number";
		}
	} while (seating[r][c] == '*' || r > 15 || c > 30 || r < 0 || c < 0 );  //  * will show sold seats.
	                                                    // this do while loop will validate input if                             second person enters reserved seat then he will 
	                                      // get message of sold out and ask him to enter other seat.

	seating[r][c] = '*';                  //this will convert # into * according to seat reserved

	seatsSold++;                            // this will count sold seats.

	totalRevenue += rowPrices[r];       //this will catculate total revenue from selected seats.
}




//This function will display expenses list.
void displayStatistics(char seating[][SEATS_PER_ROW], double& totalRevenue, int& seatsSold)
{
	cout << "\n\n\tTotal revenue generated from tcket sales is : " << totalRevenue << endl;
	cout << "\tTotal number of seats sold are : " << seatsSold << endl;
	cout << "\tNumber of available seats for each row is : \n";
	int count;                   //this will count seats sold.
	for (int i = 0; i < ROWS; i++)
	{
		count = 0;
		cout << "\tROW " << i << setw(8)<< ":";
		for (int j = 0; j < SEATS_PER_ROW; j++)
		{
			if (seating[i][j] == '*') // if seat sold then count + 1
				count++;
		}
		cout << SEATS_PER_ROW - count << endl;  // gives available seats
	}
	cout << "\n\ttotal number of available seats in the theater : ";
	count = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < SEATS_PER_ROW; j++)
		{
			if (seating[i][j] == '*')
				count++;
		}// TOTAL AVAILABLE SEATS OBTAINED BY SUBTRACTING TOTAL SEATS TO SEATS SOLD OUT.
	}
	cout << SEATS_PER_ROW * ROWS - count << endl;

}



//this function will save previous sales and its related records in a file.
void saveToFile(char seating[][SEATS_PER_ROW], double rowPrices[], double& totalRevenue, int& seatsSold, string filename)         // & used to get value of variables by reference.
{
	ofstream load(filename);         //To load existing data in a file.

	for (int i = 0; i < ROWS; i++)
	{
		load << rowPrices[i] << endl;
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < SEATS_PER_ROW; j++) //this will save chart which shows # available seats                                         and * seats sold out in a file.
		{
			load << seating[i][j];
		}
		load << endl;
	}
	load << totalRevenue << endl; //this will save revenue and number of sold seats.
	load << seatsSold;
	load.close(); // closes file named load.
}
