#include <iostream>
#include <fstream>

int* readArray(std::ifstream& fin, int& itemCount)
{

	if (!(fin >> itemCount)) {
		// �� ������� ������� ���������� ���������
		return nullptr;
	}

	int* arr = new int[itemCount]();

	int item;
	int i = 0;
	while (i < itemCount && fin >> item) {
		arr[i++] = item;
	}

	// �� ������� ������� ��� ������ ��������
	if (i < itemCount)
	{
		delete[] arr;
		arr = nullptr;
	}

	return arr;
}

void arraySpecialPrint(std::ofstream& fout, int* arr, int size, int startIndex)
{
	fout << size << std::endl;

	for (int i = 0; i < size; ++i)
	{
		fout << arr[(startIndex + i) % size] << " ";
	}

	fout << std::endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	std::string inputFileName = "in.txt";
	std::string outputFileName = "out.txt";
	std::ifstream fin(inputFileName);

	if (!fin.is_open())
	{
		std::cout << "�� ������� ������� ���� '" + inputFileName + "'";
		return 1;
	}

	int size1, size2;
	int* arr1 = readArray(fin, size1);
	if (!arr1)
	{
		std::cout << "�� ������� ������� ������ ������� ������� �� ����� '" + inputFileName + "'" << std::endl;
		fin.close();
		return 2;
	}

	int* arr2 = readArray(fin, size2);
	if (!arr2)
	{
		std::cout << "�� ������� ������� ������ ������� ������� �� ����� '" + inputFileName + "'" << std::endl;
		fin.close();
		return 2;
	}

	fin.close();

	std::cout << "��������� ������ �� ����� '" + inputFileName + "'" << std::endl;

	std::ofstream fout(outputFileName);

	if (!fout.is_open())
	{
		std::cout << "�� ������� ������� ��� ������ ���� '" + outputFileName + "'" << std::endl;
		return 3;
	}

	arraySpecialPrint(fout, arr2, size2, size2 - 1);
	arraySpecialPrint(fout, arr1, size1, 1);

	std::cout << "������� ���� '" + inputFileName + "'" << std::endl;

	fout.close();

	return 0;
}
