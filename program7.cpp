#include <fstream> //allows use of IO stream classes
#include <iostream> //allows use of cout and cin
#include <iomanip> //allows program to manipulate formatting of I/O S
#include <cstdlib> //allows program to use exit fxn
using namespace std;

//GLOBAL DECLARATIONS
const int WEATHER_STATIONS = 20, MONTHS_DATA = 12;
double cutoff;
int continueMenu = 0;
ifstream rainfallInput;

//FUNCTION DECLARATIONS
void fill_array(double rainfall[][MONTHS_DATA]);
void format_array(double rainfall[][MONTHS_DATA]);
void display_menu(int& continueMenu);

void calculate_years_more(double rainfall[][MONTHS_DATA], int stations, double& cutoff);
void display_years_more(double rainfall[][MONTHS_DATA], int stations, double cutoff);

void calculate_years_less(double rainfall[][MONTHS_DATA], int stations, double& cutoff);
void display_years_less(double rainfall[][MONTHS_DATA], int stations, double cutoff);

void calculate_months_more(double rainfall[][MONTHS_DATA], int stations, double& cutoff);
void display_months_more(double rainfall[][MONTHS_DATA], int stations, double cutoff);

void calculate_months_less(double rainfall[][MONTHS_DATA], int stations, double& cutoff);
void display_months_less(double rainfall[][MONTHS_DATA], int stations, double cutoff);

//MAIN
int main()
{
	//VARIABLE DECLARATIONS
	double rainfall[WEATHER_STATIONS][MONTHS_DATA];
	
	//CONNECT INPUT STREAM TO INPUT FILE
	rainfallInput.open("rainfall.dat");
		if (rainfallInput.fail())
			{
				cout << "Input file 'rainfall.dat' failed to open";
				exit(1);
			}
	//INTIALIZE ARRAY WITH INPUT FILE 
	fill_array(rainfall);
	format_array(rainfall);
	
	while(continueMenu == 0)
	{
		display_menu(continueMenu);
		if (continueMenu == 1)
		{
			calculate_years_more(rainfall, WEATHER_STATIONS, cutoff);
			display_years_more(rainfall, WEATHER_STATIONS, cutoff); //NEED TO DECLARE THESE PARAMETERS STILL!!!!!!
			continueMenu = 0;
		}
		else if (continueMenu == 2)
		{
			calculate_years_less(rainfall, WEATHER_STATIONS, cutoff);
			display_years_less(rainfall, WEATHER_STATIONS, cutoff); //NO brackets when calling an array!
			continueMenu = 0;
		}
		else if (continueMenu == 3)
		{
			calculate_months_more(rainfall, WEATHER_STATIONS, cutoff);
			display_months_more(rainfall, WEATHER_STATIONS, cutoff);
			continueMenu = 0;
		}
		else if (continueMenu == 4)
		{
			calculate_months_less(rainfall, WEATHER_STATIONS, cutoff);
			display_months_less(rainfall, WEATHER_STATIONS, cutoff);
			continueMenu = 0;
		}
		else if (continueMenu == 5)
		{
			rainfallInput.close();
			exit(0);
		}
		else
		{
			continueMenu = 0;
		}
	}
	
rainfallInput.close();

return 0;
}

//FUNCTION DEFINITIONS
void fill_array(double rainfall[][MONTHS_DATA])
{
int a, b;
	for (a = 0; a < WEATHER_STATIONS; a++)
	{
		for (b = 0; b < MONTHS_DATA + 1; b++)
		{
			rainfallInput >> rainfall[a][b]; //board[i][j] = input(); retreived from http://www.cplusplus.com/forum/beginner/42045/
			//cout << rainfall[a][b] << " ";  //NEED TO USE A FOR LOOP TO INITIALIZEEEEEE
		}
		//cout << endl;
	}
//convert row b only to inches, row a gets a label and also becomes an int w no decimal pts
}
void format_array(double rainfall[][MONTHS_DATA])
{
int a,b,c;
	for (a = 0; a < WEATHER_STATIONS + 1; a++) //printing the row or weather station number
	{
		cout << "WS " << a + 1 << ": ";
		for (b = 0; b < WEATHER_STATIONS + 1; b++)
		{
			std::cout <<
			std::fixed <<
			std::setprecision(2);

			c = rainfall[a][b]/25.4; //converts the milimeter rainfall data to inches
			cout << rainfall[a][c] << " ";  //NEED TO USE A FOR LOOP TO INITIALIZEEEEEE
		}
		cout << endl;
	}
}

void display_menu(int& continueMenu)
{
	cout << "Rainfall data to display:" << endl
		 << "1. Weather stations with total rainfall for year MORE than a cutoff" << endl
		 << "2. Weather stations with total rainfall for year LESS than a cutoff" << endl
		 << "3. Rainfall for a month MORE than a cutoff" << endl
		 << "4. Rainfall for a month LESS than a cutoff" << endl
		 << "5. Quit" << endl
		 << "Enter a number of your choice: " << endl;
	 cin >> continueMenu;
}


void calculate_years_more(double rainfall[][MONTHS_DATA], int stations, double& cutoff)
{
	cout << "Enter the rainfall for which to find years with more rain: ";
	cin >> cutoff;
	
	//calculate and convert to inches
}
void display_years_more(double rainfall[][MONTHS_DATA], int stations, double cutoff)
{
	//needs to calculate average first
	
	/*int i, j;
	for (i = 0; i < WEATHER_STATIONS; i++)
	{
		for (j = 0; j < MONTHS_DATA; j++) 
		{
			if (rainfall[i][j] > cutoff)
				cout << rainfall[i][j];	
		}
		cout << endl;
	}*/
}

void calculate_years_less(double rainfall[][MONTHS_DATA], int stations, double& cutoff)
{
	cout << "Enter the rainfall for which to find years with more rain: ";
	cin >> cutoff;
	
	//calculate and convert to inches
}
void display_years_less(double rainfall[][MONTHS_DATA], int stations, double cutoff)
{
	
}


void calculate_months_more(double rainfall[][MONTHS_DATA], int stations, double& cutoff)
{
	cout << "Enter the rainfall for which to find years with more rain: ";
	cin >> cutoff;
	
	//calculate and convert to inches
}
void display_months_more(double rainfall[][MONTHS_DATA], int stations, double cutoff)
{
	
}


void calculate_months_less(double rainfall[][MONTHS_DATA], int stations, double& cutoff)
{
	cout << "Enter the rainfall for which to find years with more rain: ";
	cin >> cutoff;
	
	//calculate and convert to inches
}
void display_months_less(double rainfall[][MONTHS_DATA], int stations, double cutoff)
{

}
