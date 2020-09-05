#include <iostream>
#include<time.h>
#include<vector>
#include<algorithm>
#include <math.h>
using namespace std;

const int target[25] = {1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1};
int random_num(int start, int end)
{
	int range = (end - start) ;
	int random_int = start + (rand() % range);
	return random_int;
}

class arr {
public:
	int  chromosome[25];
	float fitness;
	arr(int chromo[]);
	arr cross(arr p2);
	float calculatefitness();
	void mutate();
};
arr::arr(int chromo[]) {
	for (int i = 0;i < 25;i++){
		chromosome[i]=chromo[i]  ;
}
	fitness = calculatefitness();
};
void arr::mutate() {
int r = random_num(0, 25);
if (chromosome[r] == 0) chromosome[r] = 1;
else chromosome[r] = 0;
};
arr arr::cross(arr p2) {
	int offspring[25];
	int r = random_num(0, 24);
	for (int i = 0;i < r;i++)
		offspring[i] = chromosome[i];
	for (int i = r;i < 25;i++)
		offspring[i] = p2.chromosome[i];
	return arr(offspring);
};
float arr::calculatefitness() {
	float distance=0, f;
	for (int i = 0;i < 25;i++) {
		distance = distance + pow( (chromosome[i] - target[i]),2);
	}
	distance = sqrt(distance);
	f =  distance;
	return f;

};


bool operator<( arr &l1,  arr &l2)
{
	
	return l1.calculatefitness() < l2.calculatefitness();
	
}

int main() {

	srand((unsigned)(time(0)));
	int generation = 0;
	vector<arr> population;
	
	int a[25] = { 1,1,1,1,1,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,0,0,0,1 }, b[25] = {0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0}, c[25] = {1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,1}, d[25] = {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,0,0,1};
	arr a1(a);
	arr c1(c);
	arr b1(b);
	arr d1(d);
	population.push_back(a1);
	population.push_back(b1);
	population.push_back(c1);
	population.push_back(d1);
	bool found = false;


	while (!found){
		sort(population.begin(), population.end());
		float f = population[0].calculatefitness();
			if (f== 0) {
				found = true;
				break;
			}
		
		
		vector<arr> nextgen;
		
			nextgen.push_back(population[0]);
		
			nextgen.push_back(population[1]);
		
		arr p1 = nextgen[0];
	
		arr p2 = nextgen[1];
		arr offs1=p1.cross(p2);
		nextgen.push_back(offs1);
		arr offs2 = p2.cross(p1);
		nextgen.push_back(offs2);
		int p = random_num(0, 3);
		nextgen[0].mutate();
		population = nextgen;
		cout << "Gen:" << generation<<"\n";
		cout << "Arrays:" <<"\n";
		
			for (int j = 0;j < 25;j++) {
				
					if (j % 5 == 0) {
						cout << "\n";
					}
					cout << population[0].chromosome[j];
				
				
			}
			cout << "\n Fitness:" << (1/(1+population[0].calculatefitness()));
			cout << "\n";
			
		
		generation++;
	
	}
	cout << "Gen:" << generation << "\n";
	cout << "Arrays:" << "\n";
	
		for (int j = 0;j < 25;j++) {
			if (j % 5 == 0) {
				cout << "\n";
			}
			cout << population[0].chromosome[j];
		}
		cout << "\n Fitness:" << (1 / (1 + population[0].calculatefitness()));
		cout << "\n";
	
	system("pause");
}
