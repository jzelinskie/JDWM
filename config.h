/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[] = "Sans 10";
static const char normbordercolor[] = "#242424";
static const char normbgcolor[]     = "#0d0d0d";
static const char normfgcolor[]     = "#ffffff";
static const char selbordercolor[]  = "#242424";
static const char selbgcolor[]      = "#0d0d0d";
static const char selfgcolor[]      = "#c5f779";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 2;
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {

	/*  $ xprop | GREP WM_CLASS  */
	/* class                               instance      title       tags mask     isfloating   monitor */

        { "MPlayer",	        	   NULL,       NULL,       0,                 True,        -1 },
	{ "Firefox",                       NULL,       NULL,       1 << 1,            False,       -1 },
        { "Mumble",                        NULL,       NULL,       1 << 2,            True,        -1 },
        { "Xchat",                         NULL,       NULL,       1 << 2,            True,        -1 },
        { "Sonata",                        NULL,       NULL,       1 << 3,            True,        -1 },
        { "Deluge",                        NULL,       NULL,       1 << 4,            False,       -1 },
        { "Filezilla",                     NULL,       NULL,	   1 << 4,            False,       -1 },
        { "LibreOffice",                   NULL,       NULL,       1 << 6,            False,       -1 },

};

/* layout(s) */
static const float mfact      = 0.50; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */
static const Layout layouts[] = {

        /* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "[B]",      bstack },
	{ "[H]",      bstackhoriz },
	{ "[S]",      spiral },
	{ "[D]",      dwindle },

};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/zsh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[]  = { "dmenu_run", "-fn", "-*-proggytinyttsz-*-*-*-*-16-*-*-*-*-*-*-*", "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]   = { "urxvt", NULL };
static const char *runcmd[]    = { "gmrun", NULL };
static const char *volupcmd[]  = { "mpc", "volume", "+1", NULL };
static const char *voldncmd[]  = { "mpc", "volume", "-1", NULL };
static const char *mpcnext[]   = { "mpc", "next", NULL };
static const char *mpcprev[]   = { "mpc", "prev", NULL };
static const char *mpcplay[]   = { "mpc", "play", NULL };
static const char *mpcpause[]  = { "mpc", "pause", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_a,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_s,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_q,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_e,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[6]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
        { MODKEY|ShiftMask,             XK_p,      spawn,          {.v = runcmd } },
        { MODKEY,                       XK_Left,   cycle,          {.i = -1 } },
        { MODKEY,                       XK_Right,  cycle,          {.i = +1 } },
	{ MODKEY, 	                XK_Up,     spawn,          {.v = volupcmd } },
	{ MODKEY,	                XK_Down,   spawn,	   {.v = voldncmd } },
        { MODKEY|ControlMask,           XK_Up,     spawn,          {.v = mpcplay } },
        { MODKEY|ControlMask,           XK_Down,   spawn,          {.v = mpcpause } },
	{ MODKEY|ControlMask,           XK_Right,  spawn,          {.v = mpcnext } },
	{ MODKEY|ControlMask,	        XK_Left,   spawn,	   {.v = mpcprev } },
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
