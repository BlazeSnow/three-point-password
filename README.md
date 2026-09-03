# 三点密码

1. 三点密码是一种字符替换式密码
2. 将密钥文件发送给另一方，并保存在程序的同一目录下，即可保证双方加解密算法相同
3. 支持的范围：英文大小写字母，英文（半角）符号，空格
4. 支持的英文（半角）符号如下：

```txt
 , ! @ # $ % ^ & *

 ( ) < > . ? / ; :

" [ ] { } ' + - ~
```

## 如何下载？

前往 [GitHub Release](https://github.com/BlazeSnow/three-point-password/releases/latest) 下载对应系统的可执行文件。

文件命名格式为 `three-point-password-<版本>-<系统>-<架构>`，各平台对应关系如下：

| 文件名后缀           | 适用平台               |
| -------------------- | ---------------------- |
| `-windows-x64.exe`   | Windows x64            |
| `-windows-arm64.exe` | Windows ARM64          |
| `-linux-x64`         | Linux x64              |
| `-linux-arm64`       | Linux ARM64            |
| `-macos-x64`         | macOS（Intel）         |
| `-macos-arm64`       | macOS（Apple Silicon） |

## Linux / macOS 额外处理

```sh
sudo chmod +x <可执行文件>
```

## 更新日志

见 [CHANGELOG.md](./CHANGELOG.md)

## 许可证

[MIT](./LICENSE)
