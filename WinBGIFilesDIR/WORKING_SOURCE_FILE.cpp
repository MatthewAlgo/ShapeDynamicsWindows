#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
#include <vector>
#include "graphics.h"
using namespace std;
vector <int> xpoint;
vector <int> ypoint;
vector <int> ice1;
vector <int> ice2;
vector <int> ige1;
vector <int> ige2;
long long cnt = -1, cntor = -1, coster = 0, contor = 0;
bool ver = 0;
long long g = 0;
int previc1, previc2, previg1, previg2,ic1,ic2,ig1,ig2;
unsigned long long mini = 2000000000;
double RDOUBLE(double min, double max)
{
	double r = (double)rand() / (double)RAND_MAX;
	return min + r * (max - min);
}
double generateRandomNumberInRange(double lowEnd, double highEnd)
{
	srand(time(NULL));
	if (highEnd < lowEnd)
	{
		double tempForSwap = highEnd;
		highEnd = lowEnd;
		lowEnd = tempForSwap;
	}

	int rangeVal = (highEnd - lowEnd) + 1;
	return (std::rand() % rangeVal) + lowEnd;
}
void calculaterandompoint(double x1, double y1, double x2, double y2,double &pointx,double &pointy) {
	double randomx = RDOUBLE(x1, x2);
	double randomy = RDOUBLE(y2, y1);
	pointx = randomx;
	pointy = randomy;
}
double trand(double lower, double upper) {
	std::random_device random_device;
	std::mt19937 random_engine(random_device());
	std::uniform_int_distribution<int> distribution_1_1000(lower, upper);

	double randomNumber = distribution_1_1000(random_engine);

	return (double)randomNumber;
}
void drawpoints() {
	coster++;
	if (coster % 100 == 0) {
		//cleardevice();
	}
	for (unsigned int i = 0; i <= cnt; i++) {
		if (getpixel(xpoint[i], ypoint[i]) == WHITE) {
			xpoint.erase(xpoint.begin()+i);
			contor++;
			ypoint.erase(ypoint.begin() + i);
			cnt--;
		}
		else {
			putpixel(xpoint[i], ypoint[i], YELLOW);
		}
	}
}
void determinepoints() {
	cnt++;
	ypoint.push_back(trand(0, 1000));
	xpoint.push_back(0);
	cnt++;
	ypoint.push_back(trand(0, 1000));
	xpoint.push_back(0);
	cnt++;
	ypoint.push_back(trand(0, 1000));
	xpoint.push_back(0);
	for (unsigned int i = 0; i <= cnt; i++) {
		xpoint[i]++;
	}
	/*
	cnt++;
	ypoint.push_back(trand(0, 1000));
	xpoint.push_back(0);
	cnt++;
	ypoint.push_back(trand(0, 1000));
	xpoint.push_back(0);
	cnt++;
	ypoint.push_back(trand(0, 1000));
	xpoint.push_back(0);*/
	drawpoints();
}
void showreports() {
	cout << endl<<endl<<"_________________CURRENT REPORT_________________"<<endl;
	cout << "CURRENT SHAPE WITH MAXIMUM DYNAMIC CAPACITY TOOK " << mini << " PARTICLE COLLISIONS"<<endl;
	cout << "THE CURRENT SHAPE TOOK " << contor << " PARTICLE COLLISIONS"<<endl;
	if (contor < mini) {
		cout << "THE CURRENT SHAPE IS MORE AERODYNAMIC THAN THE PREVIOUS ONES"<<endl;
	}else{
		cout << "THE CURRENT SHAPE ISN'T MORE AERODYNAMIC THAN THE PREVIOUS ONES. IT WON'T BE REPLACED" << endl;
	}
}
void determinerandom() {
	for (unsigned int i = 200; i <= 750; i += 50) {
		cntor++;
		ice1.push_back(trand(i, i + 50));
		ige1.push_back(trand(100, 500));
		ige2.push_back(trand(500, 900));
		ice2.push_back(trand(i, i + 50));
	}
}
void redrawshape() {
	for (unsigned int i = 0; i <= cntor; i++) {
		circle(ice1[i], ige1[i], 5);
		circle(ice2[i], ige2[i], 5);
		if (i == 0) {
			line(ice1[i], ige1[i], ice2[i], ige2[i]);
		}
		else {
			line(ice1[i], ige1[i],ice1[i-1],ige1[i-1]);
			line(ice2[i], ige2[i], ice2[i-1], ige2[i-1]);
		}
	}
	line(ice1.back(), ige1.back(), ice2.back(), ige2.back());
}
void drawcoords() {
	setcolor(YELLOW);
	line(0, 500, 1000, 500);
	line(500, 0, 500, 1000);
	setcolor(WHITE);
}
int main() {
	double pointx, pointy;
	int window1 = initwindow(1000, 1000, "AEROHAULDRON");
	int window2 = initwindow(1000, 1000, "TEST AERODYNAMICS");
	//calculaterandompoint(1, 1000, 1000, 1, pointx, pointy);
	/*
	//FIRST VERTICAL
	circle(trand(200,250), trand(0,500), 20);
	circle(trand(200, 250), trand(500, 1000), 20);
	//Second
	circle(trand(250, 300), trand(0, 500), 20);
	//Third
	circle(trand(300, 350), trand(0, 500), 20);
	//Fourth
	circle(trand(350, 400), trand(0, 500), 20);
	//Fifth
	circle(trand(400, 450), trand(0, 500), 20);
	//Sixth
	circle(trand(450, 500), trand(0, 500), 20);
	//Seventh
	circle(trand(500, 550), trand(0, 500), 20);
	//Eightth
	circle(trand(550, 600), trand(0, 500), 20);
	//Nineth
	circle(trand(600, 650), trand(0, 333), 20);
	//Tenth
	circle(trand(650, 700), trand(0, 333), 20);
	*/
	//////
	/*
	for (unsigned int i = 200; i <= 750; i+=50) {
		ic1 = trand(i, i + 50);
		ig1 = trand(100, 500);
		ig2 = trand(500, 900);
		ic2 = trand(i, i + 50);
		circle(ic1, ig1, 5);
		circle(ic2, ig2, 5);
		if (i == 200) {
			line(ic1, ig1, ic2, ig2);
			previc1 = ic1;
			previg1 = ig1;
			previc2 = ic2;
			previg2 = ig2;
		}
		else {
			line(ic1, ig1, previc1, previg1);
			line(ic2, ig2, previc2, previg2);
			previc1 = ic1;
			previg1 = ig1;
			previc2 = ic2;
			previg2 = ig2;
		}
	}
	line(ic1, ig1, ic2, ig2);
	*/
	while(1){
		g++;
		setcurrentwindow(window1);
		cnt = -1; cntor = -1;
		coster = 0; contor = 0;
		xpoint.clear();
		ypoint.clear();
		ice1.clear();
		ice2.clear();
		ige1.clear();
		ige2.clear();
		cleardevice();
		determinerandom();
		if (g == 1) {
			setcurrentwindow(window2);
			cleardevice();
			redrawshape();
			drawcoords();
			setcurrentwindow(window1);
		}
		redrawshape();
		for (unsigned int i = 1; i <= 1000; i++) {
			determinepoints();
			cout <<"NUMBER OF PARTICLE HITS PER CURRENT SHAPE: "<< contor << endl;
		}
		showreports();
		if (contor < mini) {
			mini = contor;
			setcurrentwindow(window2);
			cleardevice();
			redrawshape();
			drawcoords();
		}
		delay(3000);
	}
	delay(100000);
	return 0;
}

