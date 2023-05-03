#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#define PNUM 5
#define PRINT_CYCLE 10000000
#define TOTAL_COUNTER 500000000

// SSU Scheduler 작동 확인 함수
void sdebug_func(){

	int n, pid;
	long long start_time, end_time;

	printf(1,"start sdebug command\n");
	
	// PNUM의 개수만큼 프로세스 생성	
	for(n=0;n<PNUM;n++){
		pid = fork();
		if(pid < 0){
			printf(1,"fork error\n");
			exit();
		} // 자식 프로세스라면
		if(pid == 0){
			int counter = 0; // tick 카운터
			int first = 1, print_counter = 0; // 출력 flag
			start_time = uptime(); // 자식 프로세스 시작 시간 측정
			weightset(n+1);	// 자식 프로세스에게 weight 값새로 부여

			// counter가 TOTAL_COUNTER에 도달하면 프로세스 종료
			for(counter=0;counter<TOTAL_COUNTER; counter++){

				// counter가 PRINT_CYCLE에 도달했을 때
				if(counter == PRINT_CYCLE){

					// 출력 flag가 0일 때
					if(print_counter == 0){
						if(first){
							end_time = uptime(); // 자식 프로세스 종료 시간 측정
							printf(1,"PID: %d, WEIGHT: %d, TIMES : %d ms\n", getpid(), n+1, (end_time - start_time)*10);
							first = 0; // flag 변경
						}
						print_counter = PRINT_CYCLE; // flag 변경
					}
				}
			}
			printf(1,"PID: %d terminated\n", getpid());
			exit();
			
		}
	}

	// for문을 통해 생성된 자식 프로세스의 수만큼 wait 하기
	for(; n > 0; n--){
		int p;
		if((p = wait()) < 0){
			printf(1, "wait stopped early\n");
			exit();
		}
	}

	if(wait() != -1){
		printf(1, "wait got too many\n");
		exit();
	}	

	printf(1,"end of sdebug command\n");
}

int main(){
	sdebug_func();
	exit();
}
