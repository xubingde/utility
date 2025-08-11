#include <algorithm>
#include <cstring>
#include "icode.h"

namespace xu {

constexpr static char cs_MAX2 = '\xFF';
constexpr static char cs_MAX4 = '\xFE';
constexpr static char cs_MAX8 = '\xFD';
constexpr static unsigned char cs_MAX_SIZE = '\xFC';

constexpr static unsigned char cs_SERZ_T_PINT = 255;
constexpr static unsigned char cs_SERZ_T_NINT = 254;

void
append(std::string &  pkg,
       const std::string &  value)
{
    append(pkg, value.data(), value.size());
}

void
append(std::string &  pkg,
       std::string_view const  value)
{
    append(pkg, value.data(), value.size());
}

void
append(std::string &  pkg,
       const char *  data,
       size_t const  size)
{
    if (data == nullptr || size == 0) {
        pkg.append(makeHead(0));
    } else {
        pkg.append(makeHead(size));
        pkg.append(data, size);
    }
}

std::vector<std::string_view>
viewIcode(const std::string &  value) noexcept
{
    return viewIcode(value.data(), value.size());
}

std::vector<std::string_view>
viewIcode(std::string_view const  value) noexcept
{
    return viewIcode(value.data(), value.size());
}

std::vector<std::string_view>
viewIcode(const char *  data,
          size_t const  size) noexcept
{
    std::vector<std::string_view> res;
    if (!(size == 0 || data == nullptr)) {
        viewSection(data, size, res);
    }
    return res;
}

std::pair<size_t, size_t>
extHead(const char *  data,
        size_t const  size) noexcept
{
    std::pair<size_t, size_t>  res { 0, 0 };
    if (data == nullptr || size == 0) {
        return res;
    }

    char const  head_char = *data;
    switch (head_char) {
        case cs_MAX2:
            if (size > 2) {
                std::get<0>(res) = 3;
                std::get<1>(res) = stou16(data + 1);
            }
            break;
        case cs_MAX4:
            if (size > 4) {
                std::get<0>(res) = 5;
                std::get<1>(res) = stou32(data + 1);
            }
            break;
        case cs_MAX8:
            if (size > 8) {
                std::get<0>(res) = 9;
                std::get<1>(res) = stou64(data + 1);
            }
            break;
        default:
            std::get<0>(res) = 1;
            std::get<1>(res) = static_cast<unsigned char>(head_char);
            break;
    }
    return res;
}

std::string
makeHead(size_t const  size)
{
    std::string  res;
    if (size <= cs_MAX_SIZE) {
        res.push_back(static_cast<unsigned char>(size));
    } else if (size <= UINT16_MAX) {
        res.push_back(cs_MAX2);
        res.append(u16tos(static_cast<uint16_t>(size)));
    } else if (size <= UINT32_MAX) {
        res.push_back(cs_MAX4);
        res.append(u32tos(static_cast<uint32_t>(size)));
    } else {
        res.push_back(cs_MAX8);
        res.append(u64tos(size));
    }
    return res;
}

bool
fromString(bool &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(bool &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(bool &  res,
           const char *  data,
           size_t const  size)
{
    if (size > 1) {
        return false;
    } else {
        if (data == nullptr || size == 0) {
            res = false;
        } else {
            res = static_cast<bool>(*data);
        }
        return true;
    }
}

std::string
toString(bool const  value)
{
    std::string  result;
    if (value) {
        result.push_back('\1');
    }
    return result;
}

bool
fromString(char &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(char &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(char &  res,
           const char *  data,
           size_t const  size)
{
    if (size > 1) {
        return false;
    } else {
        if (data == nullptr || size == 0) {
            res = '\0';
        } else {
            res = *data;
        }
        return true;
    }
}

std::string
toString(char const  value)
{
    std::string  res { value };
    if (value == '\0') {
        res.pop_back();
    }
    return res;
}

bool
fromString(signed char &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(signed char &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(signed char &  res,
           const char *  data,
           size_t const  size)
{
    char  ch;
    if (fromString(ch, data, size)) {
        res = static_cast<signed char>(ch);
        return true;
    } else {
        return false;
    }
}

std::string
toString(signed char const  value)
{
    std::string  res { static_cast<char>(value) };
    if (value == 0) {
        res.pop_back();
    }
    return res;
}

bool
fromString(unsigned char &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(unsigned char &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(unsigned char &  res,
           const char *  data,
           size_t const  size)
{
    char  ch;
    if (fromString(ch, data, size)) {
        res = static_cast<unsigned char>(ch);
        return true;
    } else {
        return false;
    }
}

std::string
toString(unsigned char const  value)
{
    std::string  res { static_cast<char>(value) };
    if (value == 0) {
        res.pop_back();
    }
    return res;
}

bool
fromString(long long &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(long long &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(long long &  res,
           const char *  data,
           size_t const  size)
{
    if (size > sizeof(long long) + 1) {
        return false;
    } else {
        if (size == 0 || data == nullptr) {
            res = 0;
        } else {
            unsigned char const  chPtr = *data;
            if (size == 1) {
                res = chPtr;
            } else {
                res = cpy_int(data + 1, size - 1);
                if (chPtr == cs_SERZ_T_NINT) {
                    res = -res;
                }
            }
        }
        return true;
    }
}

std::string
toString(long long const  value)
{
    return to_s(value);
}

bool
fromString(unsigned long long &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(unsigned long long &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(unsigned long long &  res,
           const char *  data,
           size_t const  size)
{
    if (size > sizeof(unsigned long long)) {
        return false;
    } else {
        if (size == 0 || data == nullptr) {
            res = 0;
        } else {
            res = cpy_int(data, size);
        }
        return true;
    }
}

std::string
toString(unsigned long long const  value)
{
    return to_s(value);
}

bool
fromString(short &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(short &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(short &  res,
           const char *  data,
           size_t const  size)
{
    long long  value;
    if (fromString(value, data, size)) {
        short const  tmp = static_cast<short>(value);
        if (value == tmp) {
            res = tmp;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

std::string
toString(short const  value)
{
    long long const  nint = value;
    return to_s(nint);
}

bool
fromString(unsigned short &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(unsigned short &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(unsigned short &  res,
           const char *  data,
           size_t const  size)
{
    unsigned long long  value;
    if (fromString(value, data, size)) {
        unsigned short const  tmp = static_cast<unsigned short>(value);
        if (value == tmp) {
            res = tmp;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

std::string
toString(unsigned short const  value)
{
    unsigned long long const  pint = value;
    return to_s(pint);
}

bool
fromString(int &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(int &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(int &  res,
           const char *  data,
           size_t const  size)
{
    long long  value;
    if (fromString(value, data, size)) {
        int const  tmp = static_cast<int>(value);
        if (value == tmp) {
            res = tmp;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

std::string
toString(int const  value)
{
    long long const  nint = value;
    return to_s(nint);
}

bool
fromString(unsigned int &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(unsigned int &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(unsigned int &  res,
           const char *  data,
           size_t const  size)
{
    unsigned long long  value;
    if (fromString(value, data, size)) {
        unsigned int const  tmp = static_cast<unsigned int>(value);
        if (value == tmp) {
            res = tmp;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

std::string
toString(unsigned int const  value)
{
    unsigned long long const  pint = value;
    return to_s(pint);
}

bool
fromString(long &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(long &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(long &  res,
           const char *  data,
           size_t const  size)
{
    long long  value;
    if (fromString(value, data, size)) {
        long const  tmp = static_cast<long>(value);
        if (value == tmp) {
            res = tmp;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

std::string
toString(long const  value)
{
    long long const  nint = value;
    return to_s(nint);
}

bool
fromString(unsigned long &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(unsigned long &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(unsigned long &  res,
           const char *  data,
           size_t const  size)
{
    unsigned long long  value;
    if (fromString(value, data, size)) {
        unsigned long const  tmp = static_cast<unsigned long>(value);
        if (value == tmp) {
            res = tmp;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

std::string
toString(unsigned long const  value)
{
    unsigned long long const  pint = value;
    return to_s(pint);
}

bool
fromString(float &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(float &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(float &  res,
           const char *  data,
           size_t const  size)
{
    if (size > sizeof(float)) {
        return false;
    } else {
        if (size == 0 || data == nullptr) {
            res = 0;
        } else {
            union {
                float  fl;
                char  ch[sizeof(float)];
            } brick;
            brick.fl = 0;

            size_t const  fld_size = sizeof(float);
            char *  begin = std::begin(brick.ch);
            cpy_df(begin, fld_size, data, size);
            res = brick.fl;
        }
        return true;
    }
}

std::string
toString(float const  value)
{
    std::string  res;
    if (value == 0) {
        return res;
    }
    union {
        float  fl;
        char  ch[sizeof(float)];
    } brick;
    brick.fl = value;

    const char *  begin = std::begin(brick.ch);
    size_t const  size = sizeof(float);
    res = d_to_s(begin, size);
    return res;
}

bool
fromString(double &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(double &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(double &  res,
           const char *  data,
           size_t const  size)
{
    if (size > sizeof(double)) {
        return false;
    } else {
        if (size == 0 || data == nullptr) {
            res = 0;
        } else {
            union {
                double  df;
                char  ch[sizeof(double)];
            } brick;
            brick.df = 0;

            size_t const  df_size = sizeof(double);
            char *  begin = std::begin(brick.ch);
            cpy_df(begin, df_size, data, size);
            res = brick.df;
        }
        return true;
    }
}

std::string
toString(double const  value)
{
    std::string  res;
    if (value == 0) {
        return res;
    }
    union {
        double  df;
        char  ch[sizeof(double)];
    } brick;
    brick.df = value;

    const char *  begin = std::begin(brick.ch);
    size_t const  size = sizeof(double);
    res = d_to_s(begin, size);
    return res;
}

bool
fromString(long double &  res,
           const std::string &  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(long double &  res,
           std::string_view const  value)
{
    return fromString(res, value.data(), value.size());
}

bool
fromString(long double &  res,
           const char *  data,
           size_t const  size)
{
    if (size > sizeof(long double)) {
        return false;
    } else {
        if (size == 0 || data == nullptr) {
            res = 0;
        } else {
            union {
                long double  ldf;
                char  ch[sizeof(long double)];
            } brick;
            brick.ldf = 0;

            size_t const  ldf_size = sizeof(long double);
            char *  begin = std::begin(brick.ch);
            cpy_df(begin, ldf_size, data, size);
            res = brick.ldf;
        }
        return true;
    }
}

std::string
toString(long double const  value)
{
    std::string  res;
    if (value == 0) {
        return res;
    }
    union {
        long double  ld;
        char  ch[sizeof(long double)];
    } brick;
    brick.ld = value;

    const char *  begin = std::begin(brick.ch);
    size_t const  size = sizeof(long double);
    res = d_to_s(begin, size);
    return res;
}

bool
fromString(std::string &  res,
           const std::string &  value)
{
    res = value;
    return true;
}

bool
fromString(std::string &  res,
           std::string_view const  value)
{
    res = value;
    return true;
}

bool
fromString(std::string &  res,
           const char *  data,
           size_t const  size)
{
    if (data == nullptr && size > 0) {
        return false;
    } else {
        res = std::string(data, size);
        return true;
    }
}

std::string
toString(const std::string &  value)
{
    return value;
}

std::string
toString(const char *  data,
         size_t const  size)
{
    return std::string(data, size);
}

std::string
u16tos(uint16_t const  value)
{
    std::string  res;
    union {
        char  ch[2];
        uint16_t  u16;
    };

    u16 = value;
    if (endian::native == endian::little) {
        for (int  i = 0; i < 2; ++i) {
            res.push_back(ch[1 - i]);
        }
    } else {
        res.append(ch, 2);
    }
    return res;
}

std::string
u32tos(uint32_t const  value)
{
    std::string  res;
    union {
        char  ch[4];
        uint32_t  u32;
    };

    u32 = value;
    if (endian::native == endian::little) {
        for (int  i = 0; i < 4; ++i) {
            res.push_back(ch[3 - i]);
        }
    } else {
        res.append(ch, 4);
    }
    return res;
}

std::string
u64tos(uint64_t const  value)
{
    std::string  res;
    union {
        char  ch[8];
        uint64_t  u64;
    };

    u64 = value;
    if (endian::native == endian::little) {
        for (int  i = 0; i < 8; ++i) {
            res.push_back(ch[7 - i]);
        }
    } else {
        res.append(ch, 8);
    }
    return res;
}

uint16_t
stou16(const char *  data) noexcept
{
    union {
        char  ch[2];
        uint16_t  u16;
    };
    if (endian::native == endian::little) {
        for (int  i = 0; i < 2; ++i) {
            ch[i] = data[1 - i];
        }
    } else {
        memcpy(ch, data, 2);
    }
    return u16;
}

uint32_t
stou32(const char *  data) noexcept
{
    union {
        char  ch[4];
        uint32_t  u32;
    };
    if (endian::native == endian::little) {
        for (int  i = 0; i < 4; ++i) {
            ch[i] = data[3 - i];
        }
    } else {
        memcpy(ch, data, 4);
    }
    return u32;
}

uint64_t
stou64(const char *  data) noexcept
{
    union {
        char  ch[8];
        uint64_t  u64;
    };
    if (endian::native == endian::little) {
        for (int  i = 0; i < 8; ++i) {
            ch[i] = data[7 - i];
        }
    } else {
        memcpy(ch, data, 8);
    }
    return u64;
}

void
viewSection(const char *  data,
            size_t  size,
            std::vector<std::string_view> &  res) noexcept
{
    if (size == 0) {
        return;
    }

    char const  head_char = *data;
    size_t  tail, headlen;
    switch (head_char) {
        case cs_MAX2:
            headlen = 3;
            if (size < headlen) {
                res.clear();
                return;
            }
            tail = stou16(data + 1) + 3ull;
            break;
        case cs_MAX4:
            headlen = 5;
            if (size < headlen) {
                res.clear();
                return;
            }
            tail = stou32(data + 1) + 5ull;
            break;
        case cs_MAX8:
            headlen = 9;
            if (size < headlen) {
                res.clear();
                return;
            }
            tail = stou64(data + 1) + 9ull;
            break;
        default:
            headlen = 1;
            tail = static_cast<unsigned char>(head_char) + 1ull;
            break;
    }
    if (size < tail) {
        res.clear();
        return;
    } else {
        res.emplace_back(data + headlen, tail - headlen);
    }

    data += tail;
    size -= tail;
    viewSection(data, size, res);
}

std::string
to_s(const unsigned long long &  value)
{
    std::string  result;
    if (value == 0) {
        return result;
    }
    pint_to_s(result, value);
    return result;
}

std::string
to_s(const long long &  value)
{
    std::string  result;
    if (value == 0) {
        return result;
    }

    unsigned long long  ull_value;
    if (value < 0) {
        result.push_back(cs_SERZ_T_NINT);
        ull_value = -value;
        pint_to_s(result, ull_value);
    } else {
        ull_value = value;
        unsigned char  ch;
        if (ull_value <= 255 ) {
            ch = static_cast<unsigned char>(ull_value);
            result.push_back(ch);
        } else {
            result.push_back(cs_SERZ_T_PINT);
            pint_to_s(result, ull_value);
        }
    }
    return result;
}

void
pint_to_s(std::string &  data,
          const unsigned long long &  value)
{
    union {
        unsigned long long  ull;
        char  ch[sizeof(unsigned long long)];
    } brick;
    brick.ull = value;

    auto  begin = std::begin(brick.ch);
    auto  end = std::end(brick.ch);
    if (endian::native == endian::little) {
        --begin;
        --end;
        for (; begin != end; --end) {
            if (*end != 0)
                break;
        }
        ++begin;
        ++end;
        for (; begin != end; ++begin) {
            data.push_back(*begin);
        }
    } else {
        for (; begin != end; ++begin) {
            if (*begin != 0)
                break;
        }
        --begin;
        --end;
        for (; begin != end; --end) {
            data.push_back(*end);
        }
    }
}

unsigned long long
cpy_int(const char *  data,
        size_t  size) noexcept
{
    union {
        unsigned long long  ull;
        char  ch[sizeof(unsigned long long)];
    } brick;
    brick.ull = 0;
    size_t const  total = sizeof(unsigned long long);
    if (size > total)
        size = total;

    const char *  data_end = data + size;
    if (endian::native == endian::little) {
        auto  begin = std::begin(brick.ch);
        for (; data != data_end; ++data) {
            *begin++ = *data;
        }
    } else {
        auto  end = std::end(brick.ch);
        --end;
        for (; data != data_end; ++data) {
            *end-- = *data;
        }
    }
    return brick.ull;
}

std::string
d_to_s(const char *  data,
       size_t const  size)
{
    std::string  result;
    const char *  end = data + size;
    if (endian::native == endian::little) {
        for (; data != end; ++data) {
            if (*data != 0)
                break;
        }
        --data;
        --end;
        for (; data != end; --end) {
            result.push_back(*end);
        }
    } else {
        --data;
        --end;
        for (; data != end; --end) {
            if (*end != 0)
                break;
        }
        ++data;
        ++end;
        for (; data != end; ++data) {
            result.push_back(*data);
        }
    }
    return result;
}

void
cpy_df(char *  dest,
       size_t const  dest_size,
       const char *  src,
       size_t const  src_size) noexcept
{
    size_t  safe_size = src_size;
    if (src_size > dest_size)  safe_size = dest_size;

    char *  dest_end = dest + dest_size;
    const char *  src_end = src + safe_size;

    if (endian::native == endian::little) {
        --dest_end;
        for (; src != src_end; ++src) {
            *dest_end-- = *src;
        }
    } else {
        for (; src != src_end; ++src) {
            *dest++ = *src;
        }
    }
}

}
