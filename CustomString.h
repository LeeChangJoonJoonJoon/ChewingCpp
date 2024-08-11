//
// Created by Changjoon Lee on 8/1/24.
//

#ifndef CHEWINGCPP_CUSTOMSTRING_H
#define CHEWINGCPP_CUSTOMSTRING_H

class CustomString
{
public:
    CustomString();
    ~CustomString();

    CustomString(const char* _sParam);
    CustomString(char _sParam);
    CustomString(const CustomString& _rhs);

    [[nodiscard]] static inline int GetStrLen(const char* _sParam)
    {
        int i_index = 0;
        while (1)
        {
            if (CustomString::s_back_slash_zero == _sParam[i_index])
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

    inline void Reserve(int _i_str_len);

    static inline void CopyString(char* _target_str, const char* _str_to_cpy);
    [[nodiscard]] const char* GetString();

    /*
     * SetString(const char)로 선언하면 _sParam is const-qualified in function declaration
     * 이란 경고가 나온다.
     * SetString(const char*)에선 그런 경고가 없었는데, 이유가 뭘까?
     *
     */
    void SetString(const char* _sParam);
    void SetString(char _sParam);

    void operator+=(const char* _sParam);
    void operator+=(char _sParam);
    bool operator==(const CustomString& _rhs);
    bool operator==(const CustomString&& _rhs);
    CustomString& operator=(const char* _sParam);
    bool operator<(const CustomString& _rhs);
    bool operator<(const CustomString&& _rhs);
    bool operator>(const CustomString& _rhs);
    bool operator>(const CustomString&& _rhs);

    bool Contains(const char* _sParam) const;

private:
    char* m_psData{nullptr};
    int m_iCap{0};

public:
    static const char s_back_slash_zero = '\0';
};

#endif //CHEWINGCPP_CUSTOMSTRING_H
