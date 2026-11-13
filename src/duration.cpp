#include "duration.h"
#include <iomanip>

Duration::Duration(int minutes, int seconds) {
    int total = minutes * 60 + seconds;

    if (total < 0) {
        total = 0;
    }

    m_total_seconds = total;
}

int Duration::total_seconds() const {
    return m_total_seconds;
}

Duration Duration::operator+(const Duration& other) const {
    Duration result;
    result.m_total_seconds = m_total_seconds + other.m_total_seconds;
    return result;
}

bool Duration::operator==(const Duration& other) const {
    return m_total_seconds == other.m_total_seconds;
}

std::ostream& operator<<(std::ostream& out, const Duration& d) {
    int minutes = d.total_seconds() / 60;
    int seconds = d.total_seconds() % 60;

    out << minutes << ':'
        << std::setfill('0') << std::setw(2) << seconds
        << std::setfill(' ');

    return out;
}
