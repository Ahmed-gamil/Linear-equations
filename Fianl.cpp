#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class equations
{
public:
	string equ;
	int v1, v2, v3, numofvar;
	float x1, x2, x3, cons;

public:
	equations()
	{
		this->v1 = 0;
		this->v2 = 0;
		this->v3 = 0;
		this->numofvar = 0;
	}
};
void main()
{
	int n;
	equations eq;
	string equation;
	cout << "How many equations : ";
	cin >> n;
	char va = 'x';
	cout << "Enter the equations" << endl;
	vector <equations>  varr;

	for (int i = 0;i < n;i++)
	{
		cout << i + 1 << " ";
		cin >> eq.equ;
		varr.push_back(eq);
	}
	cout << "------proper form------" << endl;
	for (int k = 0;k < n;k++)
	{

		cout << k + 1 << " ";
		equation = varr[k].equ;
		float x1 = 0, x2 = 0, x3 = 0, cons = 0, cona;
		int sign = 1;
		string subequ;

		bool afterequal = false;

		for (int i = 0;i < equation.size();i++)
		{

			if (!afterequal)
			{
				if (equation[i] == '+' || equation[i] == '-' || equation[i] == '=')
				{
					if (i != 0)
					{
						if (equation[i - 1] >= '0' && equation[i - 1] <= '9')
						{
							if (i >= 2)
							{
								if (equation[i - 2] < 'a'&&equation[i - 2]>'z')
								{
									cons += (sign*stof(subequ));

								}
							}
							else
								cons += (sign*stof(subequ));


							subequ = "";
						}
					}
					if (equation[i] == '+')
						sign = 1;
					else sign = -1;

				}

				else if (equation[i] >= 'a'&& equation[i] <= 'z')
				{
					va = equation[i];
					if (equation[i + 1] == '1')
					{
						varr[k].v1 = 1;
						x1 += (sign*stof(subequ));
					}
					else if (equation[i + 1] == '2')
					{
						varr[k].v2 = 1;
						x2 += (sign*stof(subequ));
					}
					else if (equation[i + 1] == '3')
					{
						varr[k].v3 = 1;
						x3 += (sign*stof(subequ));
					}
					subequ = "";
					i++;
				}

				else
				{
					subequ += equation[i];
				}
				if (equation[i] == '=')
				{
					afterequal = true;subequ = "";
				}

			}
			else
			{
				subequ += equation[i];
			}
		}
		cona = stof(subequ);
		varr[k].numofvar = varr[k].v1 + varr[k].v2 + varr[k].v3;
		float constant = (-1 * cons) + cona;
		ostringstream xx1, xx2, xx3, xo;
		xx1 << x1;xx3 << x3;xx2 << x2;xo << constant;
		varr[k].equ = (xx1.str() + va + "1+" + xx2.str() + va + "2+" + xx3.str() + va + "3=" + xo.str());
		varr[k].x1 = x1;varr[k].x2 = x2;varr[k].x3 = x3;varr[k].cons = constant;
		cout << x1 << va << "1+" << x2 << va << "2+" << x3 << va << "3 = " << (-1 * cons) + cona << endl;
	}

	cout << "------operations------" << endl;
	cout << "1 To preview num of vars" << endl;
	cout << "2 print equation number i " << endl;
	cout << "3 column of x2 " << endl;
	cout << "4 add 1 3 " << endl;
	cout << "5 subtract 1 3 " << endl;
	cout << "6 substitute x2 1 3 " << endl;
	cout << "7 D operation " << endl;
	cout << "8 D x2 operation " << endl;
	cout << "9 D_value " << endl;
	cout << "10 solve " << endl;
	cout << "11 to exit" << endl;
	int choice;
	bool operation = true;
	do
	{
		cout << "**********_____**********" << endl;
		cout << "enter your choice : ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "eqnum   equations    \t num of var." << endl;
			for (int i = 0;i < n;i++)
			{
				cout << " " << i + 1 << " ";
				cout << "\t" << varr[i].equ << "\t\t   " << varr[i].numofvar << endl;
			}
		}
		else if (choice == 2)
		{
			int equnum;
			cout << "enter equation number ";
			cin >> equnum;
			cout << varr[equnum - 1].equ << endl;

		}
		else if (choice == 3)
		{
			cout << "eqnum\t x2 coff" << endl;
			for (int i = 0;i < n;i++)
			{
				cout << " " << i + 1 << " \t" << varr[i].x2 << endl;
			}
		}
		else if (choice == 4)
		{
			equations res;
			res.x1 = varr[0].x1 + varr[2].x1;
			res.x2 = varr[0].x2 + varr[2].x2;
			res.x3 = varr[0].x3 + varr[2].x3;
			res.cons = varr[0].cons + varr[2].cons;
			ostringstream xx1, xx2, xx3, xo;
			xx1 << res.x1;xx3 << res.x3; xx2 << res.x2;xo << res.cons;
			res.equ = (xx1.str() + va + "1+" + xx2.str() + va + "2+" + xx3.str() + va + "3=" + xo.str());
			cout << "result = " << res.equ << endl;
		}
		else if (choice == 5) {

			equations res;
			res.x1 = varr[0].x1 - varr[2].x1;
			res.x2 = varr[0].x2 - varr[2].x2;
			res.x3 = varr[0].x3 - varr[2].x3;
			res.cons = varr[0].cons - varr[2].cons;
			ostringstream xx1, xx2, xx3, xo;
			xx1 << res.x1;xx3 << res.x3; xx2 << res.x2;xo << res.cons;
			res.equ = (xx1.str() + va + "1+" + xx2.str() + va + "2+" + xx3.str() + va + "3=" + xo.str());
			cout << "result = " << res.equ << endl;
		}
		else if (choice == 6)
		{
			equations tx2;
			float a;
			a = varr[2].x1;
			a = a*(-1);
			a = a / varr[2].x2;
			a = a*varr[0].x2;
			tx2.x1 = a;

			a = varr[2].x3;
			a = a*(-1);
			a = a / varr[2].x2;
			a = a*varr[0].x2;
			tx2.x3 = a;

			a = varr[2].cons;
			a = a / varr[2].x2;
			a = a*varr[0].x2;
			tx2.cons = a;


			equations res;
			res.x1 = tx2.x1 + varr[0].x1;
			res.x3 = tx2.x3 + varr[0].x3;
			res.cons = varr[0].cons - tx2.cons;
			ostringstream xx1, xx3, xo;
			xx1 << res.x1;xx3 << res.x3; xo << res.cons;
			res.equ = (xx1.str() + va + "1+" + xx3.str() + va + "3=" + xo.str());
			cout << "result = " << res.equ << endl;
		}
		else if (choice == 7)
		{
			for (int i = 0;i < n;i++)
			{
				cout << varr[i].x1 << "\t" << varr[i].x2 << "\t" << varr[i].x3 << "\t" << endl;
			}

		}
		else if (choice == 8) {
			for (int i = 0;i < n;i++)
			{
				cout << varr[i].x1 << "\t" << varr[i].cons << "\t" << varr[i].x3 << "\t" << endl;
			}
		}
		else if (choice == 9)
		{
			cout << (varr[0].x1*((varr[1].x2*varr[2].x3) - (varr[1].x3)*varr[2].x2)) - (varr[1].x1*((varr[0].x2*varr[2].x3) - (varr[0].x3)*varr[2].x2)) + (varr[2].x1*((varr[0].x2*varr[1].x3) - (varr[0].x3)*varr[1].x2)) << endl;
		}
		else if (choice == 10)
		{
			float a, b, c, d, l, m, n, k, p, q, r, s;
			a = varr[0].x1;
			b = varr[0].x2;
			c = varr[0].x3;
			d = varr[0].cons*(-1);

			l = varr[1].x1;
			m = varr[1].x2;
			n = varr[1].x3;
			k = varr[1].cons*(-1);

			p = varr[2].x1;
			q = varr[2].x2;
			r = varr[2].x3;
			s = varr[2].cons*(-1);


			float D = (a*m*r + b*p*n + c*l*q) - (a*n*q + b*l*r + c*m*p);
			float x = ((b*r*k + c*m*s + d*n*q) - (b*n*s + c*q*k + d*m*r)) / D;
			float y = ((a*n*s + c*p*k + d*l*r) - (a*r*k + c*l*s + d*n*p)) / D;
			float z = ((a*q*k + b*l*s + d*m*p) - (a*m*s + b*p*k + d*l*q)) / D;
			cout << va << "1 = " << x << endl << va << "2 = " << y << endl << va << "3 = " << z << endl;

		}
		else if (choice == 11)
		{
			operation = false;
		}

	} while (operation);
}