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

class TimeTest : public ::testing::Test
{
protected:
    Time t1{std::make_pair(12, 12)};
    Time t2{std::make_pair(12, 12)};
    Time t3{std::make_pair(10, 12)};
    Time t4{std::make_pair(20, 24)};
};

TEST_F(TimeTest, ComparationOperators)
{
    EXPECT_EQ(t1, t2);
    EXPECT_EQ(true, t1 == t2);
    EXPECT_EQ(false, t1 != t2);
    EXPECT_EQ(true, t2 >= t1);
    EXPECT_EQ(true, t2 <= t1);

    t2 = {std::make_pair<int, int>(13, 12)};
    EXPECT_NE(t1, t2);
    EXPECT_NE(true, t1 == t2);
    EXPECT_NE(false, t1 != t2);
    EXPECT_EQ(true, t2 > t1);
    EXPECT_EQ(true, t2 >= t1);
    EXPECT_NE(true, t2 < t1);
    EXPECT_NE(true, t2 <= t1);
}

TEST_F(TimeTest, AssignmentOperators)
{
    t1 = {std::make_pair<int, int>(10, 12)};
    t2 = {std::make_pair<int, int>(20, 24)};
    Time t3 = t2;
    EXPECT_EQ(t3, t2);

    Time t4 = t2;
    t4 -= t1;
    EXPECT_EQ(t1, t4);

    t1 += t1;
    EXPECT_EQ(t1, t2);
}

TEST_F(TimeTest, BinaryOperators)
{
    t1 = {std::make_pair<int, int>(10, 12)};
    t2 = {std::make_pair<int, int>(20, 24)};
    Time t3 = t2 - t1;
    EXPECT_EQ(t3, t1);

    Time t4 = t3 + t1;
    EXPECT_EQ(t4, t2);
}

TEST_F(TimeTest, Ceiling)
{
    t1 = {std::make_pair<int, int>(12, 12)};
    EXPECT_EQ(13, t1.ceil_to_hours());

    t1 = {std::make_pair<int, int>(0, 0)};
    EXPECT_EQ(0, t1.ceil_to_hours());

    t1 = {std::make_pair<int, int>(4, 1)};
    EXPECT_EQ(5, t1.ceil_to_hours());

    t1 = {std::make_pair<int, int>(14, 59)};
    EXPECT_EQ(15, t1.ceil_to_hours());
}

TEST(Parser, TestTrim)
{
    std::string str;
    str = Parser::trim(" 123_123    ");
    EXPECT_EQ("123_123", str);
    str = Parser::trim("qwerty    ");
    EXPECT_EQ("qwerty", str);
    str = Parser::trim("   qwerty");
    EXPECT_EQ("qwerty", str);
}

TEST(Parser, TestTrimInPlace)
{
    std::string str = " qwerty ";
    std::string str2 = str;
    Parser::trim_in_place(str);
    EXPECT_NE(str, str2);
    EXPECT_EQ(str, "qwerty");
}

TEST(Parser, ParseTime)
{
    Time t1 = {std::make_pair<int,int>(12,45)};
    Time t2= Parser::parse_time("  12:45  ");
    EXPECT_EQ(t1,t2);
    t2 = Parser::parse_time("  12 : 45  ");
    EXPECT_EQ(t1, t2);
    EXPECT_THROW(Parser::parse_time("  12  45  "), std::runtime_error);
    EXPECT_NO_THROW(Parser::parse_time("12 : 45 09 00"));
}

TEST(Parser, ParseTimeLine)
{
    Time t1 = {std::make_pair<int, int>(12, 45)};
    Time t2 = {std::make_pair<int, int>(9, 0)};
    auto time_line = Parser::parse_time_line("  12:45  09:00");
    EXPECT_EQ(time_line.first, t1);
    EXPECT_EQ(time_line.second, t2);
    time_line = Parser::parse_time_line("  12 : 45  09 : 00 ");
    EXPECT_EQ(time_line.first, t1);
    EXPECT_EQ(time_line.second, t2);
    EXPECT_THROW(Parser::parse_time_line("12 : 45 09 00"), std::runtime_error);
    EXPECT_THROW(Parser::parse_time_line("12 45 09 00"), std::runtime_error);
}

TEST(Parser, ParseActionLine)
{
    Event event1 = Parser::parse_action_line("08:48 1 client1");
    Event event2 = {std::make_pair<int, int>(8, 48), 1, "client1"};
    EXPECT_EQ(event1, event2);
    event1 = Parser::parse_action_line("08:48 1 client1 2");
    event2 = {std::make_pair<int, int>(8, 48), 1, "client1", "2"};
    EXPECT_EQ(event1, event2);
}

class ClubTest : public ::testing::Test
{
protected:
    Computer_club club{3,10,
     std::make_pair<Time,Time>({std::make_pair<int,int>(10,0)},
      {std::make_pair<int,int>(20,0)})};
};

TEST_F(ClubTest, AddClient)
{
    Event event= {std::make_pair(10,0),1,"client1"};
    EXPECT_NO_THROW(club.add_client(event));
    EXPECT_THROW(club.add_client(event), std::runtime_error);
}

