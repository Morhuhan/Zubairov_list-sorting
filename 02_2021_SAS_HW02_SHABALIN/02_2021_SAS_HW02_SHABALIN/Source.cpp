#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 255


typedef struct node {
	char type[SIZE];
	char space[SIZE];
	char price[SIZE];
	char avaible[SIZE];
	char view[SIZE];
	struct node* link;
}node;

/* Функция show_menu                                */
/* Назначение:                                      */
/*   выводит на экран меню для работы с программой  */
/* Входные данные:                                  */
/*   отстутствуют                                   */
/* Выходные данные:                                 */
/*   отсутствуют                                    */
/* Возвращаемое значение:                           */
/*   отстуствует                                    */
void show_menu() {
	printf("\n");
	printf("1. Добавить данные из файла list.txt\n");
	printf("2. Смотреть список\n");
	printf("3. Сортировать список\n");
	printf("4. Отчистить список\n");
	printf("0. Выход\n");
	printf("Выберите операцию: \n");
}

/* Функция show_menu_struct                         */
/* Назначение:                                      */
/*   выводит на экран меню для выбора сортировки    */
/* Входные данные:                                  */
/*   отстутствуют                                   */
/* Выходные данные:                                 */
/*   отсутствуют                                    */
/* Возвращаемое значение:                           */
/*   отстуствует                                    */
void show_menu_struct() {
	printf("\n1. Отсортировать по полю type \n");
	printf("2. Отсортировать по полю space\n");
	printf("3. Отсортировать по полю price\n");
	printf("4. Отсортировать по полю avaible\n");
	printf("5. Отсортировать по полю view\n");
	printf("0. Выход\n");
	printf("Выберите операцию: \n");
}

/* Функция view                                     */
/* Назначение:                                      */
/*   выводит на экран все элементы списка           */
/* Входные данные:                                  */
/*   указатель на первый элемент списка             */
/* Выходные данные:                                 */
/*   отсутствуют                                    */
/* Возвращаемое значение:                           */
/*   отстуствует                                    */
void view(node** first) {

	node* temp = *first;

	int i = 0;

	do {
		printf("\nELEMENT #%d\n", i);
		printf("type =  %s\n", temp->type);
		printf("space =  %s\n", temp->space);
		printf("price =  %s\n", temp->price);
		printf("avaible =  %s\n", temp->avaible);
		printf("view =  %s\n", temp->view);
		temp = (temp->link);
		i++;
	} while (temp != NULL);
}

/* Функция swap                                     */
/* Назначение:                                      */
/*   меняет местами 2 указанных элемента списка     */
/* Входные данные:                                  */
/*   указатели на элементы                          */
/* Выходные данные:                                 */
/*   отсутствуют                                    */
/* Возвращаемое значение:                           */
/*   отстуствует                                    */
void swap(node* element_1, node* element_2) {

	// Запоминаем линки первого и второго элемента
	node* temp_link_1 = element_1->link;
	node* temp_link_2 = element_2->link;

	// Запоминаем содержимое второго элемента
	node temp = *element_2;

	// Меняем местами содержимое первого и второго элемента
	*element_2 = *element_1;
	*element_1 = temp;

	// Восстанавливаем исходные линки, так как они тоже поменялись
	element_1->link = temp_link_1;
	element_2->link = temp_link_2;
}

/* Функция check                                    */
/* Назначение:                                      */
/*   проверка стоят ли числа/строки по возрастанию  */
/* Входные данные:                                  */
/*   указатели на поля сравниваемых элементов       */
/* Выходные данные:                                 */
/*   отсутствуют                                    */
/* Возвращаемое значение:                           */
/*   1 - если числа/строки не по возрастанию        */
/*   0 - если числа/строки  по возрастанию          */
int check(char* string_1, char* string_2) {

	// Проверяем пришли строки или числа

	// Если пришли строки
	if (atoi(string_1) == 0) {

		// Посимвольно сравниваем их и проверяем стоят ли они по возрастанию
		if (strcmp(string_1, string_2) > 0) {

			// Если нет, то возвращаем 1
			return 1;
		}

		else return 0;
	}

	// Если пришли числа
	else {

		// Проверяем, стоят ли они по возрастанию
		if (atoi(string_1) > atoi(string_2)) {

			// Если нет, то возвращаем 1
			return 1;
		}

		else return 0;
	}
}

