# LogManager
C++日志管理

需求：
定时检查日志目录内日志数量，删除7天以前的日志数据

程序功能描述：
1. 通过配置文件配置设置监测日志目录Path
2. 每天8点检测一次目录Path下的日志文件夹的数量，当数量超过7时，删除7天以前的日志文件夹(日志文件夹内有文件和文件夹)
3. 程序需要有一个自己的日志文件，每删除一个文件都要将文件名和删除时间记录到该日志中

日志目录样例：
- 175(0624)
- 176(0625)
- 177(0626)
- 178(0627)
- 179(0628)


|信息|   |
|---|---|
|环境|windows|
|IDE|VS2019|
|语言|C/C++|
