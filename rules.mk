RGBLIGHT_ENABLE  = yes
COMMAND_ENABLE   = no   # Disable shift combination, which conflicts with shift-parens
MOUSEKEY_ENABLE  = no   # Mouse keys (disabled to save space)
NKRO_ENABLE      = yes  # N-key rollover support
AUDIO_ENABLE     = no   # Audio output on port C6
TAP_DANCE_ENABLE = yes  # Enable tap dance

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
