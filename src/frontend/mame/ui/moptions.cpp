// license:BSD-3-Clause
// copyright-holders:Maurizio Petrarota
/***************************************************************************

    ui/moptions.cpp

    UI main options manager.

***************************************************************************/

#include "emu.h"
#include "options.h"
#include "ui/moptions.h"


//**************************************************************************
//  UI EXTRA OPTIONS
//**************************************************************************

const options_entry ui_options::s_option_entries[] =
{
	// search path options
	{ nullptr,                              nullptr,                       core_options::option_type::HEADER,  "UI SEARCH PATH OPTIONS" },
	{ OPTION_HISTORY_PATH,                  "history;dats;.",              core_options::option_type::STRING,  "path to system/software info files" },
	{ OPTION_CATEGORYINI_PATH,              "folders",                     core_options::option_type::STRING,  "path to category ini files" },
	{ OPTION_CABINETS_PATH,                 "cabinets;cabdevs",            core_options::option_type::STRING,  "path to cabinets / devices image" },
	{ OPTION_CPANELS_PATH,                  "cpanel",                      core_options::option_type::STRING,  "path to control panel image" },
	{ OPTION_PCBS_PATH,                     "pcb",                         core_options::option_type::STRING,  "path to pcbs image" },
	{ OPTION_FLYERS_PATH,                   "flyers",                      core_options::option_type::STRING,  "path to flyers image" },
	{ OPTION_TITLES_PATH,                   "titles",                      core_options::option_type::STRING,  "path to titles image" },
	{ OPTION_ENDS_PATH,                     "ends",                        core_options::option_type::STRING,  "path to ends image" },
	{ OPTION_MARQUEES_PATH,                 "marquees",                    core_options::option_type::STRING,  "path to marquees image" },
	{ OPTION_ARTPREV_PATH,                  "artwork preview;artpreview",  core_options::option_type::STRING,  "path to artwork preview image" },
	{ OPTION_BOSSES_PATH,                   "bosses",                      core_options::option_type::STRING,  "path to bosses image" },
	{ OPTION_LOGOS_PATH,                    "logo",                        core_options::option_type::STRING,  "path to logos image" },
	{ OPTION_SCORES_PATH,                   "scores",                      core_options::option_type::STRING,  "path to scores image" },
	{ OPTION_VERSUS_PATH,                   "versus",                      core_options::option_type::STRING,  "path to versus image" },
	{ OPTION_GAMEOVER_PATH,                 "gameover",                    core_options::option_type::STRING,  "path to gameover image" },
	{ OPTION_HOWTO_PATH,                    "howto",                       core_options::option_type::STRING,  "path to howto image" },
	{ OPTION_SELECT_PATH,                   "select",                      core_options::option_type::STRING,  "path to select image" },
	{ OPTION_ICONS_PATH,                    "icons",                       core_options::option_type::STRING,  "path to ICOns image" },
	{ OPTION_COVER_PATH,                    "covers",                      core_options::option_type::STRING,  "path to software cover image" },
	{ OPTION_UI_PATH,                       "ui",                          core_options::option_type::STRING,  "path to UI files" },

	// misc options
	{ nullptr,                              nullptr,    core_options::option_type::HEADER,      "UI MISC OPTIONS" },
	{ OPTION_SYSTEM_NAMES,                  "",         core_options::option_type::STRING,      "translated system names file" },
	{ OPTION_SKIP_WARNINGS,                 "0",        core_options::option_type::BOOLEAN,     "display fewer repeated warnings about imperfect emulation" },
	{ OPTION_REMEMBER_LAST,                 "1",        core_options::option_type::BOOLEAN,     "initially select last used system in main menu" },
	{ OPTION_ENLARGE_SNAPS,                 "1",        core_options::option_type::BOOLEAN,     "enlarge artwork (snapshot, title, etc.) in right panel (keeping aspect ratio)" },
	{ OPTION_FORCED4X3,                     "1",        core_options::option_type::BOOLEAN,     "force the appearance of the snapshot in the list software to 4:3" },
	{ OPTION_USE_BACKGROUND,                "1",        core_options::option_type::BOOLEAN,     "enable background image in main view" },
	{ OPTION_SKIP_BIOS_MENU,                "0",        core_options::option_type::BOOLEAN,     "skip bios submenu, start with configured or default" },
	{ OPTION_SKIP_PARTS_MENU,               "0",        core_options::option_type::BOOLEAN,     "skip parts submenu, start with first part" },
	{ OPTION_LAST_USED_FILTER,              "",         core_options::option_type::STRING,      "latest used filter" },
	{ OPTION_LAST_RIGHT_PANEL "(0-1)",      "0",        core_options::option_type::INTEGER,     "latest right panel focus" },
	{ OPTION_LAST_USED_MACHINE,             "",         core_options::option_type::STRING,      "latest used machine" },
	{ OPTION_INFO_AUTO_AUDIT,               "0",        core_options::option_type::BOOLEAN,     "enable auto audit in the general info panel" },
	{ OPTION_HIDE_ROMLESS,                  "1",        core_options::option_type::BOOLEAN,     "hide romless machine from available list" },
	{ OPTION_UNTHROTTLE_MUTE ";utm",        "0",        core_options::option_type::BOOLEAN,     "mute audio when running unthrottled" },

	// UI options
	{ nullptr,                              nullptr,        core_options::option_type::HEADER,      "UI OPTIONS" },
	{ OPTION_INFOS_SIZE "(0.20-1.00)",      "0.75",         core_options::option_type::FLOAT,       "UI right panel infos text size (0.20 - 1.00)" },
	{ OPTION_FONT_ROWS "(25-40)",           "30",           core_options::option_type::INTEGER,     "UI font lines per screen (25 - 40)" },
	{ OPTION_HIDE_PANELS "(0-3)",           "0",            core_options::option_type::INTEGER,     "UI hide left/right panel in main view (0 = Show all, 1 = hide left, 2 = hide right, 3 = hide both" },
	// MAMEFX colours changed
	{ OPTION_UI_BORDER_COLOR,               "ff000000",     core_options::option_type::STRING,      "UI border color (ARGB)" },
	{ OPTION_UI_BACKGROUND_COLOR,           "efefefef",     core_options::option_type::STRING,      "UI background color (ARGB)" },
	{ OPTION_UI_CLONE_COLOR,                "ff7f7f7f",     core_options::option_type::STRING,      "UI clone color (ARGB)" },
	{ OPTION_UI_DIPSW_COLOR,                "ff7f7f7f",     core_options::option_type::STRING,      "UI dipswitch color (ARGB)" },
	{ OPTION_UI_GFXVIEWER_BG_COLOR,         "ef101030",     core_options::option_type::STRING,      "UI gfx viewer color (ARGB)" },
	{ OPTION_UI_MOUSEDOWN_BG_COLOR,         "ef00a2e8",     core_options::option_type::STRING,      "UI mouse down bg color (ARGB)" },
	{ OPTION_UI_MOUSEDOWN_COLOR,            "fffff200",     core_options::option_type::STRING,      "UI mouse down color (ARGB)" },
	{ OPTION_UI_MOUSEOVER_BG_COLOR,         "ef00a2e8",     core_options::option_type::STRING,      "UI mouse over bg color (ARGB)" },
	{ OPTION_UI_MOUSEOVER_COLOR,            "fffff200",     core_options::option_type::STRING,      "UI mouse over color (ARGB)" },
	{ OPTION_UI_SELECTED_BG_COLOR,          "ef3f48cc",     core_options::option_type::STRING,      "UI selected bg color (ARGB)" },
	{ OPTION_UI_SELECTED_COLOR,             "fffff200",     core_options::option_type::STRING,      "UI selected color (ARGB)" },
	{ OPTION_UI_SLIDER_COLOR,               "ef22b14c",     core_options::option_type::STRING,      "UI slider color (ARGB)" },
	{ OPTION_UI_SUBITEM_COLOR,              "ef3f48cc",     core_options::option_type::STRING,      "UI subitem color (ARGB)" },
	{ OPTION_UI_TEXT_BG_COLOR,              "efefefef",     core_options::option_type::STRING,      "UI text bg color (ARGB)" },
	{ OPTION_UI_TEXT_COLOR,                 "ff000000",     core_options::option_type::STRING,      "UI text color (ARGB)" },
	{ OPTION_UI_UNAVAILABLE_COLOR,          "ff7f7f7f",     core_options::option_type::STRING,      "UI unavailable color (ARGB)" },
	{ nullptr }
};

//-------------------------------------------------
//  ui_options - constructor
//-------------------------------------------------

ui_options::ui_options() : core_options()
{
	add_entries(ui_options::s_option_entries);
}

//-------------------------------------------------
//  rgb_value - decode an RGB option
//-------------------------------------------------

rgb_t ui_options::rgb_value(const char *option) const
{
	// find the entry
	core_options::entry::shared_const_ptr entry = get_entry(option);

	// look up the value, and sanity check the result
	const char *value = entry->value();
	int len = strlen(value);
	if (len != 8)
		value = entry->default_value().c_str();

	// convert to an rgb_t
	return rgb_t((uint32_t)strtoul(value, nullptr, 16));
}
