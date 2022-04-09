#ifndef COLORS_H_INCLUDED
#define COLORS_H_INCLUDED

/*  Text color from 0x1-0x9
 *  Text background color from 0x10-0x90
 *
 * Name            FG  BG
 * Black           30  40
 * Red             31  41
 * Green           32  42
 * Yellow          33  43
 * Blue            34  44
 * Magenta         35  45
 * Cyan            36  46
 * White           37  47
 * Bright Black    90  100
 * Bright Red      91  101
 * Bright Green    92  102
 * Bright Yellow   93  103
 * Bright Blue     94  104
 * Bright Magenta  95  105
 * Bright Cyan     96  106
 * Bright White    97  107
 */

/*for background*/
#define RESETBG     "\x1B[0m";
#define REDBG       "\x1B[101m";
#define GREENBG     "\x1B[102m";
#define YELLOWBG    "\x1B[43m";
#define BLUEBG      "\x1B[44m";
#define MAGENTABG   "\x1B[105m";
#define GREYBG      "\x1B[100m";
#define MINTBG      "\x1B[102m";
#define SKYBG       "\x1B[104m";
#define PEACHBG     "\x1B[101m";
#define CYANBG      "\x1B[46m";
#define WHITEBG     "\x1B[107m";

/*for text color/foreground */
#define RESET       "\x1B[0m";
#define RED         "\x1B[91m";
#define GREEN       "\x1B[32m";
#define YELLOW      "\x1B[33m";
#define BLUE        "\x1B[34m";
#define MAGENTA     "\x1B[35m";
#define GREY        "\x1B[90m";
#define BLACK       "\x1B[30m";
#define MINT        "\x1B[92m";
#define SKY         "\x1B[94m";
#define PEACH       "\x1B[91m";
#define CYAN        "\x1B[96m";
#define WHITE       "\x1B[97m";

#endif // COLORS_H_INCLUDED
