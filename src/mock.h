#ifndef MOCK_H
#define MOCK_H

typedef struct mock_s {
    void *callback;
    int on;
} mock_t;

void mock_set_callback(mock_t *mock, void *callback);
void *mock_get_callback(mock_t *mock);
void mock_on(mock_t *mock);
void mock_off(mock_t *mock);
int mock_is_enabled(mock_t *mock);

#define SIMULACRUM(__return_type, __function_name, _N, ...)                                               \
mock_t __function_name##_mock = {.on = 1};                                                                \
typedef void (*__function_name##_mock##_callback)(arg_names_and_type_N(_N, __VA_ARGS__));                 \
void *__real_##__function_name(arg_names_and_type_N(_N, __VA_ARGS__));                                    \
void *__wrap_##__function_name(arg_names_and_type_N(_N, __VA_ARGS__))                                     \
{                                                                                                         \
  if (mock_is_enabled(&__function_name##_mock))                                                           \
  {                                                                                                       \
      if (mock_get_callback(&__function_name##_mock))                                                     \
      {                                                                                                   \
        ((__function_name##_mock##_callback)mock_get_callback(&__function_name##_mock))(arg_names_N(_N)); \
      }                                                                                                   \
      return NULL;                                                                                        \
  }                                                                                                       \
  else                                                                                                    \
  {                                                                                                       \
    return __real_##__function_name(arg_names_N(_N));                                                     \
  }                                                                                                       \
}                                                                                                         \

char *_arg0;
#define arg_names_and_type_0()
#define arg_names_and_type_1(_t1) _t1 _arg1
#define arg_names_and_type_2(_t1, _t2) _t1 _arg1, _t2 _arg2
#define arg_names_and_type_3(_t1, _t2, _t3) _t1 _arg1, _t2 _arg2, _t3 _arg3
#define arg_names_and_type_4(_t1, _t2, _t3, _t4) _t1 _arg1, _t2 _arg2, _t3 _arg3, _t4 _arg4
#define arg_names_and_type_5(_t1, _t2, _t3, _t4, _t5) _t1 _arg1, _t2 _arg2, _t3 _arg3, _t4 _arg4, _t5 _arg5
#define arg_names_and_type_6(_t1, _t2, _t3, _t4, _t5, _t6) _t1 _arg1, _t2 _arg2, _t3 _arg3, _t4 _arg4, _t5 _arg5, _t6 _arg6
#define arg_names_and_type_7(_t1, _t2, _t3, _t4, _t5, _t6, _t7) _t1 _arg1, _t2 _arg2, _t3 _arg3, _t4 _arg4, _t5 _arg5, _t6 _arg6, _t7 _arg7
#define arg_names_and_type_8(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8) _t1 _arg1, _t2 _arg2, _t3 _arg3, _t4 _arg4, _t5 _arg5, _t6 _arg6, _t7 _arg7, _t8 _arg8
#define arg_names_and_type_9(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9) _t1 _arg1, _t2 _arg2, _t3 _arg3, _t4 _arg4, _t5 _arg5, _t6 _arg6, _t7 _arg7, _t8 _arg8, _t9 _arg9
#define arg_names_and_type_10(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9, _t10) _t1 _arg1, _t2 _arg2, _t3 _arg3, _t4 _arg4, _t5 _arg5, _t6 _arg6, _t7 _arg7, _t8 _arg8, _t9 _arg9, _t10 _arg10

#define arg_names_0
#define arg_names_1 _arg1
#define arg_names_2 _arg1, _arg2
#define arg_names_3 _arg1, _arg2, _arg3
#define arg_names_4 _arg1, _arg2, _arg3, _arg4
#define arg_names_5 _arg1, _arg2, _arg3, _arg4, _arg5
#define arg_names_6 _arg1, _arg2, _arg3, _arg4, _arg5, _arg6
#define arg_names_7 _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7
#define arg_names_8 _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8
#define arg_names_9 _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9
#define arg_names_10 _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10

#define arg_names_and_type_N(_N, ...) arg_names_and_type_##_N(__VA_ARGS__)
#define arg_names_N(_N, ...) arg_names_##_N

#endif //MOCK_H
