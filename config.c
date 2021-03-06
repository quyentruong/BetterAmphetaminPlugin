#include "config.h"

void defaultConfig(CONFIG *config) {
    config->FREQ_ACCURATE = 0;
    config->SHOW_ADVANCED = 0;
    config->DEFAULT_PROFILE = 2;
	config->TEMP_IN_FAHRENHEIT = 0;
	config->PSN_INFO = 1;
	config->C1_RED = 0;
	config->C1_GREEN = 0;
	config->C1_BLUE = 255;
	config->C2_RED = 255;
	config->C2_GREEN = 0;
	config->C2_BLUE = 0;
	config->C3_RED = 0;
	config->C3_GREEN = 255;
	config->C3_BLUE = 0;
	config->C4_RED = 255;
	config->C4_GREEN = 255;
	config->C4_BLUE = 255;
	config->THEME_TITLE = 0x0033CC33;
	config->THEME_SELECTED = 0x0033CC33;
	config->THEME_BACKGROUND = 0x00000000;
	config->THEME_FONTCOLOR = 0x00FFFFFF;
}

int loadConfig(CONFIG *config) {
	defaultConfig(config);
    int fd = sceIoOpen("ux0:/plugins/amphetamin_config.txt", SCE_O_RDONLY, 0777);

    char chunk[1025];
    int chunk_size = 0;
    if ((chunk_size=sceIoRead(fd, chunk, 1024)) < 2) return -1;

    char *token = strtok(chunk, "=");

    while (token && token[0] != '\n') {
        char key[30];
        sscanf(token, "%s", key);

        token = strtok(NULL, "\n");
        int value = atoi(token);
        
        token = strtok(NULL, "=");

        if (strcmp(key, "freq_accurate") == 0) {
            config->FREQ_ACCURATE = value;
            continue;
        }   
        if (strcmp(key, "show_advanced") == 0) {
            config->SHOW_ADVANCED = value;
            continue;
        }
        if (strcmp(key, "default_profile") == 0) {
            config->DEFAULT_PROFILE = value;
            continue;
        }
		if (strcmp(key, "temp_in_fahrenheit") == 0) {
            config->TEMP_IN_FAHRENHEIT = value;
            continue;
        }
		if (strcmp(key, "psn_info") == 0) {
            config->PSN_INFO = value;
            continue;
        }
		if (strcmp(key, "pstv_features") == 0) {
            config->PSTV_FEATURES = value;
            continue;
        }
		if (strcmp(key, "c1_red") == 0) {
            config->C1_RED = value;
            continue;
        }
		if (strcmp(key, "c1_green") == 0) {
            config->C1_GREEN = value;
            continue;
        }
		if (strcmp(key, "c1_blue") == 0) {
            config->C1_BLUE = value;
            continue;
        }
		if (strcmp(key, "c2_red") == 0) {
            config->C2_RED = value;
            continue;
        }
		if (strcmp(key, "c2_green") == 0) {
            config->C2_GREEN = value;
            continue;
        }
		if (strcmp(key, "c2_blue") == 0) {
            config->C2_BLUE = value;
            continue;
        }
		if (strcmp(key, "c3_red") == 0) {
            config->C3_RED = value;
            continue;
        }
		if (strcmp(key, "c3_green") == 0) {
            config->C3_GREEN = value;
            continue;
        }
		if (strcmp(key, "c3_blue") == 0) {
            config->C3_BLUE = value;
            continue;
        }
		if (strcmp(key, "c4_red") == 0) {
            config->C4_RED = value;
            continue;
        }
		if (strcmp(key, "c4_green") == 0) {
            config->C4_GREEN = value;
            continue;
        }
		if (strcmp(key, "c4_blue") == 0) {
            config->C4_BLUE = value;
            continue;
        }
		if (strcmp(key, "theme_title") == 0) {
            config->THEME_TITLE = value;
            continue;
        }
		if (strcmp(key, "theme_selected") == 0) {
            config->THEME_SELECTED = value;
            continue;
        }
		if (strcmp(key, "theme_background") == 0) {
            config->THEME_BACKGROUND = value;
            continue;
        }
		if (strcmp(key, "theme_fontcolor") == 0) {
            config->THEME_FONTCOLOR = value;
            continue;
        }
    }

    sceIoClose(fd);

    return 0;
}


