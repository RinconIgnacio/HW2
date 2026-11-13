#include "playlist.h"

Playlist::Playlist(int capacity) {
    if (capacity < 1) {
        capacity = 1;
    }

    m_capacity = capacity;
    m_count = 0;
    m_tracks = new Track[m_capacity];
}

Playlist::~Playlist() {
    delete[] m_tracks;
}
