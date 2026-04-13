#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 20;
enum genre { ACTION, COMEDY, DRAMA, THRILLER, HORROR, SCI_FI, ROMANCE };

struct date { 
	int year;
	int month;
	int day;
};

struct film { 
	string name = "";
	string director[2] = { "", "" };
	genre type = ACTION;
	date premier = {1970, 1, 1};
	int length = 0;
	int cost = 0;
	double rating = 0;
	string main_actor = "";
	int birth=1970;
};

void print(film movies[], int k) { 

	printf("%-20s %-20s %-20s %-15s %-6s %-7s %-5s %-7s %-10s %-10s %-20s %-20s\n",
		"Название", "Режиссер имя", "Режиссер фамилия", "Жанр", "Год", "Месяц", "День",
		"Длина", "Стоимость", "Рейтинг", "Актер", "Год рождения");

	for (int i = 0; i < k; i++) {
		string jnr = "";
		switch (movies[i].type) {
		case ACTION:
			jnr = "Экшен";
			break;
		case COMEDY:
			jnr = "Комедия";
			break;
		case DRAMA:
			jnr = "Драма";
			break;
		case THRILLER:
			jnr = "Триллер";
			break;
		case HORROR:
			jnr = "Хоррор";
			break;
		case SCI_FI:
			jnr = "Научное";
			break;
		case ROMANCE:
			jnr = "Романтика";
			break;
		}
		printf("%-20s %-20s %-20s %-15s %-6d %-7d %-5d %-7d %-10d %-10.1f %-20s %-5i\n",
			movies[i].name.c_str(),
			movies[i].director[0].c_str(),
			movies[i].director[1].c_str(),
			jnr.c_str(),
			movies[i].premier.year,
			movies[i].premier.month,
			movies[i].premier.day,
			movies[i].length,
			movies[i].cost,
			movies[i].rating,
			movies[i].main_actor.c_str(),
			movies[i].birth);
	}
	cout << "\n";
}

void printWrapper(film movies[], int count, string title) { 
	cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << title << "\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	print(movies, count);
}
void printFilmByName(film movies[], int count) { 
	string searchName;
	cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "Поиск фильма по названию\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "Введите название фильма: ";
	getline(cin, searchName);

	bool found = false;
	for (int i = 0; i < count; i++) {
		if (movies[i].name == searchName) { 
			printWrapper(&movies[i], 1, "Данные по фильму: " + searchName); 
			found = true;
			break;
		}
	}
	if (!found) { 
		cout << "\nФильм \"" << searchName << "\" не найден!\n";
	}
}
void edit_film(film movies[]) { 
	bool find_name = 0;
	int index = 0;
	do {
		for (int i = 0; i < SIZE; i++) { 
			cout << i + 1 << ". " << movies[i].name << endl;
		}
		int film_name = 0;
		cout << "Введите номер фильма: ";
		cin >> index;
		if (index >= 1 and index <= 20) find_name = 1;
		if (find_name == 0) cout << "Фильма под таким номером нету\n";
	} while (find_name == 0);
	int choice = 0;
	cout << "Выбери что изменить:\n";
	cout << "1.Название 2.Режиссер имя 3.Режиссер фамилия 4.Жанр\n5.Год 6.Длина 7.Стоимость 8.Рейтинг 9.Актер\n";
	cin >> choice;
	cin.ignore();
	index--;
	int a = 0;
	int b = 0;
	double r = 0;
	switch (choice) { 
	case 1:
		cout << "Новое название: ";
		getline(cin, movies[index].name);
		break;
	case 2:
		cout << "Новый режиссер 1: ";
		getline(cin, movies[index].director[0]);
		break;
	case 3:
		cout << "Новый режиссер 2: ";
		getline(cin, movies[index].director[1]);
		break;
	case 4:
		cout << "Новый жанр: ";
		cout << "Выбери жанр\n";
		cout << "1.Экшен 2.Комедия 3.Драма 4.Триллер 5.Хоррор 6.Научное 7.Романтика\n";
		cin >> b;
		switch (b) { 
		case 1:
			movies[index].type = ACTION;
			break;
		case 2:
			movies[index].type = COMEDY;
			break;
		case 3:
			movies[index].type = DRAMA;
			break;
		case 4:
			movies[index].type = THRILLER;
			break;
		case 5:
			movies[index].type = HORROR;
			break;
		case 6:
			movies[index].type = SCI_FI;
			break;
		case 7:
			movies[index].type = ROMANCE;
			break;
		}
		break;
	case 5:
		cout << "Новый год выпуска: ";
		cin >> a;
		movies[index].premier.year = a;
		cout << "Новый месяц выпуска: ";
		cin >> a;
		movies[index].premier.month = a;
		cout << "Новый день выпуска: ";
		cin >> a;
		movies[index].premier.day = a;
		break;
	case 6:
		cout << "Новая длина: ";
		cin >> a;
		movies[index].length = a;
		break;
	case 7:
		cout << "Новая стоимость: ";
		cin >> a;
		movies[index].cost = a;
		break;
	case 8:
		cout << "Новый рейтинг: ";
		cin >> r;
		movies[index].rating = r;
		break;
	case 9:
		cout << "Новый актер: ";
		getline(cin, movies[index].main_actor);
		break;
	}
	printWrapper(movies, 20, "Измененный список фильмов"); 
}

