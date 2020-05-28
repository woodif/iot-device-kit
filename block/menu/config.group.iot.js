const dirIcon = Vue.prototype.$global.board.board_info.dir;

module.exports = {
  name: "MQTT Connector",
  index: 30,
  color: "230",
  icon: `file:///${dirIcon}/static/icons/mqtt.png`,
  blocks: [
     "mqtt_connector_begin",
     "on_prepare_data",
     "on_message",
     "append_value",
     "mqtt_connect"
  ]
};
