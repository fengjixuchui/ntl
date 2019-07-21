#include "pch.h"
#include "CppUnitTest.h"

#include "../ntl/vector"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ntltest {
	TEST_CLASS(vector) {
	public:
		TEST_METHOD(empty_constructor) {
            ntl::vector<int> v;
		}
        TEST_METHOD(count_constructor) {
            size_t size = 16;
            ntl::vector<int> v(size);
            Assert::AreEqual(v.size(), size);
            Assert::AreEqual(v.capacity(), size);
            for (auto e : v) {
                Assert::AreEqual(e, 0);
            }
        }
        TEST_METHOD(count_value_constructor) {
            int value = 2;
            size_t size = 16;
            ntl::vector<int> v(size, value);
            Assert::AreEqual(v.size(), size);
            Assert::AreEqual(v.capacity(), size);
            for (auto e : v) {
                Assert::AreEqual(e, value);
            }
        }
        TEST_METHOD(range_constructor) {
            int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
            ntl::vector<int> w(a, a + 8);
            for (int i = 0; i != 8; i++) {
                Assert::AreEqual(w[i], i);
            }
        }
	};
}
