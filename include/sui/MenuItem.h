// 华勤科技版权所有 2010-2011
// 
// 文件名：MenuItem.h
// 功  能：实现标准的MenuItem控件
// 
// 作  者：汪荣
// 时  间：2010-08-31
// 
// ============================================================================

# ifndef _UIMENUITEM_H_
# define _UIMENUITEM_H_

#include <sui/sharpuiconfig.h>
#include <sui/ItemContainer.h>
#include <suicore/uipopup.h>
#include <suicore/drawing/uidrawing.h>

namespace ui
{

// ============================================================================
// MenuItem，实现标准的菜单项。
// ============================================================================

class MenuItem;
typedef suic::shared<MenuItem> MenuItemPtr;

typedef delegate<void(suic::ObjectPtr, MenuItemPtr)> MenuItemClickEventHandler;

enum MenuItemRole
{ 
    TopLevelItem,
    TopLevelHeader, 
    SubmenuItem, 
    SubmenuHeader,
};

class SHARPUI_API MenuItem : public suic::ContentControl
{
public:

    suic::RoutedEventHandler SubmenuOpenedEvent;
    suic::RoutedEventHandler SubmenuClosedEvent;

    MenuItemClickEventHandler MenuItemClick;

    MenuItem();
    virtual ~MenuItem();

    DECLAREBUILD(MenuItem)

    bool IsSubmenuOpen() const;
    bool IsSubmenu() const;

    void SetIcon(suic::ImagePtr icon);
    suic::ImagePtr GetIcon() const;

public:

    virtual void OnClick(suic::ObjectPtr menu, bool bIsMain);

    virtual void OnPopupClosed(suic::ObjectPtr source, suic::EventArg& e);
    virtual void OnSubmenuOpened(suic::RoutedEventArg& e);

    virtual void OnChecked(suic::RoutedEventArg& e);
    virtual void OnUnchecked(suic::RoutedEventArg& e);

protected:

    suic::ElementPtr FindName(const suic::String& strName);

    int AddChild(suic::ObjectPtr child);

    suic::Size MeasureOverride(const suic::Size& size);

    void OnInitialized();
    void OnStyleUpdated();

    void OnRender(suic::DrawingContext * drawing);

    void OnTextInput(suic::KeyEventArg& e);
    void OnKeyDown(suic::KeyEventArg& e);

    void OnGotFocus(suic::FocusEventArg& e);
    void OnLostFocus(suic::FocusEventArg& e);
    void OnSetCursor(suic::CursorEventArg& e);

    void OnMouseEnter(suic::MouseEventArg& e);
    void OnMouseMove(suic::MouseEventArg& e);
    void OnMouseLeave(suic::MouseEventArg& e);
    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);

protected:

    suic::PopupPtr _submenuPopup;
    MenuItemPtr _currentSelection;
    suic::ImagePtr _icon;

    friend class Menu;
};

};

# endif
