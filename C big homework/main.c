#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#define N 1000 //学生人数
#define M 3 //考试科目数目
typedef struct student
{
    long ID;
    int rank;
    char name[20];
    float score[M];
    float total;
    float average;
    struct student *next;
}student;
int numstu=0,enternum=0;
float sum[M],aver[M];
char head[]={"ID\tName\tCal\tAlg\tC\tSum\tAverage\n"};
student stu[N];
int flagInput=0,flag1=0,flag2=0,flag3=0,flag31=0,flag32=0,flag4=0,flag5=0;
int menu();
void Input ();
void calculatestuscore();
void caltotal();
void IDsort (student a[]);
void namesort (student a[]);
void swap(student *a,student *b);
void scoresort (student a[],int n,int flag);
void ranksort (student a[N]);
void IDsearch();
void namesearch();
void Statistics();
void shuchu ();
void writefile();
void readfile();
int main()
{

    while (menu()!=0)
    {
        printf("\n");//123  gkx 12.2    12.3    12.3
    }
    return 0;
}

void menuswitch(int i)
{
    switch(i)
    {
        case 1:
            Input();
            break;
        case 2:
            calculatestuscore(numstu);
            break;
        case 3:
           caltotal();
           break;
        case 4:
            scoresort(stu,numstu,1);
            printf("Sorted in ascending order");
            break;
        case 5:
            scoresort(stu,numstu,0);
            printf("Sorted in descending order");
            break;
        case 6:
            IDsort(stu);
            printf("Sorted by student number from small to large");
            break;
        case 7:
            namesort(stu);
            printf("Sort the transcript by name in lexicographic order");
            break;
        case 8:
            IDsearch();
            break;
        case 9:
            namesearch();
            break;
        case 10:Statistics();
        break;
        case 11:shuchu();
        break;
        case 12:writefile();
        break;
        case 13:readfile();
        break;
    }

}
int menu()
{
    int n;
    printf("1.Input record\n");
    printf("2.Calculate total and average score of every course\n");
    printf("3.Calculate total and average score of every student\n");
    printf("4.Sort in descending order by total score of every student\n");
    printf("5.Sort in ascending order by total score of every student\n");
    printf("6.Sort in ascending order by number\n");
    printf("7.Sort in dictionary order by name\n");
    printf("8.Search by number\n");
    printf("9.Search by name\n");
    printf("10.Statistic analysis for every course\n");
    printf("11.List record\n");
    printf("12.Write to a file\n");
    printf("13.Read from a file\n");
    printf("0.Exit\n");
    printf("Please enter your choice:\n");
    while (scanf("%d",&n)!=1||n<0||n>13)
    {
        printf("please enter right choice\n");
         printf("Please enter your choice:\n");
    }
    getchar();
    menuswitch(n);
    return n;
}
//函数功能：显示菜单
//函数参数：n
//函数返回值：菜单选项n

void Input ()
{
    int n,j;
    printf("please enter the number of student:\n");
    scanf ("%d",&n);
    numstu+=n;
    printf("please enter the information of the student:\n");
    printf("ID\tName\tCal\tAlg\tC\n");
    for(int i = enternum;i < numstu; i++)
    {
        while (scanf("%ld %s",&stu[i].ID,stu[i].name)!=2)
        {
            printf("please enter right student ID\n");
        }
        for (j=0;j<M;j++)
        {
            while (scanf("%f",&stu[i].score[j])!=1)
            {
                printf("please enter right student score\n");
            }
        }

    }
    flagInput=1;
    enternum += numstu;
    ranksort(stu);
}
//函数功能：录入n个学生的学号、姓名和各科考试成绩,并判断是否符合输入要求；
//函数参数：n，i
//函数返回值：无

void caltotal()
{
    for (int i = 0;i<M;i++)
    {
        sum[i]=0;
        aver[i]=0;
        for(int j=0;j<numstu;j++)
        {
            sum[i]=sum[i]+stu[j].score[i];
        }
        aver[i]=sum[i]/numstu;
    }
    flag1=1;

}
//函数功能: 计算每门课程的总分和平均分
//函数参数：无
//函数返回值：无

