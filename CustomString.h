//
// Created by Changjoon Lee on 8/1/24.
//

#ifndef CHEWINGCPP_CUSTOMSTRING_H
#define CHEWINGCPP_CUSTOMSTRING_H

#include "bits/stdc++.h"
#include <iostream>
using namespace std;

class CustomString
{
public:
    CustomString();
    ~CustomString();

    CustomString(const char* _sParam);
    CustomString(char _sParam);

    [[nodiscard]] inline int GetStrLenth(const char* _sParam)
    {
        int i_index = 0;
        while (1)
        {
            if (CustomString::str_back_slash_zero == _sParam[i_index])
                break;
            /*
             * ++i는 lval, i_index++은 rval.
             * 전자는 객체를 반환하는 연산자. -> 메모리를 더 쓰게 됨.
             * 후자는 값을 반환하는 연산자.
             * 다음 링크 참고.
             * https://velog.io/@jinh2352/모던-C-4-R-Value-참조와-Move-Semantic
             */
            i_index++;
        }

        return i_index;
    }

    void CopyString(char* _target_str, const char* _str_to_cpy);
    [[nodiscard]] const char* GetString();

    /*
     * SetString(const char)로 선언하면 _sParam is const-qualified in function declaration
     * 이란 경고가 나온다.
     * SetString(const char*)에선 그런 경고가 없었는데, 이유가 뭘까?
     *
     */
    void SetString(const char* _sParam);
//    void SetString(const char _sParam);
    void SetString(char _sParam);

private:
    char* m_psData{nullptr};

public:
    static const char str_back_slash_zero = '\0';
};

#endif //CHEWINGCPP_CUSTOMSTRING_H
