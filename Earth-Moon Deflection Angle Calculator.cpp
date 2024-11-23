#include <iostream>
#include <cmath>

// ���峣��
const double PI = 3.14159265358979323846;
const double EARTH_ORBIT_RADIUS = 1.0; // �������뾶����λ����
const double MOON_ORBIT_RADIUS = 0.27; // �������뾶����λ����
const double EARTH_ROTATION_PERIOD = 365.25; // ������ת���ڣ���λ��
const double MOON_ROTATION_PERIOD = 27.32; // ������ת���ڣ���λ��
const double ORBIT_PERIOD = 365.25; // ����ת���ڣ���λ��

// ��������
double degreesToRadians(double degrees);
double calculateEarthPosition(double time);
double calculateMoonPosition(double earthTime);

int main() {
    std::cout << "������ģ��" << std::endl;
    std::cout << "����ģ���������0-365����";
    int days;
    std::cin >> days;

    // ȷ������������ں���Χ��
    if (days < 0 || days > 365) {
        std::cout << "���������������һ��ķ�Χ��" << std::endl;
        return 1;
    }

    // ���㲢��ӡ�����ǵ�λ��
    double earthPosition = calculateEarthPosition(days);
    double moonPosition = calculateMoonPosition(days);
    std::cout << "�� " << days << " �죺" << std::endl;
    std::cout << "����λ�ã�" << earthPosition * 180 / PI << " ��" << std::endl;
    std::cout << "����λ�ã�" << moonPosition * 180 / PI << " ��" << std::endl;

    return 0;
}

// ������ת��Ϊ����
double degreesToRadians(double degrees) {
    return degrees * PI / 180.0;
}

// ��������ڹ���ϵ�λ��
double calculateEarthPosition(double time) {
    // ����ת�ļ�ģ�ͣ�ʹ�����Һ���ģ��
    return sin(2 * PI * time / ORBIT_PERIOD);
}

// ���������ڹ���ϵ�λ��
double calculateMoonPosition(double earthTime) {
    // ����ת�ļ�ģ�ͣ�ʹ�����Һ���ģ��
    return sin(2 * PI * earthTime / (ORBIT_PERIOD / 12.37)); // ����ת�����ǵ���ת���ڵ�1/12.37
}
