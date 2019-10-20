#include<iostream>
#include<string.h>
#include<vector>
#include <algorithm>
#include <iomanip>
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
	//cout << sum << endl;
	for (int i = 0; i < 26; i++)
	{
		//cout << "ok" << endl;
		if (a[i].word >= 'a'&& a[i].word <= 'z')
		{
			cout << a[i].word << ' '<< setprecision(2) << 1.00*a[i].num / sum<<endl;
			//printf("%d\n", a[i].word);//,(float)1.0*a[i].num / sum
		}


		
	}
}
void readfile(struct word*&head,char *txt)
{
	FILE *fp;
	if ((fp = fopen(txt, "r")) == NULL)
	{
		printf("无法打开此文件!\n");
		exit(0);
	}
	char ch, temp[30];
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
		}
	}
}

void sort(struct word*&head)
{
	struct word *q;
	int a[10], i;
	for (i = 0; i<10; i++)
		a[i] = 0;
	printf("文章中出现频率最高的十个单词如下:\n");
	for (i = 0; i<10; i++)
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
	struct word *head;
	head = new word;
	head->next = NULL;
	if(strcpy(argv[1],"-c"))
			numberoftheword(argv[2]);
	
	//cout << 0 << endl;
}