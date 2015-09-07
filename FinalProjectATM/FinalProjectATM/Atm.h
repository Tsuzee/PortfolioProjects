//Atm Header File
//Darren Farr
//Final Project ATM
//MW 10:00

class Atm
{
public:
	//function prototypes
	Atm ();
	void welcomeMessage();
	bool gatherCardInfo();
	bool gatherPinInfo();
	char menu();
	void withdrawMenu();
	void withdrawChecking();
	void withdrawSaving();
	void depositMenu();
	void depositChecking();
	void depositSaving();
	void transferMenu();
	void transferToChecking();
	void transferToSaving();
	void balanceInquiry();
	void helpText();
	char errorCheck(const char []);
	double roundAmount(double);
	char errorCheckMenu(const char []);
	double errorCheckInput(double);
	const static int arraySize = 256;

private:
	//declare variables
	int pinCount;
	char choice;
	double checkingBalance;
	double savingBalance;
	double amount;
	char userChoice[arraySize];
	char inputAmount[arraySize];
};