#include <gtest/gtest.h>
#include "duration.h"

TEST(DurationTest, TotalSeconds) {
    Duration time(3, 5);
    EXPECT_EQ(time.total_seconds(), 185);
}

TEST(DurationTest, NegativeTotal) {
    Duration time(0, -5);
    EXPECT_EQ(time.total_seconds(), 0);
}

TEST(DurationTest, SecondsCarry) {
    Duration time(0, 75);
    EXPECT_EQ(time.total_seconds(), 75);
}

#include "playlist.h"

TEST(PlaylistTest, AddTrackAndSize) {
    Playlist playlist(2);

    EXPECT_TRUE(playlist.add_track({"Static", Duration(2, 58)}));
    EXPECT_EQ(playlist.size(), 1);

    EXPECT_TRUE(playlist.add_track({"Neon Rain", Duration(4, 5)}));
    EXPECT_EQ(playlist.size(), 2);
}

TEST(PlaylistTest, RejectFullPlaylist) {
    Playlist playlist(1);

    EXPECT_TRUE(playlist.add_track({"Static", Duration(2, 58)}));
    EXPECT_FALSE(playlist.add_track({"Overflow", Duration(3, 30)}));
    EXPECT_EQ(playlist.size(), 1);
}

TEST(PlaylistTest, RejectEmptyTitle) {
    Playlist playlist(2);

    EXPECT_FALSE(playlist.add_track({"", Duration(1, 30)}));
    EXPECT_EQ(playlist.size(), 0);
}

TEST(PlaylistTest, MinimumCapacity) {
    Playlist playlist(0);

    EXPECT_TRUE(playlist.add_track({"First", Duration(1, 0)}));
    EXPECT_FALSE(playlist.add_track({"Second", Duration(2, 0)}));
}

TEST(PlaylistTest, FindTrack) {
    Playlist playlist(2);
    playlist.add_track({"Static", Duration(2, 58)});

    const Track* found = playlist.find_track("Static");
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->length.total_seconds(), 178);

    EXPECT_EQ(playlist.find_track("Missing"), nullptr);
}

#include <sstream>

TEST(DurationTest, Addition) {
    Duration first(3, 42);
    Duration second(4, 5);

    Duration result = first + second;

    EXPECT_EQ(result.total_seconds(), 467);
    EXPECT_EQ(first.total_seconds(), 222);
    EXPECT_EQ(second.total_seconds(), 245);
}

TEST(DurationTest, Equality) {
    EXPECT_TRUE(Duration(1, 15) == Duration(0, 75));
    EXPECT_FALSE(Duration(1, 15) == Duration(1, 16));
}

TEST(DurationTest, OutputFormat) {
    std::ostringstream out;
    out << Duration(3, 5);

    EXPECT_EQ(out.str(), "3:05");
}

TEST(PlaylistTest, TotalLength) {
    Playlist playlist(3);

    playlist.add_track({"Midnight Drive", Duration(3, 42)});
    playlist.add_track({"Neon Rain", Duration(4, 5)});
    playlist.add_track({"Static", Duration(2, 58)});

    EXPECT_EQ(playlist.total_length().total_seconds(), 645);
}

TEST(PlaylistTest, EmptyTotalLength) {
    Playlist playlist(2);

    EXPECT_EQ(playlist.total_length().total_seconds(), 0);
}
