#pragma once

#include <string>

template<typename T>
struct is_arithmetic_type {
    static constexpr bool value = std::is_arithmetic<T>::value;
};


template <typename T, typename Total, size_t N, bool = is_arithmetic_type<T>::value>
class Moving_Average {
    
    // Must be an integer, float, double ...etc. 
    // (fixed integer types: uint8_t, uint16_t are allowed)
    static_assert(is_arithmetic_type<T>::value, "T must be an arithmetic type");


    Moving_Average& addSample(T inputSample) {
        
        // add input to the total
        total_ += inputSample;

        // overwrite the next sample index with the input
        if (num_samples_ < N) {
            samples_[num_samples_++] = inputSample;
        }
        else {
            T& oldest = samples_[num_samples_++ % N];
            total_ -= oldest;
            oldest = inputSample;
        }
        return *this;
    }

    // Overload the function call operator to use the class like a function
    Moving_Average& operator()(T sample) {
        return addSample(sample);
    }

    // Get the current average
    double getAverage() const {
        if (num_samples_ == 0) throw std::runtime_error("No samples to calculate average.");
        return static_cast<double>(total_) / std::min(num_samples_, N);
    }

    // Cast operator to get the current average (for backward compatibility)
    operator double() const {
        return getAverage();
    }

    // Get the most recent sample added
    T lastSample() const {
        if (num_samples_ == 0) throw std::runtime_error("MovingAverage :: lastSample() { No samples yet. } ");
        return samples_[(num_samples_ - 1) % N];
    }

    // Get all samples in the buffer
    std::array<T, N> getSamples() const {
        return samples_;
    }

    // Reset the moving average to its initial state
    void reset() {
        num_samples_ = 0;
        total_ = Total{ 0 };
        std::fill(std::begin(samples_), std::end(samples_), T{ 0 });
    }
private:
    std::array<T, N> samples_{}; // Array to store the last N samples
    size_t num_samples_{ 0 };      // The number of samples added
    Total total_{ 0 };             // The total sum of the last N samples
};

/* 
 * 
 *  _______________________________________________________________________________________________
 * 
 *                                          Helper section
 * 
 *              This section helps with ease of use for the Moving_Average class template
 * 
 */

// Define default types and sizes
using DefaultTotalType = double;
constexpr size_t DefaultSize = 30;

// Define a cleaner interface using 'using' to make it easier to use
template <typename T>
using DefaultMovingAverage = Moving_Average<T, DefaultTotalType, DefaultSize>;
