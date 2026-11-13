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

bool Playlist::add_track(const Track& track) {
    if (m_count >= m_capacity || track.title.empty()) {
        return false;
    }

    m_tracks[m_count] = track;
    m_count++;
    return true;
}

int Playlist::size() const {
    return m_count;
}
