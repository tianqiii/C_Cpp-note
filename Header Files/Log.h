#pragma once // header guards 防止被包含到单个翻译单元中 (在单个文件中包含多次)
             // 更现代的方法
// #ifndef _LOG_H
// #define _LOG_H

void Log(const char *message); // 存放函数签名
void InitLog();

// #endif