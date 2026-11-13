#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include "track.h"

// A Playlist owns an array of tracks.
// Count stays between 0 and capacity.
// Capacity is at least 1, and stored titles are never empty.
class Playlist {
public:
    /**
     * @brief Creates a playlist with a fixed capacity.
     * @param capacity Maximum number of tracks.
     */
    explicit Playlist(int capacity);

    /**
     * @brief Releases the playlist's allocated memory.
     */
    ~Playlist();

    /**
     * @brief Adds a track if there is room and its title is not empty.
     * @param track Track to add.
     * @return True if the track was added.
     */
    bool add_track(const Track& track);

    /**
     * @brief Gets the number of stored tracks.
     * @return Track count.
     */
    int size() const;

    /**
     * @brief Gets the combined duration of all tracks.
     * @return Total playlist duration.
     */
    Duration total_length() const;

    /**
     * @brief Finds the first track with a matching title.
     * @param title Title to search for.
     * @return Pointer to the track, or nullptr if not found.
     */
    const Track* find_track(const std::string& title) const;

    Playlist(const Playlist&) = delete;
    Playlist& operator=(const Playlist&) = delete;

private:
    Track* m_tracks;
    int m_count;
    int m_capacity;
};

#endif
