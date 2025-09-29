#include <iostream>
#include <stdio.h>
#include <cmath>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;


// 清屏函数
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}
//自定义雨 
void rain(){
	const int WIDTH = 600;   // 场景宽度
	const int HEIGHT = 20;  // 场景高度
	const char RAIN = '|';  // 雨滴字符
	srand((unsigned)time(0));
	
	    // 二维画布
	    vector<string> screen(HEIGHT, string(WIDTH, ' '));
	
	    while (true) {
	        // 每次生成新雨滴
	        int x = rand() % WIDTH;
	        screen[0][x] = RAIN;
	
	        // 下移雨滴
	        for (int y = HEIGHT - 1; y > 0; --y) {
	            screen[y] = screen[y - 1];
	        }
	        screen[0] = string(WIDTH, ' '); // 顶行清空，等待新雨滴
	
	        // 清屏并打印
	        clearScreen();
	        for (int y = 0; y < HEIGHT; ++y) {
	            cout << screen[y] << '\n';
	        }
	
	        // 控制雨点速度
	        this_thread::sleep_for(chrono::milliseconds(100));
	    }
	
}
//自定义心 
void love(){
	const int size = 3;      // 固定大小
	const string ch = "*";   // 固定字符
    const string red = "\033[31m"; // ANSI 红色
    const string reset = "\033[0m"; // 重置颜色

    // 控制分辨率（步长）
    double density = 0.8 + 0.4 * (size - 1);
    double stepY = 0.070 * density;   
    double stepX = 0.045 * density;   

    double ymax = 1.20, ymin = -1.20;
    double xmin = -1.35, xmax = 1.35;

    for (double y = ymax; y >= ymin; y -= stepY) {
        for (double x = xmin; x <= xmax; x += stepX) {
            double a = x*x + y*y - 1.0;
            double f = a*a*a - x*x*y*y*y;
            if (f <= 0.0) {
                cout << red << ch << reset;
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
} 

int main() {
	cout<<"吉隆坡的天气它是翻云又覆雨"<<endl<<endl;
	Sleep(3000);
	cout<<"灰蒙蒙的乌云好几天没见到你"<<endl<<endl;
	Sleep(1800);
	love();
	Sleep(1800);
	cout<<endl;
	cout<<"电影票和收据还留在我口袋里"<<endl<<endl;
	Sleep(3000);
	cout<<"可我不习惯没有带着你的打火机"<<endl<<endl;
	Sleep(3000);
    rain();
    return 0;
}
