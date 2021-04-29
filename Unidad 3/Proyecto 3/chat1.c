#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>

#define SH_SIZE 16

int shared_fd = -1;
char mem[20];
int32_t *counter = NULL;
sem_t *semaphore = NULL;
sem_t *semaphore1 = NULL;

void init_control_mechanism() {
	semaphore = sem_open("sem0", O_CREAT, 0666, 0);
	if (semaphore == SEM_FAILED) {
		perror("Opening the semaphore failed: ");
		exit(EXIT_FAILURE);
	}
	semaphore1 = sem_open("sem1", O_CREAT, 0666, 0);
	if (semaphore == SEM_FAILED) {
		perror("Opening the semaphore failed: ");
		exit(EXIT_FAILURE);
	}
}