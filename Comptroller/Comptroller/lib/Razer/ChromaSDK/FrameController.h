#ifndef _FRAMECONTROLLER_H_
#define _FRAMECONTROLLER_H_

#pragma once

#include <Windows.h>

class CFrameController
{
public:
    CFrameController();
    CFrameController(LONG FramePerSec);
    ~CFrameController();

    void Begin();
    void End();
    void SetRate(LONG FramePerSec);
    LONG GetRate();

private:
    LONG m_FramesPerSec;
    DOUBLE m_OneFrame;
};

#endif
