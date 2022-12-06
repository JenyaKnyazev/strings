#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int check_greater(char a[], char b[]) {
	int i=0;
	while (a[i] != ' ' && b[i] != ' ' && a[i] && b[i]) {
		if (a[i] > b[i])
			return 1;
		if (b[i] > a[i])
			return 0;
		i++;
	}
	if (a[i] == ' ' || !a[i])
		return 0;
	if (b[i] == ' ' || !b[i])
		return 1;
	return 0;
}
void input(char p[]) {
	char ch;
	int i=0;
	while ( (ch = getchar()) != '\n' ) {
		p[i] = ch;
		if (ch == ' ' && p[i-1] == ' ')
			i--;
		i++;
	}
	p[i] = 0;
}
void revSent(char p[]) {
	char arr[31];
	int i, j,k,m=0;
	for (j = 0; p[j]; j++);
	j--;
	while (j >= 0) {
		i = j;
		while (j>=0&&p[j] != ' ')j--;
		for (k = j + 1; k <= i; k++)
			arr[m++] = p[k];
		arr[m++] = ' ';
		j--;
	}
	arr[m - 1] = 0;
	for (j = 0; arr[j]; j++)
		p[j] = arr[j];
	p[j] = 0;
}
void rorSent(char p[], int n) {
	int i,j,k;
	char arr[31];
	for (j = 0; p[j]; j++);
	j--;
	while (n) {
		if (p[j] == ' ')
			j--;
		while (p[j] != ' ')j--;
		n--;
	}
	for (k = 0, i = j + 1; p[i]; i++, k++)
		arr[k] = p[i];
	arr[k++] = ' ';
	for (i = 0; i < j; i++)
		arr[k++] = p[i];
	arr[k] = 0;
	for (i = 0; arr[i]; i++)
		p[i] = arr[i];
	p[i] = 0;
}
void rolSent(char p[], int n) {
	int i, j=0, k;
	char arr[31];
	while (n) {
		if (p[j] == ' ')
			j++;
		while (p[j] != ' ')j++;
		n--;
	}
	for (i = j + 1, k = 0; p[i]; i++, k++)
		arr[k] = p[i];
	arr[k++] = ' ';
	for (i = 0; i < j; i++)
		arr[k++] = p[i];
	arr[k] = 0;
	for (i = 0; arr[i]; i++)
		p[i] = arr[i];
	p[i] = 0;
}
void sort_asc(char p[]) {
	int i=0, j, k;
	while (1) {
		j = i;
		while (p[j]&&p[j++] != ' ');
		if (!p[j])
			break;
		if (check_greater(p + i, p + j))
			rolSent(p + i, 1);
		else
			i = j;
	}
}
void sort_des(char p[]) {
	sort_asc(p);
	revSent(p);
}
void search(char p[], char word[]) {
	int i=0,j,count=0,is_found=0;
	while (p[i]) {
		j = 0;
		while (p[i] == word[j] && p[i]) {
			i++;
			j++;
		}
		count++;
		if (!word[j]) {
			is_found = 1;
			break;
		}
		while (p[i] != ' ' && p[i])
			i++;
		if (p[i] == ' ')
			i++;
	}
	if (is_found)
		printf("The word %s is placed in the %d place.\n", word, count);
	else
		printf("The word %s is not found.\n", word);
}
void count_words(char p[]) {
	int i, count;
	for (i = count = 0; p[i]; i++)
		if (p[i] == ' ')
			count++;
	printf("The number of words in the sentence is %d.\n", count + 1);
}
void subSent(char str[], int k) {
	char arr[31];
	char word[31];
	char word2[31];
	int i, j,m,x,y,z,is_new;
	for (j = i = 0; str[i]; i++)
		if (str[i] != ' ')
			arr[j++] = str[i];
	for (i = 0; i <= j - k; i++) {
		is_new = 1;
		for (x = 0, m = i; m < i + k; m++)
			word[x++] = arr[m];
		word[x] = 0;
		for (m = 0; m <= i-k; m++) {
			z = 0;
			for (y = m; y < m + k; y++)
				word2[z++] = arr[y];
			word2[z] = 0;
			if (strcmp(word, word2) == 0) {
				is_new = 0;
				break;
			}
		}
		if (is_new)
			puts(word);
	}
}
void printMenu() {
	printf("******** Main menu ********\n\n");
	puts("1 : Input the sentence");
	puts("2 : Print the sentence");
	puts("3: Reverse the sentence");
	puts("4 : Rotate left N");
	puts("5 : Rotate right N");
	puts("6 : Sort the sentence");
	puts("7 : Search the word");
	puts("8 : Count number of words");
	puts("9 : Display substring M");
	puts("10 :Quit");
	printf("\n\n****************************\n");
}
void print_ask() {
	printf("Please, enter your choice >");
}
int check_chars(char str[]) {
	int i;
	for (i = 0; str[i]; i++)
		if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] == ' '))
			return 0;
	return 1;
}
int maxWordLength(char str[]) {
	int i=0, count = 0,count2;
	while (str[i]) {
		count2 = 0;
		while (str[i] != ' ' && str[i]) {
			i++;
			count2++;
		}
		if (count2 > count)
			count = count2;
		if (str[i])
			i++;
	}
	return count;
}
int countWords(char p[]) {
	int i, count;
	for (i = count = 0; p[i]; i++)
		if (p[i] == ' ')
			count++;
	return count + 1;
}
void clean_buff() {
	while (getchar() != '\n');
}
void game() {
	char sentence[31],word[31];
	int choise,k,is_empty=1,correct;
	do {
		printMenu();
		print_ask();
		choise = 1;
		do {
			if (choise > 10 || choise < 1) {
				printf("ERROR: Incorrect command, try again.\n");
				print_ask();
			}
			scanf("%d", &choise);
		} while (choise > 10 || choise < 1);
		if (is_empty && choise >= 2 && choise <= 9) {
			printf("ERROR: The sentence is empty.");
			continue;
		}
		if (choise == 1)
			clean_buff();
		switch (choise) {
			case 1:
				correct = 1;
				do {
					if (!correct)
						printf("ERROR: Incorrect data, try again.\n");
					printf("Please, enter your sentence >");
					input(sentence);
				} while ((correct=check_chars(sentence)) == 0);
				is_empty = 0;
				break;
			case 2:
				puts(sentence);
				break;
			case 3:
				revSent(sentence);
				puts(sentence);
				break;
			case 4:
				scanf("%d", &k);
				if (k > countWords(sentence))
					printf("ERROR: Incorrect command, try again.\n");
				else {
					if (k < countWords(sentence))
						rolSent(sentence, k);
					puts(sentence);
				}
				clean_buff();
				break;
			case 5:
				scanf("%d", &k);
				if (k > countWords(sentence))
					printf("ERROR: Incorrect command, try again.\n");
				else {
					if (k < countWords(sentence))
						rorSent(sentence, k);
					puts(sentence);
				}
				clean_buff();
				break;
			case 6:
				getchar();
				k = getchar();
				if ((char)k == 'a' || (char)k == 'A') {
					sort_asc(sentence);
					puts(sentence);
				}else if ((char)k == 'd' || (char)k == 'D') {
					sort_des(sentence);
					puts(sentence);
				}else
					printf("ERROR: Incorrect command, try again.\n");
				clean_buff();
				break;
			case 7:
				gets(word);
				search(sentence, word);
				break;
			case 8:
				count_words(sentence);
				break;
			case 9:
				scanf("%d", &k);
				if (k > maxWordLength(sentence) || k < 1)
					printf("ERROR: Incorrect command, try again.\n");
				else
					subSent(sentence,k);
				clean_buff();
				break;
		}
	} while (choise != 10);
}
int main() {
	game();
	return 0;
}