
#include <rtxi/widgets.hpp>

// This is an generated header file. You may change the namespace, but 
// make sure to do the same in implementation (.cpp) file
namespace plugin_template
{

constexpr std::string_view MODULE_NAME = "plugin-template";

enum PARAMETER : Widgets::Variable::Id
{
    // set parameter ids here
    FIRST_PARAMETER=0,
    SECOND_PARAMETER,
    THIRD_PARAMETER,
    FOURTH_PARAMETER
};

inline  std::vector<Widgets::Variable::Info> get_default_vars() 
{
  return {
      {PARAMETER::FIRST_PARAMETER,
       "First Parameter Name",
       "First Parameter Description",     
       Widgets::Variable::INT_PARAMETER,
       int64_t{0}},
      {PARAMETER::SECOND_PARAMETER,
       "Second Parameter Name",
       "Second Parameter Description",
       Widgets::Variable::DOUBLE_PARAMETER,
       1.0},
      {PARAMETER::THIRD_PARAMETER,
       "Third Parameter Name",
       "Third Parameter Description",
       Widgets::Variable::UINT_PARAMETER,
       uint64_t{1}},
      {PARAMETER::FOURTH_PARAMETER,
       "Fourth Parameter Name",
       "Third Parameter Description",
       Widgets::Variable::STATE,
       uint64_t{1}}
  };
}

inline std::vector<IO::channel_t> get_default_channels()
{
  return {
      {"First Channel Output Name", "First Channel Output Description", IO::OUTPUT},
      {"First Channel Input Name", "First Channel Input Description", IO::INPUT}
  };
}

class Panel : public Widgets::Panel
{
  Q_OBJECT
public:
  Panel(QMainWindow* main_window, Event::Manager* ev_manager);
  void customizeGUI();

private slots:
  void aBttn_event(void);
  void bBttn_event(void);
};

class Component : public Widgets::Component
{
public:
  explicit Component(Widgets::Plugin* hplugin);
  void execute() override;

  // Additional functionality needed for RealTime computation is to be placed here
};

class Plugin : public Widgets::Plugin
{
public:
  explicit Plugin(Event::Manager* ev_manager);
};

}  // namespace plugin_template
