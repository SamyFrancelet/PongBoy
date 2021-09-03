//
//  Font data for Arial Narrow 12pt
//

// Character bitmaps for Arial Narrow 12pt
#include "lcd_highlevel.h"
const uint8_t arialNarrow_12ptBitmaps[] =
{
	// @0 ' ' (8 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //

	// @15 '!' (2 pixels wide)
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //

	// @30 '"' (5 pixels wide)
	0x00, //
	0xD8, // ## ##
	0xD8, // ## ##
	0xD8, // ## ##
	0xD8, // ## ##
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //

	// @45 '#' (7 pixels wide)
	0x00, //
	0x12, //    #  #
	0x12, //    #  #
	0x24, //   #  #
	0xFE, // #######
	0xFE, // #######
	0x48, //  #  #
	0xFE, // #######
	0xFE, // #######
	0x48, //  #  #
	0x90, // #  #
	0x90, // #  #
	0x00, //
	0x00, //
	0x00, //

	// @60 '$' (7 pixels wide)
	0x10, //    #
	0x7C, //  #####
	0xFC, // ######
	0xD6, // ## # ##
	0xD0, // ## #
	0xF0, // ####
	0x7C, //  #####
	0x1E, //    ####
	0x16, //    # ##
	0xD6, // ## # ##
	0x7E, //  ######
	0x7C, //  #####
	0x10, //    #
	0x00, //
	0x00, //

	// @75 '%' (10 pixels wide)
	0x00, 0x00, //
	0x61, 0x00, //  ##    #
	0x91, 0x00, // #  #   #
	0x92, 0x00, // #  #  #
	0x92, 0x00, // #  #  #
	0x94, 0x00, // #  # #
	0x65, 0x80, //  ##  # ##
	0x06, 0x40, //      ##  #
	0x0A, 0x40, //     # #  #
	0x0A, 0x40, //     # #  #
	0x12, 0x40, //    #  #  #
	0x11, 0x80, //    #   ##
	0x00, 0x00, //
	0x00, 0x00, //
	0x00, 0x00, //

	// @105 '&' (8 pixels wide)
	0x00, //
	0x38, //   ###
	0x7C, //  #####
	0x6C, //  ## ##
	0x7C, //  #####
	0x30, //   ##
	0x78, //  ####
	0xDA, // ## ## #
	0xCE, // ##  ###
	0xCE, // ##  ###
	0xFF, // ########
	0x7A, //  #### #
	0x00, //
	0x00, //
	0x00, //

	// @120 ''' (2 pixels wide)
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //

	// @135 '(' (4 pixels wide)
	0x00, //
	0x10, //    #
	0x20, //   #
	0x60, //  ##
	0x60, //  ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x60, //  ##
	0x60, //  ##
	0x20, //   #
	0x10, //    #

	// @150 ')' (4 pixels wide)
	0x00, //
	0x80, // #
	0x40, //  #
	0x60, //  ##
	0x20, //   #
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x60, //  ##
	0x60, //  ##
	0x40, //  #
	0x80, // #

	// @165 '*' (5 pixels wide)
	0x00, //
	0x20, //   #
	0xA8, // # # #
	0xF8, // #####
	0x20, //   #
	0x50, //  # #
	0x50, //  # #
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //

	// @180 '+' (6 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0xFC, // ######
	0xFC, // ######
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x00, //
	0x00, //
	0x00, //

	// @195 ',' (2 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0x40, //  #
	0x40, //  #
	0x80, // #

	// @210 '-' (4 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xF0, // ####
	0xF0, // ####
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //

	// @225 '.' (2 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //

	// @240 '/' (4 pixels wide)
	0x00, //
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //

	// @255 '0' (6 pixels wide)
	0x00, //
	0x78, //  ####
	0x78, //  ####
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0x78, //  ####
	0x78, //  ####
	0x00, //
	0x00, //
	0x00, //

	// @270 '1' (4 pixels wide)
	0x00, //
	0x30, //   ##
	0x30, //   ##
	0x70, //  ###
	0xF0, // ####
	0xB0, // # ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x00, //
	0x00, //
	0x00, //

	// @285 '2' (6 pixels wide)
	0x00, //
	0x38, //   ###
	0x7C, //  #####
	0xCC, // ##  ##
	0xCC, // ##  ##
	0x0C, //     ##
	0x18, //    ##
	0x38, //   ###
	0x70, //  ###
	0x60, //  ##
	0xFC, // ######
	0xFC, // ######
	0x00, //
	0x00, //
	0x00, //

	// @300 '3' (6 pixels wide)
	0x00, //
	0x78, //  ####
	0xFC, // ######
	0xCC, // ##  ##
	0x0C, //     ##
	0x38, //   ###
	0x38, //   ###
	0x0C, //     ##
	0x0C, //     ##
	0xCC, // ##  ##
	0xF8, // #####
	0x78, //  ####
	0x00, //
	0x00, //
	0x00, //

	// @315 '4' (7 pixels wide)
	0x00, //
	0x0C, //     ##
	0x1C, //    ###
	0x1C, //    ###
	0x3C, //   ####
	0x2C, //   # ##
	0x6C, //  ## ##
	0xCC, // ##  ##
	0xFE, // #######
	0xFE, // #######
	0x0C, //     ##
	0x0C, //     ##
	0x00, //
	0x00, //
	0x00, //

	// @330 '5' (6 pixels wide)
	0x00, //
	0x7C, //  #####
	0x7C, //  #####
	0x60, //  ##
	0xD8, // ## ##
	0xFC, // ######
	0xCC, // ##  ##
	0x0C, //     ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0x78, //  ####
	0x78, //  ####
	0x00, //
	0x00, //
	0x00, //

	// @345 '6' (5 pixels wide)
	0x00, //
	0x70, //  ###
	0x78, //  ####
	0xD8, // ## ##
	0xC0, // ##
	0xF0, // ####
	0xF8, // #####
	0xD8, // ## ##
	0xD8, // ## ##
	0xD8, // ## ##
	0x78, //  ####
	0x70, //  ###
	0x00, //
	0x00, //
	0x00, //

	// @360 '7' (5 pixels wide)
	0x00, //
	0xF8, // #####
	0xF8, // #####
	0x18, //    ##
	0x10, //    #
	0x30, //   ##
	0x30, //   ##
	0x20, //   #
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x00, //
	0x00, //
	0x00, //

	// @375 '8' (6 pixels wide)
	0x00, //
	0x78, //  ####
	0xFC, // ######
	0xCC, // ##  ##
	0xCC, // ##  ##
	0x78, //  ####
	0x78, //  ####
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xFC, // ######
	0x78, //  ####
	0x00, //
	0x00, //
	0x00, //

	// @390 '9' (6 pixels wide)
	0x00, //
	0x70, //  ###
	0xF8, // #####
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xFC, // ######
	0x7C, //  #####
	0x0C, //     ##
	0xCC, // ##  ##
	0xF8, // #####
	0x70, //  ###
	0x00, //
	0x00, //
	0x00, //

	// @405 ':' (2 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //

	// @420 ';' (2 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0x40, //  #
	0x40, //  #
	0x80, // #

	// @435 '<' (6 pixels wide)
	0x00, //
	0x00, //
	0x04, //      #
	0x1C, //    ###
	0x38, //   ###
	0xF0, // ####
	0xC0, // ##
	0xF0, // ####
	0x38, //   ###
	0x1C, //    ###
	0x04, //      #
	0x00, //
	0x00, //
	0x00, //
	0x00, //

	// @450 '=' (6 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xFC, // ######
	0xFC, // ######
	0x00, //
	0xFC, // ######
	0xFC, // ######
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //

	// @465 '>' (6 pixels wide)
	0x00, //
	0x00, //
	0x80, // #
	0xE0, // ###
	0x70, //  ###
	0x3C, //   ####
	0x0C, //     ##
	0x1C, //    ###
	0x70, //  ###
	0xE0, // ###
	0x80, // #
	0x00, //
	0x00, //
	0x00, //
	0x00, //

	// @480 '?' (6 pixels wide)
	0x00, //
	0x78, //  ####
	0xFC, // ######
	0xCC, // ##  ##
	0xCC, // ##  ##
	0x1C, //    ###
	0x18, //    ##
	0x30, //   ##
	0x30, //   ##
	0x00, //
	0x30, //   ##
	0x30, //   ##
	0x00, //
	0x00, //
	0x00, //

	// @495 '@' (13 pixels wide)
	0x00, 0x00, //
	0x0F, 0xC0, //     ######
	0x1F, 0xE0, //    ########
	0x30, 0x30, //   ##      ##
	0x66, 0xD8, //  ##  ## ## ##
	0xEF, 0xD8, // ### ###### ##
	0xDD, 0xD8, // ## ### ### ##
	0xD8, 0x98, // ## ##   #  ##
	0xD9, 0x98, // ## ##  ##  ##
	0xD9, 0xB0, // ## ##  ## ##
	0xDF, 0xF0, // ## #########
	0x6E, 0xC8, //  ## ### ##  #
	0x70, 0x10, //  ###       #
	0x3F, 0xE0, //   #########
	0x0F, 0xC0, //     ######

	// @525 'A' (9 pixels wide)
	0x00, 0x00, //
	0x1C, 0x00, //    ###
	0x1C, 0x00, //    ###
	0x1C, 0x00, //    ###
	0x36, 0x00, //   ## ##
	0x36, 0x00, //   ## ##
	0x36, 0x00, //   ## ##
	0x63, 0x00, //  ##   ##
	0x7F, 0x00, //  #######
	0x7F, 0x00, //  #######
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0x00, 0x00, //
	0x00, 0x00, //
	0x00, 0x00, //

	// @555 'B' (7 pixels wide)
	0x00, //
	0xFC, // ######
	0xFE, // #######
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xFC, // ######
	0xFC, // ######
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xFE, // #######
	0xFC, // ######
	0x00, //
	0x00, //
	0x00, //

	// @570 'C' (8 pixels wide)
	0x00, //
	0x3C, //   ####
	0x7E, //  ######
	0x67, //  ##  ###
	0xC2, // ##    #
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC2, // ##    #
	0x67, //  ##  ###
	0x7E, //  ######
	0x3C, //   ####
	0x00, //
	0x00, //
	0x00, //

	// @585 'D' (7 pixels wide)
	0x00, //
	0xF8, // #####
	0xFC, // ######
	0xCE, // ##  ###
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xCE, // ##  ###
	0xFC, // ######
	0xF8, // #####
	0x00, //
	0x00, //
	0x00, //

	// @600 'E' (7 pixels wide)
	0x00, //
	0xFE, // #######
	0xFE, // #######
	0xC0, // ##
	0xC0, // ##
	0xFE, // #######
	0xFE, // #######
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xFE, // #######
	0xFE, // #######
	0x00, //
	0x00, //
	0x00, //

	// @615 'F' (6 pixels wide)
	0x00, //
	0xFC, // ######
	0xFC, // ######
	0xC0, // ##
	0xC0, // ##
	0xF8, // #####
	0xF8, // #####
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //

	// @630 'G' (8 pixels wide)
	0x00, //
	0x3C, //   ####
	0x7E, //  ######
	0x67, //  ##  ###
	0xC3, // ##    ##
	0xC0, // ##
	0xCF, // ##  ####
	0xCF, // ##  ####
	0xC3, // ##    ##
	0x63, //  ##   ##
	0x7F, //  #######
	0x3C, //   ####
	0x00, //
	0x00, //
	0x00, //

	// @645 'H' (7 pixels wide)
	0x00, //
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xFE, // #######
	0xFE, // #######
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x00, //
	0x00, //
	0x00, //

	// @660 'I' (2 pixels wide)
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //

	// @675 'J' (6 pixels wide)
	0x00, //
	0x0C, //     ##
	0x0C, //     ##
	0x0C, //     ##
	0x0C, //     ##
	0x0C, //     ##
	0x0C, //     ##
	0x0C, //     ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xFC, // ######
	0x78, //  ####
	0x00, //
	0x00, //
	0x00, //

	// @690 'K' (8 pixels wide)
	0x00, //
	0xC3, // ##    ##
	0xC6, // ##   ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xD8, // ## ##
	0xFC, // ######
	0xEC, // ### ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0x00, //
	0x00, //
	0x00, //

	// @705 'L' (7 pixels wide)
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xFE, // #######
	0xFE, // #######
	0x00, //
	0x00, //
	0x00, //

	// @720 'M' (9 pixels wide)
	0x00, 0x00, //
	0xE3, 0x80, // ###   ###
	0xE3, 0x80, // ###   ###
	0xE3, 0x80, // ###   ###
	0xF7, 0x80, // #### ####
	0xD5, 0x80, // ## # # ##
	0xD5, 0x80, // ## # # ##
	0xD5, 0x80, // ## # # ##
	0xD5, 0x80, // ## # # ##
	0xDD, 0x80, // ## ### ##
	0xD9, 0x80, // ## ##  ##
	0xC9, 0x80, // ##  #  ##
	0x00, 0x00, //
	0x00, 0x00, //
	0x00, 0x00, //

	// @750 'N' (7 pixels wide)
	0x00, //
	0xC6, // ##   ##
	0xE6, // ###  ##
	0xE6, // ###  ##
	0xE6, // ###  ##
	0xF6, // #### ##
	0xD6, // ## # ##
	0xDE, // ## ####
	0xDE, // ## ####
	0xCE, // ##  ###
	0xCE, // ##  ###
	0xC6, // ##   ##
	0x00, //
	0x00, //
	0x00, //

	// @765 'O' (8 pixels wide)
	0x00, //
	0x3C, //   ####
	0x7E, //  ######
	0x67, //  ##  ###
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0xC3, // ##    ##
	0x66, //  ##  ##
	0x7E, //  ######
	0x3C, //   ####
	0x00, //
	0x00, //
	0x00, //

	// @780 'P' (7 pixels wide)
	0x00, //
	0xFC, // ######
	0xFE, // #######
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xFE, // #######
	0xFC, // ######
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //

	// @795 'Q' (9 pixels wide)
	0x00, 0x00, //
	0x3C, 0x00, //   ####
	0x7E, 0x00, //  ######
	0xE7, 0x00, // ###  ###
	0xC3, 0x00, // ##    ##
	0xC3, 0x00, // ##    ##
	0xC3, 0x00, // ##    ##
	0xC3, 0x00, // ##    ##
	0xCB, 0x00, // ##  # ##
	0x66, 0x00, //  ##  ##
	0x7F, 0x00, //  #######
	0x3D, 0x80, //   #### ##
	0x00, 0x80, //         #
	0x00, 0x00, //
	0x00, 0x00, //

	// @825 'R' (8 pixels wide)
	0x00, //
	0xFC, // ######
	0xFE, // #######
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xFE, // #######
	0xFC, // ######
	0xCC, // ##  ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC3, // ##    ##
	0x00, //
	0x00, //
	0x00, //

	// @840 'S' (7 pixels wide)
	0x00, //
	0x7C, //  #####
	0xFE, // #######
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xF0, // ####
	0x7C, //  #####
	0x0E, //     ###
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xFE, // #######
	0x7C, //  #####
	0x00, //
	0x00, //
	0x00, //

	// @855 'T' (8 pixels wide)
	0x00, //
	0xFF, // ########
	0xFF, // ########
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x00, //
	0x00, //
	0x00, //

	// @870 'U' (7 pixels wide)
	0x00, //
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x7E, //  ######
	0x38, //   ###
	0x00, //
	0x00, //
	0x00, //

	// @885 'V' (9 pixels wide)
	0x00, 0x00, //
	0xC1, 0x80, // ##     ##
	0xC1, 0x80, // ##     ##
	0x63, 0x00, //  ##   ##
	0x63, 0x00, //  ##   ##
	0x63, 0x00, //  ##   ##
	0x36, 0x00, //   ## ##
	0x36, 0x00, //   ## ##
	0x36, 0x00, //   ## ##
	0x1C, 0x00, //    ###
	0x1C, 0x00, //    ###
	0x1C, 0x00, //    ###
	0x00, 0x00, //
	0x00, 0x00, //
	0x00, 0x00, //

	// @915 'W' (11 pixels wide)
	0x00, 0x00, //
	0xC4, 0x60, // ##   #   ##
	0xC4, 0x60, // ##   #   ##
	0xCA, 0x60, // ##  # #  ##
	0x6A, 0xC0, //  ## # # ##
	0x6A, 0xC0, //  ## # # ##
	0x6A, 0xC0, //  ## # # ##
	0x6A, 0xC0, //  ## # # ##
	0x6A, 0xC0, //  ## # # ##
	0x31, 0x80, //   ##   ##
	0x31, 0x80, //   ##   ##
	0x31, 0x80, //   ##   ##
	0x00, 0x00, //
	0x00, 0x00, //
	0x00, 0x00, //

	// @945 'X' (9 pixels wide)
	0x00, 0x00, //
	0xC1, 0x80, // ##     ##
	0x63, 0x00, //  ##   ##
	0x36, 0x00, //   ## ##
	0x36, 0x00, //   ## ##
	0x1C, 0x00, //    ###
	0x1C, 0x00, //    ###
	0x1C, 0x00, //    ###
	0x36, 0x00, //   ## ##
	0x36, 0x00, //   ## ##
	0x63, 0x00, //  ##   ##
	0xC1, 0x80, // ##     ##
	0x00, 0x00, //
	0x00, 0x00, //
	0x00, 0x00, //

	// @975 'Y' (8 pixels wide)
	0x00, //
	0xC3, // ##    ##
	0x66, //  ##  ##
	0x66, //  ##  ##
	0x3C, //   ####
	0x3C, //   ####
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x18, //    ##
	0x00, //
	0x00, //
	0x00, //

	// @990 'Z' (7 pixels wide)
	0x00, //
	0xFE, // #######
	0xFE, // #######
	0x06, //      ##
	0x0C, //     ##
	0x18, //    ##
	0x30, //   ##
	0x30, //   ##
	0x60, //  ##
	0xC0, // ##
	0xFE, // #######
	0xFE, // #######
	0x00, //
	0x00, //
	0x00, //

	// @1005 '[' (3 pixels wide)
	0x00, //
	0xE0, // ###
	0xE0, // ###
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xE0, // ###
	0xE0, // ###

	// @1020 '\' (4 pixels wide)
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x00, //
	0x00, //
	0x00, //

	// @1035 ']' (3 pixels wide)
	0x00, //
	0xE0, // ###
	0xE0, // ###
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0xE0, // ###
	0xE0, // ###

	// @1050 '^' (7 pixels wide)
	0x00, //
	0x38, //   ###
	0x38, //   ###
	0x6C, //  ## ##
	0x6C, //  ## ##
	0x6C, //  ## ##
	0xC6, // ##   ##
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //

	// @1065 '_' (7 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xFE, // #######
	0x00, //

	// @1080 '`' (3 pixels wide)
	0x00, //
	0xC0, // ##
	0x60, //  ##
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //

	// @1095 'a' (6 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x78, //  ####
	0xFC, // ######
	0xCC, // ##  ##
	0x3C, //   ####
	0xFC, // ######
	0xCC, // ##  ##
	0xFC, // ######
	0x6C, //  ## ##
	0x00, //
	0x00, //
	0x00, //

	// @1110 'b' (6 pixels wide)
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xF8, // #####
	0xFC, // ######
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xF8, // #####
	0xF8, // #####
	0x00, //
	0x00, //
	0x00, //

	// @1125 'c' (5 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x70, //  ###
	0x78, //  ####
	0xD8, // ## ##
	0xC0, // ##
	0xC0, // ##
	0xD8, // ## ##
	0x78, //  ####
	0x70, //  ###
	0x00, //
	0x00, //
	0x00, //

	// @1140 'd' (6 pixels wide)
	0x00, //
	0x0C, //     ##
	0x0C, //     ##
	0x0C, //     ##
	0x7C, //  #####
	0xFC, // ######
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xFC, // ######
	0x7C, //  #####
	0x00, //
	0x00, //
	0x00, //

	// @1155 'e' (5 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x70, //  ###
	0xF8, // #####
	0xD8, // ## ##
	0xF8, // #####
	0xC0, // ##
	0xD8, // ## ##
	0xF8, // #####
	0x70, //  ###
	0x00, //
	0x00, //
	0x00, //

	// @1170 'f' (4 pixels wide)
	0x00, //
	0x30, //   ##
	0x70, //  ###
	0x60, //  ##
	0xF0, // ####
	0xF0, // ####
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x00, //
	0x00, //
	0x00, //

	// @1185 'g' (6 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x6C, //  ## ##
	0xFC, // ######
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xFC, // ######
	0x6C, //  ## ##
	0x0C, //     ##
	0xCC, // ##  ##
	0x78, //  ####

	// @1200 'h' (6 pixels wide)
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xD8, // ## ##
	0xFC, // ######
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0x00, //
	0x00, //
	0x00, //

	// @1215 'i' (2 pixels wide)
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //

	// @1230 'j' (4 pixels wide)
	0x00, //
	0x30, //   ##
	0x30, //   ##
	0x00, //
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0x30, //   ##
	0xF0, // ####
	0xE0, // ###

	// @1245 'k' (6 pixels wide)
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xCC, // ##  ##
	0xD8, // ## ##
	0xF0, // ####
	0xF8, // #####
	0xD8, // ## ##
	0xD8, // ## ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0x00, //
	0x00, //
	0x00, //

	// @1260 'l' (2 pixels wide)
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //

	// @1275 'm' (10 pixels wide)
	0x00, 0x00, //
	0x00, 0x00, //
	0x00, 0x00, //
	0x00, 0x00, //
	0xD9, 0x80, // ## ##  ##
	0xFF, 0xC0, // ##########
	0xCC, 0xC0, // ##  ##  ##
	0xCC, 0xC0, // ##  ##  ##
	0xCC, 0xC0, // ##  ##  ##
	0xCC, 0xC0, // ##  ##  ##
	0xCC, 0xC0, // ##  ##  ##
	0xCC, 0xC0, // ##  ##  ##
	0x00, 0x00, //
	0x00, 0x00, //
	0x00, 0x00, //

	// @1305 'n' (6 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xD8, // ## ##
	0xFC, // ######
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0x00, //
	0x00, //
	0x00, //

	// @1320 'o' (6 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x78, //  ####
	0x78, //  ####
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0x78, //  ####
	0x78, //  ####
	0x00, //
	0x00, //
	0x00, //

	// @1335 'p' (6 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xD8, // ## ##
	0xFC, // ######
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xF8, // #####
	0xD8, // ## ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##

	// @1350 'q' (6 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x6C, //  ## ##
	0xFC, // ######
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xFC, // ######
	0x6C, //  ## ##
	0x0C, //     ##
	0x0C, //     ##
	0x0C, //     ##

	// @1365 'r' (4 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xD0, // ## #
	0xF0, // ####
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //

	// @1380 's' (5 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x70, //  ###
	0xF8, // #####
	0xC8, // ##  #
	0xE0, // ###
	0x38, //   ###
	0x98, // #  ##
	0xF8, // #####
	0x70, //  ###
	0x00, //
	0x00, //
	0x00, //

	// @1395 't' (4 pixels wide)
	0x00, //
	0x20, //   #
	0x60, //  ##
	0x60, //  ##
	0xF0, // ####
	0xF0, // ####
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x70, //  ###
	0x70, //  ###
	0x00, //
	0x00, //
	0x00, //

	// @1410 'u' (6 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xFC, // ######
	0x6C, //  ## ##
	0x00, //
	0x00, //
	0x00, //

	// @1425 'v' (7 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x6C, //  ## ##
	0x6C, //  ## ##
	0x6C, //  ## ##
	0x38, //   ###
	0x38, //   ###
	0x38, //   ###
	0x00, //
	0x00, //
	0x00, //

	// @1440 'w' (9 pixels wide)
	0x00, 0x00, //
	0x00, 0x00, //
	0x00, 0x00, //
	0x00, 0x00, //
	0xDD, 0x80, // ## ### ##
	0xDD, 0x80, // ## ### ##
	0xDD, 0x80, // ## ### ##
	0xD5, 0x80, // ## # # ##
	0x55, 0x00, //  # # # #
	0x77, 0x00, //  ### ###
	0x77, 0x00, //  ### ###
	0x77, 0x00, //  ### ###
	0x00, 0x00, //
	0x00, 0x00, //
	0x00, 0x00, //

	// @1470 'x' (6 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xCC, // ##  ##
	0x78, //  ####
	0x78, //  ####
	0x30, //   ##
	0x30, //   ##
	0x78, //  ####
	0x78, //  ####
	0xCC, // ##  ##
	0x00, //
	0x00, //
	0x00, //

	// @1485 'y' (7 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xC6, // ##   ##
	0xC6, // ##   ##
	0x6C, //  ## ##
	0x6C, //  ## ##
	0x6C, //  ## ##
	0x38, //   ###
	0x38, //   ###
	0x38, //   ###
	0x30, //   ##
	0xF0, // ####
	0xE0, // ###

	// @1500 'z' (6 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xFC, // ######
	0xFC, // ######
	0x18, //    ##
	0x30, //   ##
	0x30, //   ##
	0x60, //  ##
	0xFC, // ######
	0xFC, // ######
	0x00, //
	0x00, //
	0x00, //

	// @1515 '{' (4 pixels wide)
	0x00, //
	0x30, //   ##
	0x70, //  ###
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0xC0, // ##
	0xC0, // ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x70, //  ###
	0x30, //   ##

	// @1530 '|' (2 pixels wide)
	0x00, //
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##

	// @1545 '}' (4 pixels wide)
	0x00, //
	0xC0, // ##
	0xE0, // ###
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x30, //   ##
	0x30, //   ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0x60, //  ##
	0xE0, // ###
	0xC0, // ##

	// @1560 '~' (6 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xE4, // ###  #
	0xFC, // ######
	0x9C, // #  ###
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //
};

