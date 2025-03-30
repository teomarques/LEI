/*
 * prob01.c
 * 
 * Copyright 2013 Bruno Cabral <bcabral@bcabral-VirtualBox>
 * 
 * This program is free softwa#include <pthread.h>re; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define N 2

typedef struct comunicacao_maquina_balcao {
	pthread_mutex_t mutexes[N];
	pthread_cond_t cond_var_go[N];
	int num_senha[N];

} struct_sh_mem;


struct_sh_mem *sh_mem;
int shmid;
//int balcao_id;
int num_senha_atendida = 0;
sem_t sem_num_cliente;

//PROCESSOS Máquina de Senhas
void maquina_de_senhas() {
	int i = 0, balcao;
	while(1) {
		balcao = (rand()% (N));
		fprintf(stderr, "Máquina à espera de mutex para balcão %d\n", balcao);
		pthread_mutex_lock(&sh_mem->mutexes[balcao]);
		sh_mem->num_senha[balcao]++;
		
		fprintf(stderr,"Máquina %d emitiu nova senha com número %d para balcão %d\n", 
			getpid(), sh_mem->num_senha[balcao], balcao);
		
		pthread_cond_broadcast(&sh_mem->cond_var_go[balcao]);
		pthread_mutex_unlock(&sh_mem->mutexes[balcao]);
		
		i++;
		sleep(rand()%5);
	}
	return;
}

//THREAD atendimento ao cliente
void* atendimento(void* p) {
	int balcao_id = *(int*)p;
	fprintf(stderr,"Atendimento do balcão %d arrancou\n", balcao_id);
	while (1) {
		pthread_mutex_lock(&sh_mem->mutexes[balcao_id]);
		while (num_senha_atendida == sh_mem->num_senha[balcao_id]) {
			fprintf(stderr,"Atendimento %d aguarda. Senha atual=%d. Senha atentida=%d\n", balcao_id, num_senha_atendida,
			sh_mem->num_senha[balcao_id]);
			pthread_cond_wait(&sh_mem->cond_var_go[balcao_id], &sh_mem->mutexes[balcao_id]);
		}
			
		num_senha_atendida++;
		fprintf(stderr, "Atendi mais um cliente no balcão %d!\n", balcao_id);
		pthread_mutex_unlock(&sh_mem->mutexes[balcao_id]);	
	}
	fprintf(stderr,"Thread de atendimento a TERMINAR!\n");
	pthread_exit(0);
}



//PROCESSOS Balcão de atendimento
void balcao(int id) {
	int i;
	pthread_t my_thread[N];
	//balcao_id = id;
	fprintf(stderr,"Balcão nº %d abriu\n", id);
	
	for (i = 0; i < N; i++) {
		if (pthread_create(&my_thread[i], NULL, atendimento, &id))
			fprintf(stderr,"Criei thread %d do Balcão %d\n", i, id);
	}

	return;
}

//Inicializador do sistema
void inicializar() {
	fprintf(stderr,"Chamei o Inicializar!\n");
	int i;
	shmid = shmget(IPC_PRIVATE, sizeof(struct_sh_mem), IPC_CREAT|0777);
	sh_mem = (struct_sh_mem *) shmat(shmid, NULL, 0);	
	pthread_mutexattr_t mattr;
	pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);
	pthread_condattr_t cattr;
	pthread_condattr_setpshared(&cattr, PTHREAD_PROCESS_SHARED);
	
	for (i = 0; i < N; i++) {
		pthread_cond_init(&sh_mem->cond_var_go[i], &cattr);
		pthread_mutex_init(&sh_mem->mutexes[i], &mattr);
		
		sh_mem->num_senha[i] = 0;
	}

	return;
}

//Limpar sistema
void terminar() {
	int i;
	for (i = 0; i < N; i++) {
		pthread_cond_destroy(&sh_mem->cond_var_go[i]);
		pthread_mutex_destroy(&sh_mem->mutexes[i]);
	}

	shmdt(sh_mem);
	shmctl(shmid, IPC_RMID, NULL);
	return;
}

int main(int argc, char **argv)
{
	int i;
	
	inicializar();
	
	for (i = 0; i < N; i++)
		if (fork() == 0) {
			maquina_de_senhas();
			exit(0);
		}
	for (i = 0; i < N; i++)
		if (fork() == 0) {
			balcao(i);
			exit(0);
		}
	
	while (wait(NULL)!=-1);
	terminar();
	return 0;
}

