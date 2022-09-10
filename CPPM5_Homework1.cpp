#include <iostream>
#include <fstream>

int* readArray(std::ifstream& fin, int& itemCount)
{

	if (!(fin >> itemCount)) {
		// не удалось считать количество элементов
		return nullptr;
	}

	int* arr = new int[itemCount]();

	int item;
	int i = 0;
	while (i < itemCount && fin >> item) {
		arr[i++] = item;
	}

	// не удалось считать все нужные элементы
	if (i < itemCount)
	{
		delete[] arr;
		arr = nullptr;
	}

	return arr;
}

void safeFreeArray(int* arr)
{
	if (arr)
	{
		delete[] arr;
	}
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
		std::cout << "Не удалось открыть файл '" + inputFileName + "'";
		return 1;
	}

	int size1 = 0, size2 = 0;
	int* arr1 = nullptr;
	int* arr2 = nullptr;

	arr1 = readArray(fin, size1);
	if (arr1)
	{
		arr2 = readArray(fin, size2);
	}

	if (!arr1)
	{
		std::cout << "Не удалось считать данные первого массива из файла '" + inputFileName + "'" << std::endl;
	}
	else
	if (!arr2)
	{
		std::cout << "Не удалось считать данные второго массива из файла '" + inputFileName + "'" << std::endl;
	}

	fin.close();

	if (arr1 && arr2)
	{
		std::cout << "Прочитаны данные из файла '" + inputFileName + "'" << std::endl;

		std::ofstream fout(outputFileName);

		if (fout.is_open())
		{
			arraySpecialPrint(fout, arr2, size2, size2 - 1);
			arraySpecialPrint(fout, arr1, size1, 1);

			std::cout << "Записан файл '" + inputFileName + "'" << std::endl;

			fout.close();
		}
		else
		{
			std::cout << "Не удалось открыть для записи файл '" + outputFileName + "'" << std::endl;
		}
	}

	safeFreeArray(arr1);
	safeFreeArray(arr2);
	
	return 0;
}
