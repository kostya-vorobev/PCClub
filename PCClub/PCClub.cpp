// PCClub.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "lib.h"

int main()
{
	setlocale(LC_ALL, "Russian"); //Включение русского языка
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do {
		int flag = 0;
		do {
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
					writeFileManager(ManagerWriteUser(), "Manager.txt", "\n");
					break;
				}
				case '2': { //Ввод данных
					system("cls");
					writeFileClient(ClientWriteUser(), "Client.txt", "\n");
					break;
				}
				case '3': { //Ввод данных
					system("cls");
					writeFileServices(ServiceWriteUser(), "Service.txt", "\n");
					break;
				}
				case '4': { //Ввод данных
					system("cls");
					writeFilePC(PCWriteUser(), "PC.txt", "\n");
					break;
				}
				case '5': { //Ввод данных
					writeFileDataCenter(DataCenterWriteUser(), "DataCenter.txt");
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
				/*
				system("cls"); // Ввод и корректировка списка данных о студентиах
				printf("	Ввод и корректировка списка данных\n\n");
				printf("	1 - ввод данных о студентах\n");
				printf("	2 - изменение данных о студентах\n");
				printf("	3 - удаление записи о студенте\n");
				printf("	ESC - назад\n");
				switch (_getch()) {
				case '1': { //Ввод данных
					system("cls");
					fillStruct();
					break;
				}
				case '2': { //Редактирование
					system("cls");
					int flagredact = 0;
					CreateFileS("tempSearch.txt");
					if (!CheckFile("dataSBaseS.txt")) { //Проверка еа существование
						break;
					}
					if (!ChekFillFile("dataSBaseS.txt")) { //Проверка наличия записей
						break;
					}
					copyFile("dataSBaseS.txt", "tempSearch.txt");
					char tempSearchS[50][50]{ {} }, ch = 0;
					int tempChI = 0;
					int i = 0;

					do { //Поиск записи
						system("cls");
						printf("		РЕДАКТИРОВАНИЕ ЗАПИСЕЙ\n\n");
						printf("	Перед началом редактирования необходимо отфильтровать записи\n");
						printf("	Ввод осуществяется выше таблицы, поиск по лючевым словам\n");
						printf("	Слова вводить через 'ПРОБЕЛ'\n");
						printf("	'ENTER' - закончить фильтрацию\n");
						printf("	Применяемый в данный момент фильтр: %s\n", tempSearchS[i]);
						if (tempSearchS[0][0] == NULL)
						{
							showDataFile("dataSBaseS.txt");
						}
						else {
							checkStringInFile(tempSearchS);
						}
						printf("Действующий фильтр: ");
						for (int j = 0; j < i; j++)
							printf("%s ", tempSearchS[j]);
						ch = _getch();
						if (tempSearchS[0][0] != NULL)
						{
							if (ch == 8)
							{
								if (strlen(tempSearchS[i]) == 0 && i != 0)
								{
									i--;
								}
								tempSearchS[i][strlen(tempSearchS[i]) - 1] = NULL;
							}
							if (ch == 32)
							{
								i++;
							}
						}
						if (ch != 8 && ch != '\r' && ch != '\n' && ch != 32)
						{
							tempSearchS[i][strlen(tempSearchS[i])] = ch;
						}
						if (ch == 27) flagredact = 1;
					} while (ch != '\r' || flagredact == 1);
					int countR = CountFillFile("tempSearch.txt");
					if (countR > 0) {
						int numS;
						numS = get_int("\nВведите номер студента для редактирования: ");
						while (numS < 1 || numS > countR) {
							numS = get_int("Ошибка, студент не найден!\nВведите номер студента для редактирования: ");
						}
						FILE* f = fopen("tempSearch.txt", "r");
						for (int i = 0; i < numS; i++)
							students = SFIF(f);
						do { //Редактирование данных в файле
							system("cls");
							printf("РЕДАКТИРОВАНИЕ ЗАПИСЕЙ\n");
							outputUPSRecotrds();
							outputOSRecotrds(students, 1);
							outputLineRecotrds(165);
							printf("|%3s|%25s|%7s|%14s|%13s|%40s|%8s|%4s|%40s|\n", " ", "1", "2", "3", "4", "5", "6", " ", "7");
							outputLineRecotrds(165);
							printf("Выберите данные для редактирования от 1 до 7\n");
							printf("ESC - назад\n");
							Student buffS = students;
							switch (int(_getch()))
							{
							case '1': { //ФИО

								do {
									inputURecotrds(students.fullName, "Введите ФИО: ", sizeof(students.fullName));
								} while (!checkName(students.fullName));
								DeleteS(buffS, "dataSBaseS.txt");
								writeFile(students, "dataSBaseS.txt");
								break;
							}
							case '2': { //Группа
								inputURecotrds(students.group, "Введите Группу: ", sizeof(students.group));
								DeleteS(buffS, "dataSBaseS.txt");
								writeFile(students, "dataSBaseS.txt");
								break;
							}
							case '3': { //Дата
								get_date(&students.dayB, &students.monthB, &students.yearB);
								DeleteS(buffS, "dataSBaseS.txt");
								writeFile(students, "dataSBaseS.txt");
								break;
							}
							case '4': { //Телефон
								do {
									inputURecotrds(students.telephone, "Введите номер телефона: ", sizeof(students.telephone));
								} while (!checkphone(students.telephone));
								DeleteS(buffS, "dataSBaseS.txt");
								writeFile(students, "dataSBaseS.txt");
								break;
							}
							case '5': { //Электронная почта
								do {
									inputURecotrds(students.email, "Введите Email: ", sizeof(students.email));
								} while (!checkEmail(students.email));
								DeleteS(buffS, "dataSBaseS.txt");
								writeFile(students, "dataSBaseS.txt");
								break;
							}
							case '6': { //Рейтин
								do {
									students.topS = get_int("Введите рейтинг студента от 0 до 100: ");
								} while (students.topS > 100);
								DeleteS(buffS, "dataSBaseS.txt");
								writeFile(students, "dataSBaseS.txt");
								break;
							}
							case '7': { //Дисциплина
								system("cls");
								printf("1 - добавить дисциплину\n");
								printf("2 - изменить дисциплину\n");
								printf("3 - удалить дисциплину\n");
								printf("ESC - назад\n");
								fseek(stdin, 0, SEEK_END);
								switch (int(_getch())) {
								case '1': //Добавление дисциплины
								{
									if (students.debts < m / 2) {
										do {
											inputURecotrds(students.charDebts[students.debts], "Введите название дисциплины: ", sizeof(students.charDebts[students.debts]));
										} while (!checkName(students.charDebts[students.debts]));
										if (students.charDebts[students.debts] != NULL)
										{
											students.debts++;
										}
										outputDSRecotrds(students);
									}
									else {
										puts("Память по долгам студента переполнена!\n");
										puts("Его давно пора отчислить!\n");
									}
									DeleteS(buffS, "dataSBaseS.txt");
									writeFile(students, "dataSBaseS.txt");
									_getch();
									break;
								}
								case '2': //Редактирование дисциплины
								{
									outputDSRecotrds(students);
									printf("Введите номер записи которую хотите изменить: ");
									int tempND = get_int("");
									while (tempND > students.debts) {
										tempND = get_int("К сожалению данная запись не найдена, вопоробуйте ввести заново: ");
									}
									do {
										inputURecotrds(students.charDebts[tempND - 1], "Введите новое название дисциплины: ", sizeof(students.charDebts[tempND - 1]));
									} while (!checkName(students.charDebts[students.debts]));
									printf("Успешно!");
									_getch();
									DeleteS(buffS, "dataSBaseS.txt");
									writeFile(students, "dataSBaseS.txt");
									break;
								}
								case '3': //Удаление дисциплины
								{
									outputDSRecotrds(students);
									printf("Введите номер записи которую хотите удалить: ");
									int tempND = get_int("");
									while (tempND > students.debts) {
										tempND = get_int("К сожалению данная запись не найдена, вопоробуйте ввести заново: ");
									}
									for (int i1 = tempND - 1; i1 < students.debts - 1; i1++)
									{
										strcpy(students.charDebts[i1], students.charDebts[i1 + 1]);
									}
									strcpy(students.charDebts[students.debts - 1], "");
									students.debts--;
									printf("Успешно!");
									_getch();
									DeleteS(buffS, "dataSBaseS.txt");
									writeFile(students, "dataSBaseS.txt");
									break;
								}
								case 27:

									break;
								default:
									printf("\nНе понимаю, что вы хотите сделать\n");
									_getch();
									break;
								};

								break;
							}
							case 27: //Выход
								break;
							default:
								printf("\nНе понимаю, что вы хотите сделать\n");
								_getch();
								break;
							}
							puts("ESC - Главнео меню");
							puts("Для повторного редактрования нажмите любую клавишу");
						} while (_getch() != 27);
					}
					else printf("\nПо данным фильтрам запсией не найдено\n");
					break;
				}
				case '3': { //Удаление записи
					system("cls");
					int flagredact = 0;
					CreateFileS("tempSearch.txt");
					if (!CheckFile("dataSBaseS.txt")) {
						break;
					}
					if (!ChekFillFile("dataSBaseS.txt")) {
						break;
					}
					char tempSearchS[50][50]{ {} }, ch = 0;
					int tempChI = 0;
					int i = 0;
					copyFile("dataSBaseS.txt", "tempSearch.txt");
					do { //Поиск записи
						system("cls");
						printf("		УДАЛЕНИЕ ЗАПИСЕЙ\n\n");
						printf("	Перед началом редактирования необходимо отфильтровать записи\n");
						printf("	Ввод осуществяется выше таблицы, поиск по лючевым словам\n");
						printf("	Слова вводить через 'ПРОБЕЛ'\n");
						printf("	'ENTER' - закончить фильтрацию\n");
						printf("	Применяемый в данный момент фильтр: %s\n", tempSearchS[i]);
						if (tempSearchS[0][0] == NULL)
						{
							showDataFile("dataSBaseS.txt");
						}
						else {
							checkStringInFile(tempSearchS);
						}
						printf("Действующий фильтр: ");
						for (int j = 0; j < i; j++)
							printf("%s ", tempSearchS[j]);
						ch = _getch();
						if (tempSearchS[0][0] != NULL)
						{
							if (ch == 8)
							{
								if (strlen(tempSearchS[i]) == 0 && i != 0)
								{
									i--;
								}
								tempSearchS[i][strlen(tempSearchS[i]) - 1] = NULL;
							}
							if (ch == 32)
							{
								i++;
							}
						}
						if (ch != 8 && ch != '\r' && ch != '\n' && ch != 32)
						{
							tempSearchS[i][strlen(tempSearchS[i])] = ch;
						}
						if (ch == 27) ch = '\r';
					} while (ch != '\r');
					int countR = CountFillFile("tempSearch.txt");
					if (countR > 0) {
						int numS;
						numS = get_int("\nВведите номер студента для редактирования: ");
						while (numS < 1 || numS > countR) {
							numS = get_int("Ошибка, студент не найден!\nВведите номер студента для редактирования: ");
						}
						FILE* f = fopen("tempSearch.txt", "r");
						for (int i = 0; i < numS; i++)
							students = SFIF(f);
						puts("Вы действительно хотите удалить ланного студента?\n 1 - Удалить\n 2 - Оставить\n");
						int ex = 0;
						do { //Выбор и удаление записи
							ex = get_int("");
						} while (ex < 1 && ex > 2);
						switch (ex)
						{
						case 1:
							DeleteS(students, "dataSBaseS.txt");
							system("cls");
							puts("Студент будет удален из базы данных");
							_getch();
							break;
						case 2:
							puts("Омена удаленния");
							_getch();
							break;
						}
					}
					else printf("\nПо данным фильтрам запсией не найдено\n");
					break;
				}
				case 27: //Выход
					break;
				default:
					printf("\nНе понимаю, что вы хотите сделать\n");
					break;
				}
				break;
			}
			case '2': { //Показ всез записей на экран
				system("cls");
				showDataFile("dataSBaseS.txt");
				_getch();
				break;
			}
			case '3': { //Фильтр запсией
				system("cls");
				printf("		ФИЛЬТР ЗАПИСЕЙ\n");
				printf("	1 - поиск студента\n");
				printf("	2 - фильтр записей\n");
				printf("	ESC - назад\n");

				switch (_getch()) {
				case '1': { //Поиск записи по ключевым словам
					int flagredact = 0;
					CreateFileS("tempSearch.txt");
					if (!CheckFile("dataSBaseS.txt")) {
						break;
					}
					if (!ChekFillFile("dataSBaseS.txt")) {
						break;
					}
					char tempSearchS[50][50]{ {} }, ch = 0;
					int tempChI = 0;
					int i = 0;

					do {
						system("cls");
						printf("		ПОИСК ЗАПИСИ\n\n");
						printf("	Ввод осуществяется выше таблицы, поиск по лючевым словам\n");
						printf("	Слова вводить через 'ПРОБЕЛ'\n");
						printf("	'ENTER' - закончить фильтрацию\n");
						printf("	Применяемый в данный момент фильтр: %s\n", tempSearchS[i]);
						if (tempSearchS[0][0] == NULL)
						{
							showDataFile("dataSBaseS.txt");
						}
						else {
							checkStringInFile(tempSearchS);
						}
						printf("Действующий фильтр: ");
						for (int j = 0; j < i; j++)
							printf("%s ", tempSearchS[j]);
						ch = _getch();
						if (tempSearchS[0][0] != NULL)
						{
							if (ch == 8)
							{
								if (strlen(tempSearchS[i]) == 0 && i != 0)
								{
									i--;
								}
								tempSearchS[i][strlen(tempSearchS[i]) - 1] = NULL;
							}
							if (ch == 32)
							{
								i++;
							}
						}
						if (ch != 8 && ch != '\r' && ch != '\n' && ch != 32)
						{
							tempSearchS[i][strlen(tempSearchS[i])] = ch;
						}
						if (ch == 27) flagredact = 1;
					} while (ch != '\r' || flagredact == 1);
					break;
				}
				case '2': {//Фильтр для поиска по критериям
					CreateFileS("tempSearch1.txt");
					copyFile("dataSBaseS.txt", "tempSearch1.txt");
					do {
						system("cls");
						printf("		ФИЛЬТР ЗАПИСЕЙ\n\n");
						puts("	Фильтры накладываются друг на друга, для очистки фильтра выйдете в главное меню");
						outputLineRecotrds(165);
						outputUPSRecotrds();
						outputLineRecotrds(165);
						printf("|%3s|%25s|%7s|%14s|%13s|%40s|%8s|%5s|%40s|\n", " ", "1", "2", "3", "4", "5", "6", "7", "8");
						outputLineRecotrds(165);
						printf("Фильтры накладываются друг на друга\n Выберите фильтр от 1 до 8\n");
						FILE* search;
						Student studentSearch;
						switch (int(_getch())) {
						case '1': //Поиск по ФИО
						{
							system("cls");
							char searchTemp[25];
							inputURecotrds(searchTemp, "Поиск по фамилии, введите ФИО для поиска: ", sizeof(searchTemp));
							CreateFileS("tempSearch2.txt");
							search = fopen("tempSearch1.txt", "r");
							if (search == NULL) {
								printf("Файл не существует");
								system("pause");
								break;
							}
							else {
								while (!feof(search)) //Считывание во временный файл
								{
									studentSearch = SFIF(search);
									if (strstr(studentSearch.fullName, searchTemp))
									{
										writeFile(studentSearch, "tempSearch2.txt");
									}
								}
								fclose(search);
							}
							copyFile("tempSearch2.txt", "tempSearch1.txt");
							remove("tempSearch2.txt");
							printf("Студенты студенты c ФИО %s \n", searchTemp);
							showDataFile("tempSearch1.txt");
							break;
						}
						case '2': //Поиск по группк
						{
							system("cls");
							char searchTemp[7];
							inputURecotrds(searchTemp, "Поиск по группе, введите группу для поиска: ", sizeof(searchTemp));
							CreateFileS("tempSearch2.txt");
							search = fopen("tempSearch1.txt", "r");
							if (search == NULL) {
								printf("Файл не существует");
								system("pause");
								break;
							}
							else {
								while (!feof(search)) //Считывание во временный файл
								{
									studentSearch = SFIF(search);
									if (strstr(studentSearch.group, searchTemp))
									{
										writeFile(studentSearch, "tempSearch2.txt");
									}
								}
								fclose(search);
							}
							copyFile("tempSearch2.txt", "tempSearch1.txt");
							remove("tempSearch2.txt");
							printf("Студенты студенты группы %s \n", searchTemp);
							showDataFile("tempSearch1.txt");
							break;
						}
						case '3': //Фильтр по дате
						{
							system("cls");
							puts("	1 - Найти студенто родившихся позже даты: ");
							puts("	2 - Найти студенто родившихся ранее даты: ");
							printf("ESC - назад\n");
							switch (_getch())
							{
							case '1': //позже определенной даты
							{
								system("cls");
								int dayS, monthS, yearS;
								get_date(&dayS, &monthS, &yearS);
								search = fopen("tempSearch1.txt", "r");
								CreateFileS("tempSearch2.txt");
								if (search == NULL) {
									printf("Файл не существует");
									system("pause");
									break;
								}
								else {
									while (!feof(search)) //Считывание во временный файл
									{
										studentSearch = SFIF(search);
										if (!iSDate(studentSearch.dayB, studentSearch.monthB, studentSearch.yearB, dayS, monthS, yearS, 2))
										{
											writeFile(studentSearch, "tempSearch2.txt");
										}
									}
									fclose(search);
								}
								copyFile("tempSearch2.txt", "tempSearch1.txt");
								remove("tempSearch2.txt");
								printf("Студенты родившиеся после %d.%d.%d \n", dayS, monthS, yearS);
								showDataFile("tempSearch1.txt");
								break;
							}
							case '2': //Ранее определенной даты
							{
								system("cls");
								int dayS, monthS, yearS;
								get_date(&dayS, &monthS, &yearS);
								CreateFileS("tempSearch2.txt");
								search = fopen("tempSearch1.txt", "r");
								if (search == NULL) {
									printf("Файл не существует");
									system("pause");
									break;
								}
								else {
									while (!feof(search)) //Считывание во временный файл
									{
										studentSearch = SFIF(search);
										if (!iSDate(studentSearch.dayB, studentSearch.monthB, studentSearch.yearB, dayS, monthS, yearS, 1))
										{
											writeFile(studentSearch, "tempSearch2.txt");
										}
									}
									fclose(search);
								}
								copyFile("tempSearch2.txt", "tempSearch1.txt");
								remove("tempSearch2.txt");
								printf("Студенты родившиеся ранее %d.%d.%d \n", dayS, monthS, yearS);
								showDataFile("tempSearch1.txt");
								break;
							}
							case 27: //Выход
							{
								break;
							}
							default:
								printf("\nНе понимаю, что вы хотите сделать\n");
								_getch();
								break;
							}
							break;
						}
						case '4': //Поиск по номеру телефона
						{
							system("cls");
							char searchTemp[12];
							inputURecotrds(searchTemp, "Поиск по телефону, введите номер телефона для поиска: ", sizeof(searchTemp));
							CreateFileS("tempSearch2.txt");
							search = fopen("tempSearch1.txt", "r");
							if (search == NULL) {
								printf("Файл не существует");
								system("pause");
								break;
							}
							else {
								while (!feof(search)) //Считывание во временный файл
								{
									studentSearch = SFIF(search);
									if (strstr(studentSearch.telephone, searchTemp))
									{
										writeFile(studentSearch, "tempSearch2.txt");
									}
								}
								fclose(search);
							}
							copyFile("tempSearch2.txt", "tempSearch1.txt");
							remove("tempSearch2.txt");
							printf("Студенты студенты c номером телефона %s \n", searchTemp);
							showDataFile("tempSearch1.txt");
							break;
						}
						case '5': //Поиск по электроннйо почте
						{
							system("cls");
							char searchTemp[41];
							inputURecotrds(searchTemp, "Поиск по почте, введите email для поиска: ", sizeof(searchTemp));
							CreateFileS("tempSearch2.txt");
							search = fopen("tempSearch1.txt", "r");
							if (search == NULL) {
								printf("Файл не существует");
								system("pause");
								break;
							}
							else {
								while (!feof(search)) //Считывание во временный файл
								{
									studentSearch = SFIF(search);
									if (strstr(studentSearch.email, searchTemp))
									{
										writeFile(studentSearch, "tempSearch2.txt");
									}
								}
								fclose(search);
							}
							copyFile("tempSearch2.txt", "tempSearch1.txt");
							remove("tempSearch2.txt");
							printf("Студенты студенты c EMAIL %s \n", searchTemp);
							showDataFile("tempSearch1.txt");
							break;
						}
						case '6': //Фильтр по рейтингу
						{
							system("cls");
							puts("	1 - Найти студентов у которых рейтинг меньше: ");
							puts("	2 - Найти студентов у которых рейтинг больше: ");
							printf("ESC - назад\n");
							switch (_getch())
							{
							case '1': //Меньше определенного рейтинга
							{
								system("cls");
								double topS;
								topS = get_int("Найти студентов у которых рейтинг меньше: ");
								CreateFileS("tempSearch2.txt");
								search = fopen("tempSearch1.txt", "r");
								if (search == NULL) {
									printf("Файл не существует");
									system("pause");
									break;
								}
								else {
									while (!feof(search)) //Считывание во временный файл
									{
										studentSearch = SFIF(search);
										if (topS > studentSearch.topS)
										{
											writeFile(studentSearch, "tempSearch2.txt");
										}
									}
									fclose(search);
								}
								copyFile("tempSearch2.txt", "tempSearch1.txt");
								remove("tempSearch2.txt");
								printf("Студенты студенты с рейтингом < %d \n", topS);
								showDataFile("tempSearch1.txt");
								break;
							}
							case '2': //Больше определенного рейтинга
							{
								system("cls");
								double topS;
								topS = get_int("Найти студентов у которых рейтинг больше: ");
								CreateFileS("tempSearch2.txt");
								search = fopen("tempSearch1.txt", "r");
								if (search == NULL) {
									printf("Файл не существует");
									system("pause");
									break;
								}
								else {
									while (!feof(search)) //Считывание во временный файл
									{
										studentSearch = SFIF(search);
										if (topS < studentSearch.topS)
										{
											writeFile(studentSearch, "tempSearch2.txt");
										}
									}
									fclose(search);
								}
								copyFile("tempSearch2.txt", "tempSearch1.txt");
								remove("tempSearch2.txt");
								printf("Студенты студенты с рейтингом > %d \n", topS);
								showDataFile("tempSearch1.txt");
								break;
							}
							case 27: //Выход
							{
								break;
							}
							default:
								printf("\nНе понимаю, что вы хотите сделать\n");
								_getch();
								break;
							}
							break;
						}
						case '7': //Фильтр по количеству долгов
						{
							system("cls");
							puts("	1 - Найти студентов у которых долгов меньше: ");
							puts("	2 - Найти студентов у которых долгов больше: ");
							printf("ESC - назад\n");
							switch (_getch())
							{
							case '1': //Долгов меньше определнного числа
							{
								system("cls");
								int debts;
								debts = get_int("Найти студентов у которых долгов меньше: ");
								CreateFileS("tempSearch2.txt");
								search = fopen("tempSearch1.txt", "r");
								if (search == NULL) {
									printf("Файл не существует");
									system("pause");
									break;
								}
								else {
									while (!feof(search)) //Считывание во временный файл
									{
										studentSearch = SFIF(search);
										if (debts > studentSearch.debts)
										{
											writeFile(studentSearch, "tempSearch2.txt");
										}
									}
									fclose(search);
								}
								copyFile("tempSearch2.txt", "tempSearch1.txt");
								remove("tempSearch2.txt");
								printf("Студенты студенты у которых долгов < %d \n", debts);
								showDataFile("tempSearch1.txt");
								break;
							}
							case '2': //Долгов больше определнного числа
							{
								system("cls");
								int debts;
								debts = get_int("Найти студентов у которых долгов больше: ");
								CreateFileS("tempSearch2.txt");
								search = fopen("tempSearch1.txt", "r");
								if (search == NULL) {
									printf("Файл не существует");
									system("pause");
									break;
								}
								else {
									while (!feof(search)) //Считывание во временный файл
									{
										studentSearch = SFIF(search);
										if (debts < studentSearch.debts)
										{
											writeFile(studentSearch, "tempSearch2.txt");
										}
									}
									fclose(search);
								}
								copyFile("tempSearch2.txt", "tempSearch1.txt");
								remove("tempSearch2.txt");
								printf("Студенты студенты у которых долгов > %d \n", debts);
								showDataFile("tempSearch1.txt");
								break;
							}
							case 27:
							{
								break;
							}
							default:
								printf("\nНе понимаю, что вы хотите сделать\n");
								_getch();
								break;
							}
							break;
						}
						case '8': //Поиск по названию дисциплины
						{
							system("cls");
							char searchTemp[41];
							inputURecotrds(searchTemp, "Поиск по предметам, введите предмет для поиска: ", sizeof(searchTemp));
							CreateFileS("tempSearch2.txt");
							search = fopen("tempSearch1.txt", "r");
							if (search == NULL) {
								printf("Файл не существует");
								system("pause");
								break;
							}
							else {
								while (!feof(search)) //Считывание во временный файл
								{
									int flagD = 0;
									studentSearch = SFIF(search);
									for (int j = 0; j < studentSearch.debts; j++)
										if (strstr(studentSearch.charDebts[j], searchTemp))
										{
											flagD = 1;
										}
									if (flagD == 1)
									{
										flagD = 0;
										writeFile(studentSearch, "tempSearch2.txt");
									}
								}
								fclose(search);
							}
							copyFile("tempSearch2.txt", "tempSearch1.txt");
							remove("tempSearch2.txt");
							printf("Студенты студенты у которых долг по %s \n", searchTemp);
							showDataFile("tempSearch1.txt");
							break;

						}
						case 27: //Выход
						{
							puts("\nДля завершения настройик фильтра нажмите ESC еще раз...");
							break;
						}
						default:
							printf("\nНе понимаю, что вы хотите сделать\n");
							_getch();
							break;
						};


					} while (_getch() != 27);
					remove("tempSearch1.txt");

					break;
				}
				case 27://Выход
				{
					break;
				}
				}
				break;
			}
			case 27: //Выход
				flag = 1;
				break;
			default:
				printf("\nНе понимаю, что вы хотите сделать\n");
				_getch();
				break;
			}


		} while (flag != 1);
		system("cls");
		// вывод результата

		printf("Для завершения ввода слов нажмите ESC\n Для повторного ввода нажмите любую клавишу... \n");
	} while (_getch() != 27);
	*/
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
					ShowManagerDataFile("Manager.txt");
					break;
				}
				case '2': { //Ввод данных
					system("cls");
					ShowClientDataFile("Client.txt");
					break;
				}
				case '3': { //Ввод данных
					system("cls");
					ShowServiceDataFile("Service.txt");
					break;
				}
				case '4': { //Ввод данных
					system("cls");
					ShowPCDataFile("PC.txt");
					break;
				}
				case '5': { //Ввод данных
					system("cls");
					ShowDataCenterDataFile("DataCenter.txt");

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