void Rayan(film movies[]) { 
	film rayan[SIZE];
	int k = 0;
	for (int i = 0; i < SIZE; i++) {
		if (movies[i].main_actor == "Райан Гослинг") { 
			rayan[k] = movies[i];
			k++;
		}
	}
	for (int i = 0; i < k - 1; i++) {
		for (int j = 0; j < k - i - 1; j++) {
			if (rayan[j].name > rayan[j + 1].name) { 
				film temp = rayan[j];
				rayan[j] = rayan[j + 1];
				rayan[j + 1] = temp;
			}
		}
	}
	printWrapper(rayan, k, "Фильмы с Райаном Гослингом"); 
}
void Expensive(film movies[]) { 
	film expensive[SIZE];
	int k = 0;
	for (int i = 0; i < SIZE; i++) {
		if (movies[i].premier.year >= 2020 && movies[i].premier.year <= 2029) { 
			expensive[k] = movies[i];
			k++;
		}
	}
	for (int i = 0; i < k - 1; i++) {
		for (int j = 0; j < k - i - 1; j++) {
			if (expensive[j].cost < expensive[j + 1].cost) { 
				film temp = expensive[j];
				expensive[j] = expensive[j + 1];
				expensive[j + 1] = temp;
			}
		}
	}

	int count = (k < 4) ? k : 4; 
	printWrapper(expensive, count, "Самые дорогие фильмы 2020-х годов"); 
}

void David(film movies[]) { 
	film david[20];
	int k = 0;
	for (int i = 0; i < SIZE; i++) {
		if (movies[i].type == THRILLER) { 
			if (movies[i].director[0] == "Дэвид") { 
				bool flag_name = 0;
				for (int j = 0; j < k; j++) {
					if (movies[i].director[1] == david[j].director[1]) { flag_name = 1; break; } 
				}
				if (flag_name == 0) {
					david[k] = movies[i];
					k++;
				}
			}
		}
	}
	printWrapper(david, k, "Фильмы с Дэвидом"); 
}

void scan_file(film movies[]) {
	ifstream fin;
	string actors[SIZE], str, year;
	int births[SIZE], years[SIZE];
	int k = -1;
	fin.open("actors.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			k++;
			fin >> str;
			actors[k] = str;
			fin >> str;
			actors[k] = actors[k] + " " + str;
			fin >> year;
			years[k] = stoi(year);
		}
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < k+1; j++) {
			if (movies[i].main_actor == actors[j]) {
				movies[i].birth = years[j];
			}
		}
	}
	printWrapper(movies, SIZE, "Считанные с файла дни рождения актеров");
}

void binaryOutput(film movies[]) {
	ofstream out("struct.txt",
		ios::binary | ios::out);
	for (int i = 0; i < SIZE; i++)
	{
		out.write((char*)&movies[i], sizeof(movies[i]));
	}
	out.close();
	cout << "Бинарная запись завершена \n";
}

void binaryInput(film movies[]) {
	fstream in("struct.txt", ios::binary | ios::in);
	int i = 0;
	if (in.is_open()) {
		while (!in.eof())
		{
			in.read((char*)&movies[i], sizeof(movies[i]));
			i++;
		}
		in.close();
	}
	else {
		cout << "Не найдено \n";
	}

	printWrapper(movies, SIZE, "Чтение из бинарной записи");
}

