#include <iostream>
using namespace std;

void reversestr(const char* cptr) {
	int length = 0;
	while (cptr[length] != '\0') {
		length++;
	}
	cout << length << endl;
	int j = length - 1;
	char* arr = new char[length + 1];
	for (int i = 0; i < length; i++) {
		arr[i] = cptr[j];
		j--;
	}
	arr[length] = '\0';
	cout << arr;
	delete[] arr;

}
void countvowels( const char* cptr) {
	int l = 0;
	while (cptr[l] != '\0') {
		l++;
	}
	char* arr = new char[l+1];
	int count = 0;
	for (int i = 0; i < l; i++) {
		if(cptr[i] == 'a' || cptr[i] == 'e' || cptr[i] == 'i' || cptr[i] == 'o' || cptr[i] == 'u'
			cptr[i] == 'A' || cptr[i] == 'E' || cptr[i] == 'I' || cptr[i] == 'O' || cptr[i] == 'U'
			) {
			count++;
		}
	}
	cout << endl;
	cout << count;

}

int main() {
		
	const char* cptr = "Hello World";
	reversestr(cptr);
	countvowels(cptr);

	
	
	
	return 0;
}