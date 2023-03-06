#include <iostream>

using namespace std;

/// <summary>
/// Заменяет указанный символ на другой
/// </summary>
/// <param name="str">Исходная строка</param>
/// <param name="symbol">Символ для замены</param>
/// <param name="value">Новый символ</param>
/// <returns>Возвращает указатель на новую строку</returns>
char* ReplaceSymbol(char* str, char symbol, char value)
{
	int size = strlen(str) + 1; // размер + 1, потому что конец строки \0
	char* copy = new char[size]; // выделяем динамическую память

	auto error = strcpy_s(copy, size, str); // копируем и проверяем на ошибку
	if (error != 0)
		return nullptr;

	_strlwr_s(copy, size); // переводим всё в нижний регистр
	auto found = strchr(copy, symbol); // ищем символ
	while (found)
	{
		*found = value; // заменяем символ
		found = strchr(found + 1, symbol); // снова ищем, но уже со следующей позиции
	}

	return copy; // возращаем строку
}

/// <summary>
/// Проверяет совпадение по двум строкам
/// </summary>
/// <param name="originalString">Строка, в которой производится поиск</param>
/// <param name="findStr">Искомая строка</param>
/// <returns>Возращает true, если найдено и false - нет</returns>
bool IsExist(char* originalString, const char* findStr)
{
	auto length = strlen(findStr); // находим длину
	auto found = _strnicmp(originalString, findStr, length); // возращается -1, если нет совпадений, 0 - найдено

	return  found == 0; // переводим в булеву
}

int main()
{
	setlocale(0, "");

	char str[] = "Hello world";
	char replaceSymbol = 'l';
	char newSymbol = 'r';
	char* newStr = ReplaceSymbol(str, replaceSymbol, newSymbol);

	cout << "Исходная строка: " << str << endl;
	cout << "Меняем символ \"" << replaceSymbol << "\" на \"" << newSymbol << "\"" << endl;
	cout << "Новая строка: " << newStr << endl;
	delete[] newStr;

	const int size = 4;
	char find[] = "sido";
	char buffer[size][10]
	{
	 {"Sidorenko"},
	 {"Sidorov"},
	 {"Sidik"},
	 {"Petrov"}
	};

	cout << "\nФамилии:" << endl;
	for (int i = 0; i < size; i++)
		cout << buffer[i] << endl;

	cout << "\nИщем \"" << find << "\". Найдено:" << endl;
	for (int i = 0; i < size; i++)
	{
		if (IsExist(buffer[i], find))
			cout << buffer[i] << endl;
	}

	return 0;
}