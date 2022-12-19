#include <stdio.h>
#include <math.h>

#define T1 160 // Время выхода на орбиту в сек. - этап 1
#define T2 300 // Конец полёта в сек. - этап 2
#define M 590.870 // Масса заправленной ракеты в тоннах
#define M0 64.37 // Масса пустой ракеты в тоннах
#define bak 40.5 // Масса одного бака
#define taga 100000 //тяга 
#define topl 64 //расход топлива
#define pogreshnost 35 // погрешность в тоннах

// Расчет расхода топлива в данный момент
double current_toplivo(int t) {
    if (t != T2) {
        return (M - M0)/t;
    } else {
        return (M - M0 + bak)/t;
    }

}

// Функция расчёта массы
double current_mass(int t) {
    return M - t*current_toplivo(t);
}

// Хар.скорость этап 1
double v1(){
    return (taga/topl)*log(M/(M - bak * 8 - pogreshnost));
}

// Хар.скорость этап 2
double v2(){
    return (taga/topl)*log((M - bak * 8 - pogreshnost)/(M - bak * 12 - pogreshnost));
}

int main()
{
    printf("Масса на момент выхода к орбите Земли: \n%.2f тонн\n", current_mass(T1));
    printf("Скорость на момент выхода к орбите Земли: \n%2.f м/c\n", v1());
    printf("_____________________________________\n");
    printf("                                         \n");
    printf("Масса на момент конца полёта: \n%.2f тонн\n", current_mass(T2));
    printf("Скорость на момент конца полёта: \n%2.f м/c\n", v2());
    
    return 0;
}



