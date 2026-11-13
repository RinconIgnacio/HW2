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
