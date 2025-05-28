#pragma once
#ifndef GENERAL_H
#define GENERAL_H

#include <QMap>
#include <QFile>

// path
#define QSS_L_MAIN_PATH         ":/qss/l_main.qss"
#define QSS_D_MAIN_PATH         ":/qss/d_main.qss"
#define QSS_DIALOG              ":/qss/dialog.qss"

#define ICON_CASHTRACKER        ":/icons/cashtracker.ico"

// Data Base
#define DB_PATH                 "./db/userdata.db"

#define ENTITIES                "'entities'"

#define LOG_FRONT               "../logs/frontend.log"

// indexes
#define CNT_CONVERTER           0
#define CNT_PROGRESS            1
#define CNT_NOTEINTERFACE       2
#define CNT_DBINTERFACE         3
#define CNT_NEWLAND             4

// api
#define BUFFER_PATH             "../buffer/buffer.txt"
#define RESPONSE_PATH           "../buffer/response.txt"
#define ARGUMENT_PATH           "../buffer/args.txt"
#define PY_BACK_PATH            "../py_backend/processor.py"
#ifdef _WIN32
#define OS_CALL_BACKEND_PATH    "run_backend.bat"
#else
#define OS_CALL_BACKEND_PATH    "run_backend.sh"
#endif


// api response types
#define TEXT_T      "text"
#define REAL_T      "real"
#define INT_T       "int"
#define DATE_T      "date"

#define NULL_ARG    "@"

enum {
    network_py, logger_py, parser_py, cache_py
};

enum {
    convert = 0x00,                 // converter
    export_json = 0x10, export_csv, // progress / dbinterface
    update_crypto_rates             // newland
};

// utils
static const QMap<int, QString> py_utils = {
    {network_py, "network_py"},
    {logger_py, "logger_py"},
    {parser_py, "parser_py"},
    {cache_py, "cache_py"}
};

// requests
static const QMap<int, QString> py_funs = {
    {convert, "convert"},
    {export_json, "export_json"}, {export_csv, "export_csv"},
    {update_crypto_rates, "update_crypto_rates"}
};

// currencies
enum {
    USD = 1, EUR, GBP, JPY, CNY, CHF,
    AUD, CAD, NZD, SEK, NOK, DKK,
    RUB, PLN, CZK,HUF, TRY, INR,
    BRL, ZAR, MXN, SGD, HKD, KRW,
    THB, MYR, IDR, VND, AED, SAR,
    EGP
};

static const QMap<QString, int> curs = {
    { "USD", USD }, { "EUR", EUR }, { "GBP", GBP }, { "JPY", JPY },
    { "CNY", CNY }, { "CHF", CHF }, { "AUD", AUD }, { "CAD", CAD },
    { "NZD", NZD }, { "SEK", SEK }, { "NOK", NOK }, { "DKK", DKK },
    { "RUB", RUB }, { "PLN", PLN }, { "CZK", CZK }, { "HUF", HUF },
    { "TRY", TRY }, { "INR", INR }, { "BRL", BRL }, { "ZAR", ZAR },
    { "MXN", MXN }, { "SGD", SGD }, { "HKD", HKD }, { "KRW", KRW },
    { "THB", THB }, { "MYR", MYR }, { "IDR", IDR }, { "VND", VND },
    { "AED", AED }, { "SAR", SAR }, { "EGP", EGP }
};

// protocol manager
enum exitcodes{
    success = 0,
    network_err, protocol_err, response_err, openfile_err,
    ready_to_read,
    parse_err,
    run_err,
    undefined,
    fatal_err = -1
};

static const QMap<QString, int> codes = {
    { "success",       success },
    { "network_err",   network_err },
    { "protocol_err",  protocol_err },
    { "response_err",  response_err },
    { "openfile_err",  openfile_err },
    { "ready_to_read", ready_to_read },
    { "parse_err",     parse_err },
    { "run_err",       run_err },
    { "undefined",     undefined },
    { "fatal_err",     fatal_err }
};

static const QMap<QString, bool> isloss = {
    { "Rent",            true },
    { "Taxes",           true },
    { "Electricity",     true },
    { "Water",           true },
    { "Gas",             true },
    { "Internet",        true },
    { "Food",            true },
    { "Transportation",  true },
    { "Health",          true },
    { "Education",       true },
    { "Entertainment",   true },
    { "Other",           false },   // means other losses
    { "Salary",          false },
    { "Gift",            false },
    { "Bonus",           false },
    { "Cashback",        false },
    { "Freelance",       false },
};

#endif // GENERAL_H
