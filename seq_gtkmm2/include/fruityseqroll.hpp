#ifndef SEQ64_FRUITYSEQROLL_HPP
#define SEQ64_FRUITYSEQROLL_HPP

/*
 *  This file is part of seq24/sequencer64.
 *
 *  seq24 is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  seq24 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with seq24; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/**
 * \file          fruityseqroll.hpp
 *
 *  This module declares/defines the base class for seqroll interactions
 *  using the "fruity" mouse paradigm.
 *
 * \library       sequencer64 application
 * \author        Seq24 team; modifications by Chris Ahlstrom
 * \date          2015-07-24
 * \updates       2016-07-03
 * \license       GNU GPLv2 or above
 *
 */

/*
 *  Do not document a namespace; it breaks Doxygen.
 */

namespace seq64
{
    class seqroll;

/**
 *  Implements the fruity mouse interaction paradigm for the seqroll.
 */

class FruitySeqRollInput
{

private:

    /**
     *  Set to tru if we hold the right mouse button down (in "fruity" mode)
     *  and start to drag the mouse around, erasing notes.
     */

    bool m_erase_painting;

    /**
     *  Holds the original position of the mouse when ctrl-left-click-drag is
     *  done, and is used to make sure that the action doesn't occur until a
     *  movement of at least 6 pixels has occurred, to avoid unintended
     *  actions caused by minimal jitter in the user's hands.
     */

    int m_drag_paste_start_pos[2];

public:

    /**
     * Default constructor.
     */

    FruitySeqRollInput () : m_erase_painting(false)
    {
        // Empty body
    }

    void update_mouse_pointer (seqroll & ths);

public:         // callbacks

    bool on_button_press_event (GdkEventButton * ev, seqroll & ths);
    bool on_button_release_event (GdkEventButton * ev, seqroll & ths);
    bool on_motion_notify_event (GdkEventMotion * ev, seqroll & ths);

};          // FruitySeqRollInput

}           // namespace seq64

#endif      // SEQ64_FRUITYSEQROLL_HPP

/*
 * fruityseqroll.hpp
 *
 * vim: sw=4 ts=4 wm=4 et ft=cpp
 */

