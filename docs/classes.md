# HW2 Class Sketch

Ignacio Rincon — COSC 1437

## Duration
Private data: `int m_total_seconds`.

Invariant: `m_total_seconds` is never negative.

Public functions:
- `Duration(int minutes = 0, int seconds = 0)`
- `int total_seconds() const`
- `Duration operator+(const Duration& other) const`
- `bool operator==(const Duration& other) const`
- `std::ostream& operator<<(std::ostream& out, const Duration& d)` (free function)

## Playlist
Private data: `Track* m_tracks`, `int m_count`, `int m_capacity`.

Invariants: capacity is at least 1; count is between 0 and capacity; the pointer owns an array of capacity tracks; no stored title is empty.

Public functions:
- `explicit Playlist(int capacity)`
- `~Playlist()`
- `bool add_track(const Track& track)`
- `int size() const`
- `Duration total_length() const`
- `const Track* find_track(const std::string& title) const`
- Copy constructor and copy assignment are deleted.

`Track` is a simple struct with a title and a `Duration` length.