void calculatestuscore()
{

    for(int i=0;i<numstu;i++)
    {
        stu[i].total=0;
        for (int j=0;j<M;j++)
        {
            stu[i].total=stu[i].total+stu[i].score[j];

        }
        stu[i].average=stu[i].total/M;
    }
    flag2=1;
}
//函数功能: 计算每个学生的总分和平均分
//函数参数：无
//函数返回值：无
void scoresort (student a[],int n,int flag)
{
    int i,j;
    if (flag2==0)printf("please calculate the total score of student");
    else {for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(flag==1)//flag==1，对成绩进行升序排序
            {if(a[i].total>a[j].total)
            {
                swap(&a[i],&a[j]);
            }
            flag31=1;
            flag32=0;
            flag4=0;
            flag5=0;
            }
            else//flag==0，对成绩进行升序排序
            {
                if(a[i].total<a[j].total)
            {
                swap(&a[i],&a[j]);
            }
            flag32=1;
            flag31=0;
            flag4=0;
            flag5=0;
            }
        }
    }
    if(flag==1)
    {
        for(i=0;i<n;i++)
        {
            a[i].rank=n-i;
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            a[i].rank=i+1;
        }
    }
    }
}
//函数功能：对学生成绩升序或降序排序
//函数参数：浮点型数组a[]，n，flag
//函数返回值：无
void IDsort (student a[])
{
    int i,j;
    for(i=0;i<numstu;i++)
    {
        for(j=i+1;j<numstu;j++)
        {
            if(a[i].ID>a[j].ID)
            {
             swap(&a[i],&a[j]);
            }
        }
    }
    printf("Sorted by Student ID");
    flag4=1;
    flag31=0,flag32=0,flag5=0;
}

//函数功能：对学生学号升序
//函数参数：浮点型数组a[]，n，flag
//函数返回值：无
void namesort (student a[])
{
    int i,j;
    for(i=0;i<numstu;i++)
    {
        for(j=i+1;j<numstu;j++)
        {
            if(strcmp(a[i].name,a[j].name)>0)
            {
             swap(&a[i],&a[j]);
            }
        }
    }
    printf("Sorted by dictionary order of names");
    flag5=1;
    flag4=0,flag32=0,flag31=0;
}
//函数功能：按姓名的字典顺序排出成绩表
//函数参数：stu
//函数返回值：无

void swap(student *a,student *b)
{
    int i;
     student *temp=(student *) malloc(sizeof(student));
    temp->ID = a->ID;
    temp->total = a->total;
    temp->average = a->average;
    temp->rank = a->rank;
    strcpy(temp->name,a -> name);
    for(i=0;i<M;i++)
    {
        temp->score[i] = a->score[i];
    }
    a->ID = b->ID;
    strcpy(a->name,b->name);
    a->total = b->total;
    a->average = b->average;
    a->rank = b->rank;
    for(i=0;i<M;i++)
    {
        a->score[i] = b->score[i];
    }
    b->ID = temp->ID;
    strcpy(b->name,temp->name);
    b->total = temp->total;
    b->average = temp->average;
    b->rank = temp->rank;
    for(i=0;i<4;i++)
    {
        b->score[i] = temp->score[i];
    }

    free(temp);
}
//函数功能：交换两个学生所有的信息
//函数参数：student a ,student b
//函数返回值：无

void ranksort (student a[N])
{
    student b[N];
    int i;
    for(int j=0;j<N;j++)
    {
        b[j].ID = a[j].ID;
        strcpy(b[j].name,a[j].name);
        b[j].total = a[j].total;
        b[j].average = a[j].average;
        b[j].rank = a[j].rank;
            for(i=0;i<M;i++)
        {
            b[j].score[i] = a[j].score[i];
        }
    }
    scoresort(b,numstu,1);
    for(i=0;i<numstu;i++)
    {
        a[i].rank = b[i].rank;
    }
}
//函数功能：计算每个学生的排名
//函数参数：a，b
//函数返回值：无

