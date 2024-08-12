//
// Created by Changjoon Lee on 8/1/24.
//

/*
 * TODO : 할당이란 행위는 리소스를 많이 먹는 행위이다. 이를 해결하려면 담으려는 데이터보다 조금 더 많은 메모리를 미리 할당하는 게 좋다. 그 정도가 뭘까?
 * TODO : UTF-8을 통해 할당하는 등의 문제. 여러 개의 바이트가 하나의 문제열에 대응되는 경우를 어떻게 할까?
 * TODO : 여러가지 검색 알고리즘(KMP, Boyer - Moore) 들을 이용하는 find 함수를 만들어보세요. 어떤 알고리즘의 경우 미리 계산된 테이블이 필요할 텐데, 이러한 정보들 역시 class 변수로 처리하셔도 됩니다. (난이도 : 上)
 */

#include "CustomString.h"
#include "bits/stdc++.h"
#include <iostream>
using namespace std;

CustomString::CustomString()
{
    cout << "CustomString()" << endl;
}

CustomString::~CustomString()
{
    cout << "~CustomString()" << endl;

    if (m_psData)
        delete[] m_psData;
}

CustomString::CustomString(char _sParam)
{
    cout << "CustomString(char)" << endl;

//    m_psData = new char[2];
//
//    char* s_input = new char[2];
//    s_input[0] = _sParam;
//
////    CopyString(m_psData, s_input);
//    m_psData = s_input;

    SetString(_sParam);
}

CustomString::CustomString(CustomString&& _rhs)
{
    cout << "" << endl;
}

CustomString::CustomString(const char* _sParam)
{
    cout << "CustomString(const char*)" << endl;

//    m_psData = new char[GetStrLen(_sParam) + 1];
//    CopyString(m_psData, _sParam);

    SetString(_sParam);
}

CustomString::CustomString(const CustomString& _rhs)
{
    cout << "CustomString(const CustomString&)" << endl;

    SetString(_rhs.m_psData);
}

void CustomString::CopyString(char* _target_str, const char* _str_to_cpy)
{
    if (!_target_str) return;

    for (int i = 0; i < GetStrLen(_str_to_cpy); i++)
        _target_str[i] = _str_to_cpy[i]; // Pointer may be null when called from function 'CustomString'
}

const char* CustomString::GetString() const
{
    if (m_psData)
        return m_psData;

    return nullptr;
}

void CustomString::SetString(const char* _sParam)
{
    Reserve(GetStrLen(_sParam));
    CopyString(m_psData, _sParam);
}

void CustomString::SetString(char _sParam)
{
    Reserve(2);
    m_psData[0] = _sParam;
}

void CustomString::operator+=(const char* _sParam)
{
    int i_str_num_m = GetStrLen(m_psData);
    int i_str_num_param = GetStrLen(_sParam);

    char* s_tmp = new char[i_str_num_m];
    CopyString(s_tmp, m_psData);
    Reserve(i_str_num_m + i_str_num_param);

    CopyString(m_psData, s_tmp);
    CopyString(&m_psData[i_str_num_m], _sParam);
}

void CustomString::operator+=(char _sParam)
{
    char* s_tmp = new char[GetStrLen(m_psData)];
    CopyString(s_tmp, m_psData);
    Reserve(GetStrLen(m_psData) + 1);

    CopyString(m_psData, s_tmp);
    m_psData[GetStrLen(m_psData)] = _sParam;
}

bool CustomString::operator==(const CustomString& _rhs) const
{
    if (GetStrLen(m_psData) != GetStrLen(_rhs.m_psData)) return false;

    for (int i = 0; i < GetStrLen(m_psData); i++)
        if (m_psData[i] != _rhs.m_psData[i]) return false;

    return true;
}

// CustomString이랑 const char*랑 비교하는 건 필요 없음. 어차피 변환생성으로 지원하면 됨.
bool CustomString::operator==(const CustomString&& _rhs) const // 변환생성의 결과인 CustomString의 우측값을 참조.
{
    return *this == _rhs;
}

CustomString& CustomString::operator=(const char* _sParam)
{
    Reserve(GetStrLen(_sParam));
    CopyString(m_psData, _sParam);
    return *this;
}

CustomString& CustomString::operator=(const CustomString& _rhs)
{
    Reserve(GetStrLen(_rhs.m_psData));
    CopyString(m_psData, _rhs.m_psData);

    return *this;
}

bool CustomString::operator<(const CustomString& _rhs) const // this가 왼쪽일지 오른쪽일지 어떻게 알고 이렇게 짠 거지??? -> 오른쪽에 있는 객체가 인수로 들어온다...
{
    if (*this == _rhs) return false;
    const int i_str_len_of_m = GetStrLen(m_psData);
    const int i_str_len_of_param = GetStrLen(_rhs.m_psData);

    const int i_str_len_of_shortest = i_str_len_of_m < i_str_len_of_param ?
                                      i_str_len_of_m : i_str_len_of_param;

    for (int i = 0; i < i_str_len_of_shortest; i++)
    {
        if (m_psData[i] == _rhs.m_psData[i]) continue;
        if (m_psData[i] < _rhs.m_psData[i]) return true;
    }

    if (i_str_len_of_m < i_str_len_of_param) return true;

    return false;
}

bool CustomString::operator<(const CustomString&& _rhs) const
{
    return *this < _rhs;
}

bool CustomString::operator>(const CustomString& _rhs) const
{
    if (*this == _rhs) return false;
    return !(*this < _rhs);
}

bool CustomString::operator>(const CustomString&& _rhs) const
{
    return *this > _rhs;
}

bool CustomString::Contains(const char* _sParam) const
{
    const int i_str_len_of_m = GetStrLen(m_psData);
    const int i_str_len_of_param = GetStrLen(_sParam);

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

void CustomString::Reserve(int _i_str_len)
{
    if (m_iCap > _i_str_len) return;

    if (m_iCap * 2 > _i_str_len)
        m_iCap *= 2;
    else
        m_iCap = _i_str_len + 1;

    if (m_psData)
        delete[] m_psData;
    m_psData = new char[m_iCap];
}
