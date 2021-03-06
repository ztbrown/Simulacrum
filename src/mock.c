#include "mock.h"

void mock_set_callback(mock_t *mock, void *callback)
{
    mock->callback = callback;
}

void *mock_get_callback(mock_t *mock)
{
    return mock->callback;
}

void mock_off(mock_t *mock)
{
    mock->on = 0;
}

void mock_on(mock_t *mock)
{
    mock->on = 1;
}

int mock_is_enabled(mock_t *mock)
{
    return mock->on;
}

void mock_increment_call_count(mock_t *mock)
{
    mock->call_count++;
}

int mock_get_call_count(mock_t *mock)
{
    return mock->call_count;
}

void mock_set_return_value(mock_t *mock, void *value)
{
    mock->return_value = value;
}

void *mock_get_return_value(mock_t *mock)
{
    return (void *)mock->return_value;
}
