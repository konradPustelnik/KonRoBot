#include <gtest/gtest.h>
#include "file.cpp"

// TEST(File, WriteReadFromFile) {
//     File file("/tmp/tmpfile");
//     ASSERT_EQ(true, file.write("test"));
//     EXPECT_EQ("test", file.read());
//     EXPECT_NE("failtest", file.read());
// }

// TEST(File, WriteReadFromOtherFile) {
//     File file("/tmp/tmpotherfile");
//     ASSERT_EQ(true, file.write("test"));
//     EXPECT_EQ("test", file.read());
//     EXPECT_NE("failtest", file.read());
// }

// class FileTest : public ::testing::Test {

// protected:
//     File createFile(std::string value) {
//         return File(value);
//     }
// };

// TEST_F(FileTest, WriteReadFromFile) {
//     auto file = createFile("/tmp/tmpfile");
//     ASSERT_EQ(true, file.write("test"));
//     EXPECT_EQ("test", file.read());
//     EXPECT_NE("failtest", file.read());
// }

// TEST_F(FileTest, WriteReadFromOtherFile) {
//     auto file = createFile("/tmp/tmpotherfile");
//     ASSERT_EQ(true, file.write("test"));
//     EXPECT_EQ("test", file.read());
//     EXPECT_NE("failtest", file.read());
// }

// This is a parameterization structure
struct TestParameters {
    std::string path;
    std::string input;
    std::string output;
    std::string failoutput;
};

class FileTest : public ::testing::TestWithParam<TestParameters> {};

TEST_P(FileTest, WriteReadFromFile) {
    TestParameters const& parameters = GetParam();
    File file(parameters.path);

    ASSERT_TRUE(file.write(parameters.input));
    EXPECT_EQ(parameters.input, file.read());
    EXPECT_EQ(parameters.output, file.read());
    EXPECT_NE(parameters.failoutput, file.read());

    ASSERT_TRUE(file.write(parameters.output));
    EXPECT_EQ(parameters.input, file.read());
    EXPECT_EQ(parameters.output, file.read());
    EXPECT_NE(parameters.failoutput, file.read());

    ASSERT_TRUE(file.write(parameters.failoutput));
    EXPECT_NE(parameters.input, file.read());
    EXPECT_NE(parameters.output, file.read());
    EXPECT_EQ(parameters.failoutput, file.read());
}

INSTANTIATE_TEST_CASE_P(FileTester, FileTest, ::testing::Values(
    TestParameters{"/tmp/tmpfile", "test", "test", "failtest"},
    TestParameters{"/tmp/tmpotherfile", "test", "test", "failtest"}
));

INSTANTIATE_TEST_CASE_P(InputOutputTester, FileTest, ::testing::Values(
    TestParameters{"/tmp/tmpfile", "test1", "test1", "failtest1"},
    TestParameters{"/tmp/tmpfile", "test2", "test2", "failtest2"},
    TestParameters{"/tmp/tmpfile", "test3", "test3", "failtest3"}
));
