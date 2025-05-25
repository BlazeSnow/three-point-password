#include <filesystem>
#include <fstream>
#include <iostream>
#include <queue>
#include <random>
#include <vector>

// 支持的输入长度or生成密钥文件的长度的一半
#define passcode_length 1000

using namespace std;

const filesystem::path CurrentPath = filesystem::current_path();
const string CurrentPathString = CurrentPath.string();

enum { CreatePasswordFile, WithPasswordFile, NoPasswordFile };

// 字符串相互对应密码结构体
struct Code {
    // 字母
    char letter;
    // 数字
    int number;
    // 字符
    int mark;
};

const vector<Code> code = {
    {'a', 0, 0}, {'b', 1, 0}, {'c', 2, 0}, {'d', 3, 0}, {'e', 4, 0},
    {'f', 5, 0}, {'g', 6, 0}, {'h', 7, 0}, {'i', 8, 0}, {'j', 9, 0},
    {'k', 0, 1}, {'l', 1, 1}, {'m', 2, 1}, {'n', 3, 1}, {'o', 4, 1},
    {'p', 5, 1}, {'q', 6, 1}, {'r', 7, 1}, {'s', 8, 1}, {'t', 9, 1},
    {'u', 0, 2}, {'v', 1, 2}, {'w', 2, 2}, {'x', 3, 2}, {'y', 4, 2},
    {'z', 5, 2}, {' ', 6, 2}, {'A', 7, 2}, {'B', 8, 2}, {'C', 9, 2},
    {'D', 0, 3}, {'E', 1, 3}, {'F', 2, 3}, {'G', 3, 3}, {'H', 4, 3},
    {'I', 5, 3}, {'J', 6, 3}, {'K', 7, 3}, {'L', 8, 3}, {'M', 9, 3},
    {'N', 0, 4}, {'O', 1, 4}, {'P', 2, 4}, {'Q', 3, 4}, {'R', 4, 4},
    {'S', 5, 4}, {'T', 6, 4}, {'U', 7, 4}, {'V', 8, 4}, {'W', 9, 4},
    {'X', 0, 5}, {'Y', 1, 5}, {'Z', 2, 5}, {',', 3, 5}, {'!', 4, 5},
    {'@', 5, 5}, {'#', 6, 5}, {'$', 7, 5}, {'%', 8, 5}, {'^', 9, 5},
    {'&', 0, 6}, {'*', 1, 6}, {'(', 2, 6}, {')', 3, 6}, {'<', 4, 6},
    {'>', 5, 6}, {'.', 6, 6}, {'?', 7, 6}, {'/', 8, 6}, {';', 9, 6},
    {':', 0, 7}, {'\"', 1, 7}, {'[', 2, 7}, {']', 3, 7}, {'{', 4, 7},
    {'}', 5, 7}, {'\'', 6, 7}, {'+', 7, 7}, {'-', 8, 7}, {'~', 9, 7}
};

// 存储输入的字符串
queue<char> inputMessage;
// 随机移动密钥
queue<int> passcode;
// 用于存放密钥的符号
const char mark[] = {',', ';', '.', '<', ':', '>', '-', '+'};

void createPasscodeFile() {
    // 创建密钥文件
    fstream file1("three-point-password.txt", ios::out);
    if (file1.is_open()) {
        // 写入文件，每个数字以空格隔开
        for (int i = 0; i < passcode_length; i++) {
            // 获取随机数字种子
            random_device rd;
            // 获取随机数
            unsigned int temp;
            if (i % 2 == 0) {
                temp = rd() % 10;
            } else {
                temp = rd() % (int) sizeof(mark);
            }
            // 写入文件
            file1 << temp << " ";
        }
        file1.close();
        // 写入完毕，输出文件位置
        printf("随机密钥文件\"three-point-password.txt\"已创建\n");
        printf("目录为：%s\n", CurrentPathString.c_str());
        printf("请提前发送给解密方\n");
    } else {
        // 写入失败
        fprintf(stderr, "错误：\"three-point-password.txt\"文件生成失败，请重试\n");
        abort();
    }
}

void input(int ChooseMode) {
    if (ChooseMode == WithPasswordFile) {
        fstream file("three-point-password.txt", ios::in);
        for (int i = 0; i < passcode_length; i++) {
            int temp;
            file >> temp;
            passcode.push(temp);
        }
        file.close();
    } else if (ChooseMode == NoPasswordFile) {
        for (int i = 0; i < passcode_length; i++) {
            passcode.push(0);
        }
    }
    printf("密钥文件\"three-point-password.txt\"读取成功\n");
    printf("目录为：%s\n", CurrentPathString.c_str());
}

