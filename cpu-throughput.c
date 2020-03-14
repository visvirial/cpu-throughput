/**
 * @file cpu-throughput.c
 * @author Masahiko Hyuga <mail@mhyuga.jp>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define LOOP (1000 * 1000 * 1000)

double microtime(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + 1e-6 * tv.tv_usec;
}

double add() {
	double a = 0;
	double b = 1;
	double c;
	for(size_t i=0; i<LOOP; i++) {
		c = a + b;
	}
	return a;
}

int main(int argc, char *argv[]) {
	
	if(argc < 2) {
		printf("Usage: %s (add)\n", argv[0]);
		return 1;
	}
	
	double begin = microtime();
	
	if(strcmp(argv[1], "add") == 0) {
		add();
	} else {
		printf("E: unknown argument: %s\n", argv[1]);
		return 1;
	}
	
	double end = microtime();
	printf("%.2lf mega instructions per sec.\n", LOOP / (end - begin) * 1e-6);
	
}

