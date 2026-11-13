#ifndef DURATION_H
#define DURATION_H

#include <ostream>

// A Duration always stores zero or more seconds.
class Duration {
public:
    /**
     * @brief Creates a duration from minutes and seconds.
     * @param minutes Number of minutes.
     * @param seconds Number of seconds.
     */
    Duration(int minutes = 0, int seconds = 0);

    /**
     * @brief Gets the duration in seconds.
     * @return Total number of seconds.
     */
    int total_seconds() const;

    /**
     * @brief Adds two durations without changing either one.
     * @param other Duration to add.
     * @return A new duration containing the sum.
     */
    Duration operator+(const Duration& other) const;

    /**
     * @brief Compares two durations.
     * @param other Duration to compare.
     * @return True if both durations are equal.
     */
    bool operator==(const Duration& other) const;

private:
    int m_total_seconds;
};

/**
 * @brief Prints a duration as minutes:seconds.
 * @param out Output stream.
 * @param d Duration to print.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& out, const Duration& d);

#endif
