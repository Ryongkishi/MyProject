#include<iostream>
#include<string.h>
#include<vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
struct numberWord
{
	int num = 0;
	char word;
};
struct word {
	char name[30];
	int num;
	struct word *next;
	struct word *children;
};
bool cmp(numberWord a, numberWord b)
{
	return a.num > b.num;
}
void numberoftheword(char *txt)
{
	FILE *fp;
	
	if ((fp = fopen(txt, "r")) == NULL)
	{
		printf("无法打开此文件!\n");
		exit(0);
	}
	int sum = 0;
	numberWord a[26];
	char ch;
	while (!feof(fp))
	{
		
		ch = fgetc(fp);
		if (ch >= 'a'&&ch <= 'z')
		{
			a[ch - 'a'].num++;
			a[ch - 'a'].word = ch;

		}
		if (ch >= 'A'&&ch <= 'Z')
		{
			a[ch - 'A'].num++;
			//a[ch - 'a'].word = ch;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		sum += a[i].num;
	}
	sort(a, a + 26, cmp);
	cout << "各个单词的频率如下：（不区分大小写）" << endl;
	//cout << sum << endl;
	for (int i = 0; i < 26; i++)
	{

		if (a[i].word >= 'a'&& a[i].word <= 'z')
		{
			cout << a[i].word << ' '<< setprecision(2) << 1.00*a[i].num / sum<<endl;
			//printf("%d\n", a[i].word);//,(float)1.0*a[i].num / sum
		}


		
	}
}
int readfileLimtiedby(struct word*&head, char *txt,int Lim_num)
{
	FILE *fp;
	if ((fp = fopen(txt, "r")) == NULL)
	{
		printf("无法打开此文件!\n");
		exit(0);
	}
	char ch, temp[30];
	int numofWord = 0;
	struct word *p;
	while (!feof(fp))
	{
		int i = 0;
		ch = fgetc(fp);
		temp[0] = ' ';
		while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || temp[0] == ' ')
		{
			if (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z')
			{
				temp[i] = ch;
				i++;
			}
			ch = fgetc(fp);
			if (feof(fp)) break;
		}
		temp[i] = '\0';
		int flag = 1;
		p = head->next;
		while (p)
		{
			if (!_stricmp(temp, p->name))
			{
				p->num++; break;
			}

			p = p->next;
		}
		if (strlen(temp) == Lim_num)
		{
			flag = 0;
		}
		if (!p&&temp[0] != '\0'&&flag)
		{
			p = new word;
			strcpy(p->name, temp);
			p->num = 1;
			p->next = head->next;
			head->next = p;
			numofWord++;
		}
	}
	return numofWord;
}
int readfile(struct word*&head,char *txt)
{
	FILE *fp;
	if ((fp = fopen(txt, "r")) == NULL)
	{
		printf("无法打开此文件!\n");
		exit(0);
	}
	char ch, temp[30];
	int numofWord = 0;
	struct word *p;
	while (!feof(fp))
	{
		int i = 0;
		ch = fgetc(fp);
		temp[0] = ' ';
		while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || temp[0] == ' ')
		{
			if (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z')
			{
				temp[i] = ch;
				i++;
			}
			ch = fgetc(fp);
			if (feof(fp)) break;
		}
		temp[i] = '\0';

		p = head->next;
		while (p)
		{
			if (!_stricmp(temp, p->name))
			{
				p->num++; break;
			}

			p = p->next;
		}
		if (!p&&temp[0] != '\0')
		{
			p = new word;
			strcpy(p->name, temp);
			p->num = 1;
			p->next = head->next;
			head->next = p;
			numofWord++;
		}
	}
	return numofWord;
}
int Vreadfile(struct word*&head, char *txt)
{
	FILE *fp;
	if ((fp = fopen(txt, "r")) == NULL)
	{
		printf("无法打开此文件!\n");
		exit(0);
	}
	char ch, temp[30];
	int numofWord = 0;
	struct word *p;
	while (!feof(fp))
	{
		int i = 0;
		ch = fgetc(fp);
		temp[0] = ' ';
		if (temp[i] == '\n')
		{
			p = new word;
			p->children = head->children;
			head->children = p;
		}
		while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || temp[0] == ' ')
		{
			if (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z')
			{
				temp[i] = ch;
				i++;
			}
			ch = fgetc(fp);
			if (feof(fp)) break;
		}
		temp[i] = '\0';

		p = head->next;
		while (p)
		{
			if (!_stricmp(temp, p->name))
			{
				p->num++; break;
			}

			p = p->next;
		}
		if (!p&&temp[0] != '\0')
		{
			p = new word;
			strcpy(p->name, temp);
			p->num = 1;
			p->next = head->next;
			head->next = p;
			numofWord++;
		}
	}
	return numofWord;
}
int stopreadfile(struct word*&head, char *txt, struct word*&stophead)
{
	FILE *fp;
	if ((fp = fopen(txt, "r")) == NULL)
	{
		printf("无法打开此文件!\n");
		exit(0);
	}
	char ch, temp[30];
	int numofWord = 0;
	struct word *p,*stop_p;
	while (!feof(fp))
	{
		int i = 0;
		ch = fgetc(fp);
		temp[0] = ' ';
		while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || temp[0] == ' ')
		{
			if (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z')
			{
				temp[i] = ch;
				i++;
			}
			ch = fgetc(fp);
			if (feof(fp)) break;
		}
		temp[i] = '\0';
		p = head->next;
		stop_p = stophead->next;
		while (p)
		{
			if (!_stricmp(temp, p->name))
			{
				p->num++; break;
			}

			p = p->next;
		}
		int flag = 1;
		while (stop_p)
		{
			if (_stricmp(stop_p->name, temp))
			{
				flag = 0;
			}

				stop_p = stop_p->next;
		}
		if (!p&&temp[0] != '\0&&'&&flag)
		{
			p = new word;
			strcpy(p->name, temp);
			p->num = 1;
			p->next = head->next;
			head->next = p;
			numofWord++;
		}
	}
	return numofWord;
}
void sort1(struct word*&head,int n)
{
	struct word *q;
	int a[26], i;
	
	for (i = 0; i<n; i++)
		a[i] = 0;
	printf("文章中出现频率最高的%d个单词如下:\n",n);
	for (i = 0; i<n; i++)
	{
		q = head;
		while (q != NULL)
		{
			if (q->num>a[i])
				a[i] = q->num;
			else
				q = q->next;
		}
		q = head;
		while (q != NULL)
		{
			if (a[i] == q->num)
			{
				q->num = 0;
				printf("出现频率:%d\t", a[i]);
				puts(q->name);
				break;
			}
			else
				q = q->next;
		}
	}
}

int main(int   argc, char*   argv[])
{
	struct word *head,*stopfilehead;
	head = new word;
	stopfilehead = new word;
	head->next = NULL;
	stopfilehead->next = NULL;
	if(strcmp(argv[1],"-c") == 0)
			numberoftheword(argv[2]);
	if (strcmp(argv[1], "-f") == 0)
	{
		int num;
		num = readfile(head,argv[2]);
		//cout << num << endl;
		if(argv[3] == NULL)
		sort1(head , num);
		if (strcmp(argv[3], "-n") == 0)
		{
			//strcpy(nvalue, );
			int temp = 0,weishu = 0;
			for(int i=0;argv[4][i]!=NULL;i++)
			{
				weishu++;
			}
			for (int i = weishu - 1,j = 0 ; i >= 0; i--,j++)
			{
				temp += (argv[4][i] - '0')* pow(10, j);
			}
			//cout << temp << endl;
			sort1(head,temp);
		}

	}
	if (strcmp(argv[1], "-d") == 0)
	{
		if (strcmp(argv[2], "-s") == 0)
			cout << "目录下的子文件已处理" << endl;
	}
	if (strcmp(argv[1], "-x") == 0)
	{
		int stop_num = readfile(stopfilehead, argv[2]);
		int num_x = stopreadfile(head, argv[4], stopfilehead);
		sort1(head, num_x);
	}
	if (strcmp(argv[1], "-p") == 0)
	{
			//strcpy(nvalue, );
			int temp = 0, weishu = 0;
			for (int i = 0; argv[2][i] != NULL; i++)
			{
				weishu++;
			}
			for (int i = weishu - 1, j = 0; i >= 0; i--, j++)
			{
				temp += (argv[2][i] - '0')* pow(10, j);
			}
			int num = readfileLimtiedby(head, argv[4], temp);
			//cout << temp << endl;
			sort1(head, num);
	}
	//if (strcmp(argv[1], "-v") == 0)
	//{
	//	int v_num = readfile(stopfilehead, argv[2]);
	//	int num_x = stopreadfile(head, argv[4], stopfilehead);
	//	sort1(head, num_x);
	//}
	//cout << 0 << endl;
}