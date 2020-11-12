#include <gtest/gtest.h>
#include "../app/file.cpp"

/*TEST(File, WriteReadFromFile) {
    File file("/tmp/tmpfile");
    ASSERT_EQ(true, file.write("test"));
    EXPECT_EQ("test", file.read());
    EXPECT_NE("failtest", file.read());
}

TEST(File, WriteReadFromOtherFile) {
    File file("/tmp/tmpotherfile");
    ASSERT_EQ(true, file.write("test"));
    EXPECT_EQ("test", file.read());
    EXPECT_NE("failtest", file.read());
}*/

class FileTest : public ::testing::Test {

protected:
    File createFile(std::string value) {
        return File(value);
    }
};

TEST_F(FileTest, WriteReadFromFile) {
    auto file = createFile("/tmp/tmpfile");
    ASSERT_EQ(true, file.write("test"));
    EXPECT_EQ("test", file.read());
    EXPECT_NE("failtest", file.read());
}

TEST_F(FileTest, WriteReadFromOtherFile) {
    auto file = createFile("/tmp/tmpotherfile");
    ASSERT_EQ(true, file.write("test"));
    EXPECT_EQ("test", file.read());
    EXPECT_NE("failtest", file.read());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
