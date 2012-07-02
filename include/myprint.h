using namespace std;

template <class t> void printBin(t value){
	unsigned long mask;
	int size = sizeof(value) * 8;
	mask = (1 << (size - 1));
	for(int i = size - 1; i >= 0; i--){
		cout << (unsigned short) (((mask & value) >> i) & 1);
		mask >>= 1;
	}
}

template <class t> void printHex(t value){
	unsigned long int mask;
	char temp;
	unsigned int size = sizeof(value) * 8;
	mask = (0xF << (size - 4));
	for(int i = (size / 4) - 1; i >= 0; i--){
		temp = (unsigned short) (((mask & value) >> i * 4) & 0xF) + '0';
		if(temp > '9') temp = temp - '0' - 10 + 'A';
		cout << temp;
		mask >>= 4;
	}
}
