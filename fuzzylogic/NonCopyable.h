#pragma once

class NonCopyable
{
public:
    NonCopyable() = default;
   ~NonCopyable() = default;
private:
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};