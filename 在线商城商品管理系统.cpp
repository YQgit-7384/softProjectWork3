#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class  goods
{
private:
	char *pName;//名称
	float unit_price;//单价
public:
	goods(){ }
	goods(char name[],float price)
	{
		pName=new char[strlen(name)+1];
		strcpy(pName,name);
		this->unit_price=price;
	}
	//对各个基本信息赋值
	void setname(char *name)
	{
		pName=new char[strlen(name)+1];
		strcpy(pName,name);
	}
	void setprice(float price){ this->unit_price=price ; }
	//返回信息
	char *getname(){ return pName ; }
	float getPrice(){ return this->unit_price ; }
	~goods()
	{
		if(pName!=NULL){ delete [] pName ; }
		pName=NULL;
	}
};
class Computer:public goods//电脑基础信息
{
private:
	char CPU[20];//中央处理器
	char RAM[20];//存储器
	char HDD[10];//机械硬盘
	char SSD[10];//固态硬盘
	char GPU[10];//显卡
	char power[20];//电源
public:
	Computer(){	}
	Computer(char *name,float price,char *CPU,char *RAM,char *HDD,char *SSD,char *GPU,char *power):goods(name,price)
	{
		strcpy(this->CPU,CPU);
		strcpy(this->RAM,RAM);
		strcpy(this->HDD,HDD);
		strcpy(this->SSD,SSD);
		strcpy(this->GPU,GPU);
		strcpy(this->power,power);
	}
	Computer(char *name,float price,char *CPU,char *RAM,char *HDD,char *SSD,char *GPU):goods(name,price)
	{
		strcpy(this->CPU,CPU);
		strcpy(this->RAM,RAM);
		strcpy(this->HDD,HDD);
		strcpy(this->SSD,SSD);
		strcpy(this->GPU,GPU);
	}
	//返回各个信息
	char *getCPU(){ return this->CPU ; }
	char *getRAM(){ return this->RAM ; }
	char *getHDD(){ return this->HDD ; }
	char *getSSD(){ return this->SSD ; }
	char *getGPU(){ return this->GPU ; }
	//对各个信息赋值
	void setCPU(char *CPU){ strcpy(this->CPU , CPU ) ; }
	void setRAM(char *RAM){ strcpy(this->RAM , RAM ) ; }
	void setHDD(char *HDD){ strcpy(this->HDD , HDD ) ; }
	void setSSD(char *SSD){ strcpy(this->SSD , SSD ) ; }
	void setGPU(char *GPU){ strcpy(this->GPU , GPU ) ; }
	void display()
	{
		cout <<"***************************"<<endl;
		cout <<"名称："<<getname()<<endl;
		cout <<"单价："<<getPrice()<<endl;
		cout <<"处理器："<<this->CPU<<endl;
		cout <<"内存："<<this->RAM<<endl;
		cout <<"机械硬盘："<<this->HDD<<endl;
		cout <<"固态硬盘："<<this->SSD<<endl;
		cout <<"显卡："<<this->GPU<<endl;
		cout <<"电源："<<this->power<<endl;
		cout <<"***************************"<<endl;
	}
	void store(FILE *t)
	{
		fprintf(t,"%s ",getname());
		fprintf(t,"%f ",getPrice());
		fprintf(t,"%s ",this->CPU);
		fprintf(t,"%s ",this->RAM);
		fprintf(t,"%s ",this->HDD);
		fprintf(t,"%s ",this->SSD);
		fprintf(t,"%s ",this->GPU);
		fprintf(t,"%s \n",this->power);
	}
	~Computer(){}
};
class notebook:public Computer
{
private:
	char Model[20];//品牌型号
public:
	notebook(char *name,char *Model,float price,char *CPU,char *RAM,char *HDD,char *SSD,char *GPU):Computer(name,price,CPU,RAM,HDD,SSD,GPU)
	{
		strcpy(this->Model ,Model);
	}
	void setModel(char *Model){ strcpy(this->Model , Model ) ; }
	char *getModel(){ return this->Model ; }
	void display()
	{
		cout <<"***************************"<<endl;
		cout <<"名称："<<getname()<<endl;
		cout <<"品牌型号："<<this->Model<<endl;
		cout <<"单价："<<getPrice()<<endl;
		cout <<"处理器："<<getCPU()<<endl;
		cout <<"内存："<<getRAM()<<endl;
		cout <<"机械硬盘："<<getHDD()<<endl;
		cout <<"固态硬盘："<<getSSD()<<endl;
		cout <<"显卡："<<getGPU()<<endl;
		cout <<"***************************"<<endl;
	}
	void store(FILE *t)
	{
		fprintf(t,"%s ",getname());
		fprintf(t,"%s ",this->Model);
		fprintf(t,"%f ",getPrice());
		fprintf(t,"%s ",getCPU());
		fprintf(t,"%s ",getRAM());
		fprintf(t,"%s ",getHDD());
		fprintf(t,"%s ",getSSD());
		fprintf(t,"%s \n",getGPU());
	}
	~notebook(){}
};
class office_supplies:public goods//办公用品
{
private:
	char Model[10];;//品牌型号
	char color[10];//颜色
public:
	office_supplies(char *name,float price,char *Model,char *color):goods(name,price)
	{
		strcpy(this->Model,Model);
		strcpy(this->color,color);
	}
	void setModel(char *Model){strcpy(this->Model,Model) ; };
	void setcolor(char *color){ strcpy(this->color ,color) ; };
	char *getModel(){ return Model ; }
	char *getcolor(){ return this->color ; }
	void display()
	{
		cout <<"***************************"<<endl;
		cout <<"名称："<<getname()<<endl;
		cout <<"单价："<<getPrice()<<endl;
		cout <<"品牌型号："<<Model<<endl;
		cout <<"颜色："<<this->color<<endl;
		cout <<"***************************"<<endl;
	}
	void store(FILE *t)
	{
		fprintf(t,"%s ",getname());
		fprintf(t,"%f ",getPrice());
		fprintf(t,"%s ",Model);
		fprintf(t,"%s \n",this->color);
	}
};
class daily_necessities:public office_supplies//生活用品
{
public:
	daily_necessities(char *name,float price,char *Model,char *color):office_supplies(name,price,Model,color){ }
};
class book:public goods
{
private:
	char author[20];//作者
	char type[10];//类型
public:
	book(char *name,float price,char *author,char *type):goods(name,price)
	{
		strcpy(this->author ,author);
		strcpy(this->type,type);
	}
	void setauthor(char *author){ strcpy(this->author,author) ; }
	void settype(char *type){ strcpy(this->type,type) ; }
	char *getauthor(){ return this->author ; }
	char *gettype(){ return this->type ; }
	void display()
	{
		cout <<"***************************"<<endl;
		cout <<"名称："<<getname()<<endl;
		cout <<"单价："<<getPrice()<<endl;
		cout <<"作者："<<author<<endl;
		cout <<"类型："<<type<<endl;
		cout <<"***************************"<<endl;
	}
	void store(FILE *t)
	{
		fprintf(t,"%s ",getname());
		fprintf(t,"%f ",getPrice());
		fprintf(t,"%s ",author);
		fprintf(t,"%s \n",type);
	}
};
void input1(FILE *t)
{
	char name[20];//名称
	float price;//单价
	char CPU[20];//中央处理器
	char RAM[20];//存储器
	char HDD[10];//机械硬盘
	char SSD[10];//固态硬盘
	char GPU[10];//显卡
	char power[20];//电源
	cout <<"输入顺序（名称，单价，CPU，内存，机械硬盘，固态硬盘，显卡，电源）"<<endl;
	cin >>name>>price>>CPU>>RAM>>HDD>>SSD>>GPU>>power;
	Computer computer(name,price,CPU,RAM,HDD,SSD,GPU,power);
	computer.display();
	cout <<"添加成功！"<<endl;
	computer.store(t);
}
void input2(FILE *t)
{
	char name[20];//名称
	char Model[20];//品牌型号
	float price;//单价
	char CPU[20];//中央处理器
	char RAM[20];//存储器
	char HDD[10];//机械硬盘
	char SSD[10];//固态硬盘
	char GPU[10];//显卡
	cout <<"输入顺序（名称，品牌型号，单价，CPU，内存，机械硬盘，固态硬盘，显卡）"<<endl;
	cin >>name>>Model>>price>>CPU>>RAM>>HDD>>SSD>>GPU;
	notebook note(name,Model,price,CPU,RAM,HDD,SSD,GPU);
	note.display();
	cout <<"添加成功！"<<endl;
	note.store(t);
}
void input3(FILE *t)
{
	char name[20];//名称
	float price;//单价
	char Model[10];;//品牌型号
	char color[10];//颜色
	cout <<"输入顺序（名称，单价，品牌型号、颜色）"<<endl;
	cin >>name>>price>>Model>>color;
	office_supplies off(name,price,Model,color);
	off.display();
	cout <<"添加成功！"<<endl;
	off.store(t);
}
void input4(FILE *t)
{
	char name[20];//名称
	float price;//单价
	char Model[10];;//品牌型号
	char color[10];//颜色
	cout <<"输入顺序（名称，单价，品牌型号、颜色）"<<endl;
	cin >>name>>price>>Model>>color;
	daily_necessities daily(name,price,Model,color);
	daily.display();
	cout <<"添加成功！"<<endl;
	daily.store(t);
}
void input5(FILE *t)
{
	char name[20];//名称
	float price;//单价
	char author[20];//作者
	char type[10];//类型
	cout <<"输入顺序（名称，单价，作者、类型）"<<endl;
	cin  >>name>>price>>author>>type;
	book Bo(name,price,author,type);
	Bo.display();
	cout <<"添加成功！"<<endl;
	Bo.store(t);
}
void menu(FILE *t)
{
	for(int i=0;;i++)
	{
		cout <<"请选择要录入信息的种类"<<endl;
		cout <<"1.计算机、"<<endl;
		cout <<"2.笔记本电脑、"<<endl;
		cout <<"3.办公用品、"<<endl;
		cout <<"4.生活用品、"<<endl;
		cout <<"5.图书、"<<endl;
		cout <<"0.结束程序。"<<endl;
		cout <<"请输入名称前的编号"<<endl;
		int type;
		cin >>type;
		switch(type)
		{
			case 1:input1(t);break;
			case 2:input2(t);break;
			case 3:input3(t);break;
			case 4:input4(t);break;
			case 5:input5(t);break;
			case 0:return; 
		}
	}
}
int main()
{
	FILE *t;
	if((t=fopen("商品信息.txt","w"))==NULL)
	{
		printf("File open error\n");
		exit(0);
	}
	cout <<"在线商城商品管理系统"<<endl;
	menu(t);
	fclose(t);
	cout <<"系统关闭"<<endl;
	return 0;

}