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
		printf("�޷��򿪴��ļ�!\n");
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
	cout << "�������ʵ�Ƶ�����£��������ִ�Сд��" << endl;
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
int readfile(struct word*&head,char *txt)
{
	FILE *fp;
	if ((fp = fopen(txt, "r")) == NULL)
	{
		printf("�޷��򿪴��ļ�!\n");
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

void sort1(struct word*&head,int n)
{
	struct word *q;
	int a[26], i;
	
	for (i = 0; i<n; i++)
		a[i] = 0;
	printf("�����г���Ƶ����ߵ�%d����������:\n",n);
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
				printf("����Ƶ��:%d\t", a[i]);
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
			cout << "Ŀ¼�µ����ļ��Ѵ���" << endl;
	}

	//cout << 0 << endl;
}