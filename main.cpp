#include "iostream"
#include "random"
#include "fstream"
#include "filesystem"
#include "vector"
#include "queue"

//支持的输入长度or生成密钥文件的长度的一半
#define passcode_length 1000

using namespace std;

class course {
public:

    void createPasscodeFile() const {
        //创建密钥文件
        fstream file1("三点密码随机密钥.txt", ios::out);
        if (file1.is_open()) {
            //写入文件，每个数字以空格隔开
            for (int i = 0; i < passcode_length; i++) {
                //获取随机数字种子
                random_device rd;
                //获取随机数
                unsigned int temp;
                if (i % 2 == 0) {
                    temp = rd() % 10;
                } else {
                    temp = rd() % (int) mark.size();
                }
                //写入文件
                file1 << temp << " ";
            }
            file1.close();
            //写入完毕，输出文件位置
            filesystem::path path = filesystem::current_path();
            cout << "随机密钥已保存至：" << path << endl;
            cout << "请提前发送给解密方" << endl;
        } else {
            //写入失败
            cout << "ERROR:文件生成失败，请重试" << endl;
            abort();
        }
    }

    void input() {
        fstream file("三点密码随机密钥.txt", ios::in);
        for (int i = 0; i < passcode_length; i++) {
            int temp;
            file >> temp;
            passcode.push(temp);
        }
        filesystem::path path = filesystem::current_path();
        cout << "密钥文件读取成功" << endl;
        cout << "目录为：" << path << endl;
    }

    void main() {
        input();
        //统计数字及字母数量，分辨编解码
        cout << "请输入需要编解码的内容：" << endl;
        //字母数量
        int NumOfLetter = 0;
        //数字数量
        int NumOfNumber = 0;
        while (true) {
            //从输入读取
            char temp = (char) cin.get();
            if (temp == '\n') {
                break;
            } else if (IfPosInLetter(temp) != -1) {
                //发现字母
                NumOfLetter++;
                array.push(temp);
            } else if ((('0' <= temp) && (temp <= '9'))) {
                //发现数字
                NumOfNumber++;
                array.push(temp);
            } else if (IfPosInMark(temp) != -1) {
                //发现字符
                array.push(temp);
            }
        }
        //判断编码解码并运行
        if (NumOfLetter > NumOfNumber && NumOfNumber == 0) {
            //进行编码
            cout << "编码的结果为:" << endl;
            encode();
        } else if (NumOfLetter <= NumOfNumber) {
            //进行解码
            cout << "解码的结果为:" << endl;
            decode();
        } else {
            //其他情况，终止程序
            cout << "ERROR:输入内容不符合规范" << endl;
            abort();
        }
    }

private:
    //存储输入的字符串
    queue<char> array;
    //随机移动密钥
    queue<int> passcode;
    //用于存放密钥的符号
    const vector<char> mark = {',', ';', '.', '<', ':', '>', '-', '+'};
    //字符串相互对应密码结构体
    struct Code {
        //字母
        char letter;
        //数字
        int number;
        //字符
        int mark;
    };
    const vector<Code> code = {{'a',  0, 0},
                               {'b',  1, 0},
                               {'c',  2, 0},
                               {'d',  3, 0},
                               {'e',  4, 0},
                               {'f',  5, 0},
                               {'g',  6, 0},
                               {'h',  7, 0},
                               {'i',  8, 0},
                               {'j',  9, 0},
                               {'k',  0, 1},
                               {'l',  1, 1},
                               {'m',  2, 1},
                               {'n',  3, 1},
                               {'o',  4, 1},
                               {'p',  5, 1},
                               {'q',  6, 1},
                               {'r',  7, 1},
                               {'s',  8, 1},
                               {'t',  9, 1},
                               {'u',  0, 2},
                               {'v',  1, 2},
                               {'w',  2, 2},
                               {'x',  3, 2},
                               {'y',  4, 2},
                               {'z',  5, 2},
                               {' ',  6, 2},
                               {'A',  7, 2},
                               {'B',  8, 2},
                               {'C',  9, 2},
                               {'D',  0, 3},
                               {'E',  1, 3},
                               {'F',  2, 3},
                               {'G',  3, 3},
                               {'H',  4, 3},
                               {'I',  5, 3},
                               {'J',  6, 3},
                               {'K',  7, 3},
                               {'L',  8, 3},
                               {'M',  9, 3},
                               {'N',  0, 4},
                               {'O',  1, 4},
                               {'P',  2, 4},
                               {'Q',  3, 4},
                               {'R',  4, 4},
                               {'S',  5, 4},
                               {'T',  6, 4},
                               {'U',  7, 4},
                               {'V',  8, 4},
                               {'W',  9, 4},
                               {'X',  0, 5},
                               {'Y',  1, 5},
                               {'Z',  2, 5},
                               {',',  3, 5},
                               {'!',  4, 5},
                               {'@',  5, 5},
                               {'#',  6, 5},
                               {'$',  7, 5},
                               {'%',  8, 5},
                               {'^',  9, 5},
                               {'&',  0, 6},
                               {'*',  1, 6},
                               {'(',  2, 6},
                               {')',  3, 6},
                               {'<',  4, 6},
                               {'>',  5, 6},
                               {'.',  6, 6},
                               {'?',  7, 6},
                               {'/',  8, 6},
                               {';',  9, 6},
                               {':',  0, 7},
                               {'\"', 1, 7},
                               {'[',  2, 7},
                               {']',  3, 7},
                               {'{',  4, 7},
                               {'}',  5, 7},
                               {'\'', 6, 7},
                               {'+',  7, 7},
                               {'-',  8, 7},
                               {'~',  9, 7}};

    //加密内容
    void encode() {
        while (!array.empty()) {
            //录入主数组
            char temp_letter = array.front();
            //主数组删除第一个
            array.pop();
            for (auto &i: code) {
                if (i.letter == temp_letter) {
                    //打印数字
                    cout << (i.number + passcode.front()) % 10;
                    //密码数组删除第一个
                    passcode.pop();
                    //打印字符
                    cout << mark[(i.mark + passcode.front()) % (int) mark.size()];
                    //密码数组删除第一个
                    passcode.pop();
                    //结束查询
                    break;
                }
            }
        }
    }

    //解码内容
    void decode() {
        while (!array.empty()) {
            //主数组录入数字
            int temp_number = (10 + (int) (array.front() - '0') - passcode.front()) % 10;
            passcode.pop();
            array.pop();
            //主数组录入字符
            int tempPosInMark = IfPosInMark(array.front());
            int temp_mark = ((int) mark.size() + tempPosInMark - passcode.front()) % (int) mark.size();
            passcode.pop();
            array.pop();
            //输出原字母
            for (auto &i: code) {
                if (temp_number == i.number && temp_mark == i.mark) {
                    cout << i.letter;
                }
            }
        }
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
        for (int i = 0; i < (int) mark.size(); i++) {
            if (mark[i] == temp) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    course a;
    fstream file("三点密码随机密钥.txt", ios::in);
    if (file.is_open()) {
        //如果读到了密钥文件
        file.close();
        a.main();
    } else {
        //没读到密钥文件
        file.close();
        a.createPasscodeFile();
    }
    return 0;
}