#include <iostream>
#include <conio.h>


//Checking invalid user input
int getValue()
{
	while (true) // The loop continues until the user enters the correct value
	{
		std::cout << "Enter an integer value: ";
		int a;
		std::cin >> a;
		// Checking for a previous checkout
		if (std::cin.fail()) // If the previous extraction failed,
		{
			std::cin.clear(); // then we return cin to 'normal' operation
			std::cin.ignore(32767, '\n'); // and remove the values ​​of the previous input from the input buffer
			std::cout << "Oops, that input is invalid. Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n'); // Remove unnecessary values
			return a;
		}
	}
}

int main(int argc, char** argv)
{
	using namespace std;

	int M1 = 0;	
	int M2 = 0;
	int S1 = 0;
	int S2 = 0;	
	do
	{
		system("cls");
		cout << "Enter the number of rows\nfor the first matrix: ";
		cin >> M1;
		cout << "Enter the number of columns\nfor the first matrix: ";
		cin >> M2;
		cout << "Enter the number of rows\nfor the second matrix: ";
		cin >> S1;
		cout << "Enter the number of columns\nfor the second matrix: ";
		cin >> S2;
		if(M2 != S1)
		{
			system("cls");
			cout << "The number of columns in the first matrix\nmust match the number of rows in the second matrix.\nTry again.";
			_getch();
		}
			
	} while (M2 != S1);
	
	// Сreating the first matrix : arr
	int** arr = new int* [M1]; 	

	for (int i(0); i < M1; i++)
	{
		arr[i] = new int[M2];
	}

	system("cls");
	// First matrix initialization
	for (int i(0); i < M1; i++)
	{
		for (int j(0); j < M2; j++)
		{
			arr[i][j] = 0;
		}
	}

	for (int i(0); i < M1; i++)
	{
		for (int j(0); j < M2; j++)
		{
			
			cout << "Enter the value in the [" << i << "] row of the [" << j << "] column for the first matrix.\n";
			
			for (int i(0); i < M1; i++)
			{
				for (int j(0); j < M2; j++)
				{
					cout <<"[" << arr[i][j] <<"]" << " ";
				}
				cout << endl;
			}
			arr[i][j] = getValue();
			system("cls");
		}
	}

	// Сreating the second matrix : brr
	int** brr = new int* [S1]; 

	for (int i(0); i < S1; i++)
	{
		brr[i] = new int[S2];

	}
	// Second matrix initialization
	for (int i(0); i < S1; i++)
	{
		for (int j(0); j < S2; j++)
		{
			brr[i][j] = 0;
		}
	}
	for (int i(0); i < S1; i++)
	{
		for (int j(0); j < S2; j++)
		{
			cout << "Enter the value in the [" << i << "] row of the [" << j << "] column for the second matrix.\n";
			
			for (int i(0); i < S1; i++)
			{
				for (int j(0); j < S2; j++)
				{
					cout << "[" << brr[i][j] << "]" << " ";
				}
				cout << endl;
			}
			brr[i][j] = getValue();
			system("cls");
		}
	}

	// Сreating the third matrix : crr
	int** crr = new int* [M1];

	for (int i(0); i < M1; i++)
	{
		crr[i] = new int[S2];
	}

	//Third matrix initialization
	for (int i(0); i < M1; i++)
	{
		for (int j(0); j < S2; j++)
		{
			crr[i][j] = 0;
		}
	}
	for (int i(0); i < M1; i++)
	{
		for (int j(0); j < M2; j++)
		{
			cout << "[" << arr[i][j] << "]" << " ";
		}
		cout << endl;
	}


	cout << "*";
	cout << endl;

	for (int i(0); i < S1; i++)
	{
		for (int j(0); j < S2; j++)
		{
			cout << "[" << brr[i][j] << "]" << " ";
		}
		cout << endl;
	}

	
	cout << "=";
	cout << endl;

	//Matrix multiplication

	for (int i(0); i < M1; i++)
	{
		for (int j(0); j < S2; j++)
		{
			for (int m(0); m < M2; m++)
			{
				crr[i][j] = crr[i][j] + (arr[i][m] * brr[m][j]);
			}
			cout << "[" << crr[i][j] << "]" << " ";
		}
		cout << endl;
	}



	
	// Deleting matrix
	for (int i(0); i < M1; i++)
	{
		delete[] crr[i];
	}

	delete[] crr;
	
	for (int i(0); i < S1; i++)
	{
		delete[] brr[i];
	}

	delete[]brr;

	for (int i(0); i < M1; i++)
	{
		delete[] arr[i];
	}

	delete[]arr;
	
	_getch();
	return 0;
}