TEST_F(ClubTest, SitDown)
{
    Event event = {std::make_pair(10, 0), 1, "client1"};
    EXPECT_NO_THROW(club.add_client(event));
    event = {std::make_pair(11, 0), 2, "client1", "1"};
    EXPECT_NO_THROW(club.sit_down(event));
    EXPECT_THROW(club.sit_down(event), std::runtime_error);
    event = {std::make_pair(12, 0), 2, "client2", "1"};
    EXPECT_THROW(club.sit_down(event), std::runtime_error);
    event = {std::make_pair(12, 0), 1, "client2", "1"};
    EXPECT_NO_THROW(club.add_client(event));
    event ={std::make_pair(13, 0), 2, "client2", "1"};
    EXPECT_THROW(club.sit_down(event), std::runtime_error);
    event = {std::make_pair(14, 0), 2, "client2", "2"};
    EXPECT_NO_THROW(club.sit_down(event));
}

TEST_F(ClubTest, ClientWait)
{
    Event event = {std::make_pair(10, 0), 3, "client1"};
    EXPECT_THROW(club.client_wait(event), std::runtime_error);
    event = {std::make_pair(10, 0), 1, "client1"};
    EXPECT_NO_THROW(club.add_client(event));
    event = {std::make_pair(11, 0), 3, "client1"};
    EXPECT_THROW(club.client_wait(event), std::runtime_error);
    for(int i =2; i < 5; ++i)
    {
        event = {std::make_pair(12, 0), 1, Message::make_string("client", i)};
        EXPECT_NO_THROW(club.add_client(event));
    }
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    event = {std::make_pair(13, 0), 3, "client1"};
    EXPECT_NO_THROW(club.client_wait(event));
    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "13:00 11 client1\n");
}

TEST_F(ClubTest, EraseClient)
{
    Event event = {std::make_pair(10, 0), 4, "client1"};
    EXPECT_THROW(club.erase_client(event), std::runtime_error);
    event = {std::make_pair(10, 0), 1, "client1"};
    EXPECT_NO_THROW(club.add_client(event));
    event = {std::make_pair(10, 0), 4, "client2"};
    EXPECT_THROW(club.erase_client(event), std::runtime_error);
    event = {std::make_pair(11, 0), 1, "client2"};
    EXPECT_NO_THROW(club.add_client(event));
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    event = {std::make_pair(12, 0), 4, "client1"};
    EXPECT_NO_THROW(club.erase_client(event));
    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "");
    buffer.clear();
    event = {std::make_pair(10, 0), 1, "client1"};
    EXPECT_NO_THROW(club.add_client(event));
    event = {std::make_pair(13, 0), 2, "client1", "1"};
    EXPECT_NO_THROW(club.sit_down(event));
    old = std::cout.rdbuf(buffer.rdbuf());
    event = {std::make_pair(14, 0), 4, "client1"};
    EXPECT_NO_THROW(club.erase_client(event));
    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "14:00 12 client2 1\n");
}

TEST_F(ClubTest, CheckProfit)
{
    Event event = {std::make_pair(10, 0), 1, "client1"};
    EXPECT_NO_THROW(club.add_client(event));
    event = {std::make_pair(10, 0), 1, "client2", ""};
    EXPECT_NO_THROW(club.add_client(event));
    event = {std::make_pair(14, 0), 2, "client2", "1"};
    EXPECT_NO_THROW(club.sit_down(event));
    event = {std::make_pair(15, 11), 2, "client1", "2"};
    EXPECT_NO_THROW(club.sit_down(event));

    event = {std::make_pair(16, 0), 1, "client3", ""};
    EXPECT_NO_THROW(club.add_client(event));
    event = {std::make_pair(16, 1), 2, "client3", "3"};
    EXPECT_NO_THROW(club.sit_down(event));
    event = {std::make_pair(16, 5), 4, "client3"};
    EXPECT_NO_THROW(club.erase_client(event));
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

    club.kick_out_clients();
    std::cout.rdbuf(old); 
    EXPECT_EQ(buffer.str(), "20:00 11 client1\n20:00 11 client2\n");
    buffer.str("");
    buffer.clear();

    old = std::cout.rdbuf(buffer.rdbuf());
    club.print_profit();
    std::cout.rdbuf(old); 
    EXPECT_EQ(buffer.str(), "1 60 06:00\n2 50 04:49\n3 10 00:04\n");
}


TEST(Reader, READER)
{
    std::string filename = "../test.txt";
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    Reader::read(filename);
    std::cout.rdbuf(old);
    std::string output_cout = R"(09:00
    08:48 1 client1
    08:48 13 NotOpenYet
    09:41 1 client1
    09:48 1 client2 
    09:52 3 client1
    09:52 13 ICanWaitNoLonger!
    09:54 2 client1 1
    10:25 2 client2 2
    10:58 1 client3 
    10:59 2 client3 3
    11:30 1 client4
    11:35 2 client4 2
    11:35 13 PlaceIsBusy
    11:45 3 client4
    12:33 4 client1
    12:33 12 client4 1
    12:43 4 client2
    15:52 4 client4
    19:00 11 client3
    19:00
    1 70 05:58 
    2 30 02:18
    3 90 08:01 
    )";
    std::string buffer_str = buffer.str();
    output_cout.erase(std::remove(output_cout.begin(), output_cout.end(), ' '), output_cout.end());
    buffer_str.erase(std::remove(buffer_str.begin(), buffer_str.end(), ' '), buffer_str.end());
    EXPECT_EQ(buffer_str, output_cout);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}