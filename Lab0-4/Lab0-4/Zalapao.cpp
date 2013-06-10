#include<iostream>
#include<string>
using namespace std;

const int week=7;
const int typeZalapao=4;
 
string ConvertDay(const int day);
string ConvertType(const int type);
class Zalapao 
{
public :
	Zalapao();
	void insertZalapao(const int day,const int zalapao,const int number);
	void zalapaoOnDay(const int day);
	void zalapaoOnDay(const int day,const int zalapao);
	void zalapaoOnWeek();
	void zalapaoOnWeek(const int zalapao);
	void minZalapaoOnWeek();
	void minZalapaoOnDay(const int day);
private:
	int pao[7][4];
	/*	pao[i][j] 
		i 0-6 for Sunday-Saturday
		j 0-3 for moodang moosub cream puk
	*/
};

Zalapao::Zalapao()
{
	for(int i=0;i<week;i++)
	{
		for(int j=0;j<typeZalapao;j++)
		{
			pao[i][j] = 0;
		}
	}
}


void Zalapao::insertZalapao(const int day, const int zalapao, const int number)
{
	pao[day][zalapao] = number;
}

void Zalapao::zalapaoOnDay(int day)
{
	int n = 0;
	for(int i=0;i<typeZalapao;i++)
	{
		n+= pao[day][i]; 
	}
	cout  << "Zalapao on " << ConvertDay(day) << " => " << n << endl;
}

void Zalapao::zalapaoOnDay(const int day, const int zalapao)
{
	cout << ConvertType(zalapao) << " on " << ConvertDay(day) << " => " << pao[day][zalapao] << endl;
}

void Zalapao::zalapaoOnWeek()
{
	int n = 0;
	for(int i=0;i<week;i++)
	{
		for(int j=0;j<typeZalapao;j++)
		{
			n += pao[i][j];
		}
	}
	cout << "All zalapao on this week => " << n << endl;
}

void Zalapao::zalapaoOnWeek(const int zalapao)
{
	int n = 0;
	for(int i=0;i<week;i++)
	{
		n += pao[i][zalapao];
	}
	cout << ConvertType(zalapao) << " on week => " << n << endl;
}

void Zalapao::minZalapaoOnWeek()
{
	int min = 1000000000, n=0, zlp[typeZalapao];
	// Assign value of array.
	for(int a=0;a<typeZalapao;a++)
	{
		zlp[a]=0;
	}

	// Calculate number of Zalapao in week for each type.
	for(int j=0;j<typeZalapao;j++)
	{
		for(int i=0;i<week;i++)
		{
			n += pao[i][j];
		}
		zlp[j] = n;
		n=0;
	}
	//Compare number of Zalapao in week for each type.
	for(int j=0;j<typeZalapao;j++)
	{
		if(zlp[j]<min)
		{
			min = zlp[j];
		}
	}
	int k=0 ,count=0;
	for(int j=0;j<typeZalapao;j++)
	{
		if(min!=zlp[j])
		{
			zlp[j] = -1;
		}
		else
		{
			cout << "min zalapao on this week => " << ConvertType(j)<< endl;
		}
	}
}
void Zalapao::minZalapaoOnDay(const int day)
{
	int n=0, min=10000000;
	for(int j=0;j<typeZalapao;j++)
	{
		n = pao[day][j];
		if(n<min){min = n;}
		n = 0;
	}
	
	for (int j=0;j<typeZalapao;j++)
	{
		if(min == pao[day][j])
		{
			cout << "min zalapao on "<< ConvertDay(day) << " is => " << ConvertType(j) <<endl;
		}
	}
}

int main()
{
Zalapao A;
A.insertZalapao(0,3,17);
A.insertZalapao(1,3,17);
A.insertZalapao(2,0,16);
A.insertZalapao(5,0,18);
A.insertZalapao(3,1,15);
A.insertZalapao(4,2,22);
A.insertZalapao(5,2,20);
A.insertZalapao(6,1,29);


A.zalapaoOnDay(5);
A.zalapaoOnDay(5,0);
A.zalapaoOnWeek();
A.zalapaoOnWeek(3);
A.minZalapaoOnWeek();
A.minZalapaoOnDay(4);
return 0;
}


string ConvertDay(const int day)
{
	switch(day)
	{
	case 0:
		return "Sunday";
	case 1:
		return "Monday";
	case 2:
		return "Tuseday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thursday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";

	default:
		return "NoDay";
	}
	
}


string ConvertType(const int type)
{
	switch(type)
	{
	case 0:
		return "moodang";
	case 1:
		return "moosub";
	case 2:
		return "cream";
	case 3:
		return "puk";
	default:
		return "NoType";
	}
}





