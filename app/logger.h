#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include "general.h"

class logger
{
public:
    logger() = default;
    static int log(const QString what, const QString& path = LOG_FRONT);
};

#endif // LOGGER_H
