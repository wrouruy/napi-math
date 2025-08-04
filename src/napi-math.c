#include <node_api.h>
#include <stdio.h>
#include <math.h>

// sum(a, b) => a + b
napi_value Sum(napi_env env, napi_callback_info info)
{
    napi_value args[2];
    size_t argc = 2;
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    double a, b;
    napi_get_value_double(env, args[0], &a);
    napi_get_value_double(env, args[1], &b);

    napi_value sum;
    napi_create_double(env, a + b, &sum);
    return sum;
}

// multiply(a, b) => a * b
napi_value Multiply(napi_env env, napi_callback_info info)
{
    napi_value args[2];
    size_t argc = 2;
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    double a, b;
    napi_get_value_double(env, args[0], &a);
    napi_get_value_double(env, args[1], &b);

    napi_value sum;
    napi_create_double(env, a * b, &sum);
    return sum;
}

// factorial(n) => n * (n - 1) * (n - 2) ...
napi_value Factorial(napi_env env, napi_callback_info info)
{
    napi_value args[1];
    size_t argc = 1;
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    int64_t n;
    napi_get_value_int64(env, args[0], &n);

    int64_t result = 1;
    for (int64_t i = 2; i <= n; i++)
        result *= i;

    napi_value factorial;
    napi_create_int64(env, result, &factorial);
    return factorial;
}

// pow(base, exp) => base ** exp
napi_value Pow(napi_env env, napi_callback_info info)
{
    napi_value args[2];
    size_t argc = 2;
    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    double base, exp;
    napi_get_value_double(env, args[0], &base);
    napi_get_value_double(env, args[1], &exp);

    napi_value result;
    napi_create_double(env, pow(base, exp), &result);

    return result;
}

// Initialization and export of functions
napi_value Init(napi_env env, napi_value exports)
{
    napi_value fnSum, fnMultiply, fnFactorial, fnPow;

    napi_create_function(env, NULL, 0, Sum, NULL, &fnSum);
    napi_set_named_property(env, exports, "sum", fnSum);

    napi_create_function(env, NULL, 0, Multiply, NULL, &fnMultiply);
    napi_set_named_property(env, exports, "multiply", fnMultiply);

    napi_create_function(env, NULL, 0, Factorial, NULL, &fnFactorial);
    napi_set_named_property(env, exports, "factorial", fnFactorial);

    napi_create_function(env, NULL, 0, Pow, NULL, &fnPow);
    napi_set_named_property(env, exports, "pow", fnPow);

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)