#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class  goods
{
private:
	char *pName;//����
	float unit_price;//����
public:
	goods(){ }
	goods(char name[],float price)
	{
		pName=new char[strlen(name)+1];
		strcpy(pName,name);
		this->unit_price=price;
	}
	//�Ը���������Ϣ��ֵ
	void setname(char *name)
	{
		pName=new char[strlen(name)+1];
		strcpy(pName,name);
	}
	void setprice(float price){ this->unit_price=price ; }
	//������Ϣ
	char *getname(){ return pName ; }
	float getPrice(){ return this->unit_price ; }
	~goods()
	{
		if(pName!=NULL){ delete [] pName ; }
		pName=NULL;
	}
};
class Computer:public goods//���Ի�����Ϣ
{
private:
	char CPU[20];//���봦����
	char RAM[20];//�洢��
	char HDD[10];//��еӲ��
	char SSD[10];//��̬Ӳ��
	char GPU[10];//�Կ�
	char power[20];//��Դ
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
	//���ظ�����Ϣ
	char *getCPU(){ return this->CPU ; }
	char *getRAM(){ return this->RAM ; }
	char *getHDD(){ return this->HDD ; }
	char *getSSD(){ return this->SSD ; }
	char *getGPU(){ return this->GPU ; }
	//�Ը�����Ϣ��ֵ
	void setCPU(char *CPU){ strcpy(this->CPU , CPU ) ; }
	void setRAM(char *RAM){ strcpy(this->RAM , RAM ) ; }
	void setHDD(char *HDD){ strcpy(this->HDD , HDD ) ; }
	void setSSD(char *SSD){ strcpy(this->SSD , SSD ) ; }
	void setGPU(char *GPU){ strcpy(this->GPU , GPU ) ; }
	void display()
	{
		cout <<"***************************"<<endl;
		cout <<"���ƣ�"<<getname()<<endl;
		cout <<"���ۣ�"<<getPrice()<<endl;
		cout <<"��������"<<this->CPU<<endl;
		cout <<"�ڴ棺"<<this->RAM<<endl;
		cout <<"��еӲ�̣�"<<this->HDD<<endl;
		cout <<"��̬Ӳ�̣�"<<this->SSD<<endl;
		cout <<"�Կ���"<<this->GPU<<endl;
		cout <<"��Դ��"<<this->power<<endl;
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
	char Model[20];//Ʒ���ͺ�
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
		cout <<"���ƣ�"<<getname()<<endl;
		cout <<"Ʒ���ͺţ�"<<this->Model<<endl;
		cout <<"���ۣ�"<<getPrice()<<endl;
		cout <<"��������"<<getCPU()<<endl;
		cout <<"�ڴ棺"<<getRAM()<<endl;
		cout <<"��еӲ�̣�"<<getHDD()<<endl;
		cout <<"��̬Ӳ�̣�"<<getSSD()<<endl;
		cout <<"�Կ���"<<getGPU()<<endl;
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
class office_supplies:public goods//�칫��Ʒ
{
private:
	char Model[10];;//Ʒ���ͺ�
	char color[10];//��ɫ
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
		cout <<"���ƣ�"<<getname()<<endl;
		cout <<"���ۣ�"<<getPrice()<<endl;
		cout <<"Ʒ���ͺţ�"<<Model<<endl;
		cout <<"��ɫ��"<<this->color<<endl;
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
class daily_necessities:public office_supplies//������Ʒ
{
public:
	daily_necessities(char *name,float price,char *Model,char *color):office_supplies(name,price,Model,color){ }
};
class book:public goods
{
private:
	char author[20];//����
	char type[10];//����
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
		cout <<"���ƣ�"<<getname()<<endl;
		cout <<"���ۣ�"<<getPrice()<<endl;
		cout <<"���ߣ�"<<author<<endl;
		cout <<"���ͣ�"<<type<<endl;
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
	char name[20];//����
	float price;//����
	char CPU[20];//���봦����
	char RAM[20];//�洢��
	char HDD[10];//��еӲ��
	char SSD[10];//��̬Ӳ��
	char GPU[10];//�Կ�
	char power[20];//��Դ
	cout <<"����˳�����ƣ����ۣ�CPU���ڴ棬��еӲ�̣���̬Ӳ�̣��Կ�����Դ��"<<endl;
	cin >>name>>price>>CPU>>RAM>>HDD>>SSD>>GPU>>power;
	Computer computer(name,price,CPU,RAM,HDD,SSD,GPU,power);
	computer.display();
	cout <<"��ӳɹ���"<<endl;
	computer.store(t);
}
void input2(FILE *t)
{
	char name[20];//����
	char Model[20];//Ʒ���ͺ�
	float price;//����
	char CPU[20];//���봦����
	char RAM[20];//�洢��
	char HDD[10];//��еӲ��
	char SSD[10];//��̬Ӳ��
	char GPU[10];//�Կ�
	cout <<"����˳�����ƣ�Ʒ���ͺţ����ۣ�CPU���ڴ棬��еӲ�̣���̬Ӳ�̣��Կ���"<<endl;
	cin >>name>>Model>>price>>CPU>>RAM>>HDD>>SSD>>GPU;
	notebook note(name,Model,price,CPU,RAM,HDD,SSD,GPU);
	note.display();
	cout <<"��ӳɹ���"<<endl;
	note.store(t);
}
void input3(FILE *t)
{
	char name[20];//����
	float price;//����
	char Model[10];;//Ʒ���ͺ�
	char color[10];//��ɫ
	cout <<"����˳�����ƣ����ۣ�Ʒ���ͺš���ɫ��"<<endl;
	cin >>name>>price>>Model>>color;
	office_supplies off(name,price,Model,color);
	off.display();
	cout <<"��ӳɹ���"<<endl;
	off.store(t);
}
void input4(FILE *t)
{
	char name[20];//����
	float price;//����
	char Model[10];;//Ʒ���ͺ�
	char color[10];//��ɫ
	cout <<"����˳�����ƣ����ۣ�Ʒ���ͺš���ɫ��"<<endl;
	cin >>name>>price>>Model>>color;
	daily_necessities daily(name,price,Model,color);
	daily.display();
	cout <<"��ӳɹ���"<<endl;
	daily.store(t);
}
void input5(FILE *t)
{
	char name[20];//����
	float price;//����
	char author[20];//����
	char type[10];//����
	cout <<"����˳�����ƣ����ۣ����ߡ����ͣ�"<<endl;
	cin  >>name>>price>>author>>type;
	book Bo(name,price,author,type);
	Bo.display();
	cout <<"��ӳɹ���"<<endl;
	Bo.store(t);
}
void menu(FILE *t)
{
	for(int i=0;;i++)
	{
		cout <<"��ѡ��Ҫ¼����Ϣ������"<<endl;
		cout <<"1.�������"<<endl;
		cout <<"2.�ʼǱ����ԡ�"<<endl;
		cout <<"3.�칫��Ʒ��"<<endl;
		cout <<"4.������Ʒ��"<<endl;
		cout <<"5.ͼ�顢"<<endl;
		cout <<"0.��������"<<endl;
		cout <<"����������ǰ�ı��"<<endl;
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
	if((t=fopen("��Ʒ��Ϣ.txt","w"))==NULL)
	{
		printf("File open error\n");
		exit(0);
	}
	cout <<"�����̳���Ʒ����ϵͳ"<<endl;
	menu(t);
	fclose(t);
	cout <<"ϵͳ�ر�"<<endl;
	return 0;

}