int IfPosInLetter(char temp) {
    for (int i = 0; i < (int) code.size(); i++) {
        if (code[i].letter == temp) {
            return i;
        }
    }
    return -1;
}

int IfPosInMark(char temp) {
    for (int i = 0; i < (int) sizeof(mark); i++) {
        if (mark[i] == temp) {
            return i;
        }
    }
    return -1;
}

// 加密内容
void encode() {
    while (!inputMessage.empty()) {
        // 录入主数组
        char temp_letter = inputMessage.front();
        // 主数组删除第一个
        inputMessage.pop();
        for (auto &i: code) {
            if (i.letter == temp_letter) {
                // 打印数字
                printf("%d", (i.number + passcode.front()) % 10);
                // 密码数组删除第一个
                passcode.pop();
                // 打印字符
                printf("%c", mark[(i.mark + passcode.front()) % (int) sizeof(mark)]);
                // 密码数组删除第一个
                passcode.pop();
                // 结束查询
                break;
            }
        }
    }
}

// 解码内容
void decode() {
    while (!inputMessage.empty()) {
        // 主数组录入数字
        int temp_number =
                (10 + (int) (inputMessage.front() - '0') - passcode.front()) % 10;
        passcode.pop();
        inputMessage.pop();
        // 主数组录入字符
        int tempPosInMark = IfPosInMark(inputMessage.front());
        int temp_mark = ((int) sizeof(mark) + tempPosInMark - passcode.front()) %
                        (int) sizeof(mark);
        passcode.pop();
        inputMessage.pop();
        // 输出原字母
        for (auto &i: code) {
            if (temp_number == i.number && temp_mark == i.mark) {
                printf("%c", i.letter);
            }
        }
    }
}

int main() {
    system("chcp 65001");
    system("cls");
    printf("Copyright (C) 2024-2025 BlazeSnow. 保留所有权利。\n");
    printf("当前程序版本号：v1.0.3\n");
    printf("https://github.com/BlazeSnow/three-point-password\n\n");

    printf("（0-生成特殊密钥；1-使用特殊密钥转换；2-无需特殊密钥转换）\n");
    printf("输入使用此程序的方法：");
    int ChooseMode = -1;
    while (true) {
        ChooseMode = (int) getchar() - '0';
        if (ChooseMode == 0 || ChooseMode == 1 || ChooseMode == 2) {
            cin.ignore();
            break;
        } else {
            fprintf(stderr, "错误：输入内容不合法。\n");
        }
    }

    if (ChooseMode == WithPasswordFile || ChooseMode == NoPasswordFile) {
        fstream file("three-point-password.txt", ios::in);
        if (file.is_open()) {
            file.close();
            input(ChooseMode);
            // 统计数字及字母数量，分辨编解码
            printf("\n请输入需要编解码的内容：\n");
            // 字母数量
            int NumOfLetter = 0;
            // 数字数量
            int NumOfNumber = 0;
            while (true) {
                // 从输入读取
                char temp = (char) cin.get();
                if (temp == '\n') {
                    break;
                } else if (IfPosInLetter(temp) != -1) {
                    // 发现字母
                    NumOfLetter++;
                    inputMessage.push(temp);
                } else if ((('0' <= temp) && (temp <= '9'))) {
                    // 发现数字
                    NumOfNumber++;
                    inputMessage.push(temp);
                } else if (IfPosInMark(temp) != -1) {
                    // 发现字符
                    inputMessage.push(temp);
                }
            }
            // 判断编码解码并运行
            if (NumOfLetter > NumOfNumber && NumOfNumber == 0) {
                // 进行编码
                printf("\n编码的结果为：\n");
                encode();
                printf("\n\n");
            } else if (NumOfLetter <= NumOfNumber) {
                // 进行解码
                printf("\n解码的结果为：\n");
                decode();
                printf("\n\n");
            } else {
                // 其他情况，终止程序
                fprintf(stderr, "错误：密钥文件\"three-point-password.txt\"读取失败\n");
            }
        } else {
            fprintf(stderr, "错误：文件\n");
        }
    } else if (ChooseMode == CreatePasswordFile) {
        createPasscodeFile();
    }
    system("pause");
    return 0;
}
