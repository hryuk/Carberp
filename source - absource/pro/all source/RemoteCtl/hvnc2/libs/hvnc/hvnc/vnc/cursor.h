#ifndef CURSOR_H_INCLUDED
#define CURSOR_H_INCLUDED

typedef struct cursor_info {
	char *data;	/* data and mask pointers */
	char *mask;
	int wx, wy;	/* size of cursor */
	int sx, sy;	/* shift to its centering point */
	rfbCursorPtr rfb;
} *pcursor_info_t,cursor_info_t;

void SetXCursor(rfbScreenInfoPtr rfbScreen,pcursor_info_t lpCursor);

extern cursor_info_t cur_arrow,cur_root,cur_fleur,cur_xterm;

extern HCURSOR hArrow;
extern ICONINFO iiCur;

#endif