// #include "Log.h"
#include <iostream>

// const表示函数不会修改传入的字符串内容，避免不必要的字符串拷贝，兼容字符串字面量和C风格字符串，提供更好的API接口安全性
// ‘*’是指针符号 {}之前的void Log()部分是函数签名
// void Log(const char *message);

// void initLog()
// {
//     Log("Initializing Log");
// };

// 实现向控制台发送文字的功能，控制日志信息的级别 记录信息的字符串

static int s_Variable = 5; // static声明的变量只有一个

class Log
{
public: // 公有变量放在一个部分
    enum Level
    {
        LevelError = 0,
        LevelWarning = 1,
        LevelInfo = 2
    };
    // const int LogLevelError = 0;
    // const int LogLevelWarning = 1;
    // const int LogLevelInfo = 2;

private: // 私有变量放在一个部分
    Level m_LogLevel = LevelInfo;

public: // 公有函数放在一个部分
    void SetLevel(Level level)
    {
        m_LogLevel = level;
    }

    void Error(const char *message)
    {
        if (m_LogLevel >= LevelError)
            std::cout << "[Error]:" << message << std::endl;
    }
    void Warn(const char *message)
    {
        if (m_LogLevel >= LevelWarning)
            std::cout << "[Warning]:" << message << std::endl;
    }
    void Info(const char *message)
    {
        if (m_LogLevel >= LevelInfo)
            std::cout << "[Info]:" << message << std::endl;
    }
};

int main()
{
    Log log;
    log.SetLevel(log.LevelInfo);
    log.Warn("Hello!");
    log.Info("Hello!");
    log.Error("Hello!");
}