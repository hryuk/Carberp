/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleRole.idl
 */

#ifndef __gen_nsIAccessibleRole_h__
#define __gen_nsIAccessibleRole_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleRole */
#define NS_IACCESSIBLEROLE_IID_STR "8c0f68f8-164a-4078-a9ee-36a7d180f0e4"

#define NS_IACCESSIBLEROLE_IID \
  {0x8c0f68f8, 0x164a, 0x4078, \
    { 0xa9, 0xee, 0x36, 0xa7, 0xd1, 0x80, 0xf0, 0xe4 }}

/**
 * Defines cross platform (Gecko) roles.
 *
 * @note - When adding a new role, be sure to also add it to nsRoleMap.h for
 *         each platform.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleRole : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEROLE_IID)

  /**
   * Used when accessible hans't strong defined role.
   */
  enum { ROLE_NOTHING = 0U };

  /**
   * Represents a title or caption bar for a window. It is used by MSAA only,
   * supported automatically by MS Windows.
   */
  enum { ROLE_TITLEBAR = 1U };

  /**
   * Represents the menu bar (positioned beneath the title bar of a window)
   * from which menus are selected by the user. The role is used by
   * xul:menubar or role="menubar".
   */
  enum { ROLE_MENUBAR = 2U };

  /**
   * Represents a vertical or horizontal scroll bar, which is part of the client
   * area or used in a control.
   */
  enum { ROLE_SCROLLBAR = 3U };

  /**
   * Represents a special mouse pointer, which allows a user to manipulate user
   * interface elements such as windows. For example, a user clicks and drags
   * a sizing grip in the lower-right corner of a window to resize it.
   */
  enum { ROLE_GRIP = 4U };

  /**
   * Represents a system sound, which is associated with various system events.
   */
  enum { ROLE_SOUND = 5U };

  /**
   * Represents the system mouse pointer.
   */
  enum { ROLE_CURSOR = 6U };

  /**
   * Represents the system caret. The role is supported for caret.
   */
  enum { ROLE_CARET = 7U };

  /**
   * Represents an alert or a condition that a user should be notified about.
   * Assistive Technologies typically respond to the role by reading the entire
   * onscreen contents of containers advertising this role. Should be used for
   * warning dialogs, etc. The role is used by xul:browsermessage,
   * role="alert", xforms:message.
   */
  enum { ROLE_ALERT = 8U };

  /**
   * Represents the window frame, which contains child objects such as
   * a title bar, client, and other objects contained in a window. The role
   * is supported automatically by MS Windows.
   */
  enum { ROLE_WINDOW = 9U };

  /**
   * A sub-document (<frame> or <iframe>)
   */
  enum { ROLE_INTERNAL_FRAME = 10U };

  /**
   * Represents a menu, which presents a list of options from which the user can
   * make a selection to perform an action. It is used for role="menu".
   */
  enum { ROLE_MENUPOPUP = 11U };

  /**
   * Represents a menu item, which is an entry in a menu that a user can choose
   * to carry out a command, select an option. It is used for xul:menuitem,
   * role="menuitem".
   */
  enum { ROLE_MENUITEM = 12U };

  /**
   * Represents a ToolTip that provides helpful hints.
   */
  enum { ROLE_TOOLTIP = 13U };

  /**
   * Represents a main window for an application. It is used for
   * role="application". Also refer to ROLE_APP_ROOT
   */
  enum { ROLE_APPLICATION = 14U };

  /**
   * Represents a document window. A document window is always contained within
   * an application window. It is used for role="document".
   */
  enum { ROLE_DOCUMENT = 15U };

  /**
   * Represents a pane within a frame or document window. Users can navigate
   * between panes and within the contents of the current pane, but cannot
   * navigate between items in different panes. Thus, panes represent a level
   * of grouping lower than frame windows or documents, but above individual
   * controls. It is used for the first child of a <frame> or <iframe>.
   */
  enum { ROLE_PANE = 16U };

  /**
   * Represents a graphical image used to represent data.
   */
  enum { ROLE_CHART = 17U };

  /**
   * Represents a dialog box or message box. It is used for xul:dialog, 
   * role="dialog".
   */
  enum { ROLE_DIALOG = 18U };

  /**
   * Represents a window border.
   */
  enum { ROLE_BORDER = 19U };

  /**
   * Logically groups other objects. There is not always a parent-child
   * relationship between the grouping object and the objects it contains. It
   * is used for html:textfield, xul:groupbox, role="group".
   */
  enum { ROLE_GROUPING = 20U };

  /**
   * Used to visually divide a space into two regions, such as a separator menu
   * item or a bar that divides split panes within a window. It is used for
   * xul:separator, html:hr, role="separator".
   */
  enum { ROLE_SEPARATOR = 21U };

  /**
   * Represents a toolbar, which is a grouping of controls (push buttons or
   * toggle buttons) that provides easy access to frequently used features. It
   * is used for xul:toolbar, role="toolbar".
   */
  enum { ROLE_TOOLBAR = 22U };

  /**
   * Represents a status bar, which is an area at the bottom of a window that
   * displays information about the current operation, state of the application,
   * or selected object. The status bar has multiple fields, which display
   * different kinds of information. It is used for xul:statusbar.
   */
  enum { ROLE_STATUSBAR = 23U };

  /**
   * Represents a table that contains rows and columns of cells, and optionally,
   * row headers and column headers. It is used for html:table,
   * role="grid". Also refer to the following roles: ROLE_COLUMNHEADER,
   * ROLE_ROWHEADER, ROLE_COLUMN, ROLE_ROW, ROLE_CELL.
   */
  enum { ROLE_TABLE = 24U };

  /**
   * Represents a column header, providing a visual label for a column in
   * a table. It is used for XUL tree column headers, html:th,
   * role="colheader". Also refer to ROLE_TABLE.
   */
  enum { ROLE_COLUMNHEADER = 25U };

  /**
   * Represents a row header, which provides a visual label for a table row.
   * It is used for role="rowheader". Also, see ROLE_TABLE.
   */
  enum { ROLE_ROWHEADER = 26U };

  /**
   * Represents a column of cells within a table. Also, see ROLE_TABLE.
   */
  enum { ROLE_COLUMN = 27U };

  /**
   * Represents a row of cells within a table. Also, see ROLE_TABLE.
   */
  enum { ROLE_ROW = 28U };

  /**
   * Represents a cell within a table. Is is used for html:td,
   * role="gridcell". Also, see ROLE_TABLE.
   */
  enum { ROLE_CELL = 29U };

  /**
   * Represents a link to something else. This object might look like text or
   * a graphic, but it acts like a button. It is used for
   * xul:label@class="text-link", html:a, html:area,
   * xforms:trigger@appearance="minimal".
   */
  enum { ROLE_LINK = 30U };

  /**
   * Displays a Help topic in the form of a ToolTip or Help balloon.
   */
  enum { ROLE_HELPBALLOON = 31U };

  /**
   * Represents a cartoon-like graphic object, such as Microsoft Office
   * Assistant, which is displayed to provide help to users of an application.
   */
  enum { ROLE_CHARACTER = 32U };

  /**
   * Represents a list box, allowing the user to select one or more items. It
   * is used for xul:listbox, html:select@size, role="list". See also
   * ROLE_LIST_ITEM.
   */
  enum { ROLE_LIST = 33U };

  /**
   * Represents an item in a list. See also ROLE_LIST.
   */
  enum { ROLE_LISTITEM = 34U };

  /**
   * Represents an outline or tree structure, such as a tree view control,
   * that displays a hierarchical list and allows the user to expand and
   * collapse branches. Is is used for role="tree".
   */
  enum { ROLE_OUTLINE = 35U };

  /**
   * Represents an item in an outline or tree structure. It is used for
   * role="treeitem".
   */
  enum { ROLE_OUTLINEITEM = 36U };

  /**
   * Represents a page tab, it is a child of a page tab list. It is used for
   * xul:tab, role="treeitem". Also refer to ROLE_PAGETABLIST.
   */
  enum { ROLE_PAGETAB = 37U };

  /**
   * Represents a property sheet. It is used for xul:tabpanel,
   * role="tabpanel".
   */
  enum { ROLE_PROPERTYPAGE = 38U };

  /**
   * Represents an indicator, such as a pointer graphic, that points to the
   * current item.
   */
  enum { ROLE_INDICATOR = 39U };

  /**
   * Represents a picture. Is is used for xul:image, html:img.
   */
  enum { ROLE_GRAPHIC = 40U };

  /**
   * Represents read-only text, such as labels for other controls or
   * instructions in a dialog box. Static text cannot be modified or selected.
   * Is is used for xul:label, xul:description, html:label, role="label",
   * or xforms:output.
   */
  enum { ROLE_STATICTEXT = 41U };

  /**
   * Represents selectable text that allows edits or is designated read-only.
   */
  enum { ROLE_TEXT_LEAF = 42U };

  /**
   * Represents a push button control. It is used for xul:button, html:button,
   * role="button", xforms:trigger, xforms:submit.
   */
  enum { ROLE_PUSHBUTTON = 43U };

  /**
   * Represents a check box control. It is used for xul:checkbox,
   * html:input@type="checkbox", role="checkbox", boolean xforms:input.
   */
  enum { ROLE_CHECKBUTTON = 44U };

  /**
   * Represents an option button, also called a radio button. It is one of a
   * group of mutually exclusive options. All objects sharing a single parent
   * that have this attribute are assumed to be part of single mutually
   * exclusive group. It is used for xul:radio, html:input@type="radio",
   * role="radio".
   */
  enum { ROLE_RADIOBUTTON = 45U };

  /**
   * Represents a combo box; an edit control with an associated list box that
   * provides a set of predefined choices. It is used for html:select,
   * xul:menulist, role="combobox".
   */
  enum { ROLE_COMBOBOX = 46U };

  /**
   * Represents the calendar control. It is used for date xforms:input.
   */
  enum { ROLE_DROPLIST = 47U };

  /**
   * Represents a progress bar, dynamically showing the user the percent
   * complete of an operation in progress. It is used for xul:progressmeter,
   * role="progressbar".
   */
  enum { ROLE_PROGRESSBAR = 48U };

  /**
   * Represents a dial or knob whose purpose is to allow a user to set a value.
   */
  enum { ROLE_DIAL = 49U };

  /**
   * Represents a hot-key field that allows the user to enter a combination or
   * sequence of keystrokes.
   */
  enum { ROLE_HOTKEYFIELD = 50U };

  /**
   * Represents a slider, which allows the user to adjust a setting in given
   * increments between minimum and maximum values. It is used by xul:scale,
   * role="slider", xforms:range.
   */
  enum { ROLE_SLIDER = 51U };

  /**
   * Represents a spin box, which is a control that allows the user to increment
   * or decrement the value displayed in a separate "buddy" control associated
   * with the spin box. It is used for xul:spinbuttons.
   */
  enum { ROLE_SPINBUTTON = 52U };

  /**
   * Represents a graphical image used to diagram data. It is used for svg:svg.
   */
  enum { ROLE_DIAGRAM = 53U };

  /**
   * Represents an animation control, which contains content that changes over
   * time, such as a control that displays a series of bitmap frames.
   */
  enum { ROLE_ANIMATION = 54U };

  /**
   * Represents a mathematical equation. It is used by MATHML, where there is a
   * rich DOM subtree for an equation. Use ROLE_FLAT_EQUATION for <img role="math" alt="[TeX]"/>
   */
  enum { ROLE_EQUATION = 55U };

  /**
   * Represents a button that drops down a list of items.
   */
  enum { ROLE_BUTTONDROPDOWN = 56U };

  /**
   * Represents a button that drops down a menu.
   */
  enum { ROLE_BUTTONMENU = 57U };

  /**
   * Represents a button that drops down a grid. It is used for xul:colorpicker.
   */
  enum { ROLE_BUTTONDROPDOWNGRID = 58U };

  /**
   * Represents blank space between other objects.
   */
  enum { ROLE_WHITESPACE = 59U };

  /**
   * Represents a container of page tab controls. Is it used for xul:tabs,
   * DHTML: role="tabs". Also refer to ROLE_PAGETAB.
   */
  enum { ROLE_PAGETABLIST = 60U };

  /**
   * Represents a control that displays time.
   */
  enum { ROLE_CLOCK = 61U };

  /**
   * Represents a button on a toolbar that has a drop-down list icon directly
   * adjacent to the button.
   */
  enum { ROLE_SPLITBUTTON = 62U };

  /**
   * Represents an edit control designed for an Internet Protocol (IP) address.
   * The edit control is divided into sections for the different parts of the
   * IP address.
   */
  enum { ROLE_IPADDRESS = 63U };

  /**
   * Represents a label control that has an accelerator.
   */
  enum { ROLE_ACCEL_LABEL = 64U };

  /**
   * Represents an arrow in one of the four cardinal directions.
   */
  enum { ROLE_ARROW = 65U };

  /**
   * Represents a control that can be drawn into and is used to trap events.
   * It is used for html:canvas.
   */
  enum { ROLE_CANVAS = 66U };

  /**
   * Represents a menu item with a check box.
   */
  enum { ROLE_CHECK_MENU_ITEM = 67U };

  /**
   * Represents a specialized dialog that lets the user choose a color.
   */
  enum { ROLE_COLOR_CHOOSER = 68U };

  /**
   * Represents control whose purpose is to allow a user to edit a date.
   */
  enum { ROLE_DATE_EDITOR = 69U };

  /**
   * An iconified internal frame in an ROLE_DESKTOP_PANE. Also refer to
   * ROLE_INTERNAL_FRAME.
   */
  enum { ROLE_DESKTOP_ICON = 70U };

  /**
   * A desktop pane. A pane that supports internal frames and iconified
   * versions of those internal frames.
   */
  enum { ROLE_DESKTOP_FRAME = 71U };

  /**
   * A directory pane. A pane that allows the user to navigate through
   * and select the contents of a directory. May be used by a file chooser.
   * Also refer to ROLE_FILE_CHOOSER.
   */
  enum { ROLE_DIRECTORY_PANE = 72U };

  /**
   * A file chooser. A specialized dialog that displays the files in the
   * directory and lets the user select a file, browse a different directory,
   * or specify a filename. May use the directory pane to show the contents of
   * a directory. Also refer to ROLE_DIRECTORY_PANE.
   */
  enum { ROLE_FILE_CHOOSER = 73U };

  /**
   * A font chooser. A font chooser is a component that lets the user pick
   * various attributes for fonts.
   */
  enum { ROLE_FONT_CHOOSER = 74U };

  /**
   * Frame role. A top level window with a title bar, border, menu bar, etc.
   * It is often used as the primary window for an application.
   */
  enum { ROLE_CHROME_WINDOW = 75U };

  /**
   *  A glass pane. A pane that is guaranteed to be painted on top of all
   * panes beneath it. Also refer to ROLE_ROOT_PANE.
   */
  enum { ROLE_GLASS_PANE = 76U };

  /**
   * A document container for HTML, whose children represent the document
   * content.
   */
  enum { ROLE_HTML_CONTAINER = 77U };

  /**
   * A small fixed size picture, typically used to decorate components.
   */
  enum { ROLE_ICON = 78U };

  /**
   * Presents an icon or short string in an interface.
   */
  enum { ROLE_LABEL = 79U };

  /**
   * A layered pane. A specialized pane that allows its children to be drawn
   * in layers, providing a form of stacking order. This is usually the pane
   * that holds the menu bar as  well as the pane that contains most of the
   * visual components in a window. Also refer to ROLE_GLASS_PANE and
   * ROLE_ROOT_PANE.
   */
  enum { ROLE_LAYERED_PANE = 80U };

  /**
   * A specialized pane whose primary use is inside a dialog.
   */
  enum { ROLE_OPTION_PANE = 81U };

  /**
   * A text object uses for passwords, or other places where the text content
   * is not shown visibly to the user.
   */
  enum { ROLE_PASSWORD_TEXT = 82U };

  /**
   * A temporary window that is usually used to offer the user a list of
   * choices, and then hides when the user selects one of those choices.
   */
  enum { ROLE_POPUP_MENU = 83U };

  /**
   * A radio button that is a menu item.
   */
  enum { ROLE_RADIO_MENU_ITEM = 84U };

  /**
   * A root pane. A specialized pane that has a glass pane and a layered pane
   * as its children. Also refer to ROLE_GLASS_PANE and ROLE_LAYERED_PANE.
   */
  enum { ROLE_ROOT_PANE = 85U };

  /**
   * A scroll pane. An object that allows a user to incrementally view a large
   * amount of information.  Its children can include scroll bars and a
   * viewport. Also refer to ROLE_VIEW_PORT.
   */
  enum { ROLE_SCROLL_PANE = 86U };

  /**
   * A split pane. A specialized panel that presents two other panels at the
   * same time. Between the two panels is a divider the user can manipulate to
   * make one panel larger and the other panel smaller.
   */
  enum { ROLE_SPLIT_PANE = 87U };

  /**
   * The header for a column of a table.
   * XXX: it looks this role is dupe of ROLE_COLUMNHEADER.
   */
  enum { ROLE_TABLE_COLUMN_HEADER = 88U };

  /**
   * The header for a row of a table.
   * XXX: it looks this role is dupe of ROLE_ROWHEADER
   */
  enum { ROLE_TABLE_ROW_HEADER = 89U };

  /**
   * A menu item used to tear off and reattach its menu.
   */
  enum { ROLE_TEAR_OFF_MENU_ITEM = 90U };

  /**
   * Represents an accessible terminal.
   */
  enum { ROLE_TERMINAL = 91U };

  /**
   * Collection of objects that constitute a logical text entity.
   */
  enum { ROLE_TEXT_CONTAINER = 92U };

  /**
   * A toggle button. A specialized push button that can be checked or
   * unchecked, but does not provide a separate indicator for the current state.
   */
  enum { ROLE_TOGGLE_BUTTON = 93U };

  /**
   * Representas a control that is capable of expanding and collapsing rows as
   * well as showing multiple columns of data.
   * XXX: it looks like this role is dupe of ROLE_OUTLINE.
   */
  enum { ROLE_TREE_TABLE = 94U };

  /**
   * A viewport. An object usually used in a scroll pane. It represents the
   * portion of the entire data that the user can see. As the user manipulates
   * the scroll bars, the contents of the viewport can change. Also refer to
   * ROLE_SCROLL_PANE.
   */
  enum { ROLE_VIEWPORT = 95U };

  /**
   * Header of a document page. Also refer to ROLE_FOOTER.
   */
  enum { ROLE_HEADER = 96U };

  /**
   * Footer of a document page. Also refer to ROLE_HEADER.
   */
  enum { ROLE_FOOTER = 97U };

  /**
   * A paragraph of text.
   */
  enum { ROLE_PARAGRAPH = 98U };

  /**
   * A ruler such as those used in word processors.
   */
  enum { ROLE_RULER = 99U };

  /**
   * A text entry having dialog or list containing items for insertion into
   * an entry widget, for instance a list of words for completion of a
   * text entry. It is used for xul:textbox@autocomplete
   */
  enum { ROLE_AUTOCOMPLETE = 100U };

  /**
   *  An editable text object in a toolbar.
   */
  enum { ROLE_EDITBAR = 101U };

  /**
   * An control whose textual content may be entered or modified by the user.
   */
  enum { ROLE_ENTRY = 102U };

  /**
   * A caption describing another object.
   */
  enum { ROLE_CAPTION = 103U };

  /**
   * A visual frame or container which contains a view of document content.
   * Document frames may occur within another Document instance, in which case
   * the second document may be said to be embedded in the containing instance.
   * HTML frames are often ROLE_DOCUMENT_FRAME. Either this object, or a
   * singleton descendant, should implement the Document interface.
   */
  enum { ROLE_DOCUMENT_FRAME = 104U };

  /**
   * Heading.
   */
  enum { ROLE_HEADING = 105U };

  /**
   * An object representing a page of document content.  It is used in documents
   * which are accessed by the user on a page by page basis.
   */
  enum { ROLE_PAGE = 106U };

  /**
   * A container of document content.  An example of the use of this role is to
   * represent an html:div.
   */
  enum { ROLE_SECTION = 107U };

  /**
   * An object which is redundant with another object in the accessible
   * hierarchy. ATs typically ignore objects with this role.
   */
  enum { ROLE_REDUNDANT_OBJECT = 108U };

  /**
   * A container of form controls. An example of the use of this role is to
   * represent an html:form.
   */
  enum { ROLE_FORM = 109U };

  /**
   * An object which is used to allow input of characters not found on a
   * keyboard, such as the input of Chinese characters on a Western keyboard.
   */
  enum { ROLE_IME = 110U };

  /**
   * XXX: document this.
   */
  enum { ROLE_APP_ROOT = 111U };

  /**
   * Represents a menu item, which is an entry in a menu that a user can choose
   * to display another menu.
   */
  enum { ROLE_PARENT_MENUITEM = 112U };

  /**
   * A calendar that allows the user to select a date.
   */
  enum { ROLE_CALENDAR = 113U };

  /**
   * A list of items that is shown by combobox.
   */
  enum { ROLE_COMBOBOX_LIST = 114U };

  /**
   * A item of list that is shown by combobox;
   */
  enum { ROLE_COMBOBOX_OPTION = 115U };

  /**
   * An image map -- has child links representing the areas
   */
  enum { ROLE_IMAGE_MAP = 116U };

  /**
   * An option in a listbox
   */
  enum { ROLE_OPTION = 117U };

  /**
   * A rich option in a listbox, it can have other widgets as children
   */
  enum { ROLE_RICH_OPTION = 118U };

  /**
   * A list of options
   */
  enum { ROLE_LISTBOX = 119U };

  /**
   * Represents a mathematical equation in the accessible name
   */
  enum { ROLE_FLAT_EQUATION = 120U };

  /**
   * It's not role actually. This contanst is important to help ensure
   * nsRoleMap's are synchronized.
   */
  enum { ROLE_LAST_ENTRY = 121U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleRole, NS_IACCESSIBLEROLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEROLE \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEROLE(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEROLE(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleRole : public nsIAccessibleRole
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEROLE

  nsAccessibleRole();

private:
  ~nsAccessibleRole();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleRole, nsIAccessibleRole)

nsAccessibleRole::nsAccessibleRole()
{
  /* member initializers and constructor code */
}

nsAccessibleRole::~nsAccessibleRole()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleRole_h__ */
