#include<iostream>
using namespace std;
struct Students {
	char name[50];
	int age;
	float cgpa;

};
 static float std_avg(Students arr[], int size) {
	float avg = 0;
	for (int i = 0; i < size ; i++) {
		avg += arr[i].cgpa;

	}
	return avg / size;
}

 static void sortstudentsbygpa(Students* arr1, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-i-1; j++) {
			if (arr1[j].cgpa < arr1[j + 1].cgpa) {
				Students temp = arr1[j];
				arr1[j].age = arr1[j + 1].age;
				arr1[j].cgpa = arr1[j+1].cgpa;
				int len = 0;
				while (arr1[j+1].name[len] != '\0') {
					len++;
				}
				for (int k = 0; k < len; k++) {
					arr1[j].name[k] = arr1[j + 1].name[k];
				}
				arr1[j].name[len] = '\0';

				arr1[j + 1].age = temp.age;
				arr1[j + 1].cgpa = temp.cgpa;
				
				int l = 0;
				while (temp.name[l] != '\0') {
					l++;
				}
				for (int k = 0; k < l; k++) {
					arr1[j + 1].name[k] = temp.name[k];
				}
				arr1[j + 1].name[l] = '\0';

			}
		}
	}
}




int main() {
	Students arr[5];
	for (int i = 0; i < 5; i++) {
		cout << "enter the data for  : " << i + 1 <<endl;
		cout << "Name : "<<endl;
		cin.ignore();
		cin.getline(arr[i].name, 50);
		cout << "Age :"<<endl;
		cin >> arr[i].age;
		cout << "cgpa : "<<endl;
		cin >> arr[i].cgpa;


	}
	for (int i = 0; i < 5; i++) {
		cout << "\t\tStudnts Credentials : ";
		cout << arr[i].name<<endl;
		cout << arr[i].age << endl;
		cout << arr[i].cgpa << endl;


	}
	cout << "Average Cgpa of Students : " << std_avg(arr, 5) << endl;

	sortstudentsbygpa(arr, 5);
	for (int i = 0; i < 5; i++) {
		cout << "\t\tStudnts Credentials : ";
		cout << arr[i].name << endl;
		cout << arr[i].age << endl;
		cout << arr[i].cgpa << endl;


	}

	return 0;
}