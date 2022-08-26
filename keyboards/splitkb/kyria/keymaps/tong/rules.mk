OLED_ENABLE = yes
ENCODER_ENABLE = yes
LEADER_ENABLE = yes
WPM_ENABLE = no
#LTO_ENABLE = yes
#COMBO_ENABLE =  yes
EXTRAKEY_ENABLE = yes
RAW_ENABLE = no

VIA_ENABLE = no
UNICODE_ENABLE = no
RGBLIGHT_ENABLE = no
MOUSEKEY_ENABLE = no
TAP_DANCE_ENABLE = no
STENO_ENABLE = no
BOOTMAGIC_ENABLE = no
TERMINAL_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
KEY_LOCK_ENABLE = no
AUDIO_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
VELOCIKEY_ENABLE = no

SRC += keylogger.c
ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += encoder.c
endif
ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += oled.c
endif
ifeq ($(strip $(RAW_ENABLE)), yes)
	SRC += hid.c
endif