void IDsearch()
{
    int i;
    long ID;
    printf("Please enter the searching ID:\n");
    scanf("%ld",&ID);
    for(i=0;i<numstu;i++)
    {
        if(stu[i].ID==ID)
        {
            printf("Search Result:\nRank:%d\nScore:Calculus:%.2f\tAlgebra:%.2f\tC:%.2f\n",stu[i].rank,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
            return;
        }
    }
    printf("Not find\n");
    return;
}
//函数功能：按学号查询学生排名及其考试成绩；
//函数参数：无
//函数返回值：无

void namesearch()
{
    int i;
    char searchname[20];
    printf("Please enter the searching name:\n");
    scanf("%s",searchname);
    for(i=0;i<numstu;i++)
    {
        if(strcmp(stu[i].name,searchname)==0)
        {
            printf("Search Result:\nRank:%d\nScore:Calculus:%.2f\tAlgebra:%.2f\tC:%.2f\n",stu[i].rank,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
            return;
        }
    }
    printf("Not find\n");
    return;
}
//函数功能：按姓名查询学生排名及其考试成绩；
//函数参数：无
//函数返回值：无
void print_10(float a[M][5][2],int i)
{
    int j;
    const char *b[M]={"Calculus","Algebra","C language"};
    printf("%s:\ttop\tGood\tMid\tpass\tFail\n",b[i]);
    printf("Number:\t\t");
    for(j=0;j<5;j++)
    {
        printf("%.0f\t",a[i][j][0]);
    }
    printf("\nPercent:\t");
    for(j=0;j<5;j++)
    {
        printf("%2.2f%%\t",a[i][j][1]);
    }
    printf("\n");
}
//函数功能：输出各个科目的统计数据
//函数参数：无
//函数返回值：无
void Statistics()
{
    int i,j;
    float a[M][5][2];//第一个代表科目，第二个代表成绩，第三个代表人数和百分比
    for(i=0;i<M;i++)//让人数的初值为0
    {
        for(j=0;j<5;j++)
        {
            a[i][j][0]=0;
        }
    }

    for(i=0;i<M;i++)
    {
        for(j=0;j<numstu;j++)
        {
            if(stu[j].score[i]>=90&&stu[j].score[i]<=100)a[i][0][0]++;
            if(stu[j].score[i]>=80&&stu[j].score[i]<=89)a[i][1][0]++;
            if(stu[j].score[i]>=70&&stu[j].score[i]<=79)a[i][2][0]++;
            if(stu[j].score[i]>=60&&stu[j].score[i]<=69)a[i][3][0]++;
            if(stu[j].score[i]>=0&&stu[j].score[i]<=59)a[i][4][0]++;
        }

    }
    for(i=0;i<M;i++)//计算百分比并赋值
    {
        for(j=0;j<5;j++)
        {
            a[i][j][1]=a[i][j][0]/numstu*100;
        }
    }
    for(i=0;i<M;i++)
    {
        print_10(a,i);
    }
}
//函数功能：统计数据
//函数参数：无
//函数返回值：无

void shuchu ()
{
    int i,j;
    if(flagInput==0)printf("please input the information");
    else
    {
    {
        if (flag1==0)printf("Total score and average score of student not calculated\n");
        if (flag2==0)printf("Total score and average score of course not calculated\n");
        if (flag31==1)printf("Will output in descending order of score\n");
        if (flag32==1)printf("Will output in ascending order of score\n");
        if (flag4==1)printf("Will output in ascending order of number\n");
        if (flag5==1)printf("Will output in dictionary order of name\n");
    }
    printf("%s",head);
    for(i=0;i<numstu;i++)
    {
        printf("%ld\t%s\t",stu[i].ID,stu[i].name);
        for(j=0;j<M;j++)
        {
            printf("%.2f\t",stu[i].score[j]);
        }
        printf("%.2f\t%.2f\n",stu[i].total,stu[i].average);
    }
    printf("\nCourse\t\tTotal\tAverage\n\n");
    const char b[M][14]={"Calculus","Algebra","C language"};
    for(i=0;i<3;i++)
    {
        printf("%s:    \t%.2f\t%.2f\n",b[i],sum[i],aver[i]);
    }
    }

}
//函数功能：按格式输出学生成绩以及科目成绩
//函数参数：无
//函数返回值：无
void writefile()
{
    FILE *fp;
    if((fp = fopen("D:\\empty.txt","w"))== NULL)
    {
        printf("Failure to open empty.txt\n");
        return;
    }
    fprintf(fp,"ID\tName\tCal\tAlg\tC\n");
    for(int i = 0 ;i < numstu ;i++)
    {
        fprintf(fp,"%ld\t%s\t",stu[i].ID,stu[i].name);
        for(int j = 0 ;j<M;j++)
        {
            fprintf(fp,"%.2f\t",stu[i].score[j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    printf("File written\n");
}
//函数功能：写入文件
//函数参数：无
//函数返回值：无

void readfile()
{
    FILE *fp;
    int i;
    if((fp = fopen("D:\\information.txt","r"))== NULL)
    {
        printf("Failure to open information.txt\n");
        return;
    }
    for(i = numstu ; feof(fp)==0 ;i++)
    {
        fscanf(fp,"%ld %s",&stu[i].ID,stu[i].name);
        for(int j = 0 ;j<M;j++)
        {
            fscanf(fp,"%f",&stu[i].score[j]);
        }
    }
    numstu=i-1;
    enternum=numstu;
    fclose(fp);
    printf("File read\n");
    flagInput=1;
    ranksort(stu);
}
//函数功能：读入文件
//函数参数：无
//函数返回值：无
