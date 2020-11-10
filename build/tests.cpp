#include <gtest/gtest.h>
#include "../app/file.cpp"

TEST(File, WriteReadFromFile) { 
    File file("/tmp/tmpfile");
    ASSERT_EQ(true, file.write("test"));
    ASSERT_EQ("test", file.read());
    ASSERT_NE("failtest", file.read());
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
