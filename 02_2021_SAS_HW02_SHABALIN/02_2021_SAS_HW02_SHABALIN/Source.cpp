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

/* ������� show_menu                                */
/* ����������:                                      */
/*   ������� �� ����� ���� ��� ������ � ����������  */
/* ������� ������:                                  */
/*   ������������                                   */
/* �������� ������:                                 */
/*   �����������                                    */
/* ������������ ��������:                           */
/*   �����������                                    */
void show_menu() {
	printf("\n");
	printf("1. �������� ������ �� ����� list.txt\n");
	printf("2. �������� ������\n");
	printf("3. ����������� ������\n");
	printf("4. ��������� ������\n");
	printf("0. �����\n");
	printf("�������� ��������: \n");
}

/* ������� show_menu_struct                         */
/* ����������:                                      */
/*   ������� �� ����� ���� ��� ������ ����������    */
/* ������� ������:                                  */
/*   ������������                                   */
/* �������� ������:                                 */
/*   �����������                                    */
/* ������������ ��������:                           */
/*   �����������                                    */
void show_menu_struct() {
	printf("\n1. ������������� �� ���� type \n");
	printf("2. ������������� �� ���� space\n");
	printf("3. ������������� �� ���� price\n");
	printf("4. ������������� �� ���� avaible\n");
	printf("5. ������������� �� ���� view\n");
	printf("0. �����\n");
	printf("�������� ��������: \n");
}

/* ������� view                                     */
/* ����������:                                      */
/*   ������� �� ����� ��� �������� ������           */
/* ������� ������:                                  */
/*   ��������� �� ������ ������� ������             */
/* �������� ������:                                 */
/*   �����������                                    */
/* ������������ ��������:                           */
/*   �����������                                    */
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

/* ������� swap                                     */
/* ����������:                                      */
/*   ������ ������� 2 ��������� �������� ������     */
/* ������� ������:                                  */
/*   ��������� �� ��������                          */
/* �������� ������:                                 */
/*   �����������                                    */
/* ������������ ��������:                           */
/*   �����������                                    */
void swap(node* element_1, node* element_2) {

	// ���������� ����� ������� � ������� ��������
	node* temp_link_1 = element_1->link;
	node* temp_link_2 = element_2->link;

	// ���������� ���������� ������� ��������
	node temp = *element_2;

	// ������ ������� ���������� ������� � ������� ��������
	*element_2 = *element_1;
	*element_1 = temp;

	// ��������������� �������� �����, ��� ��� ��� ���� ����������
	element_1->link = temp_link_1;
	element_2->link = temp_link_2;
}

/* ������� check                                    */
/* ����������:                                      */
/*   �������� ����� �� �����/������ �� �����������  */
/* ������� ������:                                  */
/*   ��������� �� ���� ������������ ���������       */
/* �������� ������:                                 */
/*   �����������                                    */
/* ������������ ��������:                           */
/*   1 - ���� �����/������ �� �� �����������        */
/*   0 - ���� �����/������  �� �����������          */
int check(char* string_1, char* string_2) {

	// ��������� ������ ������ ��� �����

	// ���� ������ ������
	if (atoi(string_1) == 0) {

		// ����������� ���������� �� � ��������� ����� �� ��� �� �����������
		if (strcmp(string_1, string_2) > 0) {

			// ���� ���, �� ���������� 1
			return 1;
		}

		else return 0;
	}

	// ���� ������ �����
	else {

		// ���������, ����� �� ��� �� �����������
		if (atoi(string_1) > atoi(string_2)) {

			// ���� ���, �� ���������� 1
			return 1;
		}

		else return 0;
	}
}

/* ������� list_sort                                */
/* ����������:                                      */
/*   ������ �� ������ ���� �������� ����������      */
/* ������� ������:                                  */
/*   ��������� �� ������ ������� ������             */
/* �������� ������:                                 */
/*   �����������                                    */
/* ������������ ��������:                           */
/*   �����������                                    */
void list_sort(node** first) {

	char string_of_chooses[SIZE];
	char* key = &string_of_chooses[0];

	node* prev_ptr = *first;
	node* next_ptr = prev_ptr->link;

	show_menu_struct();
	scanf_s("%s", string_of_chooses, SIZE);

	while (*key != '\0') {

		// �������� �� ���������� ������ ������� ������
		int j = 1;

		switch (*key) {

		case '0':
			return;
			break;

		case '1':

			// ������ ������ ����� ������ ������� ���, ������� ����������
			while (j != 0) {

				for (;;) {

					// ���� ������� ��������, ������� �� �� �����������, ������ �� �������
					if (check(&(prev_ptr->type[0]), &(next_ptr->type[0])) == 1) {
						swap(prev_ptr, next_ptr);

						// ���� �������� ��-� �������, ������ ����� ��������� ������ ������ ������� ��� 1 ���
						j++;
					}

					// ��������� �� ��� ������
					next_ptr = next_ptr->link;
					prev_ptr = prev_ptr->link;

					// ���� ��������� ����� ������, ������������ � ������ � ������� ����� �� ������ ��� 1 ���
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
			printf("����� �������� �� ����������.");
			break;
		}
		key++;
	}

	printf("\n���������� �� ��������� ����� ���������!\n");

}

/* ������� add_list                                 */
/* ����������:                                      */
/*   ��������� ������ � ������ �� ����� list.txt    */
/* ������� ������:                                  */
/*   ��������� �� ������ ������� ������             */
/*   ��������� �� ���� list.txt                     */
/* �������� ������:                                 */
/*   �����������                                    */
/* ������������ ��������:                           */
/*   1 - ���� ������ ���� ����������                */
/*   2 - ���� ������ �� ���� ����������             */
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

/* ������� list_clear                               */
/* ����������:                                      */
/*  ������� ��� �������� ������                     */
/* ������� ������:                                  */
/*   ��������� �� ������ ������� ������             */
/* �������� ������:                                 */
/*   �����������                                    */
/* ������������ ��������:                           */
/*   �����������                                    */
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

/* �������� �������                                  */
/* ������� ������:                                   */
/*   �����������                                     */
/* �������� ������:                                  */
/*   �����������                                     */
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
			printf("\n������ ��������� � ������!\n");
			break;

		case 2:
			if (first != NULL) {
				printf("\n�������� ������:\n");
				view(&first);
			}
			else {
				printf("\nC����� ����!\n");
			}
			break;

		case 3:
			if (first != NULL) {
				list_sort(&first);
			}
			else {
				printf("\nC����� ����!\n");
			}
			break;

		case 4:
			if (first != NULL) {
				list_clear(&first);
				printf("\n������ �������!\n");
			}
			else {
				printf("\nC����� ����!\n");
			}
			break;

		default:
			printf("\n����� �������� �� ����������.\n");
			break;
		}
	} while (key != 0);

	return 0;
}


