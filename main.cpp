#include <iostream>
#include <windows.h> //windows ������� include
#include <cstdlib> //rand()
#include <ctime>	//time()


using namespace std;	


char Input();
bool Process(char Key);
void Draw();
void Initialize();
void Terminate();

void CustomInitialze();
void CustomTerminate();
void CustomProcess();
void CustomDraw();

void ProcessBingo();


void InitializeBingoPlayerMap();

int Gold = 0;

int BingoPlayerMap[9];



int main()
{
	bool bGameState = true;
	Initialize();

	while (bGameState)
	{
		char Key = Input();
		bGameState = Process(Key);
		Draw();
	}
	Terminate();

	return 0;
}



char Input()
{
	char Key;

	cin >> Key;

	return Key;
}

bool Process(char Key)
{
	if (Key == 'q' || Key == 'Q')
	{
		return false;
	}

	CustomProcess();

	return true;
}

void Draw()
{
	//		system("cls");
	cout << "�׸���." << endl;

	CustomDraw();
}

void Initialize()
{
	//�ʱ�ȭ
	CustomInitialze();
}

void Terminate()
{
	CustomTerminate();
	//����
}




void CustomInitialze()
{
	InitializeBingoPlayerMap();
}

void CustomTerminate()
{
}

void CustomProcess()
{
	ProcessBingo();
}

void CustomDraw()
{
}

void ProcessBingo()
{
}

void InitializeBingoPlayerMap()
{
	for (int i = 0; i < 9; ++i)
	{
		BingoPlayerMap[i] = i + 1;
	}

	srand(static_cast<unsigned int>(time(nullptr)));

	//Shuffle
	for (int i = 0; i < 100; i++)
	{
		//rand
		int Index1 = rand() % 9;
		int Index2 = rand() % 9;

		int Temp = BingoPlayerMap[Index1];
		BingoPlayerMap[Index1] = BingoPlayerMap[Index2];
		BingoPlayerMap[Index2] = Temp;
	}
}
