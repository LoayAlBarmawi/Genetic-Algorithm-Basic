#include <iostream>
#include<time.h>
#include<vector>
#include<algorithm>
#include <math.h>
using namespace std;

const int target[1000] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,0,1,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
//a picture of groot translated into 1s and 0s reference picture in the folder
int random_num(int start, int end)
{
	int range = (end - start);
	int random_int = start + (rand() % range);
	return random_int;
}

class arr {
public:
	int  chromosome[1000];
	int fitness;
	arr(int chromo[]);
	arr cross(arr p2);
	int calculatefitness();
	void mutate();
};
arr::arr(int chromo[]) {
	for (int i = 0;i < 1000;i++) {
		chromosome[i] = chromo[i];
	}
	fitness = calculatefitness();
};
void arr::mutate() {
	int r = random_num(0, 1000);
	if (chromosome[r] == 0) chromosome[r] = 1;
	else chromosome[r] = 0;
	 r = random_num(0, 1000);
	if (chromosome[r] == 0) chromosome[r] = 1;
	else chromosome[r] = 0;
	 r = random_num(0, 1000);
	if (chromosome[r] == 0) chromosome[r] = 1;
	else chromosome[r] = 0;
	 r = random_num(0, 1000);
	if (chromosome[r] == 0) chromosome[r] = 1;
	else chromosome[r] = 0;
	 r = random_num(0, 1000);
	if (chromosome[r] == 0) chromosome[r] = 1;
	else chromosome[r] = 0;
	 r = random_num(0, 1000);
	if (chromosome[r] == 0) chromosome[r] = 1;
	else chromosome[r] = 0;
	 r = random_num(0, 1000);
	if (chromosome[r] == 0) chromosome[r] = 1;
	else chromosome[r] = 0;
	 r = random_num(0, 1000);
	if (chromosome[r] == 0) chromosome[r] = 1;
	else chromosome[r] = 0;
	 r = random_num(0, 1000);
	if (chromosome[r] == 0) chromosome[r] = 1;
	else chromosome[r] = 0;
	r = random_num(0, 1000);
	if (chromosome[r] == 0) chromosome[r] = 1;
	else chromosome[r] = 0;
};
arr arr::cross(arr p2) {
	int offspring[1000];
	int r = random_num(0, 999);
	for (int i = 0;i < r;i++)
		offspring[i] = chromosome[i];
	for (int i = r;i < 1000;i++)
		offspring[i] = p2.chromosome[i];
	return arr(offspring);
};
int arr::calculatefitness() {

	int distance, c = 0;
	for (int i = 0;i < 1000;i++) {
		if (chromosome[i] != target[i]) c++;
	}


	distance = c;
	return distance;
};


bool operator<(arr &ind1, arr &ind2)
{

	return ind1.calculatefitness() < ind2.calculatefitness();

}

int main() {

	srand((unsigned)(time(0)));
	int generation = 0;
	vector<arr> population;

	int a[1000],b[1000],c[1000],d[1000],e[1000],f[1000],g[1000],h[1000];
	for (int i = 0;i < 1000;i++) {
		a[i] = random_num(0, 1);
	}
	for (int i = 0;i < 1000;i++) {
		b[i] = random_num(0, 1);
	}
	for (int i = 0;i < 1000;i++) {
		c[i] = random_num(0, 1);
	}
	for (int i = 0;i < 1000;i++) {
		d[i] = random_num(0, 1);
	}
	for (int i = 0;i < 1000;i++) {
		e[i] = random_num(0, 1);
	}
	for (int i = 0;i < 1000;i++) {
		f[i] = random_num(0, 1);
	}
	for (int i = 0;i < 1000;i++) {
		g[i] = random_num(0, 1);
	}
	for (int i = 0;i < 1000;i++) {
		h[i] = random_num(0, 1);
	}
	arr a1(a);
	arr c1(c);
	arr b1(b);
	arr d1(d);
	arr e1(e);
	arr f1(f);
	arr g1(g);
	arr h1(h);
	population.push_back(a1);
	population.push_back(b1);
	population.push_back(c1);
	population.push_back(d1);
	population.push_back(e1);
	population.push_back(f1);
	population.push_back(g1);
	population.push_back(h1);
	bool found = false;


	while (!found) {
		sort(population.begin(), population.end());
		int f = population[0].calculatefitness();
		if (f == 0) {
			found = true;
			break;
		}


		vector<arr> nextgen;

		nextgen.push_back(population[0]);

		nextgen.push_back(population[1]);
		nextgen.push_back(population[2]);

		nextgen.push_back(population[3]);
		arr p1 = nextgen[0];

		arr p2 = nextgen[1];
		arr offs1 = p1.cross(p2);
		nextgen.push_back(offs1);
		arr offs2 = p2.cross(p1);
		nextgen.push_back(offs2);
		arr p3 = nextgen[2];

		arr p4 = nextgen[3];
		arr offs3 = p3.cross(p4);
		nextgen.push_back(offs3);
		arr offs4 = p4.cross(p3);
		nextgen.push_back(offs4);
		int p = random_num(0, 7);
		nextgen[p].mutate();
		p = random_num(0, 7);
		nextgen[p].mutate();
		population = nextgen;
		cout << "Gen:" << generation << "\n";
		cout << "Arrays:" << "\n";

		for (int j = 0;j < 1000;j++) {

			if (j % 25 == 0) {
				cout << "\n";
			}
			cout << population[0].chromosome[j];


		}
		cout << "\n Fitness:" << population[0].calculatefitness();
		cout << "\n";


		generation++;

	}
	cout << "Gen:" << generation << "\n";
	cout << "Arrays:" << "\n";

	for (int j = 0;j < 1000;j++) {
		if (j % 25 == 0) {
			cout << "\n";
		}
		cout << population[0].chromosome[j];
	}
	cout << "\n Fitness:" << population[0].calculatefitness();
	cout << "\n";

	system("pause");
}
