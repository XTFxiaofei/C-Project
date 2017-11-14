// Persist.h

#ifndef _INSIDE_VISUAL_CPP_PERSISTENT_FRAME
#define _INSIDE_VISUAL_CPP_PERSISTENT_FRAME

#include "./CustomTabCtrl/TabSDIFrameWnd.h"

class CPersistentFrame : public CTabSDIFrameWnd
{ // remembers where it was on the desktop
    DECLARE_DYNAMIC(CPersistentFrame)
public:
	void DockControlBarLeftOf(CControlBar* Bar, CControlBar* ObjRef);
	void DockControlBarRigthOf(CControlBar* Bar, CControlBar* ObjRef);
	void DockControlBarTopOf(CControlBar* Bar, CControlBar* ObjRef);
	void DockControlBarBottomOf(CControlBar* Bar, CControlBar* ObjRef);

private:
    static const CRect s_rectDefault;
    static const char s_profileHeading[];
    static const char s_profileRect[];
    static const char s_profileIcon[];
    static const char s_profileMax[];
    static const char s_profileTool[];
    static const char s_profileStatus[];
    BOOL m_bFirstTime;
protected: // Create from serialization only
    CPersistentFrame();
    ~CPersistentFrame();
//{{AFX_VIRTUAL(CPersistentFrame)
    public:
    virtual void ActivateFrame(int nCmdShow = -1);
    protected:
    //}}AFX_VIRTUAL

    //{{AFX_MSG(CPersistentFrame)
    afx_msg void OnDestroy();
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};

#endif // _INSIDE_VISUAL_CPP_PERSISTENT_FRAME