// Character descriptors for Arial Narrow 12pt
// { [Char width in bits], [Offset into arialNarrow_12ptCharBitmaps in bytes] }
const FONT_CHAR_INFO arialNarrow_12ptDescriptors[] =
{
	{8, 0}, 		//
	{2, 15}, 		// !
	{5, 30}, 		// "
	{7, 45}, 		// #
	{7, 60}, 		// $
	{10, 75}, 		// %
	{8, 105}, 		// &
	{2, 120}, 		// '
	{4, 135}, 		// (
	{4, 150}, 		// )
	{5, 165}, 		// *
	{6, 180}, 		// +
	{2, 195}, 		// ,
	{4, 210}, 		// -
	{2, 225}, 		// .
	{4, 240}, 		// /
	{6, 255}, 		// 0
	{4, 270}, 		// 1
	{6, 285}, 		// 2
	{6, 300}, 		// 3
	{7, 315}, 		// 4
	{6, 330}, 		// 5
	{5, 345}, 		// 6
	{5, 360}, 		// 7
	{6, 375}, 		// 8
	{6, 390}, 		// 9
	{2, 405}, 		// :
	{2, 420}, 		// ;
	{6, 435}, 		// <
	{6, 450}, 		// =
	{6, 465}, 		// >
	{6, 480}, 		// ?
	{13, 495}, 		// @
	{9, 525}, 		// A
	{7, 555}, 		// B
	{8, 570}, 		// C
	{7, 585}, 		// D
	{7, 600}, 		// E
	{6, 615}, 		// F
	{8, 630}, 		// G
	{7, 645}, 		// H
	{2, 660}, 		// I
	{6, 675}, 		// J
	{8, 690}, 		// K
	{7, 705}, 		// L
	{9, 720}, 		// M
	{7, 750}, 		// N
	{8, 765}, 		// O
	{7, 780}, 		// P
	{9, 795}, 		// Q
	{8, 825}, 		// R
	{7, 840}, 		// S
	{8, 855}, 		// T
	{7, 870}, 		// U
	{9, 885}, 		// V
	{11, 915}, 		// W
	{9, 945}, 		// X
	{8, 975}, 		// Y
	{7, 990}, 		// Z
	{3, 1005}, 		// [
	{4, 1020}, 		// backslash
	{3, 1035}, 		// ]
	{7, 1050}, 		// ^
	{7, 1065}, 		// _
	{3, 1080}, 		// `
	{6, 1095}, 		// a
	{6, 1110}, 		// b
	{5, 1125}, 		// c
	{6, 1140}, 		// d
	{5, 1155}, 		// e
	{4, 1170}, 		// f
	{6, 1185}, 		// g
	{6, 1200}, 		// h
	{2, 1215}, 		// i
	{4, 1230}, 		// j
	{6, 1245}, 		// k
	{2, 1260}, 		// l
	{10, 1275}, 		// m
	{6, 1305}, 		// n
	{6, 1320}, 		// o
	{6, 1335}, 		// p
	{6, 1350}, 		// q
	{4, 1365}, 		// r
	{5, 1380}, 		// s
	{4, 1395}, 		// t
	{6, 1410}, 		// u
	{7, 1425}, 		// v
	{9, 1440}, 		// w
	{6, 1470}, 		// x
	{7, 1485}, 		// y
	{6, 1500}, 		// z
	{4, 1515}, 		// {
	{2, 1530}, 		// |
	{4, 1545}, 		// }
	{6, 1560}, 		// ~
};

// Font information for Arial Narrow 12pt
const FONT_INFO arialNarrow_12ptFontInfo =
{
	15, //  Character height
	' ', //  Start character
	'~', //  End character
	arialNarrow_12ptDescriptors, //  Character descriptor array
	arialNarrow_12ptBitmaps, //  Character bitmap array
};