#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//********************STRUCTS************************
struct date_exp
{
	int day;
	int mounth;
	int year;
};
struct pro
{
	char name[100];
	long int id;
	char comp[100];
	int price;
	struct date_exp date;
} trash;
struct pro *tepo;
FILE *Trash;
FILE *fp;

//*******************FUNCTIONS*******************

void print_pro(void);
void input(void);
void delete_pro(void);
void search_pro(void);
void temp_delete(void);
int menu_select(void);
void menu_del(void);
void recover(void);
void update_pro(void);
void sort(void);
void sng_print(struct pro);
int com(void);
int com_del(void);
void pause_t(void);
void clearScreen();
void about_us();

//********************MAIN**********************

int main()
{
	char choice;
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("$$$$$$$$$-->>WELCOME TO DIAMOND MARKET<<--$$$$$$$$$\n");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	while (1)
	{
		choice = menu_select();
		switch (choice)
		{
		case 1:
			clearScreen();
			input();
			pause_t();
			break;
		case 2:
			clearScreen();
			print_pro();
			pause_t();
			break;
		case 3:
			clearScreen();
			update_pro();
			pause_t();
			break;
		case 4:
			clearScreen();
			sort();
			pause_t();
			break;
		case 5:
			clearScreen();
			search_pro();
			pause_t();
			break;
		case 6:
			clearScreen();
			menu_del();
			pause_t();
			break;
		case 7:
			clearScreen();
			recover();
			pause_t();
			break;
		case 8:
			clearScreen();
			about_us();
			pause_t();
			break;
		case 9:
			printf("\n*** Thanks for using the program! Goodbye. ***");
			exit(0);
			break;
		}
	}
	return 0;
}

//*******************MENU************************

int menu_select(void)
{
	char s[10];
	int n;
	do
	{
		printf("***Enter Your Choice Number: \n");
		printf("   >>1. Add New Product\n");
		printf("   >>2. Show The Entire List Of Products\n");
		printf("   >>3. Edit Product's Detail\n");
		printf("   >>4. Sorting The Product's List\n");
		printf("   >>5. Search In Product\n");
		printf("   >>6. Delete Product's Information\n");
		printf("   >>7. Recovering Deleted Product\n");
		printf("   >>8. About Us\n");
		printf("   >>9. Exit From  Program\n");
		scanf("%s", s);
		n = atoi(s);
		if (n < 1 || n > 9)
		{
			clearScreen();
			printf("The Value You Entered Is Invalid.\n");
			printf("**************************************\n");
			printf("Please Try Again.\n\n");
		}
	} while (n < 1 || n > 9);
	return n;
}
//*********************PAUSE*********************

void pause_t(void)
{
	printf("Press Enter To Continue...\n");
	scanf("%*c"
		  "%*c");
	clearScreen();
}

//***********************INPUT**************************

void input(void)
{
	char c[10];
	int n, i;
	printf("****************\n");
	printf("How Many Product's Info Do You Want To Add: \n");
	scanf("%s", c);
	n = atoi(c);
	tepo = (struct pro *)malloc(n * sizeof(struct pro));
	for (i = 0; i < n; i++)
	{

		printf("** Information Of %dth Product **\n", i + 1);
		printf("Enter the product's name: \n");
		scanf("%*c%[^\n]", tepo[i].name); //gets
		printf("Enter Identify Code for The Product: \n");
		scanf("%ld", &tepo[i].id);
		printf("Enter The Company's Name: \n");
		scanf("%*c%[^\n]", tepo[i].comp); //gets
		printf("Enter The Expire Date Of Product: (YYYY MM DD)\n");
		scanf("%d%d%d", &tepo[i].date.year, &tepo[i].date.mounth, &tepo[i].date.day);
		printf("Enter The Product's Price: \n");
		scanf("%d", &tepo[i].price);
	}
	fp = fopen("info.bin", "ab");
	fwrite(tepo, sizeof(struct pro), n, fp);
	fclose(fp);
	free(tepo);
}
//**************CLEAR SCREEN**********************

void clearScreen()
{
	//const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
	//write(STDOUT_FILENO,CLEAR_SCREE_ANSI,12);
	printf("\033[2J\033[1;1H");
}

//**********************COMFUNC********************
int com(void)
{
	int n;
	struct stat st;
	stat("info.bin", &st);
	n = st.st_size / sizeof(struct pro);
	tepo = (struct pro *)malloc(n * sizeof(struct pro));
	fp = fopen("info.bin", "rb");
	if (fp == NULL)
	{
		printf("There Is No Data\n");
		return 0;
	}
	fread(tepo, sizeof(struct pro), n, fp);
	fclose(fp);
	return n;
}

//********************COM-DEL**********************