/* Функция list_sort                                */
/* Назначение:                                      */
/*   узнает по какому полю выполить сортировку      */
/* Входные данные:                                  */
/*   указатель на первый элемент списка             */
/* Выходные данные:                                 */
/*   отсутствуют                                    */
/* Возвращаемое значение:                           */
/*   отстуствует                                    */
void list_sort(node** first) {

	char string_of_chooses[SIZE];
	char* key = &string_of_chooses[0];

	node* prev_ptr = *first;
	node* next_ptr = prev_ptr->link;

	show_menu_struct();
	scanf_s("%s", string_of_chooses, SIZE);

	while (*key != '\0') {

		// Отвечает за количество полных обходов списка
		int j = 1;

		switch (*key) {

		case '0':
			return;
			break;

		case '1':

			// Дедаем полный обход списка столько раз, сколько необходимо
			while (j != 0) {

				for (;;) {

					// Если находим элементы, стоящие не по возрастанию, меняем их местами
					if (check(&(prev_ptr->type[0]), &(next_ptr->type[0])) == 1) {
						swap(prev_ptr, next_ptr);

						// Если поменяли эл-ы местами, значит нужно совершить проход списка минимум еще 1 раз
						j++;
					}

					// Двигаемся на шаг вперед
					next_ptr = next_ptr->link;
					prev_ptr = prev_ptr->link;

					// Если совершили обход списка, возвращаемся в начало и смотрим нужно ли пройти еще 1 раз
					if ((next_ptr == NULL)) {
						prev_ptr = *first;
						next_ptr = prev_ptr->link;
						j--;
						break;
					}
				}
			}

			break;

		case '2':
			while (j != 0) {
				for (;;) {
					if (check(&(prev_ptr->space[0]), &(next_ptr->space[0])) == 1) {
						swap(prev_ptr, next_ptr);
						j++;
					}
					next_ptr = next_ptr->link;
					prev_ptr = prev_ptr->link;
					if ((next_ptr == NULL)) {
						prev_ptr = *first;
						next_ptr = prev_ptr->link;
						j--;
						break;
					}
				}
			}
			break;

		case '3':
			while (j != 0) {
				for (;;) {
					if (check(&(prev_ptr->price[0]), &(next_ptr->price[0])) == 1) {
						swap(prev_ptr, next_ptr);
						j++;
					}
					next_ptr = next_ptr->link;
					prev_ptr = prev_ptr->link;
					if ((next_ptr == NULL)) {
						prev_ptr = *first;
						next_ptr = prev_ptr->link;
						j--;
						break;
					}
				}
			}
			break;

		case '4':
			while (j != 0) {
				for (;;) {
					if (check(&(prev_ptr->avaible[0]), &(next_ptr->avaible[0])) == 1) {
						swap(prev_ptr, next_ptr);
						j++;
					}
					next_ptr = next_ptr->link;
					prev_ptr = prev_ptr->link;
					if ((next_ptr == NULL)) {
						prev_ptr = *first;
						next_ptr = prev_ptr->link;
						j--;
						break;
					}
				}
			}
			break;

		case '5':
			while (j != 0) {
				for (;;) {
					if (check(&(prev_ptr->view[0]), &(next_ptr->view[0])) == 1) {
						swap(prev_ptr, next_ptr);
						j++;
					}
					next_ptr = next_ptr->link;
					prev_ptr = prev_ptr->link;
					if ((next_ptr == NULL)) {
						prev_ptr = *first;
						next_ptr = prev_ptr->link;
						j--;
						break;
					}
				}
			}
			break;

		default:
			printf("\n");
			printf("Такой операции не существует.");
			break;
		}
		key++;
	}

	printf("\nСортировка по указанным полям выполнена!\n");

}

/* Функция add_list                                 */
/* Назначение:                                      */
/*   добавляет данные в список из файла list.txt    */
/* Входные данные:                                  */
/*   указатель на первый элемент списка             */
/*   указатель на файл list.txt                     */
/* Выходные данные:                                 */
/*   отсутствуют                                    */
/* Возвращаемое значение:                           */
/*   1 - если данные были добавленны                */
/*   2 - если данные не были добавленны             */
int add_list(node** first, FILE* f) {

	node* new_node = (node*)malloc(sizeof(node));
	new_node->link = NULL;
	node* ptr = *first;
	node* temp = ptr;

	if (*first == NULL) {
		*first = new_node;
	}

	else {
		while (ptr->link != NULL) {
			ptr = ptr->link;
			temp = ptr;
		}
		ptr->link = new_node;
	}

	if (fscanf_s(f, "%s", new_node->type, 255) != EOF) {
		fscanf_s(f, "%s", new_node->space, 255);
		fscanf_s(f, "%s", new_node->price, 255);
		fscanf_s(f, "%s", new_node->avaible, 255);
		fscanf_s(f, "%s", new_node->view, 255);
		return 1;
	}

	else {
		temp->link = NULL;
		free(new_node);
		return 0;
	}
}

/* Функция list_clear                               */
/* Назначение:                                      */
/*  удаляет все элементы списка                     */
/* Входные данные:                                  */
/*   указатель на первый элемент списка             */
/* Выходные данные:                                 */
/*   отсутствуют                                    */
/* Возвращаемое значение:                           */
/*   отстуствует                                    */
void list_clear(node** first) {

	node* temp = *first;
	node* ptr = *first;

	while (ptr->link != NULL) {
		temp = ptr;
		ptr = ptr->link;
		free(temp);
	}

	*first = NULL;
}

/* Основная функиця                                  */
/* Входные данные:                                   */
/*   отсутствуют                                     */
/* Выходные данные:                                  */
/*   отсутствуют                                     */
int main() {

	setlocale(LC_ALL, ".1251");
	errno_t err;
	int key;
	FILE* f;
	node* first = NULL;

	do {
		show_menu();
		scanf_s("%d", &key);

		switch (key) {

		case 0:
			break;

		case 1:
			err = fopen_s(&f, "list.txt", "r");
			while (add_list(&first, f) != 0);
			err = fclose(f);
			printf("\nДанные добавлены в список!\n");
			break;

		case 2:
			if (first != NULL) {
				printf("\nПросмотр списка:\n");
				view(&first);
			}
			else {
				printf("\nCписок пуст!\n");
			}
			break;

		case 3:
			if (first != NULL) {
				list_sort(&first);
			}
			else {
				printf("\nCписок пуст!\n");
			}
			break;

		case 4:
			if (first != NULL) {
				list_clear(&first);
				printf("\nСписок отчищен!\n");
			}
			else {
				printf("\nCписок пуст!\n");
			}
			break;

		default:
			printf("\nТакой операции не существует.\n");
			break;
		}
	} while (key != 0);

	return 0;
}


