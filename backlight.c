#include <stdio.h>
#include <stdlib.h>

const char filename[] = "/sys/class/backlight/intel_backlight/brightness";

const int MIN = 0;
const int MAX = 1060;
const int BIGSTEP = 5;
const int SMALLSTEP = 1;

int main(int argc, char *argv[]) {

	if (argc < 2) {
		exit(1);
	}

	// get current value
	FILE * pFile;
	int brightness_value;
	pFile = fopen (filename, "r");
	if (pFile != NULL) {
		fscanf(pFile, "%d", &brightness_value);
		fclose(pFile);
	} else {
		exit(1);
	}

	// find new value
	switch (*argv[1]) {
		case '+':
			if(brightness_value <= MAX - 10*SMALLSTEP && brightness_value > 9*SMALLSTEP)
				brightness_value += BIGSTEP;
			else if (brightness_value < MAX)
				brightness_value += SMALLSTEP;
			break;
		case '-':
			if(brightness_value >=  15*SMALLSTEP)
				brightness_value -= BIGSTEP;
			else if (brightness_value > MIN) 
				brightness_value -= SMALLSTEP;
			break;
		default:
			printf("Invalid argument passed.  Use + or -\n"); 
	}

	// write new value
	pFile = fopen(filename, "w");
	if (pFile == NULL) {
		printf("Error opening file\n");
		exit(1);
	}

	fprintf(pFile, "%d", brightness_value);
	fclose(pFile);

	return 0;

}


