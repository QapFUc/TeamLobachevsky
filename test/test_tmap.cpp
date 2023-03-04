#include <gtest.h>
#include "TMap.h"

TEST(TMap, can_create_map_with_positive_length)
{
  ASSERT_NO_THROW(TMap<char, int> m(1));
}

TEST(TMap, cannot_create_map_with_negative_length)
{
  ASSERT_ANY_THROW(TMap<char, int> m(-1));
}