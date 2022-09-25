// PCClub.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "lib.h"
#include "OrderTable.h"

int main()
{
	setlocale(LC_ALL, "Russian"); //Включение русского языка
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do {
		int flag = 0;
		do {
			Manager manager[2];
			for (int i = 0; i < 2; i++)
			{
				char s[5] = "123";
				manager[i] = InitManager(i, s, "123", 2);
			}
 			flag = 0;
			system("cls"); //Главнео меню
			printf("	Программный модуль учета клиентов компьютерного клуба\n\n");
			printf("	1 - Ввод данных\n");
			printf("	2 - Вывод списка\n");
			printf("	ESC - выход\n");
			switch (_getch()) {
			case '1': {
				system("cls"); //Главнео меню
				printf("	Ввод данных\n\n");
				printf("	1 - ввод данных о менеджерах\n");
				printf("	2 - ввод данных о клиентах\n");
				printf("	3 - ввод данных об услугах\n");
				printf("	4 - ввод данных о компьютерах\n");
				printf("	5 - ввод данных дата центра\n");
				printf("	ESC - выход\n");
				switch (_getch()) {
				case '1': { //Ввод данных
					system("cls");
					FprintfManager(ScanfManager(), "Manager.txt", "\n");
					break;
				}
				case '2': { //Ввод данных
					system("cls");
					FprintfClient(ScanfClient(), "Client.txt", "\n");
					break;
				}
				case '3': { //Ввод данных
					system("cls");
					FprintfServices(ScanfService(), "Service.txt", "\n");
					break;
				}
				case '4': { //Ввод данных
					system("cls");
					FprintfPC(ScanfPC(), "PC.txt", "\n");
					break;
				}
				case '5': { //Ввод данных
					FprintfOrderTable(ScanfOrderTable(), "OrderTable.txt");
					system("cls");
					break;
				}
				case 27: //Выход
					break;
				default:
					printf("\nНе понимаю, что вы хотите сделать\n");
					_getch();
					break;
				}
				break;
			}
			case '2': {
				system("cls"); //Главнео меню
				printf("	Вывод данных\n\n");
				printf("	1 - Вывод данных о менеджерах\n");
				printf("	2 - Вывод данных о клиентах\n");
				printf("	3 - Вывод данных об услугах\n");
				printf("	4 - Вывод данных о компьютерах\n");
				printf("	5 - Вывод данных дата центра\n");
				printf("	ESC - выход\n");
				switch (_getch()) {
				case '1': { //Ввод данных
					system("cls");
					PrintfFromFileManager("Manager.txt");
					break;
				}
				case '2': { //Ввод данных
					system("cls");
					PrintfFromFileClient("Client.txt");
					break;
				}
				case '3': { //Ввод данных
					system("cls");
					PrintfFromFileService("Service.txt");
					break;
				}
				case '4': { //Ввод данных
					system("cls");
					PrintfFromFilePC("PC.txt");
					break;
				}
				case '5': { //Ввод данных
					system("cls");
					PrintfFromFileOrderTable("OrderTable.txt");

					break;
				}
				case 27: //Выход
					break;
				default:
					printf("\nНе понимаю, что вы хотите сделать\n");
					_getch();
					break;
				}
			}
			case 27: //Выход
				break;
			}
		} while (flag != 1);
		system("cls");
		// вывод результата
		
		// вывод результата
		printf("Для завершения ввода слов нажмите ESC\n Для повторного ввода нажмите любую клавишу... \n");
	} while (_getch() != 27);
	remove("tempSearch.txt"); //Удаление временных файлов
	remove("tempSearch1.txt");
	remove("tempSearch2.txt");
	remove("dataSBaseS1.txt");
	system("pause");
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
