****************************************************************************
# 摘要

纯 C 语言应用级扩展库，每个模块都与硬件无关。是在工作、学习过程中积累或研发的应用模
块集合,每个模块有一个独立的项目文件，编码遵循标准 ANSI C，命名规范，易于扩展和学习。
常用模块：
- 状态机：FsmTiny
- 按键：WtButton
- 灯控：WtLamp
- 十六进制转换：Hex
# 开发环境：
- Microsoft Visual Studio Community 2022 (64 位)
- Microsoft Visual C++ 2022（纯 C 模式）

# 获取

```SHELL
git clone https://github.com/feallee/WtLibrary.git 
```
# 注意事项
****************************************************************************
- 部分开发环境需要预先初始化动态内存池作为使用动态内存的前置条件(如 Keil C51)。
- 在其它环境编译、调试只需指定模块相应的 .c 和 .h 文件即可。
- 模块与硬件无关，需编写硬件驱动与模块关联（如：按键、灯控等）。

# 问题和建议

如果有什么问题或者建议，欢迎选用下面的方式进行讨论：
- [issues](https://github.com/feallee/WtLibrary/issues)
- [feallee@hotmail.com](mailto://feallee@hotmail.com) 
- [weas.top](https://www.weas.top)

# 维护
 
- [feallee](https://github.com/feallee)

# 感谢



# 友情链接

- [深圳市华智联科技有限公司](https://www.szhzlkj.com/)
- [weas.top](https://www.weas.top)
