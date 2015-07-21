/**
 * @file  Utility.cpp
 * @brief Utility
 *
 * Class implementation for Utility
 *
 * @author     Clay Freeman
 * @date       March 20, 2015
 */

#include <algorithm>
#include <functional>
#include <string>
#include <utility>
#include <vector>
#include "Utility.hpp"

/**
 * @brief Explode
 *
 * Explodes a std::string by a delimiter to a std::vector of std::string
 *
 * @param s The std::string to explode
 * @param d The delimiter to explode the std::string
 *
 * @return std::vector of std::string
 */
std::vector<std::string> Utility::explode(const std::string& s,
    const std::string& d) {
  std::size_t lpos = 0;
  std::vector<std::string> result;

  for (std::size_t cpos = 0; (cpos = s.find(d, lpos)) != std::string::npos;
      lpos = cpos + d.length())
    // Add each item separated by a delimiter
    result.push_back(s.substr(lpos, cpos - lpos));
  // Add the last substr with no delimiter
  result.push_back(s.substr(lpos));

  return result;
}

/**
 * @brief Implode
 *
 * Implodes a std::vector of std::string by a delimiter to a std::string
 *
 * @param v The std::vector of std::string to implode
 * @param d The delimiter to implode the std::vector of std::string
 *
 * @return std::string
 */
std::string Utility::implode(const std::vector<std::string>& v,
    const std::string& d) {
  std::string result;
  for (const std::string& s : v) {
    if (result.length() > 0)
      result += d;
    result += s;
  }
  return result;
}

/**
 * @brief Left Trim
 *
 * Trims whitespace from the left end of the provided std::string
 *
 * @param[out] s The std::string to trim
 *
 * @return The modified std::string&
 */
std::string& Utility::ltrim(std::string& s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(),
    std::ptr_fun<int, int>(std::isgraph)));
  return s;
}

/**
 * @brief Repeat
 *
 * Repeats a given std::string n times
 *
 * @param s The std::string to repeat
 * @param n Number of times to repeat
 *
 * @return The resulting std::string
 */
std::string Utility::repeat(const std::string& s, int n) {
  std::string result;
  for (int i = 0; i < n; i++)
    result += s;
  return result;
}

/**
 * @brief Right Trim
 *
 * Trims whitespace from the right end of the provided std::string
 *
 * @param[out] s The std::string to trim
 *
 * @return The modified std::string&
 */
std::string& Utility::rtrim(std::string& s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
    std::ptr_fun<int, int>(std::isgraph)).base(), s.end());
  return s;
}

/**
 * @brief String to Lower
 *
 * Transforms a copy of the provided std::string to lower-case
 *
 * @param s The string to transform to lower-case
 *
 * @return A lower-case transformation of the provided std::string
 */
std::string Utility::strtolower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

/**
 * @brief Trim
 *
 * Trims whitespace from both ends of the provided std::string
 *
 * @param[out] s The std::string to trim
 *
 * @return The modified std::string&
 */
std::string& Utility::trim(std::string& s) {
  return Utility::ltrim(Utility::rtrim(s));
}
