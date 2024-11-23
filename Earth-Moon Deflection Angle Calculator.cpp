#include <iostream>
#include <cmath>

// 定义常量
const double PI = 3.14159265358979323846;
const double EARTH_ORBIT_RADIUS = 1.0; // 地球轨道半径，单位任意
const double MOON_ORBIT_RADIUS = 0.27; // 月球轨道半径，单位任意
const double EARTH_ROTATION_PERIOD = 365.25; // 地球自转周期，单位天
const double MOON_ROTATION_PERIOD = 27.32; // 月球自转周期，单位天
const double ORBIT_PERIOD = 365.25; // 地球公转周期，单位天

// 函数声明
double degreesToRadians(double degrees);
double calculateEarthPosition(double time);
double calculateMoonPosition(double earthTime);

int main() {
    std::cout << "三球仪模拟" << std::endl;
    std::cout << "输入模拟的天数（0-365）：";
    int days;
    std::cin >> days;

    // 确保输入的天数在合理范围内
    if (days < 0 || days > 365) {
        std::cout << "输入的天数超出了一年的范围。" << std::endl;
        return 1;
    }

    // 计算并打印三球仪的位置
    double earthPosition = calculateEarthPosition(days);
    double moonPosition = calculateMoonPosition(days);
    std::cout << "第 " << days << " 天：" << std::endl;
    std::cout << "地球位置：" << earthPosition * 180 / PI << " 度" << std::endl;
    std::cout << "月球位置：" << moonPosition * 180 / PI << " 度" << std::endl;

    return 0;
}

// 将度数转换为弧度
double degreesToRadians(double degrees) {
    return degrees * PI / 180.0;
}

// 计算地球在轨道上的位置
double calculateEarthPosition(double time) {
    // 地球公转的简化模型，使用正弦函数模拟
    return sin(2 * PI * time / ORBIT_PERIOD);
}

// 计算月球在轨道上的位置
double calculateMoonPosition(double earthTime) {
    // 月球公转的简化模型，使用正弦函数模拟
    return sin(2 * PI * earthTime / (ORBIT_PERIOD / 12.37)); // 月球公转周期是地球公转周期的1/12.37
}
