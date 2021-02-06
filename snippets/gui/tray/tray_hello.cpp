#include <cstring>
#include <iostream>
#include <tray.h>

// Set string with the icon file for your OS
#if TRAY_APPINDICATOR
#define TRAY_ICON1 "indicator-messages"
#define TRAY_ICON2 "indicator-messages-new"
#elif TRAY_APPKIT
#define TRAY_ICON1 "icon.png"
#define TRAY_ICON2 "icon.png"
#elif TRAY_WINAPI
#define TRAY_ICON1 "icon.ico"
#define TRAY_ICON2 "icon.ico"
#endif

// Encapsulate tray and menu options into a class
class tray_and_menu {
  public:
    tray_and_menu() {
        // Setup arrays with tray items
        if (tray_.menu != nullptr) {
            return;
        }

        tray_.menu = new tray_menu[8];
        tray_.menu[0] = {.text = "Hello", .cb = hello_cb, .submenu = nullptr};
        tray_.menu[1] = {
            .text = "Checked", .cb = toggle_cb, .submenu = nullptr};
        tray_.menu[2] = {.text = "Disabled", .disabled = 1, .submenu = nullptr};
        tray_.menu[3] = {.text = "-", .submenu = nullptr};
        tray_.menu[4] = {.text = "SubMenu", .submenu = new tray_menu[3]};
        tray_.menu[5] = {.text = "-", .submenu = nullptr};
        tray_.menu[6] = {.text = "Quit", .cb = quit_cb, .submenu = nullptr};
        tray_.menu[7] = {.text = nullptr, .submenu = nullptr};

        tray_.menu[4].submenu[0] = {.text = "FIRST",
                                    .checked = 1,
                                    .cb = submenu_cb,
                                    .submenu = nullptr};
        tray_.menu[4].submenu[1] = {.text = "SECOND",
                                    .submenu = new tray_menu[6]};
        tray_.menu[4].submenu[2] = {.text = nullptr, .submenu = nullptr};

        tray_.menu[4].submenu[1].submenu[0] = {.text = "THIRD",
                                               .submenu = new tray_menu[4]};
        tray_.menu[4].submenu[1].submenu[1] = {.text = "FOUR",
                                               .submenu = new tray_menu[3]};
        tray_.menu[4].submenu[1].submenu[2] = {.text = nullptr,
                                               .submenu = nullptr};

        tray_.menu[4].submenu[1].submenu[0].submenu[0] = {
            .text = "7", .cb = submenu_cb, .submenu = nullptr};
        tray_.menu[4].submenu[1].submenu[0].submenu[1] = {.text = "-",
                                                          .submenu = nullptr};
        tray_.menu[4].submenu[1].submenu[0].submenu[2] = {
            .text = "8", .cb = submenu_cb, .submenu = nullptr};
        tray_.menu[4].submenu[1].submenu[0].submenu[3] = {.text = nullptr,
                                                          .submenu = nullptr};

        tray_.menu[4].submenu[1].submenu[1].submenu[0] = {
            .text = "5", .cb = submenu_cb, .submenu = nullptr};
        tray_.menu[4].submenu[1].submenu[1].submenu[1] = {
            .text = "6", .cb = submenu_cb, .submenu = nullptr};
        tray_.menu[4].submenu[1].submenu[1].submenu[2] = {
            .text = nullptr, .cb = submenu_cb, .submenu = nullptr};

        if (tray_init(&tray_) < 0) {
            std::runtime_error("failed to create tray_");
        }
    }

    ~tray_and_menu() {
        delete[] tray_.menu[4].submenu[1].submenu[1].submenu;
        delete[] tray_.menu[4].submenu[1].submenu[0].submenu;
        delete[] tray_.menu[4].submenu[1].submenu;
        delete[] tray_.menu[4].submenu;
        delete[] tray_.menu[3].submenu;
        delete[] tray_.menu->submenu;
        tray_.menu->submenu = nullptr;
    }

    static void run_tray() {
        while (tray_loop(1) == 0) {
            std::cout << "Iteration" << std::endl;
        }
    }

  private:
    static void toggle_cb(struct tray_menu *item) {
        std::cout << "toggle cb" << std::endl;
        item->checked = !item->checked;
        tray_update(&tray_);
    }

    static void hello_cb(struct tray_menu *item) {
        (void)item;
        std::cout << "hello cb" << std::endl;
        // NOLINTNEXTLINE(bugprone-branch-clone)
        if (strcmp(tray_.icon, TRAY_ICON1) == 0) {
            tray_.icon = TRAY_ICON2;
        } else {
            tray_.icon = TRAY_ICON1;
        }
        tray_update(&tray_);
    }

    static void quit_cb(struct tray_menu *item) {
        (void)item;
        std::cout << "quit cb" << std::endl;
        tray_exit();
    }

    static void submenu_cb(struct tray_menu *item) {
        (void)item;
        std::cout << "submenu: clicked on " << item->text << std::endl;
        tray_update(&tray_);
    }

  private /* members */:
    // Tray with pointers to menu
    static tray tray_;
};

tray tray_and_menu::tray_{.icon = TRAY_ICON1, .menu = nullptr};

int main() {
    tray_and_menu t;
    tray_and_menu::run_tray();
    return 0;
}