film* init() { 
	film* movies = new film[SIZE]; 
	movies[0] = { "Ла-Ла Ленд", { "Дэмьен", "Шазелл" }, DRAMA, { 2016, 8, 31 }, 128, 30, 8.3, "Райан Гослинг" };
	movies[1] = { "Драйв", { "Николас", "Виндинг Рефн" }, THRILLER, { 2011, 5, 20 }, 100, 15, 7.8, "Райан Гослинг" };
	movies[2] = { "Оппенгеймер", { "Кристофер", "Нолан" }, DRAMA, { 2023, 7, 21 }, 180, 100, 8.6, "Киллиан Мерфи" };
	movies[3] = { "Барби", { "Грета", "Гервиг" }, COMEDY, { 2023, 7, 21 }, 114, 145, 7.2, "Марго Робби" };
	movies[4] = { "Дюна", { "Дени", "Вильнев" }, SCI_FI, { 2021, 9, 16 }, 155, 165, 8.1, "Тимоти Шаламе" };
	movies[5] = { "Джон Уик 4", { "Чад", "Стахелски" }, ACTION, { 2023, 3, 24 }, 169, 100, 8.0, "Киану Ривз" };
	movies[6] = { "Семь", { "Дэвид", "Финчер" }, THRILLER, { 1995, 9, 22 }, 127, 33, 8.6, "Брэд Питт" };
	movies[7] = { "Бойцовский клуб", { "Дэвид", "Финчер" }, DRAMA, { 1999, 10, 15 }, 139, 63, 8.8, "Брэд Питт" };
	movies[8] = { "Начало", { "Кристофер", "Нолан" }, SCI_FI, { 2010, 7, 16 }, 148, 160, 8.7, "Леонардо ДиКаприо" };
	movies[9] = { "Интерстеллар", { "Кристофер", "Нолан" }, SCI_FI, { 2014, 11, 7 }, 169, 165, 8.6, "Мэттью МакКонахи" };
	movies[10] = { "Паразиты", { "Пон Джун", "Хо" }, THRILLER, { 2019, 5, 30 }, 132, 154, 8.2, "Сон КанХо" };
	movies[11] = { "Джокер", { "Тодд", "Филлипс" }, THRILLER, { 2019, 10, 4 }, 122, 55, 8.1, "Хоакин Феникс" };
	movies[12] = { "Остров проклятых", { "Дэвид", "Скорсезе" }, THRILLER, { 2010, 2, 19 }, 138, 80, 8.4, "Леонардо ДиКаприо" };
	movies[13] = { "Форсаж 10", { "Луи", "Летерье" }, ACTION, { 2023, 5, 19 }, 141, 340, 6.5, "Вин Дизель" };
	movies[14] = { "Аватар: Путь воды", { "Джеймс", "Кэмерон" }, SCI_FI, { 2022, 12, 16 }, 192, 460, 7.9, "Сэм Уортингтон" };
	movies[15] = { "Человек-паук", { "Джон", "Уоттс" }, ACTION, { 2021, 12, 15 }, 148, 200, 7.8, "Том Холланд" };
	movies[16] = { "Топ Ган", { "Джозеф", "Косински" }, ACTION, { 2022, 5, 27 }, 130, 170, 8.2, "Том Круз" };
	movies[17] = { "Молчание ягнят", { "Джонатан", "Демми" }, THRILLER, { 1991, 2, 14 }, 118, 19, 8.5, "Джоди Фостер" };
	movies[18] = { "Одержимость", { "Дэмьен", "Шазелл" }, DRAMA, { 2014, 10, 10 }, 107, 33, 8.5, "Майлз Теллер" };
	movies[19] = { "Безумный Макс", { "Джордж", "Миллер" }, ACTION, { 2015, 5, 15 }, 120, 150, 7.9, "Том Харди" };

	return movies;
}

int main() {
	system("chcp 1251 > nul");
	setlocale(LC_ALL, "Russian");

	film* movies = init();
	Rayan(movies);
	Expensive(movies);
	printFilmByName(movies, 20);
	edit_film(movies);
	David(movies);
	scan_file(movies);
	binaryOutput(movies);
	binaryInput(movies);
	delete[] movies;

	return 0;

}
