#include "gtest/gtest.h"
#include "Reader.h"

TEST(Message, Conversion)
{
    std::string str = "12 string";
    EXPECT_EQ(str, Message::make_string("12", " ", "str", "ing"));
}

TEST(Message, EmptyInput)
{
    EXPECT_EQ("", Message::make_string());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}