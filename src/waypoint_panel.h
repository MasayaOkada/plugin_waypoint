#ifndef STATE_TRIGGER_PANEL_H
#define STATE_TRIGGER_PANEL_H

#ifndef Q_MOC_RUN
# include <ros/ros.h>

# include <rviz/panel.h>
#endif

class QPushButton;

namespace plugin_waypoint
{

class StateTriggerPanel: public rviz::Panel
{
Q_OBJECT
public:
  StateTriggerPanel( QWidget* parent = 0 );

  virtual void load( const rviz::Config& config );
  virtual void save( rviz::Config config ) const;

public Q_SLOTS:
  void pushStartNavigation();
  void pushSetNavigation();
    
protected:
  ros::NodeHandle nh_;
  ros::Publisher start_journey_,path_ready_;
  QPushButton *start_nav_button_;
  QPushButton *set_nav_button_;

};

} // end namespace orne_rviz_plugins

#endif // STATE_TRIGGER_PANEL_H
