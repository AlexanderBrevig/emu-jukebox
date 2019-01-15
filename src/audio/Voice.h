//
// Created by robin on 10.01.19.
//

#ifndef EMU_JUKEBOX_VOICE_H
#define EMU_JUKEBOX_VOICE_H

#include <iostream>
#include <libgme/Music_Emu.h>
#include "../gui/controls/Checkbox.h"

namespace ebox
{
    class Voice
    {
        public:
            Voice();
            Voice(Music_Emu *emu, int channelNo, const std::string &channelName, bool isMuted);

            void showCheckbox();
            void toggleMute();

            void setEmu(Music_Emu *emu);
            void setChannelNo(int channelNo);
            void setChannelName(const std::string &channelName);
            void setMuted(bool isMuted);

            Music_Emu *getEmu() const;
            int getChannelNo() const;
            const std::string &getChannelName() const;
            bool isMuted() const;
            bool *getMuted();

        private:
            ebox::Checkbox m_checkbox;
            int m_channelNo = 0;
            std::string m_channelName = "";
            bool m_isMuted = false;

            Music_Emu *m_emu = nullptr;
    };
}

#endif //EMU_JUKEBOX_VOICE_H
