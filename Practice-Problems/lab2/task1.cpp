#include <iostream>
using namespace std;

int stringlen(const char* arr) {
	int l = 0;
	while (arr[l] != '\0') {
		l++;
	}
	return l;
}

char* strcopy(const char* arr) {
	int l = stringlen(arr);

	char* my_str = new char[l + 1];
	for (int i = 0; i < l; i++) {
		my_str[i] = arr[i];
	}
	my_str[l] = '\0';
	return my_str;

}

int compstrings(const char* s1, const char* s2) {
	int l1 = stringlen(s1);
	int l2 = stringlen(s2);
	int i = 0;
	while (i < l1 && i < l2) {
		if (s1[i] == s2[i])
			return 0;
		else if (s1[i] < s2[i])
			return -1;
		else {
			return 1;
		}
		i++;
	}
	if (l1 == l2)
		return 0;
	else if (l1 > l2)
		return 1;
	else {
		return -1;
	}
}

int main() {
	char* arr1 = new char[100];
	char* arr2 = new char[100];

	cout << "enter the string1 : ";
	
	cin.getline(arr1, 100);
	

	char* str1 = strcopy(arr1);

	cout << "enter the string2 : ";
	//cin.ignore(100, '\0');
	cin.getline(arr2, 100);

	char* str2 = strcopy(arr2);

	cout << compstrings(str1, str2) << endl;


	delete[] str1;
	delete[] str2;




	

	
	
	return 0;
}