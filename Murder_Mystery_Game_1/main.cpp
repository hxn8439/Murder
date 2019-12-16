#include "MurderMystery.h"
#include <gtkmm.h>
#include <iostream>

int main (int argc, char **argv)
{
    while(true)
    {
      Gtk::Main app(argc, argv);
      Loop l(app);
    }
}
