# 写在最前

1. **三点密码**是一种字符替换式密码
2. 程序开始后，如果没有密钥文件，将自动生成密钥文件
3. 将密钥文件**发送给另一方**，并保存在**编译器目录**，即可保证双方加解密算法相同
4. 若不需要二次加密，请前往仓库中复制[**全0文件**](/全0文件.txt)，替换txt内容
5. **直接输入**需编码或解码内容即可
6. 支持的范围：英文大小写字母，英文（**半角**）符号，空格
7. 支持的英文（半角）符号如下：

```
 , ! @ # $ % ^ & *

 ( ) < > . ? / ; :

" [ ] { } ' + - ~
```

# 更新日志

- **2024年4月17日12点59分**
    - 将仓库从```Gitee```转移到```GitHub```
- **2024年3月30日15点25分**
    - 优化主程序代码进```class```
    - 优化部分```public```函数进入```private```
    - 优化注释
    - 优化不需要修改值的数组为```const```常量
- **2024年3月28日17点14分**
    - 优化代码为```class```
    - 删除二次加密相关内容，默认开启二次加密
    - 若不需要二次加密，请前往仓库中复制```全0文件```，替换```txt```内容
- **2024年3月27日22点31分**
    - 优化注释内容
    - 优化二次加密关闭时的稳定性
- **2024年3月27日22点11分**
    - 使用```queue```重写数组
    - 优化程序判断能力
    - 默认开启二次加密
    - 程序解耦合，相同功能分装到函数中
    - 将```“密钥文件.txt”```修改为```“三点密码密钥文件.txt”```
- **2024年3月13日19点32分**
    - 创建结构体```p```用于存放输入数组和二次加密密钥数组
    - 增加```vector```的读取完毕后截断
- **2024年3月13日18点01分**
    - 用```vector```代替```calloc```，删去```NULL```检查和```delete```收尾
- **2024年1月23日13点22分**
    - 合并了二次加密与主程序，因此删除了仓库中的```“二次加密.cpp”```
    - 通过创建密钥文件来进行二次加密
    - 重新整理了“三点密码”表格：将数字的```“1到9”```改为```“0到9”```
    - 注意：此版本与先前版本的“三点密码”不兼容
    - 增加支持了键盘上绝大多数的英文字符
    - 优化```calloc```收尾的```free```为```delete```
- **2024年1月23日07点37分**
    - 将此文件从```PrimaryProjects```中分离，建立新的仓库
- **2024年1月14日19点33分**
    - 移除```system("pause")```
    - 优化文字叙述
- **2024年1月8日11点37分**
    - 添加```system("pause")```
    - 优化文字叙述
- **2024年1月4日18点26分**
    - 优化```malloc```收尾，删去```=NULL```
    - 将```cin.get```强转类型为```char```字符型
    - 优化子函数的```for```为```Range-based for```
- **2023年11月19日22点46分**
    - 优化内容输入为```cin.get```
- **2023年9月19日22点54分**
    - 将代码从```C```优化为```C++```
- **2023年9月7日17点48分**
    - 优化文字叙述
- **2023年8月18日22点00分**
    - 优化了对```malloc```的```NULL```空指针检查
- **2023年7月31日21点00分**
    - 删除二次加密功能
    - 后续会单独出一个程序来二次加密
- **2023年7月31日18点00分**
    - 简化了代码
- **2023年7月31日17点00分**
    - 增加了符号的二次加密，可以和数字的二次加密共同使用
- **2023年7月31日08点30分**
    - 增加了二次加密功能
    - 优化了注释
- **2023年7月31日08点00分**
    - 增加了更多的错误拦截
- **2023年7月30日17点00分**
    - 优化```字符数组```为```malloc```
    - 增加了注释行：使用说明和版本号
    - 增加支持了更多的英文符号
- **2023年7月30日13点50分**
    - 优化了输入前的文字说明
    - 增加上限为```1000```个字符，便于编解码更多的内容
- **2023年7月26日09点45分**
    - 优化了上个版本的字符识别问题，可以拦截更多的输入错误
- **2023年7月26日07点30分**
    - 使用C语言的```结构体```改写程序
    - 不再需要输入编解码的判断字符
- **2023年7月23日12点30分**
    - 优化了文字叙述
    - 修改了编码和解码的区分字符
    - 更改编码为```UTF-8```
- **2023年7月17日15点00分**
    - 优化了文字叙述
- **2023年7月10日16点00分**
    - 根据程序提示分离编码与解码，不再需要加上结尾字符```“#”```或```“$”```了
    - 程序输出的字符加上了白色底、红色颜色的样式
    - 优化了```scanf```为```getchar```
    - 使读取字符串的代码更为简洁
- **2023年7月9日09点00分**
    - 支持了英文大写字母的传达
    - 修复了解码无法生成字母```“u”```的问题
    - 增加了对英文逗号```“,”```的支持
- **2023年7月9日08点30分**
    - 用C语言的指针```char *```改写程序
    - 将主程序中的算法移至子函数中
- **2023年7月8日22点00分**
    - 更新了程序二合一(编码和解码合并在一个程序里，不需要两个程序了)
    - 更新了大写字母自动转小写
    - 此版本后编写密码的结尾不再是```“.”```，而是```“#”```
- **2023年7月8日18点30分**
    - 更新了界面排版和文字叙述
- **2023年7月8日16点30分**
    - 以前的想法“三点密码”的实现
