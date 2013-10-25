#ifdef E_TYPEDEFS

typedef struct _E_Event_Desklock E_Event_Desklock;
typedef Eina_Bool (*E_Desklock_Show_Cb)(void);
typedef void (*E_Desklock_Hide_Cb)(void);

typedef enum _E_Desklock_Background_Method {
    E_DESKLOCK_BACKGROUND_METHOD_THEME_DESKLOCK = 0,
    E_DESKLOCK_BACKGROUND_METHOD_THEME,
    E_DESKLOCK_BACKGROUND_METHOD_WALLPAPER,
    E_DESKLOCK_BACKGROUND_METHOD_CUSTOM,
} E_Desklock_Background_Method;
#else
#ifndef E_DESKLOCK_H
#define E_DESKLOCK_H

struct _E_Event_Desklock
{
   int on;
   int suspend;
};

EINTERN int e_desklock_init(void);
EINTERN int e_desklock_shutdown(void);

EAPI int e_desklock_show(Eina_Bool suspend);
EAPI int e_desklock_show_autolocked(void);
EAPI void e_desklock_hide(void);
EAPI Eina_Bool e_desklock_state_get(void);

EAPI void e_desklock_show_hook_add(E_Desklock_Show_Cb cb);
EAPI void e_desklock_show_hook_del(E_Desklock_Show_Cb cb);
EAPI void e_desklock_hide_hook_add(E_Desklock_Hide_Cb cb);
EAPI void e_desklock_hide_hook_del(E_Desklock_Hide_Cb cb);

extern EAPI int E_EVENT_DESKLOCK;

#endif
#endif