int com_del(void)
{
	int n;
	struct stat st;
	stat("trash.bin", &st);
	n = st.st_size / sizeof(struct pro);
	tepo = (struct pro *)malloc(n * sizeof(struct pro));
	Trash = fopen("trash.bin", "rb");
	if (Trash == NULL)
	{
		return 0;
	}
	fread(tepo, sizeof(struct pro), n, Trash);
	fclose(Trash);
	return n;
}

//*******************SINGLE PRINT******************

void sng_print(struct pro good)
{
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("**The Product Name Is : %s\n", good.name);
	printf("**The Company Of The Product Is: %s\n", good.comp);
	printf("**The Product's ID Is: %ld\n", good.id);
	printf("**The Price Of The Product Is: %d\n", good.price);
	printf("**The Expire Date Of The Product Is: %d/%d/%d\n", good.date.year, good.date.mounth, good.date.day);
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||\n");
}

//***********************SEARCH********************

void search_pro(void)
{
	char c[100];
	int n, j, p, q, i, found = 0;
	long int s;
	char se[100];
	int h = com(); //tedad info mojud
	if (h != 0)
	{
		do
		{
			printf("***Enter your choice.\n");
			printf(">>>1.Search By Product's Name\n");
			printf(">>>2.Search By Company's Name\n");
			printf(">>>3.Search By Product's Id Number\n");
			scanf("%s", c);
			n = atoi(c);
			if (n < 1 || n > 3)
			{
				printf("It Is Invalid.\n\n");
				printf("Please Try Again\n");
			}
		} while (n < 1 || n > 3);
		if (n == 1)
		{
			printf("Enter Product's Name: \n");
			scanf("%*c%[^\n]", se);
			for (p = 0; se[p] != 0; p++)
				; //tool reshte kalame karbar
			for (j = 0; j < h; j++)
			{
				for (q = 0; tepo[j].name[q] != 0; q++)
					;
				if (q == p)
				{
					for (i = 0; i < q + 1; i++)
					{
						if (se[i] != tepo[j].name[i])
						{
							break; //yaft nashod
						}
						if (se[i] == 0 && tepo[j].name[i] == 0)
						{
							printf("**The Product Is Found:  \n");
							sng_print(tepo[j]);
							found = 1;
						}
					}
				}
			}
			if (found == 0)
			{
				printf("Not Found\n");
			}
		}

		else if (n == 2)
		{
			printf("Enter company's name: \n");
			scanf("%*c%[^\n]", se);
			for (p = 0; se[p] != 0; p++)
				; //tool reshte kalame karbar
			for (j = 0; j < h; j++)
			{
				for (q = 0; tepo[j].comp[q] != 0; q++)
					;
				if (q == p)
				{
					for (i = 0; i < q + 1; i++)
					{
						if (se[i] != tepo[j].comp[i])
						{
							break;
						}
						if (se[i] == 0 && tepo[j].comp[i] == 0)
						{
							printf("This Product Has Been Found: \n");
							sng_print(tepo[j]);
							found = 1;
						}
					}
				}
			}
			if (found == 0)
			{
				printf("Not Found\n");
			}
		}

		else if (n == 3)
		{
			printf("Enter Product's Id: \n");
			scanf("%ld", &s);
			for (i = 0; i < h; i++)
			{
				if (s == tepo[i].id)
				{
					printf("**The Product Is Found:  \n");
					sng_print(tepo[i]);
					found = 1;
				}
			}
			if (found == 0)
			{
				printf("Not Found\n");
			}
		}
	}
	free(tepo);
}
//*******************PRINT_PRO***************
void print_pro(void)
{
	int i;
	int h = com();
	printf("\n>>There Are %d Products In The Market<<\n", h);
	for (i = 0; i < h; i++)
	{
		sng_print(tepo[i]); //age product nabood
	}
	free(tepo);
}

//***************SORT****************************
void sort(void)
{
	int h = com();
	char c[10];
	int n, i, j;
	struct pro temp;
	if (h != 0)
	{
		do
		{
			printf(">>>1.Srot By Ascending Order\n");
			printf(">>>2.Sort By Descending Order\n");
			scanf("%s", c);
			n = atoi(c);
			if (n < 1 || n > 2)
			{
				printf("The Value You Entered Is Invalid.\nPlease Try Again\n");
			}
		} while (n < 1 || n > 2);
		if (n == 1)
		{

			for (j = 1; j < h; j++)
			{
				i = j;
				while (i > 0 && tepo[i - 1].price > tepo[i].price)
				{
					temp = tepo[i];
					tepo[i] = tepo[i - 1];
					tepo[i - 1] = temp;
					i--;
				}
			}
			printf("-->Products Are Sorted By Ascending Order.<--\n");
		}
		if (n == 2)
		{
			for (i = 0; i < h; i++)
			{
				for (j = i + 1; j < h; j++)
				{
					if (tepo[i].price < tepo[j].price)
					{
						temp = tepo[i];
						tepo[i] = tepo[j];
						tepo[j] = temp;
					}
				}
			}
			printf("-->Products Are Sorted By Descending Order.<--\n");
		}
		fp = fopen("info.bin", "wb");
		fwrite(tepo, sizeof(struct pro), h, fp);
		fclose(fp);
	}
	free(tepo);
}
//**********************DELETE-COMPLETE***************
void delete_pro(void)
{
	int h = com(), i, j, f = 0;
	long int s;
	if (h != 0)
	{
		printf("Enter Product's Id: \n");
		scanf("%ld", &s);
		for (i = 0; i < h; i++)
		{
			if (s == tepo[i].id)
			{
				printf("This Product Is Deleted\n");
				f = 1;
				for (j = i; j < h - 1; j++)
				{
					tepo[j] = tepo[j + 1];
				}
			}
		}
		if (f == 1)
		{
			fp = fopen("info.bin", "wb");
			fwrite(tepo, sizeof(struct pro), h - 1, fp);
			fclose(fp);
		}
		if (f == 0)
		{
			printf("Not Found\n");
		}
	}
	free(tepo);
}

