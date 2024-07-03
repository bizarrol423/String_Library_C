#include "s_string.h"
// поиск длинны строки
s_size_t s_strlen(const char *str) {  //  длинна строки
    s_size_t size = 0;
    while (str[size] != '\0') size++;
    return size;
}
// cравнивает первые n байтов str1 и str2.
int s_memcmp(const void *str1, const void *str2, s_size_t n) {
    if ((int)n == 0) return 0;
    while (--n && *(char *)str1 == *(char *)str2) {
        str1 = (char *)str1 + 1;
        str2 = (char *)str2 + 1;
    }
    return (*(char *)str1) - (*(char *)str2);
}
//  равнивает строку, на которую указывает str1, со строкой, на которую
//  указывает
// str2
int s_strcmp(const char *str1, const char *str2) {
    s_size_t size = 0;
    int result = 0;
    while (str1[size] != '\0' || str2[size] != '\0') {
        if (str1[size] != str2[size]) {
            result = str1[size] - str2[size];
            break;
        }
        size++;
    }
    return result;
}
// сравнивает первые n символов
int s_strncmp(const char *str1, const char *str2, s_size_t n) {
    const char *end = str1 + n;
    int result = 0;
    while (result == 0 && str1 != end && (*str1 || *str2)) {
        result = *(str1++) - *(str2++);
    }
    // for (; result == 0 && str1 != end && (*str1 || *str2);
    //      result = *(str1++) - *(str2++))
    //     ;
    return result;
}  // верхний регистр
void *s_to_upper(const char *str1) {
    s_size_t size = 0;
    char *str = malloc(sizeof(s_strlen(str1)));
    while (str1[size] != '\0') {
        if (str1[size] >= 'a' && str1[size] <= 'z')
            str[size] = str1[size] - 32;
        else
            str[size] = str1[size];
        size++;
    }
    str[size] = '\0';
    return (void *)str;
}  // нижний регистр
void *s_to_lower(const char *str1) {
    s_size_t size = 0;
    char *str = malloc(sizeof(s_strlen(str1) + 1));
    while (str1[size] != '\0') {
        if (str1[size] >= 'A' && str1[size] <= 'Z')
            str[size] = str1[size] + 32;
        else
            str[size] = str1[size];
        size++;
    }
    str[size] = '\0';
    return (void *)str;
}  //  вставляет строку в строку в указанном индексе
void *s_insert(const char *src, const char *str, s_size_t start_index) {
    char *res = malloc(s_strlen(src) + s_strlen(str) + 1);
    if (start_index <= s_strlen(src) && start_index >= 0) {
        char *src_copy, *str_copy;
        src_copy = malloc(s_strlen(src));
        s_strcpy(src_copy, src);
        str_copy = malloc(s_strlen(str));
        s_strcpy(str_copy, str);
        for (s_size_t i = 0, j = 0; i < s_strlen(src) + s_strlen(str) + 1;
             i++, j++) {
            if (i == start_index) {
                s_strcat(res, str);
                i += s_strlen(str);
                res[i] = src_copy[j];
            } else {
                res[i] = src_copy[j];
            }
        }
        res[s_strlen(src) + s_strlen(str) + 1] = '\0';
    } else {
        res = '\0';
    }
    return (void *)res;
}
// возвращает новую строку,
// в которой удаляются все начальные и конечные вхождения набора заданных
// символов(trim_chars)
// из данной строки(src).
// void *s_trim(const char *str, const char *char_trim) {  //  (\n\0\t )
// char *retval = "";
// int start = 1;
// int end = 1;
// s_size_t end_counter = 0;
// char trimmers[128];
// if (char_trim == s_NULL || char_trim == "\0") {
// trimmers[0] = ' ';
// trimmers[1] = '\n';
// trimmers[2] = '\t';
// trimmers[3] = '\0';
// } else {
// int i = 0;
// while (char_trim[i] != '\0') {
// trimmers[i] = char_trim[i];
// i++;
// }
// }
// s_size_t trim_lenght = s_strlen(trimmers);
// s_size_t start_counter = 0;
// if (str == s_NULL) {
// start = 0;
// end = 0;
// end_counter = -1;
// } else {
// end_counter = s_strlen(str) - 1;
// }
// while (start == 1 || end == 1) {
// int finish = 0;
// start = 0;
// end = 0;
// for (int i = 0; i < trim_lenght; i++) {
// if (str[start_counter] == trimmers[i] && start == 0) {
// start_counter++;
// start = 1;
// }
// if (str[end_counter] == trimmers[i] && end == 0) {
// end_counter--;
// end = 1;
// }
// }
// }
// if (start_counter >= end_counter || str == s_NULL) {
// retval = s_NULL;
// } else {
// for (int i = start_counter, j = 1; i <= end_counter + 1; i++, j++) {
// retval = (char *)realloc(retval, sizeof(char) * j);
// retval[j - 1] = str[i];
// }
// }
// return (void *)retval;
// }
/*
Функция s_strcspn определяет наибольшую длину начального участка строки
str1, не содержащего ни один из символов строки str2.
*/
s_size_t s_strcspn(const char *str1, const char *str2) {
    s_size_t numb = 0, flag = 0;
    for (; str1[numb] != '\0'; numb++) {
        for (int i = 0; str2[i] != '\0'; i++) {
            if (str1[numb] == str2[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }
    return numb;
}
/*
Функция s_memchr ищет вхождение в массив (область памяти) символа c, сравнивая
каждый байт массива (области памяти) определенный как unsigned char с кодом
искомого символа. Если искомый символ найден, то возвращается адрес найденного
символа и сравнение завершается. Если, после проверки n байтов, искомый символ
не найден, то сравнение прекращается и функция возвращает s_NULL.
*/
void *s_memchr(const void *str, int c, s_size_t n) {
    const char *symb = s_NULL, *ptr = str;
    for (s_size_t i = 0; i < n; i++, ptr++) {
        if (*ptr == c) {
            symb = ptr;
            break;
        }
    }
    return (void *)symb;
}
/*
Функция s_strchr ищет первое вхождения символа c (ASCII), в строке str
*/
char *s_strchr(const char *str, int c) {
    const char *symb = "";
    for (symb = str; *symb != c; symb++) {
        if (*symb == '\0') {
            symb = s_NULL;
            break;
        }
    }
    return (char *)symb;
}
/*
Функция s_strpbrk ищет первое вхождение в строке str1,
одного из символов, входящих в строку str2.
*/
char *s_strpbrk(const char *str1, const char *str2) {
    const char *symb = "";
    for (symb = str1; *symb != '\0'; symb++) {
        const char *i = "";
        i = str2;
        while (*i != *symb && *i != '\0') {
            i++;
        }
        // for (i = str2; *i != *symb && *i != '\0'; i++) {
        // ;
        // }
        if (*i == *symb) break;
    }
    if (*symb == '\0') symb = s_NULL;
    return (char *)symb;
}
/*
Функция s_strchr ищет последнее вхождения символа,
в строке str.
*/
char *s_strrchr(const char *str, int c) {
    char *rtnval = 0;
    do {
        if (*str == c) {
            rtnval = (char *)str;
        }
    } while (*str++);
    return (char *)rtnval;
}
/*
Функция s_strstr ищет первое вхождение строки (за исключением признак конца
строки) needle, в строку haystack. Если строка needle имеет нулевую длину, то
функция вернет указатель на начало строки haystack.
*/
char *s_strstr(const char *haystack, const char *needle) {
    char *temp = s_NULL;
    if (*needle == '\0') {
        temp = (char *)haystack;
    } else {
        temp = s_NULL;
        do {
            const char *p = "";
            const char *q = "";
            for (p = haystack, q = needle; *q != '\0' && *p == *q; p++, q++) {
            }
            if (*q == '\0') {
                temp = (char *)haystack;
            }
        } while (*(haystack++) != '\0');
    }
    return (char *)temp;
}
char *s_strtok(
    char *str,
    const char *delimiters) {  //  Заменить все на наши фунеции и убрать коммы
    char *token = "";
    static char *olds = "";
    if (str == s_NULL) str = olds;

    /* Scan leading delimiters.  */
    str += s_strspn(str, delimiters);
    if (*str == '\0') {
        olds = str;
        token = s_NULL;
    } else {
        /* Find the end of the token.  */
        token = str;
        str = s_strpbrk(token, delimiters);
        if (str == s_NULL) { /* This token finishes the string.  */
            olds = s_memchr(token, '\0', 1024);
        } else {
            /* Terminate the token and make OLDS point past it.  */
            *str = '\0';
            olds = str + 1;
        }
    }
    return (char *)token;
}

char *s_strcat(
    char *dest,
    const char *src) {  //  Заменить все на наши фунеции и убрать коммы
    s_strcpy(dest + s_strlen(dest), src);
    return dest;
}

char *s_strncat(
    char *dest, const char *src,
    s_size_t n) {  //  Заменить все на наши фунеции и убрать коммы
    char *str = dest;
    /* Find the end of str1.  */
    dest += s_strlen(dest);
    s_size_t str_size = s_strlen(src);
    if (str_size > n) str_size = n;
    dest[str_size] = '\0';
    s_memcpy(dest, src, str_size);
    return str;
}

char *s_strerror(int errnum) {
    char *errlist[] = {ERRSTR};
    static char retval[80];
    if (errnum >= ERRMIN && errnum < ERRMAX) {
        s_strcpy(retval, errlist[errnum]);
    } else {
        char num[10] = {0};
        if (errnum < 0) {
            num[0] = '-';
            errnum *= -1;
        }
        s_strcpy(retval, "Unknown error: ");
        int i = 0;
        for (i = 8; errnum != 0; errnum /= 10, i--) num[i] = errnum % 10 + '0';
        if (num[0] == '-') retval[15] = '-';
        s_strcat(retval, num + i + 1);
    }
    return (char *)retval;
}
/*
Возвращает целочисленное значение, задающее длину подстроки в str1,
которая состоит исключительно из символов в str2.
Если str1 начинается с символа, не из str2, функция возвращает 0.
str1 - Строка для поиска, завершающаяся символом NULL.
str2 - Набор символов, завершающийся символом NULL.
*/
s_size_t s_strspn(const char *str1, const char *str2) {
    const char *p = "";
    const char *a = "";
    int count = 0;
    for (p = str1; *p != '\0'; ++p) {
        for (a = str2; *a != '\0'; ++a) {
            if (*p == *a) {
                count++;
                break;
            }
        }
        if (*a == '\0') {
            break;
        }
    }
    return count;
}
/*
s_memcpy копирует count байт из src в dest;
При перекрытии исходного и конечного буферов
поведение s_memcpy не определено.
Используйте s_memmove для обработки перекрывающихся областей.
dest - Новый буфер.
src - Буфер, из которого происходит копирование.
n - Число копируемых символов.
*/
void *s_memcpy(void *dest, const void *src, s_size_t n) {
    char *csrc = (char *)src;
    char *cdest = (char *)dest;
    for (int i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }
    return (void *)cdest;
}

/*
Копирует count байтов из src в dest.
Если отдельные области конечного объекта перекрывают области
исходного объекта,
то функция гарантируют, что байты исходного объекта в
перекрывающейся области будут скопированы,
прежде чем будут перезаписаны.
Убедитесь в том, что буфер назначения равен или превосходит
по размеру исходный буфер.
dest - Конечный объект.
src - Исходный объект.
n - Число копируемых байтов.
*/
void *s_memmove(void *dest, const void *src, s_size_t n) {
    char *csrc = (char *)src;
    char *cdest = (char *)dest;
    char *temp = s_NULL;
    temp = (char *)malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++) {
        temp[i] = csrc[i];
    }
    for (int i = 0; i < n; i++) {
        cdest[i] = temp[i];
    }
    free(temp);
    temp = s_NULL;
    return (void *)cdest;
}

/*
Задает для первых n символов str значение символа c.
str - Указатель на место назначения.
c - Задаваемый символ.
n - Число символов.
*/
void *s_memset(void *str, int c, s_size_t n) {
    if (str != s_NULL) {
        char *temp = (char *)str;
        for (int i = 0; i < n; i++) {
            *temp++ = c;
        }
    }
    return str;
}
/*
Функция копирует src, включая завершающий символ null,
в расположение, указанное параметром dest.
При перекрытии исходного и конечного буферов поведение
s_strcpy не определено.
dest - Конечная строка.
src - Исходная строка, завершающаяся символом NULL.
*/
char *s_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
/*
Функция s_strncpy копирует первые несколько символов,
количество которых определяет параметр n,
из строки src в строку dest и возвращает строку dest.
Если значение параметра n меньше или равно длине строки src,
символ null не добавляется к скопированной строке автоматически.
Если значение n больше, чем длина строки src,
строка назначения заполняется символами null, пока ее длина
не достигнет длины строки n.
При перекрытии исходного и конечного буферов поведение
s_strncpy не определено.
dest - Конечная строка.
src - Исходная строка.
n - Число копируемых символов.
*/
char *s_strncpy(char *dest, const char *src, s_size_t n) {
    s_size_t i = 0;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}
typedef void (*out_fct_type)(char character, void *buffer, s_size_t idx,
                             s_size_t maxlen);

static void out_buf(char character, void *buffer, s_size_t idx,
                    s_size_t maxlen) {
    if (idx < maxlen) {
        ((char *)buffer)[idx] = character;
    }
}

static void out_null(char character, void *buffer, s_size_t idx,
                     s_size_t maxlen) {
    (void)character;
    (void)buffer;
    (void)idx;
    (void)maxlen;
}

static s_size_t exp_to_asc(out_fct_type out, char *buffer, s_size_t idx,
                             s_size_t maxlen, double value, unsigned int prec,
                             unsigned int width, unsigned int flags);

static bool is_digit(char ch) { return (ch >= '0') && (ch <= '9'); }

static unsigned int asc_to_int(const char **str) {
    unsigned int i = 0U;
    while (is_digit(**str)) {
        i = i * 10U + (unsigned int)(*((*str)++) - '0');
    }
    return i;
}

unsigned int s_strnlen(const char *str, s_size_t maxsize) {
    const char *s;
    for (s = str; *s && maxsize--; ++s) {
    }
    return (unsigned int)(s - str);
}

static s_size_t reverse(out_fct_type out, char *buffer, s_size_t idx,
                          s_size_t maxlen, const char *buf, s_size_t len,
                          unsigned int width, unsigned int flags) {
    const s_size_t start_idx = idx;

    if (!(flags & F_MINUS) && !(flags & F_ZERO)) {
        for (s_size_t i = len; i < width; i++) {
            out(' ', buffer, idx++, maxlen);
        }
    }

    while (len) {
        out(buf[--len], buffer, idx++, maxlen);
    }

    if (flags & F_MINUS) {
        while (idx - start_idx < width) {
            out(' ', buffer, idx++, maxlen);
        }
    }
    return idx;
}

static s_size_t num_to_asc_fmt(out_fct_type out, char *buffer, s_size_t idx,
                                 s_size_t maxlen, char *buf, s_size_t len,
                                 bool negative, unsigned int base,
                                 unsigned int prec, unsigned int width,
                                 unsigned int flags) {
    if (!(flags & F_MINUS)) {
        if (width && (flags & F_ZERO) &&
            (negative || (flags & (F_PLUS | F_SPACE)))) {
            width--;
        }
        while ((len < prec) && (len < NTOA_BUFFER_SIZE)) {
            buf[len++] = '0';
        }
        while ((flags & F_ZERO) && (len < width) && (len < NTOA_BUFFER_SIZE)) {
            buf[len++] = '0';
        }
    }

    if (flags & F_HASH) {
        if (!(flags & F_PRECISION) && len &&
            ((len == prec) || (len == width))) {
            len--;
            if (len && (base == 16U)) {
                len--;
            }
        }
        if ((base == 16U) && !(flags & F_UP_CASE) && (len < NTOA_BUFFER_SIZE)) {
            buf[len++] = 'x';
        } else {
            if ((base == 16U) && (flags & F_UP_CASE) &&
                (len < NTOA_BUFFER_SIZE)) {
                buf[len++] = 'X';
            } else {
                if ((base == 2U) && (len < NTOA_BUFFER_SIZE)) {
                    buf[len++] = 'b';
                }
            }
        }
        if (len < NTOA_BUFFER_SIZE) {
            buf[len++] = '0';
        }
    }

    if (len < NTOA_BUFFER_SIZE) {
        if (negative) {
            buf[len++] = '-';
        } else {
            if (flags & F_PLUS) {
                buf[len++] = '+';
            } else {
                if (flags & F_SPACE) {
                    buf[len++] = ' ';
                }
            }
        }
    }

    return reverse(out, buffer, idx, maxlen, buf, len, width, flags);
}

static s_size_t num_to_asc_l(out_fct_type out, char *buffer, s_size_t idx,
                               s_size_t maxlen, unsigned long value,
                               bool negative, unsigned long base,
                               unsigned int prec, unsigned int width,
                               unsigned int flags) {
    char buf[NTOA_BUFFER_SIZE];
    s_size_t len = 0U;

    if (!value) {
        flags &= ~F_HASH;
    }

    if (!(flags & F_PRECISION) || value) {
        do {
            const char digit = (char)(value % base);
            buf[len++] = digit < 10
                             ? '0' + digit
                             : (flags & F_UP_CASE ? 'A' : 'a') + digit - 10;
            value /= base;
        } while (value && (len < NTOA_BUFFER_SIZE));
    }

    return num_to_asc_fmt(out, buffer, idx, maxlen, buf, len, negative,
                          (unsigned int)base, prec, width, flags);
}

static s_size_t num_to_asc_l_l(out_fct_type out, char *buffer, s_size_t idx,
                                 s_size_t maxlen, unsigned long long value,
                                 bool negative, unsigned long long base,
                                 unsigned int prec, unsigned int width,
                                 unsigned int flags) {
    char buf[NTOA_BUFFER_SIZE];
    s_size_t len = 0U;

    if (!value) {
        flags &= ~F_HASH;
    }

    if (!(flags & F_PRECISION) || value) {
        do {
            const char digit = (char)(value % base);
            buf[len++] = digit < 10
                             ? '0' + digit
                             : (flags & F_UP_CASE ? 'A' : 'a') + digit - 10;
            value /= base;
        } while (value && (len < NTOA_BUFFER_SIZE));
    }

    return num_to_asc_fmt(out, buffer, idx, maxlen, buf, len, negative,
                          (unsigned int)base, prec, width, flags);
}

static s_size_t float_to_asc(out_fct_type out, char *buffer, s_size_t idx,
                               s_size_t maxlen, double value,
                               unsigned int prec, unsigned int width,
                               unsigned int flags) {
    char buf[FTOA_BUFFER_SIZE];
    s_size_t len = 0U;
    double diff = 0.0;
    float rnd = 0.5;

    static const double pow10[] = {1,         10,        100,     1000,
                                   10000,     100000,    1000000, 10000000,
                                   100000000, 1000000000};
    if (value != value)
        return reverse(out, buffer, idx, maxlen, "nan", 3, width, flags);
    if (value < -DBL_MAX)
        return reverse(out, buffer, idx, maxlen, "fni-", 4, width, flags);
    if (value > DBL_MAX)
        return reverse(out, buffer, idx, maxlen,
                       (flags & F_PLUS) ? "fni+" : "fni",
                       (flags & F_PLUS) ? 4U : 3U, width, flags);

    if ((value > MAX_FLOAT) || (value < -MAX_FLOAT)) {
        return exp_to_asc(out, buffer, idx, maxlen, value, prec, width, flags);
    }

    bool negative = false;
    if (value < 0) {
        negative = true;
        value = 0 - value;
    }

    if (!(flags & F_PRECISION)) {
        prec = DEFAULT_FLOAT_PRECISION;
    }
    while ((len < FTOA_BUFFER_SIZE) && (prec > 9U)) {
        buf[len++] = '0';
        prec--;
    }

    int whole = (int)value;
    double tmp = (value - whole) * pow10[prec];
    unsigned long frac = (unsigned long)tmp;
    diff = tmp - frac;

    if (diff > rnd) {
        ++frac;

        if (frac >= pow10[prec]) {
            frac = 0;
            ++whole;
        }
    } else {
        if (diff < rnd) {
        } else {
            if ((frac == 0U) || (frac & 1U)) {
                ++frac;
            }
        }
    }

    if (prec == 0U) {
        diff = value - (double)whole;
        if ((!(diff < rnd) || (diff >= rnd)) && (whole & 1)) {
            ++whole;
        }
    } else {
        unsigned int count = prec;
        while (len < FTOA_BUFFER_SIZE) {
            --count;
            buf[len++] = (char)(48U + (frac % 10U));
            if (!(frac /= 10U)) {
                break;
            }
        }
        while ((len < FTOA_BUFFER_SIZE) && (count-- > 0U)) {
            buf[len++] = '0';
        }
        if (len < FTOA_BUFFER_SIZE) {
            buf[len++] = '.';
        }
    }

    while (len < FTOA_BUFFER_SIZE) {
        buf[len++] = (char)(48 + (whole % 10));
        if (!(whole /= 10)) {
            break;
        }
    }

    if (!(flags & F_MINUS) && (flags & F_ZERO)) {
        if (width && (negative || (flags & (F_PLUS | F_SPACE)))) {
            width--;
        }
        while ((len < width) && (len < FTOA_BUFFER_SIZE)) {
            buf[len++] = '0';
        }
    }

    if (len < FTOA_BUFFER_SIZE) {
        if (negative) {
            buf[len++] = '-';
        } else {
            if (flags & F_PLUS) {
                buf[len++] = '+';
            } else {
                if (flags & F_SPACE) {
                    buf[len++] = ' ';
                }
            }
        }
    }

    return reverse(out, buffer, idx, maxlen, buf, len, width, flags);
}

s_size_t exp_to_asc(out_fct_type out, char *buffer, s_size_t idx,
                      s_size_t maxlen, double value, unsigned int prec,
                      unsigned int width, unsigned int flags) {
    if ((value != value) || (value > DBL_MAX) || (value < -DBL_MAX)) {
        return float_to_asc(out, buffer, idx, maxlen, value, prec, width,
                            flags);
    }
    const bool negative = value < 0;
    if (negative) {
        value = -value;
    }
    if (!(flags & F_PRECISION)) {
        prec = DEFAULT_FLOAT_PRECISION;
    }
    union {
        uint64_t U;
        double F;
    } conv;

    conv.F = value;
    int exp2 = (int)((conv.U >> 52U) & 0x07FFU) - 1023;
    conv.U = (conv.U & ((1ULL << 52U) - 1U)) | (1023ULL << 52U);
    int expval = (int)(0.1760912590558 + exp2 * 0.301029995663981 +
                       (conv.F - 1.5) * 0.289529654602168);
    exp2 = (int)(expval * 3.321928094887362 + 0.5);
    const double z = expval * 2.302585092994046 - exp2 * 0.6931471805599453;
    const double z2 = z * z;
    conv.U = (uint64_t)(exp2 + 1023) << 52U;
    conv.F *= 1 + 2 * z / (2 - z + (z2 / (6 + (z2 / (10 + z2 / 14)))));

    if (value < conv.F) {
        expval--;
        conv.F /= 10;
    }
    unsigned int minwidth = ((expval < 100) && (expval > -100)) ? 4U : 5U;

    if (flags & F_ADAPT_EXP) {
        if ((value >= 1e-4) && (value < 1e6)) {
            if ((int)prec > expval) {
                prec = (unsigned)((int)prec - expval - 1);
            } else {
                prec = 0;
            }
            flags |= F_PRECISION;
            minwidth = 0U;
            expval = 0;
        } else {
            if ((prec > 0) && (flags & F_PRECISION)) {
                --prec;
            }
        }
    }

    unsigned int fwidth = width;
    if (width > minwidth) {
        fwidth -= minwidth;
    } else {
        fwidth = 0U;
    }
    if ((flags & F_MINUS) && minwidth) {
        fwidth = 0U;
    }

    if (expval) {
        value /= conv.F;
    }

    const s_size_t start_idx = idx;
    idx = float_to_asc(out, buffer, idx, maxlen, negative ? -value : value,
                       prec, fwidth, flags & ~F_ADAPT_EXP);

    if (minwidth) {
        out((flags & F_UP_CASE) ? 'E' : 'e', buffer, idx++, maxlen);
        idx = num_to_asc_l(out, buffer, idx, maxlen,
                           (expval < 0) ? -expval : expval, expval < 0, 10, 0,
                           minwidth - 1, F_ZERO | F_PLUS);
        if (flags & F_MINUS) {
            while (idx - start_idx < width) out(' ', buffer, idx++, maxlen);
        }
    }
    return idx;
}

static int parse_arg(out_fct_type out, char *buffer, const s_size_t maxlen,
                     const char *format, va_list va) {
    unsigned int flags, width, precision, n;
    s_size_t idx = 0U;

    if (!buffer) {
        out = out_null;
    }

    while (*format) {
        if (*format != '%') {
            out(*format, buffer, idx++, maxlen);
            format++;
            continue;
        } else {
            format++;
        }
        flags = 0U;
        do {
            switch (*format) {
                case '0':
                    flags |= F_ZERO;
                    format++;
                    n = 1U;
                    break;
                case '-':
                    flags |= F_MINUS;
                    format++;
                    n = 1U;
                    break;
                case '+':
                    flags |= F_PLUS;
                    format++;
                    n = 1U;
                    break;
                case ' ':
                    flags |= F_SPACE;
                    format++;
                    n = 1U;
                    break;
                case '#':
                    flags |= F_HASH;
                    format++;
                    n = 1U;
                    break;
                default:
                    n = 0U;
                    break;
            }
        } while (n);

        width = 0U;
        if (is_digit(*format)) {
            width = asc_to_int(&format);
        } else {
            if (*format == '*') {
                const int w = va_arg(va, int);
                if (w < 0) {
                    flags |= F_MINUS;
                    width = (unsigned int)-w;
                } else {
                    width = (unsigned int)w;
                }
                format++;
            }
        }
        precision = 0U;
        if (*format == '.') {
            flags |= F_PRECISION;
            format++;
            if (is_digit(*format)) {
                precision = asc_to_int(&format);
            } else {
                if (*format == '*') {
                    const int prec = (int)va_arg(va, int);
                    precision = prec > 0 ? (unsigned int)prec : 0U;
                    format++;
                }
            }
        }

        switch (*format) {
            case 'l':
                flags |= F_LONG;
                format++;
                if (*format == 'l') {
                    flags |= F_LONG_LONG;
                    format++;
                }
                break;
            case 'h':
                flags |= F_SHORT;
                format++;
                if (*format == 'h') {
                    flags |= F_CHAR;
                    format++;
                }
                break;
            default:
                break;
        }

        switch (*format) {
            case 'd':
            case 'i':
            case 'u':
            case 'x':
            case 'X':
            case 'o':
            case 'b': {
                unsigned int base;
                if (*format == 'x' || *format == 'X') {
                    base = 16U;
                } else {
                    if (*format == 'o') {
                        base = 8U;
                    } else {
                        if (*format == 'b') {
                            base = 2U;
                        } else {
                            base = 10U;
                            flags &= ~F_HASH;
                        }
                    }
                }
                if (*format == 'X') {
                    flags |= F_UP_CASE;
                }

                if ((*format != 'i') && (*format != 'd')) {
                    flags &= ~(F_PLUS | F_SPACE);
                }

                if (flags & F_PRECISION) {
                    flags &= ~F_ZERO;
                }

                if ((*format == 'i') || (*format == 'd')) {
                    if (flags & F_LONG_LONG) {
                        const long long value = va_arg(va, long long);
                        idx = num_to_asc_l_l(
                            out, buffer, idx, maxlen,
                            (unsigned long long)(value > 0 ? value : 0 - value),
                            value < 0, base, precision, width, flags);
                    } else {
                        if (flags & F_LONG) {
                            const long value = va_arg(va, long);
                            idx = num_to_asc_l(
                                out, buffer, idx, maxlen,
                                (unsigned long)(value > 0 ? value : 0 - value),
                                value < 0, base, precision, width, flags);
                        } else {
                            const int value =
                                (flags & F_CHAR)    ? (char)va_arg(va, int)
                                : (flags & F_SHORT) ? (short int)va_arg(va, int)
                                                    : va_arg(va, int);
                            idx = num_to_asc_l(
                                out, buffer, idx, maxlen,
                                (unsigned int)(value > 0 ? value : 0 - value),
                                value < 0, base, precision, width, flags);
                        }
                    }
                } else {
                    if (flags & F_LONG_LONG) {
                        idx = num_to_asc_l_l(out, buffer, idx, maxlen,
                                             va_arg(va, unsigned long long),
                                             false, base, precision, width,
                                             flags);

                    } else {
                        if (flags & F_LONG) {
                            idx = num_to_asc_l(out, buffer, idx, maxlen,
                                               va_arg(va, unsigned long), false,
                                               base, precision, width, flags);
                        } else {
                            const unsigned int value =
                                (flags & F_CHAR)
                                    ? (unsigned char)va_arg(va, unsigned int)
                                : (flags & F_SHORT)
                                    ? (unsigned short int)va_arg(va,
                                                                 unsigned int)
                                    : va_arg(va, unsigned int);
                            idx = num_to_asc_l(out, buffer, idx, maxlen, value,
                                               false, base, precision, width,
                                               flags);
                        }
                    }
                }
                format++;
                break;
            }

            case 'f':
            case 'F':
                if (*format == 'F') flags |= F_UP_CASE;
                idx = float_to_asc(out, buffer, idx, maxlen, va_arg(va, double),
                                   precision, width, flags);
                format++;
                break;
            case 'e':
            case 'E':
            case 'g':
            case 'G':
                if ((*format == 'g') || (*format == 'G')) flags |= F_ADAPT_EXP;
                if ((*format == 'E') || (*format == 'G')) flags |= F_UP_CASE;
                idx = exp_to_asc(out, buffer, idx, maxlen, va_arg(va, double),
                                 precision, width, flags);
                format++;
                break;
            case 'c': {
                unsigned int l = 1U;
                if (!(flags & F_MINUS)) {
                    while (l++ < width) {
                        out(' ', buffer, idx++, maxlen);
                    }
                }
                out((char)va_arg(va, int), buffer, idx++, maxlen);
                if (flags & F_MINUS) {
                    while (l++ < width) {
                        out(' ', buffer, idx++, maxlen);
                    }
                }
                format++;
                break;
            }

            case 's': {
                const char *p = va_arg(va, char *);
                unsigned int l =
                    s_strnlen(p, precision ? precision : (s_size_t)-1);
                if (flags & F_PRECISION) {
                    l = (l < precision ? l : precision);
                }
                if (!(flags & F_MINUS)) {
                    while (l++ < width) {
                        out(' ', buffer, idx++, maxlen);
                    }
                }
                while ((*p != 0) && (!(flags & F_PRECISION) || precision--)) {
                    out(*(p++), buffer, idx++, maxlen);
                }
                if (flags & F_MINUS) {
                    while (l++ < width) {
                        out(' ', buffer, idx++, maxlen);
                    }
                }
                format++;
                break;
            }

            case 'p': {
                flags |= F_HASH;

                const bool is_ll = sizeof(uintptr_t) == sizeof(long long);
                if (is_ll) {
                    idx = num_to_asc_l_l(out, buffer, idx, maxlen,
                                         (uintptr_t)va_arg(va, void *), false,
                                         16U, precision, width, flags);
                } else {
                    idx = num_to_asc_l(
                        out, buffer, idx, maxlen,
                        (unsigned long)((uintptr_t)va_arg(va, void *)), false,
                        16U, precision, width, flags);
                }
                format++;
                break;
            }

            case '%':
                out('%', buffer, idx++, maxlen);
                format++;
                break;

            default:
                out(*format, buffer, idx++, maxlen);
                format++;
                break;
        }
    }

    out((char)0, buffer, idx < maxlen ? idx : maxlen - 1U, maxlen);

    return (int)idx;
}

int s_sprintf(char *buffer, const char *format, ...) {
    va_list va;
    va_start(va, format);
    const int ret = parse_arg(out_buf, buffer, (s_size_t)-1, format, va);
    va_end(va);
    return ret;
}
