#include <iostream>
#include<fstream>
#include <string>
int menu();
void consolio(int a);
void fileio(int a);
using namespace std;
int** matrix1, ** matrix2, ** matrix3;
bool in1, in2;
short v1, v2;



int main()
{
	setlocale(LC_ALL, "ru");
	while (true)
	{
		int a = menu();

		if (a == 0)
			break;
		if (a == 1)
		{
			cout << "====================================================" << "\n";
			cout << "1. ������ ������� �" << endl << "2. ������ ������� �" << endl << "3. ������ ��� �������" << "\n" <<
				"4. ������� �� ����� ������� �" << "\n" << "5. ������� �� ����� ������� �" << "\n";
			cout << "====================================================" << "\n";
			cin >> a;
			cout << endl;
			consolio(a);
			a = 10;
		}
		if (a == 2)
		{
			cout << "====================================================" << "\n";
			cout << "1. ��������� ������� �" << endl << "2. ��������� ������� �" << endl << "3. ��������� ��� �������" << "\n"
				<< "4. ��������� ������� � � ����" << "\n" << "5. ��������� ������� � � ����" << "\n";
			cout << "====================================================" << "\n";
			cin >> a;
			cout << "\n";
			fileio(a);
			a = 10;
		}
		if (a == 3)
		{
			cout << "1.�������������� ������� �" << "\n" << "2. �������������� ������� �" << "\n";
		}
	}
	cout << "��������� ��������� ������..." << "\n";
	delete[]matrix1;
	delete[]matrix2;
	delete[]matrix3;
}
int menu()
{
	int n;
	cout << "====================================================" << "\n";
	cout << "\t" << "\t" << "����" << "\n"
		<< "\t" << "1.���������� ����/�����" << "\n"
		<< "\t" << "2.�������� ����/�����" << "\n"
		<< "\t" << "3.������������� �������" << "\n"
		<< "\t" << "4.������������ ������" << "\n"
		<< "\t" << "0.������� ���������" << "\n";
	cout << "====================================================" << "\n";
	cin >> n;
	cout << "\n";
	return n;
}
void consolio(int a)                                                            //���������� ���� �����
{

	int i, j;
	if ((a == 1) || (a == 3)) //���� ������ ������
	{
		delete[]matrix1;
		cout << "������� �" << "\n" << "������� ������ ���������� �������: ";
		cin >> v1;
		cout << "\n";
		matrix1 = new int* [v1];
		for (i = 0; i < v1; i++)
			matrix1[i] = new int[v1];
		for (i = 0; i < v1; i++)
			for (j = 0; j < v1; j++)
			{
				cout << "������� " << i + 1 << " " << j + 1 << " ������� �������: ";
				cin >> matrix1[i][j];
			}
		in1 = true;
	}

	if (((a == 1) || (a == 3) || (a == 4)) && (in1 == true)) //����� ������ �������
	{
		cout << "���� ������� �: " << "\n";
		for (i = 0; i < v1; i++)
		{
			for (j = 0; j < v1; j++)
			{
				cout << matrix1[i][j] << " ";
			}
			cout << "\n";
		}
	}
	if ((a == 4) && (in1 == false)) //���� �������� ����� ������ �������, �� ��� �� �������
	{
		cout << "��� ������ ������� ������� �" << "\n";
	}

	if ((a == 2) || (a == 3)) //���� ������ ������
	{
		delete[]matrix2;
		cout << "������� �" << "\n" << "������� ������ ���������� �������: ";
		cin >> v2;
		cout << "\n";
		matrix2 = new int* [v2];
		for (i = 0; i < v2; i++)
			matrix2[i] = new int[v2];
		for (i = 0; i < v2; i++)
			for (j = 0; j < v2; j++)
			{
				cout << "������� " << i + 1 << " " << j + 1 << " ������� �������: ";
				cin >> matrix2[i][j];
			}
		in2 = true;
	}

	if (((a == 2) || (a == 3) || (a == 5)) && (in2 == true)) //����� ������ �������
	{
		cout << "���� ������� �: " << "\n";
		for (i = 0; i < v2; i++)
		{
			for (j = 0; j < v2; j++)
			{
				cout << matrix2[i][j] << " ";
			}
			cout << "\n";
		}
	}
	if ((a == 5) && (in2 == false)) //���� �������� ����� ������ �������, �� ��� �� �������
	{
		cout << "��� ������ ������� ������� �" << "\n";
	}
	cout << "\n";
}
void fileio(int a)
{
	int i, j;
	string locate;
	if ((a == 1) || (a == 3))                        //�������� ������ � �� �����
	{
		delete[]matrix1;
		cout << "��������� ������� �" << "\n";
		cout << "������� ���� �� �����: ";
		cin >> locate;
		cout << "\n";
		ifstream fmatrix1;
		fmatrix1.open(locate);
		if (fmatrix1.is_open())
		{
			int n = 0, tmp;
			cout << "���� ������� ������" << "\n" << "\n";
			while (!fmatrix1.eof())
			{
				fmatrix1 >> tmp;
				n += 1;
			}
			v1 = n / n;
			fmatrix1.seekg(0, ios::beg);
			cout << "��������� ������� � " << v1 << " x " << v1 << ":" << endl;
			matrix1 = new int* [v1];
			for (i = 0; i < v1; i++)
				matrix1[i] = new int[n];
			for (i = 0; i < v1; i++)
				for (j = 0; j < v1; j++)
				{
					fmatrix1 >> matrix1[i][j];
				}

			for (i = 0; i < v1; i++)
			{
				for (j = 0; j < v1; j++)
				{
					cout << matrix1[i][j] << " ";
				}
				cout << "\n";
			}
		}
		else
		{
			cout << "Open file error" << "\n";
		}
		fmatrix1.close();
		in1 = true;
	}

	if ((a == 2) || (a == 3))                            //�������� ������� � �� �����
	{
		delete[]matrix2;
		cout << "��������� ������� �" << "\n";
		cout << "������� ���� �� �����: ";
		cin >> locate;
		cout << "\n";
		ifstream fmatrix2;
		fmatrix2.open(locate);
		if (fmatrix2.is_open())
		{
			int n = 0, tmp;
			cout << "���� ������� ������" << "\n" << "\n";
			while (!fmatrix2.eof())
			{
				fmatrix2 >> tmp;
				n += 1;
			}
			v2 = n / n;
			fmatrix2.seekg(0, ios::beg);
			cout << "��������� ������� � " << v2 << " x " << v2 << ":" << endl;
			matrix2 = new int* [v2];
			for (i = 0; i < v2; i++)
				matrix2[i] = new int[n];
			for (i = 0; i < v2; i++)
				for (j = 0; j < v2; j++)
				{
					fmatrix2 >> matrix2[i][j];
				}

			for (i = 0; i < v2; i++)
			{
				for (j = 0; j < v2; j++)
				{
					cout << matrix2[i][j] << " ";
				}
				cout << "\n";
			}
		}
		else
		{
			cout << "Open file error" << "\n";
		}
		fmatrix2.close();
		in2 = true;
	}
	if ((a == 4) && (in1 == true))                           //����� ������ � � ����
	{
		cout << "����� ������� �" << "\n";
		cout << "������� ���� �� �����: ";
		cin >> locate;
		cout << "\n";
		ofstream fmatrix1;
		fmatrix1.open(locate, ios_base::app);
		if (fmatrix1.is_open())
		{
			for (i = 0; i < v1; i++)
			{
				for (j = 0; j < v1; j++)
				{
					fmatrix1 << matrix1[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
			cout << "����� �������� �������" << "\n";
			cout << "\n";
		}
		fmatrix1.close();
	}
	if ((a == 4) && (in1 == false))                           //������, ���� �� ������� ������� �
	{
		cout << "��� ������ ������� ������� �" << "\n";
	}

	if ((a == 5) && (in2 == true))                           //����� ������� � � ����
	{
		cout << "����� ������� �" << "\n";
		cout << "������� ���� �� �����: ";
		cin >> locate;
		cout << "\n";
		ofstream fmatrix2;
		fmatrix2.open(locate, ios_base::app);
		if (fmatrix2.is_open())
		{
			for (i = 0; i < v2; i++)
			{
				for (j = 0; j < v2; j++)
				{
					fmatrix2 << matrix2[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
			cout << "����� �������� �������" << "\n";
			cout << "\n";
		}
		fmatrix2.close();
	}
	if ((a == 5) && (in2 == false))                           //������, ���� �� ������� ������� �
	{
		cout << "��� ������ ������� ������� �" << "\n";
	}
	cout << "\n";
}