//*******************TEMP-DELETE*****************

void temp_delete(void)
{
	int h = com(), i, j, f = 0;
	long int s;
	if (h != 0)
	{
		printf("Enter Product's Id: \n");
		scanf("%ld", &s);
		for (i = 0; i < h; i++)
		{
			if (s == tepo[i].id)
			{
				printf("This Product Is Deleted\n");
				f = 1;
				trash = tepo[i];
				for (j = i; j < h - 1; j++)
				{
					tepo[j] = tepo[j + 1];
				}
			}
		}
		if (f == 1)
		{
			fp = fopen("info.bin", "wb");
			fwrite(tepo, sizeof(struct pro), h - 1, fp);
			fclose(fp);
			Trash = fopen("trash.bin", "ab");
			fwrite(&trash, sizeof(struct pro), 1, Trash);
			fclose(Trash);
		}
		if (f == 0)
		{
			printf("Not Found\n");
		}
	}
	free(tepo);
}

//******************MENU-DELETE************
void menu_del(void)
{
	char num_del[10];
	int dc;
	do
	{
		printf("Do You Want To Delete Temprory or Parmanent: \n");
		printf("1.Temprory\n");
		printf("2.Parmanently\n");
		printf("3.Delet All Data\n");
		scanf("%s", num_del);
		dc = atoi(num_del);
		if (dc == 1)
		{
			temp_delete();
		}
		else if (dc == 2)
		{
			delete_pro();
		}
		else if (dc == 3)
		{
			remove("info.bin");
		}
		else
		{
			printf("The Value You Entered Is Invalid.\n");
		}
	} while (dc > 3 || dc < 1);
}

//****************UPDATE***************
void update_pro(void)
{
	long int s;
	int f = 0, i;
	int h = com();
	if (h != 0)
	{
		printf("Enter Product's Id: \n");
		scanf("%ld", &s);
		for (i = 0; i < h; i++)
		{
			if (s == tepo[i].id)
			{
				printf("The Product You Want To Change Is: \n");
				sng_print(tepo[i]);
				printf("Enter New Information For This Product: \n");
				printf("Enter The Product's Name: \n");
				scanf("%*c%[^\n]", tepo[i].name); //gets
				printf("Enter Identify Code For The Product: \n");
				scanf("%ld", &tepo[i].id);
				printf("Enter The Company's Name: \n");
				scanf("%*c%[^\n]", tepo[i].comp); //gets
				printf("Enter The Expire's Date Of Product: (yyyy mm dd)\n");
				scanf("%d%d%d", &tepo[i].date.year, &tepo[i].date.mounth, &tepo[i].date.day);
				printf("Enter The Product's Price: \n");
				scanf("%d", &tepo[i].price);
				f = 1;
			}
		}
		if (f == 1)
		{
			fp = fopen("info.bin", "wb");
			fwrite(tepo, sizeof(struct pro), h, fp);
			fclose(fp);
		}
		if (f == 0)
		{
			printf("Not Found\n");
		}
	}
	free(tepo);
}

//******************RECOVER******************
void recover(void)
{
	int l = com_del();
	if (l != 0)
	{
		fp = fopen("info.bin", "ab");
		fwrite(tepo, sizeof(struct pro), l, fp);
		fclose(fp);
		remove("trash.bin");
		printf("%d Product Is Recovered\n", l);
		free(tepo);
	}
	else if (l == 0)
	{
		printf("Trash Is Empty\n");
	}
}
//*********************ABOUT US*****************
void about_us()
{
	printf("**********************************\n");
	printf("*         Produced By:           *\n");
	printf("*   SEYED ALI MIR AMIR KHANI     *\n");
	printf("*         FARID LOTFALI          *\n");
	printf("**********************************\n");
	printf("*    Project Completion Date     *\n");
	printf("*           94/10/27             *\n");
	printf("**********************************\n\n\n\n");
}
