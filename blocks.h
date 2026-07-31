//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    // {"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g", 30, 0},
    {"Pow:", "cat /sys/class/power_supply/BAT0/capacity", 120, 0},
    {"Bat:", "cat /sys/class/power_supply/BAT0/status", 3, 0},
    // {"Vol:", "pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}'", 1, 10},
    {"Vol:", "test \"$(pactl get-sink-mute @DEFAULT_SINK@ | awk '{print $2}')\" = \"yes\" && printf 'muted' || pactl get-sink-volume @DEFAULT_SINK@ | awk '{print $5}'", 1, 10},
    {"Date:", "date +'%Y-%m-%d %X'", 1, 0},

    /* Updates whenever "pkill -SIGRTMIN+10 someblocks" is ran */
    /* {"", "date '+%b %d (%a) %I:%M%p'",					0,		10},
     */
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
