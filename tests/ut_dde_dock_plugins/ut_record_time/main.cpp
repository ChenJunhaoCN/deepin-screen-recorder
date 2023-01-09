// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <gtest/gtest.h>
#include <QDebug>
#include <QApplication>
#include <sanitizer/asan_interface.h>
#include "test_all_interfaces.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "start RecordTimePlugin test cases ..............";
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
#ifdef ENABLE_TSAN_TOOL
    __sanitizer_set_report_path("./asan_ut_record_time.log");
#endif
    qDebug() << "end RecordTimePlugin test cases ..............";
    return ret;
}
