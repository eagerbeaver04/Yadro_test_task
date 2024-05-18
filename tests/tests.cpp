#include "gtest/gtest.h"
#include "Reader.h"

TEST(Message, Conversion)
{
    EXPECT_EQ("12 string", Message::make_string(12, " ", "str", "ing", ""));
    EXPECT_EQ("1.2 str_len ", Message::make_string(1.2, " ", "str", "_len", " "));
    EXPECT_EQ("1,23", Message::make_string(1,",",23));
}

TEST(Message, EmptyInput)
{
    EXPECT_EQ("", Message::make_string());
}

TEST(Time, EmptyConstructor)
{
    Time t;  
    EXPECT_EQ(0, t.value.first);
    EXPECT_EQ(0, t.value.second);
}

TEST(Time, Ceiling)
{
    Time t1{std::make_pair<int,int>(12,12)};
    EXPECT_EQ(13, t1.ceil_to_hours());
    t1 = {std::make_pair<int, int>(0, 0)};
    EXPECT_EQ(0, t1.ceil_to_hours());
    t1 = {std::make_pair<int, int>(4, 1)};
    EXPECT_EQ(5, t1.ceil_to_hours());
    t1 = {std::make_pair<int, int>(14, 59)};
    EXPECT_EQ(15, t1.ceil_to_hours());
}

TEST(Time, ComparationOperators)
{
    Time t1{std::make_pair<int, int>(12, 12)};
    Time t2{std::make_pair<int, int>(12, 12)};
    EXPECT_EQ(t1,t2);
    EXPECT_EQ(true, t1 == t2);
    EXPECT_EQ(false, t1 != t2);
    EXPECT_EQ(true, t2 >= t1);
    EXPECT_EQ(true, t2 <= t1);
    t2 = {std::make_pair<int,int>(13,12)};
    EXPECT_NE(t1, t2);
    EXPECT_NE(true, t1 == t2);
    EXPECT_NE(false, t1 != t2);
    EXPECT_EQ(true, t2 > t1);
    EXPECT_EQ(true, t2 >= t1);
    EXPECT_NE(true, t2 < t1);
    EXPECT_NE(true, t2 <= t1);
}

TEST(Time, AssignmentOperators)
{
    Time t1{std::make_pair<int, int>(10, 12)};
    Time t2{std::make_pair<int, int>(20, 24)};
    Time t3 = t2;
    EXPECT_EQ(t3, t2);
    Time t4 = t2;
    t4-=t1;
    EXPECT_EQ(t1, t4);
    t1+=t1;
    EXPECT_EQ(t1, t2);
}

TEST(Time, BinaryOperators)
{
    Time t1{std::make_pair<int, int>(10, 12)};
    Time t2{std::make_pair<int, int>(20, 24)};
    Time t3 = t2 - t1;
    EXPECT_EQ(t3, t1);
    Time t4 = t3 + t1;
    EXPECT_EQ(t4, t2);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}