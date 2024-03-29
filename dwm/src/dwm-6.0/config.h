/* See LICENSE file for copyright and license details. */

/* appearance */

static const char font[]            = "Ubuntu:pixelsize=10" ;
static const char normbordercolor[] = "#000000";	/*black*/
static const char normbgcolor[]     = "#000000";	/*black*/
static const char normfgcolor[]     = "#999999";	
static const char selbordercolor[]  = "#000000";	/*black*/
static const char selbgcolor[]      = "#000000";	/*black*/
static const char selfgcolor[]      = "#1E90FF";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */


static const char *tags[] = {"WEB","TERM","CODE","DOC","FM","MUSIC","IMG","CALC","IX"};

/*	web=chromium
 * 	term=rxvt-unicode
 * 	code=geany
 * 	doc=libreoffice
 * 	fm=pcmanfm
 * 	music=deadbeef
 * 	img=gimp
 * 	calc=galculator
 * 	IX=misc	*/


static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Chromium",		NULL,       NULL,       1<<0,       False,       -1 },
	{ "URxvt",   		NULL,       NULL,       1<<1,       False,       -1 },
	{ "Geany",			NULL,       NULL,       1<<2,       False,       -1 },
	{ "Codeblocks",		NULL,       NULL,       1<<2,       False,       -1 },
	{ "Leafpad",   	  	NULL,       NULL,       1<<3,       False,       -1 },
	{ "libreoffice",	NULL,       NULL,       1<<3,       False,       -1 },
	{ "Pcmanfm",	  	NULL,       NULL,       1<<4,       False,       -1 },
	{ "Deadbeef",     	NULL,       NULL,       1<<5,       False,       -1 },
	{ "Gimp",	      	NULL,       NULL,       1<<6,       False,       -1 },
	{ "Galculator",	    NULL,       NULL,       1<<7,       False,       -1 },

};

/* layout(s) */
static const float mfact      = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[M]",      monocle },
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *wwwcmd[] = {"chromium", NULL};
static const char *termcmd[]  = { "urxvt", NULL };
static const char *codecmd[] = {"geany", NULL};
static const char *doccmd[] = {"libreoffice", NULL};
static const char *fmcmd[] = {"pcmanfm", NULL};
static const char *musiccmd[] = {"deadbeef", NULL};
static const char *imgcmd[] = {"gimp", NULL};
static const char *calccmd[] = {"galculator", NULL};
static const char *lockcmd[] = {"slock", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                   XK_p,      spawn,          {.v = dmenucmd } },
	{ ControlMask,				XK_1,	   spawn,	   	   {.v = wwwcmd } },
	{ ControlMask,			    XK_2, 	   spawn,          {.v = termcmd } },
	{ ControlMask,			    XK_3, 	   spawn,          {.v = codecmd } },
	{ ControlMask,			    XK_4, 	   spawn,          {.v = doccmd } },
	{ ControlMask,			    XK_5, 	   spawn,          {.v = fmcmd } },
	{ ControlMask,			    XK_6, 	   spawn,          {.v = musiccmd } },
	{ ControlMask,			    XK_7, 	   spawn,          {.v = imgcmd } },
	{ ControlMask,			    XK_8, 	   spawn,          {.v = calccmd } },
	{ ControlMask,			    XK_l, 	   spawn,          {.v = lockcmd } },
	{ MODKEY,                   XK_b,      togglebar,      {0} },
	{ MODKEY,                   XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                   XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                   XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                   XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                   XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                   XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                   XK_Return, zoom,           {0} },
	{ MODKEY,                   XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,         XK_c,      killclient,     {0} },
	{ MODKEY,                   XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                   XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                   XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                   XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,         XK_space,  togglefloating, {0} },
	{ MODKEY,                   XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,         XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                   XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                   XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,         XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,         XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                    XK_1,                      0)
	TAGKEYS(                    XK_2,                      1)
	TAGKEYS(                    XK_3,                      2)
	TAGKEYS(                    XK_4,                      3)
	TAGKEYS(                    XK_5,                      4)
	TAGKEYS(                    XK_6,                      5)
	TAGKEYS(                    XK_7,                      6)
	TAGKEYS(                    XK_8,                      7)
	TAGKEYS(                    XK_9,                      8)
	{ MODKEY|ShiftMask,         XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

