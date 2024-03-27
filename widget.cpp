#include "widget.hpp"

plugin_template::Plugin::Plugin(Event::Manager *ev_manager)
    : Widgets::Plugin(ev_manager, std::string(plugin_template::MODULE_NAME)) {}

plugin_template::Panel::Panel(QMainWindow *main_window,
                              Event::Manager *ev_manager)
    : Widgets::Panel(std::string(plugin_template::MODULE_NAME), main_window,
                     ev_manager) {
  setWhatsThis("Template Plugin");
  createGUI(plugin_template::get_default_vars()); // this is required to create the GUI
  customizeGUI();
  resizeMe();    // Resize window to show all fields and buttons
}

void plugin_template::Panel::customizeGUI() {
  // By default createGUI function defines the layout to be QVBoxLayout type
  auto *customlayout = dynamic_cast<QVBoxLayout *>(this->layout());

  QGroupBox *button_group = new QGroupBox;

  QPushButton *abutton = new QPushButton("Button A");
  QPushButton *bbutton = new QPushButton("Button B");
  QHBoxLayout *button_layout = new QHBoxLayout;
  button_group->setLayout(button_layout);
  button_layout->addWidget(abutton);
  button_layout->addWidget(bbutton);
  QObject::connect(abutton, SIGNAL(clicked()), this, SLOT(aBttn_event()));
  QObject::connect(bbutton, SIGNAL(clicked()), this, SLOT(bBttn_event()));

  customlayout->insertWidget(0, button_group);
}

plugin_template::Component::Component(Widgets::Plugin *hplugin)
    : Widgets::Component(hplugin, std::string(plugin_template::MODULE_NAME),
                         plugin_template::get_default_channels(),
                         plugin_template::get_default_vars()) {}

void plugin_template::Component::execute() {
  // This is the real-time function that will be called
  switch (this->getState()) {
  case RT::State::EXEC:
    break;
  case RT::State::INIT:
    break;
  case RT::State::MODIFY:
    break;
  case RT::State::PERIOD:
    break;
  case RT::State::PAUSE:
    break;
  case RT::State::UNPAUSE:
    break;
  default:
    break;
  }
}

void plugin_template::Panel::aBttn_event(void) {}

void plugin_template::Panel::bBttn_event(void) {}

///////// DO NOT MODIFY BELOW //////////
// The exception is if your plugin is not going to need real-time functionality.
// For this case just replace the craeteRTXIComponent return type to nullptr.
// RTXI will automatically handle that case and won't attach a component to the
// real time thread for your plugin.

std::unique_ptr<Widgets::Plugin> createRTXIPlugin(Event::Manager *ev_manager) {
  return std::make_unique<plugin_template::Plugin>(ev_manager);
}

Widgets::Panel *createRTXIPanel(QMainWindow *main_window,
                                Event::Manager *ev_manager) {
  return new plugin_template::Panel(main_window, ev_manager);
}

std::unique_ptr<Widgets::Component>
createRTXIComponent(Widgets::Plugin *host_plugin) {
  return std::make_unique<plugin_template::Component>(host_plugin);
}

Widgets::FactoryMethods fact;

extern "C" {
Widgets::FactoryMethods *getFactories() {
  fact.createPanel = &createRTXIPanel;
  fact.createComponent = &createRTXIComponent;
  fact.createPlugin = &createRTXIPlugin;
  return &fact;
}
};

//////////// END //////////////////////
