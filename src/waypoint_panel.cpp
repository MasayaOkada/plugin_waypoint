#include <stdio.h>

#include <QPainter>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include<std_msgs/Empty.h>
#include <std_srvs/Trigger.h>
#include"waypoint_panel.h"
//#include "state_trigger_panel.h"

namespace plugin_waypoint
{

StateTriggerPanel::StateTriggerPanel( QWidget* parent )
  : rviz::Panel( parent )
{
  start_journey_ = nh_.advertise<std_msgs::Empty>("start_journey", false);
  path_ready_ = nh_.advertise<std_msgs::Empty>("path_ready", false);

  start_nav_button_ = new QPushButton("StartWaypointsNavigation");
  set_nav_button_ = new QPushButton("SetWaypointNavigation");

  QHBoxLayout* layout = new QHBoxLayout;
  layout->addWidget(start_nav_button_);
  layout->addWidget(set_nav_button_);
  setLayout( layout );
  
  connect(start_nav_button_, SIGNAL(clicked()), this, SLOT(pushStartNavigation()));
  connect(set_nav_button_, SIGNAL(clicked()), this, SLOT(pushSetNavigation()));
}

void StateTriggerPanel::save( rviz::Config config ) const
{
  rviz::Panel::save( config );
}

void StateTriggerPanel::load( const rviz::Config& config )
{
  rviz::Panel::load( config );
}

void StateTriggerPanel::pushStartNavigation() {
    ROS_INFO("Topic pub: start waypoints navigation");
    
    std_msgs::Empty trigger;
    start_journey_.publish(trigger);
}

void StateTriggerPanel::pushSetNavigation() {
    ROS_INFO("Topic pub: set waypoints navigation");
    
    std_msgs::Empty set;
    path_ready_.publish(set);
}

} // end namespace orne_rviz_plugins

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(plugin_waypoint::StateTriggerPanel,rviz::Panel )
