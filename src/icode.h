#pragma once
/* C++17 */
#ifndef XU_ICODE_H_
#define XU_ICODE_H_

#include <string>
#include <cstdint>
#include <string_view>
#include <vector>
#include <map>
#include <set>
#include <array>
#include <list>
#include <utility>
#include <tuple>
#include <type_traits>
#include <memory>

namespace xu {

enum class endian {
#if defined(_MSC_VER) && !defined(__clang__)
    little = 0,
    big    = 1,
    native = little
#else
    little = __ORDER_LITTLE_ENDIAN__,
    big = __ORDER_BIG_ENDIAN__,
    native = __BYTE_ORDER__
#endif
};

template <typename, template <typename...> class>
struct is_specialization: std::false_type {};

template <template <typename...> class Template, typename... Args>
struct is_specialization<Template<Args...>, Template>: std::true_type {};

void  append(std::string &  pkg, const std::string &  value);
void  append(std::string &  pkg, std::string_view const  value);
void  append(std::string &  pkg, const char *  data, size_t const  size);
std::vector<std::string_view>  viewIcode(const std::string &  value) noexcept;
std::vector<std::string_view>  viewIcode(std::string_view const  value) noexcept;
std::vector<std::string_view>  viewIcode(const char *  data, size_t const  size) noexcept;
std::pair<size_t, size_t>  extHead(const char *  data, size_t const  size) noexcept;
std::string  makeHead(size_t const  size);

bool  fromString(bool &  res, const std::string &  value);
bool  fromString(bool &  res, std::string_view const  value);
bool  fromString(bool &  res, const char *  data, size_t const  size);
std::string  toString(bool const  value);
bool  fromString(char &  res, const std::string &  value);
bool  fromString(char &  res, std::string_view const  value);
bool  fromString(char &  res, const char *  data, size_t const  size);
std::string  toString(char const  value);
bool  fromString(signed char &  res, const std::string &  value);
bool  fromString(signed char &  res, std::string_view const  value);
bool  fromString(signed char &  res, const char *  data, size_t const  size);
std::string  toString(signed char const  value);
bool  fromString(unsigned char &  res, const std::string &  value);
bool  fromString(unsigned char &  res, std::string_view const  value);
bool  fromString(unsigned char &  res, const char *  data, size_t const  size);
std::string  toString(unsigned char const  value);
bool  fromString(long long &  res, const std::string &  value);
bool  fromString(long long &  res, std::string_view const  value);
bool  fromString(long long &  res, const char *  data, size_t const  size);
std::string  toString(long long const  value);
bool  fromString(unsigned long long &  res, const std::string &  value);
bool  fromString(unsigned long long &  res, std::string_view const  value);
bool  fromString(unsigned long long &  res, const char *  data, size_t const  size);
std::string  toString(unsigned long long const  value);
bool  fromString(short &  res, const std::string &  value);
bool  fromString(short &  res, std::string_view const  value);
bool  fromString(short &  res, const char *  data, size_t const  size);
std::string  toString(short const  value);
bool  fromString(unsigned short &  res, const std::string &  value);
bool  fromString(unsigned short &  res, std::string_view const  value);
bool  fromString(unsigned short &  res, const char *  data, size_t const  size);
std::string  toString(unsigned short const  value);
bool  fromString(int &  res, const std::string &  value);
bool  fromString(int &  res, std::string_view const  value);
bool  fromString(int &  res, const char *  data, size_t const  size);
std::string  toString(int const  value);
bool  fromString(unsigned int &  res, const std::string &  value);
bool  fromString(unsigned int &  res, std::string_view const  value);
bool  fromString(unsigned int &  res, const char *  data, size_t const  size);
std::string  toString(unsigned int const  value);
bool  fromString(long &  res, const std::string &  value);
bool  fromString(long &  res, std::string_view const  value);
bool  fromString(long &  res, const char *  data, size_t const  size);
std::string  toString(long const  value);
bool  fromString(unsigned long &  res, const std::string &  value);
bool  fromString(unsigned long &  res, std::string_view const  value);
bool  fromString(unsigned long &  res, const char *  data, size_t const  size);
std::string  toString(unsigned long const  value);
bool  fromString(float &  res, const std::string &  value);
bool  fromString(float &  res, std::string_view const  value);
bool  fromString(float &  res, const char *  data, size_t const  size);
std::string  toString(float const  value);
bool  fromString(double &  res, const std::string &  value);
bool  fromString(double &  res, std::string_view const  value);
bool  fromString(double &  res, const char *  data, size_t const  size);
std::string  toString(double const  value);
bool  fromString(long double &  res, const std::string &  value);
bool  fromString(long double &  res, std::string_view const  value);
bool  fromString(long double &  res, const char *  data, size_t const  size);
std::string  toString(long double const  value);
bool  fromString(std::string &  res, const std::string &  value);
bool  fromString(std::string &  res, std::string_view const  value);
bool  fromString(std::string &  res, const char *  data, size_t const  size);
std::string  toString(const std::string &  value);
std::string  toString(const char *  data, size_t const  size);

static std::string  u16tos(uint16_t const  value);
static std::string  u32tos(uint32_t const  value);
static std::string  u64tos(uint64_t const  value);
static uint16_t  stou16(const char *  data) noexcept;
static uint32_t  stou32(const char *  data) noexcept;
static uint64_t  stou64(const char *  data) noexcept;
static void  viewSection(const char *  data, size_t  size, std::vector<std::string_view> &  res) noexcept;
static std::string  to_s(const unsigned long long &  value);
static std::string  to_s(const long long &  value);
static void  pint_to_s(std::string &  data, const unsigned long long &  value);
static unsigned long long  cpy_int(const char *  data, size_t  size) noexcept;
static std::string  d_to_s(const char *  data, size_t const  size);
static void  cpy_df(char *  dest, size_t const  dest_size, const char *  src, size_t const  src_size) noexcept;

template <typename T, typename U>
bool  fromString(std::pair<T, U> &  res, const std::string &  value);
template <typename T, typename U>
bool  fromString(std::pair<T, U> &  res, std::string_view const  value);
template <typename T, typename U>
bool  fromString(std::pair<T, U> &  res, const char *  data, size_t const  size);
template <typename T, typename U>
std::string  toString(const std::pair<T, U> &  value);
template <typename T, typename U>
bool  fromString(std::map<T, U> &  res, const std::string &  value);
template <typename T, typename U>
bool  fromString(std::map<T, U> &  res, std::string_view const  value);
template <typename T, typename U>
bool  fromString(std::map<T, U> &  res, const char *  data, size_t const  size);
template <typename T, typename U>
std::string  toString(const std::map<T, U> &  value);
template <typename T>
bool  fromString(std::vector<T> &  res, const std::string &  value);
template <typename T>
bool  fromString(std::vector<T> &  res, std::string_view const  value);
template <typename T>
bool  fromString(std::vector<T> &  res, const char *  data, size_t const  size);
template <typename T>
std::string  toString(const std::vector<T> &  value);
template <typename T>
bool  fromString(std::list<T> &  res, const std::string &  value);
template <typename T>
bool  fromString(std::list<T> &  res, std::string_view const  value);
template <typename T>
bool  fromString(std::list<T> &  res, const char *  data, size_t const  size);
template <typename T>
std::string  toString(const std::list<T> &  value);
template <typename T>
bool  fromString(std::set<T> &  res, const std::string &  value);
template <typename T>
bool  fromString(std::set<T> &  res, std::string_view const  value);
template <typename T>
bool  fromString(std::set<T> &  res, const char *  data, size_t const  size);
template <typename T>
std::string  toString(const std::set<T> &  value);
template <typename T>
bool  fromString(T &  res, const std::string &  value);
template <typename T>
bool  fromString(T &  res, std::string_view const  value);
template <typename T>
bool  fromString(T &  res, const char *  data, size_t const  size);
template <typename T>
std::string  toString(const T &  value);

template <size_t N>
constexpr void  append(std::string &  pkg, const char (&r)[N]);
template <typename Tuple, size_t... Is>
constexpr bool  from_for_each_tp(Tuple &  t, const std::vector<std::string_view> &  vi, std::index_sequence<Is...>);
template <typename Tuple, size_t... Is>
constexpr void  for_each_tp(std::string &  res, const Tuple &  t, std::index_sequence<Is...>);

template <typename T, typename U> inline
bool
fromString(std::pair<T, U> &  res,
           const std::string &  value)
{
    return xu::fromString(res, value.data(), value.size());
}

template <typename T, typename U> inline
bool
fromString(std::pair<T, U> &  res,
           std::string_view const  value)
{
    return xu::fromString(res, value.data(), value.size());
}

template <typename T, typename U> inline
bool
fromString(std::pair<T, U> &  res,
           const char *  data,
           size_t const  size)
{
    auto  vi { xu::viewIcode(data, size) };
    if (vi.size() == 2) {
        std::pair<T, U>  pa;
        if (    xu::fromString(pa.first, vi[0]) &&
                xu::fromString(pa.second, vi[1]) ) {
            res = std::move(pa);
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

template <typename T, typename U> inline
std::string
toString(const std::pair<T, U> &  value)
{
    std::string  res;
    xu::append(res, xu::toString(value.first));
    xu::append(res, xu::toString(value.second));
    return res;
}

template <typename T, typename U> inline
bool
fromString(std::map<T, U> &  res,
           const std::string &  value)
{
    return xu::fromString(res, value.data(), value.size());
}

template <typename T, typename U> inline
bool
fromString(std::map<T, U> &  res,
           std::string_view const  value)
{
    return xu::fromString(res, value.data(), value.size());
}

template <typename T, typename U> inline
bool
fromString(std::map<T, U> &  res,
           const char *  data,
           size_t const  size)
{
    std::map<T, U>  resTmp;
    auto  vi { xu::viewIcode(data, size) };
    size_t const  viSize = vi.size();
    for (size_t  i = 0; i < viSize; ++i) {
        auto  v2vi = xu::viewIcode(vi[i]);
        std::pair<T, U>  pa;
        if (v2vi.size() == 2) {
            if (    xu::fromString(pa.first, v2vi[0]) &&
                    xu::fromString(pa.second, v2vi[1]) ) {
                resTmp.insert(std::move(pa));
            } else {
                return false;
            }
        }
    }
    res = std::move(resTmp);
    return true;
}

template <typename T, typename U> inline
std::string
toString(const std::map<T, U> &  value)
{
    std::string  res;
    for (const auto &  item : value) {
        xu::append(res, xu::toString(item));
    }
    return res;
}

template <typename T> inline
bool
fromString(std::vector<T> &  res,
           const std::string &  value)
{
    return xu::fromString(res, value.data(), value.size());
}

template <typename T> inline
bool
fromString(std::vector<T> &  res,
           std::string_view const  value)
{
    return xu::fromString(res, value.data(), value.size());
}

template <typename T> inline
bool
fromString(std::vector<T> &  res,
           const char *  data,
           size_t const  size)
{
    std::vector<T>  resTmp;
    auto  vi { xu::viewIcode(data, size) };
    size_t const  viSize = vi.size();
    for (size_t  i = 0; i < viSize; ++i) {
        T  item;
        if (xu::fromString(item, vi[i])) {
            resTmp.push_back(std::move(item));
        } else {
            return false;
        }
    }
    res = std::move(resTmp);
    return true;
}

template <typename T> inline
std::string
toString(const std::vector<T> &  value)
{
    std::string  res;
    const size_t  size = value.size();
    for (size_t  i = 0; i < size; ++i) {
        xu::append(res, toString(value[i]));
    }
    return res;
}

template <typename T> inline
bool
fromString(std::list<T> &  res,
           const std::string &  value)
{
    return xu::fromString(res, value.data(), value.size());
}

template <typename T> inline
bool
fromString(std::list<T> &  res,
           std::string_view const  value)
{
    return xu::fromString(res, value.data(), value.size());
}

template <typename T> inline
bool
fromString(std::list<T> &  res,
           const char *  data,
           size_t const  size)
{
    std::list<T>  resTmp;
    auto  vi { xu::viewIcode(data, size) };
    size_t const  viSize = vi.size();
    for (size_t  i = 0; i < viSize; ++i) {
        T  item;
        if (xu::fromString(item, vi[i])) {
            resTmp.push_back(std::move(item));
        } else {
            return false;
        }
    }
    res = std::move(resTmp);
    return true;
}

template <typename T> inline
std::string
toString(const std::list<T> &  value)
{
    std::string  res;
    for (const auto &  item : value) {
        xu::append(res, xu::toString(item));
    }
    return res;
}

template <typename T> inline
bool
fromString(std::set<T> &  res,
           const std::string &  value)
{
    return xu::fromString(res, value.data(), value.size());
}

template <typename T> inline
bool
fromString(std::set<T> &  res,
           std::string_view const  value)
{
    return xu::fromString(res, value.data(), value.size());
}

template <typename T> inline
bool
fromString(std::set<T> &  res,
           const char *  data,
           size_t const  size)
{
    std::set<T>  resTmp;
    auto  vi { xu::viewIcode(data, size) };
    size_t const  viSize = vi.size();
    for (size_t  i = 0; i < viSize; ++i) {
        T  item;
        if (xu::fromString(item, vi[i])) {
            resTmp.insert(std::move(item));
        } else {
            return false;
        }
    }
    res = std::move(resTmp);
    return true;
}

template <typename T> inline
std::string
toString(const std::set<T> &  value)
{
    std::string  res;
    for (const auto &  item : value) {
        xu::append(res, xu::toString(item));
    }
    return res;
}

template <typename T> inline
bool
fromString(T &  res,
           const std::string &  value)
{
    return xu::fromString(res, value.data(), value.size());
}

template <typename T> inline
bool
fromString(T &  res,
           std::string_view const  value)
{
    return xu::fromString(res, value.data(), value.size());
}

template <typename T> inline
bool
fromString(T &  res,
           const char *  data,
           size_t const  size)
{
    if constexpr (std::is_enum<T>::value) {
        std::underlying_type_t<T>  resTmp;
        if (xu::fromString(resTmp, data, size)) {
            res = static_cast<T>(resTmp);
            return true;
        } else {
            return false;
        }
    } else if constexpr (xu::is_specialization<T, std::tuple>::value) {
        T  resTmp;
        auto  vi { xu::viewIcode(data, size) };
        size_t const  viSize = vi.size();
        constexpr size_t  tpSize = std::tuple_size<T>();
        if (viSize == tpSize) {
            bool const  flag = xu::from_for_each_tp(resTmp, vi,
                    std::make_index_sequence<std::tuple_size_v<T>>());
            if (flag) {
                res = std::move(resTmp);
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return res.fromString(data, size);
    }
}

template <typename T> inline
std::string
toString(const T &  value)
{
    std::string  res;

    if constexpr (std::is_enum<T>::value) {
        res = xu::toString(static_cast<typename std::underlying_type<T>::type>(value));
    } else if constexpr (xu::is_specialization<T, std::tuple>::value) {
        xu::for_each_tp(res, value, std::make_index_sequence<std::tuple_size_v<T>>());
    } else {
        res = value.toString();
    }

    return res;
}

template <size_t N> inline constexpr
void
append(std::string &  pkg,
       const char (&r)[N])
{
    static_assert(N != 0, "Icode append error: 0 length arrays.");
    if (*(r + N - 1) == '\0') {
        xu::append(pkg, r, N - 1);
    } else {
        xu::append(pkg, r, N);
    }
}

template <typename Tuple, size_t... Is> inline constexpr
bool
from_for_each_tp(Tuple &  t,
                 const std::vector<std::string_view> &  vi,
                 std::index_sequence<Is...>)
{
    return (xu::fromString(std::get<Is>(t), vi[Is]) && ...);
}

template <typename Tuple, size_t... Is> inline constexpr
void
for_each_tp(std::string &  res,
            const Tuple &  t,
            std::index_sequence<Is...>)
{
    (xu::append(res, xu::toString(std::get<Is>(t))), ...);
}

}

#endif
