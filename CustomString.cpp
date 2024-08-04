//
// Created by Changjoon Lee on 8/1/24.
//

/*
 * TODO : strlen(), strcpy() 안쓰고 문자열을 관리하는 클래스 만들어 보기.
 * TODO : 변환 생성자, 이동 생성자, 형변환 지원하기.
 */

#include "CustomString.h"

CustomString::CustomString()
{
    cout << "CustomString()" << endl;

    m_psData = new char;
}

CustomString::~CustomString()
{
    cout << "~CustomString()" << endl;

    delete[] m_psData;
}

CustomString::CustomString(char _sParam)
{
    cout << "CustomString(char)" << endl;

    m_psData = new char;
    char* s_input = new char;
    s_input[0] = _sParam;

    CopyString(m_psData, s_input);
}

CustomString::CustomString(const char* _sParam)
{
    cout << "CustomString(const char*)" << endl;

    m_psData = new char;
    CopyString(m_psData, _sParam);
}

void CustomString::CopyString(char* _target_str, const char* _str_to_cpy)
{
    if (!_target_str) return;

    int i_str_len = GetStrLenth(_str_to_cpy);
    for (int i = 0; i < i_str_len; i++)
        _target_str[i] = _str_to_cpy[i];
}

const char* CustomString::GetString()
{
    if (m_psData)
        return m_psData;

    return nullptr;
}

void CustomString::SetString(const char* _sParam)
{
    CopyString(m_psData, _sParam);
}

void CustomString::SetString(char _sParam)
{
    char* s_input = new char;
    s_input[0] = _sParam;

    CopyString(m_psData, s_input);
}

void CustomString::operator+=(const char* _sParam)
{
    char* s_tmp = new char;

    const int i_str_len_of_m = GetStrLenth(m_psData);
    for (int i = 0; i < i_str_len_of_m; i++)
        s_tmp[i] = m_psData[i];

    const int i_str_len_of_param = GetStrLenth(_sParam);
    for (int i = 0; i < i_str_len_of_param; i++)
        s_tmp[i_str_len_of_m + i] = _sParam[i];

    m_psData = s_tmp;
}

bool CustomString::operator==(const char* _sParam)
{
    const int i_str_len_of_m = GetStrLenth(m_psData);
    const int i_str_len_of_param = GetStrLenth(_sParam);

    if (i_str_len_of_m != i_str_len_of_param) return false;
    for (int i = 0; i < i_str_len_of_m; i++)
        if (m_psData[i] != _sParam[i]) return false;

    return true;
}

bool CustomString::Contains(const char* _sParam)
{
    const int i_str_len_of_m = GetStrLenth(m_psData);
    const int i_str_len_of_param = GetStrLenth(_sParam);

    if (i_str_len_of_m < i_str_len_of_param) return false;

    for (int i = 0; i < i_str_len_of_m; i++)
    {
        if (_sParam[0] != m_psData[i]) continue;
        if (i + i_str_len_of_param > i_str_len_of_m) return false;

        for (int j = 0; j < i_str_len_of_param; j++)
            if (_sParam[j] != m_psData[i + j]) return false;

        return true;
    }

    return false;
}
