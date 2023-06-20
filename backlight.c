#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "config.h"

void print_usage() {
	printf("Usage:\n\tbacklight +\n\tbacklight -\n");
    printf("\tbacklight s int\nwhere %d <= int <= %d\n\n", min, max);
    printf("See the man page backlight(1) for details on exit codes.\n");
}

int main(int argc, char *argv[]) {

	if (argc < 2) {
        print_usage();
		exit(2);
	}

    int brightness_value;
    char *p;
	
    // get current value
	FILE * pFile;
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
			if(brightness_value <= max - 10*smallstep && brightness_value > 9*smallstep)
				brightness_value += bigstep;
			else if (brightness_value < max)
				brightness_value += smallstep;
			break;
		case '-':
			if(brightness_value >=  15*smallstep)
				brightness_value -= bigstep;
			else if (brightness_value > min) 
				brightness_value -= smallstep;
			break;
        case 's':
            if (argc < 3) {
                print_usage();
                exit(2);
            }

            int value = (int)strtol(argv[2], &p, 10);
            
            if (errno != 0 || *p != '\0' || value > max || value < min) {
                print_usage();
                exit(2);
            }
                brightness_value = value;
            break;
		default:
            print_usage();
            exit(2);
	}

	// write new value
	pFile = fopen(filename, "w");
	if (pFile == NULL) {
		exit(1);
	}

	fprintf(pFile, "%d", brightness_value);
	fclose(pFile);

	return 0;

}


