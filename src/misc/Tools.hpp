//
// Created by robin on 11.08.17.
//

#ifndef PIXELMOUND_TOOLS_H
#define PIXELMOUND_TOOLS_H

#include "../../EmuJukeboxConfig.h"

#include <sstream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdarg>
#include <cctype>
#include <initializer_list>

#include <fmt/core.h>
#include <fmt/printf.h>
#include <regex>

#if MSVC
    #include <filesystem>
    #include <SFML/Graphics.hpp>
#elif APPLE
    #include <experimental/filesystem>
    #include <SFML/Graphics.hpp>
#else
    #include <filesystem>
    #include <SFML/Graphics.hpp>
#endif

namespace ebox::tools
{
    namespace string
    {
        namespace helper
        {
            //HELPER FUNCTION FOR SplitString
            template<typename Out>
            static void split(const std::string &s, char delim, Out result)
            {
                std::stringstream ss;
                ss.str(s);
                std::string item;

                while (std::getline(ss, item, delim))
                {
                    *(result++) = item;
                }
            }
        }

        static void StringReplace(std::string *str, const std::string &toReplace, const std::string &replaceWith)
        {
            //*str = std::regex_replace(*str, std::regex("\\" + toReplace), "\\" + replaceWith);
            *str = std::regex_replace(*str, std::regex(toReplace), replaceWith);
        }

        static bool StringContains(const std::string &str, const std::string &text)
        {
            size_t find = str.find(text);
            return (find != std::string::npos) ? true : false;
        }

        static std::vector<std::string> SplitString(const std::string &s, char delim)
        {
            std::vector<std::string> elems;
            helper::split(s, delim, std::back_inserter(elems));
            return elems;
        }
    }

    namespace fs
    {
        static bool IsDirectory(const std::filesystem::directory_entry &entry)
        {
            return std::filesystem::is_directory(entry);
        }

        static std::string GetPath(const std::filesystem::directory_entry &entry)
        {
            return entry.path().string();
        }
    }

    namespace vector
    {
        /*!
         * Checks if the first vector is equal to the second
         * @param first Main vector
         * @param second Second vector
         * @return Are the vectors equal?
         */
        static bool IsEqual(const sf::Vector2f &first, const sf::Vector2f &second)
        {
            return (first.x == second.x && first.y == second.y) ? true : false;
        }

        //Checks
        static bool IsSmallerThan(const sf::Vector2f &first, const sf::Vector2f &second)
        {
            return (first.x == second.x && first.y == second.y) ? true : false;
        }


    }

}

#endif //PIXELMOUND_TOOLS_H
