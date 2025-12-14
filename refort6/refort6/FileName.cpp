#include <stdio.h>  
#include <math.h> 

int main() {

    // 1단계: 상수 및 입력 데이터 정의와 단위 변환
  
    // --- 입력 조건 ---
    double P_MPa = 0.9;         // 압력 (MPa)
    double T_Celcius = 70.0;    // 온도 (섭씨 C)

    // --- R-134a 열역학 상수 ---
    double R_CONST = 0.08149;   // R-134a 기체 상수 (kJ/kg*K)
    double TCR = 374.2;         // 임계 온도 (K)
    double PCR = 4059.0;        // 임계 압력 (kPa)

    // --- 표 데이터 (기준값으로 사용) ---
    // 주의: 이 값은 코드로 계산되는 것이 아니라, 열역학 표를 보고 입력한 값입니다.
    double v_table = 0.02741;   // 표로부터의 비체적 (m^3/kg)

    // --- 단위 변환 ---
    double P_kPa = P_MPa * 1000.0;      // 0.9 MPa -> 900 kPa
    double T_K = T_Celcius + 273.15;    // 70 C -> 343.15 K

    // 결과값을 저장할 변수들
    double v_ideal;
    double v_chart;

    printf("R-134a 비체적 계산 프로젝트\n");
    printf("입력 조건: P=%.1f MPa, T=%.1f C\n", P_MPa, T_Celcius);
   
    // (a) 이상 기체 방정식 계산 및 출력
   
    // 수식: v = R * T / P
    v_ideal = (R_CONST * T_K) / P_kPa;

    printf("(a) 이상 기체 방정식 결과\n");
    printf("   [수식: v_ideal = R * T / P]\n");
    printf("   - 계산된 비체적 (v_ideal): %.5f m^3/kg\n", v_ideal);
   
    // (b) 일반화된 압축성 도표를 이용한 계산 및 출력
   
    // 환산 상태량 계산 (Z 인자를 찾기 위한 근거)
    double Pr = P_kPa / PCR;
    double Tr = T_K / TCR;

    // Z 값 (도표에서 읽은 값) 정의: Pr=0.2217, Tr=0.9168 일 때 Z=0.85 가정
    double Z_factor = 0.85;

    // 수식: v = Z * (R * T / P) = Z * v_ideal
    v_chart = Z_factor * v_ideal;

    printf("(b) 압축성 도표를 이용한 결과\n");
    printf("   [수식: v_chart = Z * R * T / P]\n");
    printf("   - Z 계산 근거: Pr=%.4f, Tr=%.4f (Z=%.2f 사용)\n", Pr, Tr, Z_factor);
    printf("   - 계산된 비체적 (v_chart): %.5f m^3/kg\n", v_chart);
    
    // (c) 표 데이터 출력
    printf("(c) 표 데이터\n");
    printf("   - 비체적 (v_table): %.5f m^3/kg\n", v_table);
    printf("   [설명: R-134a 과열 증기표에서 직접 읽은 값이며, 기준값으로 사용됨]\n");

    // 4단계: 결과 비교 및 분석
    printf("최종 결과 요약\n");
    printf("   (a) 이상 기체: %.5f m^3/kg\n", v_ideal);
    printf("   (b) 압축성 인자: %.5f m^3/kg\n", v_chart);
    printf("   (c) 표 데이터: %.5f m^3/kg\n", v_table);

    return 0;
}