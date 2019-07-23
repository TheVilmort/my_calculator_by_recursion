#include"Header.h"
using namespace std;
static double value;
double Calculator(double first_value, char action, double second_value)
{
	char new_action;
	double new_second_value;
	char answer;
	double reserv;
	switch (action)
	{
	case'+':
		value = first_value + second_value;
		break;
	case'-':
		value = first_value - second_value;
		break;
	case'*':
		value = first_value * second_value;
		break;
	case'/':
		
		try 
		{
			reserv = value;
			value = first_value / second_value;
			if (second_value == 0)
			{
				throw static_cast<string>("Division by zero!Try again!");
			}
		}
		catch (string ex)
		{
			cout <<"Eror:"<< ex << "\n";
			value = reserv;
		}
		break;
	case'^':
		value = pow(first_value, second_value);
		break;
	//case '√':
	default:
		cout << "You have entered an incorrect action!Try again!" << "\n";
		break;
	}
	cout << "Result: " << value;
	cout << "\n" << "Press \"Y\" to continue to take action on this number: ";
	cin >> answer;
	if (answer == 'Y' || answer == 'y')
	{
		cout << value;
		cin >> new_action >> new_second_value;
		Calculator(value, new_action, new_second_value);
	}
	

	return value;
}
int main()
{
	setlocale(LC_ALL,"Rus");
	cout << "———> Calculator <———" << "\n";
	double first_value;
	char action;
	double second_value;

	cin >> first_value >> action >> second_value;

	Calculator(first_value, action, second_value);
}
