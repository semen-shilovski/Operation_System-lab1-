#include "pch.h"
#include "../../src/Source.h"
#pragma warning(disable: 2664)

TEST(EmployeeStructTest, EmployeeStructTest1) {
    employee e = { 1, "Alice", 40.0 };

    EXPECT_EQ(e.num, 1);
    EXPECT_STREQ(e.name, "Alice");
    EXPECT_DOUBLE_EQ(e.hours, 40.0);
}

TEST(EmployeeStructTest, EmployeeStructTest2) {
    employee e = { 99, "Sema", 40.0 };

    EXPECT_EQ(e.num, 99);
    EXPECT_STREQ(e.name, "Sema");
    EXPECT_DOUBLE_EQ(e.hours, 40.0);
}