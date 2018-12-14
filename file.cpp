#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

class Day
{
public:
    int year,month,day;
};

class file : public Day
{
public:
    void newmessage();
    string getname()
    {
        return name;
    }
    string getnum()
    {
        return num;
    }
    void getinfor();
    void revise();
private:
    string name,num,quality;
    int size;
};

void file::newmessage()
{
    string name1,num1,quality1;
    int size1 ,remain1;
    int year1,month1,day1;
    cout<<"请输入文件编号:";
    cin>>name1;
    cout<<"请输入文件名称:";
    cin>>num1;
    cout<<"请输入文件性质:";
    cin>>quality1;
    cout<<"请输入文件的年：";
    cin>>year1;
    cout<<"月：";
    cin>>month1;
    cout<<"日：";
    cin>>day1;
    cout<<"请输入文件大小:";
    cin>>size1;
    name=name1,num=num1,quality=quality1;
    size=size1 ,year=year1,month=month1,day=day1;
}


void file::getinfor()
{
    cout<<"文件编号为："<<num<<endl;
    cout<<"文件名称为："<<name<<endl;
    cout<<"文件的性质为："<<quality<<endl;
    cout<<"文件大小为："<<size<<endl;
    cout<<"文件的生产日期为："<<year<<" "<<month<<" "<<day<<endl;
    system("pause");
    system("cls");
}

void file::revise()
{
    cout<<"请输入新的文件编号："<<endl;
    cin>>num;
    cout<<"请输入新的文件名："<<endl;
    cin>>name;
    cout<<"请输入新的性质："<<endl;
    cin>>quality;
    cout<<"请输入新的大小："<<endl;
    cin>>size;
    cout<<"请输入新的日期："<<endl;
    cout<<"年：";
    cin>>year;
    cout<<"月：";
    cin>>month;
    cout<<"日：";
    cin>>day;
    cout<<"修改数据成功";
    system("pause");
    system("cls");
}


int sum=0;
file g[108];


void Show()
{
    if(sum==0)
    {
        cout<<"现在没有文件存在"<<endl;
        return;
    }
    for(int i=0; i<sum; i++)
    {
        cout<<"第"<<i+1<<"件文件的信息为:"<<endl;
        g[i].getinfor();
    }
    system("pause");
    system("cls");
}

void Find()
{
    cout<<"请输入您要查找的文件名:"<<endl;
    string name1;
    cin>>name1;
    int flag=0;
    for(int i=0; i<sum; i++)
    {
        if(g[i].getname()==name1)
        {
            flag=1;
            g[i].getinfor();
            break;
        }
    }
    if(flag==0)
    {
        cout<<"您要查询的文件不存在"<<endl;
    }
    else
    {
        cout<<"查询成功"<<endl;
    }
    system("pause");
    system("cls");
}

void Add()
{
    g[sum++].newmessage();
    system("pause");
    system("cls");
}

void Revise()
{
    string name1;
    int flag=0;
    cout<<"请输入您要修改的文件名"<<endl;
    cin>>name1;
    for(int i=0; i<sum; i++)
    {
        if(name1==g[i].getname())
        {
            flag=1;
            g[i].revise();
            break;
        }
    }
    if(flag==0)
    {
        cout<<"您要修改的数据不存在"<<endl;
    }
    system("pause");
    system("cls");
}

void Delete()
{
    string na;
    cout<<"请输入您要删除的数据的姓名："<<endl;
    cin>>na;
    int s=0;
    for(int i=0; i<sum; i++)
    {
        if(na==g[i].getname())
        {
            for(int j=i; j<sum; j++)
            {
                g[j]=g[j+1];
            }
            s=1;
            sum--;
            break;
        }
    }
    if(s==0)
    {
        cout<<"您所要删除的数据不存在"<<endl;
    }
    else
    {
        cout<<"删除成功！"<<endl;
    }
    system("pause");
    system("cls");
}
int main()
{
    cout<<"欢迎来到文件信息管理系统"<<endl;
    system("pause");
    system("cls");
    while(1)
    {
        cout<<"1.增加数据"<<endl;
        cout<<"2.浏览数据"<<endl;
        cout<<"3.查询数据"<<endl;
        cout<<"4.修改数据"<<endl;
        cout<<"5.删除数据"<<endl;
        cout<<"6.退出"<<endl;
        cout<<"请输入您的选择："<<endl;
        int n;
        cin>>n;
        switch(n)
        {
        case 1:
            Add();
            break;
        case 2:
            Show();
            break;
        case 3:
            Find();
            break;
        case 4:
            Revise();
            break;
        case 5:
            Delete();
            break;
        case 6:
            return 0;
        }
    }
}
