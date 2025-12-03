#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14 
#define DT 0.01 // 시간 간격 (0.01초)
#define G 9.81 // 중력 가속도

// 함수: 물로켓의 비행을 시뮬레이션하고 결과를 포인터로 반환
// *time: 체공 시간을 저장할 변수의 주소
// *height: 최고 높이를 저장할 변수의 주소
// *range: 수평 사거리를 저장할 변수의 주소
void calculate_flight_simple(float v0, float angle_deg,
    float* time, float* height, float* range) {

    // 1. 초기 속도와 각도 설정
    const float angle_rad = angle_deg * PI / 180.0;

    // 수평 속도 (Vx)는 비행 중 변하지 않습니다.
    float vx = v0 * cos(angle_rad);
    // 수직 속도 (Vy)는 중력 때문에 계속 변합니다.
    float vy = v0 * sin(angle_rad);

    // 현재 위치 및 시간
    float x_pos = 0.0;
    float y_pos = 0.0;
    float t_total = 0.0;

    // 최고 높이 추적 변수
    float max_h = 0.0;

    printf("--- 시뮬레이션 시작 (DT = %.2f초 간격) ---\n", DT);

    // 2. 비행 루프 (while 반복문)
    // y_pos가 0보다 클 때 (땅에 떨어지지 않았을 때) 계속 반복합니다.
    // **y_pos < 0.0이 되면 착지한 것으로 보고 루프를 멈춥니다.**
    while (y_pos >= 0.0) {

        // 1단계: 속도 업데이트 (중력 적용)
        // Vy = Vy - (G * DT)
        // DT 동안 중력(G)에 의해 속도가 감소합니다.
        vy = vy - (G * DT);

        // 2단계: 위치 업데이트
        // X_new = X_current + (Vx * DT)
        x_pos = x_pos + (vx * DT);
        // Y_new = Y_current + (Vy_new * DT) 
        y_pos = y_pos + (vy * DT);

        // 3단계: 시간 업데이트
        t_total = t_total + DT;

        // 4단계: 최고 높이 갱신
        if (y_pos > max_h) {
            max_h = y_pos;
        }

        // y_pos가 음수가 되면 (땅 아래로 내려가면) 루프를 종료합니다.
        if (y_pos < 0.0) {
            break;
        }
    }

    // 3. 포인터를 사용하여 main 함수로 결과 전달
    // *time = t_total; : t_total의 값을 time 포인터가 가리키는 곳에 저장합니다.
    *time = t_total;
    *height = max_h;
    *range = x_pos;
}

int main() {
    // 초기 조건 (문제에서 주어진 값)
    const float V0 = 15.0; // 초기 속도
    const float ANGLE = 75.0; // 발사 각도

    // 결과를 저장할 변수 선언 (값을 받기 위한 그릇)
    float time_of_flight, height_max, range_max;

    // 함수 호출
    // &time_of_flight : 변수의 주소(포인터)를 함수에 전달합니다.
    calculate_flight_simple(V0, ANGLE,
        &time_of_flight,
        &height_max,
        &range_max);

    // 최종 결과 출력
    printf("\n=========================================\n");
    printf("물로켓 비행 계산 결과\n");
    printf("=========================================\n");
    printf("1. 체공 시간:         %.2f [sec]\n", time_of_flight);
    printf("2. 최고 도달 높이:    %.2f [m]\n", height_max);
    printf("3. 수평 사거리:       %.2f [m]\n", range_max);
    printf("=========================================\n");

    return 0;
}