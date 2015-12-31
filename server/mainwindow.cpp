// generated by Fast Light User Interface Designer (fluid) version 1.0302

#include "mainwindow.hpp"

void MainWindow::cb_Launch_i(Fl_Menu_*, void*) {
  // Launch
{
    extern GateServer      *g_GateServer;
    extern ConfigureWindow *g_ConfigureWindow;
    if(!g_GateServer){
        g_GateServer = new GateServer(g_ConfigureWindow->ClientPort(), g_ConfigureWindow->SceneServerPort());
    }
    g_GateServer->Init();
    g_GateServer->Launch();
};
}
void MainWindow::cb_Launch(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_Launch_i(o,v);
}

void MainWindow::cb_Configure_i(Fl_Menu_*, void*) {
  {
    extern ConfigureWindow *g_ConfigureWindow;
    g_ConfigureWindow->ShowAll();
};
}
void MainWindow::cb_Configure(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_Configure_i(o,v);
}

Fl_Menu_Item MainWindow::menu_[] = {
 {"Server", 0,  0, 0, 64, FL_NORMAL_LABEL, 4, 14, 0},
 {"Launch          ", 0x4006c,  (Fl_Callback*)MainWindow::cb_Launch, 0, 128, FL_NORMAL_LABEL, 4, 14, 0},
 {"Configure", 0x40066,  (Fl_Callback*)MainWindow::cb_Configure, 0, 0, FL_NORMAL_LABEL, 4, 14, 0},
 {"Pause", 0x40070,  0, 0, 128, FL_NORMAL_LABEL, 4, 14, 0},
 {"Quit", 0,  0, 0, 0, FL_NORMAL_LABEL, 4, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};

MainWindow::MainWindow() {
  { m_Window = new Fl_Double_Window(720, 400, "GateServer");
    m_Window->labelfont(4);
    m_Window->user_data((void*)(this));
    { Fl_Menu_Bar* o = new Fl_Menu_Bar(0, 0, 721, 25);
      o->box(FL_FLAT_BOX);
      o->labelfont(4);
      o->textfont(4);
      o->menu(menu_);
    } // Fl_Menu_Bar* o
    { m_Browser = new Fl_Browser(0, 24, 720, 375);
      m_Browser->type(2);
      m_Browser->labelfont(4);
      m_Browser->textfont(4);
    } // Fl_Browser* m_Browser
    m_Window->end();
  } // Fl_Double_Window* m_Window
}

void MainWindow::ShowAll() {
  {
      m_Window->show();
  }
}

void MainWindow::AddLog(int nLogType, const char *szMessage) {
  // AddLog(int nLogType, const char *szMessage)
  {
      std::time_t stRes         = std::time(nullptr);
      std::string szFullMessage = std::asctime(std::localtime(&stRes));
      szFullMessage.back() = ' ';
      switch(nLogType){
          case 0:
              szFullMessage = "@C4"  + szFullMessage + "  " + szMessage;
              break;
          case 1:
              szFullMessage = "@C9" + szFullMessage + "  " + szMessage;
              break;
          default:
              szFullMessage = "@C1" + szFullMessage + "  " + szMessage;
              break;
      }
      m_Browser->add(szFullMessage.c_str());
  }
}
