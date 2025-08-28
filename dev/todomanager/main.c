#include <ncurses.h>
#include <string.h>

#define MAX_TASKS 100

struct Task {
    char text[256];
    int done;
};

struct Task tasks[MAX_TASKS];
int task_count = 0;
int selected = 0;

void draw_tasks() {
    clear();
    mvprintw(0, 0, "TUI ToDo Manager - q zum Beenden");
    for (int i = 0; i < task_count; i++) {
        if (i == selected) attron(A_REVERSE);  // Highlight
        mvprintw(i+2, 0, "[%c] %s", tasks[i].done ? 'x' : ' ', tasks[i].text);
        if (i == selected) attroff(A_REVERSE);
    }
    refresh();
}

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Beispiel-Tasks
    strcpy(tasks[0].text, "Milch kaufen"); tasks[0].done = 0;
    strcpy(tasks[1].text, "C lernen"); tasks[1].done = 1;
    task_count = 2;

    int ch;
    while ((ch = getch()) != 'q') {
        switch(ch) {
            case KEY_UP: if (selected > 0) selected--; break;
            case KEY_DOWN: if (selected < task_count-1) selected++; break;
            case ' ': tasks[selected].done = !tasks[selected].done; break;
        }
        draw_tasks();
    }

    endwin();
    return 0;
}
